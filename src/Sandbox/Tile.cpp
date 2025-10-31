#include "pch.h"
#include "Tile.h"
#include "Scene.h"
#include "DefineTile.h"


Tile::Tile()
{
	SetTag(TileType::BASIC);
}

Tile::~Tile()
{
	for (int i = mEntities.size() - 1; i > -1; i--)
	{
		delete mEntities[i];
	}
}

void Tile::Start()
{
	mSize = TILE_BASIC_SIZE;
	mPosition = gce::Vector3f32(0.f, 0.f, 0.f);
	SetConfig(TileConfig::CLASSIC_CONFIG);
}

void Tile::Update(float deltaTime)
{
	for (int i = 0; i < mEntities.size(); i++)
	{
		mEntities[i]->Update(deltaTime);
	}
}

void Tile::Draw(Window* renderTarget)
{
	for(int i = 0; i < mEntities.size(); i++)
	{
		mEntities[i]->Draw(renderTarget);
	}
}

void Tile::Make()
{
	Entity* e1 = Add<Entity>();
	e1->SetScale(ENTITY_D_SIZE);
	e1->SetTag(Entity::GROUND);

	if (GenerateRandomNumber(100) <= BONUS_CHANCE)
	{
		AddBonus();
	}
}

void Tile::CollideWithEntity(Entity* entityOther)
{
	int lenght_all_entity = mEntities.size();
	for (int i = 0; i < lenght_all_entity; i++)
	{
		Entity* entityTile = mEntities[i];
		gce::Vector3f32 penetration = entityTile->Collide(entityOther); 
		if (penetration != gce::Vector3f32(0.f, 0.f, 0.f))
		{
			entityTile->OnCollision(entityOther, penetration);
			entityOther->OnCollision(entityTile, penetration);
		}
	}
}

void Tile::CenterEntitiesOfTileOnZ()
{
	float sizeDiff = TILE_D_SIZE - mSize.z;

	for (int i = 0; i < mEntities.size(); i++)
	{
		gce::Vector3f32 entityPos = mEntities[i]->GetPosition();
		mEntities[i]->SetPosition({ entityPos.x, entityPos.y, entityPos.z - sizeDiff });
	}
}



void Tile::SetPosition(gce::Vector3f32 position)
{
	for (int i = 0; i < mEntities.size(); i++)
	{
		gce::Vector3f32 offset = mEntities[i]->GetPosition() - mPosition;
		mEntities[i]->SetPosition(position + offset);
	}
	mPosition = position;
}

void Tile::SetEntityPosition(Entity* entity, gce::Vector3f32 position)
{
	entity->SetPosition(mPosition + position);
}

void Tile::SetDead()
{
	for(int i = 0; i < mEntities.size(); i++)
	{
		mEntities[i]->SetIsDead(true);
	}
	mIsDead = true;
}

Entity* Tile::GetEntity(Entity::Tag tagOfEntity)
{
	for (int i = 0; i < mEntities.size(); i++)
	{
		if (mEntities[i]->IsTag(tagOfEntity))
		{
			return mEntities[i];
		}
	}
	return nullptr;
}

Entity* Tile::AddBonus()
{
	return AddBonus(mPosition + gce::Vector3f32{ 0.f, 1.f, 0.f });
}

Entity* Tile::AddBonus(gce::Vector3f32 bonusPos)
{
	Entity* e = Add<Entity>();
	e->SetGeometry(new Sphere);
	e->SetColor({ 1.f, 1.f, 0.f });
	e->SetTag(Entity::SPEED_BONUS);
	e->SetPosition(bonusPos);
	return e;
}


int Tile::GenerateRandomNumber(int min, int max)
{
	int range = max - min + 1;
	int value = rand() % range + min;
	return value;
}

int Tile::GenerateRandomNumber(int max)
{
	int value = rand() % (max + 1);
	return value;
}

gce::Vector3f32 Tile::MonopolaireConfig(gce::Vector3f32 classicPosition, TileConfig config1, gce::Vector3f32 toMulptiply1)
{
	if (mConfig == config1)
	{
		return classicPosition * toMulptiply1;
	}
	return gce::Vector3f32(0.f, 0.f, 0.f);
}

gce::Vector3f32 Tile::BipolarConfig(gce::Vector3f32 classicPosition, TileConfig config1, gce::Vector3f32 toMulptiply1, TileConfig config2, gce::Vector3f32 toMulptiply2)
{
	if (mConfig == config1)
	{
		return classicPosition * toMulptiply1;
	}
	if (mConfig == config2)
	{
		return classicPosition * toMulptiply2;
	}
	return classicPosition;
}

gce::Vector3f32 Tile::TripolarConfig(gce::Vector3f32 classicPosition, TileConfig config1, gce::Vector3f32 toMulptiply1, TileConfig config2, gce::Vector3f32 toMulptiply2, TileConfig config3, gce::Vector3f32 toMulptiply3)
{
	if (mConfig == config1)
	{
		return classicPosition * toMulptiply1;
	}
	if (mConfig == config2)
	{
		return classicPosition * toMulptiply2;
	}
	if (mConfig == config3)
	{
		return classicPosition * toMulptiply2;
	}
	return classicPosition;
}