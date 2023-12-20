#include "onion.hpp"

Onion::Onion(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfOnionsNonTransparentPixelsList, int (*onionsNonTransparentPixels)[2]) : RandomlyAppearingEntity(srcRect, moverRect, entityType, lengthOfOnionsNonTransparentPixelsList, onionsNonTransparentPixels) {}