#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char username[20];
	char password[20];

	printf("enter username\n");
	scanf("%s",username);
	printf("enter password\n");
	scanf("%s",password);

	int i = 0;

	while(strcmp(username,"admin")!=0||strcmp(password,"admin")!=0){
		printf("invalid,try again\n");
		printf("enter username\n");
		scanf("%s",username);
		printf("enter password\n");
		scanf("%s",password);

	}

	printf("login succesful\n");			
	printf("1.hide_data 2.reveal_data\n");

	int n;
	scanf("%d",&n);
	if(n==1){
    		system("mv data data.dat");
    		system("mv users users.dat");
    		system("mv passwords passwords.dat");
    		system("mv result result.dat");
    		printf("succesfully hidden\n");
    		if(i){
    			//start of encryption
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
    			//end of decryption

    		}
    		exit(0);
	}


	if(n==2){
			system("mv data.dat data");
			system("mv users.dat users");
			system("mv passwords.dat passwords");
			system("mv result.dat result");
			if(i){
				char fname[20], ch;
	FILE *fpts, *fptt;
	
		

	fpts=fopen("users.dat", "r");

	if(fpts==NULL)
	{

		exit(1);
	}
	fptt=fopen("users", "w");
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
			ch=ch-100;
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
	fptt=fopen("users.dat", "r");
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
	printf(" File %s successfully encrypted ..!!\n\n", fname);
	fclose(fpts);
	fclose(fptt);

	system("rm users.dat");
			}

			printf("succesfully revealed\n");
			exit(0);
	}

	




		

	return 0;
}