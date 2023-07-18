#pragma once
#include "BBEntity.h"

namespace BB
{
	class Resource : public Entity
	{
	public:
		Resource();
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;

		std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

		
	private:
		std::wstring mPath;
	};
}
