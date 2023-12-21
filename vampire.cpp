#include "vampire.hpp"
#include <unordered_set>
#include "randomlyAppearingEntity.hpp"

// Function to convert coordinates to a unique integer for set comparison
size_t makeHash(int x, int y) {
    return static_cast<size_t>(x) * 31 + static_cast<size_t>(y); // Adjust multiplier as needed
}

Vampire::Vampire(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType) : Entity(srcRect, moverRect, entityType)
{
    if (m_direction == right)
    {
        if (m_animateState == firstAnimationState)
        {
            m_srcRect.x = 0;
        }
    }
}

void Vampire::drawEntity(ObjectCreator& creatorObject)
{
    Entity::drawEntity();
    Vampire::physics();

    // Update the vampire's laser
    if (laser != nullptr)
    {
        laser->update();
        if (laser->reachedEnd())
        {
            delete laser;
            laser = nullptr;
        }
    }
    
    
    
    std::vector<RandomlyAppearingEntity*>& entities = creatorObject.getEntities();

    //Check if Vampire collides 
    for (auto it = entities.rbegin(); it != entities.rend(); ++it)
    {

        if (*it != nullptr)
        {
            if (m_moverRect.x < (*it)->m_moverRect.x + (*it)->m_moverRect.w &&
                m_moverRect.x + m_moverRect.w > (*it)->m_moverRect.x &&
                m_moverRect.y < (*it)->m_moverRect.y + (*it)->m_moverRect.h &&
                m_moverRect.y + m_moverRect.h > (*it)->m_moverRect.y)
            {
                if ((*it)->m_type == CAT || (*it)->m_type == GARLIC || (*it)->m_type == ONION || (*it)->m_type == KNIFE)
                {
                    m_lives -= 1;
                }
                else if ((*it)->m_type == LASER)
                {
                    m_availableLaserAbility += 1;
                }
                else if ((*it)->m_type == FLY)
                {
                    m_availableFlyAbility += 1;
                }
                else if ((*it)->m_type == TIMER)
                {
                    m_availableTimerAbility += 1;
                }
                else if ((*it)->m_type == BAT)
                {
                    m_batsCollected += 1;
                }
                else if ((*it)->m_type == JAR_OF_BLOOD)
                {
                    m_lives += 1;
                }
                delete *it;
                *it = nullptr;
                entities.erase(std::next(it).base());
            }
        }
    }
    
    // //Failed attempt at collision detection when non transparent pixels coincide
    // int offsetX[] = {-1, 0, 1, -1}; // Adjust as needed
    // int offsetY[] = {-1, -1, 0, 0}; // Adjust as needed

    // for (auto it = entities.begin(); it != entities.end();) {
    //     std::unordered_set<size_t> entityPixels;

    //     // Populate an unordered_set with hash values generated from entity's pixels
    //     for (int i = 0; i < (*it)->m_lengthOfEntitysNonTransparentPixelsList; ++i) {
    //         int x = (*it)->m_entitysNonTransparentPixels[i][0];
    //         int y = (*it)->m_entitysNonTransparentPixels[i][1];
    //         entityPixels.insert(makeHash(x, y));
    //     }

    //     bool collisionDetected = false;

    //     // Check for collisions between vampire and entities
    //     for (int i = 0; i < this->m_lengthOfEntitysNonTransparentPixelsList; ++i) {
    //         for (int k = 0; k < 9; ++k) {
    //             int x = this->m_entitysNonTransparentPixels[i][0] + offsetX[k];
    //             int y = this->m_entitysNonTransparentPixels[i][1] + offsetY[k];

    //             if (entityPixels.find(makeHash(x, y)) != entityPixels.end()) {
    //                 std::cout << "Collision detected" << std::endl;
    //                 it = entities.erase(it); // Remove collided entity from vector
    //                 collisionDetected = true;
    //                 break;
    //             }
    //         }
    //         if (collisionDetected) {
    //             break;
    //         }
    //     }

    //     if (!collisionDetected) {
    //         ++it; // Move to the next entity if no collision detected
    //     }
    // }

}

void Vampire::moveLeft()
{
    // Make sure the vampire is on the ground and that it doesn't already have a laser before changing direction or moving
    if ((m_moverRect.y + m_moverRect.h == 460) && (laser == nullptr) && (m_moverRect.x > 0))
    {
        if (m_direction == right)
        m_direction = left;

        if (m_animateState == firstAnimationState)
            m_animateState = secondAnimationState;
        else if (m_animateState == secondAnimationState)
            m_animateState = thirdAnimationState;
        else if (m_animateState == thirdAnimationState)
            m_animateState = firstAnimationState;

        updateAnimations();

        m_moverRect.x -= 5;
    }
}

void Vampire::moveRight()
{
    // Make sure the vampire is on the ground and that it doesn't already have a laser before changing direction or moving
	if ((m_moverRect.y + m_moverRect.h == 460) && (laser == nullptr) && (m_moverRect.x < 832))
    {
        if (m_direction == left)
        m_direction = right;

        if (m_animateState == firstAnimationState)
            m_animateState = secondAnimationState;
        else if (m_animateState == secondAnimationState)
            m_animateState = thirdAnimationState;
        else if (m_animateState == thirdAnimationState)
            m_animateState = firstAnimationState;

        updateAnimations();

        m_moverRect.x += 5;
    }
}

void Vampire::jump()
{
    // Make sure the vampire is on the ground and that it doesn't already have a laser before jumping
    if ((m_moverRect.y + m_moverRect.h == 460) && (laser == nullptr) && (isFlying == false))
    {
        // Set the jumping and falling flags to true
        isJumping = true;
        isFalling = false;
    }
}

void Vampire::activateFlyAbility()
{
    // Check if the vampire has any fly abilities left
    // Then Make sure the vampire is on the ground and that it doesn't already have a laser before flying
    if ((m_moverRect.y + m_moverRect.h == 460) && (laser == nullptr) && (m_availableFlyAbility > 0))
    {
        // Set the flying flag to true
        isFlying = true;

        // Decrement the number of fly abilities the vampire has left
        m_availableFlyAbility -= 1;

        // Set the timer for the fly ability
        m_FlyAbilityTimer = 500;
    }

}

void Vampire::physics()
{
    // Check if the vampire is jumping
    if (isJumping)
    {
        // Move the vampire up
        m_moverRect.y -= 2;     


        // if (m_direction == left)
        // {
        //     m_moverRect.x -= 1;     

        // }
        // else if (m_direction == right)
        // {
        //     m_moverRect.x += 1;     

        // }

        // Check if the vampire has reached the top of the jump
        if (m_moverRect.y <= 200)
        {
            // Set the jumping and falling flags to false
            isJumping = false;
            isFalling = true;
        }
        
    }
    // Check if the vampire is falling
    else if (isFalling)
    {
        // Move the vampire down
        m_moverRect.y += 2;     


        // if (m_direction == left)
        // {
        //     m_moverRect.x -= 1;     

        // }
        // else if (m_direction == right)
        // {
        //     m_moverRect.x += 1;     

        // }

        // Check if the vampire has reached the ground
        if (m_moverRect.y + m_moverRect.h >= 460)
        {
            // Set the jumping and falling flags to false
            isFalling = false;
        }
    }
    else if (isFlying)
    {
        if (m_moverRect.y >= 0)
        {
            // Move the vampire up
            m_moverRect.y -= 2;
        }

        // Check if the vampire has reached the top of the screen
        else if (m_moverRect.y <= 0)
        {

            // Change the timer for the fly ability
            m_FlyAbilityTimer -= 1;

            // Check if the timer has reached 0
            if (m_FlyAbilityTimer == 0)
            {
                isFalling = true;
                isFlying = false;
            }
        }
    }
}

void Vampire::updateAnimations()
{
    if (m_direction == left)
    {
        if (m_animateState == firstAnimationState)
        {
            m_srcRect.x = 117;
        }
            
        else if (m_animateState == secondAnimationState)
        {
            m_srcRect.x = 156;
        }
        else if (m_animateState == thirdAnimationState)
        {
            m_srcRect.x = 195;
        }
    }
    else if (m_direction == right)
    {
        if (m_animateState == firstAnimationState)
        {
            m_srcRect.x = 0;
        }
        else if (m_animateState == secondAnimationState)
        {
            m_srcRect.x = 39;
        }
        else if (m_animateState == thirdAnimationState)
            m_srcRect.x = 78;
    }
}

void Vampire::shootLaser()
{
    // Check if the vampire has any lasers left
    // Then Make sure the vampire is on the ground and that it doesn't already have a laser before shooting
    // Then create a new laser with the screen bounds 0 and 832 (hardcoded)
    
	if ((m_moverRect.y + m_moverRect.h == 460) && (laser == nullptr) && (m_availableLaserAbility > 0))
    {
        // Check the direction the vampire is facing and create a laser accordingly
        if (m_direction == left)
        {
            laser = new ShootLaser(Drawing::gRenderer, m_moverRect.x + 20, m_moverRect.y + 17, 0, 0, left);
        }
        else 
        // Check the direction the vampire is facing and create a laser accordingly
        if (m_direction == right)
        {
            laser = new ShootLaser(Drawing::gRenderer, m_moverRect.x + 20, m_moverRect.y + 17, 0, 832, right);
        }

        // Decrement the number of lasers the vampire has left
        m_availableLaserAbility -= 1;
    }
}

int* Vampire::getVampiresLasersPosition()
{
    // Check if the vampire has a laser
    if (laser != nullptr)
    {
        // Return the laser's position
        vampiresLasersPosition = new int{laser->laserTrajectoryX};
        return  vampiresLasersPosition;
    }
    else
    {
        // Return nullptr if the vampire doesn't have a laser
        return nullptr;
    }
}