#include "shootLaser.hpp"

void ShootLaser::drawLaserPoint(int x, int y, SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(renderer, x, y);
}

void ShootLaser::drawLaserBeam()
{
    SDL_Color beamColors[] = {
        {234, 125, 124, 255}, // #EA7D7C
        {240, 90, 91, 255},   // #F05A5B
        {253, 137, 91, 255},  // #FD895B
        {253, 244, 219, 255}, // #FDF4DB
        {253, 137, 91, 255},  // #FD895B
        {240, 90, 91, 255},   // #F05A5B
        {234, 125, 124, 255}  // #EA7D7C
    };

    if (m_direction == left)
    {
        for (int i = eyeX; i > laserTrajectoryX; i--)
        {
            for (int j = 0; j < 7; j++)
            {
                drawLaserPoint(i, eyeY + j, beamColors[j]);
            }
        }
    }
    else if (m_direction == right)
    {
        for (int i = eyeX; i < laserTrajectoryX; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                drawLaserPoint(i, eyeY + j, beamColors[j]);
            }
        }
    }
}

bool ShootLaser::reachedEnd() const
{
    if (m_direction == left)
    {
        return laserTrajectoryX <= m_screenBoundLeft;
    }
    else
    {
        return laserTrajectoryX >= m_screenBoundRight;
    }
}

void ShootLaser::update()
{
    if (!reachedEnd())
    {
        drawLaserBeam();

        if (m_direction == left)
        {
            laserTrajectoryX -= 7;        }
        else if (m_direction == right)
        {
            laserTrajectoryX += 7;
        }
    }
}