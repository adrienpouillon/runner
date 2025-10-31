#pragma once
#include "Tile.h"
class TileCrossroads :public Tile
{
public:
	TileCrossroads();
	~TileCrossroads();

	virtual void Start();

	virtual Entity* AddBonus() override;

	virtual void Make() override;
};

