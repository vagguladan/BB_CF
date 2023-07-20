#include "BBPlayer.h"
#include "BBTransform.h"
#include "BBInput.h"
#include "BBTime.h"
#include "BBAnimator.h"

namespace BB
{

	Player::Player()
		: mState(eState::Idle)
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

	/*	Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Animator* anim = GetComponent<Animator>();*/

	/*	if (Input::GetKey(eKeyCode::W))
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

			anim->PlayAnimation(L"BackMove", true);

		if (Input::GetKeyUp(eKeyCode::D))
			anim->PlayAnimation(L"Test", true);


		if (Input::GetKeyDown(eKeyCode::H))
			anim->PlayAnimation(L"AAttack", false);


		if (Input::GetKeyDown(eKeyCode::J))
			anim->PlayAnimation(L"BAttackS", false);

		if (Input::GetKeyDown(eKeyCode::Y))
			anim->PlayAnimation(L"CAttack", false);


		if (Input::GetKeyDown(eKeyCode::U))
		{
			anim->PlayAnimation(L"DAttack", false);
		}
		if (Input::GetKeyDown(eKeyCode::L))
		{
			anim->PlayAnimation(L"BAttack", false);
		}




		tr->SetPosition(pos);*/


		switch (mState)
		{
		case BB::Player::eState::Idle:
			Idle();
			break;
		case BB::Player::eState::Move:
			Move();
			break;
		case BB::Player::eState::Attack:
			Attack();
			break;
		case BB::Player::eState::Hit:
			Hit();
			break;
		case BB::Player::eState::End:
			break;
		default:
			break;
		}

	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Player::OnCollisionEnter(Collider* other)
	{
	}

	void Player::OnCollisionStay(Collider* other)
	{
	}

	void Player::OnCollisionExit(Collider* other)
	{
	}

	void Player::Idle()
	{

		Animator* animator = GetComponent<Animator>();
		if (Input::GetKey(eKeyCode::W))
		{
			animator->PlayAnimation(L"JumpMove", false);
			mState = eState::Move;
		}
		if (Input::GetKey(eKeyCode::A))
		{
			animator->PlayAnimation(L"FrontMove", true);
			mState = eState::Move;
		}
		if (Input::GetKey(eKeyCode::S))
		{
			animator->PlayAnimation(L"DownMove", true);
			mState = eState::Move;
		}
		if (Input::GetKey(eKeyCode::D))
		{
			animator->PlayAnimation(L"BackMove", true);
			mState = eState::Move;
		}

		if (Input::GetKey(eKeyCode::H))
		{
			animator->PlayAnimation(L"AAttack", false);
			mState = eState::Attack;
		}

		if (Input::GetKey(eKeyCode::J))
		{
			animator->PlayAnimation(L"BAttackS", false);
			mState = eState::Attack;
		}
		if (Input::GetKey(eKeyCode::Y))
		{
			animator->PlayAnimation(L"CAttack", false);
			mState = eState::Attack;
		}
		if (Input::GetKey(eKeyCode::U))
		{
			animator->PlayAnimation(L"DAttack", false);
			mState = eState::Attack;
		}
	}

	void Player::Move()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
	
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
			if (pos.y < 480.0f)
			pos.y += 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 300.0f * Time::DeltaTime();
		}
		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::W)
			|| Input::GetKeyUp(eKeyCode::A)
			|| Input::GetKeyUp(eKeyCode::S)
			|| Input::GetKeyUp(eKeyCode::D))
		{
			Animator* animator = GetComponent<Animator>();
			animator->PlayAnimation(L"PlayerIdle", true);
			mState = eState::Idle;
		}
	}

	void Player::Attack()
	{
		Animator* animator = GetComponent<Animator>();
		if (animator->IsActiveAnimationComplete())
		{
			animator->PlayAnimation(L"PlayerIdle", true);
			mState = eState::Idle;
		}
	}

	void Player::Hit()
	{
	}

	void Player::Jump()
	{
	}

}