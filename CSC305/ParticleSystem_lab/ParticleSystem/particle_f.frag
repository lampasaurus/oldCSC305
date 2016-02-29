#version 150
uniform sampler2D textureID; //  using a texture for particles
out vec4 color;

in float opacity;

void main() {
 // using point uv coordinates which are pre-defined over the point
   vec4 texcol = texture(textureID, gl_PointCoord);

// change the opacity of texture color and assign it to "color" as a out : create a vec4 color using opacity.
      color = vec4(1.0,0.5,0.5,0.5)* texcol / opacity;
}
