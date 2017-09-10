#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
#include<sys/types.h>
#include<math.h>
#include<stdio.h>

void menu();
void game();
void game_info();
void distance();

void distance(int m,int n,int o,int p,int variable)//Closing Statement
	{
	char msg[128];
	int z =abs(m-o);
	int y =abs(n-p);
	if(sqrt(pow(z,2)+pow(y,2))<=35)//Condition to check if game over
	{
		int ch;
		cleardevice();
		while(1)
		{
		rectangle(100,100,500,400);
		outtextxy(220,150,"Congratulations");
		outtextxy(200,180,"You won the game!!!");
		sprintf(msg , "You finished the game in %d seconds" , variable); //Prints seconds in outtextxy
		outtextxy(180,200,msg);
		outtextxy(180,210,"Press escape to exit");
		outtextxy(180,220,"Press backspace to play again");
		outtextxy(180,300,"Thank you for playing our game :)");
		if(kbhit())
		{
			ch=getch();
			if(ch==27)//exit
			{
				exit(0);
			}
			if(ch==8)//backspace
			{
				game();
			}
		}
		}

	}
}


void game()
{
	int i=50,j=50,x=10,y=0,ch,flag=1,a,b,k=0,m=0;//Flag determines when the random object will be generated
	while(1)
		{
			rectangle(10,10,600,450);//Canvas
			if(flag==1)//Prints and object at first second
			{
				a=rand()%500;
				b=rand()%350;
				if(a<10)
				{
					a+=30;
				}
				if(b<10)
				{
					b+=30;
				}
				setfillstyle(SOLID_FILL,RED);
				circle(a,b,15);
				floodfill(a+1,b+1,WHITE);
			}
			setfillstyle(SOLID_FILL , GREEN);
			circle(i,j,15);//User controlled object
			floodfill(i+1,j+1,WHITE);
			if(kbhit())//Movement controlled by user
			{
				ch = getch();
				if(ch==72)//up
				{
					x=0;
					y=-10;
				}
				if(ch==80)//down
				{
					x=0;
					y=10;
				}
				if(ch==75)//right
				{
					x=-10;
					y=0;
				}
				if(ch==77)//left
				{
					x=10;
					y=0;
				}
				if(ch==27)//escape button
				{
					exit(0);
				}
			 }
			 if(flag%10==0)//Changing position of object after every 3 seconds
			 {
				a=rand()%500;
				b=rand()%350;
				if(a<10)//To generate ball inside canvas
				{
					a+=30;
				}
				if(b<10)
				{
					b+=30;
				}
				setfillstyle(SOLID_FILL,RED);
				circle(a,b,15);
				floodfill(a+1,b+1,WHITE);
			 }
			 setfillstyle(SOLID_FILL , RED);
			 circle(a,b,15);//Prints the object again and again so that it seems static
			 floodfill(a+1,b+1,WHITE);
			 //Movement of user controlled object
			 i=i+x;
			 j=j+y;
			 //Reflection
			 if(i>=585)
			 {
				i=i-x;
				x=-10;
			 }
			 if(j>=435)
			 {
				j=j-y;
				y=-10;
			 }
			 if(i<=25)
			 {
				i=i-x;
				x=10;
			 }
			 if(j<=25)
			 {
				j=j-y;
				y=10;
			 }
			//Count seconds played in game
			if(k%20==0)
			{
				m++;
			}
			//Call method to check if game over
			distance(a,b,i,j,m);
			//Delay in miliseconds to refresh screen
			delay(50);
			cleardevice();
			flag++;
			k++;
		}
}

void game_info()
{
	int ch;
	cleardevice();
	while(1)
	{
		rectangle(100,100,500,400);
		outtextxy(110,110,"This game is created by");
		outtextxy(110,120,"Mihir Chouhan and Zaid Farooqui of TE IT B.");
		outtextxy(110,130,"The creators of this game proudly present this"); 
		outtextxy(110,140,"game to you.");
		outtextxy(110,150,"We encourage everyone to pick this up and make"); 
		outtextxy(110,160,"it better in anyway possible.");
		outtextxy(110,170,"Any kind is piracy of this game is strictly"); 
		outtextxy(110,180,"encouraged.");
		outtextxy(110,190,"PS : All the lines have been written by the ");
		outtextxy(110,200,"creators themselves. ABSOLUTE ORIGINAL");
		outtextxy(250,260,"THANK YOU!!!!");
		outtextxy(110,320,"Press escape or backspace to go to previous page");
		if(kbhit())
		{
			ch=getch();
			if(ch==27 || ch==8)//Escape and Backspace button
			{
				menu();
			}
		}
	}
}


void menu()//Opening Statement
{
	int j=250,k=255,l=252,ch;
	while(1)
	{
		rectangle(100,50,500,450);//Canvas for introduction
		outtextxy(270,60,"Welcome!!");
		outtextxy(220,90,"Catch me if you can :)");
		rectangle(220,130,400,200);
		setfillstyle(SOLID_FILL,GREEN);
		circle(245,144,5);
		floodfill(246,145,WHITE);
		outtextxy(245,132,"Catcher");
		setfillstyle(SOLID_FILL,RED);
		circle(330,170,5);
		floodfill(331,171,WHITE);
		outtextxy(320,180,"Object");
		outtextxy(300,400,"An Original Created By -");
		outtextxy(300,410,"Mihir Chouhan (1514073)");
		outtextxy(300,420,"Zaid Farooqui (1514078)");

		outtextxy(245,250,"Start a new game");
		outtextxy(245,260,"Information about game");
		outtextxy(245,270,"Exit");
		outtextxy(240,330,"ALL THE BEST!!");
		outtextxy(230,350,"May the Force be with you");
		int triangle[8]={235,j,235,k,240,l,235,j};
		drawpoly(4,triangle);
		int y=0;
		if(kbhit())//Movement controlled by user
			{
				ch = getch();
				if(ch==72)//up
				{
					y=-10;
				}
				if(ch==80)//down
				{
					y=10;
				}
				if(ch==27)//escape button
				{
					exit(0);
				}
				if(ch==13)//Enter button
				{
					if(j==250)
					{
						 //Start a new game
						 game();
					}
					else if(j==260)
					{
						//Call for Game information
						game_info();
					}
					else if(j==270)
					{
						exit(0);
					}
				}
			}
			j+=y;
			k+=y;
			l+=y;
			delay(50);
			cleardevice();
	}

}

void main()
{
	int gd=DETECT,gm;
	clrscr();
	initgraph(&gd,&gm,"C://TC//BGI");

		//Initialize the menu of game
		menu();
		//Game starts
		game();
}
