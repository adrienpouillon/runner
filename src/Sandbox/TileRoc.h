#pragma once
#include "Tile.h"
class TileRoc : public Tile
{
public:
	TileRoc();
	~TileRoc();

	virtual void Start();

	virtual gce::Vector3f32 PosBonus();

	gce::Vector3f32 PosJump();

	virtual void Make() override;
};

