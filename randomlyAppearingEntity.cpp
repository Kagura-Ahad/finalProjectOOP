#include "randomlyAppearingEntity.hpp"

RandomlyAppearingEntity::RandomlyAppearingEntity(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType) : Entity(srcRect, moverRect, entityType) {}

void RandomlyAppearingEntity::drawEntity()
{
    Entity::drawEntity();
    Entity::m_moverRect.x -= 2;
}