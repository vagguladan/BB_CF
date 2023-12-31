#include "BBSpriteRenderer.h"
#include "BBTransform.h"
#include "BBGameObject.h"
#include "BBCamera.h"

namespace BB
{


	SpriteRenderer::SpriteRenderer()
		:Component(eComponentType::SpriteRenderer)
		, mScale(Vector2::One)
		, mbAffectCamera(true)
		, mTexture(nullptr)
		, mAlpha(1.0f)
	{
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Initialize()
	{
	}

	void SpriteRenderer::Update()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			return;

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();



		if (mbAffectCamera)
			pos = Camera::CalculatePosition(pos);

		if (mTexture->GetType() == eTextureType::Bmp)
		{
			TransparentBlt(hdc, (int)pos.x - (mTexture->GetWidth() * mScale.x / 2.0f)
				, (int)pos.y - (mTexture->GetHeight() * mScale.y / 2.0f)
				, mTexture->GetWidth() * mScale.x
				, mTexture->GetHeight() * mScale.y
				, mTexture->GetHdc()
				, 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (mTexture->GetType() == eTextureType::AlphaBmp)
		{
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			// 0.0f ~ 1.0f -> 0 ~ 255
			int alpha = (int)(mAlpha * 255.0f);
			if (alpha <= 0)
				alpha = 0;
			func.SourceConstantAlpha = alpha; // 0 ~ 255

			AlphaBlend(hdc, (int)pos.x - (mTexture->GetWidth() * mScale.x / 2.0f)
				, (int)pos.y - (mTexture->GetHeight() * mScale.y / 2.0f)
				, mTexture->GetWidth() * mScale.x
				, mTexture->GetHeight() * mScale.y
				, mTexture->GetHdc()
				, 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
				, func);
		}
		else if (mTexture->GetType() == eTextureType::Png)
		{
			//// 내가 원하는 픽셀을 투명화 시킬떄
			//Gdiplus::ImageAttributes imageAtt = {};
			//// 투명화 시킬 픽셀 색 범위
			//imageAtt.SetColorKey(Gdiplus::Color(100,100,100)
			//	, Gdiplus::Color(255,255,255));
			//Gdiplus::Graphics graphics(hdc);
			//graphics.DrawImage(mTexture->GetImage()
			//	, Gdiplus::Rect
			//	(
			//		(int)(pos.x - (mTexture->GetWidth() * mScale.x / 2.0f))
			//		, (int)(pos.y - (mTexture->GetHeight() * mScale.y / 2.0f))
			//		, (int)(mTexture->GetWidth() * mScale.x)
			//		, (int)(mTexture->GetHeight() * mScale.y)
			//	)
			//	, 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
			//	, Gdiplus::UnitPixel
			//	, &imageAtt);
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage()
				, (int)(pos.x - (mTexture->GetWidth() * mScale.x / 2.0f))
				, (int)(pos.y - (mTexture->GetHeight() * mScale.y / 2.0f))
				, (int)(mTexture->GetWidth() * mScale.x)
				, (int)(mTexture->GetHeight() * mScale.y));
		}
	}

}