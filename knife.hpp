#pragma once
#include "randomlyAppearingEntity.hpp"


class Knife : public RandomlyAppearingEntity
{
    private:

    public:
        Knife(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType) : RandomlyAppearingEntity(srcRect, moverRect, entityType) {}
};