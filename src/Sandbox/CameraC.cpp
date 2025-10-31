#include "pch.h"
#include "CameraC.h"

CameraC::CameraC()
{
}

void CameraC::Start()
{
	CreatNewCamera();
    SetPosition(gce::Vector3f32(0.0f, 0.0f, 0.0f));
    SetRotation(gce::Vector3f32(0.f, 0.f, 0.f));
}

void CameraC::Update(float deltaTime)
{
    //DebugMove();
}

void CameraC::Update(float deltaTime, bool endGame)
{
    //DebugMove();
}

void CameraC::CreatNewCamera()
{
	mCamera = new Camera(CameraType::PERSPECTIVE);
    mCamera->SetPosition({ 0.0f, 5.f, 0.f });
    mCamera->SetRotation({ 45.f, 0.0f, 0.0f });
    mCamera->SetFOV(gce::PI / 4);
    mCamera->SetFarPlane(500.0f);
    mCamera->SetNearPlane(0.001f);
}

void CameraC::DebugMove()
{
    gce::Vector3f32 dir = {};
    dir.x = GetKey(Keyboard::D) - GetKey(Keyboard::Q);
    dir.y = GetKey(Keyboard::SPACE) - GetKey(Keyboard::LCONTROL);
    dir.z = GetKey(Keyboard::Z) - GetKey(Keyboard::S);
    dir.SelfNormalize();
    dir *= 1.6f;

    gce::Vector3f32 rot = {};
    rot.x = GetKey(Keyboard::UP_ARROW) - GetKey(Keyboard::DOWN_ARROW);
    rot.y = GetKey(Keyboard::RIGHT_ARROW) - GetKey(Keyboard::LEFT_ARROW);
    rot.z = 0;
    rot *= 0.0314f;

    mCamera->Translate(dir);
    mCamera->Rotate(rot);
}


void CameraC::SetCamera(Camera* camera)
{
    mCamera = camera;
}

void CameraC::ReplaceCamera(Camera* camera)
{
    if (mCamera != nullptr)
    {
        delete mCamera;
    }
    mCamera = camera;
}

Camera* CameraC::GetCamera()
{
    return mCamera;
}

void CameraC::SetPosition(const gce::Vector3f32& xyz)
{
    mCamera->SetPosition(xyz);
}

gce::Vector3f32 CameraC::GetPosition()
{
    return mCamera->GetPosition();
}

void CameraC::SetRotation(const gce::Vector3f32& rotation)
{
    mCamera->SetRotation(rotation);
}

gce::Vector3f32 CameraC::GetRotation()
{
    return mCamera->GetRotation();
}

