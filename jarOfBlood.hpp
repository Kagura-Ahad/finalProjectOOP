#pragma once
#include "randomlyAppearingEntity.hpp"


class JarOfBlood : public RandomlyAppearingEntity
{
    private:

    public:
        JarOfBlood(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType) : RandomlyAppearingEntity(srcRect, moverRect, entityType) {}
};