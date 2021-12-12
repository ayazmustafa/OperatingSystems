#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int strtoint( char*);

// 12. dkaç - 16-17dk
int main(int argc, char *argv[])
{	
	int first, second, result;
	
	
	read(3, &first,  sizeof(int));
	read(3, &second, sizeof(int));
	
	result = first - second;
	
	write(4, &result,  sizeof(int));
        
        return 0;
}



