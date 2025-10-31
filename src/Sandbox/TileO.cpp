#include "pch.h"
#include "TileO.h"
#include "Entity.h"
#include "DefineTile.h"

TileO::TileO()
{
	SetTag(TileType::O);
}

TileO::~TileO()
{
	Tile::~Tile();
}

void TileO::Start()
{
	Tile::Start();
	SetConfig(TileConfig::RANDOM_CONFIG);
}

Entity* TileO::AddBonus()
{
	return Tile::AddBonus(GetPosition() + BipolarConfig({ 3.f, 1.f, 0.f }, TileConfig::_1CONFIG, { 1.f, 1.f, 1.f }, TileConfig::_2CONFIG, { -1.f, 1.f, 1.f }));
}

void TileO::Make()
{
	if (GetConfig() == RANDOM_CONFIG)
	{
		SetConfig(GenerateRandomNumber(_1CONFIG, _2CONFIG));
	}

	SetSize({ 9.f ,9.f ,12.f });

	//backward ground
	Entity* e1 = Add<Entity>();
	e1->SetScale({ 3.f, 1.f, 3.f });
	e1->SetColor({ 0.f, 1.f, 0.f });
	e1->SetPosition({ 0.f, 0.f, 6.f });
	e1->SetTag(Entity::GROUND);

	//horizontal forward ground
	Entity* e2 = Add<Entity>();
	e2->SetScale({ 9.f, 1.f, 3.f });
	e2->SetColor({ 1.f, 0.f, 1.f });
	e2->SetPosition({ 0.f, 0.f, -3.f });
	e2->SetTag(Entity::GROUND);

	//deep left ground
	Entity* e3 = Add<Entity>();
	e3->SetScale({ 3.f , 1.f , 3.f });
	e3->SetColor({ 1.f, 0.f, 1.f });
	e3->SetPosition({ 3.f, 0.f, 0.f });
	e3->SetTag(Entity::GROUND);

	//deep right ground
	Entity* e4 = Add<Entity>();
	e4->SetScale({ 3.f , 1.f , 3.f });
	e4->SetColor({ 1.f, 0.f, 1.f });
	e4->SetPosition({ -3.f, 0.f, 0.f });
	e4->SetTag(Entity::GROUND);

	//horizontal backward ground
	Entity* e5 = Add<Entity>();
	e5->SetScale({ 9.f , 1.f , 3.f });
	e5->SetColor({ 1.f, 0.f, 1.f });
	e5->SetPosition({ 0.f, 0.f, 3.f });
	e5->SetTag(Entity::GROUND);

	if (GenerateRandomNumber(100) <= BONUS_CHANCE)
	{
		AddBonus();
	}
}