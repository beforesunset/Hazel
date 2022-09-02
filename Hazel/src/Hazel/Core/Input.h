#pragma once
#include "Hazel/Core/MouseCodes.h"
#include "Hazel/Core/KeyCodes.h"

// to be solved
//#include <glm/glm.cpp>

namespace Hazel
{
	class HAZEL_API Input 
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		
		// to be solved
		//static glm::vec2 GetMousePosition();

		static std::pair<float, float> GetMousePosition();

		static float GetMouseX();
		static float GetMouseY();

	// to be solved
	private:
		static Input* s_Instance;
	};


}
