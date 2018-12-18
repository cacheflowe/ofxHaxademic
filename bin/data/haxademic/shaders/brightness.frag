#version 150

uniform float brightness;

in vec2 texCoordVarying;
uniform sampler2D tex0;

out vec4 outputColor;

void main()
{
	vec4 color = texture(tex0, texCoordVarying);
	color *= brightness;
	outputColor = vec4(color.r, color.g, color.b, 1.0);
}