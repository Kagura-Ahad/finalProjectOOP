#include "knife.hpp"

Knife::Knife(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfKnifesNonTransparentPixelsList, int (*knifesNonTransparentPixels)[2], RandomlyAppearingEntityType type) : RandomlyAppearingEntity(srcRect, moverRect, entityType, lengthOfKnifesNonTransparentPixelsList, knifesNonTransparentPixels, type) {}