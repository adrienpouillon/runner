#pragma once
#include "Tile.h"

class TileL : public Tile
{
public:
	TileL();
	~TileL();

	virtual void Start();
	
	virtual gce::Vector3f32 PosBonus();

	gce::Vector3f32 PosJump();

	virtual void Make() override;
};

