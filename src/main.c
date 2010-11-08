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
 */
int main (int argc, char const* argv[])
{
	int i,j;
	char ref[11]="mynameisap";
	char population[10][11];
	for( i = 0; i < 10; i += 1)
	{
	for(j = 0; j < 10; j += 1)
	{
		population[i][j]=rand()%26+'a';	
		
	}
	population[i][10]='\0';
	printf("\nString no:%d-%s",i,population[i]);
	}



return 0;
}
	
