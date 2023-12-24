#include "shootLaser.hpp"
#include "entity.hpp"
#include "objectCreator.hpp"

enum AnimateState{
    firstAnimationState,
    secondAnimationState,
    thirdAnimationState
};

class Vampire : public Entity
{
    private:
        AnimateState m_animateState = firstAnimationState;
        Direction m_direction = right;
        int m_availableLaserAbility = 0;
        int m_availableFlyAbility = 1;
        int m_FlyAbilityTimer = 0;
        int m_availableTimerAbility = 0;
        bool isJumping = false;
        bool isFalling = false;
        bool isFlying = false;

    public:
        int m_lives = 3;
        int m_batsCollected = 0;
        ShootLaser* laser = nullptr;
        int* vampiresLasersPosition = nullptr;
        Vampire(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType);
        void moveLeft();
        void moveRight();
        void jump();
        void updateAnimations();
        void shootLaser();
        void physics();
        int* getVampiresLasersPosition();
        void drawEntity();
        void activateFlyAbility();
        void vampireCollisionChecker(ObjectCreator& creatorObject);
        int getAvailableLaserAbility();
};