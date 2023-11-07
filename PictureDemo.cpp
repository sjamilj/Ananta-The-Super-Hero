# include "iGraphics.h"
#include "bitmap_loader.h"
#include<iostream>
using namespace std;


int pic_x=200, pic_y=300;
int pic=1;
int fire=0;
int lx,ly; 
int gotFire=0;
int efire=0;
int lx1;//guli cordinate 
//char bg[10][20]={"aj1.bmp", "aj2.bmp", "aj3.bmp", "aj4.bmp"};
//int bgIndex=0;
/*
	function iDraw() is called again and again by the system.
*/

void Key(){
	if(GetKeyState(70)<0)
    {
        fire=1;
    }
	//cout<<"Jamil";
    if(GetKeyState(VK_RIGHT)<0)
    {
        pic_x+=1.1;
        if(pic_x>1000)
            pic_x=1000;
    }
    if(GetKeyState(VK_LEFT)<0)
    {
        pic_x-=1.1;
        if(pic_x<0)
            pic_x=0;
    }
    if(GetKeyState(VK_UP)<0)
    {
         pic_y+=1.2;
        if(pic_y>750)
            pic_y=750;
    }
    if(GetKeyState(VK_DOWN)<0)
    {
        pic_y-=1.1;
        if(pic_y<0)
            pic_y=0;
    }
}

void Afire()
{
	if(!fire)
	{
		lx=pic_x+83;
		ly=pic_y+83;
	}
	if(fire)
	{
			
		lx+=30;
	}
	if(lx>=1000)
	{

		fire=0;
		lx=pic_x+83;
		ly=pic_y+83;
		
	}
	
}


void iDraw()
{
	//place your drawing codes here

	iClear();
	Key();
	
	iShowBMP(pic_x, pic_y,"aj1.bmp");
	
	
	

	iSetColor(255,0,0);

	if(fire)
	iFilledRectangle(lx,ly,20,5);
	
	


}
void iMouseMove(int mx, int my)
{
	//place your codes here
}


void iPassiveMouse(int mx, int my)
{
	//place your codes here
}


/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		
		//cout<<mx<<endl;
		//cout<<my<<endl;
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{

	//place your codes for other keys here
}


void iSpecialKeyboard(unsigned char key)
{

	
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.
	
	
	iInitialize(1000,750, "PictureDemo");
	iSetTimer(10,Afire);
	

	iStart();
	return 0;
}
