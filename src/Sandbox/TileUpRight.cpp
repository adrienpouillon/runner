#include "pch.h"
#include "TileUpRight.h"
#include "Entity.h"
#include "DefineTile.h"

TileUpRight::TileUpRight()
{
	SetTag(TileType::UP_RIGHT);
}

TileUpRight::~TileUpRight()
{
	Tile::~Tile();
}

void TileUpRight::Start()
{
	Tile::Start();
	SetConfig(TileConfig::CLASSIC_CONFIG);
}

Entity* TileUpRight::AddBonus()
{
	return Tile::AddBonus(GetPosition() + gce::Vector3f32{ 0.f, 2.f, -3.f });
}

void TileUpRight::Make()
{
	/*if (mConfig == RANDOM_CONFIG)
	{
		SetConfig(GenerateRandomNumber(_1CONFIG, _2CONFIG));
	}*/
	SetSize({ 9.f ,9.f ,9.f });

	//deep ground
	Entity* e1 = Add<Entity>();
	e1->SetScale({ 3.f, 1.f, 9.f });
	e1->SetColor({ 0.f, 1.f, 0.f });
	e1->SetPosition({ -3.f, 0.f, 0.f });
	e1->SetTag(Entity::GROUND);

	//vertical ground
	Entity* e2 = Add<Entity>();
	e2->SetScale({ 6.f , 3.f , 9.f});
	e2->SetColor({ 0.5f, 0.5f, 0.5f });
	e2->SetPosition({ e1->GetScale().x / 2, 0.f, 0.f });
	e2->SetTag(Entity::GROUND);

	if (GenerateRandomNumber(100) <= BONUS_CHANCE)
	{
		AddBonus();
	}
}