#include "iGraphics.h"

int rectangleX = -40 ,rectangleY = 10;

double X1=-50 , X2=-30, X3=0 ;
double Y1=120 ,Y2=250 ,Y3=120 ;

int cirX = -50,cirY = 300;

int ellipseX=-50,ellipseY=450 ;

void rectangle()
{
	iSetColor(24,185,12);
	iFilledRectangle(rectangleX,rectangleY, 100 ,100) ;
	rectangleX =rectangleX+1 ;
	if(rectangleX -50>=600)
		rectangleX=-50;
}
void polygon()
{
	iSetColor(233,239,52);
	double PolygonXpos[]={X1,X2,X3};
	double PolygonYpos[]={Y1,Y2,Y3};
	iFilledPolygon(PolygonXpos,PolygonYpos, 3);
	X1++ ;
	X2++ ;
	X3++ ;
	if(X1 -50>=600)
	{
		X1= -50;
		X2= -30 ;
		X3= -5;
	}
}

void circle()
{
	iSetColor(210,13,13);
	iFilledCircle(cirX, cirY, 50, 600);
	cirX = cirX+1;
	if(cirX-50 >= 600)
		cirX = -50;
}
void ellipse()
{
	iSetColor(94,182,249) ;
	iFilledEllipse(ellipseX,ellipseY, 50, 30) ;
	ellipseX=ellipseX+1 ;
	if(ellipseX -50>=600)
		ellipseX = -50 ;
}

void iDraw()
{
	iClear();
	
	iSetColor(14,14,14);
	iFilledRectangle(0,0, 600, 600);

	//circle();
	//rectangle();
	//ellipse();
	//polygon();
}
void iPassiveMouse(int x, int y)
{

}

void iMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}
}

void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
}

int main()
{
	//iSetTimer(450,circle);
	//iSetTimer(450,rectangle);
	//iSetTimer(450,ellipse);
	//iSetTimer(450,polygon);
	iInitialize(600, 600, "Different shapes movement");
	iStart();
	return 0;
}