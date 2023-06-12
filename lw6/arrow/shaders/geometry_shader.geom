#version 150

layout(lines) in;
layout(line_strip) out;
layout(max_vertices = 5) out;

in mat4 modelViewMatrix[];
in mat4 projectionMatrix[];

vec2 GenerateVector(float angle, float vecAngle, float size)
{
    float angleRadians = radians(angle) + vecAngle;
    return vec2(size * cos(angleRadians), size * sin(angleRadians));
}

void DrawArraw(mat4 matrix1, mat4 matrix2, vec2 downLine, vec2 upLine)
{
    gl_Position = matrix1[0] * matrix2[0] * gl_in[0].gl_Position;
    EmitVertex();
    gl_Position = matrix1[0] * matrix2[0] * gl_in[1].gl_Position;
    EmitVertex();
    gl_Position = matrix1[0] * matrix2[0] * (gl_in[1].gl_Position + vec4(downLine, 0, 0));
    EmitVertex();
    gl_Position = matrix1[0] * matrix2[0] * gl_in[1].gl_Position;
    EmitVertex();
    gl_Position = matrix1[0] * matrix2[0] * (gl_in[1].gl_Position + vec4(upLine, 0, 0));
    EmitVertex();
    EndPrimitive();
}

void main()
{
    float arrowEndLenght = distance(gl_in[0].gl_Position, gl_in[1].gl_Position);
    float arrowSize = arrowEndLenght / 4;
    const float rightAngle = 180 - 30 / 2;
    const float leftAngle = 180 + 30 / 2;

    vec2 vecX = vec2(1, 0);
    vec2 vecArrow = normalize(gl_in[1].gl_Position.xy - gl_in[0].gl_Position.xy);

    float dotProductBetweenVecAndAbscissa = dot(vecX, vecArrow);

    float angleBetweenVecAndAbscissa = acos(dotProductBetweenVecAndAbscissa);

    if (gl_in[1].gl_Position.y < gl_in[0].gl_Position.y)
    {
        angleBetweenVecAndAbscissa = -angleBetweenVecAndAbscissa;
    }

    vec2 downLine = GenerateVector(rightAngle, angleBetweenVecAndAbscissa, arrowSize);
    vec2 upLine = GenerateVector(leftAngle, angleBetweenVecAndAbscissa, arrowSize);

    gl_Position = projectionMatrix[0] * modelViewMatrix[0] * gl_in[0].gl_Position;
    EmitVertex();
    gl_Position = projectionMatrix[0] * modelViewMatrix[0] * gl_in[1].gl_Position;
    EmitVertex();
    gl_Position = projectionMatrix[0] * modelViewMatrix[0] * (gl_in[1].gl_Position + vec4(downLine, 0, 0));
    EmitVertex();
    gl_Position = projectionMatrix[0] * modelViewMatrix[0] * gl_in[1].gl_Position;
    EmitVertex();
    gl_Position = projectionMatrix[0] * modelViewMatrix[0] * (gl_in[1].gl_Position + vec4(upLine, 0, 0));
    EmitVertex();

    EndPrimitive();
}