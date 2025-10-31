#pragma once
#include "Entity.h"

#define BONUS_CHANCE 50.f
#define MALUS_CHANCE 10.f
#define JUMP_CHANCE 30.f


class Tile
{
public:
	enum TileType
	{
		BASIC,
		CANYON,
		CROSSROAD,
		FALL,
		L,
		O,
		ONE_VOID,
		RIGHT_PATH,
		ROC,
		STAIR,
		UP_RIGHT,

		COUNT
	};

	enum TileBiome
	{
		PLAINE,
		NEIGE,
		DESERT,
		HANTE,

		RANDOM_BIOME
	};

	enum TileConfig
	{
		CLASSIC_CONFIG,
		_1CONFIG,
		_2CONFIG,
		_3CONFIG,

		RANDOM_CONFIG
	};

private:
	std::vector<Entity*> mEntities;
	bool mIsDead;
	TileType mTag;
	gce::Vector3f32 mPosition;
	gce::Vector3f32 mSize;
	int mConfig;


public:
	Tile();
	~Tile();
	virtual void Start();

	virtual void Update(float deltaTime);
	virtual void Draw(Window* renderTarget);

	virtual void Make();

	virtual Entity* CreatBonus(int nb_bonus);
	virtual Entity* CreatJump(int nb_bonus);

	virtual Entity* ChooseBonusMalus(int nb_malus, gce::Vector3f32 pos);

	virtual gce::Vector3f32 PosBonus();
	virtual gce::Vector3f32 PosJump();

	Entity* AddBonus(gce::Vector3f32 bonusPos);
	Entity* AddMalus(gce::Vector3f32 bonusPos);
	Entity* AddJump(gce::Vector3f32 bonusPos);

	void CollideWithEntity(Entity* entity);

	template<typename T>
	T* Add();

	void CenterEntitiesOfTileOnZ();

	gce::Vector3f32 GetPosition() { return mPosition; }
	void SetPosition(gce::Vector3f32 position);

	void SetEntityPosition(Entity* entity, gce::Vector3f32 position);

	gce::Vector3f32 GetSize() { return mSize; }
	void SetSize(gce::Vector3f32 size) { mSize = size; }

	void SetTag(TileType tag) { mTag = tag; }
	TileType GetTag() { return mTag; }
	bool IsTag(TileType tileType) { return mTag == tileType; }

	void SetDead();
	bool IsDead() { return mIsDead; }

	void SetConfig(int config) { mConfig = config; }
	int GetConfig() { return mConfig; }

	Entity* GetEntity(Entity::Tag tagOfEntity);


	int GenerateRandomNumber(int min, int max);
	int GenerateRandomNumber(int max);

	gce::Vector3f32 MonopolaireConfig(gce::Vector3f32 classicPosition, TileConfig config1, gce::Vector3f32 toMulptiply1);
	gce::Vector3f32 BipolarConfig(gce::Vector3f32 classicPosition, TileConfig config1, gce::Vector3f32 toMulptiply1, TileConfig config2, gce::Vector3f32 toMulptiply2);
	gce::Vector3f32 TripolarConfig(gce::Vector3f32 classicPosition, TileConfig config1, gce::Vector3f32 toMulptiply1, TileConfig config2, gce::Vector3f32 toMulptiply2, TileConfig config3, gce::Vector3f32 toMulptiply3);
};

template<typename T>
inline T* Tile::Add()
{
	T* entity = new T();
	entity->Start();
	mEntities.push_back(entity);
	return entity;
}