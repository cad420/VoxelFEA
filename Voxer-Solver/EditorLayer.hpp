#pragma once
#include <rengine.hpp>
#include <imgui.h>
#include "Panels/SceneHierarchyPanel.hpp"
#include "Rengine/Renderer/EditorCamera.hpp"

namespace Rengin
{
class EditorLayer : public Layer
{
private:
    ShaderLibrary m_shader_lib;
    Ref<Shader> m_shader;
    Ref<VertexBuffer> m_verbuf;
    Ref<IndexBuffer> m_indbuf;
    Ref<VertexArray> m_verarr;
    Ref<FrameBuffer> m_framebuffer;
    OrthoGraphicsCameraController m_camera_controller;

    Ref<Scene> m_ActiveScene;
    EditorCamera m_EditorCamera;

    Entity m_SquareEntity;
    Entity m_Camera;

    glm::vec2 m_ViewPortSize;
    bool m_ViewportFocused = false;
    bool m_ViewportHovered = false;

    int  m_GizmoType = -1;

    //Panels
    SceneHierarchyPanel m_panel;
private:
    bool OnKeyPressed(KeyPressEvent& e);
    void NewScene();
    void OpenScene();
    void SaveSceneAs();
public:
    EditorLayer();
    ~EditorLayer();
    void OnUpdate(TimeStep timestep) override;
    virtual void OnImGuiRender() override;
    virtual void OnAttach()override;
    virtual void OnDetach()override;
    void OnEvent(Event& ev) override;
};


} // namespace Rengin

