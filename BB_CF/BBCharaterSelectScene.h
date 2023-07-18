#pragma once
#include "BBScene.h"


namespace BB
{
	class CharaterSelectScene :public Scene
	{
	public:
		CharaterSelectScene();
		virtual ~CharaterSelectScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:

	};
}