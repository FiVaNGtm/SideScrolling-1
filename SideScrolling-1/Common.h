#pragma once
#include <Siv3D.hpp>

enum class State
{
    title,
    game,
};

struct GameData
{
    uint32_t highScore = 0;
};

using my_app = SceneManager<State, GameData>;