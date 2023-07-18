#pragma once
#include <vector>
#include <list>
#include <map>
#include <set>
#include <functional>
#include <string>
#include <filesystem>

#include "framework.h"
#include "BBMath.h"

#pragma comment(lib, "Msimg32.lib")

namespace BB::enums
{
	enum class eLayerType
	{
		Background,
		Player,
		Enemy,
		Cursor,
		Monster,
		Effect,
		UI,
		End,
	};

	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Animation,
		Animator,
		End,
	};

}