#pragma once
#include "BBGameObject.h"


namespace BB
{
	using namespace math;
	class Camera
	{
	public:
		static void Initalize();
		static void Update();

		static Vector2 CalculatePosition(Vector2 pos) { return pos - mDistance; }

		static GameObject* GetTarget() { return mTarget; }
		static void SetTarget(GameObject* target) { mTarget = target; }


	private:
		static Vector2 mResolution;
		static Vector2 mLookPosition;
		static Vector2 mDistance;
		static GameObject* mTarget;

	};
}