#include "BBScene.h"
#include "BBSpriteRenderer.h"
#include "BBPlayer.h"
#include "BBEnemy.h"

namespace BB
{
	Scene::Scene()
	{
		mLayers.resize((int)eLayerType::End);
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{

	}
	void Scene::Update()
	{

		for (Layer& layer : mLayers)
		{
			layer.Update();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (Layer& layer : mLayers)
		{
			layer.Render(hdc);
		}
	}
}