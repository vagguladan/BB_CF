#include "BBApplication.h"
#include "BBTime.h"
#include "BBInput.h"
#include "BBTitleScene.h"
#include "BBSceneManager.h"
#include "BBCamera.h"

namespace BB
{

	Application::Application()
		: mHwnd(NULL)
		, mHdc(NULL)
		, mWidth(0)
		, mHeight(0)
		, mBackBuffer(NULL)
		, mBackHdc(NULL)
	{

	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		mWidth = 1280;
		mHeight = 720;


		RECT rect = { 0, 0, mWidth, mHeight };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(mHwnd
			, nullptr, 0, 0
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0);
		ShowWindow(mHwnd, true);

		// ������ �ػ� ������ ��Ʈ�� ����
		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);

		// ���� ������ ��Ʈ���� ����Ű�� DC ����
		mBackHdc = CreateCompatibleDC(mHdc);

		// ���� ������ ��Ʈ�ʰ� DC�� ���� ����
		HBITMAP defaultBitmap
			= (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(defaultBitmap);

		Time::Initailize();
		Input::Initailize();
		Camera::Initalize();

		SceneManager::Initialize();
	}

	void Application::Run()
	{
		Update();
		Render();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();
		Camera::Update();

		SceneManager::Update();
	}

	void Application::Render()
	{
		HBRUSH brush = CreateSolidBrush(RGB(125, 125, 125));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHdc, brush);
		Rectangle(mBackHdc, -1, -1, mWidth + 1, mHeight + 1);
		SelectObject(mBackHdc, oldBrush);
		DeleteObject(brush);

		Time::Render(mBackHdc);

		SceneManager::Render(mBackHdc);
		//Rectangle(mHdc, 100, 100, 200, 200);
		//Ellipse(mBackHdc, 100 + mPlayerPos.x, 100 + mPlayerPos.y
		//	, 200 + mPlayerPos.x, 200 + mPlayerPos.y);
		BitBlt(mHdc, 0, 0, mWidth, mHeight
			, mBackHdc, 0, 0, SRCCOPY);
	}
}