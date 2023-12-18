#include "vampire.hpp"

void Vampire::moveLeft()
{
    if (m_direction == right)
        m_direction = left;

    if (m_animateState == firstAnimationState)
        m_animateState = secondAnimationState;
    else if (m_animateState == secondAnimationState)
        m_animateState = thirdAnimationState;
    else if (m_animateState == thirdAnimationState)
        m_animateState = firstAnimationState;

    updateAnimations();

    m_moverRect.x -= 5;
}

void Vampire::moveRight()
{
    if (m_direction == left)
        m_direction = right;

    if (m_animateState == firstAnimationState)
        m_animateState = secondAnimationState;
    else if (m_animateState == secondAnimationState)
        m_animateState = thirdAnimationState;
    else if (m_animateState == thirdAnimationState)
        m_animateState = firstAnimationState;

    updateAnimations();

    m_moverRect.x += 5;
}

void Vampire::updateAnimations()
{
    if (m_direction == left)
    {
        if (m_animateState == firstAnimationState)
            m_srcRect.x = 270;
        else if (m_animateState == secondAnimationState)
            m_srcRect.x = 360;
        else if (m_animateState == thirdAnimationState)
            m_srcRect.x = 450;
    }
    else if (m_direction == right)
    {
        if (m_animateState == firstAnimationState)
            m_srcRect.x = 0;
        else if (m_animateState == secondAnimationState)
            m_srcRect.x = 90;
        else if (m_animateState == thirdAnimationState)
            m_srcRect.x = 180;
    }
}

void Vampire::shootLaser(int screenWidth)
{
    if (availableLasers > 0)
    {
        laser = new ShootLaser(Drawing::gRenderer, m_moverRect.x + 17, m_moverRect.y + 16, screenWidth);
        // availableLasers -= 1;
    }
}