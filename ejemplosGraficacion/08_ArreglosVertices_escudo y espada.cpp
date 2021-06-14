//JUAN CARLOS CONDE RAMIREZ		-	200522404
//	TOPICOS SELECTOS II			-	PRACTICA 1
#include <windows.h>
#include <GL/glut.h>

	float alpha, beta;
	int x0, y0;
	int w1, w2;

	//Menu de OPCIONES a elegir
	typedef enum{L1,L2,L3,L4,S1,S2}opcionMenu;

	//Matriz de COLORES
	float colores[9][3]=
	{
		{0.0,0.0,0.0}, //0 negro
		{1.0,0.0,0.0}, //1 rojo
		{0.0,1.0,0.0}, //2 verde
		{1.0,1.0,0.0}, //3 amarillo
		{0.0,0.5,1.0}, //4 azul
		{1.0,0.0,1.0}, //5 magenta
		{0.0,1.0,1.0}, //6 cian
		{1.0,1.0,1.0}, //7 blanco
		{0.9,0.9,0.9}  //8 gris
	};

	//MATERIALES
	void plasticoRojo();
	void plasticoNegro();
	void plataBrillante();
	void plata();
	void cobre();
	void brass();
	void turqueza();
	void obsidianaRoja();

	GLfloat vtx[][9]=
	{
		{ 0.0, 1.5,  1.0,  -1.0, 0.0,  1.0,   1.0, 0.0,  1.0},//0:Triangulo 1
		{ 0.0, 1.5, -1.0,   1.0, 0.0, -1.0,  -1.0, 0.0, -1.0},//1:Triangulo 2
		{ 1.0, 0.0,  1.0,   1.0, 0.0, -1.0,   0.0, 1.5, -1.0},//2:Cuadrado 1
		{ 1.0, 0.0,  1.0,   0.0, 1.5, -1.0,   0.0, 1.5,  1.0},//3:
		{-1.0, 0.0, -1.0,  -1.0, 0.0,  1.0,   0.0, 1.5,  1.0},//4:Cuadrado 2
		{-1.0, 0.0, -1.0,   0.0, 1.5,  1.0,   0.0, 1.5, -1.0},//5:
		{ 1.0, 0.0,  1.0,  -1.0, 0.0,  1.0,   1.0, 0.0, -1.0},//6:Cuadrado 3
		{-1.0, 0.0,  1.0,  -1.0, 0.0, -1.0,   1.0, 0.0, -1.0} //7:
	};

class Poligono
{

	public:
		Poligono(){glEnableClientState (GL_VERTEX_ARRAY);};

		void definePoligono(int n);
};

void Poligono::definePoligono(int n)
{
	glVertexPointer(3, GL_FLOAT, 0, vtx[n]);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Figura(void)
{
	Poligono p;

	glPushMatrix();
		cobre();//plataBrillante();
			p.definePoligono(0);

		//cobre();
			p.definePoligono(1);

		//turqueza();
			p.definePoligono(2);
			p.definePoligono(3);

		//brass();
			p.definePoligono(4);
			p.definePoligono(5);

		//obsidianaRoja();
			p.definePoligono(6);
			p.definePoligono(7);
	glPopMatrix();
}

void espada(void)
{
	glPushMatrix();
		glTranslatef(0.0, -1.0, 0.0);
		glScalef(0.25, 3.0, 0.05);
		Figura();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, -1.0, 0.0);
		glRotatef(180.0, 0.0, 0.0, 1.0);
		glScalef(0.75, 0.25, 0.25);
		Figura();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, -1.75, 0.0);
		glScalef(0.15, 0.5, 0.15);
		Figura();
	glPopMatrix();
}

void escudo(void)
{
	glPushMatrix();
		glTranslatef(0.0, -0.5, 0.0);
		glScalef(1.5, 1.5, 0.15);
		Figura();
	glPopMatrix();

	glPushMatrix();
		glRotatef(180.0, 0.0, 0.0, 1.0);
		glTranslatef(0.0, -0.5, 0.0);
		glScalef(1.5, 1.5, 0.15);
		Figura();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.5, 0.0, -0.15);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glRotatef(270.0, 0.0, 0.0, 1.0);
		glScalef(0.5, 0.25, 0.1);
		Figura();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.5, 0.0, -0.15);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glRotatef(270.0, 0.0, 0.0, 1.0);
		glScalef(0.5, 0.25, 0.1);
		Figura();
	glPopMatrix();
}

void Objeto()
{
	glPushMatrix();
		glTranslatef(1.0, 0.0, 0.0);
		espada();
	glPopMatrix();

	glPushMatrix();
		glRotatef(180.0, 0.0, 1.0, 0.0);
		glTranslatef( 1.0, 0.0, 0.0);
		escudo();
	glPopMatrix();
}

void luzCero(void)
{
	GLfloat l_a_color[]={colores[7][0], colores[7][1], colores[7][2], 1.0f};
	GLfloat l_difusa[]={colores[7][0], colores[7][1], colores[7][2], 1.0f};
	GLfloat l_especular[]={colores[7][0], colores[7][1], colores[7][2], 1.0f};
	GLfloat l_posicion[]={10.0, 10.0, 10.0, 0.0};

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,l_a_color);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, l_difusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, l_difusa);
	glLightfv(GL_LIGHT0, GL_POSITION, l_posicion);
	glLightfv(GL_LIGHT0, GL_AMBIENT, l_a_color);
	glEnable (GL_LIGHT0);
}

void luzUno(void)
{
	GLfloat l_difusa[]={colores[8][0], colores[8][1], colores[8][2], 1.0f};
	GLfloat l_especular[]={colores[8][0], colores[8][1], colores[8][2], 1.0f};
	GLfloat l_posicion[]={-5.0, 0.0, 5.0, 1.0};

	glLightfv(GL_LIGHT1, GL_DIFFUSE, l_difusa);
	glLightfv(GL_LIGHT1, GL_SPECULAR, l_difusa);
	glLightfv(GL_LIGHT1, GL_POSITION, l_posicion);
	//glEnable (GL_LIGHT1);
}

void luzDos(void)
{
	GLfloat l_difusa[]={colores[4][0], colores[4][1], colores[4][2], 1.0f};
	GLfloat l_especular[]={colores[4][0], colores[4][1], colores[4][2], 1.0f};
	GLfloat l_posicion[]={5.0, 0.0, 5.0, 1.0};

	glLightfv(GL_LIGHT2, GL_DIFFUSE, l_difusa);
	glLightfv(GL_LIGHT2, GL_SPECULAR, l_difusa);
	glLightfv(GL_LIGHT2, GL_POSITION, l_posicion);
	//glEnable (GL_LIGHT2);
}

void luzTres(void)
{
	GLfloat l_difusa[]={1.0, 1.0, 1.0, 1.0f};
	GLfloat l_especular[]={1.0, 1.0, 1.0, 1.0f};
	GLfloat l_posicion[]={0.0, 0.0, 5.0, 1.0};
	//GLfloat spot_direccion[]={0.0, 0.0, 0.0, 0.0};

	glLightfv(GL_LIGHT3, GL_DIFFUSE, l_difusa);
	glLightfv(GL_LIGHT3, GL_SPECULAR, l_difusa);
	glLightfv(GL_LIGHT3, GL_POSITION, l_posicion);

	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 11.0);
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 0.0);
	//glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direccion);
	//glEnable (GL_LIGHT3);
}


void plasticoRojo()
{
	GLfloat l_ambiente[]={0.0f, 0.0f, 0.0f, 1.0f};
	GLfloat l_difusa[]={0.5f, 0.0f, 0.0f, 1.0f};
	GLfloat l_especular[]={0.7f, 0.6f, 0.6f, 1.0f};
	GLfloat brillo[]={32.0};

	glMaterialfv(GL_FRONT, GL_AMBIENT, l_ambiente);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, l_difusa);
	glMaterialfv(GL_FRONT, GL_SPECULAR, l_especular);
	glMaterialfv(GL_FRONT, GL_SHININESS, brillo);
}

void plasticoNegro()
{
	GLfloat l_ambiente[]={0.02f, 0.02f, 0.02f, 1.0f};
	GLfloat l_difusa[]={0.01f, 0.01f, 0.01f, 1.0f};
	GLfloat l_especular[]={0.4f, 0.4f, 0.4f, 1.0f};
	GLfloat brillo[]={10.0};

	glMaterialfv(GL_FRONT, GL_AMBIENT, l_ambiente);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, l_difusa);
	glMaterialfv(GL_FRONT, GL_SPECULAR, l_especular);
	glMaterialfv(GL_FRONT, GL_SHININESS, brillo);
}

void plata()
{
	GLfloat l_ambiente[]={0.19225f, 0.19225f, 0.19225f, 1.0f};
	GLfloat l_difusa[]={0.50754f, 0.50754f, 0.50754f, 1.0f};
	GLfloat l_especular[]={0.508273f, 0.508273f, 0.508273f, 1.0f};
	GLfloat brillo[]={51.2};

	glMaterialfv(GL_FRONT, GL_AMBIENT, l_ambiente);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, l_difusa);
	glMaterialfv(GL_FRONT, GL_SPECULAR, l_especular);
	glMaterialfv(GL_FRONT, GL_SHININESS, brillo);
}

void plataBrillante()
{
	GLfloat l_ambiente[]={0.23125f, 0.23125f, 0.23125f, 1.0f};
	GLfloat l_difusa[]={0.2775f, 0.2775f, 0.2775f, 1.0f};
	GLfloat l_especular[]={0.773911f, 0.773911f, 0.773911f, 1.0f};
	GLfloat brillo[]={89.6};

	glMaterialfv(GL_FRONT, GL_AMBIENT, l_ambiente);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, l_difusa);
	glMaterialfv(GL_FRONT, GL_SPECULAR, l_especular);
	glMaterialfv(GL_FRONT, GL_SHININESS, brillo);
}

void cobre()
{
	GLfloat l_ambiente[]={0.19125f, 0.0735f, 0.0225f, 1.0f};
	GLfloat l_difusa[]={0.7038f, 0.27048f, 0.0828f, 1.0f};
	GLfloat l_especular[]={0.256777f, 0.137622f, 0.086014f, 1.0f};
	GLfloat brillo[]={12.8};

	glMaterialfv(GL_FRONT, GL_AMBIENT, l_ambiente);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, l_difusa);
	glMaterialfv(GL_FRONT, GL_SPECULAR, l_especular);
	glMaterialfv(GL_FRONT, GL_SHININESS, brillo);
}

void brass()
{
	GLfloat l_ambiente[]={0.329412f, 0.223529f, 0.027451f, 1.0f};
	GLfloat l_difusa[]={0.780932f, 0.568627f, 0.113725f, 1.0f};
	GLfloat l_especular[]={0.992157f, 0.941176f, 0.807843f, 1.0f};
	GLfloat brillo[]={27.8974};

	glMaterialfv(GL_FRONT, GL_AMBIENT, l_ambiente);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, l_difusa);
	glMaterialfv(GL_FRONT, GL_SPECULAR, l_especular);
	glMaterialfv(GL_FRONT, GL_SHININESS, brillo);
}

void turqueza()
{
	GLfloat l_ambiente[]={0.1f, 0.18725f, 0.1745f, 0.8f};
	GLfloat l_difusa[]={0.396f, 0.74151f, 0.69102f, 0.8f};
	GLfloat l_especular[]={0.297254f, 0.30829f, 0.306678f, 0.8f};
	GLfloat brillo[]={12.8};

	glMaterialfv(GL_FRONT, GL_AMBIENT, l_ambiente);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, l_difusa);
	glMaterialfv(GL_FRONT, GL_SPECULAR, l_especular);
	glMaterialfv(GL_FRONT, GL_SHININESS, brillo);
}

void obsidianaRoja()
{
	GLfloat l_ambiente[]={1.0f, 0.1f, 0.1f, 0.82f};
	GLfloat l_difusa[]={1.0f, 0.1f, 0.01f, 0.82f};
	GLfloat l_especular[]={0.332741f, 0.328634f, 0.346435f, 0.82f};
	GLfloat brillo[]={38.4};

	glMaterialfv(GL_FRONT, GL_AMBIENT, l_ambiente);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, l_difusa);
	glMaterialfv(GL_FRONT, GL_SPECULAR, l_especular);
	glMaterialfv(GL_FRONT, GL_SHININESS, brillo);
}

void init(void)
{

    glEnable(GL_CULL_FACE);		//Activar metodo de ocultacion de caras (que no se ven)
    glFrontFace(GL_CCW);		//Sentido que tienen los vertices cuandi de mirar
								//(Horario - Antihorario)
	luzCero();
	//luzUno();
	//luzDos();
	//luzTres();
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}

void display0(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//PARAMETROS DE gluPerspective(float alpha, float aspect, float near, float far);
	//angulo de vision vertical(y)
	//relación entre angulo de vision horizontal y vertical (altura/anchura)
	//La relación entre far/near debería ser lo más cercana posible a 1
	gluPerspective(65.0, 1.0, 1.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0f, 0.0f, 5.5f,
			  0.0f, 0.0f, 0.0f,
			  0.0f, 1.0f, 0.0f);

	glPushMatrix();

		glRotatef(alpha, 1.0f, 0.0f, 0.0f);
		glRotatef(beta, 0.0f, 1.0f, 0.0f);

		Figura();

	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

void display1(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//PARAMETROS DE gluPerspective(float alpha, float aspect, float near, float far);
	//angulo de vision vertical(y)
	//relación entre angulo de vision horizontal y vertical (altura/anchura)
	//La relación entre far/near debería ser lo más cercana posible a 1
	gluPerspective(65.0, 1.0, 1.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0f, 0.0f, 5.5f,
			  0.0f, 0.0f, 0.0f,
			  0.0f, 1.0f, 0.0f);

	glPushMatrix();

		glRotatef(alpha, 1.0f, 0.0f, 0.0f);
		glRotatef(beta, 0.0f, 1.0f, 0.0f);

		Objeto();

	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

void setDisplay(void)
{
	glutSetWindow(w1);
	glLoadIdentity();
    glutPostRedisplay();

	glutSetWindow(w2);
	glLoadIdentity();
    glutPostRedisplay();
}

void onMouse(int button, int state, int x, int y)
{
	if ( (button == GLUT_LEFT_BUTTON) & (state == GLUT_DOWN) )
	{
		x0 = x; y0 = y;
	}
}

void onMotion(int x, int y)
{
	alpha = (alpha + (y - y0));
	beta = (beta + (x - x0));
	x0 = x;
	y0 = y;
	glutPostRedisplay();
}

void menuFiguras(int opcion)
{
	switch(opcion)
	{
		case L1:
			glEnable(GL_LIGHT1);
			break;
		case L2:
			glEnable(GL_LIGHT2);
			break;
		case L3:
			glDisable(GL_LIGHT1);
			break;
		case L4:
			glDisable(GL_LIGHT2);
			break;
		case S1:
			glEnable(GL_LIGHT3);
			break;
		case S2:
			glDisable(GL_LIGHT3);
			break;
	}
	luzCero();
	luzUno();
	luzDos();
	luzTres();
	glutPostRedisplay();
}

void creacionMenu(void)
{
	int menuLUCES, menuMain;
	int on, off;

	on = glutCreateMenu(menuFiguras);
	glutAddMenuEntry("Luz 1", L1);
	glutAddMenuEntry("Luz 2", L2);
	glutAddMenuEntry("Spot", S1);

	off = glutCreateMenu(menuFiguras);
	glutAddMenuEntry("Luz 1", L3);
	glutAddMenuEntry("Luz 2", L4);
	glutAddMenuEntry("Spot", S2);

	menuLUCES = glutCreateMenu(menuFiguras);
	glutAddSubMenu("Activar", on);
	glutAddSubMenu("Desactivar", off);

	menuMain = glutCreateMenu(menuFiguras);
	glutAddSubMenu("Luces", menuLUCES);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 100);
	w1=glutCreateWindow("Figura 3D");
	init();

	glutMouseFunc(onMouse);
	glutMotionFunc(onMotion);
	creacionMenu();

	glutDisplayFunc(display0);


	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(450, 100);
	w2=glutCreateWindow("Objeto 3D");
	init();

	glutMouseFunc(onMouse);
	glutMotionFunc(onMotion);
	creacionMenu();

	glutDisplayFunc(display1);


	glutMainLoop();
}

