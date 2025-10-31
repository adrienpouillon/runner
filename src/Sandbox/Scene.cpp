#include "pch.h"
#include "Scene.h"
#include "Character.h"
#include "Pause.h"
#include "ControlKeyboard.h"
#include "MoveController.h"

#include "TileL.h"
#include "TileUpRight.h"
#include "TileRightPath.h"
#include "TileOneVoid.h"
#include "TileCanyon.h"
#include "TileCrossroads.h"
#include "TileRoc.h"
#include "TileO.h"
#include "TileStair.h"
#include "TileFall.h"



Scene::Scene()
{
	SetCamera(nullptr);
}

void Scene::Start()
{
	SetCharacter(nullptr);
	SetText(nullptr);
	SetPause(nullptr);
	mInputs = std::vector<Controller*>();
	mTiles = std::vector<Tile*>();

	CreateCharacter();
	if (mCamera == nullptr)
	{
		CreateCharacterCameraC();
	}
	else
	{
		if (CharacterCameraC* ccc = dynamic_cast<CharacterCameraC*>(mCamera))
		{
			ccc->SetTarget(mCharacter);
		}
	}
	CreateText();
	CreatePause();

	SetEnd(false);
	SetFinish(false);
	SetRestart(false);
	mPositionFormer = gce::Vector3f32(0.f, 0.f, 0.f);
}

void Scene::Update(float deltaTime)
{
	for (Controller* input : mInputs)
	{
		input->Update(deltaTime);
	}

	mPause->Update(deltaTime);
	if (mPause->GetPause())
	{
		deltaTime = 0.f;
		mText->SetPosition({ 600.0f, 400.0f });
		mText->SetText(mPause->GetText());
	}
	
	if (mEnd)
	{
		mCharacter->Update(0.f);
		mCamera->Update(deltaTime, mEnd);
		return;
	}

	UpdateInfinitePath();

	if (mCharacter)
	{
		mCharacter->Update(deltaTime);
	}
	for (Tile* tile : mTiles)
	{
		tile->Update(deltaTime);
	}
	int lenghtNearTile = LENGHT_TILE_COLLIDE * NB_PATH_TILE;
	if (lenghtNearTile > mTiles.size())
	{
		lenghtNearTile = mTiles.size();
	}
	for (int i = 0; i < lenghtNearTile; i++)
	{
		mTiles[i]->CollideWithEntity(mCharacter);
	}

	mCamera->Update(deltaTime);

	if (mPause->GetPause() == false)
	{
		if (mText)
		{
			mText->SetPosition({ 10.0f, 10.0f });
			if (mCharacter)
			{
				int score = (int)(mCharacter->GetPosition().z);
				mText->SetText(L"Score : " + std::to_wstring(score));
			}
			else
			{
				mText->SetText(L"Score : ");
			}
		}

		if (mCharacter)
		{
			gce::Vector3f32 positionPlayer = mCharacter->GetPosition();
			gce::Vector3f32 velocityPlayer = mCharacter->GetVelocity();
			if ((positionPlayer.x == mPositionFormer.x && positionPlayer.y == mPositionFormer.y && positionPlayer.z == mPositionFormer.z) || (velocityPlayer.y > 50.f || velocityPlayer.y < -50.f))
			{
				mEnd = true;

			}
			mPositionFormer = positionPlayer;
		}
	}
}

void Scene::Draw(Window* renderTarget)
{
	for (Tile* tile : mTiles)
	{
		tile->Draw(renderTarget);
	}
	if (mCharacter)
	{
		mCharacter->Draw(renderTarget);
	}
	if (mText)
	{
		renderTarget->DrawText(*mText);
	}
}


void Scene::CreateCharacterCameraC()
{
	mCamera = new CharacterCameraC();
	mCamera->Start();
	mCamera->SetPosition({ 0.f, 10.f, -10.f });
	mCamera->SetRotation({ 20.f, 0.f, 0.f });

	CharacterCameraC* characterCamera = dynamic_cast<CharacterCameraC*>(mCamera);
	characterCamera->SetTarget(mCharacter);
	characterCamera->SetOffset({ 0.f, 3.5f, -8.f });
}

void Scene::CreateCharacter()
{
	mCharacter = new Character();
	mCharacter->Start();
	mCharacter->SetPosition({ 0.f, 2.f, 0.f });

	mCharacter->SetVelocity(gce::Vector3f32(0.f, 0.f, MAX_VELOCITY_PLAYER * 0.75));
	mCharacter->SetMaxVelocity(gce::Vector3f32(1.f, 20.f, MAX_VELOCITY_PLAYER));
	mCharacter->SetGravity(0.52f);
	
	MoveController* moveInput = AddInput<MoveController>();
	moveInput->SetCharacter(mCharacter);
	moveInput->SetAllControl(new std::vector<Control*>());
	moveInput->SetMoveKey("Left", Keyboard::LEFT_ARROW, "Up", Keyboard::UP_ARROW, "Right", Keyboard::RIGHT_ARROW, "Up2", Keyboard::DOWN_ARROW);
}

void Scene::CreateText()
{
	gce::Font* font = new gce::Font(L"Arial");

	mText = new Text;
	mText->SetFont(font);
	mText->SetText(L"0");
	mText->SetPosition({ 10.0f, 10.0f });
	mText->SetColor(gce::Color::Red);
}

void Scene::CreatePause()
{
	mPause = new Pause;
	mPause->SetText(L"          !!!  Pause  !!!          \n"
	 + std::wstring(L"     'Esc' pour reprendre          \n")
	 + std::wstring(L"     'Entre'' pour recommencer     \n")
	 + std::wstring(L"     'Effacer' pour quitter        \n"));
	mPause->SetPause(false);
	mPause->SetScene(this);

	PauseController* inputPause = AddInput<PauseController>();
	inputPause->SetPause(mPause);
	inputPause->SetAllControl(new std::vector<Control*>());
	inputPause->SetPauseKey("Esc", Keyboard::ESC, "Entre", Keyboard::ENTER, "Quit", Keyboard::BACKSPACE);
}

Tile* Scene::AddRandomTile()
{
	float tileType = GenerateRandomNumber(200);
	
	if (tileType < 6.f)
	{
		return AddTile<TileCanyon>();
	}
	else if (tileType < 12.f)
	{
		return AddTile<TileRoc>();
	}
	else if (tileType < 25.f)
	{
		return AddTile<TileO>();
	}
	else if(tileType < 37.f)
	{
		return AddTile<TileUpRight>();
	}
	else if (tileType < 50.f)
	{
		return AddTile<TileCrossroads>();
	}
	else if (tileType < 62.f)
	{
		return AddTile<TileRightPath>();
	}
	else if (tileType < 75.f)
	{
		return AddTile<TileL>();
	}
	else if (tileType < 100.f)
	{
		return AddTile<TileOneVoid>();
	}
	else if (tileType < 150.f)
	{
		return AddTile<Tile>();
	}
	else if (tileType < 175.f)
	{
		return AddTile<TileFall>();
	}
	else if (tileType < 200.f)
	{
		return AddTile<TileStair>();
	}

	else
	{
		return nullptr;
	}
}

void Scene::UpdateInfinitePath()
{
	if (not mCharacter)
	{
		return;
	}
	
	gce::Vector3f32 characterPosition = mCharacter->GetPosition();

	ExtendInfinitePath();
	if (mTiles.size() == 0)
	{
		return;
	}
	if(characterPosition.z > mTiles[0]->GetPosition().z + mTiles[0]->GetSize().z)
	{ 
		DeletePastTile();
	}
}

void Scene::ExtendInfinitePath()
{
	float pathSize = 0.f;

	for(int i = 0; i < mTiles.size(); i++)
	{
		pathSize += mTiles[i]->GetSize().z;
	}
	if (pathSize <= INFINITE_PATH_LENGHT)
	{
		Tile* tile;
		if (pathSize > INFINITE_PATH_LENGHT * 0.05f)
		{
			tile = AddRandomTile();
		}
		else
		{
			tile = AddTile<Tile>();
		}
		
		if(tile == nullptr)
		{
			return;
		}
		tile->Make();
		if(mTiles.size() >= 2)
		{
			Tile* lastTile = mTiles[mTiles.size() - 2];

			gce::Vector3f32 lastTilePosition = lastTile->GetPosition();
			gce::Vector3f32 lastTileSize = lastTile->GetSize();

			if (lastTile->IsTag(Tile::TileType::STAIR))
			{
				tile->SetPosition({ lastTilePosition.x, lastTilePosition.y + lastTileSize.y, lastTilePosition.z + lastTileSize.z });
			}
			else if (lastTile->IsTag(Tile::TileType::FALL))
			{
				tile->SetPosition({ lastTilePosition.x, lastTilePosition.y - lastTileSize.y, lastTilePosition.z + lastTileSize.z });
			}
			else
			{
				tile->SetPosition({ lastTilePosition.x, lastTilePosition.y, lastTilePosition.z + lastTileSize.z });
			}
		}

		Entity* e = tile->GetEntity(Entity::GROUND);
		if(e)
		{
			e->SetColor({ GenerateRandomNumber(100) / 100.f, GenerateRandomNumber(100) / 100.f, GenerateRandomNumber(100) / 100.f });

		}
	}
}

void Scene::DeletePastTile()
{
	delete mTiles[0];
	mTiles.erase(mTiles.begin());
}

int Scene::GenerateRandomNumber(int min, int max)
{
	int range = max - min + 1;
	int value = rand() % range + min;
	return value;
}

int Scene::GenerateRandomNumber(int max)
{
	int value = rand() % (max + 1);
	return value;
}

void Scene::SetCamera(CameraC* camera)
{
	if (mCamera)
	{
		delete mCamera;
	}
	mCamera = camera;
}

void Scene::FinishScene()
{
	DeleteAll<Controller>(mInputs);
	DeleteAll<Tile>(mTiles);
	delete mCharacter;
	mCharacter = nullptr;
	//delete mCamera;
	//mCamera = nullptr;
	delete mText;
	mText = nullptr;
	delete mPause;
	mPause = nullptr;
}

Scene::~Scene()
{
	FinishScene();
}


