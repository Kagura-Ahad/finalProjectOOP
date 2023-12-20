#pragma once
#include "randomlyAppearingEntity.hpp"


class Fly : public RandomlyAppearingEntity
{
    private:

    public:
        Fly(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfFliesNonTransparentPixelsList, int (*fliesNonTransparentPixels)[2]);
};