#pragma once
#include "Tile.h"

class TileOneVoid : public Tile
{
public:
	TileOneVoid();
	~TileOneVoid();

	virtual void Start();

	virtual void Make() override;

	virtual Entity* AddBonus() override;
};

