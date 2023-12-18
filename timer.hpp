#include "entity.hpp"
class Timer : public Entity
{
    private:

    public:
        Timer(SDL_Rect srcRect, SDL_Rect moverRect) : Entity(srcRect, moverRect) {}
};