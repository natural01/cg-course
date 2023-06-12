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

bool DrawInStar(vec2 centerCoord, float smallCircleRadius, float bigCircleRadius, vec2 point)
{
	#define M_PI 3.1415926535897932384626433832795
	vec2 starVertexes[10];

	starVertexes[0] = vec2(centerCoord.x, centerCoord.y + bigCircleRadius);

	starVertexes[1] = vec2(centerCoord.x + smallCircleRadius * cos(126*M_PI/180), centerCoord.y + smallCircleRadius * sin(126*M_PI/180));
	starVertexes[2] = vec2(centerCoord.x + bigCircleRadius * cos(162*M_PI/180), centerCoord.y + bigCircleRadius * sin(162*M_PI/180));
	starVertexes[3] = vec2(centerCoord.x + smallCircleRadius * cos(198*M_PI/180), centerCoord.y + smallCircleRadius * sin(198*M_PI/180));
	starVertexes[4] = vec2(centerCoord.x + bigCircleRadius * cos(234*M_PI/180), centerCoord.y + bigCircleRadius * sin(234*M_PI/180));
	starVertexes[5] = vec2(centerCoord.x, centerCoord.y - smallCircleRadius);
	starVertexes[6] = vec2(centerCoord.x + bigCircleRadius * cos(306*M_PI/180), centerCoord.y + bigCircleRadius * sin(306*M_PI/180));
	starVertexes[7] = vec2(centerCoord.x + smallCircleRadius * cos(342*M_PI/180), centerCoord.y + smallCircleRadius * sin(342*M_PI/180));
	starVertexes[8] = vec2(centerCoord.x + bigCircleRadius * cos(18*M_PI/180), centerCoord.y + bigCircleRadius * sin(18*M_PI/180));
	starVertexes[9] = vec2(centerCoord.x + smallCircleRadius * cos(54*M_PI/180), centerCoord.y + smallCircleRadius * sin(54*M_PI/180));
	int size = 10;
	bool isLocated = false;
	int j = size - 1;
	for (int i = 0; i < size; i++) {
		if ((starVertexes[i].y < point.y && starVertexes[j].y >= point.y || starVertexes[j].y < point.y && starVertexes[i].y >= point.y) && 
		(starVertexes[i].x + (point.y - starVertexes[i].y) / (starVertexes[j].y - starVertexes[i].y) * (starVertexes[j].x - starVertexes[i].x) < point.x))
		{
			isLocated = !isLocated;
		}
		j = i;
	}
	return isLocated;
}

void Draw(vec2 point, vec2 flagVertexesOutside[4], vec2 flagVertexesInside[4], vec2 starCenterCoord, 
	float smallCircleRadius, float bigCircleRadius)
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

	if (DrawInStar(starCenterCoord, smallCircleRadius, bigCircleRadius, point))
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

	float smallCircleRadius = 0.36;
	float bigCircleRadius = 1.0;
	vec2 starCenterCoord = vec2(2.0, 2.0);

	Draw(pos, flagVertexesOutside, flagVertexesInside, starCenterCoord, smallCircleRadius, bigCircleRadius);
}