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
#define POPULATIONSIZE 10

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

void shuffle(int *o)
{
    int k=0,j=0,tmp;
    for(k=POPULATIONSIZE-1;k>0;k--)
    {
        j=rand()%k;
        tmp = o[j];
        o[j] = o[k];
        o[k] = tmp;
    }

}




int main (int argc, char const* argv[])
{
	int i,j,flag=1,maxm=0,m,n,gen = 0;
	int order[POPULATIONSIZE];
	char ref[11]="abcccabccc";
	char population[POPULATIONSIZE][11];
	srand(time(NULL));

	for(i = 0;i<POPULATIONSIZE;order[i]=i,i++);

	for( i = 0; i < POPULATIONSIZE; i += 1)
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
	    shuffle(order);
		for(i = 0;i<POPULATIONSIZE;i+=2)
		{
			m=fitness(population[order[i]],ref);
			maxm = m>maxm?m:maxm;
			n=fitness(population[order[i+1]],ref);
			maxm = n>maxm?n:maxm;
			if(m>n)
			{
				strcpy(population[order[i+1]],population[order[i]]);
			}
			else
			{
			    strcpy(population[order[i]],population[order[i+1]]);
			}
			mutate(population[order[i]]);
			if(strcmp(population[order[i]],ref)==0)
			{
			    i=order[i];
			    flag = 0;
			    break;
			}
			if(strcmp(population[order[i+1]],ref)==0)
			{
			    i=order[i+1];
			    flag = 0;
			    break;
			}

		}



	}
	printf("\ni=%d,j=%d\nPopulation list final\n",i,j);

	for( i = 0; i < POPULATIONSIZE; i += 1)
	{
	printf("\nString no:%d-%s",i,population[i]);
	}

	printf ("\nNo of gens:%d",gen);




return 0;
}

