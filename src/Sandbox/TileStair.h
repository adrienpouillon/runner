#pragma once
#include "Tile.h"
class TileStair : public Tile
{
public:
	TileStair();
	~TileStair();

	virtual void Start();

	virtual Entity* AddBonus() override;

	virtual void Make() override;
};

