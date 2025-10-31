#pragma once
#include "pch.h"
#include "Controller.h"

class Character;

class MoveController :public Controller
{
protected:
	Keyboard::Key mKeyTarget;
	Character* mCharacter;
public:

	MoveController();

	virtual void Start();

	virtual void Update(float deltaTime);

	void SetMoveKey(std::string string1, Keyboard::Key key1, std::string string2, Keyboard::Key key2, std::string string3, Keyboard::Key key3, std::string string4, Keyboard::Key key4);

	std::vector<bool> GetAllMoveIsBeginPressed();
	std::vector<bool> GetAllMoveIsPressed();
	std::vector<bool> GetAllMoveIsEndPressed();

	void SetCharacter(Character* character);
	Character* GetCharacter();

};

