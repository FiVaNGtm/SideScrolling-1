#include "Stage1.h"

#include <Siv3D/Vector2D.hpp>

Stage1::Stage1(const InitData& init)
	: IScene(init)
{

}

void Stage1::update()
{
	m_exitTransition.update(m_exitButton.mouseOver());
	m_ground.draw(ColorF{ 0.2,0.6,0.3 });
	m_air.draw(Arg::top = ColorF{ 0.1,0.3,0.6 }, Arg::bottom = ColorF{ 0.3,0.7,1.0 });

	if(KeyA.pressed())
	{
		m_playerPos.x -= (m_playerSpeed * Scene::DeltaTime());
	}
	else if(KeyD.pressed())
	{
		m_playerPos.x += (m_playerSpeed * Scene::DeltaTime());
	}

	m_enemyPosX -= (m_enemySpeed * Scene::DeltaTime());
	m_enemy.drawAt(m_enemyPosX, m_playerPos.y);

	m_playerTexture.drawAt(m_playerPos);

	if(KeySpace.pressed())
	{
		m_playerAttack.drawAt(m_playerPos.x + 80, m_playerPos.y);
	}

	if (m_exitButton.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	if (m_exitButton.leftClicked())
	{
		changeScene(State::title);
	}
}

void Stage1::draw() const
{
	m_exitButton.draw(ColorF(1.0, m_exitTransition.value())).drawFrame(2);
	FontAsset(U"Menu")(U"Back").drawAt(m_exitButton.center(), ColorF(0.25));
}