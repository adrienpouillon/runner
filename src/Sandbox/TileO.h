#pragma once
#include "Tile.h"
class TileO : public Tile
{
public:
	TileO();
	~TileO();

	virtual void Start();

	virtual gce::Vector3f32 PosBonus();

	gce::Vector3f32 PosJump();

	virtual void Make() override;
};

