#pragma once
#include "Tile.h"
class TileO : public Tile
{
public:
	TileO();
	~TileO();

	virtual void Start();

	virtual Entity* AddBonus() override;

	virtual void Make() override;
};

