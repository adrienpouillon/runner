#pragma once
#include "pch.h"

class CameraC
{
protected:
	Camera* mCamera;
public:

	CameraC();

	virtual void Start();

	virtual void Update(float deltaTime);
	virtual void Update(float deltaTime, bool endGame);

    void CreatNewCamera();

    void DebugMove();


	void SetCamera(Camera* camera);
	void ReplaceCamera(Camera* camera);
	Camera* GetCamera();

	void SetPosition(const gce::Vector3f32& xyz);

	gce::Vector3f32 GetPosition();

	void SetRotation(const gce::Vector3f32& rotation);

	gce::Vector3f32 GetRotation();
};

