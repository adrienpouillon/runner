#pragma once
#include "Tile.h"
class TileCrossroads :public Tile
{
public:
	TileCrossroads();
	~TileCrossroads();

	virtual void Start();

	virtual gce::Vector3f32 PosBonus();

	gce::Vector3f32 PosJump();

	virtual void Make() override;
};

