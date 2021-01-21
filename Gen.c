#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void)
{
	typedef enum {
		false,
		true
	}bool;

	bool started = true;

	FILE *password = fopen("password.secret", "a+");

	while (started == true)
	{

		int lenght = 0;
   		char website[2048];

   	    printf("Lenght of the password : ");
		scanf ("%d", &lenght);

		if (lenght > 1024)
		{
			printf("Your password is very long, is not very usefull and the almost website don't take password with lenght > 128\n");
		}

		time_t t;

		srand((unsigned) time(&t));

		int ascii_id;

		printf ("Website of this password : ");
		scanf("%s", &website);
	
		fprintf(password, "%s : ", &website);

		for (int i = 0 ; i < lenght ; i++)
		{
				ascii_id = 58 + (rand() % 64);
				fputc (ascii_id ,password);

		}
		fprintf(password, "\n");
		
		char selected[3];
		char yes []= "Yes";

		printf("Continue ? Yes or No : \n");
		scanf("%s", selected);

		int select = strcmp(selected, yes);

		if (select != 0)
		{
			started = false;
		}
		
	}
	fclose(password);

	return 0;
}
