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

    float shin = 80.0;                          //Sinyness factor

    vec4 texCol = texture(colormap, texture0);
    vec4 toon;                                  //Generates a range of colors to pick from based on the angle of the light
    if (dot(N, L) > 0.95)
            toon = vec4(1.0,0.5,0.5,1.0) * texCol;
    else if (dot(N, L) > 0.5)
            toon = vec4(0.4,0.2,0.2,1.0)* texCol;
    else if (dot(N, L) > 0.25)
            toon = vec4(0.2,0.1,0.1,1.0)* texCol;
    else
            toon = vec4(0.0,0.0,0.0,1.0);

    vColor = toon;                              //final output color
}
