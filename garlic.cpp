#include "garlic.hpp"

Garlic::Garlic(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfGarlicsNonTransparentPixelsList, int (*garlicsNonTransparentPixels)[2], RandomlyAppearingEntityType type) : RandomlyAppearingEntity(srcRect, moverRect, entityType, lengthOfGarlicsNonTransparentPixelsList, garlicsNonTransparentPixels, type) {}