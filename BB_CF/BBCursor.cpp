#include "BBCursor.h"
#include "BBTransform.h"
#include "BBInput.h"
#include "BBTime.h"
#include "BBAnimator.h"

namespace BB
{


	Cursor::Cursor()
	{
	}

	Cursor::~Cursor()
	{
	}

	void Cursor::Initialize()
	{
	}

	void Cursor::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Animator* anim = GetComponent<Animator>();

		if (Input::GetKey(eKeyCode::W))
		{
			pos.y -= 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A))
		{


			pos.x -= 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			pos.y += 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 300.0f * Time::DeltaTime();
		}


	}

	void Cursor::Render(HDC hdc)
	{
		GameObject::Render(hdc);

	}
}