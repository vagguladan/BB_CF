#pragma once
#include "BBScene.h"


namespace BB
{
	class BattleScene :public Scene
	{
	public:
		BattleScene();
		virtual ~BattleScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
	};
}