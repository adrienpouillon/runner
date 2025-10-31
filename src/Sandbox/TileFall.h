#pragma once
#include "Tile.h"
class TileFall : public Tile
{
public:
	TileFall();
	~TileFall();

	virtual void Start();

	virtual gce::Vector3f32 PosBonus();

	gce::Vector3f32 PosJump();

	virtual void Make() override;
};