#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct credentials{
    char username[40];
    char password[40];
}credentials;

bool findspaces(char string[20]){
    for (int i = 0; i < strlen(string); ++i)
    {
        if(string[i]==' '){
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    
    int flag = 0,flag2=0;
    FILE *fp = fopen("users.dat","a");
    FILE *fp2 = fopen("passwords.dat","a");
    
    while(flag==0){
        
        printf("enter your username\n");
        scanf("%[^\n]%*c",credentials.username);
        while(findspaces(credentials.username)){
        printf("username should not contain spaces,enter again\n");
        scanf("%[^\n]%*c",credentials.username);
        }
        FILE *fptr = fopen("users.dat","r");
        char string[40];
        while(!feof(fptr)){
            fscanf(fptr,"%s\n",string);
            if(strcmp(string,credentials.username)==0){
                printf("username already exists,try different one\n");
                flag2 = 1;
                break;

            }
        }
        if(flag2==1){
            flag2=0;
            continue;
        }
        printf("enter password\n");
        scanf("%[^\n]%*c",credentials.password);
        while(findspaces(credentials.password)){
        printf("password should not contain spaces,enter again\n");
        scanf("%[^\n]%*c",credentials.password);
         }

        char password_backup[40];
        strcpy(password_backup,credentials.password);
        printf("reenter your password\n");
        scanf("%[^\n]%*c",credentials.password);
        if(strcmp(password_backup,credentials.password)==0){
        system("clear");
        printf("registration succesful\nnow you can login\n");
        flag = 1;

        }
        if(flag!=1){
        	printf("passwords mismatched, enter again\n");
        }
        


    }

    

    fprintf(fp, "%s\n",credentials.username);
    fprintf(fp2, "%s\n",credentials.password);
    fclose(fp);
    fclose(fp2);



    return 0;
}