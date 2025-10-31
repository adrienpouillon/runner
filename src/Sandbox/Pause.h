#pragma once
#include "Scene.h"
#include "PauseController.h"

class Pause
{
protected:
	bool mPause;
	std::wstring mStringPause;
	Scene* mScene;
public:
	Pause();
	virtual ~Pause();

	virtual void Start();

	void Update(float deltaTime);

	void RestartGame();

	void QuitGame();

	void SetPause(bool pause) { mPause = pause; }
	void InversePause() { mPause = !mPause; }
	bool GetPause() { return mPause; }

	void SetText(std::wstring stringPause) { mStringPause = stringPause; }
	std::wstring GetText() { return mStringPause; }

	void SetScene(Scene* scene) { mScene = scene; }
	Scene* GetScene() { return mScene; }
};

