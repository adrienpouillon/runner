#pragma once
#include "Tile.h"
class TileCanyon :
	public Tile
{
public:
	TileCanyon();
	~TileCanyon();

	virtual void Start();

	virtual gce::Vector3f32 PosBonus();

	gce::Vector3f32 PosJump();

	virtual void Make() override;
};

