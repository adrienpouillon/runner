#include "pch.h"
#include "Pause.h"
#include "PauseController.h"


Pause::Pause()
{

}

Pause::~Pause()
{
	
}

void Pause::Start()
{
	SetText(L"vide");
	SetPause(false);
	SetScene(nullptr);
}

void Pause::Update(float deltaTime)
{
	
}

void Pause::RestartGame()
{
	mScene->SetFinish(true);
	mScene->SetRestart(true);
}

void Pause::QuitGame()
{
	mScene->SetEnd(true);
	mScene->SetFinish(true);
	mScene->SetRestart(false);
}