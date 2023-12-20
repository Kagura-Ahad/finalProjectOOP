#pragma once
#include "randomlyAppearingEntity.hpp"


class Laser : public RandomlyAppearingEntity
{
    private:

    public:
        Laser(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfLasersNonTransparentPixelsList, int (*lasersNonTransparentPixels)[2]);
};