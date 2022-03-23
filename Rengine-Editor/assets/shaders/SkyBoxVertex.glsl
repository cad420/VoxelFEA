#version 330

layout(location = 0) vec3 a_Position;
// layout(location = 1) vec3 a_Normal;
// layout(location = 2) vec2 a_TexCoords;

uniform mat4 u_Transform;
uniform mat4 u_View;
uniform mat4 u_Projection;
uniform mat4 u_MoveWithCamera;

out vec2 v_TexCoords;
out vec3 v_FragPos;
out vec3 v_Normal;

void main() {

    // v_Normal = a_Normal;
    // v_TexCoords = a_TexCoords;
    v_TexCoords = a_Position;
    vec4 position = u_Projection * m_View * vec4(a_Position, 1.0);
    gl_Position = position.xyww;
    // gl_Position = u_Projection * viewMatrix * u_Transform * u_MoveWithCamera * vec4(a_Position, 1.0);
    //gl_Position = uProjectionMatrix * uViewMatrix * uModelMatrix * vec4(aVertexPosition, 1.0);
    v_FragPos = a_Position;
    //gl_Position.xyz;
}