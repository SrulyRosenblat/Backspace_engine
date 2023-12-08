#version 330 core

in vec2 TexCoord;
uniform sampler2D picture;

out vec4 fragColor;


void main()
{
  fragColor = texture(picture,TexCoord);
}