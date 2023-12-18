#include "shootLaser.hpp"
#include "entity.hpp"

enum AnimateState{
    firstAnimationState,
    secondAnimationState,
    thirdAnimationState
};

class Vampire : public Entity
{
    private:
        AnimateState m_animateState;
        Direction m_direction;
        int availableLasers = 1;

    public:
        ShootLaser* laser = nullptr;
        Vampire(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType) : m_animateState(firstAnimationState), m_direction(right), Entity(srcRect, moverRect, entityType) {}
        void moveLeft();
        void moveRight();
        void updateAnimations();
        void shootLaser();
};