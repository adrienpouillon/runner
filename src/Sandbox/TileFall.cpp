#include "pch.h"
#include "TileFall.h"
#include "Entity.h"
#include "DefineTile.h"

TileFall::TileFall()
{
	SetTag(TileType::FALL);
}

TileFall::~TileFall()
{
	Tile::~Tile();
}

void TileFall::Start()
{
	Tile::Start();
	SetConfig(TileConfig::RANDOM_CONFIG);
}

Entity* TileFall::AddBonus()
{
	return Tile::AddBonus(GetPosition() + TripolarConfig({ 0.f, -1.5f, 3.f }, TileConfig::_1CONFIG, { 1.f, 1.f, 1.f }, TileConfig::_2CONFIG, { -1.f, 1.f, 1.f }, TileConfig::_3CONFIG, { -1.f, 1.f, 1.f }));
}

void TileFall::Make()
{
	if (GetConfig() == RANDOM_CONFIG)
	{
		SetConfig(GenerateRandomNumber(_1CONFIG, _2CONFIG));
	}

	SetSize({ 9.f ,4.f ,12.f });

	//ground
	Entity* e1 = Add<Entity>();
	e1->SetScale({ 9.f, 1.f, 9.f });
	e1->SetColor({ 0.5f, 0.5f, 0.5f });
	e1->SetPosition({ 0.f, -2.5f, 3.f });
	e1->SetTag(Entity::GROUND);

	//vertical wall
	Entity* e2 = Add<Entity>();
	e2->SetScale({ 9.f, 3.f, 3.f });
	e2->SetColor({ 0.5f, 0.5f, 0.5f });
	e2->SetPosition({ 0.f, -1.f, -3.f });
	e2->SetTag(Entity::GROUND);

	if (GenerateRandomNumber(100) <= BONUS_CHANCE)
	{
		AddBonus();
	}
}