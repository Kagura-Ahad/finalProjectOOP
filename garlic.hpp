#pragma once
#include "randomlyAppearingEntity.hpp"


class Garlic : public RandomlyAppearingEntity
{
    private:

    public:
        Garlic(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfGarlicsNonTransparentPixelsList, int (*garlicsNonTransparentPixels)[2]);
};