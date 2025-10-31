#pragma once
#include "pch.h"

class Scene;

class GameManager
{
	static GameManager* mInstance;
	Window mWindow;
	Scene* mScene = nullptr;

	bool mIsRunning = true;
	float mPauseCooldown = 0.f;

public:
	static GameManager* GetInstance();

	GameManager();
	~GameManager();
	void Init();

	void Update(float deltaTime);
	void Draw();
	void Run();

	
	void DeleteCurrentScene();

	template<typename T>
	T* CreateScene();
};

template<typename T>
inline T* GameManager::CreateScene()
{
	if (mScene)
	{
		delete mScene;
	}
	T* t = new T();
	mScene = t;
	t->Start();
	return t;
}
