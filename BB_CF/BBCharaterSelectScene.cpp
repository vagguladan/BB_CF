#include "BBCharaterSelectScene.h"
#include "BBPlayer.h"
#include "BBSpriteRenderer.h"
#include "BBObject.h"
#include "BBInput.h"
#include "BBPlayer.h"
#include "BBSpriteRenderer.h"
#include "BBTexture.h"
#include "BBTransform.h"
#include "BBResources.h"
#include "BBBackGround.h"
#include "BBCamera.h"
#include "BBAnimator.h"
#include "BBCursor.h"

namespace BB
{

CharaterSelectScene::CharaterSelectScene()
{
}

CharaterSelectScene::~CharaterSelectScene()
{

}

void CharaterSelectScene::Initialize()
{
	Texture* image = Resources::Load<Texture>(L"CharterSelectImgae"
		, L"..\\Resources\\Image\\CharcterScene\\BBCF_Roster.png");

	BackGround* bg = object::Instantiate<BackGround>(eLayerType::Background);
	SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
	bgsr->SetImage(image);
	bgsr->SetScale(Vector2(2.0f, 1.8f));
	bgsr->SetAffectCamera(false);

	bg->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));

	image = Resources::Load<Texture>(L"cursor"
		, L"..\\Resources\\Image\\Coursor\\cursor.png");

	

	Cursor* cr = object::Instantiate<Cursor>(eLayerType::Cursor);
	Transform* tr = cr->GetComponent<Transform>();
	tr->SetPosition(Vector2(400.0f, 400.0f));

	Animator* at = cr->AddComponent<Animator>();
	at->CreateAnimationFolder(L"cursor"
		, L"..\\Resources\\Image\\Coursor");

	SpriteRenderer* sr = cr->AddComponent<SpriteRenderer>();
	sr->SetImage(image);
	sr->SetScale(Vector2(1.2f, 1.2f));

}

void CharaterSelectScene::Update()
{
	Scene::Update();

	if (Input::GetKeyDown(eKeyCode::B))
	{
		SceneManager::LoadScene(L"BattleScene");
	}
	if (Input::GetKeyDown(eKeyCode::T))
	{
		SceneManager::LoadScene(L"TitleScene");
	}
	if (Input::GetKeyDown(eKeyCode::C))
	{
		SceneManager::LoadScene(L"CharaterSelectScene");
	}
}

void CharaterSelectScene::Render(HDC hdc)
{
	Scene::Render(hdc);

}

}