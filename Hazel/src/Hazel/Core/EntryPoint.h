#pragma once


#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	Hazel::Log::Init();
	HZ_ERROR("test1");
	int a = 10;
	HZ_INFO("var: {0}", a);
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}
#endif