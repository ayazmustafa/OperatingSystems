#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int main(int argc, char *argv[])
{


    
    int count= strtoint(argv[1]);
    for (int i = 1; i <= count; ++i) {
           printf("%d %s\n",i, argv[0]);
    }



    return 0;
}

