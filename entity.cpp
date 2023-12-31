#include "entity.hpp"

Entity::Entity(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfEntitysNonTransparentPixelsList, int (*entitysNonTransparentPixels)[2])
 : m_srcRect(srcRect), m_moverRect(moverRect), m_entityType(entityType), m_lengthOfEntitysNonTransparentPixelsList(lengthOfEntitysNonTransparentPixelsList), m_entitysNonTransparentPixels(entitysNonTransparentPixels) {}

Entity::Entity(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType)
 : m_srcRect(srcRect), m_moverRect(moverRect), m_entityType(entityType) {}

void Entity::drawEntity()
{
    //Draw the texture
    if (m_entityType == PLAYER)
    {
        SDL_RenderCopy(Drawing::gRenderer, Drawing::assetsPlayer, &m_srcRect, &m_moverRect);
    }
    else if (m_entityType == RANDOMLY_APPEARING_ENTITY)
    {
        SDL_RenderCopy(Drawing::gRenderer, Drawing::assetsRANDOMLY_APPEARING_ENTITY, &m_srcRect, &m_moverRect);
    }
}

bool Entity::operator==(const Entity& other) const {
        return (
            m_moverRect.x < other.m_moverRect.x + other.m_moverRect.w &&
            m_moverRect.x + m_moverRect.w > other.m_moverRect.x &&
            m_moverRect.y < other.m_moverRect.y + other.m_moverRect.h &&
            m_moverRect.y + m_moverRect.h > other.m_moverRect.y
        );
    }