#pragma once
#include "Tile.h"

class TileL : public Tile
{
public:
	TileL();
	~TileL();

	virtual void Start();
	
	virtual Entity* AddBonus() override;

	virtual void Make() override;
};

