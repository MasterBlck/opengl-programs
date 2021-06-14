#include <GL/glx.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

void renderFunction();

int main(int argc, char* argv[]) { 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE); 
	glutInitWindowSize(500,500); 
	glutInitWindowPosition(100,100); 
	glutCreateWindow("OpenGL - First window demo"); 
	glutDisplayFunc(renderFunction); 
	glutMainLoop(); 
	return 0; 
}


void renderFunction() { 
        glClearColor(0.0, 0.0, 0.0, 0.0); 
        glClear(GL_COLOR_BUFFER_BIT); 
        glColor3f(1.0, 1.0, 1.0); 
        glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 
        glBegin(GL_POLYGON); 
        glVertex2f(-0.5, -0.5); 
        glVertex2f(-0.5, 0.5); 
        glVertex2f(0.5, 0.5); 
        glVertex2f(0.5, -0.5); 
        glEnd(); glFlush(); 
} 
