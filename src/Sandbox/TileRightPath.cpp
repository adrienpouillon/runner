#include "pch.h"
#include "TileRightPath.h"
#include "Entity.h"
#include "DefineTile.h"

TileRightPath::TileRightPath()
{
	SetTag(TileType::RIGHT_PATH);
}

TileRightPath::~TileRightPath()
{
	Tile::~Tile();
}

void TileRightPath::Start()
{
	Tile::Start();
	SetConfig(TileConfig::RANDOM_CONFIG);
}

Entity* TileRightPath::AddBonus()
{
	return Tile::AddBonus(GetPosition() + BipolarConfig({ 3.f, 3.f, 0.f }, TileConfig::_1CONFIG, { 1.f, 1.f, 1.f }, TileConfig::_2CONFIG, { -1.f, 1.f, 1.f }));
}

void TileRightPath::Make()
{
	if (GetConfig() == RANDOM_CONFIG)
	{
		SetConfig(GenerateRandomNumber(_1CONFIG, _2CONFIG));
	}

	SetSize(TILE_BASIC_SIZE);

	//deep ground
	Entity* e1 = Add<Entity>();
	e1->SetScale({ 3.f , 1.f, 9.f });
	e1->SetColor({ 0.f, 1.f, 0.f });
	e1->SetPosition(BipolarConfig({ 3.f, 0.f, 0.f }, TileConfig::_1CONFIG, { 1.f, 1.f, 1.f }, TileConfig::_2CONFIG, { -1.f, 1.f, 1.f }));
	e1->SetTag(Entity::GROUND);

	if (GenerateRandomNumber(100) <= BONUS_CHANCE)
	{
		AddBonus();
	}

	CenterEntitiesOfTileOnZ();
}
