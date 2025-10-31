#pragma once
#include "Tile.h"
class TileFall : public Tile
{
public:
	TileFall();
	~TileFall();

	virtual void Start();

	virtual Entity* AddBonus() override;

	virtual void Make() override;
};