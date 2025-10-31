#pragma once
#include "Tile.h"
class TileCanyon :
	public Tile
{
public:
	TileCanyon();
	~TileCanyon();

	virtual void Start();

	virtual Entity* AddBonus() override;

	virtual void Make() override;
};

