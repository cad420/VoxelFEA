#pragma once
#include "Rengine/Core/core.hpp"
#include <glm/glm.hpp>

namespace Rengin
{
struct Material
{
    glm::vec3 Ks,Kd,Ka,Le;
    double Ns,Ni;
};
} // namespace Rengin
