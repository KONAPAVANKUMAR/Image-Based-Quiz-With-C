#include <stdio.h>
#include <stdlib.h>

int main()
{
	char fname[20], ch;
	FILE *fpts, *fptt;
	
		

	fpts=fopen("users", "r");

	if(fpts==NULL)
	{

		exit(1);
	}
	fptt=fopen("users.dat", "w");
	if(fptt==NULL)
	{
		printf(" Error in creation of file temp.txt ..!!");
		fclose(fpts);
		exit(2);
	}
	while(1)
	{
		ch=fgetc(fpts);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			ch=ch+100;
			fputc(ch, fptt);
		}
	}
	fclose(fpts);
	fclose(fptt);
	fpts=fopen(fname, "w");
	if(fpts==NULL)
	{

		exit(3);
	}
	fptt=fopen("users", "r");
	if(fptt==NULL)
	{

		fclose(fpts);
		exit(4);
	}
	while(1)
	{
		ch=fgetc(fptt);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			fputc(ch, fpts);
		}
	}
	system("rm users");

	fclose(fpts);
	fclose(fptt);

	


	// users encrypted

}
