#pragma once
#include "drawing.hpp"
#include <iostream>

enum EntityType
{
    PLAYER,
    RANDOMLY_APPEARING_ENTITY,
};

class Entity
{
    private:
        EntityType m_entityType;

    public:
        SDL_Rect m_srcRect, m_moverRect;

        Entity(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType) : m_srcRect(srcRect), m_moverRect(moverRect), m_entityType(entityType) {}

        virtual void drawEntity();
};