#pragma once
#include "entity.hpp"

class RandomlyAppearingEntity : public Entity
{
    private:
    int* entityListX;
    int* entityListY;

    public:
        RandomlyAppearingEntity(SDL_Rect srcRect, SDL_Rect moverRect, EntityType entityType);
        void drawEntity() override;
};