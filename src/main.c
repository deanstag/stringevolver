/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  main file of string evolver algorithm
 *
 *        Version:  1.0
 *        Created:  Monday 08 November 2010 09:29:58  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  MIKHAIL (), deanstag@gmail.com
 *        Company:  User
 *
 * =====================================================================================
 * */
#include <time.h>

int generatechar()
{

    return rand()%3+'a';
}

int fitness(char *a,char *b)
{
    int i=0;int c=0;
    while(*a!='\0'&&*b!='\0')
    {
        if(*a==*b)
        c++;

        a++;
        b++;
    }
    return c;
}

void mutate(char *a)
{
    a[rand()%10] = generatechar();

}




int main (int argc, char const* argv[])
{
	int i,j,flag=1,maxm=0,m,n,gen = 0;
	char ref[11]="abcccabccc";
	char population[10][11];
	srand(time(NULL));
	for( i = 0; i < 10; i += 1)
	{
	for(j = 0; j < 10; j += 1)
	{
		population[i][j]=generatechar();
		
	}
	population[i][10]='\0';
	printf("\nString no:%d-%s",i,population[i]);
	}

	while(flag)
	{
	    gen++;
	    printf("\nGeneration:%d",gen);
		for(i = 0;i<10;i+=2)
		{
			m=fitness(population[i],ref);
			maxm = m>maxm?m:maxm;
			n=fitness(population[i+1],ref);
			maxm = n>maxm?n:maxm;
			if(m>n)
			{
				strcpy(population[i+1],population[i]);
			}
			else
			{
			    strcpy(population[i],population[i+1]);
			}
			mutate(population[i]);
			if(strcmp(population[i],ref)==0)
			{
			    flag = 0;
			    break;
			}
			mutate(population[i+1]);
			if(strcmp(population[i+1],ref)==0)
			{
			    flag = 0;
			    break;
			}

		}



	}
	printf("\ni=%d,j=%d\nPopulation list final\n",i,j);

	for( i = 0; i < 10; i += 1)
	{
	printf("\nString no:%d-%s",i,population[i]);
	}

	printf ("\nNo of gens:%d",gen);




return 0;
}
	
