#version 150

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
uniform int usePostMultiply;
uniform mat3 normalMatrix;
uniform vec3 lightPos;
uniform vec4 lightCol;

in vec4 fColor;
in vec3 fVertex;
in vec3 norm;
in vec4 position;
in vec3 view;
in vec2 texture0;

uniform sampler2D colormap;


out vec4 vColor;

void main()
{
    vec3 E = normalize(-view);                  //direction from surface to camera
    vec3 N = normalize(norm * normalMatrix);    // surface normal Vector
    vec3 L = normalize(lightPos - view);        //Calculates lighting direction vector
    vec3 R = normalize(-reflect(L, N));         //Calculates light reflection vector

    float shin = 80.0;                          //Shinyness factor

    vec4 texCol = texture(colormap, texture0);  //Gets the color from the texture at location texture0

    vec4 ambient = texCol * 0.2;                                                                        //Sets the ambient colouring
    vec4 diffuse = clamp((lightCol + 3 * texCol)/4 * max(dot(N, L), 0.0), 0.0, 1.0) * 1.0;              //Diffuse reflection = diffuseColor * angle
    vec4 specular = clamp((lightCol + texCol)/2 * pow(max(dot(R,E),0.0),shin) , 0.0, 1.0) * 0.3;        //Specular reflection = specularColor * reflection ^ shinyness
    if(dot(N, L) <= 0)
        specular = fColor * 0;                                                                          //accounts for if the specular is in the direction of the light or facing away from it.

    vColor = ambient + diffuse + specular;      //final output color
}
