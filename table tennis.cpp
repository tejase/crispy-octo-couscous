#include <graphics.h>
#include <dos.h>
#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<sys/types.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#define M 1 //make this 1 if u want player 1 as a bot else keep it 0
#define N 1 //make this 1 if u want to enable player 2 as a bot else 0
#define R 45 //alter this value for controlling the angle
char xyz[100],xyz1[100];char hs[100];
int x1=392,end=0,x2=0;
int bigflag=0;
time_t t;
struct bat

{
 int length;
 int width;
 int xcoordinate;
 int new_ycoordinate;
 int old_ycoordinate;
}batA, batB; 

struct ball
{
  int radius;
  int speedx;
  int speedy;
  int old_xcenter;
  int old_ycenter;
  int new_xcenter;
  int new_ycenter;
}ball1;

struct score
{
  int score_A;
  int score_B;
 

}score_game;





void commencegame()
{
    /*outtextxy (237,80,"A,D (player 1)    J,K (player2)");
    delay(1000);
     setfillstyle (2,0);
    outtextxy (237,99,"9");
    printf("\a");
    delay(1000);
     setfillstyle (1,0);
    outtextxy (237,99,"8");
    printf("\a");
    delay(1000);
     setfillstyle (1,0);
    outtextxy (237,99,"7");printf("\a");
    delay(1000);
     setfillstyle (1,0);
    outtextxy (237,99,"6");printf("\a");
    delay(1000);
     setfillstyle (1,0);
    outtextxy (237,99,"5");printf("\a");
    delay(1000);
     setfillstyle (1,0);
    outtextxy (237,99,"4");printf("\a");
    delay(1000);
     setfillstyle (1,0);
    outtextxy (237,99,"3");printf("\a");
    delay(1000);
     setfillstyle (1,0);
    outtextxy (237,99,"2");printf("\a");
    delay(1000);
     setfillstyle (1,0);
    outtextxy (237,99,"1");printf("\a");
    setfillstyle (1,0);
    outtextxy (237,99,"ROCK AND ROLL AMIGO!!!!");
    delay(1000);
    cleardevice();*/
    int x,y,i;
    x=getmaxx()/2;
    y=getmaxy()/2;
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
    setcolor(4);
    int c=150;
    for(int e=0;e<30;e++)
    {
    	for(int i=50;i<100;i++)
    	{
    		setcolor(3);
    		settextstyle(SMALL_FONT,HORIZ_DIR,10);
    		outtextxy(x,y,"loading");
    		settextstyle(SMALL_FONT,HORIZ_DIR,5);
    		outtextxy(x+5,y+5,"Please wait");
    		circle(x,y,i);
    		circle(x,y,c);
    		c--;
    		cleardevice();
		}
	}
	//----- geting player names :)
	int flag=0;
	slayer:
	if(flag==0) setcolor(GREEN);
	else setcolor(BLUE);
	 setbkcolor(0);
	 //printing face
	   
	  ellipse(298,244,160,380,60,80);
	   

			    
	ellipse(280,220,270,0,10,40); 
	ellipse(315,220,180,270,10,40); 
	ellipse(285,260,100,285,8,7);
	ellipse(310,260,255,70,8,7);
	circle(320,230,2); 
	circle(275,230,2);
	arc(297,257,228,689,15); 
	ellipse(298,290,0,360,30,7); 
	line(270,290,326,290);  
	ellipse(234,240,0,330,4,20); 
	ellipse(362,240,220,170,4,20);
	if(flag==0) 		outtextxy(450,250,"P1 ENTER NAME (7 letters must)");
	else     outtextxy(450,250,"P2 ENTER NAME (7 letters must)");
					char q[100],ch[2];
					int p;
					for(p=0;p<7;p++)
					{
						ch[0]=getch();
						if(ch[0]!=13)
						{	
							q[p]=ch[0];
							ch[1]='\0';
							outtextxy(500+8*p,290,ch);
						}		
						else
							break;
					}
					q[p]='\0';
					if(flag==0) strcpy(xyz,q);
					else strcpy(xyz1,q);
					if(flag==0) outtextxy(500,290,xyz);
					else outtextxy(500,290,xyz1);
					 getch();  
					 if(flag==0) 
					 {
					 	flag++;
					 goto slayer;
				}
    
}



void initialize () // Initialize the game.

{
 	int gdriver = DETECT, gmode;
 	 char tempstring [10]; //holds score in char
 	 time_t t;// Used to generate random number from system time.
 	 closegraph ();
 	 initgraph(&gdriver, &gmode, " "); // Intializes Graphics
  
 	 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);

 	//bat a init
 	batA.length = 80;
 	batA.width = 2;
 	batA.xcoordinate = 20;
 	batA.new_ycoordinate = 237;
 	batA.old_ycoordinate = 237;

 	// b init
 	batB.length = 80;
 	batB.width = 2;
 	batB.xcoordinate = 620;
 	batB.new_ycoordinate = 237;
 	batB.old_ycoordinate = 237;

 	// ball init
 	ball1.radius = 10;
 	ball1.speedx = 20;
 	srand((unsigned ) time(&t)); 
 	ball1.speedy = rand ()%R;// setting random speed.
 	if (rand() % 2 == 0)
  {
    	ball1.speedx = - ball1.speedx; // Generate Random X direction.
    	ball1.speedy = - ball1.speedy; // Generate Random Y direction.
  }
 	ball1.old_xcenter = 320;
 	ball1.old_ycenter = 250;
 	ball1.new_xcenter = 320;
 	ball1.new_ycenter = 250;
 	// Intialise Score
 	//score_game.score_A = 0;
 	//score_game.score_B = 0;

 	//set center
 	// Set Background to white
 	circle(ball1.new_xcenter,ball1.new_ycenter,45);
 	
 	setbkcolor (BLACK);
	
 	// Draw Ball at Initial Position
 	setfillstyle (1,15);
 	fillellipse (ball1.new_xcenter,ball1.new_ycenter,ball1.radius,ball1.radius);

 	// Draw Bats at Intial Position
 	bar (batA.xcoordinate,batA.new_ycoordinate,batA.xcoordinate+batA.width,batA.new_ycoordinate+batA.length);
 	bar (batB.xcoordinate,batB.new_ycoordinate,batB.xcoordinate+batB.width,batB.new_ycoordinate+batB.length);
	
 	// Display Score
	// textcolor ();
	setcolor(3);
 	sprintf (tempstring,"%s - %d",xyz,score_game.score_A);
 	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
 	outtextxy (10,400,tempstring);
 	sprintf (tempstring,"%s - %d",xyz1,score_game.score_B);
 	settextstyle(SMALL_FONT,HORIZ_DIR,8);
 	outtextxy (420,400,tempstring);
 	outtextxy (40,470,"By Tejas E");
 	if(bigflag==1) 
 	{
 		outtextxy(300,200,hs);
 		setfillstyle (1,0); // Remove last postion.
 	}
 	
}	
seconds()
{
	int n; 
	cleardevice();
	outtextxy(getmaxx()/2,getmaxy()/2,"Enter number of min u want to play!");
	//scanf("%d",&n);
	n=getch();
	n=n-48;
	x1=n*x1;
}
highscore()
{
	int highscore,flag=0;
	if(score_game.score_A>score_game.score_B) 
		highscore=score_game.score_A;
	else 
		highscore = score_game.score_B;
	FILE*p = fopen("hs.txt","r");
	int x;
	fscanf(p,"%d",&x);
	printf("%d        ",x);
	fclose(p);
	FILE*pt = fopen("hs.txt","w");
	if(highscore>x)
	{	
 		flag=1;
 		fprintf(pt,"%d",highscore);
 		bigflag=1;
 		if(score_game.score_A>score_game.score_B)
			 sprintf(hs,"high score!! ( %s ) %d",xyz,highscore);
 		else 
 			sprintf(hs,"high score!! (%s) %d",xyz1,highscore);
	}	
	else 
	{
	
		bigflag=1;
		if(score_game.score_A>score_game.score_B)
			sprintf(hs,"WINNER %s -%d",xyz,highscore);
		else 
			sprintf(hs,"WINNER %s -%d",xyz1,highscore);	
	}	
	fclose(pt);
	//fseek(fptr, 0, SEEK_SET);


	char temph[100];
	sprintf(temph,"%d",x);
	outtextxy(400,400,temph);
	if(flag==1)
		printf("%d-highesttttt",highscore);
	else
		 printf("%d",x);
	initialize();
}

void movebat (char input)

{
 	switch (input)
   	{
    	           case 'A' :
    	            		if (batA.new_ycoordinate > 0) // Move only when bat is not touching the top so it doesnt jump out of screen.
    	              		{
    		            	      //printf("a"); (just chacked if it was working :))
            		    	    batA.old_ycoordinate = batA.new_ycoordinate;
            		    	    batA.new_ycoordinate=batA.new_ycoordinate-10;// --;batA.new_ycoordinate --;batA.new_ycoordinate --;batA.new_ycoordinate --;batA.new_ycoordinate --;
                			    setfillstyle (1,0); // Remove last postion
                    			setcolor(4);
                    			bar (batA.xcoordinate,batA.old_ycoordinate,batA.xcoordinate+batA.width,batA.old_ycoordinate+batA.length);
                    			setcolor(4);
                   			 	setfillstyle (1,15); // Display New postion.
                   				bar (batA.xcoordinate,batA.new_ycoordinate,batA.xcoordinate+batA.width,batA.new_ycoordinate+batA.length);
                   				break;
                  			}

               case 'S' :
               			if (batA.new_ycoordinate+batA.length < 480) // Make sure bat doesnot go below the screen.
                  		{
                    			batA.old_ycoordinate = batA.new_ycoordinate;
                    			batA.new_ycoordinate =batA.new_ycoordinate+10;//batA.new_ycoordinate ++;batA.new_ycoordinate ++;batA.new_ycoordinate ++;batA.new_ycoordinate ++;
                    			setfillstyle (1,0); // Remove last postion.
                    			bar (batA.xcoordinate,batA.old_ycoordinate,batA.xcoordinate+batA.width,batA.old_ycoordinate+batA.length);
                    			setfillstyle (1,15); // Display New postion.
                    			bar (batA.xcoordinate,batA.new_ycoordinate,batA.xcoordinate+batA.width,batA.new_ycoordinate+batA.length);
                    			break;
                   		}

              case 'J' :
               			if (batB.new_ycoordinate > 0) // Move only when bat is not touching the top so it doesnt jump out of screen.
                		 {
                   				batB.old_ycoordinate = batB.new_ycoordinate;
                   				batB.new_ycoordinate=batB.new_ycoordinate-10; //;batB.new_ycoordinate --;batB.new_ycoordinate --;batB.new_ycoordinate --;batB.new_ycoordinate --;
                   				setfillstyle (1,0); // Remove last postion.
                   				bar (batB.xcoordinate,batB.old_ycoordinate,batB.xcoordinate+batB.width,batB.old_ycoordinate+batB.length);
                   				setfillstyle (1,15); // Display New postion.
                   				bar (batB.xcoordinate,batB.new_ycoordinate,batB.xcoordinate+batB.width,batB.new_ycoordinate+batB.length);
                   				break;
                 		}

              case 'K' :
              			if (batB.new_ycoordinate+batB.length < 480) // Make sure bat doesnot go below the screen.
                		{
                  				batB.old_ycoordinate = batB.new_ycoordinate;
                  				batB.new_ycoordinate =batB.new_ycoordinate+10;//batB.new_ycoordinate ++;batB.new_ycoordinate ++;batB.new_ycoordinate ++;batB.new_ycoordinate ++;
                  				setfillstyle (1,0); // Remove last postion.
                  				bar (batB.xcoordinate,batB.old_ycoordinate,batB.xcoordinate+batB.width,batB.old_ycoordinate+batB.length);
                  				setfillstyle (1,15); // Display New postion.
                  				bar (batB.xcoordinate,batB.new_ycoordinate,batB.xcoordinate+batB.width,batB.new_ycoordinate+batB.length);
                  				break;
                		}

   }

}
void moveball ()

{
	//static int x1=50000;
  	ball1.old_xcenter = ball1.new_xcenter;
  	ball1.old_ycenter = ball1.new_ycenter;
  	ball1.new_xcenter = ball1.new_xcenter + ball1.speedx;
 	ball1.new_ycenter = ball1.new_ycenter + ball1.speedy;
  	setcolor (0);
  	setfillstyle (1,0);// Remove last postion.
  	setcolor (8);
  	circle(320,250,45);
  	setcolor (0);
  	fillellipse (ball1.old_xcenter,ball1.old_ycenter,ball1.radius,ball1.radius);
  	setcolor (8);
  	circle(320,250,45);
  	setcolor (0);
  	setfillstyle (7,14); // Display New postion.
 	fillellipse (ball1.new_xcenter,ball1.new_ycenter,ball1.radius,ball1.radius);
 	 if ( ball1.new_ycenter - ball1.radius < 0 ) 
  		ball1.speedy = -ball1.speedy; // Reflect From Top
  	if ( ball1.new_ycenter + ball1.radius > 430 )
	  	ball1.speedy = -ball1.speedy; // Reflect From Bottom
	  	printf("%d ",x1);
	  	system ("cls");
	  	
	x1--;
	if(x1<5) printf("/a");
	if(x1==0) 
	{
		end++;
		x1=='q';
		printf("%d",end);

	}
		printf("   //%d",x1);
	}
void physics ()

{
  	char tempstring [10];//score
  	if ( ball1.new_xcenter - ball1.radius <= 20)
  	   {
    	     if (ball1.new_ycenter > batA.new_ycoordinate && ball1.new_ycenter < batA.new_ycoordinate+batA.length)
        	    {
           		    ball1.speedx = - ball1.speedx;
           		    ball1.speedy = rand () % R;// Sets speed from 0 to 2 
               		if (rand() % 2 == 0) ball1.speedy = - ball1.speedy; // Generate Random Y direction.
             	}
          	else // Reintialize entire game with new score
            	 {
               		score_game.score_B ++;
               		printf("\a");
               		initialize ();
             	}
          return;
      }

  if ( ball1.new_xcenter +  ball1.radius > 620)

      {
         	if (ball1.new_ycenter > batB.new_ycoordinate && ball1.new_ycenter < batB.new_ycoordinate+batB.length)
          	{
           		ball1.speedx = - ball1.speedx;
            	ball1.speedy = rand ()%R;// Sets speed from 0 to 2 
            	if (rand() % 2 == 0)
					ball1.speedy = - ball1.speedy; // Generate Random Y direction.
           }
         	else // Reintialize game with new score
        	{
           		score_game.score_A ++;
           		initialize ();
          	}
           return;
       }
      
	
       
}
remainingsec()
   {
   		//static int x=0;
   		char temp1[100];
   		sprintf(temp1,"%d",x2);
		char temp[500];
 		sprintf(temp,"%d",x1);
 		setcolor(4);
 		if((x1%6)==0) {
		 outtextxy(320,250,temp1);
		setfillstyle (1,0); // Remove last postion.
		//if((x1%6)==0)  outtextxy(400,200,temp1);
		x2++;
	}
	}
	void sp()
	{
}

	
	void play () // Our Budding Game Engine
	
	{
	//	#include<windows.h>
	    //trying fork
	    //didnt workout
	    // Check wether key press is Q if so exit loop
	   char x; int i=0;
	 /*  while(!_kbhit())
	   {
	   
	   i++;
	   if(i>0)
	   {
	   
	   x='h';
	   break;
	}*/
	   	
	
	    x=getch();
	    
	
	    while (x!='q')
	    {
	    	//delay (10);
			// x=getch();
		
	     	delay(10);
	    while(kbhit())
	   	{
	   
	   		i++;
	   		x=getch();
	   			if(end==1) break;
	   		goto tejas;
	   		if(i>20)
	   		{  
	   			x='h';
	   			break;
			}
		}
			if(end==1) x='q';
			if(end==1) break;
		x='h';	
		//x=getch();
		tejas:
      if (x=='a')
	  		movebat ('A');
      if (x=='s')
	  		movebat ('S');
      if (x=='j')
	  		movebat ('J');
      if (x=='k')
	  		movebat ('K');
	  		//-------------------------------------
	  		
		
	  remainingsec();
      moveball ();
      //-----------------------------------------
       if(M)
       {
	   
       	if( ( (batA.new_ycoordinate+(batA.length/2))-ball1.new_ycenter) > 0 )
       	
	{
		movebat('A')	;
		movebat('A')	;
		movebat('A')	;
	}
	else if(ball1.new_ycenter<(batA.new_ycoordinate+(batA.length))&& ball1.new_ycenter>(batA.new_ycoordinate))
	{
		movebat('h');
	}
	else {
		movebat('S');
		movebat('S');
		movebat('S');
	}
	if(N)
	{
		
	 if(ball1.new_ycenter<(batB.new_ycoordinate+(batB.length))&& ball1.new_ycenter>(batB.new_ycoordinate))
	{
		movebat('h');
	}
	
	else if(((batB.new_ycoordinate+(batB.length/2))-ball1.new_ycenter)>0)
	{
		movebat('J');
		movebat('J');
		movebat('J');
	}
	else {
		movebat('K');
	//	movebat('K');
		movebat('K');
	}
}
	}
      
      physics ();
      sp();
    }
}



int main ()

{
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode,  " "); // Intializes Graphics
	score_game.score_A=score_game.score_B=0;

	commencegame();
//	printf("Enter number of min u want to play");
	
	
	seconds();
	initialize ();

	play ();                                   // Game Engine
	gethere:

	highscore();

	getch();
	getch();
	getch();
	closegraph ();                            // Close Graphics
	return 0;
}