bool DrawInCanvas(vec2 point, vec2 rectVertexes[4])
{
	int size = 4;
	bool isLocated = false;
	int j = size - 1;
	for (int i = 0; i < size; i++) {
		if ((rectVertexes[i].y < point.y && rectVertexes[j].y >= point.y || rectVertexes[j].y < point.y && rectVertexes[i].y >= point.y) && 
		(rectVertexes[i].x + (point.y - rectVertexes[i].y) / (rectVertexes[j].y - rectVertexes[i].y) * (rectVertexes[j].x - rectVertexes[i].x) < point.x))
		{
			isLocated = !isLocated;
		}
		j = i;
	}
	return isLocated;
}

void Draw(vec2 point, vec2 flagVertexesOutside[4], vec2 flagVertexesInside[4], vec2 flagVertexes1[4], vec2 flagVertexes2[4])
{
	if (DrawInCanvas(point, flagVertexesOutside))
	{
		gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
	}
	else if (DrawInCanvas(point, flagVertexesInside))
	{
		gl_FragColor = vec4(0.5, 0.5, 0.5, 1.0);
	} 
	else 
	{
		gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
	}

	if (DrawInCanvas(point, flagVertexes1) || DrawInCanvas(point, flagVertexes2))
	{
		gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
	}
}

void main()
{
	vec2 pos = gl_TexCoord[0].xy;

	vec2 flagVertexesOutside[4];
	flagVertexesOutside[0] = vec2(0.2, 1.0);
	flagVertexesOutside[1] = vec2(3.8, 1.0);
	flagVertexesOutside[2] = vec2(3.8, 3.0);
	flagVertexesOutside[3] = vec2(0.2, 3.0);

	vec2 flagVertexesInside[4];
	flagVertexesInside[0] = vec2(0.18, 0.98);
	flagVertexesInside[1] = vec2(3.82, 0.98);
	flagVertexesInside[2] = vec2(3.82, 3.02);
	flagVertexesInside[3] = vec2(0.18, 3.02);

	vec2 flagVertexes1[4];
	flagVertexes1[0] = vec2(1.73, 1.3);
	flagVertexes1[1] = vec2(2.13, 1.3);
	flagVertexes1[2] = vec2(2.13, 2.68);
	flagVertexes1[3] = vec2(1.73, 2.68);

	vec2 flagVertexes2[4];
	flagVertexes2[0] = vec2(1.24, 1.79);
	flagVertexes2[1] = vec2(2.62, 1.79);
	flagVertexes2[2] = vec2(2.62, 2.19);
	flagVertexes2[3] = vec2(1.24, 2.19);

	Draw(pos, flagVertexesOutside, flagVertexesInside, flagVertexes1, flagVertexes2);
}