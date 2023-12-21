#pragma once
#include "entity.hpp"
#include <tuple>

enum RandomlyAppearingEntityType
{
    FLY,
    BAT,
    CAT,
    GARLIC,
    JAR_OF_BLOOD,
    KNIFE,
    LASER,
    ONION,
    TIMER
};


class RandomlyAppearingEntity : public Entity
{
    private:

    public:
        RandomlyAppearingEntityType m_type;
        RandomlyAppearingEntity(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType, int m_lengthOfEntitysNonTransparentPixelsList, int (*m_entitysNonTransparentPixels)[2], RandomlyAppearingEntityType type);
        void drawEntity() override;
};