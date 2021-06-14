#include <windows.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

int posicionx[2];				//arreglo para coordenadas x
int posiciony[2];				//arreglo para coordenadas y
int contador=0;					//contador para salvar coordenada


void Save(int x,int y)			//funcion para salvar coordenadas
{
	posicionx[contador]=x;
	posiciony[contador]=y;
	contador++;

}

void OnMouseClick(int button,int state,int x,int y)
{
	if(state == GLUT_DOWN)
	{
		if ((button == GLUT_LEFT_BUTTON) )
		{
			if(contador==2)				//se ya se capturaron 2 coordenada, lo volvemos a inicializar
				contador=0;				//para que acepte otras 2 coordenadas

			Save(x,y);					//guardamos coordenadas capturadas
		}
		cout <<"coordenadas:(" <<x << "," << y <<")" ;//<< endl;
	}

	glutPostRedisplay();
}

void Pinta()
{
	glColor3f(0.5,0.5,1);

	glBegin(GL_POINTS);
        for(int i=0;i<contador;i++)
            glVertex2i(posicionx[i],posiciony[i]);
	glEnd();
}

void drawline(const int x, const int y, const int x2, const int y2)
{

	int ax=x;
	int ay=y;
	int bx=x2;
	int by=y2;

	if(y>y2)			//ordenamos coordenadas inicial y final
	{
		ax=x2;
		ay=y2;
		bx=x;
		by=y;
	}

	glColor3f(1.0, 0.0, 0.0);

	if(ay==by)						//imprime linea horizontal
	{
		cout<<"horizontal"<<endl;
		int a=ax;
		int b=bx;

		if(bx<ax)
		{
			a=bx;
			b=ax;
		}

		glBegin(GL_POINTS);
            for(a;a<=b;a++)
                glVertex2i(a,ay);
		glEnd();
	}

	if(ax==bx)						//imprime linea Vertical
	{
		cout<<"vertical"<<endl;
		int a=ay;
		int b=by;

		if(by<ay)
		{
			a=by;
			b=ay;
		}

		glBegin(GL_POINTS);
            for(a;a<=b;a++)
                glVertex2i(ax,a);
		glEnd();
	}

    //para saber que linea se va a imprimir, calculamos la pendiente

	int m=-1;					//variable para la pendiente
	int r=-1;					//variable para residuo de division

	if((bx-ax)!=0)				//evitamos division con cero
	{
		m=(by-ay)/(bx-ax);		//calculamos pendiente (entero)
		r=(by-ay)%(bx-ax);		//obtenemos residuo
	}

	cout<<"m= "<<m<<endl;
	cout<<"r= "<<r<<endl;

	if(((m==0) && (bx-ax >=1) && (by-ay >= 1)) || (m>=1 && r==0) )			//para imprimir linea entre 0 y 45 grados
	{
		cout<<"0 - 45 grados"<<endl;
		const int w = bx - ax;				// ancho (horizontal)
		const int h = by - ay;				// alto (vertical)
		const int rightstep = 2 * h;		// "f" aumenta para mover rt
		const int diagstep = 2 * (h - w);	// "f" aumenta para mover rt y arriba
		int x;								// x coord de pt actual
		int y = ay;								// y coord de pt actual
		int f = 2 * h - w;					// "f": valor de prueba de Bresenham

		glBegin(GL_POINTS);
            for (x = ax; x <= bx; ++x)  // Ciclo principal de Bresenham
            {
                glVertex2i(x, y);   // Plot del punto
                if (f < 0)
                {
                    f += rightstep;     // a la derecha
                }
                else
                {
                    ++y;
                    f += diagstep;  // derecha y arriba
                }
            }
		glEnd();
	}
	if((m>=1) && (r>=0))								//para imprimir linea entre 45 y 90 grados
	{
		cout<<" 45 -90 grados"<<endl;
		const int w = bx - ax;				// ancho (horizontal)
		const int h = by - ay;				// alto (vertical)
		const int rightstep = 2 * w;		// "f" aumenta para mover rt (cambia w por h ya que el ciclo se va a hacer con y en vez de x)
		const int diagstep = 2 * (w - h);	// "f" aumenta para mover rt y arriba
		int y;								// x coord de pt actual
		int x = ax;							// y coord de pt actual
		int f = 2 * w - h;					// "f": valor de prueba de Bresenham

		glBegin(GL_POINTS);
            for (y = ay; y <= by; ++y)  // Ciclo principal de Bresenham
            {

                glVertex2i(x, y);   // Plot del punto
                if (f < 0)
                {
                    f += rightstep;     // a la derecha
                }
                else
                {
                    ++x;
                    f += diagstep;  // derecha y arriba
                }
            }
		glEnd();
	}

	if(((m==0) && (bx-ax <1 || by-ay < 1)) || (m==0 && r>=0) )		//para imprimir linea entre 90 y 135 grados
	{
		cout<<" 90 - 135 grados negativo"<<endl;

		//utilizamos la funcion para linea entre 0 y 45 grados
		//reflejamos los puntos de x de modo que quede una linea entre 0 y 45 grados
		//obtenemos las y's y las imprimimos con x hacia atras
		int bx2=bx;
			bx2+=2*(ax-bx);				//coordenada final reflejada
		int t=0;

		const int w = bx2 - ax;					// ancho (horizontal)
		const int h = by - ay;					// alto (vertical)
		const int rightstep = 2 * h;			// "f" aumenta para mover rt
		const int diagstep = 2 * (h - w);		// "f" aumenta para mover rt y arriba
		int x;									// x coord de pt actual
		int y = ay;								// y coord de pt actual
		int f = 2 * h - w;						// "f": valor de prueba de Bresenham

		glBegin(GL_POINTS);
            for (x = ax; x <= bx2; ++x)				// Ciclo principal de Bresenham
            {
                glVertex2i(ax-t,y );				// Plot del punto, restamos 1 a ax, cuando x incrementa, para que los
                t++;								//puntos se en el angulo entre 90 y 135
                if (f < 0)
                {
                    f += rightstep;					// a la derecha
                }
                else
                {
                    ++y;
                    f += diagstep;					// derecha y arriba
                }
            }
		glEnd();

	}
	if((m<=-1) && (r>=0))						//para imprimir linea entre 135 y 180 grados
	{
		cout<<" + 45 grados negativo"<<endl;

		int bx2=bx;
			bx2+=2*(ax-bx);				//reflejamos la coordenada final
										//para que quede una linea entre 45 y 90 grados

		const int w = bx2 - ax;				// ancho (horizontal)
		const int h = by - ay;				// alto (vertical)
		const int rightstep = 2 * w;		// "f" aumenta para mover rt
		const int diagstep = 2 * (w - h);	// "f" aumenta para mover rt y arriba
		int y;								// x coord de pt actual
		int x = ax;							// y coord de pt actual
		int f = 2 * w - h;					// "f": valor de prueba de Bresenham


		glBegin(GL_POINTS);
            //se hacen los calculo igual que en la linea entre 45 y 90 grados
            for (y = ay; y <= by; ++y)  // Ciclo principal de Bresenham
            {									//cuando se incrementa x, en vez de imprimirlo en la coordenada
                                                //(x,y), calculamos el punto que refleja a x y en ese lo imprimimos
                glVertex2i(ax - (x-ax), y);     // Plot del punto

                if (f < 0)
                {
                    f += rightstep;     // a la derecha
                }
                else
                {
                    ++x;
                    f += diagstep;  // derecha y arriba
                }
            }
		glEnd();
	}




}

void OnDraw()
{
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	if(contador==2)					//verificamos que ya se tengan las dos coordenadas
	{								//para imprimir la linea
		drawline(posicionx[0],posiciony[0],posicionx[1],posiciony[1]);
	}

	//***** glFlush() VS glutSwapBuffers(); ******

	glFlush();

	/*
	Different GL implementations buffer commands in several different locations, including network buffers and
	the graphics accelerator itself. glFlush empties all of these buffers, causing all issued commands to be
	executed as quickly as they are accepted by the actual rendering engine.

	Errors:
	GL_INVALID_OPERATION is generated if glFlush is executed between the execution of glBegin and the corresponding
	execution of glEnd.

			https://www.opengl.org/sdk/docs/man2/xhtml/glFlush.xml
	*/

	Pinta();

	glutSwapBuffers();

	/*
	Performs a buffer swap on the layer in use for the current window. Specifically, glutSwapBuffers promotes the
	contents of the back buffer of the layer in use of the current window to become the contents of the front buffer.

	An implicit glFlush() is done by glutSwapBuffers before it returns. Subsequent OpenGL commands can be issued
	immediately after calling glutSwapBuffers, but are not executed until the buffer exchange is completed.

	If the layer in use is not double buffered, glutSwapBuffers has no effect.

                        https://www.opengl.org/resources/libraries/glut/spec3/node21.html
	*/

}

void Init()
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
    glPointSize(5.0); // Dibuja Puntos "grandes" (cuadros 5x5)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 100, 0, 100, -1.0, 1.0);
	// enable depth testing
	glEnable(GL_DEPTH_TEST);

	// make the points a little bigger for our control points
    //	glPointSize(10);
}

void OnReshape(int w, int h)
{
	// prevent division by zero when minimised
	if (h==0)
		h=1;

	// set the drawable region of the window
	glViewport(0,0,w,h);

	// set up the projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// just use a perspective projection
	glOrtho(0,w,h,0,-100,100);

	// go back to modelview matrix so we can move the objects about
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27:  // Tecla Escape
				exit(0);
				break;
		default:
				break;
	}
}

int main(int argc,char** argv) {

	glutInit(&argc,argv);

    //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowSize(640,480);
	glutCreateWindow("Bresenham-Line");
	glutFullScreen();
	glutDisplayFunc(OnDraw);
	glutReshapeFunc(OnReshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(OnMouseClick);
	Init();
	glutMainLoop();

	return 0;
}
