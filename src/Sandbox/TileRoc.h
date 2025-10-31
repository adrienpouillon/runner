#pragma once
#include "Tile.h"
class TileRoc : public Tile
{
public:
	TileRoc();
	~TileRoc();

	virtual void Start();

	virtual Entity* AddBonus() override;

	virtual void Make() override;
};

