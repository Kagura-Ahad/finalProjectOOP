#include "bat.hpp"

Bat::Bat(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfBatsNonTransparentPixelsList, int (*batsNonTransparentPixels)[2]) : RandomlyAppearingEntity(srcRect, moverRect, entityType, lengthOfBatsNonTransparentPixelsList, batsNonTransparentPixels) {}