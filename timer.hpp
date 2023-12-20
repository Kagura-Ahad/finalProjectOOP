#pragma once
#include "randomlyAppearingEntity.hpp"


class Timer : public RandomlyAppearingEntity
{
    private:

    public:
        Timer(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfTimersNonTransparentPixelsList, int (*timersNonTransparentPixels)[2]);
};