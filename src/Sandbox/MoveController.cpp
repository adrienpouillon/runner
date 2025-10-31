#include "pch.h"
#include "MoveController.h"

#include "Character.h"
#include "ControlKeyboard.h"

MoveController::MoveController()
{
	Start();
}

void MoveController::Start()
{
	Controller::Start();

	SetCharacter(nullptr);
}

void MoveController::Update(float deltaTime)
{
	Controller::Update(deltaTime);
	/*std::vector<bool> allInputMove = GetAllMoveIsBeginPressed();
	bool left = allInputMove[0];
	bool up = allInputMove[1];
	bool right = allInputMove[2];
	bool up2 = allInputMove[3];*/
	bool left = GetIsBeginPressed(GetString(0));
	bool up = GetIsPressed(GetString(1));
	bool right = GetIsBeginPressed(GetString(2));
	bool up2 = GetIsPressed(GetString(3));

	gce::Vector3f32 velocity = mCharacter->GetVelocity();
	mCharacter->SetVelocity(gce::Vector3f32(0.f, velocity.y, velocity.z));

	if (left)
	{
		mCharacter->MoveLeft();
	}

	if (right)
	{
		mCharacter->MoveRight();
	}

	if (up || up2)
	{
		mCharacter->Jump();
	}
}



void MoveController::SetMoveKey(std::string string1, Keyboard::Key key1, std::string string2, Keyboard::Key key2, std::string string3, Keyboard::Key key3, std::string string4, Keyboard::Key key4)
{
	if (GetAllControl() != nullptr)
	{
		SetKeyboardKey(string1, key1);
		mAllString.push_back(string1);
		SetKeyboardKey(string2, key2);
		mAllString.push_back(string2);
		SetKeyboardKey(string3, key3);
		mAllString.push_back(string3);
		SetKeyboardKey(string4, key4);
		mAllString.push_back(string4);
		return;
	}
	std::cout << "MoveController::SetMoveKey() : mAllControl == nullptr" << std::endl;
}

std::vector<bool> MoveController::GetAllMoveIsBeginPressed()
{
	std::vector<bool> allIsPressed;

	int lenght = 4;
	for (int i = 0; i < lenght; i++)
	{
		allIsPressed.push_back(GetIsBeginPressed(GetString(i)));
	}

	return allIsPressed;
}

std::vector<bool> MoveController::GetAllMoveIsPressed()
{
	std::vector<bool> allIsPressed;

	int lenght = 4;
	for (int i = 0; i < lenght; i++)
	{
		allIsPressed.push_back(GetIsPressed(GetString(i)));
	}

	return allIsPressed;
}

std::vector<bool> MoveController::GetAllMoveIsEndPressed()
{
	std::vector<bool> allIsPressed;

	int lenght = 4;
	for (int i = 0; i < lenght; i++)
	{
		allIsPressed.push_back(GetIsEndPressed(GetString(i)));
	}

	return allIsPressed;
}

void MoveController::SetCharacter(Character* character)
{
	mCharacter = character;
}

Character* MoveController::GetCharacter()
{
	return mCharacter;
}
