#include "pch.h"
#include "MoveController.h"
#include "GameManager.h"
#include "Scene.h"
#include "Pause.h"

int main()
{
	GameManager* gameManager = GameManager::GetInstance();

	gameManager->Init();
	Scene* scene = gameManager->CreateScene<Scene>();
    scene->GetPause()->SetPause(true);

    gameManager->Run();

    return 0;
}