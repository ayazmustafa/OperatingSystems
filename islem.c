#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int strtoint( char*);

// 12. dkaç - 16-17dk
int main(int argc, char *argv[], char ** envp)
{	
	//printf("argv0: %s argv1: %s argv2: %s\n", argv[0], argv[1], argv[2]);   toplama x y
	int myPipe[2]; // C => P
	
	
	
	int firstNR  = strtoint(argv[1]);
	int secondNR = strtoint(argv[2]);
	
	
	
	if(pipe(myPipe) == -1) { return 1; }
	
	write(myPipe[1], &firstNR,  sizeof(int));
	write(myPipe[1], &secondNR, sizeof(int));
	
	if(strcmp(argv[0], "topla") == 0)
	{
		int pId = fork();
		int i, status, value;
		
		
		if(pId == 0)
		{
		
		
          		i = execve("topla", NULL, envp); 
          			
      		}
      		else
      		{
      			int result;
		  	value = wait(&status); // forku bekle
		  	read(myPipe[0], &result, sizeof(int));
		  	exit(result);
		  			
      		}
		
	}
	else
	{
		int pId = fork();
		int i, status, value;
		
		
		if(pId == 0)
		{
		
		
          		i = execve("cikar", NULL, envp); 
          			
      		}
      		else
      		{
		  	int result;
		  	value = wait(&status); // forku bekle
		  	read(myPipe[0], &result, sizeof(int));
		  	exit(result);
		  			
      		}
	}

        
        return 0;
}


int strtoint( char* charnums)
{
 int number=0;
 int index=0;
 while(charnums[index])
 {
    if(('0'<=charnums[index]) && (charnums[index]<='9'))
    {

    if(!number)
        number= ( (int) charnums[index]) - 48;
    else
    {
        number = (number *= 10) + ((int) charnums[index] - 48);
    }
    index++;
         }
         else
         {
            number=-1;
            printf("\nGecersiz islem");
            break;
         }
 }
 return number;
}

