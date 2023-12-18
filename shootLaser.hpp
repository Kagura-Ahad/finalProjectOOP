#include<C:\mingw_dev_lib\include\SDL2\SDL.h>
#include<C:\mingw_dev_lib\include\SDL2\SDL_image.h>

enum Direction{
    left,
    right
};

class ShootLaser
{
    private:
        SDL_Renderer* renderer;
        int eyeX;
        int eyeY;
        int m_screenBoundLeft;
        int m_screenBoundRight;
        Direction m_direction;
        
    public:
        int laserTrajectoryX;
        ShootLaser(SDL_Renderer* renderer, int startX, int startY, int screenBoundLeft, int screenBoundRight, Direction direction)
         : renderer(renderer), eyeX(startX), eyeY(startY), laserTrajectoryX(startX + 1), m_screenBoundLeft(screenBoundLeft), m_screenBoundRight(screenBoundRight), m_direction(direction) {}

        void drawLaserPoint(int x, int y, SDL_Color color);
        void drawLaserBeam();
        bool reachedEnd() const;
        void update();

};