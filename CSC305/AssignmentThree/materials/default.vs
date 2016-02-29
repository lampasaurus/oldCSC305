#version 150

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
uniform int usePostMultiply;
uniform mat3 normalMatrix;
uniform vec3 lightPos;
uniform vec4 lightCol;


in vec3 vertex;
in vec4 color;
in vec3 normal;
in vec4 texcoord0;

out vec4 vColor;

void main()
{
	vec4 position = modelMatrix * vec4(vertex, 1.0);
	gl_Position = projectionMatrix * viewMatrix * position;

        vColor = vec4(0.0, 1.0, 0.5, 0.0);
}
