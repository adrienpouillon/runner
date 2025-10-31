#pragma once
#include "Tile.h"
class TileUpRight :public Tile
{
public:
	TileUpRight();
	~TileUpRight();

	virtual void Start();

	virtual gce::Vector3f32 PosBonus();

	gce::Vector3f32 PosJump();

	virtual void Make() override;
};

