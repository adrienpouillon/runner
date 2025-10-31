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

gce::Vector3f32 TileOneVoid::PosBonus()
{
	return GetPosition() + gce::Vector3f32{ 0.f, 1.f, 0.f };
}

gce::Vector3f32 TileOneVoid::PosJump()
{
	return GetPosition() + gce::Vector3f32{ 0.f, 1.f, -6.f };
}

void TileOneVoid::Make()
{
	/*if (mConfig == RANDOM_CONFIG)
	{
		SetConfig(GenerateRandomNumber(_1CONFIG, _2CONFIG));
	}*/

	SetSize({ 9.f, 9.f, 3.f });

	CreatBonus(100);
	CreatJump(100);
}
