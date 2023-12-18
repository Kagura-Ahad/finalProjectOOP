#include "entity.hpp"

class ShootLaser
{
    private:
        SDL_Renderer* renderer;
        int eyeX;
        int eyeY;
        int m_screenWidth;
    public:
        int laserTrajectoryX;
        ShootLaser(SDL_Renderer* renderer, int startX, int startY, int screenWidth)
            : renderer(renderer), eyeX(startX), eyeY(startY), laserTrajectoryX(startX + 1), m_screenWidth(screenWidth) {}

        void drawLaserPoint(int x, int y, SDL_Color color);
        void drawLaserBeam();
        bool reachedEnd() const;
        void update();

};