#include <Siv3D/System.hpp>

#include "Common.h"
#include "Title.h"
#include "Stage1.h"

void Main()
{
	// タイトルを設定
	Window::SetTitle(U"DASH TO RIGHT");

	// 背景色を設定
	Scene::SetBackground(Color(0, 110, 128));

	// 使用するフォントアセットを登録
	FontAsset::Register(U"Title", 90, U"example/font/AnnyantRoman/AnnyantRoman.ttf");
	FontAsset::Register(U"Menu", 30, Typeface::Regular);
	FontAsset::Register(U"Score", 36, Typeface::Bold);

	// シーンと遷移時の色を設定
	my_app manager;
	manager
		.add<Title>(State::title)
		.add<Stage1>(State::game)
		.setFadeColor(ColorF(1.0));

	while (s3d::System::Update())
	{
		if (!manager.update())
		{
			break;
		}
	}
}