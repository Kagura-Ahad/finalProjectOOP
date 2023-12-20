#pragma once
#include "entity.hpp"
#include <tuple>


class RandomlyAppearingEntity : public Entity
{
    private:

    public:
        RandomlyAppearingEntity(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int m_lengthOfEntitysNonTransparentPixelsList, int (*m_entitysNonTransparentPixels)[2]);
        void drawEntity() override;
};