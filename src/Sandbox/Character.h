#pragma once
#include "pch.h"

#include "Entity.h"

#define LATERAL_VELOCITY 3.f
#define JUMP 12.f

#define MAX_X TILE_D_SIZE * 0.5 * NB_PATH_TILE

class Character : public Entity
{
	gce::Vector3f32 mVelocity;
	gce::Vector3f32 mMove;
	gce::Vector3f32 mMaxVelocity;
	float mGravity;

	bool mBoost;

public:
	Character();
	~Character();

	void Start();

	void Update(float deltaTime);

	virtual void OnCollision(Entity* other, gce::Vector3f32 penetration);

	void MoveLeft();
	void MoveRight();
	void Jump();

	float SpeedIsBoost(float velocity, float maxVelocity);
	float MaxSpeedIsBoost(float deltaTime);

	void SetGravity(float gravity);
	float GetGravity();

	void SetBoost(bool boost);
	bool GetBoost();

	void SetVelocity(gce::Vector3f32 velocity);
	gce::Vector3f32 GetVelocity();

	void SetMove(gce::Vector3f32 move);
	gce::Vector3f32 GetMove();

	void SetMaxVelocity(gce::Vector3f32 maxVelocity);
	gce::Vector3f32 GetMaxVelocity();



};

