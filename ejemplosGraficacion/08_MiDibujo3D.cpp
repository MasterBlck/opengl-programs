#include <windows.h>
#include <GL/glut.h>

float alpha, beta;
int x0, y0;

//Menu de figuras a elegir
typedef enum{L1,L2,L3,L4,S1,S2}opcionMenu;

//Matriz de colores
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

int color = 7;
int colorf = 0;
int colorl = 3;

void plasticoRojo();
void plasticoNegro();
void plataBrillante();
void plata();
void cobre();
void brass();
void turqueza();
void obsidianaRoja();

void tracktor(void)
{
	//VENTANAS
	glPushMatrix();
		turqueza();
		glScalef(1.0, 1.0, 0.9);

		glPushMatrix();
			glTranslatef(-0.55, 0.825, 0.0);
			glBegin(GL_POLYGON);
				glVertex3f(0.0, 0.0, 1.0);
				glVertex3f(0.0, 0.65, 1.0);
				glVertex3f(-0.4, 0.0, 1.0);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-0.55, 0.825, -2.0);
			glBegin(GL_POLYGON);
				glVertex3f(0.0, 0.0, 1.0);
				glVertex3f(0.0, 0.65, 1.0);
				glVertex3f(-0.4, 0.0, 1.0);
			glEnd();
		glPopMatrix();

		//PARABRISAS
		glPushMatrix();
			glTranslatef(-0.55, 0.825, 0.0);
			glBegin(GL_POLYGON);
				glVertex3f(0.0, 0.65, 1.0);
				glVertex3f(-0.4, 0.0, 1.0);
				glVertex3f(-0.4, 0.0, -1.0);
				glVertex3f(0.0, 0.65, -1.0);
			glEnd();
		glPopMatrix();	

		//VENTANAS TRASERAS
		glPushMatrix();
			glTranslatef(0.4, 0.0, 0.0);
			glRotatef(180, 0.0, 1.0, 0.0);
			
			glPushMatrix();
				glTranslatef(-0.55, 0.825, 0.0);
				glBegin(GL_POLYGON);
					glVertex3f(0.0, 0.0, 1.0);
					glVertex3f(0.0, 0.65, 1.0);
					glVertex3f(-0.3, 0.0, 1.0);
				glEnd();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-0.55, 0.825, -2.0);
				glBegin(GL_POLYGON);
					glVertex3f(0.0, 0.0, 1.0);
					glVertex3f(0.0, 0.65, 1.0);
					glVertex3f(-0.3, 0.0, 1.0);
				glEnd();
			glPopMatrix();

			//PARABRISAS TRASERO
			glPushMatrix();
				glTranslatef(-0.55, 0.825, 0.0);
				glBegin(GL_POLYGON);
					glVertex3f(0.0, 0.65, 1.0);
					glVertex3f(-0.3, 0.0, 1.0);
					glVertex3f(-0.3, 0.0, -1.0);
					glVertex3f(0.0, 0.65, -1.0);
				glEnd();
			glPopMatrix();
		glPopMatrix();

	glPopMatrix();

	//CABINA
	glPushMatrix();
		plasticoRojo();
		glTranslatef(0.2, 1.5, 0.0);
		glScalef(1.5, 0.1, 1.9);
		glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
		plasticoRojo();
		glTranslatef(0.7, 1.15, 0.0);
		glScalef(0.7, 0.655, 1.9);
		glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
		turqueza();
		glTranslatef(0.2, 1.15, 0.0);
		glScalef(1.5, 0.65, 1.8);
		glutSolidCube(1.0);
	glPopMatrix();

	//CHACIS
	glPushMatrix();
		plasticoRojo();
		glTranslatef(0.0, 0.5, 0.0);
		glScalef(3.0, 0.65, 2.0);
		glutSolidCube(1.0);
	glPopMatrix();

	//DEFENSA
	glPushMatrix();
		plataBrillante();
		glTranslatef(0.0, 0.0, 0.0);
		glScalef(3.5, 0.6, 2.5);
		glutSolidSphere(0.5, 45, 45);
	glPopMatrix();
	
	glPushMatrix();
		plataBrillante();
		glTranslatef(0.0, 0.0, 0.0);
		glScalef(3.25, 0.35, 2.1);
		glutSolidCube(1.0);
	glPopMatrix();

	//FAROS	DELANTEROS
	brass();
	glPushMatrix();
		glTranslatef(-1.5, 0.6, 0.8);
		glScalef(0.15, 0.40, 0.40);
		glutSolidSphere(0.5, 45, 45);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.5, 0.6, -0.8);
		glScalef(0.15, 0.40, 0.40);
		glutSolidSphere(0.5, 45, 45);
	glPopMatrix();


	plata();
	glPushMatrix();
		glTranslatef(-1.5, 0.37, 0.0);
		glScalef(0.05, 0.50, 0.10);
		glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.5, 0.37, 0.12);
		glScalef(0.05, 0.50, 0.07);
		glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.5, 0.37, 0.22);
		glScalef(0.05, 0.50, 0.07);
		glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.5, 0.37, -0.12);
		glScalef(0.05, 0.50, 0.07);
		glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.5, 0.37, -0.22);
		glScalef(0.05, 0.50, 0.07);
		glutSolidCube(1.0);
	glPopMatrix();

	//FAROS	TRASEROS
	obsidianaRoja();
	glPushMatrix();
		glTranslatef(1.45, 0.6, 0.8);
		glScalef(0.15, 0.35, 0.45);
		glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.45, 0.6, -0.8);
		glScalef(0.15, 0.35, 0.45);
		glutSolidCube(1.0);
	glPopMatrix();

	//LLANTAS
	glLineWidth(0.5);
	plasticoNegro();
	glPushMatrix();
		glTranslatef(-1.0, -0.5, -0.75);
		glRotatef(180.0, 1.0, 1.0, 0.0);
		glScalef(1.0, 1.0, 1.0);
		glutSolidTorus(0.25, 0.5, 25, 25);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.0, -0.5, -0.75);
		glRotatef(180.0, 1.0, 1.0, 0.0);
		glScalef(1.0, 1.0, 1.0);
		glutSolidTorus(0.25, 0.5, 25, 25);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.0, -0.5, 0.75);
		glRotatef(180.0, 1.0, 1.0, 0.0);
		glScalef(1.0, 1.0, 1.0);
		glutSolidTorus(0.25, 0.5, 25, 25);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.0, -0.5, 0.75);
		glRotatef(180.0, 1.0, 1.0, 0.0);
		glScalef(1.0, 1.0, 1.0);
		glutSolidTorus(0.25, 0.5, 25, 25);
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
	luzCero();
	//luzUno();
	//luzDos();
	//luzTres();
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}

void display(void)
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
		tracktor();
	glPopMatrix();
	
	glFlush();
	glutSwapBuffers();
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
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Camioneta 3D");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(onMouse);
	glutMotionFunc(onMotion);
	creacionMenu();
	glutMainLoop();
}
