#include "randomlyAppearingEntity.hpp"

RandomlyAppearingEntity::RandomlyAppearingEntity(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfEntitysNonTransparentPixelsList, int (*entitysNonTransparentPixels)[2])
 : Entity(srcRect, moverRect, entityType, lengthOfEntitysNonTransparentPixelsList, entitysNonTransparentPixels) {}

void RandomlyAppearingEntity::drawEntity()
{
    Entity::drawEntity();
    Entity::m_moverRect.x -= 2;
}