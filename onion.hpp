#pragma once
#include "randomlyAppearingEntity.hpp"


class Onion : public RandomlyAppearingEntity
{
    private:

    public:
        Onion(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfOnionsNonTransparentPixelsList, int (*onionsNonTransparentPixels)[2], RandomlyAppearingEntityType type);
};