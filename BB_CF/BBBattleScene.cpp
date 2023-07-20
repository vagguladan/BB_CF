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

		Texture* BGimage = Resources::Load<Texture>(L"BattleBackGroundImgae"
			, L"..\\Resources\\Image\\BackGround\\Lessons_CS_Screenshot_01.png");

		BackGround* bg = object::Instantiate<BackGround>(eLayerType::Background);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(BGimage);
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

		//Hazama 무브셋
		/*Animator* at = player->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Test", L"..\\Resources\\Image\\Player\\Hazama\\Standing", Vector2(0.0f, -52.0f));
		at->CreateAnimationFolder(L"FrontMove", L"..\\Resources\\Image\\Player\\Hazama\\FrontMove",Vector2(-10.0f, 0.0f));
		at->CreateAnimationFolder(L"BackMove", L"..\\Resources\\Image\\Player\\Hazama\\BackMove", Vector2(10.0f, 0.0f));
		at->CreateAnimationFolder(L"DownMove", L"..\\Resources\\Image\\Player\\Hazama\\DownMove", Vector2(-50.0f, 30.0f));

		at->CreateAnimationFolder(L"AAttack", L"..\\Resources\\Image\\Player\\Hazama\\AAttack",Vector2(-30.0f, 0.0f));
		at->CreateAnimationFolder(L"BAttack", L"..\\Resources\\Image\\Player\\Hazama\\BAttack", Vector2(-20.0f, 100.0f));
		at->CreateAnimationFolder(L"CAttack", L"..\\Resources\\Image\\Player\\Hazama\\CAttack");
		at->CreateAnimationFolder(L"DAttack", L"..\\Resources\\Image\\Player\\Hazama\\DAttack",Vector2(-140.0f, -10.0f));

		at->PlayAnimation(L"Test", true);
		at->SetAffectedCamera(true);*/


		//ES 무브셋.

		Animator* at = player->AddComponent<Animator>();
		at->CreateAnimationFolder(L"PlayerIdle", L"..\\Resources\\Image\\Player\\Es\\Standing");
		at->CreateAnimationFolder(L"JumpMove", L"..\\Resources\\Image\\Player\\Es\\JumpMove");
		at->CreateAnimationFolder(L"FrontMove", L"..\\Resources\\Image\\Player\\Es\\FrontMove");
		at->CreateAnimationFolder(L"BackMove", L"..\\Resources\\Image\\Player\\Es\\BackMove");
		at->CreateAnimationFolder(L"DownMove", L"..\\Resources\\Image\\Player\\Es\\DownMove", Vector2(-50.0f, 30.0f));

		at->CreateAnimationFolder(L"AAttack", L"..\\Resources\\Image\\Player\\Es\\AAttack", Vector2(0.0f, 0.0f), 0.05f);
		at->CreateAnimationFolder(L"BAttack", L"..\\Resources\\Image\\Player\\Es\\BAttack", Vector2(0.0f, 0.0f), 0.05f);
		at->CreateAnimationFolder(L"CAttack", L"..\\Resources\\Image\\Player\\Es\\CAttack", Vector2(0.0f, 0.0f), 0.05f);
		at->CreateAnimationFolder(L"DAttack", L"..\\Resources\\Image\\Player\\Es\\DAttack", Vector2(0.0f, 0.0f), 0.05f);

		Texture* Battack = Resources::Load<Texture>(L"BAttackSheet"
			, L"..\\Resources\\Image\\Player\\Es\\Battacksheet\\Battack.bmp");



		at->CreateAnimation(L"BAttackS", Battack, Vector2(0.0f, 0.0f), Vector2(600.0f, 800.0f), 11, Vector2(0.0f, 0.0f), 0.05f);


		at->PlayAnimation(L"PlayerIdle", true);
		at->SetAffectedCamera(true);




		//Bullet 무브셋.%
		Animator* at2 = Em->AddComponent<Animator>();
		at2->CreateAnimationFolder(L"EnemyIdle", L"..\\Resources\\Image\\Player\\Bullet\\Standing");
		at2->CreateAnimationFolder(L"BackMoveE", L"..\\Resources\\Image\\Player\\Bullet\\BackMove");
		at2->CreateAnimationFolder(L"FrontMoveE", L"..\\Resources\\Image\\Player\\Bullet\\FrontMove");
		at2->CreateAnimationFolder(L"DownMoveE", L"..\\Resources\\Image\\Player\\Bullet\\DownMove", Vector2(0.0f, 50.0f));
		at2->PlayAnimation(L"EnemyIdle", true);
		at2->SetAffectedCamera(true);

		at2->CreateAnimationFolder(L"AAttackE", L"..\\Resources\\Image\\Player\\Bullet\\AAttack", Vector2(0.0f, 0.0f), 0.02f);
		at2->CreateAnimationFolder(L"BAttackE", L"..\\Resources\\Image\\Player\\Bullet\\BAttack",Vector2(0.0f, 10.0f), 0.02f);
		at2->CreateAnimationFolder(L"CAttackE", L"..\\Resources\\Image\\Player\\Bullet\\CAttack",Vector2(0.0f, 10.0f), 0.02f);
		at2->CreateAnimationFolder(L"DAttackE", L"..\\Resources\\Image\\Player\\Bullet\\DAttack");

		at2->CreateAnimationFolder(L"DAAttackE", L"..\\Resources\\Image\\Player\\Bullet\\DAAttack",Vector2(0.0f, 10.0f), 0.02f);


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