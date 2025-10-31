#include "pch.h"
#include "TileOneVoid.h"

TileOneVoid::TileOneVoid()
{
	SetTag(TileType::ONE_VOID);
}

TileOneVoid::~TileOneVoid()
{
	Tile::~Tile();
}

void TileOneVoid::Start()
{
	Tile::Start();
	SetConfig(TileConfig::CLASSIC_CONFIG);
}

Entity* TileOneVoid::AddBonus()
{
	return Tile::AddBonus(GetPosition() + gce::Vector3f32{ 0.f, 1.f, 0.f });
}

void TileOneVoid::Make()
{
	/*if (mConfig == RANDOM_CONFIG)
	{
		SetConfig(GenerateRandomNumber(_1CONFIG, _2CONFIG));
	}*/

	SetSize({ 9.f, 9.f, 3.f });

	if (GenerateRandomNumber(100) < BONUS_CHANCE)
	{
		AddBonus();
	}
}
