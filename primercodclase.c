#include <stdio.h>
#include <GL/freeglut.h>
#include <GL/glx.h>
#include <GL/gl.h>

void dibujar();

int main(int argc, char *argv[]){

	glutInit(&argc, argv);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(10,10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Bad King 1.0");
	glutDisplayFunc(dibujar);
	glutMainLoop();

	return 0;
}

void dibujar(){
	glClear( GL_COLOR_BUFFER_BIT );
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1, -1, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 1.0, 0.0);
	glEnd();
	glutSwapBuffers();
}
