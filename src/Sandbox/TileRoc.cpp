#include "pch.h"
#include "TileRoc.h"
#include "Entity.h"
#include "DefineTile.h"

TileRoc::TileRoc()
{
	SetTag(TileType::ROC);
}

TileRoc::~TileRoc()
{
	Tile::~Tile();
}

void TileRoc::Start()
{
	Tile::Start();
	SetConfig(TileConfig::RANDOM_CONFIG);
}

gce::Vector3f32 TileRoc::PosBonus()
{
	return GetPosition() + BipolarConfig({ 3.f, 4.5f, 3.f }, TileConfig::_1CONFIG, { 1.f, 1.f, 1.f }, TileConfig::_2CONFIG, { -1.f, 1.f, 1.f });
}

gce::Vector3f32 TileRoc::PosJump()
{
	return GetPosition() + BipolarConfig({ 3.f, 1.f, 3.f }, TileConfig::_2CONFIG, { 1.f, 1.f, 1.f }, TileConfig::_1CONFIG, { -1.f, 1.f, 1.f });
}

void TileRoc::Make()
{
	if (GetConfig() == RANDOM_CONFIG)
	{
		SetConfig(GenerateRandomNumber(_1CONFIG, _2CONFIG));
	}
	SetSize({ 9.f ,9.f ,9.f });

	//ground
	Entity* e1 = Add<Entity>();
	e1->SetScale({ 9.f, 1.f, 9.f });
	e1->SetColor({ 0.f, 1.f, 0.f });
	e1->SetPosition({ 0.f, 0.f, 0.f });
	e1->SetTag(Entity::GROUND);

	//vertical ground 1
	Entity* e2 = Add<Entity>();
	e2->SetScale({ 3.f , 3.f , 9.f });
	e2->SetColor({ 1.f, 1.f, 1.f });
	e2->SetPosition(BipolarConfig({ 3.f, 0.f, 0.f }, TileConfig::_1CONFIG, { 1.f, 1.f, 1.f }, TileConfig::_2CONFIG, { -1.f, 1.f, 1.f }));
	e2->SetTag(Entity::GROUND);

	//vertical ground little 2
	Entity* e3 = Add<Entity>();
	e3->SetScale({ 3.f , 3.f , 3.f });
	e3->SetColor({ 1.f, 1.f, 1.f });
	e3->SetPosition(BipolarConfig({ 3.f, 2.f, 3.f }, TileConfig::_1CONFIG, { 1.f, 1.f, 1.f }, TileConfig::_2CONFIG, { -1.f, 1.f, 1.f }));
	e3->SetTag(Entity::GROUND);

	CreatBonus(100);
	CreatJump(100);
}
