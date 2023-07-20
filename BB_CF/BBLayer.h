#pragma once
#include "BBEntity.h"
#include "BBGameObject.h"

namespace BB
{
	class Layer :public Entity
	{
	public:
		Layer();
		virtual ~Layer();


		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);


		void AddGameObject(GameObject* gameObj)
		{
			mGameObjects.push_back(gameObj);
		}

		std::vector<GameObject*>& GetGameObjects() { return mGameObjects; }

	private:
		std::vector<GameObject*> mGameObjects;
	};
}