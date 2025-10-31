#pragma once
#include "Tile.h"
class TileUpRight :public Tile
{
public:
	TileUpRight();
	~TileUpRight();

	virtual void Start();

	virtual Entity* AddBonus() override;

	virtual void Make() override;
};

