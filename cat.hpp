#pragma once
#include "randomlyAppearingEntity.hpp"


class Cat : public RandomlyAppearingEntity
{
    private:

    public:
        Cat(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType) : RandomlyAppearingEntity(srcRect, moverRect, entityType) {}
};