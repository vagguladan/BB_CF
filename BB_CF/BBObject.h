#pragma once
#include "BBScene.h"
#include "BBGameObject.h"
#include "BBSceneManager.h"

namespace BB::object
{
	template <typename T>
	static __forceinline T* Instantiate(eLayerType type)
	{
		T* gameObject = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameObject);

		return gameObject;
	}
}