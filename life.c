#include<stdio.h>
#include<time.h>

void drown(void* world,int w,int h)
{
	char (*World)[w]=world;

        for(int y=0; y<w ; y++)
        {
                for(int x=0;x<h;x++)
                {
                        printf("0");
                }
		printf("\n");
        }
}

void enviroment(void *world,int w,int h)
{
	char* new=world;
	
	for(int y=0; y<w ; y++)
	{
		for(int x=0;x<h;x++)
		{
			printf("0");
		}
		printf("\n");
	}
}

int main()
{
	//Initilze Value
	int w = 30;//Length Width
	int h = 30;//Length Hight
	char world[w][h];//My World
	
	//Initilize new Matrix World
	drown(world,w,h);
	
	//Check Life cell
	enviroment(world,w,h);

	return 0;
}
