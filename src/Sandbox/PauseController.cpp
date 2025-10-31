#include "pch.h"
#include "PauseController.h"

#include "Pause.h"

PauseController::PauseController()
{
	Start();
}

void PauseController::Start()
{
	SetPause(nullptr);
}

void PauseController::Update(float deltaTime)
{
	Controller::Update(deltaTime);

	bool pause = GetIsBeginPressed(GetString(PAUSE));
	if (pause)
	{
		mPause->InversePause();
	}

	bool restart = GetIsBeginPressed(GetString(RESTART));
	if (restart)
	{
		mPause->RestartGame();
	}

	bool quit = GetIsBeginPressed(GetString(QUIT));
	if (quit)
	{
		mPause->QuitGame();
	}
}

void PauseController::SetPauseKey(std::string string1, Keyboard::Key key1, std::string string2, Keyboard::Key key2, std::string string3, Keyboard::Key key3)
{
	if (GetAllControl() != nullptr)
	{
		SetKeyboardKey(string1, key1);
		mAllString.push_back(string1);
		SetKeyboardKey(string2, key2);
		mAllString.push_back(string2);
		SetKeyboardKey(string3, key3);
		mAllString.push_back(string3);
		return;
	}
	std::cout << "MoveController::SetPauseKey() : mAllControl == nullptr" << std::endl;
}

void PauseController::SetPause(Pause* pause)
{
	mPause = pause;
}

Pause* PauseController::GetPause()
{
	return mPause;
}
