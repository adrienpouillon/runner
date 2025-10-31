#include "pch.h"
#include "TileL.h"
#include "Entity.h"
#include "DefineTile.h"

TileL::TileL()
{
	SetTag(TileType::L);
}

TileL::~TileL()
{
	Tile::~Tile();
}

void TileL::Start()
{
	Tile::Start();
	SetConfig(TileConfig::RANDOM_CONFIG);
}

gce::Vector3f32 TileL::PosBonus()
{
	return GetPosition() + gce::Vector3f32{ 0.f, 1.f, 3.f };
}

gce::Vector3f32 TileL::PosJump()
{
	return GetPosition() + BipolarConfig({ 3.f, 1.f, 3.f }, TileConfig::_2CONFIG, { 1.f, 1.f, 1.f }, TileConfig::_1CONFIG, { -1.f, 1.f, 1.f });
}

void TileL::Make()
{
	if (GetConfig() == RANDOM_CONFIG)
	{
		SetConfig(GenerateRandomNumber(_1CONFIG, _2CONFIG));
	}

	SetSize({ 9.f, 1.f, 6.f });

	Entity* e1 = Add<Entity>();
	e1->SetScale({ 3.f, 1.f, 3.f });
	e1->SetColor({ 0.f, 1.f, 0.f });
	e1->SetPosition(BipolarConfig({ 3.f, 0.f, 0.f }, TileConfig::_1CONFIG, { 1.f, 1.f, 1.f }, TileConfig::_2CONFIG, { -1.f, 1.f, 1.f }));
	e1->SetTag(Entity::GROUND);

	Entity* e2 = Add<Entity>();
	e2->SetScale({ 9.f, 1.f, 3.f });
	e2->SetColor({ 0.f, 1.f, 0.f });
	e2->SetPosition({ 0.f, 0.f, e1->GetScale().z });
	e2->SetTag(Entity::GROUND);

	CreatBonus(100);
	CreatJump(100);

	CenterEntitiesOfTileOnZ();
}
