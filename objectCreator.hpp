#include "randomlyAppearingEntity.hpp"
#include "fly.hpp"
#include "bat.hpp"
#include "cat.hpp"
#include "garlic.hpp"
#include "jarOfBlood.hpp"
#include "knife.hpp"
#include "laser.hpp"
#include "onion.hpp"
#include "timer.hpp"
#include <vector>




class ObjectCreator
{
    private:
        std::vector<RandomlyAppearingEntity*> entities;

    public:       
        ObjectCreator(); 
        void createRandomlyAppearingEntities(int* vampiresLasersPosition);
};