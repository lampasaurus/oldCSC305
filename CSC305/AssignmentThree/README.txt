Keiran Reilly V00715836
Assignment 3: Shaders


1 pt for code comments & README.txt file (Completed)
1 pt for loading textures and uploading them to OpenGL (Completed)
2 pt for Gouraud shading of vertex colours (Completed)
2 pt for Phong shading of vertex colours (Completed)
2 pt for Phong shading with textures	(Completed)
2 pt for Bump mapping	(Nope)
2 bonus points for toon shading (Completed)

Instructions for compiling:
It should compile fine on the lab computers.  It was made entirely on them.

Instructions for running:
Click the add button, select a 3d .obj file
Click File->LoadShader and select a .materials file


Shader formula was modified from:
http://www.blog.nathanhaze.com/glsl-phong-and-gouard-shading/


Log:
So I started with the Gouaurd shader, and after about a day I had something that looked like a light going around my objects.
I moved on to Phong shading, I just copied most of the stuff out of my Gouaurd shader.  After getting this working, i noticed a problem with the math in my shaders, the specular was showing up on the opposite side of the light.
Spent 5 or so hours finding out that i needed a "if(angle < 0) specular = 0" in there
Went on to texturing, which went without a hitch EXCEPT that the parameter GL_TEXTURE2D 
doesn't exist!  So i spent another 3 or so hours trying to find out why, and ended
up replacing it with GL_TEXTURE_2D.
After getting the textured shader working, I went on to bump mapping.
After about an hour of looking into bump mapping, I decided I'd had enough and skipped it.
I'd heard that toon shading was an accepted bonus mark, so I made a toon shader in about
half an hour.
Then I took some screenshots, wrote this, and zipped the folder up.