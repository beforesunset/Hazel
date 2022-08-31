#pragma once

#define HAZEL_API __declspec(dllexport)

namespace Hazel {

	HAZEL_API void Print();

	class HAZEL_API Test
	{
	public:
		Test();
	};

}
