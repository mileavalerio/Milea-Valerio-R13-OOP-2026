#include <iostream>
#include <cmath>
#include "Canvas.h"

using namespace std;

Canvas::Canvas(int width, int height)
{
	w = width;
	h = height;

	matrix = new char*[h];

	for(int i = 0; i < h; i++)
	{
		matrix[i] = new char[w];
		for (int j = 0; j < w; j++)
			matrix[i][j] = ' ';
	}

}

void Canvas::SetPoint(int x, int y, char ch) 
{
	if (x >= 0 && x < w && y >= 0 && y < h) 
	{
		matrix[y][x] = ch;
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++)
	{
		if (i >= 0 && i < h)
		{
			if(left > 0 && left < w) matrix[i][left] = ch;
			if(right > 0 && right < w) matrix[i][right] = ch;
		}
	}
	for (int j = left + 1; j < right; j++)
	{
		if (j >= 0 && j < w)
		{
			if(top > 0 && top < h) matrix[top][j] = ch;
			if(bottom > 0 && bottom < h) matrix[bottom][j] = ch;
		}
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
			if(i > 0 && j > 0 && i < h && j < w)
				matrix[i][j] = ch;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = y - ray; i <= y + ray; i++)
		for (int j = x - ray; j <= x + ray; j++)
			if (i >= 0 && j >= 0 && i < h && j < w && round(sqrt((j - x) * (j - x) + (i - y) * (i - y))) == ray)
				matrix[i][j] = ch;
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = y - ray; i <= y + ray; i++)
		for (int j = x - ray; j <= x + ray; j++)
			if (i >= 0 && j >= 0 && i < h && j < w && round(sqrt((j - x) * (j - x) + (i - y) * (i - y))) <= ray)
				matrix[i][j] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);

	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;

	int err = dx - dy;

	while (true)
	{
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2) break;

		if (2 * err > -dy) 
		{
			err -= dy;
			x1 += sx;
		}

		if (2 * err < dx) 
		{
			err += dx;
			y1 += sy;
		}
	}
}

void Canvas::Print()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			cout << matrix[i][j];
		cout << endl;
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			matrix[i][j] = ' ';
		}
	}
}