#pragma once
#include "randomlyAppearingEntity.hpp"


class JarOfBlood : public RandomlyAppearingEntity
{
    private:

    public:
        JarOfBlood(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfJarOfBloodsNonTransparentPixelsList, int (*jarOfBloodsNonTransparentPixels)[2], RandomlyAppearingEntityType type);
};