#include "BBEnemy.h"
#include "BBTransform.h"
#include "BBInput.h"
#include "BBTime.h"
#include "BBAnimator.h"

namespace BB
{

	Enemy::Enemy()
	{
	}

	Enemy::~Enemy()
	{
	}

	void Enemy::Initialize()
	{
	}

	void Enemy::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Animator* anim = GetComponent<Animator>();

		if (Input::GetKey(eKeyCode::I))
		{
			pos.y -= 300.0f * Time::DeltaTime();
		}


		if (Input::GetKey(eKeyCode::J))
		{
			pos.x -= 300.0f * Time::DeltaTime();
		}
		if (Input::GetKeyDown(eKeyCode::J))
			anim->PlayAnimation(L"BackMoveE", true);
		if (Input::GetKeyUp(eKeyCode::J))
			anim->PlayAnimation(L"Enemy", true);
		

		if (Input::GetKey(eKeyCode::K))
		{
			if (pos.y < 480.0f)
			pos.y += 300.0f * Time::DeltaTime();
		}
		if (Input::GetKeyDown(eKeyCode::K))
			anim->PlayAnimation(L"DownMoveE", true);
		if (Input::GetKeyUp(eKeyCode::K))
			anim->PlayAnimation(L"Enemy", true);

		if (Input::GetKey(eKeyCode::L))
		{
			
			pos.x += 300.0f * Time::DeltaTime();
		}
		if (Input::GetKeyDown(eKeyCode::L))
			anim->PlayAnimation(L"FrontMoveE", true);
		if (Input::GetKeyUp(eKeyCode::L))
			anim->PlayAnimation(L"Enemy", true);

		tr->SetPosition(pos);
	}

	void Enemy::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

}