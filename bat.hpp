#pragma once
#include "randomlyAppearingEntity.hpp"


class Bat : public RandomlyAppearingEntity
{
    private:

    public:
        Bat(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType) : RandomlyAppearingEntity(srcRect, moverRect, entityType) {}
};