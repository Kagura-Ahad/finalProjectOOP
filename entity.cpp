#include "entity.hpp"

void Entity::drawEntity()
{
    //Draw the texture
    SDL_RenderCopy( Drawing::gRenderer, m_entityType == PLAYER ? Drawing::assetsPlayer : Drawing::assetsNPC, &m_srcRect, &m_moverRect);
}