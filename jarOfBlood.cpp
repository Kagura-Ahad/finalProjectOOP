#include "jarOfBlood.hpp"

JarOfBlood::JarOfBlood(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfJarOfBloodsNonTransparentPixelsList, int (*jarOfBloodsNonTransparentPixels)[2], RandomlyAppearingEntityType type) : RandomlyAppearingEntity(srcRect, moverRect, entityType, lengthOfJarOfBloodsNonTransparentPixelsList, jarOfBloodsNonTransparentPixels, type) {}