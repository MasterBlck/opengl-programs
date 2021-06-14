#include <windows.h>
#include <GL/glut.h>

GLUquadricObj *q;
GLfloat eyeX=2.3, eyeY=1.3, eyeZ=2.0;

GLfloat light_amb[] = {0.4f, 0.5f, 0.6f, 1.0f};
GLfloat light_dif[] = {0.4f, 0.5f, 0.6f, 1.0f};
GLfloat light_spe[] = {0.4f, 0.5f, 0.6f, 1.0f};
GLfloat light_pos[] = {2.0f, 6.0f, 3.0f, 1.0f};

GLfloat light_red_amb[] = {0.9f, 0.1f, 0.1f, 1.0f};
GLfloat light_red_dif[] = {0.8f, 0.1f, 0.1f, 1.0f};
GLfloat light_red_pos[] = {0.0f, 7.0f, 0.0f, 1.0f};

GLfloat gold_Ka[4] = { 0.64725f, 0.5995f, 0.0745f, 1.0f };
GLfloat gold_Kd[4] = { 0.75164f, 0.60648f, 0.22648f, 1.0f };
GLfloat gold_Ks[4] = { 0.628281f, 0.555802f, 0.366065f, 1.0f };
GLfloat gold_Ke = 51.2;

GLfloat ruby_Ka[4]  = { 0.1745f, 0.01175f, 0.01175f, 0.55f };
GLfloat ruby_Kd[4]  = { 0.61424f, 0.04136f, 0.04136f, 0.55f };
GLfloat ruby_Ks[4]  = { 0.727811f, 0.626959f, 0.626959f, 0.55f };
GLfloat ruby_Ke = 76.8;

GLfloat silver_Ka[4]  = { 0.23125f, 0.23125f, 0.23125f, 1.0f };
GLfloat silver_Kd[4]  = { 0.2775f, 0.2775f, 0.2775f, 1.0f };
GLfloat silver_Ks[4]  = { 0.773911f, 0.773911f, 0.773911f, 1.0f };
GLfloat silver_Ke = 51.2;

GLfloat emerald_Ka[4]  = { 0.0215f, 0.1745f, 0.0215f, 0.55f };
GLfloat emerald_Kd[4]  = { 0.07568f, 0.61424f, 0.07568f, 0.55f };
GLfloat emerald_Ks[4]  = { 0.633f, 0.727811f, 0.633f, 0.55f };
GLfloat emerald_Ke = 76.8;

GLfloat bronze_Ka[4]  = { 0.2125f, 0.1275f, 0.054f, 1.0f };
GLfloat bronze_Kd[4]  = { 0.714f, 0.4284f, 0.18144f, 1.0f };
GLfloat bronze_Ks[4]  = { 0.393548f, 0.271906f, 0.166721f, 1.0f };
GLfloat bronze_Ke = 25.6;

GLfloat pearl_Ka[4]  = { 0.95f, 0.90725f, 0.90725f, 0.922f };
GLfloat pearl_Kd[4]  = { 1.0f, 0.829f, 0.829f, 0.922f };
GLfloat pearl_Ks[4]  = { 0.996648f, 0.996648f, 0.996648f, 0.922f };
GLfloat pearl_Ke = 11.264;

GLfloat window_Ka[4] = { 0.02125f, 0.2136f, 0.626959f, 0.55f };
GLfloat window_Kd[4] = { 0.1125f, 0.3136f, 0.7959f, 0.55f };
GLfloat window_Ks[4] = { 0.225f, 0.4272f, 0.87918f, 0.55f };
GLfloat window_Ke = 51.2;

void init(void)
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_dif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_spe);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH);
    glFrontFace(GL_CCW);
	glEnable(GL_NORMALIZE);
    glClearColor(0.1f, 0.2f, 0.4f, 1.0f);
	glEnableClientState(GL_VERTEX_ARRAY);

}

void drawCube(void)
{
	GLfloat squareFront[] = {-1.0, 1.0, 1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, 1.0};
	GLfloat squareBack[] = {1.0, 1.0, -1.0, 1.0, -1.0, -1.0, -1.0, 1.0, -1.0, -1.0, -1.0, -1.0};
	GLfloat squareRight[] = {1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0, 1.0, -1.0, 1.0, -1.0, -1.0};
	GLfloat squareLeft[] = {-1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, -1.0, -1.0, 1.0};
	GLfloat squareBottom[] = {-1.0, -1.0, 1.0, -1.0, -1.0, -1.0, 1.0, -1.0, 1.0, 1.0, -1.0, -1.0};
	GLfloat squareTop[] = {1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0, 1.0, 1.0, -1.0, 1.0, -1.0};

	glVertexPointer(3, GL_FLOAT, 0, squareFront);
	glNormal3f(0.0f ,0.0f ,1.0f);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glVertexPointer(3, GL_FLOAT, 0, squareBack);
	glNormal3f(0.0f ,0.0f ,-1.0f);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glVertexPointer(3, GL_FLOAT, 0, squareRight);
	glNormal3f(1.0f ,0.0f ,0.0f);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glVertexPointer(3, GL_FLOAT, 0, squareLeft);
	glNormal3f(-1.0f ,0.0f ,0.0f);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glVertexPointer(3, GL_FLOAT, 0, squareBottom);
	glNormal3f(0.0f ,-1.0f ,0.0f);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glVertexPointer(3, GL_FLOAT, 0, squareTop);
	glNormal3f(0.0f ,1.0f ,0.0f);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

}

void drawBuild(void)
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, pearl_Ka);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, pearl_Kd);
	glMaterialfv(GL_FRONT, GL_SPECULAR, pearl_Ks);
	glMaterialf(GL_FRONT, GL_SHININESS, pearl_Ke);

	glPushMatrix();
		glScalef(0.5, 1.0, 0.05);
		drawCube();
	glPopMatrix();
	glPushMatrix();
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		glScalef(0.5, 1.0, 0.05);
		glTranslatef(-0.97, 0.0, 9.0);
		drawCube();
	glPopMatrix();
	glPushMatrix();
		glScalef(0.5, 1.0, 0.05);
		glTranslatef(0.0, 0.0, -19.0);
		drawCube();
	glPopMatrix();
	glPushMatrix();
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glScalef(0.5, 1.0, 0.05);
		glTranslatef(0.97, 0.0, 9.0);
		drawCube();
	glPopMatrix();
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glScalef(0.5, 0.5, 0.05);
		glTranslatef(0.0, -1.0, -18.0);
		drawCube();
	glPopMatrix();
	glPushMatrix();
		glScalef(0.3, 0.25, 0.3);
		glTranslatef(0.0, -3.0, -0.4);
		drawCube();
	glPopMatrix();

	glPushMatrix();
		glScalef(1.7, 0.05, 1.7);
		glTranslatef(0.2, -19.5, -0.5);
		drawCube();
	glPopMatrix();
	glPushMatrix();
		glScalef(0.65, 0.05, 1.7);
		glTranslatef(-5.0, -19.5, -0.5);
		drawCube();
	glPopMatrix();
	glPushMatrix();
		glScalef(1.7, 0.05, 0.65);
		glTranslatef(0.2, -19.5, 5.0);
		drawCube();
	glPopMatrix();
}

void drawWindows(void)
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, window_Ka);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, window_Kd);
	glMaterialfv(GL_FRONT, GL_SPECULAR, window_Ks);
	glMaterialf(GL_FRONT, GL_SHININESS, window_Ke);

	for(float j = 0.0; j < 18.0; j+=3.0)
	{
		for(float k = 0.0; k < 9.0; k+=3.0)
		{
			glPushMatrix();
				glScalef(0.565, 0.1, 0.1);
				glTranslatef(0.0, 8.3-j, -8.0+k);
				drawCube();
			glPopMatrix();
		}
	}

	for(float j = 0.0; j < 15.0; j+=3.0)
	{
		for(float k = 0.0; k < 9; k+=3.0)
		{
			glPushMatrix();
				glScalef(0.1, 0.1, 0.565);
				glTranslatef(-3.0+k, 8.3-j, -0.82);
				drawCube();
			glPopMatrix();
		}
	}
}

void drawFloor(void)
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, silver_Ka);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, silver_Kd);
	glMaterialfv(GL_FRONT, GL_SPECULAR, silver_Ks);
	glMaterialf(GL_FRONT, GL_SHININESS, silver_Ke);

	glPushMatrix();
		glScalef(4.0, 0.05, 4.0);
		glTranslatef(0.0, -21.0, 0.0);
		drawCube();
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_AMBIENT, gold_Ka);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, gold_Kd);
	glMaterialfv(GL_FRONT, GL_SPECULAR, gold_Ks);
	glMaterialf(GL_FRONT, GL_SHININESS, gold_Ke);

	for (int i = 0; i < 8; i++)
	{
		glPushMatrix();
			glScalef(0.05, 0.01, 0.25);
			glTranslatef(-50.0+(3*i), -100.0, 2.0);
			drawCube();
		glPopMatrix();
		glPushMatrix();
			glScalef(0.05, 0.01, 0.25);
			glTranslatef(-50.0+(3*i), -100.0, -8.8);
			drawCube();
		glPopMatrix();
		glPushMatrix();
			glScalef(0.25, 0.01, 0.05);
			glTranslatef(-4.2, -100.0, 19.0+(4*i));
			drawCube();
		glPopMatrix();
		glPushMatrix();
			glScalef(0.25, 0.01, 0.05);
			glTranslatef(7.0, -100.0, 19.0+(4*i));
			drawCube();
		glPopMatrix();
	}
}

void drawCruz(void)
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, ruby_Ka);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, ruby_Kd);
	glMaterialfv(GL_FRONT, GL_SPECULAR, ruby_Ks);
	glMaterialf(GL_FRONT, GL_SHININESS, ruby_Ke);

	glPushMatrix();
		glScalef(0.1, 0.01, 0.25);
		glTranslatef(0.0, 95.0, -2.0);
		drawCube();
	glPopMatrix();
	glPushMatrix();
		glScalef(0.25, 0.01, 0.1);
		glTranslatef(0.0, 95.0, -5.0);
		drawCube();
	glPopMatrix();

}

void drawTroncos(void)
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, bronze_Ka);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, bronze_Kd);
	glMaterialfv(GL_FRONT, GL_SPECULAR, bronze_Ks);
	glMaterialf(GL_FRONT, GL_SHININESS, bronze_Ke);

	for (float j = 0; j < 1.6; j+=0.5)
	{
		glPushMatrix();
			q = gluNewQuadric ( );
			gluQuadricDrawStyle ( q, GLU_FILL   );
			gluQuadricNormals   ( q, GLU_SMOOTH );
			glRotatef(-90.0, 1.0, 0.0, 0.0);
			glTranslatef(1.3, j, -0.95);
			gluCylinder(q, 0.115f, 0.065f, 0.34f, 200, 100);
		glPopMatrix();
	}
}

void drawArbol(void)
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, emerald_Ka);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, emerald_Kd);
	glMaterialfv(GL_FRONT, GL_SPECULAR, emerald_Ks);
	glMaterialf(GL_FRONT, GL_SHININESS, emerald_Ke);

	for(float j = -1.5; j < 0.1; j+= 0.5)
	{
		glPushMatrix();
			glTranslatef(1.3, -0.5, j);
			glutSolidSphere(0.17, 100, 100);
		glPopMatrix();
	}
}


void spinDisplay(void)
{
	eyeX = (eyeX - 0.0025f);
	if (eyeX <= -2.3) eyeX = 2.3;

	glutPostRedisplay();
}

void displaySolid(void)
{
	// fijar la camara
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double winHt = 2.0;
	glOrtho(-winHt*64/48.0, winHt*64/48.0, -winHt, winHt, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, 0.0, 0.25, 0.0, 0.0, 1.0, 0.0);

	// Dibujar
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	drawBuild();
	drawFloor();
	drawCruz();
	drawArbol();
	drawTroncos();
	drawWindows();
	glFlush();
}

main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB| GLUT_DEPTH);
 glutInitWindowSize(640, 480);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Escena 3D");
 glutDisplayFunc(displaySolid);
 init();
 glutIdleFunc(spinDisplay);
 glViewport(0, 0, 640, 480);
 glutMainLoop();
}

