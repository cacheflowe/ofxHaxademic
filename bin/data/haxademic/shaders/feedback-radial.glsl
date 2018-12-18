// by cacheflowe
// radial displacement

#version 150

in vec2 texCoordVarying;
uniform sampler2D tex0;
uniform float amp = 0.01;
uniform float samplemult = 1.0;
uniform float alphaMult = 1.0;

out vec4 outputColor;

void main()
{
  vec2 texSize = textureSize(tex0, 0);
  vec2 uv = texCoordVarying;
  float aspect = float(texSize.x) / float(texSize.y);				// feedback applied with compensated aspect ratio 
  vec4 color = texture(tex0, uv);
  vec2 center = vec2(0.5);
  float distFromCenter = distance(uv, center);
  float curRads = atan(center.y - uv.y, center.x - uv.x);			// get current pixel's angle to center
  vec2 displace = uv + vec2(amp * cos(curRads), amp * sin(curRads) * aspect);
  vec4 sampleColor = texture(tex0, displace) * vec4(vec3(samplemult), alphaMult);
  outputColor = sampleColor;
}
