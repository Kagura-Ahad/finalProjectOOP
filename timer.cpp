#include "timer.hpp"

Timer::Timer(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfTimersNonTransparentPixelsList, int (*timersNonTransparentPixels)[2], RandomlyAppearingEntityType type) : RandomlyAppearingEntity(srcRect, moverRect, entityType, lengthOfTimersNonTransparentPixelsList, timersNonTransparentPixels, type)
{}