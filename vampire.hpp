#include "entity.hpp"
#include "shootLaser.hpp"

enum AnimateState{
    firstAnimationState,
    secondAnimationState,
    thirdAnimationState
};

enum Direction{
    left,
    right
};

class Vampire : public Entity
{
    private:
        AnimateState m_animateState;
        Direction m_direction;
        int availableLasers = 1;

    public:
        ShootLaser* laser = nullptr;
        Vampire(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType) : m_animateState(firstAnimationState), m_direction(left), Entity(srcRect, moverRect, entityType) {}
        void moveLeft();
        void moveRight();
        void updateAnimations();
        void shootLaser(int screenWidth);
};