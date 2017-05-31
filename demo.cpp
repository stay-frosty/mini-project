#include<iostream>
#include<stdlib.h>
#include<glut.h>

GLfloat spin = 0, i = 0, j = 0, y = 0.05, z = 0, t = 0;
void *currentfont;
int r = 0, l = 0;
float ballX = -0.8f;
float ballY = -0.3f;
float ballZ = -1.2f;
float colR = 1.0;
float colG = 0.5;
float colB = 0.1;
float bgColR = 0.0;
float bgColG = 0.0;
float bgColB = 0.0;
float _angle = 45.0f;
static int flag = 1;
int wflag = 0, frflag = 0, flflag = 0;
void display(void);

void setFont(void *font)
{
	currentfont = font;//Set font
}

void drawstring(float x, float y, float z, char *s)
{
	glRasterPos3f(x, y, z);
	for (int i = 0; s[i] != '\0'; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
	}
}

void wel(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 0.0);
	drawstring(-0.4, 0.3, -1.0, "MANGALORE INSTITUTE OF TECHNOLOGY AND ENGINEERING");
	glColor3f(0.7, 0.5, 0.79);
	drawstring(-0.2, 0.25, -1.0, "WELCOME TO THE PROJECT ");
	glColor3f(1.0, 0.6, 0.0);
	drawstring(-0.1, 0.2, -1.0, "WAR SCENE");
	glColor3f(0.75, 0.0, 0.8);
	drawstring(-0.7, 0.1, -1.0, "1)PRESS ENTER to start");
	drawstring(-0.7, 0.05, -1.0, "2)PRESS 'l' to make the left tank fire");
	drawstring(-0.7, 0.0, -1.0, "3)PRESS 'r' to make the right tank fire");
	drawstring(-0.7, -0.05, -1.0, "4)PRESS 'a' to move the left tank");
	drawstring(-0.7, -0.1, -1.0, "5)PRESS 'd' to move the right tank");
	drawstring(-0.7, -0.15, -1.0, "6)PRESS 'q' or 'Q' to quit");
	glColor3f(0.0, 0.0, 1.0);
	drawstring(-0.7, -0.25, -1.0, "GUIDED BY:");
	glColor3f(0.8, 0.5, 0.0);
	drawstring(-0.7, -0.3, -1.0, "Mr. John Prakash");
	drawstring(-0.7, -0.35, -1.0, "Mr. Sunil Kumar");
	glColor3f(0.0, 0.0, 1.0);
	drawstring(0.35, -0.3, -1.0, "PRESENTED BY:");
	glColor3f(0.8, 0.5, 0.0);
	drawstring(0.25, -0.34, -1.0, "AASTHA BHATNAGAR   4MT14CS002");
	glFlush();
	glutSwapBuffers();
}

void drawheli(void)
{
	//tail
	glBegin(GL_POLYGON);
	glColor3f(0.6,0.8,0.296078);
	glVertex3f(-0.5+y, 0.4, -1.0);
	glVertex3f(-0.45+y, 0.4, -1.0);
	glVertex3f(-0.4+y, 0.35, -1.0);
	glVertex3f(-0.35+y, 0.35, -1.0);
	glVertex3f(-0.35+y, 0.3, -1.0);
	glVertex3f(-0.4+y, 0.3, -1.0);
	glVertex3f(-0.45+y, 0.25, -1.0);
	glVertex3f(-0.375+y, 0.375, -1.0);
	glEnd();

	//body
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.8, 0.296078);
	glVertex3f(-0.35+y, 0.4, -1.0);
	glVertex3f(-0.35+y, 0.3, -1.0);
	glVertex3f(-0.25+y, 0.3, -1.0);
	glVertex3f(-0.28+y, 0.4, -1.0);
	glEnd();
}

void drawSun(void)
{
	glColor3f(colR, colG, colB); //set sun colour
	glTranslatef(ballX, ballY, ballZ); //moving it toward the screen a bit on creation
	glutSolidSphere(0.05, 30, 30); //create sun
}

void drawfort(void)
{
	//door
	glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.06, -0.5, -1.0);
		glVertex3f(-0.06, -0.2, -1.0);
		glVertex3f(0.06, -0.2, -1.0);
		glVertex3f(0.06, -0.5, -1.0);
	glEnd();

	//window
	glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(-0.05, -0.05, -1.0);
		glVertex3f(-0.05, -0.1, -1.0);
		glVertex3f(-0.11, -0.1, -1.0);
		glVertex3f(-0.11, -0.05, -1.0);
	glEnd();

	//window
	glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.05, -0.05, -1.0);
		glVertex3f(0.05, -0.1, -1.0);
		glVertex3f(0.11, -0.1, -1.0);
		glVertex3f(0.11, -0.05, -1.0);
	glEnd();

	//building
	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-0.2, -0.5, -1.0);
		glVertex3f(-0.2, 0.1, -1.0);
		glVertex3f(0.2, 0.1, -1.0);
		glVertex3f(0.2, -0.5, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.1, -0.5, -1.0);
		glVertex3f(0.1, -0.5, -1.0);
		glVertex3f(0.1, -0.4, -1.0);
		glVertex3f(-0.1, -0.4, -1.0);
	glEnd();

	//stick

	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.05, 0.2 + t, -1.0);
	glVertex3f(-0.05, 0.1, -1.0);
	glVertex3f(-0.04, 0.1, -1.0);
	glVertex3f(-0.04, 0.2 + t, -1.0);
	glEnd();


	//flag
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0 + t, 0.0);
	glVertex3f(-0.04, 0.2 + t, -1.0);
	glVertex3f(0.0, 0.16 + t, -1.0);
	glVertex3f(-0.04, 0.16 + t, -1.0);
	glEnd();

	//backdrop
	glBegin(GL_POLYGON);
		glColor3f(0.5, 1.0, 1.0);
		glVertex3f(-0.6, -0.5, -1.0);
		glVertex3f(-0.6, -0.2, -1.0);
		glVertex3f(0.0, 0.0, -1.0);
		glVertex3f(0.6, -0.2, -1.0);
		glVertex3f(0.6, -0.2, -1.0);
		glVertex3f(0.6, -0.5, -1.0);
	glEnd();

}

void drawClouds(void)
{

	glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.2, 0.2, -1.0);
		glVertex3f(0.2, 0.3, -1.0);
		glVertex3f(0.25, 0.25, -1.0);
		glVertex3f(0.3, 0.3, -1.0);
		glVertex3f(0.3, 0.2, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(-0.6, 0.2, -1.0);
		glVertex3f(-0.6, 0.3, -1.0);
		glVertex3f(-0.55, 0.25, -1.0);
		glVertex3f(-0.7, 0.3, -1.0);
		glVertex3f(-0.7, 0.2, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(-0.1, 0.23, -1.0);
		glVertex3f(-0.05, 0.25, -1.0);
		glVertex3f(-0.1, 0.35, -1.0);
		glVertex3f(-0.2, 0.35, -1.0);
		glVertex3f(-0.2, 0.23, -1.0);
	glEnd();
}

void drawTankleft(void)
{
	//tank body
	glBegin(GL_POLYGON);
	glColor3f(0.59, 0.41, 0.31);
	glVertex3f(-0.74 + y, -0.5, -1.0);
	glVertex3f(-0.4 + y, -0.5, -1.0);
	glVertex3f(-0.4 + y, -0.25, -1.0);
	glVertex3f(-0.74 + y, -0.25, -1.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.59, 0.41, 0.31);
	glVertex3f(-0.4 + y, -0.5, -1.0);
	glVertex3f(-0.4 + y, -0.25, -1.0);
	glVertex3f(-0.3 + y, -0.375, -1.0);
	glEnd();

	//cannon body
	glBegin(GL_POLYGON);
	glColor3f(0.29, 0.21, 0.11);
	glVertex3f(-0.7 + y, -0.25, -1.0);
	glVertex3f(-0.7 + y, -0.2, -1.0);
	glVertex3f(-0.55 + y, -0.2, -1.0);
	glVertex3f(-0.55 + y, -0.25, -1.0);
	glEnd();

	//cannon
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-0.55 + y, -0.23, -1.0);
	glVertex3f(-0.55 + y, -0.22, -1.0);
	glVertex3f(-0.4 + y, -0.2, -1.0);
	glVertex3f(-0.4 + y, -0.21, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-0.55 + y, -0.22, -1.0);
	glVertex3f(-0.5 + y, -0.22, -1.0);
	glVertex3f(-0.5 + y, -0.25, -1.0);
	glVertex3f(-0.55 + y, -0.25, -1.0);
	glEnd();
}

void drawTankright(void)
{
	//tank body
	glBegin(GL_POLYGON);
	glColor3f(0.59, -0.41, 0.31);
	glVertex3f(0.74 - z, -0.5, -1.0);
	glVertex3f(0.4 - z, -0.5, -1.0);
	glVertex3f(0.4 - z, -0.25, -1.0);
	glVertex3f(0.74 - z, -0.25, -1.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.59, -0.41, 0.31);
	glVertex3f(0.4 - z, -0.5, -1.0);
	glVertex3f(0.4 - z, -0.25, -1.0);
	glVertex3f(0.3 - z, -0.375, -1.0);
	glEnd();

	//cannon body
	glBegin(GL_POLYGON);
	glColor3f(0.29, -0.21, 0.11);
	glVertex3f(0.7 - z, -0.25, -1.0);
	glVertex3f(0.7 - z, -0.2, -1.0);
	glVertex3f(0.55 - z, -0.2, -1.0);
	glVertex3f(0.55 - z, -0.25, -1.0);
	glEnd();

	//cannon
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.55 - z, -0.23, -1.0);
	glVertex3f(0.55 - z, -0.22, -1.0);
	glVertex3f(0.4 - z, -0.2, -1.0);
	glVertex3f(0.4 - z, -0.21, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.55 - z, -0.22, -1.0);
	glVertex3f(0.5 - z, -0.22, -1.0);
	glVertex3f(0.5 - z, -0.25, -1.0);
	glVertex3f(0.55 - z, -0.25, -1.0);
	glEnd();
}

void drawTank(void)
{
	glPushMatrix();
	drawTankleft();
	glPopMatrix();
	if (l == 1)
	{
		y = y + 0.002;//---------------------here---------------------
		l = 0;
	}
	glPushMatrix();
	drawTankright();
	glPopMatrix();
	if (r == 1)
	{
		z = z + 0.002;//---------------------here---------------------
		r = 0;
	}
}


void init(void)
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE); //Automatically normalize normals
	glShadeModel(GL_SMOOTH); //Enable smooth shading
}

//Called when the window is resized
void Reshape(int w, int h)
{
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
	//Set the camera perspective

	glLoadIdentity(); //Reset the camera
	gluPerspective(_angle,                  //The camera angle
		(double)w / (double)h, //The width-to-height ratio
		1.0,                   //The near z clipping coordinate
		200.0);                //The far z clipping coordinate
}

void fireright(void)
{
	glPushMatrix();
	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.25, 0.0);
		glVertex3f(-0.55+y, -0.2, -1.0);
		glVertex3f(-0.625+y, -0.05, -1.0);
		glVertex3f(-0.7+y, -0.2, -1.0);
		glVertex3f(-0.625+y, -0.25, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.5, 0.5, 0.5);
		glVertex3f(0.4-z, -0.23, -1.0);
		glVertex3f(0.4-z, -0.22, -1.0);
		glVertex3f(0.37-z, -0.2, -1.0);
		glVertex3f(0.4-z, -0.18, -1.0);
		glVertex3f(0.35-z, -0.15, -1.0);
		glVertex3f(0.37-z, -0.1, -1.0);
	glEnd();

	glPopMatrix();
}


void fireleft(void)
{
	glPushMatrix();
	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.25, 0.0);
		glVertex3f(0.55-z, -0.2, -1.0);
		glVertex3f(0.625-z, -0.05, -1.0);
		glVertex3f(0.7-z, -0.2, -1.0);
		glVertex3f(0.625-z, -0.25, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.5, 0.5, 0.5);
		glVertex3f(-0.4+y, -0.23, -1.0);
		glVertex3f(-0.4+y, -0.22, -1.0);
		glVertex3f(-0.37+y, -0.2, -1.0);
		glVertex3f(-0.4+y, -0.18, -1.0);
		glVertex3f(-0.35+y, -0.15, -1.0);
		glVertex3f(-0.37+y, -0.1, -1.0);
	glEnd();
	glPopMatrix();
}

void display(void)
{
	if (wflag == 0)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
		wel();
	}
	else
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(bgColR, bgColG, bgColB, 0.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//Add ambient light

		GLfloat ambientColor[] = { 1.0f, 1.0f, 1.0f, 1.0f }; //Color (0.2, 0.2, 0.2)
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
		//Add positioned light

		GLfloat lightColor0[] = { 1.0f, 0.5f, 0.0f, 1.0f }; //Color (0.5, 0.5, 0.5)
		GLfloat lightPos0[] = { 4.0f, 0.0f, 8.0f, 1.0f }; //Positioned at (4, 0, 8)
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
		glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
		//Add directed light

		GLfloat lightColor1[] = { 1.0f, 0.5f, 0.0f, 1.0f }; //Color (0.5, 0.2, 0.2)
		//Coming from the direction (-1, 0.5, 0.5)

		GLfloat lightPos1[] = { -1.0f, 0.5f, 0.5f, 0.0f };
		glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
		glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

		//drawing the Sun
		glPushMatrix();
		drawSun();
		glPopMatrix();

		if (flflag == 1)
			fireleft();

		if (frflag == 1)
			fireright();

		//drawing the tank
		glPushMatrix();
		drawTank();
		glPopMatrix();

		//drawing fort
		glPushMatrix();
		drawfort();
		glPopMatrix();
		if (t<0.19999)
			t += 0.00005;

		//drawing the helicopter
		glPushMatrix();
		drawheli();
		glPopMatrix();

		//drawing the Clouds
		glPushMatrix();
		drawClouds();
		glPopMatrix();
		
		
	}
	glFlush();
	glutSwapBuffers();
}

void update(int value)
{
	
		if (ballX > 0.9f)
		{
			//ballX = -0.8f;
			//ballY = -0.3f;
			flag = 1;
			colR = 1.0;
			colG = 0.00;
			colB = 0.0;
			bgColB = 0.0;
		}

		if (flag)
		{
			ballX += 0.001f;
			ballY += 0.0007f;
			colR -= 0.000;
			colG += 0.000;
			colB += 0.000;
			if (ballX > -0.3)
				colB += 0.0;
			bgColB += 0.001;
			bgColR += 0.001;
			bgColG += 0.001;

			if (ballX > 0.01)
				flag = 0;
		}
		if (!flag)
		{
			ballX += 0.001f;
			ballY -= 0.0007f;
			colR += 0.000;
			colB -= 0.00;
			bgColB -= 0.001;
			bgColR -= 0.001;
			bgColG -= 0.001;

			if (ballX < -0.5)
			{
				flag = 1;
			}
		}

		glutPostRedisplay(); //Tell GLUT that the display has changed

		//Tell GLUT to call update again in 25 milliseconds
		glutTimerFunc(25, update, 0);
}

void key(unsigned char k, int x, int y)
{
	switch (k)
	{
	case 'a':
	case 'A':l = 1;
		glutPostRedisplay();
		break;
	case 'd':
	case 'D':r = 1;
		glutPostRedisplay();
		break;
	case 'F':
	case 'l':flflag = 1;//right tank fire
		glutPostRedisplay(); 
		break;
	case 'r':frflag = 1;//left tank fire
		glutPostRedisplay();
		break;
	case'p':wel();
		break;
	case 13:if (wflag == 0)
			{
				wflag = 1;
		glutPostRedisplay();
			}
		break;
	case 'q':
	case 'Q':exit(0);
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 700);
	glutCreateWindow("War Scene");
	glutFullScreen();
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutReshapeFunc(Reshape);
	glutTimerFunc(25, update, 0);
	init();
	glutMainLoop();
	return(0);
} 