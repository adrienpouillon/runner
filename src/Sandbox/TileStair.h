#pragma once
#include "Tile.h"
class TileStair : public Tile
{
public:
	TileStair();
	~TileStair();

	virtual void Start();

	virtual gce::Vector3f32 PosBonus();

	gce::Vector3f32 PosJump();

	virtual void Make() override;
};

