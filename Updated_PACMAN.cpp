#include <graphics.h>
#include<conio.h>
#include <stdlib.h>
#include<dos.h>
#include<bits/stdc++.h>
using namespace std;

int m_right(int &a,int &b,int &c);
int m_left(int &a,int &b,int &c);
int m_up(int &a,int &b,int &c);
int m_down(int &a,int &b,int &c);
void grid();
void mapp();
void *ghost(void *threadid);
void *navu_pshs(void *threadid);
char key;

int a,b,c,d,e,gx,gy,x,y,l,k;
int main(void)
{
	initwindow(640,480,"");
	setcolor(0);
	outtextxy(100,240,"PAKABHAI ARRIVING SHORTYLY!");
	settextstyle(3,0,1);
	grid();
	a=320;
	b=240;
	int c=0;
	int d=480;
	int e=640;
	gx=600;
	gy=50;
	key='w';
	cout<<"MAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAINMAIN"<<endl;
	pthread_t threads[2];
	while(1)
	{
		pthread_create(&threads[1], NULL, ghost,(void *)1);
		cout<<"\n*-----------------------*-*-*-*-*-*GHOST:"<<"("<<gx<<","<<gy<<")-*-*-*-*-*-*-*";
		delay(10);
		pthread_create(&threads[0], NULL, navu_pshs,(void *)1);
		cout<<"\n-------------------------*-*-*-*-*-*-*Pako:"<<"("<<x<<","<<y<<")*-*-*-*-*-*-*-*-**";
		delay(10);
		if(x==gx && y==gy){
			settextstyle(3,0,6);
				setcolor(15);
				outtextxy(150,200,"GAME OVER");
				delay(1000);
				setcolor(10);
				outtextxy(150,200,"GAME OVER");
				delay(1000);
				setcolor(9);
				outtextxy(150,200,"GAME OVER");
				delay(1000);
				setcolor(8);
				outtextxy(150,200,"GAME OVER");
				delay(1000);
				exit(0);	
		}
	
	}
	   pthread_exit(NULL);
	getch();
	return 0;
}

void *navu_pshs(void *threadid)
{
	cout<<"PAKPAKPAKPAK : "<<key<<endl;
	switch(key)
	{
		case 'w':
			m_up(a,b,c);
			break;
		case 'a':
			m_left(a,b,c);
			break;
		case 's':
			m_down(a,b,d);
			break;
		case 'd':
			m_right(a,b,e);
			break;
		default:
			settextstyle(3,0,6);
			setcolor(15);
			outtextxy(150,200,"GAME OVER");
			delay(1000);
			setcolor(10);
			outtextxy(150,200,"GAME OVER");
			delay(1000);
			setcolor(9);
			outtextxy(150,200,"GAME OVER");
			delay(1000);
			setcolor(8);
			outtextxy(150,200,"GAME OVER");
			delay(1000);
			exit(0);	
	}
}
//=========FUNCTION FOR GRID FORMATION============//
void grid()
{ 
	setcolor(9);
	mapp();
}
//=============FUNTION FOR MOVING RIGHT========//
int m_right(int &a,int &b,int &c)
{
int s,e;
s=30,e=330;
int k=a ;
k=k+2;

	if(s==0)
	{
		s=30;e=330;
	}
	if(k==c-19)
	{
		key='d';
		a=0;
		b=b;
		return 0;
	}
	if(kbhit())
	{
		a=k;
		b=b;
		cout<<"------------------------>KBHIT";
		key=getch();
//		return 0;
	}
	if(getpixel(k+20,b)==2 || getpixel(k+20,b+20)==2 || getpixel(k+20,b-20)==2)
	{
		a=k-2;
		b=b;
		key=getch();
		return 0;
	}
	x = k;
	y = b;
	cout<<"\nFORRRRRRRRRRRRRRRRRRRR(k,b)->("<<k<<","<<b<<")-----------------(a,l)->("<<a<<","<<l<<")";
	ghost((void *)1);
	setfillstyle(SOLID_FILL,14);
	pieslice(k,b,s,e,18);
	setfillstyle(SOLID_FILL,0);
	pieslice(k,b-10,0,360,5);
	setcolor(0);
	circle(k+1,b,18);
	s=s-1;e=e+1;
}

//=========FUNCTION FOR MOVING LEFT===========//
int m_left(int &a,int &b,int &c)
{
int s,e;
s=150,e=210;
int k=a;
k=k-2;

	if(s==180)
	{
		s=150;e=210;
	}
	if(k==c+19)
	{
		key='z';
		return 0;
	}
	if(kbhit())
	{
		a=k;
		b=b;
		cout<<"------------------------>KBHIT";
		key=getch();
//		return 0;
	}
	if(getpixel(k-20,b)==2 || getpixel(k-20,b+20)==2 || getpixel(k-20,b-20)==2)
	{
		a=k+2;
		b=b;
		key=getch();
		return 0;
	}
	x = k;
	y = b;
		cout<<"\nFORRRRRRRRRRRRRRRRRRRR(k,b)->("<<k<<","<<b<<")-----------------(a,l)->("<<a<<","<<l<<")";
	ghost((void *)1);
	setfillstyle(SOLID_FILL,14);
	pieslice(k,b,e,s,18);
	setfillstyle(SOLID_FILL,0);
	pieslice(k,b-11,0,360,5);
	setcolor(0);
	circle(k-1,b,18);
	s=s+1;e=e-1;
	
}


//========FUNCTION FOR MOVING UP=============//
int m_up(int &a,int &b,int &c)
{ 
int s,e;
s=60,e=120;
int l=b;
l=l-2;
	{
		if(s==90)
		{
			s=60;e=120;
		}
		if(l==(c+19))
		{
			key='z';
			return 0;
		}
		if(kbhit())
		{
			a=a;
			b=l;
			cout<<"------------------------>KBHIT";
			key=getch();
//			return 0;
		}
		if(getpixel(a,l-20)==2 || getpixel(a+20,l-20)==2 || getpixel(a-20,l-20)==2)
		{
			a=a;
			b=l+2;
			key=getch();
			return 0;
		}
		x = a;
		y = l;
			cout<<"\nFORRRRRRRRRRRRRRRRRRRR(k,b)->("<<k<<","<<b<<")-----------------(a,l)->("<<a<<","<<l<<")";
		ghost((void *)1);
		setfillstyle(SOLID_FILL,14);

		pieslice(a,l,e,s,18);
		setfillstyle(SOLID_FILL,0);
		pieslice(a-11,l,0,360,5);
		setcolor(0);
		circle(a,l-1,18);
		s=s+1;e=e-1;
			
	}
}

//========FUNCTION FOR MOVING DOWN==============//
int m_down(int &a,int &b,int &c)
{ 
	int s,e;
	s=240,e=300;
int l=b;
l=l+2;
	{
		if(s==270)
		{
			s=240;e=300;
		}
		if(l==(c-19))
		{
			key='z';
			return 0;
		}
		if(kbhit())
		{
			a=a;
			b=l;
			cout<<"------------------------>KBHIT";
			key=getch();
//			return 0;
		
		}
		if(getpixel(a,l+20)==2 || getpixel(a-20,l+20)==2 || getpixel(a+20,l+20)==2)
		{
			a=a;
			b=l-2;
			key=getch();
			return 0;
		}	
		x = a;
		y = l;	
			cout<<"\nFORRRRRRRRRRRRRRRRRRRR(k,b)->("<<k<<","<<b<<")	-----------------(a,l)->("<<a<<","<<l<<")";
		ghost((void *)1);
		setfillstyle(SOLID_FILL,14);
		pieslice(a,l,e,s,18);
		setfillstyle(SOLID_FILL,0);
		pieslice(a-11,l,0,360,5);
		setcolor(0);
		circle(a,l+1,18);
		s=s+1;e=e-1;
		
	}
}


void *ghost(void *threadid)
{
	
	cout<<"GHOST_GHOST_GHOST"<<endl;
	if(getpixel(gx+19,gy)==2 || getpixel(gx+19,gy-19)==2 ||getpixel(gx+19,gy+19)==2 || getpixel(gx,gy+19)==2 || getpixel(gx,gy-19)==2 || getpixel(gx-19,gy)==2 || getpixel(gx-19,gy-19)==2 || getpixel(gx-19,gy+19)==2) 
	{
	
	if(gx<x)
	{
		if(gy<y)//ghost e pacman ni upar ni baju left side che-> so e pehla right side javano try karse
		{
			if(getpixel(gx+19,gy)==2 || getpixel(gx+19,gy-19)==2 ||getpixel(gx+19,gy+19)==2)//ghost na right side javana path ma wall che
			{
				if(getpixel(gx,gy+19)==2 || getpixel(gx-19,gy+19)==2)//getpixel(gx+19,gy+19)==2 || ghost ni niche ni side java ma wall che
				{
					if(getpixel(gx,gy-19)==2 || getpixel(gx-19,gy-19)==2)//getpixel(gx+19,gy-19)==2 || upar ni side wall ayi
					{
						if(getpixel(gx-19,gy)==2)//getpixel(gx-19,gy+19)==2 ||  || getpixel(gx-19,gy-19)==2)//left side wall ayi
						{
							
						}
						else
						{
							gx=gx-1;
						}
					}
					else
					{
						gy=gy-1;
					}
				}
				else
				{
					gy=gy+1;
				}								
			}
			else
			{
				gx=gx+1;
			}
		}
		else//ghost e pacman ni niche ni baju left side che ->so e pehla right side javano try karse->pachi jo tya diwal hase to upar ->niche->left
		{
			if(getpixel(gx+19,gy)==2 || getpixel(gx+19,gy-19)==2 ||getpixel(gx+19,gy+19)==2)//ghost na rght side javana path ma wall che
			{
				if(getpixel(gx,gy-19)==2 || getpixel(gx-19,gy-19)==2)//getpixel(gx+19,gy-19)==2 || upar ni side wall ayi
				{
					if(getpixel(gx,gy+19)==2 || getpixel(gx-19,gy+19)==2)//getpixel(gx+19,gy+19)==2 ||ghost ni niche ni side java ma wall che
					{
						if(getpixel(gx-19,gy)==2)//getpixel(gx-19,gy+19)==2 ||  || getpixel(gx-19,gy-19)==2)//left side wall ayi
						{
							
						}
						else
						{
							gx=gx-1;
						}
					}
					else
					{
						gy=gy+1;
					}
				}
				else
				{
					gy=gy-1;
				}
			}
			else
			{
				gx=gx+1;
			}
		}
	}
	if(gx>x)//ghost pacman ni right side che
	{
		if(gy<y)//ghost pacman ni upar ni baju and right side che so firrst e left javano try karse->niche->upar->right
		{
			if(getpixel(gx-19,gy+19)==2 || getpixel(gx-19,gy)==2 || getpixel(gx-19,gy-19)==2)//left side wall ayi
			{
				if(getpixel(gx+19,gy+19)==2 || getpixel(gx,gy+19)==2) //*|| getpixel(gx-19,gy+19)==2*/)//ghost ni niche ni side java ma wall che
				{
					if(getpixel(gx+19,gy-19)==2 || getpixel(gx,gy-19)==2) //*|| getpixel(gx-19,gy-19)==2*/)//upar ni side wall ayi
					{
						if(getpixel(gx+19,gy)==2 )//*|| getpixel(gx+19,gy-19)==2 ||getpixel(gx+19,gy+19)==2*/)//ghost na rght side javana path ma wall che
						{
							
						}
						else
						{
							gx=gx+1;
						}
					}
					else
					{
						gy=gy-1;
					}
				}
				else
				{
					gy=gy+1;
				}
			}
			else
			{
				gx=gx-1;
			}
		}
		else//ghost e pacman ni niche ni side and right side che so pehla e left avse ->upar->niche->right
		{
			if(getpixel(gx-19,gy+19)==2 || getpixel(gx-19,gy)==2 || getpixel(gx-19,gy-19)==2)//left side wall ayi
			{
				if(getpixel(gx+19,gy-19)==2 || getpixel(gx,gy-19)==2)// || getpixel(gx-19,gy-19)==2)//upar ni side wall ayi
				{
					if(getpixel(gx+19,gy+19)==2 || getpixel(gx,gy+19)==2)// || getpixel(gx-19,gy+19)==2)//ghost ni niche ni side java ma wall che
					{
						if(getpixel(gx+19,gy)==2)// || getpixel(gx+19,gy-19)==2 ||getpixel(gx+19,gy+19)==2)//ghost na rght side javana path ma wall che
						{
							
						}
						else
						{
							gx=gx+1;
						}
					}
					else
					{
						gy=gy+1;
					}
				}
				else
				{
					gy=gy-1;
				}
			}
			else
			{
				gx=gx-1;
			}
		}
	}
	}
	else
	{
		if(abs(gx-x)>abs(gy-y))
		{
			if(gx>x)
			{
				gx=gx-1;
			}
			else
			{
				gx=gx+1;
			}
		}
		else
		{
			if(gy>y)
			{
				gy=gy-1;
			}
			else
			{
				gy=gy+1;
			}
		}
	}
	setfillstyle(SOLID_FILL,4);
	pieslice(gx,gy,30,330,18);
	//delay(10);
}

void mapp()
{
	setcolor(2);
	int arr[]={80,80,80,120,120,120,120,160,160,160,160,120,200,120,200,80,80,80};
	setfillstyle(8,1);
	fillpoly(9,arr);
	bar(240,40,280,120);
	rectangle(240,40,280,120);
//	line(200,160,280,160);
	int arr1[]={360,80,440,80,440,120,400,120,400,160,320,160,320,120,360,120,360,80};
	fillpoly(9,arr1);
	int arr2[]={480,40,560,40,560,120,520,120,520,80,480,80,480,40};
	fillpoly(7,arr2);
	bar(40,200,120,240);
	rectangle(40,200,120,240);
	bar(200,200,280,240);
	rectangle(200,200,280,240);
	bar(360,200,440,240);
	rectangle(360,200,440,240);
	bar(520,200,600,240);
	rectangle(520,200,600,240);
//	line(480,160,480,280);
//	line(440,280,480,280);
//	line(40,280,80,280);
//	line(200,320,280,320);
	int arr3[]={120,320,160,320,160,360,200,360,200,400,80,400,80,360,120,360,120,320};
	fillpoly(9,arr3);
//	line(280,400,280,440);
	int arr4[]={320,320,400,320,400,400,360,400,360,360,320,360,320,320};
	fillpoly(7,arr4);
    int arr5[]={520,320,560,320,560,400,480,400,480,360,520,360,520,320};
    fillpoly(7,arr5);
    rectangle(0,0,640,480);
    rectangle(1,1,639,479);
    rectangle(2,2,638,478);
}
