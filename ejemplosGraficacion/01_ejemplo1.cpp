#include <windows.h>
#include <GL/glut.h>
//#include <GL/gl.h>
//#include <stdlib.h>
//#include <iostream>


void init(void)
{

	glClearColor(1.0, 1.0, 1.0, 0.0);       // DEFINE COLOR DE FONDO
	glColor3f(0.0f, 0.0f, 1.0f);            // DEFINE COLOR DE PUNTOS
	glPointSize(8.0);                       // DEFINE TAMAÑO DE PUNTO
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);     // DEFINE VISTA (ORTOGONAL 2D)
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);   // LIMPIA PANTALLA

	glBegin(GL_POINTS);             // DIBUJA 3 PUNTOS
	  glVertex2i(100, 50);
	  glVertex2i(100, 130);
	  glVertex2i(150, 130);
    glEnd();

	glFlush();                      // ENVIA TODA LA SALIDA A LA PANTALLA
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(200, 100);

    glutCreateWindow("Mi primer ejemplo");
    glutDisplayFunc(display);

    init();

    glutMainLoop();
}

