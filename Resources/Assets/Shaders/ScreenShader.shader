
#ifdef __Vertex_Shader__

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;

out vec2 TexCoords;

void main()
{
    gl_Position = vec4(aPos, 1.0); 
    TexCoords = aTexCoords;
}  

#endif

//--------------------

#ifdef __Fragment_Shader__

out vec4 FragColor;
  
in vec2 TexCoords;

uniform sampler2D screenTexture;
uniform float progression;

void main()
{ 
    
    
    if (TexCoords.x < progression) 
    {
        FragColor = vec4(0, 0, 0, 1);
    }
    else 
    {
        FragColor = texture(screenTexture, TexCoords);
    }
    
    
}

#endif