//Jeff Chastine
#include <GL\freeglut.h>
using namespace std;


#define w 500
#define h 500
float step;
bool flag = false;



void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glColor3f(0.0f, 0.0f, 0.0f);

	glPointSize(2.5);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluOrtho2D(-w, w, -h, h);
}


void setpixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glFlush();
}

void circlePlotPoints(int xCenter, int yCenter, int x, int y)
{
	setpixel(xCenter + x, yCenter + y);
	setpixel(xCenter - x, yCenter + y);
	setpixel(xCenter + x, yCenter - y);
	setpixel(xCenter - x, yCenter - y);
	setpixel(xCenter + y, yCenter + x);
	setpixel(xCenter - y, yCenter + x);
	setpixel(xCenter + y, yCenter - x);
	setpixel(xCenter - y, yCenter - x);
}

void circleMidpoint(int xCenter, int yCenter, int radius)
{
	int x = 0;
	int y = radius;
	int f = 1 - radius;

	circlePlotPoints(xCenter, yCenter, x, y);
	while (x < y) {
		x++;
		if (f < 0)
			f += 2 * x + 1;
		else {
			y--;
			f += 2 * (x - y) + 1;
		}
		circlePlotPoints(xCenter, yCenter, x, y);
	}
}
void fillcircle(int x, int y, int re, float r, float g, float b, float size)
{
	glColor3f(r, g, b);
	glPointSize(size);
	glBegin(GL_POINTS);
	for (int i = re; i >= 0; i -= size)
		circleMidpoint(x, y, i);

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(2.5);

}
void smilePlotPoints(int xCenter, int yCenter, int x, int y)
{
	setpixel(xCenter + x, yCenter - y);
	setpixel(xCenter - x, yCenter - y);

}
void smile(int xCenter, int yCenter, int radius)
{
	int x = 0;
	int y = radius;
	int f = 1 - radius;

	smilePlotPoints(xCenter, yCenter, x, y);
	while (x < y) {
		x++;
		if (f < 0)
			f += 2 * x + 1;
		else {
			y--;
			f += 2 * (x - y) + 1;
		}
		smilePlotPoints(xCenter, yCenter, x, y);
	}
}

void refsmilePlotPoints(int xCenter, int yCenter, int x, int y)
{
	setpixel(xCenter + x, yCenter + y);
	setpixel(xCenter - x, yCenter + y);

}
void refsmile(int xCenter, int yCenter, int radius)
{
	int x = 0;
	int y = radius;
	int f = 1 - radius;

	refsmilePlotPoints(xCenter, yCenter, x, y);
	while (x < y) {
		x++;
		if (f < 0)
			f += 2 * x + 1;
		else {
			y--;
			f += 2 * (x - y) + 1;
		}
		refsmilePlotPoints(xCenter, yCenter, x, y);
	}
}
void myDisplay(void)
{
	if (!flag)
		for (step = 70; step <= 300; step += 50)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glBegin(GL_POINTS);

			circleMidpoint(-200, 50 + step, 100);
			fillcircle(-200, 50 + step, 100, 1, 1, 0, 20);
			fillcircle(-150, 90 + step, 10, 0, 0, 0, 2);
			fillcircle(-250, 90 + step, 10, 0, 0, 0, 2);
			smile(-200, 50 + step, 75);


			circleMidpoint(-200, -50 - step, 100);
			fillcircle(-200, -50 - step, 100, 1, 1, 0.4, 20);
			fillcircle(-150, -90 - step, 10, 0, 0, 0, 2);
			fillcircle(-250, -90 - step, 10, 0, 0, 0, 2);
			refsmile(-200, -50 - step, 75);

			glEnd();
			glFlush();
		}
	flag = true;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(800, 800);

	glutInitWindowPosition(500, 00);

	glutCreateWindow("smiley sun");

	myInit();

	glutDisplayFunc(myDisplay);

	glutMainLoop();
}