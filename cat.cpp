#include "cat.hpp"

Cat::Cat(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfCatsNonTransparentPixelsList, int (*catsNonTransparentPixels)[2]) : RandomlyAppearingEntity(srcRect, moverRect, entityType, lengthOfCatsNonTransparentPixelsList, catsNonTransparentPixels) {}