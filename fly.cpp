#include "fly.hpp"

Fly::Fly(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfFliesNonTransparentPixelsList, int (*fliesNonTransparentPixels)[2], RandomlyAppearingEntityType type) : RandomlyAppearingEntity(srcRect, moverRect, entityType, lengthOfFliesNonTransparentPixelsList, fliesNonTransparentPixels, type) {}