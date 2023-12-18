#pragma once
#include "drawing.hpp"

enum EntityType
{
    PLAYER,
    NPC
};

class Entity
{
    private:
        EntityType m_entityType;

    public:
        SDL_Rect m_srcRect, m_moverRect;

        Entity(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType) : m_srcRect(srcRect), m_moverRect(moverRect), m_entityType(entityType) {}

        void drawEntity();
};