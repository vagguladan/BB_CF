#include "BBBattleScene.h"
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
#include "BBEnemy.h"

namespace BB
{



BattleScene::BattleScene()
{
}

BattleScene::~BattleScene()
{
}

void BattleScene::Initialize()
{

	Texture* image = Resources::Load<Texture>(L"BattleBackGroundImgae"
		, L"..\\Resources\\Image\\BackGround\\Lessons_CS_Screenshot_01.png");

	BackGround* bg = object::Instantiate<BackGround>(eLayerType::Background);
	SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
	bgsr->SetImage(image);
	bgsr->SetScale(Vector2(2.0f, 1.8f));
	bgsr->SetAffectCamera(false);

	bg->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));



	//image = Resources::Load<Texture>(L"Player"
	//	, L"..\\Resources\\Image\\Player\\es000_00.png");

	Player* player = object::Instantiate<Player>(eLayerType::Player);
	Transform* tr = player->GetComponent<Transform>();
	tr->SetPosition(Vector2(1100.0f, 500.0f));

	Enemy* Em = object::Instantiate<Enemy>(eLayerType::Enemy);
	Transform* tr2 = Em->GetComponent<Transform>();
	tr2->SetPosition(Vector2(400.0f, 500.0f));

	//SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
	//sr->SetImage(image);
	//sr->SetScale(Vector2(1.2f, 1.2f));

	//image = Resources::Load<Texture>(L"Smile"
	//	, L"..\\Resources\\Image\\Player\\Standing");
	
	//ES �����
	Animator* at = player->AddComponent<Animator>();
	at->CreateAnimationFolder(L"Test", L"..\\Resources\\Image\\Player\\Es\\Standing");
	at->CreateAnimationFolder(L"FrontMove", L"..\\Resources\\Image\\Player\\Es\\FrontMove");
	at->CreateAnimationFolder(L"BackMove", L"..\\Resources\\Image\\Player\\Es\\BackMove");
	at->CreateAnimationFolder(L"DownMove", L"..\\Resources\\Image\\Player\\Es\\DownMove",Vector2(0.0f, 50.0f));
	at->PlayAnimation(L"Test", true);
	at->SetAffectedCamera(true);




	//MAI �����.
	Animator* at2 = Em->AddComponent<Animator>();
	at2->CreateAnimationFolder(L"Enemy", L"..\\Resources\\Image\\Player\\Bullet\\Standing");
	at2->CreateAnimationFolder(L"BackMoveE", L"..\\Resources\\Image\\Player\\Bullet\\BackMove");
	at2->CreateAnimationFolder(L"FrontMoveE", L"..\\Resources\\Image\\Player\\Bullet\\FrontMove");
	at2->CreateAnimationFolder(L"DownMoveE", L"..\\Resources\\Image\\Player\\Bullet\\DownMove", Vector2(0.0f, 50.0f));
	at2->PlayAnimation(L"Enemy", true);
	at2->SetAffectedCamera(true);


	//Animator* at = player->AddComponent<Animator>();
	//at->CreateAnimationFolder(L"PlayerMove", L"..\\Resources\\Image\\Player\\Move");
	//at->CreateAnimationFolder(L"Test", L"..\\Resources\\Image\\Player\\Move");
	//at->PlayAnimation(L"Test", true);
	//at->SetAffectedCamera(true);
}

void BattleScene::Update()
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

void BattleScene::Render(HDC hdc)
{

	Scene::Render(hdc);
}

}