#pragma once
#include "pch.h"
#include <vector>
#include "Tile.h"
#include "CharacterCameraC.h"

#define LENGHT_TILE_COLLIDE 3
#define NB_PATH_TILE 1
#define INFINITE_PATH_LENGHT 400.f

#define MAX_VELOCITY_PLAYER 15.f

#define INCREASE_VELOCITY_PLAYER 0.003f
#define REDUCE_VELOCITY_PLAYER 0.003f
#define MULTIPLICATOR_MAX_VELOCITY_PLAYER 0.004f

class Character;
class Controller;
class Pause;

class Scene
{
	std::vector<Controller*> mInputs;
	std::vector<Tile*> mTiles;
	Character* mCharacter;
	CameraC* mCamera;
	Text* mText;
	Pause* mPause;

	bool mEnd;
	bool mFinish;
	bool mRestart;
	
	gce::Vector3f32 mPositionFormer;

public:
	Scene();

	virtual void Start();

	void Update(float deltaTime);
	void Draw(Window* renderTarget);

	void CreateCharacterCameraC();
	void CreateCharacter();
	void CreateText();
	void CreatePause();

	template<typename T>
	T* AddTile();
	template<typename T>
	T* AddInput();

	Tile* AddRandomTile();
	

	void UpdateInfinitePath();
	void ExtendInfinitePath();
	void DeletePastTile();

	template<typename T>
	void DeleteAll(std::vector<T*>* all);
	template<typename T>
	void DeleteAll(std::vector<T*> all);

	int GenerateRandomNumber(int min, int max);
	int GenerateRandomNumber(int max);

	void SetCharacter(Character* character) { mCharacter = character; }
	Character* GetCharacter() { return mCharacter; }

	void SetCamera(CameraC* camera);
	CameraC* GetCamera() { return mCamera; }

	void SetText(Text* text) { mText = text; }
	Text* GetText() { return mText; }

	void SetPause(Pause* pause) { mPause = pause; }
	Pause* GetPause() { return mPause; }

	void SetEnd(bool end) { mEnd = end; }
	bool GetEnd() { return mEnd; }

	void SetFinish(bool finish) { mFinish = finish; }
	bool GetFinish() { return mFinish; }

	void SetRestart(bool restart) { mRestart = restart; }
	bool GetRestart() { return mRestart; }

	void FinishScene();

	virtual ~Scene();
};

template<typename T>
inline T* Scene::AddTile()
{
	T* tile = new T();
	mTiles.push_back(tile);
	tile->Start();
	return tile;
}

template<typename T>
inline T* Scene::AddInput()
{
	T* input = new T();
	mInputs.push_back(input);
	input->Start();
	return input;
}

template<typename T>
inline void Scene::DeleteAll(std::vector<T*>* all)
{
	int lenghtAll = all->size() - 1;
	for (int i = lenghtAll; i > -1; i--)
	{
		delete (*all)[i];
	}
	delete all;
}

template<typename T>
inline void Scene::DeleteAll(std::vector<T*> all)
{
	int lenghtAll = all.size() - 1;
	for (int i = lenghtAll; i > -1; i--)
	{
		delete all[i];
	}
}
