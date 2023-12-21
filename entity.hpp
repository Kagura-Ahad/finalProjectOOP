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
        int m_lengthOfEntitysNonTransparentPixelsList;
        int (*m_entitysNonTransparentPixels)[2];
        SDL_Rect m_srcRect, m_moverRect;

        Entity(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int lengthOfEntitysNonTransparentPixelsList, int (*entitysNonTransparentPixels)[2]);
        Entity(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType);
        virtual void drawEntity();
        bool operator==(const Entity& other) const;
};