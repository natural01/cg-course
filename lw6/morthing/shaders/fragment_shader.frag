#define M_PI 3.1415926535897932384626433832795

bool checkArray(vec2 point, int arraySize, vec2 array[10])
{
	bool isLocated = false;
	int j = arraySize - 1;
	for (int i = 0; i < arraySize; i++) {
		if ((array[i].y < point.y && array[j].y >= point.y || array[j].y < point.y && array[i].y >= point.y) && 
		(array[i].x + (point.y - array[i].y) / (array[j].y - array[i].y) * (array[j].x - array[i].x) < point.x))
		{
			isLocated = !isLocated;
		}
		j = i;
	}
	return isLocated;
}

bool DrawInArea(vec2 point, vec2 rectVertexes[10])
{
	return checkArray(point, 4, rectVertexes);
}

bool DrawInStar(vec2 centerCoord, float smallCircleRadius, float bigCircleRadius, vec2 point)
{
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
	return checkArray(point, 10, starVertexes);
}

bool DrawInHammer(vec2 startCoord, vec2 point)
{
	vec2 hammerVertexes[10];

	hammerVertexes[0] = vec2(startCoord.x, startCoord.y);
	hammerVertexes[1] = vec2(startCoord.x - 0.05, startCoord.y - 0.04);
	hammerVertexes[2] = vec2(startCoord.x - 0.1, startCoord.y + 0.02);
	hammerVertexes[3] = vec2(startCoord.x + 0.02, startCoord.y + 0.11);
	hammerVertexes[4] = vec2(startCoord.x + 0.08, startCoord.y + 0.05);
	hammerVertexes[5] = vec2(startCoord.x + 0.03, startCoord.y + 0.02);
	hammerVertexes[6] = vec2(startCoord.x + 0.33, startCoord.y - 0.26);
	hammerVertexes[7] = vec2(startCoord.x + 0.3, startCoord.y - 0.29);

	return checkArray(point, 8, hammerVertexes);
}

bool DrawInSickle(vec2 centerCoords, float angle, vec2 point, float a, float b)
{
	angle = angle * M_PI / 180;

    float p = (pow(cos(angle)*(point.x - centerCoords.x) + sin(angle)*(point.y - centerCoords.y), 2) / pow(a, 2))
            + (pow(sin(angle)*(point.x - centerCoords.x) - cos(angle)*(point.y - centerCoords.y), 2) / pow(b, 2));
 
    return p <= 1;
}

void Draw(vec2 point, vec2 rectVertexes[10], vec2 starCenterCoord, float smallCircleRadius, float bigCircleRadius, 
			   vec2 hammerStartCoord, vec2 biggerEllipseCenter, float biggerEllipseRotateAngle, float biggerLargeSemiaxis, 
			   float biggerSmallSemiaxis, vec2 smallerEllipseCenter, float smallerEllipseRotateAngle, float smallerElargeSemiaxis, 
			   float smallerSmallSemiaxis, vec2 handleVertexes[10], vec2 handleVertexes2[10], vec2 shade[10])
{
	if (DrawInArea(point, rectVertexes))
	{
		gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
		if (DrawInStar(starCenterCoord, smallCircleRadius, bigCircleRadius, point))
		{
			gl_FragColor = vec4(1.0, 1.0, 0.0, 1.0);
			if (DrawInStar(starCenterCoord, smallCircleRadius-0.022, bigCircleRadius-0.022, point))
			{
				gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
			}
		}
		else if (DrawInSickle(biggerEllipseCenter, biggerEllipseRotateAngle, point, biggerLargeSemiaxis, biggerSmallSemiaxis) ||
				 DrawInArea(point, handleVertexes2))
		{
			gl_FragColor = vec4(1.0, 1.0, 0.0, 1.0);
			if (DrawInSickle(smallerEllipseCenter, smallerEllipseRotateAngle, point, smallerElargeSemiaxis, smallerSmallSemiaxis) ||
				DrawInArea(point, handleVertexes) || DrawInArea(point, shade))
			{
				gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
			}

			
		}
		if (DrawInHammer(hammerStartCoord, point))
		{
			gl_FragColor = vec4(1.0, 1.0, 0.0, 1.0);
		}
	}
	else
	{
		gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
	}
}

void main()
{
	vec2 pos = gl_TexCoord[0].xy;

	vec2 canvasVertexes[10];
	canvasVertexes[0] = vec2(0.2, 1.0);
	canvasVertexes[1] = vec2(3.8, 1.0);
	canvasVertexes[2] = vec2(3.8, 3.0);
	canvasVertexes[3] = vec2(0.2, 3.0);

	float smallCircleRadius = 0.05;
	float bigCircleRadius = 0.14;
	vec2 starCenterCoord = vec2(0.7, 2.64);

	vec2 hammerStartCoord = vec2(0.62, 2.3);

	float biggerLargeSemiaxis = 0.26;
	float biggerSmallSemiaxis = 0.20; 
	float biggerllipseRotateAngle = 128.0;
	vec2 biggerEllipseCenter = vec2(0.7, 2.25);

	float smallerLargeSemiaxis = 0.24, smallerSmallSemiaxis = 0.17, smallerllipseRotateAngle = 125.0;
	vec2 smallerEllipseCenter = vec2(0.67, 2.27);

	vec2 handleVertexes1[10];
	handleVertexes1[0] = vec2(smallerEllipseCenter.x+0.3, smallerEllipseCenter.y-0.5);
	handleVertexes1[1] = vec2(smallerEllipseCenter.x+0.35, smallerEllipseCenter.y-0.48);
	handleVertexes1[2] = vec2(smallerEllipseCenter.x+0.6, smallerEllipseCenter.y-1.5);
	handleVertexes1[3] = vec2(smallerEllipseCenter.x+0.58, smallerEllipseCenter.y-1.52);

	vec2 handleVertexes2[10];
	handleVertexes2[0] = vec2(0.7, 2.3);
	handleVertexes2[1] = vec2(0.75, 2.25);
	handleVertexes2[2] = vec2(0.5, 2.0);
	handleVertexes2[3] = vec2(0.45, 2.05);

	vec2 shade[10];
	shade[0] = vec2(0.7, 2.3);
	shade[1] = vec2(0.5, 2.4);
	shade[2] = vec2(0.3, 2.0);
	shade[3] = vec2(0.45, 2.05);

	Draw(pos, canvasVertexes, starCenterCoord, smallCircleRadius, bigCircleRadius, hammerStartCoord, 
			  biggerEllipseCenter, biggerllipseRotateAngle, biggerLargeSemiaxis, biggerSmallSemiaxis, smallerEllipseCenter, 
			  smallerllipseRotateAngle, smallerLargeSemiaxis, smallerSmallSemiaxis, handleVertexes1, handleVertexes2, shade);
}