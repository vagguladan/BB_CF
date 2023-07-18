#include "BBPlayer.h"
#include "BBTransform.h"
#include "BBInput.h"
#include "BBTime.h"
#include "BBAnimator.h"

namespace BB
{

	Player::Player()
	{
	}

	Player::~Player()
	{
	}

	void Player::Initialize()
	{
	}

	void Player::Update()
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
		if (Input::GetKeyDown(eKeyCode::A))
		{
			anim->PlayAnimation(L"FrontMove", true);
		}
		if (Input::GetKeyUp(eKeyCode::A))
		{
			anim->PlayAnimation(L"Test", true);
		}


		if (Input::GetKey(eKeyCode::S))
		{
			
			if (pos.y < 480.0f)
			pos.y += 300.0f * Time::DeltaTime();
		}
		if (Input::GetKeyDown(eKeyCode::S))
		{
			anim->PlayAnimation(L"DownMove", true);
		}
		if (Input::GetKeyUp(eKeyCode::S))
		{
			anim->PlayAnimation(L"Test", true);
		}



		if (Input::GetKey(eKeyCode::D))
		{
			
			pos.x += 300.0f * Time::DeltaTime();
		}

		if (Input::GetKeyDown(eKeyCode::D))
		{
			anim->PlayAnimation(L"BackMove", true);
		
		}
		if (Input::GetKeyUp(eKeyCode::D))
		{
			anim->PlayAnimation(L"Test", true);
		}

	


		tr->SetPosition(pos);
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

}