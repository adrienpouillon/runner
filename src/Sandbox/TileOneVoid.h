#pragma once
#include "Tile.h"

class TileOneVoid : public Tile
{
public:
	TileOneVoid();
	~TileOneVoid();

	virtual void Start();

	virtual gce::Vector3f32 PosBonus();

	gce::Vector3f32 PosJump();

	virtual void Make() override;
};

