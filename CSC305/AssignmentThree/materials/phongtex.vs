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
in vec2 texcoord0;

out vec3 norm;
out vec3 fVertex;
out vec4 position;
out vec4 fColor;
out vec2 texture0;
out vec3 view;



void main()
{

    position = modelMatrix * vec4(vertex, 1.0);     //camera position vector
    gl_Position = projectionMatrix * viewMatrix * position;


    view = vec3(viewMatrix * vec4(vertex, 1.0));    //view direction vector
    norm = normalize(normalMatrix * normal);        //Surface Normal vector

    fColor = color;
    fVertex = vertex;

    texture0 = texcoord0;

}
