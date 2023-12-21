#include "randomlyAppearingEntity.hpp"

RandomlyAppearingEntity::RandomlyAppearingEntity(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfEntitysNonTransparentPixelsList, int (*entitysNonTransparentPixels)[2], RandomlyAppearingEntityType type) : Entity(srcRect, moverRect, entityType, lengthOfEntitysNonTransparentPixelsList, entitysNonTransparentPixels), m_type(type) {}

void RandomlyAppearingEntity::drawEntity()
{
    Entity::drawEntity();
    Entity::m_moverRect.x -= 2;

    for (int i = 0; i < m_lengthOfEntitysNonTransparentPixelsList; i++)
    {
        m_entitysNonTransparentPixels[i][0] -= 2;
    }
}