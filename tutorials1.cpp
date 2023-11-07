# include "iGraphics.h"
#include  "bitmap_loader.h"
#include<iostream>
#define JUMPLIMIT 100
#define ENEMIESNUMBER 10
#define BGSPEED 10
using namespace std;

int menu=0;
int x=0,y=110;
int r=255,g=255,b=255;
int dx,dy;
bool music=true;
int count=0;
int score=0;

int sy = 510;

char mn[4][15]={"frontpage.bmp","op.bmp","hs.bmp"};
int mnIndex=0;
char bc[6][20]={"aj2.bmp","aj3.bmp","aj4.bmp","aj5.bmp","aj6.bmp","aj7.bmp"};
int bcIndex=0;
int fire=0;
int fx,fy;
bool efire=false;
bool efire2=false;
bool efire3=false;
int efx1,efy1,efx2,efy2,efx3,efy3;
char bcStand[15]="aj1.bmp";
char bcjump[2][15]={"aj3.bmp","aj2.bmp"};
char en[10][20]={"e1.bmp","e2.bmp","e3.bmp","e4.bmp","e5.bmp","e6.bmp","e7.bmp","e8.bmp"};
int enIndex=0;
int enx1=750,eny1=110,enx2=950,eny2=110,enx3=1100,eny3=110,enx4=750,eny4=110;
bool enshow=true;
char eg[2][15]={"gun2.bmp","gun3.bmp"};
int egIndex=0;
char lf[4][15]={"life1.bmp","life2.bmp","life3.bmp","life4.bmp"};
int lfIndex=0;
//char bg[9][15]={"bc11.bmp","bc12.bmp","bc13.bmp","bc14.bmp","bc15.bmp","bc16.bmp","bc17.bmp","bc18.bmp","bc19.bmp"};

bool standposs=true;
int standcont=0;
bool jump=false;
bool jumpup=false;
int jumpcor=0;
int ebfx=750,ebfy;
int boss=1;
void iDraw()
{
	//place your drawing codes here
	iClear();
	iSetColor(r,g,b);
	if(menu==0){
	iShowBMP(0,0,mn[mnIndex]);
		if(mnIndex==2){
			int ara[100]={0};
			int st, n, i, j=0;
			FILE *fp1 = fopen("score.txt", "r");
			while(fscanf(fp1, "%d", &st) != EOF){
				ara[j]=st;
				j++;
			}
			n = j;
			int c, d, swap;
			for (c = 0 ; c < n - 1; c++){
				for (d = 0 ; d < n-1; d++){
					if (ara[d] < ara[d+1]){
						swap       = ara[d];
						ara[d]   = ara[d+1];
						ara[d+1] = swap;
					}
				}
			}
			if(n>5) n = 5;
			int sx = 360;
			for(i=0; i<n; i++){
				char  buf[BUFSIZ];
				sprintf(buf, "%d", ara[i]);
				iSetColor(255, 255, 255);
				iText(sx, sy, buf, GLUT_BITMAP_TIMES_ROMAN_24);
				sy -= 30;
				if(i==n-1) sy = 510;
			}
			fclose(fp1);
		}
	}
	if(menu==1)
	{
		iShowBMP(0,0,"back1.bmp");
		//iText(250, 720, "Press p for pause, r for resume");
		iSetColor(0,255,0);

	if(fire)
	iFilledRectangle(fx,fy,20,5);
	
	if(efire)
	{
		 iSetColor(255,0,0);
		 iFilledRectangle(efx1,efy1,20,5); 
	}
		if(enshow)
		{
			
	     iShowBMP2(enx1,eny1,en[enIndex],0);		 
		 iShowBMP2(enx2,eny2,en[enIndex],0);
		 iShowBMP2(enx3,eny3,en[enIndex],0);				 
		}
	if(jump)
	{
		if(jumpup)
		{
			iShowBMP2(x,y+jumpcor,bcjump[0],0);
		}
		else
		{
           iShowBMP2(x,y+jumpcor,bcjump[1],0);
		}
	}
	else
	{
		if(!standposs)
	{
	iShowBMP2(x+10,y,bc[bcIndex],0);
	standcont++;
	
	
	if(standcont>=20)
	{
		standcont=0;
		bcIndex=0;
		standposs=true;
	}
	}
	else
	{
		iShowBMP2(x,y,bcStand,0);
	}
	}
	}
	if (menu==2)
	{

		iShowBMP(0,0,"back2.bmp");
			iSetColor(255,0,0);

	if(fire)
	iFilledRectangle(fx,fy,20,5);
	if(efire)
	{
		iSetColor(255,0,0);
		 iFilledRectangle(efx1,efy1,20,5);
		 
	}
		if(enshow)
		{

	     iShowBMP2(enx1,eny1,en[enIndex],0);		 
		 iShowBMP2(enx2,eny2,en[enIndex],0);
		 iShowBMP2(enx3,eny3,en[enIndex],0);				 
		}
		if(jump)
	{
		if(jumpup)
		{
			iShowBMP2(x,y+jumpcor,bcjump[0],0);
		}
		else
		{
           iShowBMP2(x,y+jumpcor,bcjump[1],0);
		}
	}
	else
	{
		if(!standposs)
	{
	iShowBMP2(x+10,y,bc[bcIndex],0);
	standcont++;
	
	
	if(standcont>=20)
	{
		standcont=0;
		bcIndex=0;
		standposs=true;
	}
	}
	else
	{
		iShowBMP2(x,y,bcStand,0);
	}
	}
	}
	if(menu==3)
	{
      iShowBMP(0,0,"back3.bmp");
	  iSetColor(0,255,0);
	if(fire)
	iFilledRectangle(fx,fy,20,5);
	if(boss==1)
	{
		 iSetColor(255,0,0);
		 iFilledRectangle(ebfx,ebfy,20,5);
	}

	
	if(efire)
	{
		iSetColor(255,0,0);
		 iFilledRectangle(efx1,efy1,20,5);
	}
	iShowBMP2(x+10,y,"aj8.bmp",0);
	iShowBMP2(enx4,eny4,"e9.bmp",0);
	}
	if(menu==4)
	{
		iShowBMP(0,0,"go.bmp");
		char  buf[BUFSIZ];
		sprintf(buf, "%d", score);
		iText(450, 320, "Your Score", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(480, 290, buf, GLUT_BITMAP_TIMES_ROMAN_24);

	}
	

	//iText(x,y,"Shafayat Jamil",GLUT_BITMAP_TIMES_ROMAN_24);
	
    if(menu!=0)
		iShowBMP2(100,600,lf[lfIndex],0);
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/

void iMouseMove(int mx, int my)
{
	//place your codes here
		//x=mx-150;
		//y=my-20;
}

/*
	function iPassiveMouse() is called when the user moves the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
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
	cout<<mx<<"  "<<my<<endl;
	if(menu==0)
	{
		if(mx>=82 && mx<=273 && my>=304 && my<=328)
		{
			menu=1;
		}
			if(mx>=31 && mx<=144 && my>=629 && my<=704)
		{
			mnIndex=0;
		}
		if(mx>=87 && mx<=241 && my>=227 && my<=253)
		{
			mnIndex=1;
		}
		if(mx>=54 && mx<=302 && my>=160 && my<=187)
		{
			mnIndex=2;	

		}
		if(mx>=86 && mx<=171 && my>=77 && my<=102)
		{
			exit(0);
		}

	}
	if(menu==4)
	{
		if(mx>=23 && mx<=101 && my>=650 && my<=708)
		{
			menu=0;
			mnIndex=0;
		}
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
		//fire=1;

	}
	/*
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
			r=255,g=0,b=0;
		
	}*/
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'm')
	{
		if(music)
		{
			music=false;
			PlaySound(0,0,0);
		}
		else
		{
			music=true;
			PlaySound("dhakarpola.wav",NULL,SND_LOOP| SND_ASYNC);
		}

	}
	else if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
	}
	else if(key == 'r')
	{
		iResumeTimer(0);
	}
	else if(key == 'f')
	{
		fire=1;
	}
	//r=g=b=255
	else if(key == ' ')
	{
		if(!jump)
		{
			jump=true;
			jumpup=true;
			}
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_UP)
	{
		y+=10;	
	}
	else if(key == GLUT_KEY_DOWN)
	{
			bcIndex++;
			y-=10;
	}
	else if(key == GLUT_KEY_LEFT)
	{
		x-=5;
			bcIndex++;
	if(bcIndex>=6)
		bcIndex=0;
	standposs=false;
	
	}
	else if(key == GLUT_KEY_RIGHT)
	{
		x+=2;
			bcIndex++;
	if(bcIndex>=6)
		bcIndex=0;
	standposs=false;
	
	}
	
	//place your codes for other keys here
}
void change()
{
	
	if(menu==1)
	{
	enIndex++;
	if(enIndex>=4)
	{
		enIndex=0;
		enx1-=20;
		enx2-=20;
		enx3-=20;
	}
		if(enx1<x+85)
	{
		enx1=850;
		lfIndex++;
		
	}
	else if(enx2<x+85)
	{
		enx2=900;
		lfIndex++;
	}
	else if(enx3<x+85)
	{
		enx3=950;
		lfIndex++;
	}
	if(count>5)
	{
		menu=2;
		enIndex=5;
	}
	if(lfIndex>=4)
	{
		menu=4;
	}

	if(jump)
	{
		if(jumpup)
		{
			jumpcor+=5;
			if(jumpcor>=JUMPLIMIT)
			{
			jumpup=false;
			}
		}
	
		else
		{
			jumpcor-=5;
         if(jumpcor<0)
			{
			jump=false;
			jumpcor=0;
			}
		}
	}
	}
	if(menu==2)
	{
	enIndex++;
	if(enIndex>=8)
	{
		enIndex=5;
		enx1-=25;
		enx2-=25;
		enx3-=25;
	}
		if(enx1<x+85)
	{
		enx1=850;
		lfIndex++;
	}
	else if(enx2<x+85)
	{
		enx2=900;
		lfIndex++;
	}
	else if(enx3<x+85)
	{
		enx3=950;
		lfIndex++;
	}
	if(count>8)
	{
		menu=3;
	}
	if(lfIndex>=4)
	{
		menu=4;
	}

	if(jump)
	{
		if(jumpup)
		{
			jumpcor+=5;
			if(jumpcor>=JUMPLIMIT)
			{
			jumpup=false;
			}
		}
	
		else
		{
			jumpcor-=5;
         if(jumpcor<0)
			{
			jump=false;
			jumpcor=0;
			}
		}
	}
	}
	if(menu==3)
	{
		enx4+= dx;
	    eny4+= dy;

	if(enx4 > 700 )dx = -5;
	if(enx4 < 400)dx = 5;
	if(eny4 > 600 || eny4 < 100)dy = -dy;
		
	
	if(count>14)
	{
		/*FILE *fp = fopen("score.txt", "a");
		fprintf(fp, "%d\n", score);
		fclose(fp);*/
		menu=4;
		
		cout<<"score="<<score<<endl;
	}
	if(lfIndex>=4)
	{

		menu=4;
	}
	}
}
void Afire()
{
	if(!fire)
	{
		fx=x+83;
		fy=y+83;
	}
	if(fire)
	{
			
		fx+=30;

	}
	if(fx>=1000)
	{

		fire=0;
		fx=x+83;
		fy=y+83;
		count++;
		score+=10;
		
	}
		if(enx1<fx)
	{
		enx1=1050;
		fire=0;
		fx=x+83;
		fy=y+83;
		count++;
		score+=10;
	}
	else if(enx2<fx)
	{
		enx2=1150;
		fire=0;
		fx=x+83;
		fy=y+83;
		count++;
		score+=10;
	}
	else if(enx3<fx)
	{
		enx3=1300;
		fire=0;
		fx=x+83;
		fy=y+83;
		count++;
		score+=10;
		
	}	
	else if(enx4<fx && eny4<fy)
	{
		enx4=750;
		fire=0;
		fx=x+83;
		fy=y+83;
		count++;
		score+=20;
		
	}
	
}
void Efire()
{
	if(enx1==550)
	{
		efire=true;
	}
	if(efire==false)
	{
		efx1=enx1-83;
		efy1=eny1+127;
	}
	if(efire)
	{
		efx1-=30;
	}	
	if(ebfx<=0)
	{	
		ebfx=750;
	  ebfy=eny4;
		boss=1;
	}
	
	 if(boss==1)
	{
		ebfx-=30;
	}
	if(efx1<x+85)
	{
		efire=false;
	
		lfIndex++;
	}
}

int main()
{
	//setAll();
	//setenVariable();
	//place your own initialization codes here. 
	iSetTimer(50,Afire);
	iSetTimer(50,Efire);
	iSetTimer(50,change);
	dx=3;
	dy=4;
	 ebfx=750;
	 ebfy=eny4;
	if(music)
		PlaySound("dhakarpola.wav",NULL,SND_LOOP| SND_ASYNC);
	iInitialize(1000,750, "ANANTA-THE SAVIOR");

	iStart();


	return 0;
}

