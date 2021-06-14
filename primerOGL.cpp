#include <iostream>
#include <GL/glx.h>    //Siempre se requiere (OpenGL)
#include <GL/freeglut.h>
#include <GL/gl.h>

void myInit(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);   //Selecciona el color de fondo
  glColor3f(1.0f, 0.0f, 0.0f);        //El color a dibujar
  glPointSize(4.0);                   //Tamaño de los puntos
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void)
{
  glClear(GL_COLOR_BUFFER_BIT);      //Limpia la pantalla
  glBegin(GL_POINTS);
    glVertex2i(100, 50);            //Dibujamos 3 puntos
    glVertex2i(100, 130);
    glVertex2i(120, 130);
  glEnd();
  glFlush();                        //Envía toda la salida a pantalla
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);                            //Inicializa toolkit
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);      //Selecciona modo de pantalla
  glutInitWindowSize(640, 480);                     //Tamaño de ventana
  glutInitWindowPosition(100,150);                  //Posición de ventana
  glutCreateWindow("Mi primer ejemplo con OpenGL"); //Crear ventana: Hasta que no
  // se llama a la función glutMainLoop no se muestra la ventana creada

  glutDisplayFunc(myDisplay);                       //Registra función de redibujar
  myInit();
  glutMainLoop();                                   //Bucle continuo
  return 0;
}

