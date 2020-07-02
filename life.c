#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>

void drow(void* wrd,int w,int h)
{
	//Temp World
	char (*world)[w]=wrd;

	//Clear Terminal
	printf("\033[H");

        for(int y=0; y<h ; y++)
        {
                for(int x=0;x<w;x++)
                {
                        printf(world[y][x]? "*" : " ");
                }
		printf("\n");
        }
}

void evolution(void *wrd,int w,int h)
{
	char (*world)[w]=wrd;
	char newWorld[h][w];

	for(int y=0; y<h ; y++)
	{
		for(int x=0;x<w;x++)
		{
			//state cell live count
			int live = 0;

			for(int yi=y-1; yi<y+1; yi++)
				for(int xi=x-1; xi<x+1; xi++)
					if(world[(yi+h)%h][(xi+w)%w])
						live++;
			if(world[y][x])
				live--;

			newWorld[y][x] = (live == 3 || (live==2 && world[y][x]));
		}
	}

	world = newWorld;
}

int main()
{
	//Initilze Value
	int w = 30;//Length culomns
	int h = 30;//Length rows
	char world[h][w];//My World

	//Initilize new Matrix World
	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
			world[i][j]=rand() < RAND_MAX / 10 ? 1 : 0 ;

	for(;;)
	{
		//Show State matrix
		drow(world,w,h);

		//Check Life cell
		evolution(world,w,h);

		//sleep 1s
		usleep(1000000);
	}

	return 0;
}
