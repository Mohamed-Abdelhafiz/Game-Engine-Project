#version 330 core 
out vec4 FragColor;

in vec2 TexCoords;

uniform vec3 Color;
uniform bool ColorBool;
uniform bool CubeTextureBool;
uniform sampler2D CubeTexture;

void main(){

	if(gl_FrontFacing){
		if(ColorBool== true)
			FragColor = vec4(Color, 1.0);
		else if(CubeTextureBool==true)
			FragColor = texture(CubeTexture, TexCoords);
		else
			FragColor = vec4(1.0);
	}else
		FragColor = vec4(1.0);

}