#version 330 core 
out vec4 FragColor;

in vec2 TexCoords;

uniform vec3 Color;
uniform sampler2D Cubetexture;

void main(){

	if(Color== NULL)
		FragColor = vec4(Color, 1.0);
	else if(Cubetexture== NULL)
		FragColor = texture(CubeTexture, TexCoords);
	else
		FragColor = vec4(1.0);

}