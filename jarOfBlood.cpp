#include "jarOfBlood.hpp"

JarOfBlood::JarOfBlood(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfJarOfBloodsNonTransparentPixelsList, int (*jarOfBloodsNonTransparentPixels)[2]) : RandomlyAppearingEntity(srcRect, moverRect, entityType, lengthOfJarOfBloodsNonTransparentPixelsList, jarOfBloodsNonTransparentPixels) {}