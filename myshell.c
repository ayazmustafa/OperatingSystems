#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// cumleler: ANA METİN
// cumle: ana metindeki cümleler + 
// cumleCPY: 
// kelimeler: boşlukla ayrılmış komut


// tekrar ahmet 5|islem toplama 7 2|tekrar mehmet 3|islem carpma 2 4
// islem bolme 3 7|tekrar ilker 5|islem carpma 2 1
// 
char** split(const char* , const char* , int*);

int main(int argc, char *argv[],char ** envp) {
	
	
	while(1)
	{
		int bigCount, smallCount;
		char *command = (char*)malloc(2000 * sizeof(char));
	 	printf("myshell>>");
	 	gets(command);
	 	
	 	// islem topla 3 5| asda | asdasd
	 	// 1. islem topla 3 52. asda 3. asdasd
	 	// islem
	 	// topla
	 	// 3
	 	// 5
	 	char** sentences = (char**)command;
		sentences = split(command, "|", &bigCount); 
		
		for (int i = 0; i <= bigCount - 1; i++)
		{
			//printf("%s\n", sentences[i]);
			char **words;
			words = split(sentences[i], " ", &smallCount);
			int miniCount = 0;
			
			if (strcmp(words[0], "cat") == 0)
			{
				
				printf("cat: ");
				for(int ite = 4; ite < strlen(sentences[i]); ite++)
				{
					printf("%c", sentences[i][ite]);
				}
				printf("\n");
		
			} 
		
			for (int j = 0; j <= smallCount - 1; j++)
			{	
				
				if (strcmp(words[0], "tekrar") == 0 && miniCount == 0)
				{
					//printf("TEKRAR -- word: %s howManyTimes: %s\n", words[1], words[2]);
					char *newargv[3];
					newargv[0] = words[1];
      					newargv[1] = words[2];
      					newargv[2] = NULL;
      					int f, status;
      					f= fork();
      					if(f==0)
      					{
          
		
          				i = execve("tekrar", newargv,envp); // main2 = exe'nin ismi
          				

      					}
      					else
      					{
          				//sleep(0.9);
		  			wait(&status); // forku bekle

          				

      					}	
      				miniCount++;
					
				}
				
				
				else if (strcmp(words[0], "islem") == 0 && miniCount == 0)
				{
					//printf("ISLEM -- word: %s 1stNR: %s  2ndNR: %s\n", words[1], words[2],words[3] );
					char *newargv[4];
					newargv[0] = words[1];
      					newargv[1] = words[2];
      					newargv[2] = words[3];
      					newargv[3] = NULL;
      					int f, status, value;
      					f= fork();
      					if(f==0)
      					{
          
		
          				i = execve("islem", newargv, envp); // main2 = exe'nin ismi
          			
      					}
      					else
      					{
          				//sleep(0.9);
		  				value = wait(&status); // forku bekle
		  				printf("Cevap = %d\n", WEXITSTATUS(status));
      					}
					miniCount++;
					
				}
				else if (strcmp(words[0], "exit") == 0)
				{
					exit(0);
				
				}
				else if (strcmp(words[0], "bash") == 0)
				{
					int f, status;
      					f= fork();
      					if(f==0)
      					{
          
		
          				i = execve("/bin/bash", NULL,envp); 
          				

      					}
      					else
      					{
          				//sleep(0.9);
		  			wait(&status); // forku bekle

          				

      					}
				
				}
				else if (strcmp(words[0], "clear") == 0)
				{
					system("clear");
				
				}
				
				/*else if (strcmp(words[0], "cat") == 0 && miniCount == 0)
				{
					for (int is = 0; is < bigCount; is++)
						printf("%s\n", words[1]);
					miniCount++;
				
				}*/
				else if (strcmp(words[0], "ls") == 0 )
				{
					system("ls");
				
				}
				else if (miniCount <= 0 && (strcmp(words[0], "cat")) != 0  )
				{
					printf("Yazdiginiz komut hatalı.\n");
					miniCount++;
				}
		
			}
			
		}
		

	

	 	
	 }
	

	
	return 0;
}


	char** split(const char* text, const char* separator, int* count) {
		unsigned int sep_pos = 0, i = 0, j = 0, k = 0, ccount = 1;
		char** list = (char*)malloc(sizeof(char));
		char* buffer;
		char* ntext;
		bool flag = true;

		if (strlen(separator) > strlen(text)) {
			ntext = (char*)malloc(strlen(text) + 1);
			memcpy(ntext, text, strlen(text) + 1);
			list[0] = ntext;
			return list;
		}

		for (i = (strlen(text) - strlen(separator)); i <= strlen(text) - 1; i++) {
			if (text[i] != separator[j])
				flag = false;
			j++;
		}

		if (flag == false) {
			ntext = (char*)malloc(strlen(text) + strlen(separator) + 1);
			memset(ntext, 0, strlen(text) + strlen(separator) + 1);
			strcat(ntext, text);
			strcat(ntext, separator);
		}
		else {
			ntext = (char*)malloc(strlen(text) + 1);
			strncpy(ntext, text, strlen(text) + 1);
		}

		for (i = 0; i <= (strlen(ntext) - strlen(separator)); i++) {
			flag = true;
			k = 0;

			for (j = i; j <= (i + strlen(separator) - 1); j++) {
				if (ntext[j] != separator[k])
					flag = false;
				k++;
			}

			if (flag == true) {
				list = (char*)realloc(list, (ccount * sizeof(char)));
				int size_buffer = (i - sep_pos);
				buffer = (char*)malloc(size_buffer + 1);
				int k = 0;

				for (j = sep_pos; j <= (sep_pos + size_buffer - 1); j++) {
					buffer[k] = ntext[j];
					k++;
				}

				buffer[k] = '\0';

				list[ccount - 1] = buffer;

				sep_pos = i + strlen(separator);

				ccount++;
			}
		}

		

		if (count != NULL)
			(*count) = ccount - 1;

		return list;
	}
