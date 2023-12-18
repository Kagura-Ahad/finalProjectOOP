#include "vampire.hpp"

void Vampire::moveLeft()
{
    // Make sure the vampire is on the ground and that it doesn't already have a laser before changing direction or moving
    // Comment Updated: The vampire can move right even if it is not on the ground
    if (/*(m_moverRect.y + m_moverRect.h == 460) && */(laser == nullptr) && (m_moverRect.x > 0))
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
    // Comment Updated: The vampire can move right even if it is not on the ground
	if (/*(m_moverRect.y + m_moverRect.h == 460) && */(laser == nullptr) && (m_moverRect.x < 832))
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
    if ((m_moverRect.y + m_moverRect.h == 460) && (laser == nullptr))
    {
        // Set the jumping and falling flags to true
        isJumping = true;
        isFalling = false;
    }
}

void Vampire::physics()
{
    // Check if the vampire is jumping
    if (isJumping)
    {
        // Move the vampire up
        m_moverRect.y -= 1;

        // Check if the vampire has reached the top of the jump
        if (m_moverRect.y <= 300)
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
        m_moverRect.y += 1;

        // Check if the vampire has reached the ground
        if (m_moverRect.y + m_moverRect.h >= 460)
        {
            // Set the jumping and falling flags to false
            isFalling = false;
        }
    }
}

void Vampire::updateAnimations()
{
    if (m_direction == left)
    {
        if (m_animateState == firstAnimationState)
            m_srcRect.x = 270;
        else if (m_animateState == secondAnimationState)
            m_srcRect.x = 360;
        else if (m_animateState == thirdAnimationState)
            m_srcRect.x = 450;
    }
    else if (m_direction == right)
    {
        if (m_animateState == firstAnimationState)
            m_srcRect.x = 0;
        else if (m_animateState == secondAnimationState)
            m_srcRect.x = 90;
        else if (m_animateState == thirdAnimationState)
            m_srcRect.x = 180;
    }
}

void Vampire::shootLaser()
{
    // Check if the vampire has any lasers left
    // Then Make sure the vampire is on the ground and that it doesn't already have a laser before shooting
    // Then create a new laser with the screen bounds 0 and 832 (hardcoded)
    
	if ((m_moverRect.y + m_moverRect.h == 460) && (laser == nullptr) && (availableLasers > 0))
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
        // availableLasers -= 1;
    }
}