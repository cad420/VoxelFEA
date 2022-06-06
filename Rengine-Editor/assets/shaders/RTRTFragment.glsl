#version 450
#define MAXBOUNCE 5

in vec3 v_position;
in vec3 v_normal;
in vec2 v_texCoords;

layout(location = 0) out vec4 o_color;
layout(location = 1) out int o_Entity;

uniform int u_Entity;
uniform int u_Bounce;
uniform sampler2D u_texture[32];
uniform int u_TexId;
uniform int u_trianglenums;

//Camera
uniform vec3 u_CameraPos;

// Light
uniform int u_LightNums;
uniform vec3 u_LightPos;
uniform vec3 u_LightIntensity;

//Material
uniform vec3 u_Ks;
uniform vec3 u_Kd;
uniform vec3 u_Ka;
uniform float u_Ns;
uniform float u_Ni;

// Triangle
layout(std430,binding = 1) buffer TriangleV
{
    float m_Vertex[];
};

// Normal
layout(std430,binding = 2) buffer TriangleN
{
    float m_Normal[];
};

// Texture
layout(std430,binding = 3) buffer TriangleT
{
    int m_Texture[];
};

// Texture
layout(std430,binding = 3) buffer Light
{
    int m_LightsTri[];
};


float Rand1(inout float p)
{
    p = fract(p * .1031);
    p *= p + 33.33;
    p *= p + p;
    return fract(p);
}

vec2 Rand2(inout float p)
{
    return vec2(Rand1(p), Rand1(p));
}

vec3 Rand3(inout float p)
{
    return vec3(Rand1(p), Rand2(p));
}

vec4 Rand4(inout float p)
{
    return vec4(Rand2(p), Rand2(p));
}

float InitRand(vec2 uv)
{
	vec3 p3  = fract(vec3(uv.xyx) * .1031);
    p3 += dot(p3, p3.yzx + 33.33);
    return fract((p3.x + p3.y) * p3.z);
}

vec3 BlinnPhong()
{
    vec3 color = texture2D(u_texture[u_TexId],v_texCoords).rgb;
    color = pow(color, vec3(2.2));

    vec3 ambient = 0.05 * color;

    vec3 lightDir = normalize(u_LightPos);
    vec3 normal = normalize(v_normal);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 light_atten_coff = u_LightIntensity / pow(length(u_LightPos - v_position), 2.0);
    vec3 diffuse = diff * light_atten_coff * color;

    vec3 viewDir = normalize(u_CameraPos - v_position);
    vec3 halfDir = normalize((lightDir + viewDir));
    float spec = pow(max(dot(halfDir, normal), 0.0), u_Ns);
    vec3 specular = u_Ks * light_atten_coff * spec;

    vec3 radiance = (ambient + diffuse + specular);
 
    vec3 phongColor = pow(radiance, vec3(1.0 / 2.2));
    return phongColor;
}

bool hit(vec3 position,vec3 direction,out vec3 hitbary)
{
    return true;
}

bool ray_tracing(vec3 position,vec3 direction,out vec3 color)
{
    vec3 albedo[MAXBOUNCE];
    for(int i = 0;i < u_Bounce;i++)
    {

    }

    return true;
}

void main()
{
    float s = InitRand(gl_FragCoord.xy);
    vec4 color = vec4(BlinnPhong(),1.0);
    o_color = color;
    o_Entity = u_Entity;
}