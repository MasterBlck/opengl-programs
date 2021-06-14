// (C) JUAN CARLOS CONDE RAMIREZ - 2011

#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

GLfloat alpha=0, beta=0;
GLint px0, py0;

//FRENTE
	GLfloat ctrlpoints1[5][5][3] =
{
	{{-2.0, -5.0,  0.0},
	{-1.0, -4.8,  0.0},
	{-0.0, -4.8,  0.0},
	{ 1.0, -4.6,  0.0},
	{ 2.0, -4.2,  0.0}},

	{{-2.0, -2.5,  0.5},
	{-1.0, -2.5,  0.5},
	{-0.0, -2.5,  0.5},
	{ 1.0, -2.5,  0.5},
	{ 2.0, -2.5,  0.5}},

	{{-2.0,  0.0,  1.0},
	{-1.0,  0.0,  1.0},
	{-0.0,  0.0,  1.0},
	{ 1.0,  0.0,  1.0},
	{ 2.0,  0.0,  1.0}},

	{{-2.0,  2.5,  0.5},
	{-1.0,  2.5,  0.5},
	{-0.0,  2.5,  0.5},
	{ 1.0,  2.5,  0.5},
	{ 2.0,  2.5,  0.5}},

	{{-2.0,  5.0,  0.0},
	{-1.0,  4.8,  0.0},
	{-0.0,  4.8,  0.0},
	{ 1.0, 4.6,  0.0},
	{ 2.0, 4.2,  0.0}}
};

GLfloat ctrlpoints2[5][5][3] =
{
	{{-2.0, -4.2,  0.0},
	{-1.0, -4.6,  0.0},
	{-0.0, -4.8,  0.0},
	{ 1.0, -4.8,  0.0},
	{ 2.0, -5.0,  0.0}},

	{{-2.0, -2.5,  0.5},
	{-1.0, -2.5,  0.5},
	{-0.0, -2.5,  0.5},
	{ 1.0, -2.5,  0.5},
	{ 2.0, -2.5,  0.5}},

	{{-2.0,  0.0,  1.0},
	{-1.0,  0.0,  1.0},
	{-0.0,  0.0,  1.0},
	{ 1.0,  0.0,  1.0},
	{ 2.0,  0.0,  1.0}},

	{{-2.0,  2.5,  0.5},
	{-1.0,  2.5,  0.5},
	{-0.0,  2.5,  0.5},
	{ 1.0,  2.5,  0.5},
	{ 2.0,  2.5,  0.5}},

	{{-2.0,  4.2,  0.0},
	{-1.0,  4.6,  0.0},
	{-0.0,  4.8,  0.0},
	{ 1.0, 4.8,  0.0},
	{ 2.0, 5.0,  0.0}}
};

GLfloat ctrlpoints3[5][5][3] =
{
	{{-2.1, -5.0,  0.0},
	{-1.0, -5.0,  0.0},
	{-0.0, -5.0,  0.0},
	{ 1.0, -5.0,  0.0},
	{ 2.1, -5.0,  0.0}},

	{{-2.1, -3.75,  0.25},
	{-1.0, -3.75,  0.25},
	{-0.0, -3.75,  0.25},
	{ 1.0, -3.75,  0.25},
	{ 2.1, -3.75,  0.25}},

	{{-2.1,  -2.5,  0.60},
	{-1.0,  -2.5,  0.60},
	{-0.0,  -2.5,  0.60},
	{ 1.0,  -2.5,  0.60},
	{ 2.1,  -2.5,  0.60}},

	{{-2.1,  -1.25,  0.65},
	{-1.0,  -1.25,  0.65},
	{-0.0,  -1.25,  0.65},
	{ 1.0,  -1.25,  0.65},
	{ 2.1,  -1.25,  0.65}},

	{{-2.1, 0.0,  0.60},
	{-1.0,  0.0,  0.60},
	{-0.0,  0.0,  0.60},
	{ 1.0,  0.0,  0.60},
	{ 2.1,  0.0,  0.60}}
};

GLfloat ctrlpoints4[5][5][3] =
{
	{{-2.0, -4.2,  0.0},
	{-0.5, -4.2,  0.0},
	{-0.5, -4.2,  0.0},
	{-0.5, -4.2,  0.0},
	{-0.5, -2.5,  0.0}},

	{{-2.5, -2.5,  0.0},
	{-2.0, -2.5,  0.0},
	{-1.5, -2.5,  0.0},
	{-1.5, -2.5,  0.0},
	{-1.5, -2.5,  0.0}},

	{{-3.0,  0.0,  0.0},
	{-2.5,  0.0,  0.0},
	{-2.0,  0.0,  0.0},
	{-2.0, 0.0,  0.0},
	{-2.0, 0.0,  0.0}},

	{{-2.5,  2.5,  0.0},
	{-2.0,  2.5,  0.0},
	{-2.0,  2.5,  0.0},
	{-2.0,  2.5,  0.0},
	{-2.0,  2.5,  0.0}},

	{{-2.0,  4.2,  0.0},
	{-2.0,  4.2,  0.0},
	{-2.0,  4.2,  0.0},
	{-2.0, 4.2,  0.0},
	{-2.0, 4.2,  0.0}}
};

GLfloat ctrlpoints5[5][5][3] =
{
	{{2.0,  4.2,  0.0},
	{ 2.0,  4.2,  0.0},
	{ 2.0,  4.2,  0.0},
	{ 2.0,  4.2,  0.0},
	{ 2.0,  4.2,  0.0}},

	{{2.5,  2.5,  0.0},
	{ 2.0,  2.5,  0.0},
	{ 2.0,  2.5,  0.0},
	{ 2.0,  2.5,  0.0},
	{ 2.0,  2.5,  0.0}},

	{{3.0,  0.0,  0.0},
	{ 2.5,  0.0,  0.0},
	{ 2.0,  0.0,  0.0},
	{ 2.0,  0.0,  0.0},
	{ 2.0,  0.0,  0.0}},

	{{ 2.5, -2.5,  0.0},
	{ 2.0, -2.5,  0.0},
	{ 1.5, -2.5,  0.0},
	{ 1.5, -2.5,  0.0},
	{ 1.5, -2.5,  0.0}},

	{{2.0, -4.2,  0.0},
	{ 0.5, -4.2,  0.0},
	{ 0.5, -4.2,  0.0},
	{ 0.5, -4.2,  0.0},
	{ 0.5, -2.5,  0.0}}
};

GLfloat ctrlpoints6[5][5][3] =
{
	{{-6.0, -2.0,  0.0},
	{-3.0, -2.0,  1.0},
	{ 0.0, -2.0,  1.0},
	{ 3.0, -2.0,  1.0},
	{ 6.0, -2.0,  0.0}},

	{{-6.0, -1.0,  0.0},
	{-3.0, -1.0,  1.0},
	{ 0.0, -1.0,  1.0},
	{ 3.0, -1.0,  1.0},
	{ 6.0, -1.0,  0.0}},

	{{-6.0,  0.0,  0.0},
	{-3.0,  0.0,  1.0},
	{ 0.0,  0.0,  1.0},
	{ 3.0,  0.0,  1.0},
	{ 6.0,  0.0,  0.0}},

	{{-6.0,  1.0,  0.0},
	{-3.0,  1.0,  1.0},
	{ 0.0,  1.0,  1.0},
	{ 3.0,  1.0,  1.0},
	{ 6.0,  1.0,  0.0}},

	{{-6.0,  2.0,  0.0},
	{-3.0,  2.0,  1.0},
	{ 0.0,  2.0,  1.0},
	{ 3.0,  2.0,  1.0},
	{ 6.0,  2.0,  0.0}}
};

GLfloat ctrlpoints7[5][5][3] =
{
	{{-2.75, -5.0,  0.0},
	{-1.0, -5.0,  0.0},
	{-0.0, -5.0,  0.0},
	{ 1.0, -5.0,  0.0},
	{ 2.75, -5.0,  0.0}},

	{{-2.5, -3.75,  0.25},
	{-1.0, -3.75,  0.25},
	{-0.0, -3.75,  0.25},
	{ 1.0, -3.75,  0.25},
	{ 2.5, -3.75,  0.25}},

	{{-2.0,  -2.5,  0.60},
	{-1.0,  -2.5,  0.60},
	{-0.0,  -2.5,  0.60},
	{ 1.0,  -2.5,  0.60},
	{ 2.0,  -2.5,  0.60}},

	{{-2.0,  -1.25,  0.65},
	{-1.0,  -1.25,  0.65},
	{-0.0,  -1.25,  0.65},
	{ 1.0,  -1.25,  0.65},
	{ 2.0,  -1.25,  0.65}},

	{{-1.75, 0.0,  0.60},
	{-1.0,  0.0,  0.60},
	{-0.0,  0.0,  0.60},
	{ 1.0,  0.0,  0.60},
	{ 1.75,  0.0,  0.60}}
};

GLfloat ctrlpoints8[5][5][3] =
{
	{{-2.75, -5.0,  0.0},
	{-2.0, -3.75,  0.0},
	{-0.0, -2.5,  0.0},
	{ 1.8, -1.25,  1.0},
	{ 1.8, -1.25, -1.0}},

	{{-2.5, -3.75,  0.25},
	{-2.0, -3.75,  0.25},
	{-0.0, -2.5,  0.25},
	{ 1.8, -1.25,  1.25},
	{ 1.8, -1.25, -1.25}},

	{{-2.5,  -2.5,  0.60},
	{-2.0,  -2.5,  0.60},
	{-0.0,  -1.25,  0.60},
	{ 1.8,  -1.25,  1.60},
	{ 1.8,  -1.25,  -1.60}},

	{{-2.5,  -1.25,  0.65},
	{-2.0,  -1.25,  0.65},
	{-0.0,  -1.25,  0.65},
	{ 1.8,  -1.25,  1.65},
	{ 1.8,  -1.25, -1.65}},

	{{-2.75, 0.0,  0.60},
	{-2.0, -1.0,  0.60},
	{-0.0, -1.25,  0.60},
	{ 2.5,  -0.8,  1.60},
	{ 2.5,  0.8, -1.0}}
};

GLfloat ctrlpoints9[5][5][3] =
{
	{{2.75, 0.0,  0.60},
	{ 2.0, -1.0,  0.60},
	{ 0.0, -1.25,  0.60},
	{-2.5,  -0.8,  1.60},
	{-2.5,  0.8, -1.0}},

	{{2.5,  -1.25,  0.65},
	{ 2.0,  -1.25,  0.65},
	{ 0.0,  -1.25,  0.65},
	{-1.8,  -1.25,  1.65},
	{-1.8,  -1.25, -1.65}},

	{{2.5,  -2.5,  0.60},
	{ 2.0,  -2.5,  0.60},
	{ 0.0,  -1.25,  0.60},
	{-1.8,  -1.25,  1.60},
	{-1.8,  -1.25,  -1.60}},

	{{2.5, -3.75,  0.25},
	{ 2.0, -3.75,  0.25},
	{ 0.0, -2.5,  0.25},
	{-1.8, -1.25,  1.25},
	{-1.8, -1.25, -1.25}},

	{{2.75, -5.0,  0.0},
	{2.0, -3.75,  0.0},
	{0.0, -2.5,  0.0},
	{-1.8, -1.25,  1.0},
	{-1.8, -1.25, -1.0}},
};

GLfloat ctrlpoints10[5][5][3] =
{
	{{0.0, -4.2, -2.0},
	{ 0.0, -5.0, -0.25},
	{-0.5, -5.0,  0.5},
	{ 0.25, -5.0,  0.0},
	{ 1.5, -5.0,  0.0}},

	{{0.0, -3.75, -2.0},
	{ 0.0, -3.75, -0.25},
	{-0.5, -3.75,  0.5},
	{ 0.25, -3.75,  0.0},
	{ 1.5, -3.75,  0.0}},

	{{0.0,  -2.5, -2.0},
	{ 0.0,  -2.5, -0.25},
	{-0.5,  -2.5,  0.5},
	{ 0.25,  -2.5,  0.0},
	{ 1.5,  -2.5,  0.0}},

	{{0.0,  -1.25, -2.0},
	{ 0.0,  -1.25, -0.25},
	{-0.5,  -1.25,  0.5},
	{ 0.25,  -1.25,  0.0},
	{ 1.5,  -1.25,  0.0}},

	{{0.0, -1.25,  -2.0},
	{ 0.0,  -0.625, -0.25},
	{-0.5,  0.0,  0.5},
	{ 0.25,  0.0,  0.0},
	{ 1.5,  0.0,  0.0}}
};

GLfloat ctrlpoints11[5][5][3] =
{
	{{0.0, -1.25,  -2.0},
	{ 0.0,  -0.625, -0.25},
	{ 0.5,  0.0,  0.5},
	{-0.25,  0.0,  0.0},
	{-1.5,  0.0,  0.0}},

	{{0.0,  -1.25, -2.0},
	{ 0.0,  -1.25, -0.25},
	{ 0.5,  -1.25,  0.5},
	{-0.25,  -1.25,  0.0},
	{-1.5,  -1.25,  0.0}},

	{{0.0,  -2.5, -2.0},
	{ 0.0,  -2.5, -0.25},
	{ 0.5,  -2.5,  0.5},
	{-0.25,  -2.5,  0.0},
	{-1.5,  -2.5,  0.0}},

	{{0.0, -3.75, -2.0},
	{ 0.0, -3.75, -0.25},
	{ 0.5, -3.75,  0.5},
	{-0.25, -3.75,  0.0},
	{-1.5, -3.75,  0.0}},

	{{0.0, -4.2, -2.0},
	{ 0.0, -5.0, -0.25},
	{ 0.5, -5.0,  0.5},
	{-0.25, -5.0,  0.0},
	{-1.5, -5.0,  0.0}},
};

GLfloat ctrlpoints12[5][5][3] =
{
	{{0.0, -5.0, -2.0},
	{ 0.0, -5.0, -0.25},
	{-0.5, -5.0,  0.5},
	{ 0.25, -5.0,  0.0},
	{ 2.125, -5.0,  0.0}},

	{{0.0, -3.75, -2.0},
	{ 0.0, -3.75, -0.25},
	{-0.5, -3.75,  0.5},
	{ 0.25, -3.75,  0.0},
	{ 2.125, -3.75,  0.0}},

	{{0.0,  -2.5, -2.0},
	{ 0.0,  -2.5, -0.25},
	{-0.5,  -2.5,  0.5},
	{ 0.25,  -2.5,  0.0},
	{ 2.125,  -2.5,  0.0}},

	{{0.0,  -1.25, -1.8},
	{ 0.0,  -1.25, -0.25},
	{-0.5,  -1.25,  0.5},
	{ 0.25,  -1.25,  0.0},
	{ 2.125,  -1.25,  0.0}},

	{{0.0, -1.25,  -2.0},
	{ 0.0,  -0.625, -0.25},
	{-0.5,  0.0,  0.5},
	{ 0.25,  0.0,  0.0},
	{ 2.125,  0.0,  0.0}}
};

GLfloat ctrlpoints13[5][5][3] =
{
	{{0.0, -1.25,  -2.0},
	{ 0.0,  -0.625, -0.25},
	{ 0.5,  0.0,  0.5},
	{-0.25,  0.0,  0.0},
	{-2.125,  0.0,  0.0}},

	{{0.0,  -1.25, -2.0},
	{ 0.0,  -1.25, -0.25},
	{ 0.5,  -1.25,  0.5},
	{-0.25,  -1.25,  0.0},
	{-2.125,  -1.25,  0.0}},

	{{0.0,  -2.5, -2.0},
	{ 0.0,  -2.5, -0.25},
	{ 0.5,  -2.5,  0.5},
	{-0.25,  -2.5,  0.0},
	{-2.125,  -2.5,  0.0}},

	{{0.0, -3.75, -2.0},
	{ 0.0, -3.75, -0.25},
	{ 0.5, -3.75,  0.5},
	{-0.25, -3.75,  0.0},
	{-2.125, -3.75,  0.0}},

	{{0.0, -5.0, -2.0},
	{ 0.0, -5.0, -0.25},
	{ 0.5, -5.0,  0.5},
	{-0.25, -5.0,  0.0},
	{-2.125, -5.0,  0.0}},
};

GLfloat ctrlpoints14[5][5][3] =
{
	{{-2.0, -5.0,  0.0},
	{-1.0, -5.0,  0.0},
	{ 0.0, -5.0,  0.0},
	{ 1.0, -5.0,  0.0},
	{ 2.0, -5.0,  0.0}},

	{{-2.0, -3.75,  0.0},
	{-1.0, -3.75,  0.0},
	{ 0.0, -3.75,  0.0},
	{ 1.0, -3.75,  0.0},
	{ 2.0, -3.75,  0.0}},

	{{-2.0,  -2.5,  0.05},
	{-1.0,  -2.5,  0.05},
	{ 0.0,  -2.5,  0.05},
	{ 1.0,  -2.5,  0.05},
	{ 2.0,  -2.5,  0.05}},

	{{-2.0,  -1.25,  0.1},
	{-1.0,  -1.25,  0.1},
	{ 0.0,  -1.25,  0.1},
	{ 1.0,  -1.25,  0.1},
	{ 2.0,  -1.25,  0.1}},

	{{-2.0,  0.0,  0.1},
	{-1.0,  0.0,  0.1},
	{ 0.0,  0.0,  0.1},
	{ 1.0,  0.0,  0.1},
	{ 2.0,  0.0,  0.1}},
};

GLfloat ctrlpoints15[5][5][3] =
{
	{{2.0, -5.0,  0.0},
	{ 1.0, -5.0,  0.0},
	{ 0.0, -5.0,  0.0},
	{-1.0, -5.0,  0.0},
	{-2.0, -5.0,  0.0}},

	{{2.0, -3.75,  0.0},
	{ 1.0, -3.75,  0.0},
	{ 0.0, -3.75,  0.0},
	{-1.0, -3.75,  0.0},
	{-2.0, -3.75,  0.0}},

	{{2.0,  -2.5, -0.05},
	{ 1.0,  -2.5, -0.05},
	{ 0.0,  -2.5, -0.05},
	{-1.0,  -2.5, -0.05},
	{-2.0,  -2.5, -0.05}},

	{{2.0,  -1.25, -0.1},
	{ 1.0,  -1.25, -0.1},
	{ 0.0,  -1.25, -0.1},
	{-1.0,  -1.25, -0.1},
	{-2.0,  -1.25, -0.1}},

	{{2.0,  0.0,  -0.1},
	{1.0,  0.0,  -0.1},
	{ 0.0,  0.0, -0.1},
	{-1.0,  0.0, -0.1},
	{-2.0,  0.0, -0.1}},
};

GLfloat ctrlpoints16[5][5][3] =
{
	{{-0.6, -2.0, -0.6},
	{-0.5, -2.0, -0.5},
	{ 0.0, -2.0, -0.5},
	{ 0.5, -2.0, -0.5},
	{ 1.0, -2.0, -0.5}},

	{{-1.0, -1.5, -0.6},
	{-0.5, -1.5, -0.5},
	{ 0.0, -1.5, -0.5},
	{ 0.5, -1.5, -0.5},
	{ 1.5, -1.5, -0.5}},

	{{-1.25, -1.0, -0.6},
	{-0.5, -1.0, -0.5},
	{ 0.0, -1.0, -0.5},
	{ 0.5, -1.0, -0.5},
	{ 2.0, -1.0, -0.5}},

	{{-1.4, -0.5, -0.6},
	{-0.5, -0.75, -0.5},
	{ 0.0, -0.75, -0.5},
	{ 0.5, -0.75, -0.5},
	{ 1.0, -1.0, -0.5}},

	{{-1.8,  0.0, -0.6},
	{-0.5, -0.75, -0.5},
	{ 0.0, -0.75, -0.5},
	{ 0.5, -0.75, -0.5},
	{ 1.0, -1.0, -0.5}}
};

GLfloat ctrlpoints17[5][5][3] =
{
	{{-1.0, -1.0, -0.5},
	{-0.5, -1.0, -0.5},
	{ 0.0, -1.0, -0.5},
	{ 0.5, -1.0, -0.5},
	{ 1.0, -1.0, -0.5}},

	{{-1.75, 0.0, -0.5},
	{-1.5, 0.0, -0.5},
	{-1.25, 0.0, -0.5},
	{-1.0, 0.0, -0.5},
	{-0.75, 0.0, -0.5}},

	{{-2.5, 1.0, -0.75},
	{-2.3, 1.0, -0.75},
	{-2.1, 1.0, -0.75},
	{-1.9, 1.0, -0.75},
	{-1.7, 1.0, -0.75}},

	{{-2.5, 1.5, -0.3},
	{-2.25, 1.5, -0.0},
	{-2.0, 1.5, -0.0},
	{-1.75, 1.5, -0.0},
	{-1.5, 1.5, -0.0}},

	{{-2.5,  2.0, -0.6},
	{-1.5, 3.25, -1.5},
	{-1.5, 2.75, -1.0},
	{-1.0, 2.55, -1.0},
	{-0.5, 1.5, -0.5}}
};

GLfloat ctrlpoints18[5][5][3] =
{
	{{1.8,  0.0, -0.6},
	{ 0.5, -0.75, -0.5},
	{ 0.0, -0.75, -0.5},
	{-0.5, -0.75, -0.5},
	{-1.0, -1.0, -0.5}},

	{{1.4, -0.5, -0.6},
	{ 0.5, -0.75, -0.5},
	{ 0.0, -0.75, -0.5},
	{-0.5, -0.75, -0.5},
	{-1.0, -1.0, -0.5}},

	{{1.25, -1.0, -0.6},
	{ 0.5, -1.0, -0.5},
	{ 0.0, -1.0, -0.5},
	{-0.5, -1.0, -0.5},
	{-2.0, -1.0, -0.5}},

	{{1.0, -1.5, -0.6},
	{ 0.5, -1.5, -0.5},
	{ 0.0, -1.5, -0.5},
	{-0.5, -1.5, -0.5},
	{-1.5, -1.5, -0.5}},

	{{0.6, -2.0, -0.6},
	{ 0.5, -2.0, -0.5},
	{ 0.0, -2.0, -0.5},
	{-0.5, -2.0, -0.5},
	{-1.0, -2.0, -0.5}}
};

GLfloat ctrlpoints19[5][5][3] =
{
	{{2.5,  2.0, -0.6},
	{ 1.5, 3.25, -1.5},
	{ 1.5, 2.75, -1.0},
	{ 1.0, 2.55, -1.0},
	{ 0.5, 1.5, -0.5}},

	{{2.5, 1.5, -0.3},
	{ 2.25, 1.5, -0.0},
	{ 2.0, 1.5, -0.0},
	{ 1.75, 1.5, -0.0},
	{ 1.5, 1.5, -0.0}},

	{{2.5, 1.0, -0.75},
	{ 2.3, 1.0, -0.75},
	{ 2.1, 1.0, -0.75},
	{ 1.9, 1.0, -0.75},
	{ 1.7, 1.0, -0.75}},

	{{1.75, 0.0, -0.5},
	{ 1.5, 0.0, -0.5},
	{ 1.25, 0.0, -0.5},
	{ 1.0, 0.0, -0.5},
	{ 0.75, 0.0, -0.5}},

	{{1.0, -1.0, -0.5},
	{ 0.5, -1.0, -0.5},
	{ 0.0, -1.0, -0.5},
	{-0.5, -1.0, -0.5},
	{-1.0, -1.0, -0.5}}
};

GLfloat ctrlpoints20[5][5][3] =
{
	{{-2.9, -4.0, -3.7},
	{-2.75, -4.0, -0.5},
	{ 0.0, -4.0, -2.5},
	{ 2.75, -4.0, -0.5},
	{ 2.9, -4.0, -3.7}},

	{{-3.0, -2.0, -3.5},
	{-5.0, -2.0,  1.5},
	{ 0.0, -2.0,  -3.5},
	{ 5.0, -2.0,  1.5},
	{ 3.0, -2.0,  -3.5}},

	{{-3.0, -1.0, -3.5},
	{-5.0, -1.0,  1.0},
	{ 0.0, -1.0, -6.5},
	{ 5.0, -1.0,  1.0},
	{ 3.0, -1.0,  -3.5}},

	{{-3.75,  1.0, -3.5},
	{-5.0,  1.0,  0.5},
	{ 0.0,  1.0,  -0.5},
	{ 5.0,  1.0,  0.5},
	{ 3.75,  1.0,  -3.5}},

	{{-1.5,  2.0, -5.5},
	{-0.5,  2.0, -5.5},
	{ 0.0,  2.0, -5.5},
	{ 0.5,  2.0, -5.5},
	{ 1.5,  2.0, -5.5}}
};

GLfloat ctrlpoints21[5][5][3] =
{
	{{-1.0, -3.5, 0.0},
	{-0.5, -3.5, 0.0},
	{ 0.0, -3.5, 0.0},
	{ 0.5, -3.5, 0.0},
	{ 1.0, -3.65, 0.0}},

	{{-3.0, -0.0, 1.0},
	{-0.5, -0.0, 1.0},
	{ 0.0, -0.0, 1.0},
	{ 0.5, -0.0, 1.0},
	{ 1.0, -0.0, 1.0}},

	{{-3.5, 2.5, -0.25},
	{-0.5, 2.5, 0.5},
	{ 0.0, 2.5, 0.5},
	{ 0.5, 2.5, 1.0},
	{ 1.0, 2.5, 1.0}},

	{{-2.0, 5.0, 0.6},
	{-0.5, 5.0, 0.0},
	{ 0.0, 5.0, 0.0},
	{ 0.5, 5.0, 0.0},
	{ 1.0, 5.0, 0.0}},

	{{0.0, 5.0, -2.0},
	{0.0, 5.0, -2.0},
	{ 0.0, 5.0, -2.0},
	{ 1.0, 5.0, -2.0},
	{ 1.0, 5.0, -2.6}}
};

GLfloat ctrlpoints22[5][5][3] =
{
	{{0.0, 5.0, -2.0},
	{0.0, 5.0, -2.0},
	{ 0.0, 5.0, -2.0},
	{-1.0, 5.0, -2.0},
	{-1.0, 5.0, -2.6}},

	{{ 2.0, 5.0, 0.6},
	{ 0.5, 5.0, 0.0},
	{ 0.0, 5.0, 0.0},
	{-0.5, 5.0, 0.0},
	{-1.0, 5.0, 0.0}},

	{{ 3.5, 2.5, -0.25},
	{ 0.5, 2.5, 0.5},
	{ 0.0, 2.5, 0.5},
	{-0.5, 2.5, 1.0},
	{-1.0, 2.5, 1.0}},

	{{ 3.0, -0.0, 1.0},
	{ 0.5, -0.0, 1.0},
	{ 0.0, -0.0, 1.0},
	{-0.5, -0.0, 1.0},
	{-1.0, -0.0, 1.0}},

	{{ 1.0, -3.5, 0.0},
	{ 0.5, -3.5, 0.0},
	{ 0.0, -3.5, 0.0},
	{-0.5, -3.5, 0.0},
	{-1.0, -3.65, 0.0}},
};

// propiedades del material
GLfloat oro_ambient[] = {0.24725f, 0.1995f, 0.0745f, 1.0f};
GLfloat oro_diffuse[] = {0.75164f, 0.60648f, 0.22648f, 1.0f};
GLfloat oro_specular[] = {0.628281f, 0.555802f, 0.366065f, 1.0f};


// propiedades del material
GLfloat ruby_ambient[] = {0.1745, 0.01175, 0.01175, 0.55};
GLfloat ruby_diffuse[] = {0.61424, 0.04136, 0.04136, 0.55};
GLfloat ruby_specular[] = {0.727811, 0.626959, 0.626959, 0.55};


// angulos de rotacion
GLfloat rotx = -90.0;
GLfloat roty = -10.0;
GLfloat rotz = 180.0;


int n = 5;

// parametros de la fuente de luz
void initlights(void)
{
 // propiedades de la fuente de luz
 GLfloat ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
 GLfloat diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
 GLfloat position[] = { 0.0f, 0.0f, 1.0f, 0.0f };

 glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
 glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
 glLightfv(GL_LIGHT0, GL_POSITION, position);
 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
}


// dibuja los puntos de control de la superficie
void DrawPoints(void)
{
 int i,j;

 glPushAttrib( GL_LIGHTING_BIT );
 glDisable( GL_LIGHTING );

 // cambia el tamaño del pexels para hacerlo mas visible
 glPointSize(4.0f);

 // dibuja todos los puntos de control de la superficie
 glColor3f( 0.0, 1.0, 1.0);
 glBegin(GL_POINTS);

 for(j=0; j<n; j++)
    for (i=0; i<n; i++)
       glVertex3fv(ctrlpoints21[j][i]);
 glEnd();

 glColor3f( 0.0, 0.25, 0.5);
 glBegin(GL_LINES);

 for (j=0; j<n-1; j++)
     for (i=0; i<n-1; i++)
         {
         glVertex3fv(ctrlpoints21[j][i]);
         glVertex3fv(ctrlpoints21[j][i+1]);
         }

 for (i=0; i<n-1; i++)
     for (j=0; j<n-1; j++)
         {
         glVertex3fv(ctrlpoints21[j][i]);
         glVertex3fv(ctrlpoints21[j+1][i]);
         }
 glEnd();

 glPopAttrib();
}

// dibuja la superficie
void display(void)
{

 glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glMatrixMode( GL_MODELVIEW_MATRIX );

 glLoadIdentity();
 glTranslated(0.0, 3.0, 0.0);
 glScalef(2.0, 2.0, 2.0);
 //glRotatef(rotx, 1.0, 0.0, 0.0);
 //glRotatef(roty, 0.0, 1.0, 0.0);
 //glRotatef(rotz, 0.0, 0.0, 1.0);

  glRotatef(alpha, 1.0f, 0.0f, 0.0f);
  glRotatef(beta, 0.0f, 1.0f, 0.0f);

glPushMatrix();

	glPushMatrix();
		glTranslated(2.0, 0.0, 0.0);
		glScalef(0.5, 0.5, 0.5);

		glMaterialfv (GL_FRONT, GL_AMBIENT, oro_ambient);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, oro_diffuse);
		glMaterialfv (GL_FRONT, GL_SPECULAR, oro_specular);
		glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

		glMap2f(GL_MAP2_VERTEX_3,
		0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
		&ctrlpoints1[0][0][0]);

		glEnable(GL_MAP2_VERTEX_3);

		glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0, 10, 0, 10);

		//DrawPoints();
	glPopMatrix();

	glPushMatrix();
		glTranslated(-2.0, 0.0, 0.0);
		glScalef(0.5, 0.5, 0.5);

		glMaterialfv (GL_FRONT, GL_AMBIENT, oro_ambient);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, oro_diffuse);
		glMaterialfv (GL_FRONT, GL_SPECULAR, oro_specular);
		glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

		glMap2f(GL_MAP2_VERTEX_3,
		0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
		&ctrlpoints2[0][0][0]);

		glEnable(GL_MAP2_VERTEX_3);

		glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0, 10, 0, 10);

		//DrawPoints();
	glPopMatrix();

		glPushMatrix();
			glTranslated(0.0, 0.0, 0.0);
			glScalef(0.5, 0.5, 0.5);

			glMaterialfv (GL_FRONT, GL_AMBIENT, oro_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, oro_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, oro_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints3[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();

	glPushMatrix();
		glTranslated(3.0, 0.0, -1.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glScalef(0.5, 0.5, 0.5);

		glMaterialfv (GL_FRONT, GL_AMBIENT, oro_ambient);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, oro_diffuse);
		glMaterialfv (GL_FRONT, GL_SPECULAR, oro_specular);
		glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

		glMap2f(GL_MAP2_VERTEX_3,
		0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
		&ctrlpoints4[0][0][0]);

		glEnable(GL_MAP2_VERTEX_3);

		glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0, 10, 0, 10);

		//DrawPoints();
	glPopMatrix();

	glPushMatrix();
		glTranslated(-3.0, 0.0, -1.0);
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		glScalef(0.5, 0.5, 0.5);

		glMaterialfv (GL_FRONT, GL_AMBIENT, oro_ambient);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, oro_diffuse);
		glMaterialfv (GL_FRONT, GL_SPECULAR, oro_specular);
		glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

		glMap2f(GL_MAP2_VERTEX_3,
		0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
		&ctrlpoints5[0][0][0]);

		glEnable(GL_MAP2_VERTEX_3);

		glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0, 10, 0, 10);

		//DrawPoints();
	glPopMatrix();

		glPushMatrix();
			glTranslated(0.0, -2.0, -0.1);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			glScalef(0.5, 0.05, 0.5);

			glMaterialfv (GL_FRONT, GL_AMBIENT, oro_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, oro_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, oro_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints6[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();

	glPushMatrix();
		glTranslated(0.0, -2.4, -0.5);
		glRotatef(15.0, 1.0, 0.0, 0.0);
		glScalef(0.5, 0.9, 0.5);

		glMaterialfv (GL_FRONT, GL_AMBIENT, oro_ambient);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, oro_diffuse);
		glMaterialfv (GL_FRONT, GL_SPECULAR, oro_specular);
		glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

		glMap2f(GL_MAP2_VERTEX_3,
		0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
		&ctrlpoints7[0][0][0]);

		glEnable(GL_MAP2_VERTEX_3);

		glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0, 10, 0, 10);

		//DrawPoints();
	glPopMatrix();

	glPushMatrix();
		glRotatef(10.0, 0.0, 0.0, 1.0);
		glPushMatrix();
			glTranslated(1.5, -2.5, -0.5);
			glRotatef(15.0, 1.0, 0.0, 0.0);
			glScalef(0.5, 0.9, 0.5);

			glMaterialfv (GL_FRONT, GL_AMBIENT, oro_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, oro_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, oro_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints8[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glRotatef(-10.0, 0.0, 0.0, 1.0);
		glPushMatrix();
			glTranslated(-1.5, -2.5, -0.5);
			glRotatef(15.0, 1.0, 0.0, 0.0);
			glScalef(0.5, 0.9, 0.5);

			glMaterialfv (GL_FRONT, GL_AMBIENT, oro_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, oro_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, oro_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints9[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();
	glPopMatrix();

		glPushMatrix();
			glTranslated(-1.25, -7.0, -1.75);
			glRotatef(15.0, 1.0, 0.0, 0.0);
			glScalef(0.6, 0.2, 0.6);

			glMaterialfv (GL_FRONT, GL_AMBIENT, oro_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, oro_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, oro_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints10[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();

		glPushMatrix();
			glTranslated(1.25, -7.0, -1.75);
			glRotatef(15.0, 1.0, 0.0, 0.0);
			glScalef(0.6, 0.2, 0.6);

			glMaterialfv (GL_FRONT, GL_AMBIENT, oro_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, oro_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, oro_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints11[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();



		glPushMatrix();
			glTranslated(-1.25, -7.0, -1.75);
			glRotatef(15.0, 1.0, 0.0, 0.0);
			glScalef(0.6, 0.15, 0.6);

			glMaterialfv (GL_FRONT, GL_AMBIENT, oro_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, oro_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, oro_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints12[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();

		glPushMatrix();
			glTranslated(1.25, -7.0, -1.75);
			glRotatef(15.0, 1.0, 0.0, 0.0);
			glScalef(0.6, 0.15, 0.6);

			glMaterialfv (GL_FRONT, GL_AMBIENT, oro_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, oro_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, oro_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints13[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();

		glPushMatrix();
			glTranslated(2.25, -5.0, -2.0);
			glRotatef(-25.0, 0.0, 0.0, 1.0);
			glRotatef(90.0, 0.0, 1.0, 0.0);

			glScalef(0.5, 1.0, 0.5);

			glMaterialfv (GL_FRONT, GL_AMBIENT, oro_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, oro_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, oro_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints16[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();

		glPushMatrix();
			glTranslated(2.25, -5.0, -2.0);
			glRotatef(-25.0, 0.0, 0.0, 1.0);
			glRotatef(90.0, 0.0, 1.0, 0.0);

			glScalef(0.5, 1.0, 0.5);

			glMaterialfv (GL_FRONT, GL_AMBIENT, oro_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, oro_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, oro_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints17[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();



		glPushMatrix();
			glTranslated(-2.25, -5.0, -2.0);
			glRotatef(25.0, 0.0, 0.0, 1.0);
			glRotatef(-90.0, 0.0, 1.0, 0.0);

			glScalef(0.5, 1.0, 0.5);

			glMaterialfv (GL_FRONT, GL_AMBIENT, oro_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, oro_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, oro_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints18[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();

		glPushMatrix();
			glTranslated(-2.25, -5.0, -2.0);
			glRotatef(25.0, 0.0, 0.0, 1.0);
			glRotatef(-90.0, 0.0, 1.0, 0.0);

			glScalef(0.5, 1.0, 0.5);

			glMaterialfv (GL_FRONT, GL_AMBIENT, oro_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, oro_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, oro_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints19[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();




	glPushMatrix();
		glTranslated(0.0, 0.0, -0.3);
		glRotatef(65.0, 1.0, 0.0, 0.0);
		glPushMatrix();
			glTranslated(1.25, -5.0, 5.0);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glScalef(0.3, 0.15, 0.3);

			glMaterialfv (GL_FRONT, GL_AMBIENT, oro_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, oro_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, oro_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints14[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslated(0.0, 0.0, -0.3);
		glRotatef(65.0, 1.0, 0.0, 0.0);
		glPushMatrix();
			glTranslated(-1.25, -5.0, 5.0);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glScalef(0.3, 0.15, 0.3);

			glMaterialfv (GL_FRONT, GL_AMBIENT, oro_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, oro_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, oro_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints15[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();
	glPopMatrix();


	//RUBIE-------------------------------------------------------------------------------------------
	glPushMatrix();
	glScalef(0.95, 1.0, 1.0);
	glPushMatrix();

		glPushMatrix();
			glTranslated(-1.25, -7.0, -1.8);
			glRotatef(15.0, 1.0, 0.0, 0.0);
			glScalef(0.6, 0.3, 0.85);

			glMaterialfv (GL_FRONT, GL_AMBIENT, ruby_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, ruby_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, ruby_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints12[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();

		glPushMatrix();
			glTranslated(1.25, -7.0, -1.8);
			glRotatef(15.0, 1.0, 0.0, 0.0);
			glScalef(0.6, 0.3, 0.85);

			glMaterialfv (GL_FRONT, GL_AMBIENT, ruby_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, ruby_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, ruby_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints13[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();
	glPopMatrix();
	glPopMatrix();

		glPushMatrix();
			glTranslated(0.0, 2.5, 1.3);
			glScalef(0.98, 1.0, 0.7);

			glMaterialfv (GL_FRONT, GL_AMBIENT, ruby_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, ruby_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, ruby_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints20[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();

	glPushMatrix();
		glTranslated(-0.1, -0.15, -0.3);
		glRotatef(65.0, 1.0, 0.0, 0.0);
		glPushMatrix();
			glTranslated(1.25, -5.0, 5.0);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glScalef(0.3, 0.3, 0.3);

			glMaterialfv (GL_FRONT, GL_AMBIENT, ruby_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, ruby_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, ruby_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints14[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslated(0.1, -0.15, -0.3);
		glRotatef(65.0, 1.0, 0.0, 0.0);
		glPushMatrix();
			glTranslated(-1.25, -5.0, 5.0);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glScalef(0.3, 0.3, 0.3);

			glMaterialfv (GL_FRONT, GL_AMBIENT, ruby_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, ruby_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, ruby_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints15[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslated(-0.1, 0.8, -0.7);
		glRotatef(65.0, 1.0, 0.0, 0.0);
		glPushMatrix();
			glTranslated(1.25, -5.0, 5.0);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glScalef(0.3, 0.31, 0.3);

			glMaterialfv (GL_FRONT, GL_AMBIENT, ruby_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, ruby_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, ruby_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints14[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslated(0.1, 0.8, -0.7);
		glRotatef(65.0, 1.0, 0.0, 0.0);
		glPushMatrix();
			glTranslated(-1.25, -5.0, 5.0);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glScalef(0.3, 0.31, 0.3);

			glMaterialfv (GL_FRONT, GL_AMBIENT, ruby_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, ruby_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, ruby_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints15[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();
	glPopMatrix();


		glPushMatrix();
			glTranslated(2.25, -2.0, -3.0);
			glRotatef(12.0, 1.0, 0.0, 0.0);
			glRotatef(-15.0, 0.0, 0.0, 1.0);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glScalef(0.9, 1.2,1.0);

			glMaterialfv (GL_FRONT, GL_AMBIENT, ruby_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, ruby_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, ruby_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints21[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();

		glPushMatrix();
			glTranslated(-2.25, -2.0, -3.0);
			glRotatef(12.0, 1.0, 0.0, 0.0);
			glRotatef(15.0, 0.0, 0.0, 1.0);
			glRotatef(-90.0, 0.0, 1.0, 0.0);
			glScalef(0.9, 1.2,1.0);

			glMaterialfv (GL_FRONT, GL_AMBIENT, ruby_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, ruby_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, ruby_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, 12.8f);

			glMap2f(GL_MAP2_VERTEX_3,
			0.0, 1.0, 3.0, 5.0, 0.0, 1.0, 15.0, 5.0,
			&ctrlpoints22[0][0][0]);

			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 10, 0, 10);

			//DrawPoints();
		glPopMatrix();

glPopMatrix();

 glFlush();
 glutSwapBuffers();
}

void init(void)
{
 //glClearColor (0.0, 0.3, 0.7, 1.0);
 glEnable (GL_DEPTH_TEST);
 glEnable(GL_AUTO_NORMAL);
 glEnable(GL_NORMALIZE);
 //glDepthFunc(GL_LEQUAL);
 initlights();
}

void onMouse(int button, int state, int x, int y)
{
	if ( (button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) )
	{
		px0 = x;  py0 = y;
	}
}

void onMotion(int x, int y)
{
	alpha = (alpha + (y - py0));
	beta = (beta + (x - px0));
	px0 = x;  py0 = y;
	glutPostRedisplay();
}

void Key(unsigned char Tecla,int x, int y)
{
    switch(Tecla){
	 case 27:  exit (0);
		       break;
	}
}

void ChangeSize(int w, int h)
{
	if(h == 0)
		h = 5;

    glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-15.0f, 15.0f, -15.0f, 15.0f, -20.0f, 20.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 glutInitWindowSize (800, 600);
 glutInitWindowPosition (100, 100);
 glutCreateWindow ("*** O V N I ***");
 init ();
 glutReshapeFunc(ChangeSize);
 glutKeyboardFunc(Key);
 glutDisplayFunc(display);
 glutMouseFunc(onMouse);
 glutMotionFunc(onMotion);
 glutMainLoop();
 return 0;
}


