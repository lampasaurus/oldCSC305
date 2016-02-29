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

out vec4 vColor;

void main()
{

    vec4 position = modelMatrix * vec4(vertex, 1.0);
    gl_Position = projectionMatrix * viewMatrix * position;

    vec3 view = vec3(viewMatrix[3]);  //camera direction
    vec3 norm = normalize(normalMatrix * normal);

    vec3 E = normalize(-view);                  //direction from surface to camera
    vec3 N = normalize(norm * normalMatrix);    // surface normal Vector
    vec3 L = normalize(lightPos - view);        //Calculates lighting direction vector
    vec3 R = normalize(-reflect(L, N));         //Calculates light reflection vector

    float shin = 10.0; //shinyness factor


    vec4 ambient = color * 0.2;  //Sets the ambient colouring
    vec4 diffuse = clamp((lightCol + 3 * color)/4 * max(dot(N, L), 0.0), 0.0, 1.0) * 1.0;           //Diffuse reflection = diffuseColor * angle

    vec4 specular = clamp((lightCol + color)/2 * pow(max(dot(R,E),0.0),shin) , 0.0, 1.0) * 0.3;     //Specular reflection = specularColor * reflection ^ shinyness
    if(dot(N, L) <= 0)
        specular = color * 0;                                                                       //accounts for if the specular is in the direction of the light or facing away from it.

    vColor = ambient + diffuse + specular;      //final output color

}
