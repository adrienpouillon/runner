#pragma once
#include "pch.h"


class Entity
{
public:
	enum Tag {
		ENTITY,

		GROUND,
		CHARACTER,
		SPEED_BONUS,

		COUNT
	};
protected:
	Geometry* mGeometry;
	Tag mTag;
	bool mIsDead;

public:
	Entity();

	virtual void Start();

	virtual void Update(float deltaTime);

	virtual void OnCollision(Entity* other, gce::Vector3f32 penetration);

	virtual void Draw(Window* renderTarget);

	gce::Vector3f32 Collide(Entity* other);

	float IsCollide(float me_pos, float me_scale, float o_pos, float o_scale);

	void SetTexture(Texture& texture);
	void SetColor(const gce::Vector3f32& color);

	void SetGeometry(Geometry* geometry);
	void ReplaceGeometry(Geometry* geometry);
	Geometry* GetGeometry();

	void SetPosition(const gce::Vector3f32& xyz);
	gce::Vector3f32 GetPosition();

	void SetScale(const gce::Vector3f32& scale);
	gce::Vector3f32 GetScale();

	void SetRotation(const gce::Vector3f32& rotation);
	gce::Vector3f32 GetRotation();

	void SetIsDead(bool isDead);
	bool GetIsDead();

	void SetTag(Tag tag) { mTag = tag; }
	Tag GetTag() { return mTag; }
	bool IsTag(Tag tag) { return mTag == tag; }

	virtual ~Entity();
};

