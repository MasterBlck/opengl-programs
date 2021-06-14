#include <windows.h>
#include <gl/glut.h>

float aspect = 1.0f;

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 5.0f);
    //gluPerspective(20.0f, aspect, 1.0f, 5.0f);
    gluPerspective(20.0f, aspect, 1.0f, 10.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    gluLookAt(0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glutWireTeapot(0.5);

    glFlush();

    glutSwapBuffers();
}
void onSize(int sx, int sy)
{
    glViewport(0, 0, sx, sy);
    aspect = (float) sx / (float) sy;
}

int main(void)
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Objetos GLUT y Proyecciones");
    glutDisplayFunc(display);
    glutReshapeFunc(onSize);

    init();

    glutMainLoop();

    return 0;
}

