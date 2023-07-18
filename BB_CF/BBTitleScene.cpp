#include "BBTitleScene.h"
#include "BBPlayer.h"
#include "BBSpriteRenderer.h"
#include "BBObject.h"
#include "BBTexture.h"
#include "BBResources.h"
#include "BBBackGround.h"
#include "BBInput.h"
#include "BBCamera.h"
#include "BBTransform.h"

namespace BB
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		Texture* image = Resources::Load<Texture>(L"TitleBackGroundImgae"
			, L"..\\Resources\\Image\\Tiltle\\ss01-sp.bmp");

	
		BackGround* bg = object::Instantiate<BackGround>(eLayerType::Background);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(image);
		bgsr->SetScale(Vector2(2.0f, 1.8f));

		bgsr->SetAffectCamera(false);

		bg->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));

		
	}
	void TitleScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(eKeyCode::B))
		{
			SceneManager::LoadScene(L"BattleScene");
		}
		if (Input::GetKeyDown(eKeyCode::T))
		{
			SceneManager::LoadScene(L"TitileScene");
		}
		if (Input::GetKeyDown(eKeyCode::C))
		{
			SceneManager::LoadScene(L"CharaterSelectScene");
		}

	}
	void TitleScene::Render(HDC hdc)
	{

		Scene::Render(hdc); 
	}
}