#include "BBEnemy.h"
#include "BBTransform.h"
#include "BBInput.h"
#include "BBTime.h"
#include "BBAnimator.h"

namespace BB
{

	Enemy::Enemy()
		: mState(eState::Idle)
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
/*
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

		tr->SetPosition(pos); */

		switch (mState)
		{
		case BB::Enemy::eState::Idle:
			Idle();
			break;
		case BB::Enemy::eState::Move:
			Move();
			break;
		case BB::Enemy::eState::Attack:
			Attack();
			break;
		case BB::Enemy::eState::Hit:
			Hit();
			break;
		case BB::Enemy::eState::End:
			break;
		default:
			break;
		}

	}

	void Enemy::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Enemy::OnCollisionEnter(Collider* other)
	{
	}

	void Enemy::OnCollisionStay(Collider* other)
	{
	}

	void Enemy::OnCollisionExit(Collider* other)
	{
	}

	void Enemy::Idle()
	{
		Animator* animator = GetComponent<Animator>();
		if (Input::GetKey(eKeyCode::Up))
		{
			animator->PlayAnimation(L"JumpMove", false);
			mState = eState::Move;
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			animator->PlayAnimation(L"FrontMoveE", true);
			mState = eState::Move;
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			animator->PlayAnimation(L"DownMoveE", true);
			mState = eState::Move;
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			animator->PlayAnimation(L"BackMoveE", true);
			mState = eState::Move;
		}

		if (Input::GetKey(eKeyCode::NUM1))
		{
			animator->PlayAnimation(L"AAttackE", false);
			mState = eState::Attack;
		}

		if (Input::GetKey(eKeyCode::NUM2))
		{
			animator->PlayAnimation(L"BAttackE", false);
			mState = eState::Attack;
		}
		if (Input::GetKey(eKeyCode::NUM3))
		{
			animator->PlayAnimation(L"CAttackE", false);
			mState = eState::Attack;
		}
		if (Input::GetKey(eKeyCode::NUM4))
		{
			animator->PlayAnimation(L"DAttackE", false);
			mState = eState::Attack;
		}
	}
	
	

	void Enemy::Move()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Animator* animator = GetComponent<Animator>();

		if (Input::GetKey(eKeyCode::Up))
		{
			pos.y -= 300.0f * Time::DeltaTime();

		}

		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			if (pos.y < 480.0f)
				pos.y += 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 300.0f * Time::DeltaTime();
		}
		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::Up)
			|| Input::GetKeyUp(eKeyCode::Left)
			|| Input::GetKeyUp(eKeyCode::Right)
			|| Input::GetKeyUp(eKeyCode::Down))
		{
			Animator* animator = GetComponent<Animator>();
			animator->PlayAnimation(L"EnemyIdle", true);
			mState = eState::Idle;
		}

		if (Input::GetKey(eKeyCode::NUM1))
		{
			animator->PlayAnimation(L"AAttackE", false);
			mState = eState::Attack;
		}

		if (Input::GetKey(eKeyCode::NUM2))
		{
			animator->PlayAnimation(L"BAttackE", false);
			mState = eState::Attack;
		}
		if (Input::GetKey(eKeyCode::NUM3))
		{
			animator->PlayAnimation(L"CAttackE", false);
			mState = eState::Attack;
		}
		if (Input::GetKey(eKeyCode::NUM4))
		{
			animator->PlayAnimation(L"DAttackE", false);
			mState = eState::Attack;
		}

	}

	void Enemy::Attack()
	{

		Animator* animator = GetComponent<Animator>();
		if (animator->IsActiveAnimationComplete())
		{
			animator->PlayAnimation(L"EnemyIdle", true);
			mState = eState::Idle;
		}
	}

	void Enemy::Hit()
	{
	}

	void Enemy::Jump()
	{
	}

	void Enemy::Sit()
	{
		/*Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Animator* animator = GetComponent<Animator>();

		if (Input::GetKeyUp(eKeyCode::Down))
		{
			animator->PlayAnimation(L"EnemyIdle", true);
			mState = eState::Idle;
		}

		if (Input::GetKey(eKeyCode::NUM1))
		{
			animator->PlayAnimation(L"DAAttackE", false);
			mState = eState::Attack;
		}

		if (Input::GetKey(eKeyCode::NUM2))
		{
			animator->PlayAnimation(L"DBAttackE", false);
			mState = eState::Attack;
		}
		if (Input::GetKey(eKeyCode::NUM3))
		{
			animator->PlayAnimation(L"DCAttackE", false);
			mState = eState::Attack;
		}
		if (Input::GetKey(eKeyCode::NUM4))
		{
			animator->PlayAnimation(L"D	DAttackE", false);
			mState = eState::Attack;
		}*/

	}

}