// Algoritmo de Bresenham (líneas)
#include <windows.h>
#include <GL/glut.h>

// drawline
// dibuja una línea usando el algoritmo de Bresenham

// Se asume que:
//     (1) bx >= ax
//     (2) Pendiente de la línea en [0,1].

void drawline(const int ax, const int ay, const int bx, const int by)
{
    const int w = bx - ax;  // ancho (delta x)
    const int h = by - ay;  // alto  (delta y)

    const int rightstep = 2 * h;       // "f" aumenta para mover rt
    const int diagstep = 2 * (h - w);  // "f" aumenta para mover rt y arriba

    int x;                  // x coord de pt actual
    int y = ay;             // y coord de pt actual
    int f = 2 * h - w;      // "f": valor de prueba de Bresenham

    glBegin(GL_POINTS);

    for (x = ax; x <= bx; ++x)  // Ciclo principal de Bresenham
    {
        glVertex2i(x, y);       // Plot del punto
        if (f < 0)
        {
            f += rightstep;     // a la derecha
        }
        else
        {
            ++y;
            f += diagstep;      // derecha y arriba
        }
    }

    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    drawline(5,15, 90,95);
    glFlush();
}

void init()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 100, 0, 100, -1.0, 1.0);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Algoritmo de Bresenham: líneas");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


