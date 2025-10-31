#include "pch.h"
#include "TileCanyon.h"
#include "Entity.h"
#include "DefineTile.h"

TileCanyon::TileCanyon()
{
	SetTag(TileType::CANYON);
}

TileCanyon::~TileCanyon()
{
	Tile::~Tile();
}

void TileCanyon::Start()
{
	Tile::Start();
	SetConfig(TileConfig::RANDOM_CONFIG);
}

gce::Vector3f32 TileCanyon::PosBonus()
{
	return GetPosition() + gce::Vector3f32{ 3.f, 3.f, 6.f };
}

gce::Vector3f32 TileCanyon::PosJump()
{
	return GetPosition() + gce::Vector3f32{ 0.f, 1.f, 0.f };
}

void TileCanyon::Make()
{
	if (GetConfig() == RANDOM_CONFIG)
	{
		SetConfig(GenerateRandomNumber(_1CONFIG, _2CONFIG));
	}

	SetSize({ 9.f ,9.f ,9.f });

	//ground
	Entity* e1 = Add<Entity>();
	e1->SetScale({ 9.f, 1.f, 9.f });
	e1->SetColor({ 1.f, 1.f, 1.f });
	e1->SetPosition({ 0.f, 0.f, 0.f });
	e1->SetTag(Entity::GROUND);

	//vertical wall 1
	Entity* e2 = Add<Entity>();
	e2->SetScale({ 3.f , 3.f , 6.f });
	e2->SetColor({ 0.75f, 0.75f, 0.75f });
	e2->SetPosition(BipolarConfig({ -3.f, 1.5f, 1.2f }, TileConfig::_1CONFIG, { 1.f, 1.f, 1.f }, TileConfig::_2CONFIG, { 1.f, 1.f, -1.f }));
	e2->SetTag(Entity::GROUND);

	//vertical wall 2
	Entity* e3 = Add<Entity>();
	e3->SetScale({ 3.f , 3.f , 6.f });
	e3->SetColor({ 0.75f, 0.75f, 0.75f });
	e3->SetPosition(BipolarConfig({ 3.f, 1.5f, 1.2f }, TileConfig::_1CONFIG, { 1.f, 1.f, 1.f }, TileConfig::_2CONFIG, { 1.f, 1.f, -1.f }));
	e3->SetTag(Entity::GROUND);

	CreatBonus(100);
	CreatJump(100);
}
