#pragma once
#include "Tile.h"
class TileRightPath : public Tile
{
public:
	TileRightPath();
	~TileRightPath();

	virtual void Start();

	virtual Entity* AddBonus() override;

	virtual void Make() override;
};

