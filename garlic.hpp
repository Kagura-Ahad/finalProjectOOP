#pragma once
#include "randomlyAppearingEntity.hpp"


class Garlic : public RandomlyAppearingEntity
{
    private:

    public:
        Garlic(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType) : RandomlyAppearingEntity(srcRect, moverRect, entityType) {}
};