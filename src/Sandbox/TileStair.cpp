#include "pch.h"
#include "TileStair.h"
#include "Entity.h"
#include "DefineTile.h"

TileStair::TileStair()
{
	SetTag(TileType::STAIR);
}

TileStair::~TileStair()
{
	Tile::~Tile();
}

void TileStair::Start()
{
	Tile::Start();
	SetConfig(TileConfig::RANDOM_CONFIG);
}

Entity* TileStair::AddBonus()
{
	return Tile::AddBonus(GetPosition() + BipolarConfig({ 3.f, 4.f, 6.f }, TileConfig::_1CONFIG, { 1.f, 1.f, 1.f }, TileConfig::_2CONFIG, { -1.f, 1.f, 1.f }));
}

void TileStair::Make()
{
	if (GetConfig() == RANDOM_CONFIG)
	{
		SetConfig(GenerateRandomNumber(_1CONFIG, _2CONFIG));
	}

	SetSize({ 9.f ,3.f ,30.f });

	gce::Vector3f32 pos = gce::Vector3f32(0.f, 1.f, 0.f);

	//ground up 1
	Entity* e1 = Add<Entity>();
	e1->SetScale({ 6.f, 1.f, 9.f });
	e1->SetPosition(BipolarConfig(gce::Vector3f32(pos.x + 1.5f, pos.y, pos.z), TileConfig::_1CONFIG, { -1.f, 1.f, 1.f }, TileConfig::_2CONFIG, { 1.f, 1.f, 1.f }));
	e1->SetTag(Entity::GROUND);
	e1->SetColor({ 0.5f, 0.5f, 0.5f });

	//ground up 2
	Entity* e2 = Add<Entity>();
	e2->SetScale({9.f, 1.f, 9.f});
	e2->SetPosition(pos + gce::Vector3f32(0.f, 1.f, 9.f));
	e2->SetTag(Entity::GROUND);
	e2->SetColor({ 0.5f, 0.5f, 0.5f });

	/*//dalle up
	Entity* e3 = Add<Entity>();
	e3->SetScale({ 3.f, 1.f, 3.f });
	e3->SetPosition(BipolarConfig({ 3.f, pos.y + 1.f, pos.z + 3.f }, TileConfig::_1CONFIG, { -1.f, 1.f, 1.f }, TileConfig::_2CONFIG, { 1.f, 1.f, 1.f }));
	e3->SetTag(Entity::GROUND);
	e3->SetColor({ 0.5f, 0.5f, 0.5f });*/

	//dalle up 2
	Entity* e4 = Add<Entity>();
	e4->SetScale({ 3.f, 1.f, 6.f });
	e4->SetPosition(e2->GetPosition() + gce::Vector3f32(0.f, 1.f, 1.5f));
	e4->SetTag(Entity::GROUND);
	e4->SetColor({ 0.5f, 0.5f, 0.5f });

	//ground up 3
	Entity* e5 = Add<Entity>();
	e5->SetScale({ 9.f, 1.f, 12.f });
	e5->SetPosition(e2->GetPosition() + gce::Vector3f32(0.f, 1.f, 10.5f));
	e5->SetTag(Entity::GROUND);
	e5->SetColor({ 0.5f, 0.5f, 0.5f });

	//up backward ground
	Entity* e6 = Add<Entity>();
	e6->SetScale({ 3.f , 3.f , 18.f });
	e6->SetColor({ 0.5f, 0.5f, 0.5f });
	e6->SetPosition(BipolarConfig({ 3.f, 2.f, 4.5f }, TileConfig::_1CONFIG, { 1.f, 1.f, 1.f }, TileConfig::_2CONFIG, { -1.f, 1.f, 1.f }));
	e6->SetTag(Entity::GROUND);

	if (GenerateRandomNumber(100) <= BONUS_CHANCE)
	{
		AddBonus();
	}
}