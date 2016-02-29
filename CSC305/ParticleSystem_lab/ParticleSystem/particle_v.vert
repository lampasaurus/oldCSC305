#version 150

in vec3 vVelocity; // initial velocity
in float timeStarted; // time that particle started

uniform  mat4 matrix;  // projection matrix * view matrix
uniform  float timeElapsed; // system time T in seconds
uniform  float maxPointSize;
uniform  vec3 startPosition; // emitter position in world coordinates

out float opacity;

void main() {
    float t = (timeElapsed - timeStarted)/1000;
  // work out how many seconds into our particle's life-time we are (after its starting time)
  
    gl_PointSize = maxPointSize - (t*10);
  // calculate the point size and change the size of particles over time using maxPointSize
    opacity = 1;
  // gradually make particle more transparent over its life-time
    vec3 p = startPosition;
  // p stores the particle position

    float speed = 1.0;
  // particle stays put until it has reached its birth second
  if (t > 0) {
    // gravity vector (acceleration)
    p.x = startPosition.x + vVelocity.x * t / speed;
    p.y = startPosition.y + vVelocity.y * t / speed - t * t * 2;
    p.z = startPosition.z + vVelocity.z * t / speed;

    // a standard kinematics equation of motion with velocity (from VBO) and acceleration (gravity), note: normalize velocity.
   
  } else {
    
  }
  gl_Position = matrix * vec4(p, 1);
}

