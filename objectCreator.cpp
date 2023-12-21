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
                entity = new Bat({0, 0, 60, 60}, {762, 400, 60, 60}, RANDOMLY_APPEARING_ENTITY, 165, returnArrayOfArrays(0), BAT);
                break;
            case 1:
                entity = new Cat({60, 0, 60, 60}, {762, 400, 60, 60}, RANDOMLY_APPEARING_ENTITY, 289, returnArrayOfArrays(1), CAT);
                break;
            case 2:
                entity = new Fly({120, 0, 60, 60}, {762, 400, 60, 60}, RANDOMLY_APPEARING_ENTITY, 165, returnArrayOfArrays(2) , FLY);
                break;
            case 3:
                entity = new Garlic({0, 60, 60, 60}, {762, 400, 60, 60}, RANDOMLY_APPEARING_ENTITY, 98, returnArrayOfArrays(3), GARLIC);
                break;
            case 4:
                entity = new JarOfBlood({60, 60, 60, 60}, {762, 400, 60, 60}, RANDOMLY_APPEARING_ENTITY, 155, returnArrayOfArrays(4), JAR_OF_BLOOD);
                break;
            case 5:
                entity = new Knife({120, 60, 60, 60}, {762, 400, 60, 60}, RANDOMLY_APPEARING_ENTITY, 139, returnArrayOfArrays(5), KNIFE);
                break;
            case 6:
                entity = new Laser({0, 120, 60, 60}, {762, 400, 60, 60}, RANDOMLY_APPEARING_ENTITY, 146, returnArrayOfArrays(6), LASER);
                break;
            case 7:
                entity = new Onion({60, 120, 60, 60}, {762, 400, 60, 60}, RANDOMLY_APPEARING_ENTITY, 141, returnArrayOfArrays(7), ONION);
                break;
            case 8:
                entity = new Timer({120, 120, 60, 60}, {762, 400, 60, 60}, RANDOMLY_APPEARING_ENTITY, 159, returnArrayOfArrays(8), TIMER);
                break;
            default:
                break;
        }
        if (entity != nullptr)
        {
            // for (int i = 0; i < 165; i++)
            //     {
            //         std::cout << "{" << entity->m_entitysNonTransparentPixels[i][0] << ", " << entity->m_entitysNonTransparentPixels[i][1] << "}, ";
            //     }
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

int (*ObjectCreator::returnArrayOfArrays(int entity))[2]
{
    int (*arr0)[2] = new int[168][2];
    int (*arr1)[2] = new int[289][2];
    int (*arr2)[2] = new int[165][2];
    int (*arr3)[2] = new int[98][2];
    int (*arr4)[2] = new int[155][2];
    int (*arr5)[2] = new int[139][2];
    int (*arr6)[2] = new int[146][2];
    int (*arr7)[2] = new int[141][2];
    int (*arr8)[2] = new int[159][2];
    switch (entity)
    {
    case 0:
        arr0 = new int[168][2]{{56, 9}, {57, 9}, {54, 10}, {55, 10}, {57, 10}, {52, 11}, {53, 11}, {56, 11}, {51, 12}, {56, 12}, {49, 13}, {50, 13}, {56, 13}, {48, 14}, {56, 14}, {47, 15}, {56, 15}, {46, 16}, {56, 16}, {45, 17}, {56, 17}, {45, 18}, {56, 18}, {44, 19}, {57, 19}, {43, 20}, {57, 20}, {43, 21}, {57, 21}, {42, 22}, {56, 22}, {42, 23}, {55, 23}, {41, 24}, {54, 24}, {41, 25}, {54, 25}, {40, 26}, {53, 26}, {40, 27}, {53, 27}, {40, 28}, {53, 28}, {40, 29}, {53, 29}, {40, 30}, {53, 30}, {34, 31}, {35, 31}, {40, 31}, {53, 31}, {34, 32}, {35, 32}, {40, 32}, {53, 32}, {9, 33}, {10, 33}, {11, 33}, {12, 33}, {13, 33}, {14, 33}, {15, 33}, {16, 33}, {17, 33}, {28, 33}, {29, 33}, {30, 33}, {33, 33}, {36, 33}, {40, 33}, {54, 33}, {7, 34}, {8, 34}, {18, 34}, {19, 34}, {28, 34}, {31, 34}, {32, 34}, {36, 34}, {40, 34}, {51, 34}, {52, 34}, {53, 34}, {54, 34}, {5, 35}, {6, 35}, {20, 35}, {29, 35}, {36, 35}, {39, 35}, {49, 35}, {50, 35}, {4, 36}, {21, 36}, {22, 36}, {29, 36}, {36, 36}, {39, 36}, {48, 36}, {3, 37}, {23, 37}, {30, 37}, {37, 37}, {38, 37}, {47, 37}, {3, 38}, {4, 38}, {5, 38}, {6, 38}, {24, 38}, {30, 38}, {46, 38}, {7, 39}, {8, 39}, {25, 39}, {26, 39}, {30, 39}, {45, 39}, {9, 40}, {27, 40}, {28, 40}, {29, 40}, {45, 40}, {10, 41}, {44, 41}, {10, 42}, {43, 42}, {10, 43}, {42, 43}, {10, 44}, {11, 44}, {12, 44}, {13, 44}, {14, 44}, {15, 44}, {42, 44}, {16, 45}, {41, 45}, {16, 46}, {41, 46}, {17, 47}, {19, 47}, {20, 47}, {21, 47}, {22, 47}, {23, 47}, {40, 47}, {17, 48}, {18, 48}, {24, 48}, {28, 48}, {29, 48}, {30, 48}, {31, 48}, {32, 48}, {33, 48}, {40, 48}, {17, 49}, {25, 49}, {26, 49}, {27, 49}, {34, 49}, {35, 49}, {39, 49}, {36, 50}, {37, 50}, {38, 50}, {39, 50}};
        for (int i = 0; i < 168; i++)
        {
            arr0[i][0] += 762;
            arr0[i][1] += 400;
        }
        return arr0;
    case 1:
        arr1 = new int[289][2]{{46, 0}, {48, 0}, {45, 1}, {49, 1}, {50, 1}, {45, 2}, {50, 2}, {46, 3}, {51, 3}, {47, 4}, {51, 4}, {47, 5}, {52, 5}, {47, 6}, {52, 6}, {47, 7}, {52, 7}, {8, 8}, {9, 8}, {10, 8}, {11, 8}, {23, 8}, {24, 8}, {25, 8}, {48, 8}, {52, 8}, {8, 9}, {12, 9}, {22, 9}, {25, 9}, {48, 9}, {52, 9}, {8, 10}, {12, 10}, {21, 10}, {26, 10}, {48, 10}, {52, 10}, {8, 11}, {13, 11}, {20, 11}, {26, 11}, {48, 11}, {52, 11}, {8, 12}, {14, 12}, {15, 12}, {16, 12}, {17, 12}, {18, 12}, {19, 12}, {26, 12}, {47, 12}, {52, 12}, {8, 13}, {26, 13}, {47, 13}, {52, 13}, {8, 14}, {26, 14}, {47, 14}, {52, 14}, {8, 15}, {26, 15}, {47, 15}, {52, 15}, {59, 15}, {7, 16}, {26, 16}, {47, 16}, {52, 16}, {59, 16}, {7, 17}, {26, 17}, {47, 17}, {52, 17}, {7, 18}, {26, 18}, {47, 18}, {51, 18}, {7, 19}, {26, 19}, {46, 19}, {51, 19}, {7, 20}, {26, 20}, {46, 20}, {51, 20}, {7, 21}, {26, 21}, {46, 21}, {51, 21}, {5, 22}, {6, 22}, {27, 22}, {28, 22}, {46, 22}, {51, 22}, {5, 23}, {29, 23}, {30, 23}, {46, 23}, {50, 23}, {5, 24}, {7, 24}, {30, 24}, {45, 24}, {50, 24}, {5, 25}, {6, 25}, {8, 25}, {31, 25}, {32, 25}, {33, 25}, {34, 25}, {35, 25}, {36, 25}, {37, 25}, {38, 25}, {39, 25}, {40, 25}, {41, 25}, {42, 25}, {43, 25}, {44, 25}, {50, 25}, {7, 26}, {8, 26}, {50, 26}, {5, 27}, {6, 27}, {7, 27}, {9, 27}, {10, 27}, {50, 27}, {5, 28}, {6, 28}, {11, 28}, {50, 28}, {5, 29}, {12, 29}, {50, 29}, {12, 30}, {50, 30}, {12, 31}, {50, 31}, {12, 32}, {50, 32}, {12, 33}, {50, 33}, {12, 34}, {50, 34}, {12, 35}, {50, 35}, {12, 36}, {50, 36}, {12, 37}, {50, 37}, {13, 38}, {50, 38}, {13, 39}, {50, 39}, {14, 40}, {50, 40}, {14, 41}, {35, 41}, {51, 41}, {14, 42}, {30, 42}, {31, 42}, {32, 42}, {33, 42}, {34, 42}, {36, 42}, {51, 42}, {14, 43}, {27, 43}, {28, 43}, {29, 43}, {36, 43}, {51, 43}, {14, 44}, {26, 44}, {36, 44}, {51, 44}, {15, 45}, {26, 45}, {36, 45}, {52, 45}, {15, 46}, {26, 46}, {37, 46}, {52, 46}, {15, 47}, {26, 47}, {37, 47}, {52, 47}, {15, 48}, {26, 48}, {38, 48}, {53, 48}, {15, 49}, {26, 49}, {38, 49}, {45, 49}, {53, 49}, {15, 50}, {20, 50}, {26, 50}, {39, 50}, {44, 50}, {46, 50}, {53, 50}, {15, 51}, {19, 51}, {21, 51}, {26, 51}, {39, 51}, {44, 51}, {47, 51}, {53, 51}, {15, 52}, {19, 52}, {21, 52}, {26, 52}, {40, 52}, {44, 52}, {48, 52}, {53, 52}, {15, 53}, {19, 53}, {21, 53}, {26, 53}, {40, 53}, {44, 53}, {48, 53}, {53, 53}, {15, 54}, {19, 54}, {21, 54}, {26, 54}, {40, 54}, {44, 54}, {48, 54}, {53, 54}, {15, 55}, {19, 55}, {21, 55}, {25, 55}, {40, 55}, {44, 55}, {48, 55}, {52, 55}, {15, 56}, {19, 56}, {21, 56}, {25, 56}, {40, 56}, {44, 56}, {48, 56}, {52, 56}, {15, 57}, {19, 57}, {21, 57}, {25, 57}, {39, 57}, {43, 57}, {47, 57}, {52, 57}, {15, 58}, {18, 58}, {21, 58}, {24, 58}, {39, 58}, {43, 58}, {47, 58}, {51, 58}, {16, 59}, {17, 59}, {21, 59}, {23, 59}, {24, 59}, {39, 59}, {40, 59}, {41, 59}, {42, 59}, {47, 59}, {50, 59}, {51, 59}};
        for (int i = 0; i < 289; i++)
        {
            arr1[i][0] += 762;
            arr1[i][1] += 400;
        }
        return arr1;
    case 2:
        arr2 = new int[165][2]{{0, 15}, {1, 15}, {2, 15}, {3, 15}, {4, 15}, {5, 15}, {6, 15}, {7, 15}, {52, 15}, {53, 15}, {54, 15}, {55, 15}, {56, 15}, {57, 15}, {58, 15}, {59, 15}, {8, 16}, {9, 16}, {50, 16}, {51, 16}, {0, 17}, {10, 17}, {11, 17}, {12, 17}, {47, 17}, {48, 17}, {49, 17}, {59, 17}, {1, 18}, {13, 18}, {46, 18}, {58, 18}, {2, 19}, {14, 19}, {15, 19}, {44, 19}, {45, 19}, {57, 19}, {3, 20}, {16, 20}, {43, 20}, {56, 20}, {3, 21}, {17, 21}, {42, 21}, {56, 21}, {3, 22}, {18, 22}, {41, 22}, {56, 22}, {3, 23}, {19, 23}, {40, 23}, {56, 23}, {3, 24}, {20, 24}, {40, 24}, {56, 24}, {3, 25}, {20, 25}, {39, 25}, {56, 25}, {3, 26}, {20, 26}, {39, 26}, {56, 26}, {3, 27}, {21, 27}, {39, 27}, {56, 27}, {2, 28}, {21, 28}, {38, 28}, {57, 28}, {2, 29}, {21, 29}, {38, 29}, {57, 29}, {3, 30}, {4, 30}, {5, 30}, {21, 30}, {38, 30}, {54, 30}, {55, 30}, {56, 30}, {6, 31}, {7, 31}, {22, 31}, {37, 31}, {53, 31}, {8, 32}, {22, 32}, {37, 32}, {52, 32}, {8, 33}, {23, 33}, {36, 33}, {51, 33}, {8, 34}, {23, 34}, {36, 34}, {51, 34}, {8, 35}, {24, 35}, {35, 35}, {51, 35}, {8, 36}, {12, 36}, {13, 36}, {14, 36}, {15, 36}, {16, 36}, {25, 36}, {34, 36}, {43, 36}, {44, 36}, {45, 36}, {46, 36}, {47, 36}, {51, 36}, {8, 37}, {9, 37}, {10, 37}, {11, 37}, {17, 37}, {18, 37}, {19, 37}, {26, 37}, {27, 37}, {28, 37}, {31, 37}, {32, 37}, {33, 37}, {41, 37}, {42, 37}, {48, 37}, {49, 37}, {50, 37}, {51, 37}, {20, 38}, {28, 38}, {31, 38}, {39, 38}, {40, 38}, {21, 39}, {27, 39}, {32, 39}, {38, 39}, {22, 40}, {27, 40}, {33, 40}, {37, 40}, {23, 41}, {26, 41}, {33, 41}, {36, 41}, {24, 42}, {25, 42}, {34, 42}, {35, 42}, {25, 43}, {26, 43}, {33, 43}, {34, 43}};
        for (int i = 0; i < 165; i++)
        {
            arr2[i][0] += 762;
            arr2[i][1] += 400;
        }
        return arr2;
    case 3:
        arr3 = new int[98][2]{{29, 12}, {30, 12}, {28, 13}, {30, 13}, {27, 14}, {30, 14}, {27, 15}, {30, 15}, {27, 16}, {31, 16}, {27, 17}, {31, 17}, {27, 18}, {31, 18}, {26, 19}, {31, 19}, {26, 20}, {32, 20}, {26, 21}, {33, 21}, {25, 22}, {33, 22}, {23, 23}, {24, 23}, {34, 23}, {23, 24}, {35, 24}, {21, 25}, {22, 25}, {36, 25}, {37, 25}, {20, 26}, {38, 26}, {18, 27}, {19, 27}, {39, 27}, {16, 28}, {17, 28}, {40, 28}, {41, 28}, {15, 29}, {42, 29}, {14, 30}, {43, 30}, {13, 31}, {44, 31}, {13, 32}, {45, 32}, {12, 33}, {45, 33}, {12, 34}, {46, 34}, {11, 35}, {46, 35}, {11, 36}, {46, 36}, {11, 37}, {46, 37}, {12, 38}, {46, 38}, {12, 39}, {46, 39}, {12, 40}, {46, 40}, {13, 41}, {46, 41}, {14, 42}, {45, 42}, {15, 43}, {44, 43}, {16, 44}, {43, 44}, {17, 45}, {18, 45}, {19, 45}, {20, 45}, {22, 45}, {23, 45}, {41, 45}, {42, 45}, {21, 46}, {24, 46}, {33, 46}, {34, 46}, {35, 46}, {36, 46}, {37, 46}, {38, 46}, {39, 46}, {40, 46}, {25, 47}, {32, 47}, {26, 48}, {27, 48}, {28, 48}, {29, 48}, {30, 48}, {31, 48}};
        for (int i = 0; i < 98; i++)
        {
            arr3[i][0] += 762;
            arr3[i][1] += 400;
        }
        return arr3;
    case 4:
        arr4 = new int[155][2]{{22, 0}, {48, 0}, {49, 0}, {26, 1}, {27, 1}, {28, 1}, {29, 1}, {30, 1}, {31, 1}, {32, 1}, {23, 2}, {24, 2}, {25, 2}, {33, 2}, {34, 2}, {35, 2}, {21, 3}, {22, 3}, {36, 3}, {37, 3}, {20, 4}, {38, 4}, {20, 5}, {38, 5}, {20, 6}, {38, 6}, {19, 7}, {39, 7}, {18, 8}, {40, 8}, {17, 9}, {41, 9}, {17, 10}, {42, 10}, {16, 11}, {42, 11}, {17, 12}, {42, 12}, {17, 13}, {18, 13}, {19, 13}, {39, 13}, {40, 13}, {41, 13}, {20, 14}, {38, 14}, {21, 15}, {37, 15}, {21, 16}, {38, 16}, {20, 17}, {38, 17}, {20, 18}, {38, 18}, {19, 19}, {39, 19}, {18, 20}, {40, 20}, {17, 21}, {41, 21}, {15, 22}, {16, 22}, {42, 22}, {43, 22}, {14, 23}, {44, 23}, {12, 24}, {13, 24}, {45, 24}, {46, 24}, {11, 25}, {47, 25}, {10, 26}, {48, 26}, {10, 27}, {49, 27}, {9, 28}, {49, 28}, {9, 29}, {49, 29}, {9, 30}, {49, 30}, {9, 31}, {49, 31}, {9, 32}, {49, 32}, {9, 33}, {49, 33}, {9, 34}, {49, 34}, {9, 35}, {49, 35}, {9, 36}, {49, 36}, {9, 37}, {49, 37}, {9, 38}, {49, 38}, {9, 39}, {49, 39}, {9, 40}, {49, 40}, {10, 41}, {49, 41}, {10, 42}, {49, 42}, {10, 43}, {49, 43}, {10, 44}, {48, 44}, {10, 45}, {48, 45}, {10, 46}, {48, 46}, {10, 47}, {48, 47}, {11, 48}, {48, 48}, {11, 49}, {47, 49}, {12, 50}, {46, 50}, {13, 51}, {14, 51}, {44, 51}, {45, 51}, {15, 52}, {16, 52}, {17, 52}, {41, 52}, {42, 52}, {43, 52}, {18, 53}, {19, 53}, {20, 53}, {21, 53}, {22, 53}, {23, 53}, {35, 53}, {36, 53}, {37, 53}, {38, 53}, {39, 53}, {40, 53}, {24, 54}, {25, 54}, {26, 54}, {27, 54}, {28, 54}, {29, 54}, {30, 54}, {31, 54}, {32, 54}, {33, 54}, {34, 54}};
        for (int i = 0; i < 155; i++)
        {
            arr4[i][0] += 762;
            arr4[i][1] += 400;
        }
        return arr4;
    case 5:
        arr5 = new int[139][2]{{51, 4}, {52, 4}, {49, 5}, {50, 5}, {53, 5}, {54, 5}, {48, 6}, {54, 6}, {46, 7}, {47, 7}, {54, 7}, {45, 8}, {54, 8}, {44, 9}, {54, 9}, {43, 10}, {54, 10}, {42, 11}, {53, 11}, {41, 12}, {52, 12}, {39, 13}, {40, 13}, {51, 13}, {38, 14}, {50, 14}, {37, 15}, {49, 15}, {36, 16}, {48, 16}, {35, 17}, {47, 17}, {34, 18}, {46, 18}, {33, 19}, {45, 19}, {27, 20}, {28, 20}, {32, 20}, {44, 20}, {26, 21}, {29, 21}, {30, 21}, {31, 21}, {43, 21}, {27, 22}, {42, 22}, {26, 23}, {41, 23}, {24, 24}, {25, 24}, {40, 24}, {23, 25}, {39, 25}, {23, 26}, {39, 26}, {21, 27}, {22, 27}, {38, 27}, {20, 28}, {37, 28}, {19, 29}, {37, 29}, {10, 30}, {11, 30}, {17, 30}, {18, 30}, {38, 30}, {10, 31}, {12, 31}, {13, 31}, {14, 31}, {17, 31}, {38, 31}, {11, 32}, {15, 32}, {16, 32}, {36, 32}, {37, 32}, {38, 32}, {11, 33}, {35, 33}, {8, 34}, {9, 34}, {10, 34}, {34, 34}, {7, 35}, {33, 35}, {7, 36}, {8, 36}, {9, 36}, {32, 36}, {10, 37}, {31, 37}, {8, 38}, {9, 38}, {31, 38}, {8, 39}, {30, 39}, {9, 40}, {29, 40}, {8, 41}, {28, 41}, {8, 42}, {27, 42}, {7, 43}, {25, 43}, {26, 43}, {7, 44}, {24, 44}, {7, 45}, {23, 45}, {7, 46}, {22, 46}, {6, 47}, {20, 47}, {21, 47}, {6, 48}, {19, 48}, {6, 49}, {17, 49}, {18, 49}, {5, 50}, {16, 50}, {5, 51}, {14, 51}, {15, 51}, {5, 52}, {12, 52}, {13, 52}, {5, 53}, {9, 53}, {10, 53}, {11, 53}, {5, 54}, {6, 54}, {7, 54}, {8, 54}, {5, 55}};
        for (int i = 0; i < 139; i++)
        {
            arr5[i][0] += 762;
            arr5[i][1] += 400;
        }
        return arr5;
    case 6:
        arr6 = new int[146][2]{{28, 3}, {29, 3}, {30, 3}, {31, 3}, {23, 4}, {24, 4}, {25, 4}, {26, 4}, {27, 4}, {32, 4}, {33, 4}, {34, 4}, {35, 4}, {36, 4}, {20, 5}, {21, 5}, {22, 5}, {37, 5}, {38, 5}, {39, 5}, {18, 6}, {19, 6}, {40, 6}, {41, 6}, {16, 7}, {17, 7}, {42, 7}, {43, 7}, {15, 8}, {44, 8}, {13, 9}, {14, 9}, {45, 9}, {46, 9}, {12, 10}, {47, 10}, {11, 11}, {48, 11}, {10, 12}, {49, 12}, {9, 13}, {49, 13}, {9, 14}, {50, 14}, {8, 15}, {51, 15}, {7, 16}, {52, 16}, {7, 17}, {52, 17}, {6, 18}, {53, 18}, {6, 19}, {53, 19}, {5, 20}, {54, 20}, {5, 21}, {54, 21}, {5, 22}, {54, 22}, {4, 23}, {55, 23}, {4, 24}, {55, 24}, {4, 25}, {55, 25}, {4, 26}, {55, 26}, {4, 27}, {55, 27}, {4, 28}, {55, 28}, {4, 29}, {55, 29}, {4, 30}, {55, 30}, {4, 31}, {55, 31}, {4, 32}, {55, 32}, {4, 33}, {55, 33}, {4, 34}, {55, 34}, {4, 35}, {55, 35}, {5, 36}, {54, 36}, {5, 37}, {54, 37}, {5, 38}, {54, 38}, {6, 39}, {53, 39}, {6, 40}, {53, 40}, {7, 41}, {52, 41}, {7, 42}, {52, 42}, {8, 43}, {51, 43}, {9, 44}, {50, 44}, {9, 45}, {50, 45}, {10, 46}, {49, 46}, {11, 47}, {48, 47}, {12, 48}, {47, 48}, {13, 49}, {46, 49}, {14, 50}, {15, 50}, {44, 50}, {45, 50}, {16, 51}, {17, 51}, {43, 51}, {18, 52}, {19, 52}, {40, 52}, {41, 52}, {42, 52}, {20, 53}, {21, 53}, {38, 53}, {39, 53}, {22, 54}, {23, 54}, {24, 54}, {25, 54}, {26, 54}, {33, 54}, {34, 54}, {35, 54}, {36, 54}, {37, 54}, {27, 55}, {28, 55}, {29, 55}, {30, 55}, {31, 55}, {32, 55}};
        for (int i = 0; i < 146; i++)
        {
            arr6[i][0] += 762;
            arr6[i][1] += 400;
        }
        return arr6;
    case 7:
        arr7 = new int[141][2]{{26, 5}, {27, 5}, {29, 5}, {30, 5}, {25, 6}, {27, 6}, {29, 6}, {30, 6}, {25, 7}, {26, 7}, {28, 7}, {30, 7}, {32, 7}, {33, 7}, {34, 7}, {22, 8}, {23, 8}, {25, 8}, {27, 8}, {31, 8}, {33, 8}, {22, 9}, {24, 9}, {32, 9}, {23, 10}, {24, 10}, {31, 10}, {25, 11}, {31, 11}, {26, 12}, {31, 12}, {25, 13}, {31, 13}, {25, 14}, {31, 14}, {25, 15}, {32, 15}, {24, 16}, {33, 16}, {22, 17}, {23, 17}, {34, 17}, {20, 18}, {21, 18}, {35, 18}, {17, 19}, {18, 19}, {19, 19}, {36, 19}, {37, 19}, {15, 20}, {16, 20}, {38, 20}, {39, 20}, {14, 21}, {40, 21}, {13, 22}, {41, 22}, {42, 22}, {12, 23}, {43, 23}, {11, 24}, {44, 24}, {10, 25}, {44, 25}, {9, 26}, {45, 26}, {9, 27}, {46, 27}, {8, 28}, {46, 28}, {8, 29}, {47, 29}, {7, 30}, {47, 30}, {7, 31}, {47, 31}, {7, 32}, {47, 32}, {7, 33}, {47, 33}, {7, 34}, {47, 34}, {7, 35}, {47, 35}, {7, 36}, {47, 36}, {7, 37}, {47, 37}, {8, 38}, {47, 38}, {8, 39}, {46, 39}, {9, 40}, {46, 40}, {9, 41}, {45, 41}, {10, 42}, {44, 42}, {11, 43}, {44, 43}, {12, 44}, {43, 44}, {13, 45}, {41, 45}, {42, 45}, {14, 46}, {15, 46}, {40, 46}, {16, 47}, {38, 47}, {39, 47}, {17, 48}, {18, 48}, {19, 48}, {35, 48}, {36, 48}, {37, 48}, {20, 49}, {21, 49}, {22, 49}, {23, 49}, {24, 49}, {31, 49}, {32, 49}, {33, 49}, {34, 49}, {25, 50}, {30, 50}, {24, 51}, {30, 51}, {23, 52}, {24, 52}, {25, 52}, {26, 52}, {27, 52}, {31, 52}, {28, 53}, {29, 53}, {30, 53}, {31, 53}};
        for (int i = 0; i < 141; i++)
        {
            arr7[i][0] += 762;
            arr7[i][1] += 400;
        }
        return arr7;
    case 8:
        arr8 = new int[159][2]{{27, 0}, {28, 0}, {29, 0}, {30, 0}, {22, 1}, {23, 1}, {24, 1}, {25, 1}, {27, 1}, {30, 1}, {21, 2}, {25, 2}, {28, 2}, {30, 2}, {21, 3}, {26, 3}, {27, 3}, {30, 3}, {21, 4}, {31, 4}, {21, 5}, {30, 5}, {31, 5}, {21, 6}, {29, 6}, {22, 7}, {30, 7}, {31, 7}, {32, 7}, {33, 7}, {34, 7}, {20, 8}, {21, 8}, {35, 8}, {36, 8}, {37, 8}, {19, 9}, {38, 9}, {39, 9}, {42, 9}, {17, 10}, {18, 10}, {40, 10}, {41, 10}, {43, 10}, {15, 11}, {16, 11}, {44, 11}, {45, 11}, {46, 11}, {14, 12}, {47, 12}, {13, 13}, {47, 13}, {12, 14}, {47, 14}, {11, 15}, {46, 15}, {11, 16}, {47, 16}, {10, 17}, {48, 17}, {10, 18}, {49, 18}, {9, 19}, {49, 19}, {8, 20}, {50, 20}, {8, 21}, {51, 21}, {7, 22}, {51, 22}, {7, 23}, {51, 23}, {7, 24}, {52, 24}, {7, 25}, {52, 25}, {7, 26}, {53, 26}, {6, 27}, {53, 27}, {6, 28}, {53, 28}, {6, 29}, {53, 29}, {6, 30}, {53, 30}, {6, 31}, {53, 31}, {6, 32}, {54, 32}, {6, 33}, {54, 33}, {6, 34}, {53, 34}, {6, 35}, {53, 35}, {6, 36}, {53, 36}, {7, 37}, {53, 37}, {7, 38}, {53, 38}, {7, 39}, {53, 39}, {8, 40}, {53, 40}, {8, 41}, {52, 41}, {9, 42}, {52, 42}, {9, 43}, {51, 43}, {10, 44}, {51, 44}, {10, 45}, {51, 45}, {11, 46}, {50, 46}, {12, 47}, {49, 47}, {13, 48}, {49, 48}, {14, 49}, {48, 49}, {15, 50}, {47, 50}, {16, 51}, {46, 51}, {17, 52}, {44, 52}, {45, 52}, {18, 53}, {19, 53}, {42, 53}, {43, 53}, {20, 54}, {21, 54}, {40, 54}, {41, 54}, {22, 55}, {23, 55}, {37, 55}, {38, 55}, {39, 55}, {24, 56}, {25, 56}, {26, 56}, {27, 56}, {28, 56}, {29, 56}, {30, 56}, {31, 56}, {32, 56}, {33, 56}, {34, 56}, {35, 56}, {36, 56}};
        for (int i = 0; i < 159; i++)
        {
            arr8[i][0] += 762;
            arr8[i][1] += 400;
        }
        return arr8;
    default:
        return nullptr;
    }
}

std::vector<RandomlyAppearingEntity*>& ObjectCreator::getEntities()
{
    return entities;
}