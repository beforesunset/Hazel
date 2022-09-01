#include "Hazel.h"

class ExamplerLayer : public Hazel::Layer
{
public:
	ExamplerLayer()
		: Layer("Example") {}
	
	void OnUpdate() override
	{
		HZ_INFO("Examplerlayer: Update");
	}

	void OnEvent(Hazel::Event& event) override
	{
		HZ_TRACE("{0}", event);
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



