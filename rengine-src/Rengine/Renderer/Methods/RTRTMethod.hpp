#pragma once
#include "Rengine/Core/core.hpp"
#include "BaseMethod.hpp"
#include "../FrameBuffer.hpp"

namespace Rengin
{

class RTRTMethod : public RenderMethod
{
private:
    Ref<FrameBuffer> m_GBuffer;
    Ref<FrameBuffer> m_MainFrame;
    Ref<Shader> m_GBufferShader;
    Ref<Shader> m_SSRShader;
public:
    RTRTMethod();
    virtual ~RTRTMethod();

    virtual void Render(const std::vector<int>& ids,const std::vector<Ref<ObjManager>>& ObjLists,const EditorCamera& camera,const Lights& lights) override;

    template<typename ...Args>
    void AddResource(const Args&... resource);
};

} // namespace Rengin