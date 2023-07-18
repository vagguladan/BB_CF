#pragma once
#include "BBGameObject.h"

namespace BB
{
	class Cursor : public GameObject
	{
	public:
		Cursor();
		virtual ~Cursor();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:

	};
}