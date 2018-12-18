// by cacheflowe
// leaves black but turns other colors transparent

#version 150

in vec2 texCoordVarying;
uniform sampler2D tex0;
uniform float crossfade = 1.0;

out vec4 outputColor;

void main()
{
	vec4 color = texture(tex0, texCoordVarying);
    float grayColor = (color.r + color.g + color.b) / 3.;
    // grayColor = smoothstep(0., 0.2, grayColor); // quick falloff from full black
    float alpha = 1. - (grayColor * crossfade);
    outputColor = vec4(color.rgb, alpha);
}