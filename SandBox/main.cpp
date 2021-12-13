#include <rengine.hpp>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi
#include <imgui.h>

glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
{
	glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	return Projection * View * Model;
}
class ExampleLayer : public Rengin::Layer
{
public:
    ExampleLayer():Layer("Example"){
        auto cam = camera(0.1f,{0.3f,0.2f});
    }
    void OnUpdate(){
        // RE_INFO("Updating");
        if(Rengin::Input::isKeyPressed(RE_KEY_TAB))
        {
            RE_TRACE("Tab is Pressed!");
        }
    }
    
    virtual void OnImGuiRender() override
    {
        ImGui::Begin("Test");
        ImGui::Text("Hello World");
        ImGui::End();
    }

    void OnEvent(Rengin::Event& ev){
        
        RE_TRACE("Event {0}",ev);
    }
};

class SandBox :public Rengin::Application
{
public:
    SandBox(){

        PushLayer(new ExampleLayer());
    }

    ~SandBox(){}
};


Rengin::Application* Rengin::CreateApplication()
{
    return new SandBox();
}