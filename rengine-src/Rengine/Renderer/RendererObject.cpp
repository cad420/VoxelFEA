#include "repch.hpp"
#include "RendererObject.hpp"
#include "Rengine/Renderer/RenderCommand.hpp"

namespace Rengin
{

RendererObject::RendererObject()
{
}

void RendererObject::AddObj(const Ref<ObjManager> obj)
{
    ObjLists.push_back(obj);
}

void RendererObject::AddMethod(const std::string &name, Ref<RenderMethod> method)
{
    if(m_Methods.find(name) != m_Methods.end())   return;
    m_Methods[name] = method;
}

void RendererObject::DrawObject(const std::string& methodName,const std::vector<int>& ids,const EditorCamera& camera)
{
    m_Methods[methodName]->Render(ids,ObjLists,camera,lights);
}

void RendererObject::ComputePrt()
{
    for (int i = 0; i < ObjLists.size(); i++)
    {
        if(ObjLists[i]->isPrt())
        {
            dynamic_cast<PRTObjManager>(ObjLists[i])->ComputeTransportSH();
        }
    }
}

} // namespace Rengin
