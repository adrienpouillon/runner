#include "pch.h"
#include "GameManager.h"
#include <chrono>
#include "Scene.h"


GameManager* GameManager::mInstance = nullptr;

GameManager* GameManager::GetInstance()
{
	if (mInstance == nullptr)
	{
		mInstance = new GameManager();
	}
	return mInstance;
}

GameManager::GameManager() : mWindow(L"Game Engine", 1920, 1080)
{
}

GameManager::~GameManager()
{
}

void GameManager::Init()
{
	srand(time(NULL));
}

void GameManager::Update(float deltaTime)
{
	if (mScene)
	{
		mScene->Update(deltaTime);
	}
}

void GameManager::Draw()
{
	if(mScene == nullptr)
	{
		return;
	}
	mWindow.Begin(*mScene->GetCamera()->GetCamera());
	if (mScene)
	{
		mScene->Draw(&mWindow);
	}
	mWindow.End();
	mWindow.Display();
}

void GameManager::Run()
{
	using clock = std::chrono::high_resolution_clock;
	auto lastTime = clock::now();
	while (mWindow.IsOpen())
	{
		auto currentTime = clock::now();
		std::chrono::duration<float> delta = currentTime - lastTime;
		float deltaTime = delta.count();  // en secondes
		lastTime = currentTime;

		if(mScene->GetFinish() == false)
		{
			Update(deltaTime);
			Draw();
		}
		else
		{
			if (mScene->GetRestart())
			{
				DeleteCurrentScene();
				mScene->Start();
			}
			else
			{
				
				break;
			}
		}
	}
}

void GameManager::DeleteCurrentScene()
{
	//delete mScene;
	mScene->FinishScene();
}
