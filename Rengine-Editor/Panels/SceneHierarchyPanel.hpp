#pragma once

#include "Rengine/Core/core.hpp"
#include "Rengine/Scene/Scene.hpp"
#include "Rengine/Scene/Entity.hpp"

namespace Rengin
{
class SceneHierarchyPanel
{
private:
    Ref<Scene> m_Context;
    Entity m_SelectionContext;
public:
    SceneHierarchyPanel(const Ref<Scene>& scene);
    SceneHierarchyPanel() = default;

    void SetContext(const Ref<Scene>& scene);

    void OnImGuiRender();

private:
    void DrawEntityNode(Entity entity);
};


} // namespace Rengin
