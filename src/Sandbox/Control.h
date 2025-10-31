#pragma once
#include "pch.h"

class Control
{
protected:
	std::string mStringId;
public:

	Control();

	virtual void Start();

	virtual void Update(float deltaTime);

	virtual bool GetIsBeginPressed() = 0;
	virtual bool GetIsPressed() = 0;
	virtual bool GetIsEndPressed() = 0;


	void SetString(std::string stringId);
	std::string GetString();

};

