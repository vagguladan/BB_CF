#pragma once
#include "BBGameObject.h"

namespace BB
{
	class Enemy : public GameObject
	{
	public:
		Enemy();
		virtual ~Enemy();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:

	};
}