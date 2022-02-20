#include<graphics.h>
#include<windows.h>

void board();
void round(int ,int);
void cross(int , int);
void symbol(int , int , int);
void banner();
void result(int);
void turn(int);

int main()
{
	
	int gd=DETECT, gm;
	initgraph(&gd, &gm,(char*)"");
	
	START:
	cleardevice();
	fflush(stdin);
	int cross_circle=0;
	char d;
	int board_index[3][3]={{11,22,33},{44,55,66},{77,88,99}};
	int sum;
	
	board();
	banner();
	
	while(true)
	{
		sum=0;
		turn(cross_circle);
		d=getch();
		
		if(d>='1'&&d<='9')
		{
			switch(d)
				{
					case '1':
						if(board_index[0][0]>10)
						{
							symbol(100,100,cross_circle);
							board_index[0][0]=cross_circle;
							cross_circle=1-cross_circle;
						}
						break;
					case '2':
						if(board_index[0][1]>10)
						{
							
							symbol(200,100,cross_circle);
							board_index[0][1]=cross_circle;
							cross_circle=1-cross_circle;
						}
						break;
					case '3':
						if(board_index[0][2]>10)
						{
							symbol(300,100,cross_circle);
							board_index[0][2]=cross_circle;
							cross_circle=1-cross_circle;
						}
						break;
					case '4':
						if(board_index[1][0]>10)
						{
							symbol(100,200,cross_circle);
							board_index[1][0]=cross_circle;
							cross_circle=1-cross_circle;
						}
						break;
					case '5':
						if(board_index[1][1]>10)
						{
							symbol(200,200,cross_circle);
							board_index[1][1]=cross_circle;
							cross_circle=1-cross_circle;
						}
						break;
					case '6':
						if(board_index[1][2]>10)
						{
							symbol(300,200,cross_circle);
							board_index[1][2]=cross_circle;
							cross_circle=1-cross_circle;
						}
						break;
					case '7':
						if(board_index[2][0]>10)
						{
							symbol(100,300,cross_circle);
							board_index[2][0]=cross_circle;
							cross_circle=1-cross_circle;
						}
						break;
					case '8':
						if(board_index[2][1]>10)
						{
							symbol(200,300,cross_circle);
							board_index[2][1]=cross_circle;
							cross_circle=1-cross_circle;
						}
						break;
					case '9':
						if(board_index[2][2]>10)
						{
							symbol(300,300,cross_circle);
							board_index[2][2]=cross_circle;
							cross_circle=1-cross_circle;
						}
						break;
				}
				
		}
		
		if((board_index[0][0]==board_index[0][1]&&board_index[0][1]==board_index[0][2])||(board_index[1][0]==board_index[1][1]&&board_index[1][1]==board_index[1][2])||(board_index[2][0]==board_index[2][1]&&board_index[2][1]==board_index[2][2])||(board_index[0][0]==board_index[1][0]&&board_index[1][0]==board_index[2][0])||(board_index[0][1]==board_index[1][1]&&board_index[1][1]==board_index[2][1])||(board_index[0][2]==board_index[1][2]&&board_index[1][2]==board_index[2][2])||(board_index[0][0]==board_index[1][1]&&board_index[1][1]==board_index[2][2])||(board_index[0][2]==board_index[1][1]&&board_index[1][1]==board_index[2][0]))
		{
			result(cross_circle);
			outtextxy(420,300,"Press R for restart");
			while(true)
			{
				char restart= getch();
				if(restart=='R'||restart=='r')
					goto START;
			}	
		}
		
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				sum+=board_index[i][j];
				
		
		if(sum<6)
		{
			outtextxy(500,260,"DRAW");
			outtextxy(420,300,"Press R for restart");
			while(true)
			{
				char restart= getch();
				if(restart=='R'||restart=='r')
					goto START;
			}
		}
	}
}

void board()
{
	line(50,50,350,50);
	line(50,50,50,350);
	line(50,350,350,350);
	line(350,50,350,350);
	line(150,50,150,350);
	line(250,50,250,350);
	line(50,150,350,150);
	line(50,250,350,250);
	outtextxy(100,120,"1");
	outtextxy(200,120,"2");
	outtextxy(300,120,"3");
	outtextxy(100,220,"4");
	outtextxy(200,220,"5");
	outtextxy(300,220,"6");
	outtextxy(100,320,"7");
	outtextxy(200,320,"8");
	outtextxy(300,320,"9");
}

void cross(int x, int y)
{
	line(x-45,y-45,x+45,y+45);
	line(x+45,y-45,x-45,y+45);
}

void round(int x, int y)
{
	circle(x,y,45);
}

void symbol(int x, int y, int cross_circle)
{
	if(cross_circle)
		cross(x,y);
	else
		round(x,y);
		
}

void banner()
{
	bar(360, 50, 600, 350);
	outtextxy(450,70,"TIC-TAC-TOE");
	outtextxy(400,260,"RESULT:");
}

void result(int cross_circle)
{
	if(cross_circle)
		outtextxy(500,260,"O WINS");
	else
		outtextxy(500,260,"X WINS");
}

void turn(int cross_circle)
{
	if(cross_circle)
		outtextxy(440,170,"X'S TURN");
	else
		outtextxy(440,170,"O'S TURN");
}

