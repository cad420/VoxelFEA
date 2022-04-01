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
        if(ObjLists[i]->UsePrt())
        {
            std::dynamic_pointer_cast<PRTObjManager>(ObjLists[i])->ComputeTransportSH(m_PrtType,this);
        }
    }
}

bool RendererObject::rayIntersect(const glm::vec3 &v, const glm::vec3 &wi)
{
    for (int i = 0; i < ObjLists.size(); i++)
    {
        if(std::dynamic_pointer_cast<PRTObjManager>(ObjLists[i])->hit(v,wi))   return true;
    }
    return false;
}

bool RendererObject::rayIntersect(const glm::vec3 &v, const glm::vec3 &wi, glm::vec3 &bary)
{
    bool flag = false;
    float t = 1e20;
    for (int i = 0; i < ObjLists.size(); i++)
    {
        if(std::dynamic_pointer_cast<PRTObjManager>(ObjLists[i])->hit(v,wi,bary,t))   flag = true;
    }
    return flag;
}

} // namespace Rengin
