#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>

void draw(void* wrd,int w,int h)
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

void evolution(void* wrd,int w,int h)
{
	char (*world)[w]=wrd;
	char newWorld[h][w];

	for(int x=0; x<w ; x++)
	{
		for(int y=0; y<h;y++)
		{
			//state cell live count
			int live = 0;

			for(int xi=x-1; xi<=x+1; xi++)
				for(int yi=y-1; yi<=y+1; yi++)
					if(world[(yi+h)%h][(xi+w)%w])
						live++;
			if(world[y][x])
				live--;

			newWorld[y][x] = (live == 3 || (live==2 && world[y][x]));
		}
	}

	//world = newWorld;
	for(int y=0; y<h; y++)
		for(int x=0; x<w; x++)
			world[y][x]=newWorld[y][x];
}

int main()
{
	//Initilze Value
	int w = 60;//Length culomns
	int h = 60;//Length rows
	char world[h][w];//My World

	//Initilize new Matrix World
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			world[i][j] = rand() < RAND_MAX / 10;

	for(;;)
	{
		//Show State matrix
		draw(world,w,h);

		//Check Life cell
		evolution(world,w,h);

		//sleep 1s
		usleep(1000000);
	}

	return 0;
}
