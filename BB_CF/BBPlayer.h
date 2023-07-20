#pragma once
#include "BBGameObject.h"

namespace BB
{
	class Player : public GameObject
	{
	public:

		enum class eState
		{
			Idle,
			Move,
			Attack,
			Hit,
			Jump,
			End,
		};


		Player();
		virtual ~Player();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;


		void Idle();
		void Move();
		void Attack();
		void Hit();
		void Jump();

	private:
		eState mState;
	};
	

}