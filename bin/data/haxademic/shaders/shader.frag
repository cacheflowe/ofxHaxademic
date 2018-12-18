#version 150

uniform int width;
uniform int height;
uniform float amp;
uniform int time;

in vec2 texCoordVarying;

out vec4 outputColor;

void main()
{
	float timeMult = float(time) * 0.1;
	vec2 center = vec2(0);
	vec2 uv = vec2(gl_FragCoord.x / float(width), gl_FragCoord.y / float(height)) - 0.5;
	uv.x *= float(width) / float(height);
	float luma = 0.5 + 0.5 * sin(-timeMult + (50. + amp * 100.) * distance(uv, center));		// texCoordVarying.x; // 
	luma = smoothstep(0.45, 0.55, luma);
	outputColor = vec4(luma, luma, luma, 1.);
}