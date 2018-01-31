#version 330 core
out vec4 Fragcolor;

in vec2 TexCoords;
uniform sampler2D texture_diffuse;

void main(){
	Fragcolor = texture(texture_diffuse, TexCoords);
}