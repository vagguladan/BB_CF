#include "BBTransform.h"
#include "BBInput.h"
#include "BBTime.h"


namespace BB
{


	Transform::Transform()
		: Component(eComponentType::Transform)
		, mRotation(0.0f)
	{
	}

	Transform::~Transform()
	{
	}

	void Transform::Initialize()
	{
	}

	void Transform::Update()
	{
	}

	void Transform::Render(HDC hdc)
	{
	}
}