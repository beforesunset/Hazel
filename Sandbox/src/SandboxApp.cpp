#include "Hazel.h"

class ExamplerLayer : public Hazel::Layer
{
public:
	ExamplerLayer()
		: Layer("Example") {}
	
	void OnUpdate() override
	{
		//HZ_INFO("Examplerlayer: Update");
		if (Hazel::Input::IsKeyPressed(Hazel::Key::Tab))
			HZ_TRACE("TAB key is pressed (update)");
	}
	
	void OnEvent(Hazel::Event& event) override
	{
		if (event.GetEventType() == Hazel::EventType::KeyPressed)
		{
			Hazel::KeyPressedEvent& e = (Hazel::KeyPressedEvent&) event;
			if (e.GetKeyCode() == Hazel::Key::Tab)
				HZ_TRACE("Tab key is pressed (event)");
			HZ_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};


class Sandbox : public Hazel::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExamplerLayer());
		PushOverlay(new Hazel::ImGuiLayer());
	}
	~Sandbox() {}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}



