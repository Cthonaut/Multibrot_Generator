#version 330 core
out vec4 FragColor;
in vec4 vertexColor;
uniform vec2 resolution;

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

float computeInterations_functionset(vec2 uv, float max_iter)
{
    vec2 c = uv;
    vec2 z = vec2(0.0);
    float iter = 0;
    for(int i; i < max_iter; i++)
    {
        z = cpow(z,vec2(2,0)) + c;
        if(dot(z,z) > 4.0)
        {
            return iter/max_iter;
        }
        ++iter;
    }
    return 0.0f;// το εσωτερικό του συνόλου
}

void main()
{
    vec2 uv = (gl_FragCoord.xy - 0.5 * resolution.xy) / (resolution.y);

    vec3 col = vec3(0.0);
    col += computeInterations_functionset(uv,50);
    FragColor = vec4(col, 1.0);
}