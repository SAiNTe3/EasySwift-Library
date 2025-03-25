#include "include/Window.hpp"
#include "include/ImGUI.hpp"
int main()
{
	Window::Initialize(4, 6);
	Window window(800, 450, "DemoWindow", true, true);
	imgui_init(window.getWindow());
	while (window.isOpen())
	{
		window.pollEvents();
		ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // 创建 ImGui 窗口
        ImGui::Begin("Hello, ImGui!");
        ImGui::Text("This is a simple ImGui window.");
        if (ImGui::Button("Close"))
            window.closeWindow();
        ImGui::End();

        // 渲染
        ImGui::Render();
		window.clear();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		window.display();
	}
	ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
	Window::Terminate();
}