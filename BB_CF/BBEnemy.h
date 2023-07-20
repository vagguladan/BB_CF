#pragma once
#include "BBGameObject.h"

namespace BB
{
	class Enemy : public GameObject
	{
	public:
		enum class eState
		{
			Idle,
			Move,
			Attack,
			Hit,
			Jump,
			Sit,
			End,
		};


		Enemy();
		virtual ~Enemy();

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
		void Sit();


	private:
		eState mState;
	};
}