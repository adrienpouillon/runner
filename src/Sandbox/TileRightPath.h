#pragma once
#include "Tile.h"
class TileRightPath : public Tile
{
public:
	TileRightPath();
	~TileRightPath();

	virtual void Start();

	virtual gce::Vector3f32 PosBonus();

	gce::Vector3f32 PosJump();

	virtual void Make() override;
};

