#include "laser.hpp"

Laser::Laser(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfLasersNonTransparentPixelsList, int (*lasersNonTransparentPixels)[2]) : RandomlyAppearingEntity(srcRect, moverRect, entityType, lengthOfLasersNonTransparentPixelsList, lasersNonTransparentPixels) {}