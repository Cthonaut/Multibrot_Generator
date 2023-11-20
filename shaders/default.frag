#version 460 core
#extension GL_ARB_shading_language_420pack : enable

out vec4 FragColor;
in vec4 vertexColor;
uniform vec2 resolution;
uniform vec2 pos;
uniform vec2 power;
uniform float zoom;

vec2 cpow(vec2 z, vec2 p)
{
    vec2 result = vec2(0.0);
    if(z.x != 0)
    {
        float r_l = log(length(z));
        float theta = atan(z.y,z.x);
        float lamda = exp(r_l*p.x-theta*p.y);
        float kapa = r_l*p.y+theta*p.x;
        float r_part = lamda*cos(kapa);
        float i_part = lamda*sin(kapa);
        result = vec2(r_part,i_part);
    }
    return result;
}

vec3 computeInterations_functionset(vec2 uv, float max_iter,vec3 cols[3])
{
    vec2 c = uv;
    vec2 z = vec2(0.0);
    float iter = 0;
    for(int i = 0; i < max_iter; i++)
    {
        z = cpow(z,power) + c;
        if(dot(z,z) > 4.0)
        {
            float return_const = iter/max_iter;
            vec3 return_value = vec3(cols[0]);
            for(int j = 0; j < 3; j++)
            {
                float temp = 1;
                for(int k = 0; k < 3 - j; k++)
                {
                    temp *= return_const;
                }
                return_value += temp*cols[j];
            }
            return return_value;
        }
        ++iter;
    }
    return vec3(0);
}

void main()
{
    vec2 uv = (gl_FragCoord.xy - 0.5 * resolution.xy) / (resolution.y*zoom);
    uv = vec2(uv.x + pos.x,uv.y + pos.y);

    vec3 color1 = vec3(0.0,0.0,0.25);
    vec3 color2 = vec3(12.5,12.5,0.0);
    vec3 color3 = vec3(12.5,0.0,0.0);

    vec3 colors[3] = {color1,color2,color3};

    vec3 col = vec3(0.0);
    col = computeInterations_functionset(uv,500,colors);
    FragColor = vec4(col, 1.0);
}