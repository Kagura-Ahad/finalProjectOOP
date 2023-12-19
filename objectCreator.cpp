#pragma once
#include "ObjectCreator.hpp"

ObjectCreator::ObjectCreator() {}

void ObjectCreator::createRandomlyAppearingEntities(int* PositionOfVampiresLasers)
{
    // Randomly create an object with a 10% chance
    int chanceOfAnObjectAppearing = rand() % 1000 + 1;
    if (chanceOfAnObjectAppearing <= 10)
    {
        RandomlyAppearingEntity* entity = nullptr;
        int random = rand() % 9;
        switch(random)
        {
            case 0:
                entity = new Bat({0, 0, 60, 60}, {762, 400, 60, 60}, RANDOMLY_APPEARING_ENTITY);
                break;
            case 1:
                entity = new Cat({60, 0, 60, 60}, {762, 400, 60, 60}, RANDOMLY_APPEARING_ENTITY);
                break;
            case 2:
                entity = new Fly({120, 0, 60, 60}, {762, 400, 60, 60}, RANDOMLY_APPEARING_ENTITY);
                break;
            case 3:
                entity = new Garlic({0, 60, 60, 60}, {762, 400, 60, 60}, RANDOMLY_APPEARING_ENTITY);
                break;
            case 4:
                entity = new JarOfBlood({60, 60, 60, 60}, {762, 400, 60, 60}, RANDOMLY_APPEARING_ENTITY);
                break;
            case 5:
                entity = new Knife({120, 60, 60, 60}, {762, 400, 60, 60}, RANDOMLY_APPEARING_ENTITY);
                break;
            case 6:
                entity = new Laser({0, 120, 60, 60}, {762, 400, 60, 60}, RANDOMLY_APPEARING_ENTITY);
                break;
            case 7:
                entity = new Onion({60, 120, 60, 60}, {762, 400, 60, 60}, RANDOMLY_APPEARING_ENTITY);
                break;
            case 8:
                entity = new Timer({120, 120, 60, 60}, {762, 400, 60, 60}, RANDOMLY_APPEARING_ENTITY);
                break;
            default:
                break;
        }
        if (entity != nullptr)
        {
            entities.push_back(entity);
        }
    }

    // Draw the entities
    for (int i = 0; i < entities.size(); i++)
    {
        if (entities[i] != nullptr)
        {
            entities[i]->drawEntity();
        }
    }

    // Delete the entities that have gone off-screen
    for (auto it = entities.rbegin(); it != entities.rend(); ++it)
    {
        if (((*it)->m_moverRect.x < -(*it)->m_moverRect.w) && (*it != nullptr))
        {
            delete *it;
            *it = nullptr;
            entities.erase(std::next(it).base());
        }
    }

    // Delete the entities that have been hit by the vampire's laser
    /*
    Right now the entities are destroyed when laser trajectory comes within 10 pixels of the entitys' moverRect, I will later change this to entities being
    destroyed when the laser trajectory actually hits the entity by making a vector of all the pixels of the entitys' moverRect which are not transparent
    and then checking if the laser trajectory hits any of those pixels
    */
   if (PositionOfVampiresLasers != nullptr)
   {
    for (auto it = entities.rbegin(); it != entities.rend(); ++it)
    {
        if (((*it)->m_moverRect.x < *PositionOfVampiresLasers + 10 && (*it)->m_moverRect.x > *PositionOfVampiresLasers - 10) && (*it != nullptr))
        {
            delete *it;
            *it = nullptr;
            entities.erase(std::next(it).base());
        }
    }
   }
}
