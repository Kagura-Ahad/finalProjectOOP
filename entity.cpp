#include "entity.hpp"

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