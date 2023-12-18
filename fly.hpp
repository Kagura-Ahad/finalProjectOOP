#include "entity.hpp"
class Fly : public Entity
{
    private:

    public:
        Fly(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType) : Entity(srcRect, moverRect, entityType) {}
};