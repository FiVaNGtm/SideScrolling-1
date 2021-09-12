#pragma once
#include "Common.h"

class Stage1 : public my_app::Scene
{
private:

    Rect m_exitButton = Rect(Arg::center = Scene::Center().moveBy(-200, 270), 300, 40);
    Rect m_ground = Rect{ 0,520,800,80 };
    Rect m_air = Rect{ 0,0,800,520 };

    const Texture m_playerTexture{ Emoji{U"😃"} };
    const double m_playerSpeed = 300;
    Vec2 m_playerPos{ 400,500 };

    const Texture m_playerAttack{ Emoji{U"👊"} };

    const Texture m_enemy{ Emoji{U"👾"} };
    const int m_enemyInitPos = 800;
    const double m_enemySpeed = 200;
     double m_enemyPosX = m_enemyInitPos;

    Transition m_exitTransition = Transition(0.4s, 0.2s);
public:
    Stage1(const InitData& init);
    void update() override;
    void draw() const override;
};