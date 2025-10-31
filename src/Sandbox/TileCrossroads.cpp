#include "pch.h"
#include "TileCrossroads.h"
#include "Entity.h"
#include "DefineTile.h"

TileCrossroads::TileCrossroads()
{
	SetTag(TileType::CROSSROAD);
}

TileCrossroads::~TileCrossroads()
{
	Tile::~Tile();
}

void TileCrossroads::Start()
{
	Tile::Start();
	SetConfig(TileConfig::RANDOM_CONFIG);
}

gce::Vector3f32 TileCrossroads::PosBonus()
{
	return GetPosition() + gce::Vector3f32{ 0.f, 1.f, 0.f };
}

gce::Vector3f32 TileCrossroads::PosJump()
{
	return GetPosition() + BipolarConfig({ 3.f, 1.f, 9.f }, TileConfig::_1CONFIG, { 1.f, 1.f, 1.f }, TileConfig::_2CONFIG, { -1.f, 1.f, 1.f });
}

void TileCrossroads::Make()
{

	if (GetConfig() == RANDOM_CONFIG)
	{
		SetConfig(GenerateRandomNumber(CLASSIC_CONFIG, _2CONFIG));
	}

	SetSize({ 9.f ,9.f ,15.f });

	//ground 1
	Entity* e1 = Add<Entity>();
	e1->SetScale({ 3.f, 1.f, 9.f });
	e1->SetColor({ 1.f, 1.f, 1.f });
	e1->SetPosition({ 0.f, 0.f, 0.f });
	e1->SetTag(Entity::GROUND);

	if (GetConfig() != _2CONFIG)
	{//mConfig == CLASSIC_CONFIG && mConfig == _1CONFIG
		//deep ground 1
		Entity* e2 = Add<Entity>();
		e2->SetScale({ 3.f , 1.f , 10.5f });
		e2->SetColor({ 1.f, 1.f, 0.f });
		e2->SetPosition({ -3.f, 0.f, 5.25f });
		e2->SetTag(Entity::GROUND);
	}
	
	if (GetConfig() != _1CONFIG)
	{//mConfig == CLASSIC_CONFIG && mConfig == _2CONFIG
		//deep ground 2
		Entity* e3 = Add<Entity>();
		e3->SetScale({ 3.f , 1.f , 10.5f });
		e3->SetColor({ 1.f, 1.f, 0.f });
		e3->SetPosition({ 3.f, 0.f, 5.25f });
		e3->SetTag(Entity::GROUND);
	}

	CreatBonus(100);
	CreatJump(100);
}

