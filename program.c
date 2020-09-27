#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct student{
	char username[20];
	int score;
}student;

struct node
{
	struct node *prev;
	char question[500];
	char options[500];
	char imagename[20];
	char answer[20];
	int marks;
	char resp[30];
	struct node *next;
};

struct credentials{
    char username[40];
    char password[40];
}credentials;

struct leaderboard{
	int rank;
	int score;
	char name[30];
}lb[100];
int z = 0;

void merge(int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  

    struct leaderboard L[n1], R[n2]; 
  

    for (i = 0; i < n1; i++) 
        L[i] = lb[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = lb[m + 1+ j]; 
  

    i = 0; 
    j = 0; 
    k = l;  
    while (i < n1 && j < n2) 
    { 
        if (L[i].score > R[j].score) 
        { 
            lb[k] = L[i]; 
            i++; 
        } 
        else
        { 
            lb[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    
    while (i < n1) 
    { 
        lb[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    
    while (j < n2) 
    { 
        lb[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(int l, int r) 
{ 
    if (l < r) 
    { 
        
        int m = l+(r-l)/2; 
  

        mergeSort(l, m); 
        mergeSort(m+1, r); 
  
        merge(l, m, r); 
    } 
} 





bool findspaces(char string[20]){
    for (int i = 0; i < strlen(string); ++i)
    {
        if(string[i]==' '){
            return true;
        }
    }
    return false;
}



struct node *addatend(struct node *start,char question[100],char options[100],char imagename[100],char answer[100])
{
	if(start==NULL){
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	strcpy(tmp->question,question);
	strcpy(tmp->options,options);
	strcpy(tmp->imagename,imagename);
	strcpy(tmp->answer,answer);

	tmp->prev=NULL;
	tmp->next=NULL;
	start=tmp;
	return start;
	}
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	strcpy(tmp->question,question);
	strcpy(tmp->options,options);
	strcpy(tmp->imagename,imagename);
	strcpy(tmp->answer,answer);

	p=start;
	while(p->next!=NULL)
		p=p->next;
	p->next=tmp;
	tmp->next=NULL;
	tmp->prev=p;
	return start;
}

int count(struct node *start){

	struct node *p = start;
	int count=0;
	while(p!=NULL){
		count++;
		p=p->next;
	}
	return count;

}

int countscore(struct node *start){
	struct node *p = start;
	int score = 0;
	while(p!=NULL){
		printf("%d\n",score);
		score = score + p->marks;
		p=p->next;
	}

	return score;
}


void displayresponses(struct node *start){
	struct node *p = start;
	int i = 1;
	while(p!=NULL){
		printf("%d. response:%s\n",i,p->resp);
		i++;
		p=p->next;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	
	printf("1.register 2.signin 3.leader_board\n");
	scanf("%d",&n);

	if(n==1){
		if(z){
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
	}

		system("gcc registration.c");
		system("./a.out");
	}

	


	char username[20];
	char password[20];
	printf("enter your username\n");
	scanf("%s",username);
	printf("enter your password\n");
	scanf("%s",password);
	char string[20];
	char string2[20];
	FILE *fp = fopen("users.dat","r");
	FILE *fp2 = fopen("passwords.dat","r");
	int flag = 0;



	while(!feof(fp)){

		fscanf(fp,"%s\n",string);
		fscanf(fp2,"%s\n",string2);
		if(strcmp(string,username)==0&&strcmp(string2,password)==0){
			printf("login succesful\n");
			flag = 1;
			break;
		}
	}
	fclose(fp);
	fclose(fp2);
	while(flag==0){
	printf("invalid credentials enter again\n");
	fp = fopen("users.dat","r");
	fp2 = fopen("passwords.dat","r");

	printf("enter your username\n");

	scanf("%s",username);

	printf("enter your password\n");

	scanf("%s",password);



	while(!feof(fp)){

		fscanf(fp,"%s\n",string);

		fscanf(fp2,"%s\n",string2);

		if(strcmp(string,username)==0&&strcmp(string2,password)==0){
			flag = 1;
			printf("login succesful\n");
		}
	}



	fclose(fp);
	fclose(fp2);



	}


	char name[20];
	FILE *fptr = fopen("result.dat","r");
	while(!feof(fptr)){
		fscanf(fptr,"%s\n",name);

		if(strcmp(username,name)==0){
			printf("user already attempted\n");



    	FILE *fptr; 
  
   		 char c; 
  
   		   

   		fptr = fopen(username, "r"); 
    	if (fptr == NULL) 
    	{ 
        printf("Cannot open file \n"); 
        exit(0); 
   		} 
  

  		  c = fgetc(fptr); 
   		 while (c != EOF) 
    	{ 
       		 printf ("%c", c); 
       		c = fgetc(fptr); 
    	} 
  
   		 fclose(fptr); 
   		 system("gcc sort.c");
			system("./a.out");
			printf("\n\n\n");




			system("gcc program.c");
			system("./a.out");
			exit(1);

		}
	}


	strcpy(student.username,username);
	student.score = 0;

	system("clear");
	char question[500];
	char options[500];
	char imagename[100];
	char answer[100];
	char response[50];
	fp=fopen("data.dat","r");
	struct node *start = NULL;

	while(!feof(fp)){
		fscanf(fp,"%[^\n]%*c",question);
		fscanf(fp,"%[^\n]%*c",options);
		fscanf(fp,"%[^\n]%*c",imagename);
		fscanf(fp,"%[^\n]%*c",answer);
		start = addatend(start,question,options,imagename,answer);
	}
	struct node *start_backup=start;


	struct node *q=start;
	while(q!=NULL){
		strcpy(q->resp,"not attempted");
		q=q->next;
	}
	while(start!=NULL){

		printf("quit--to end the quiz ,review--review your responses,\nskip--skip question prev--go to previous question \n");
		printf("switch n to switch to nth question\n");

		printf("%s\n",start->question);
		if(strcmp(start->options,"nooptions")!=0){
			printf("%s\n",start->options);

		}
		char com[30];
		if(strcmp(start->imagename,"noimage")!=0){

			sprintf(com, "open %s.png",start->imagename);
			system(com);

			system("open -a Terminal");	


		}
		
		scanf("\n");

    	scanf("%[^\n]%*c",response);


    	FILE *temp=fopen("tempfile.dat","w");
   		 fprintf(temp, "%s\n",response);
   		 fclose(temp);
    	temp = fopen("tempfile.dat","r");
    	char firstword[20];
    	int number;
    	fscanf(temp,"%s %d\n",firstword,&number);
    	fclose(temp);

   		

    	

       	system("pkill Preview");
    	system("clear");
    	if(strcmp(response,start->answer)==0){
    		start->marks = 4;
    		strcpy(start->resp,response);
   		 }

   		else if(strcmp(response,"skip")==0){
   			if(start->next!=NULL){
   				start=start->next;
   				continue;


   			}
   			else{
   				printf("end of questions\n\n\n\n");
   				continue;
   			}
   			   			

   		}
   		else if(strcmp(response,"prev")==0){
   			if(start->prev!=NULL){
   				start = start->prev;
   				continue;
   			}
   			else{
   				printf("no previous questions\n\n\n");
   				continue;
   			}
   		}

   		else if(strcmp(firstword,"switch")==0){
   			
   			if(number>=0&&number<=count(start_backup)){
   				start = start_backup;
   				for (int i = 0; i < number-1; ++i)
   			{
   				start=start->next;
   			}
   			continue;

   			}
   			else{
   				printf("question number that u entered doesnt exist\n");
   				continue;
   			}
   			

   		}

   		else if(strcmp(response,"quit")==0){
   			break;
   		}

   		else if(strcmp(response,"review")==0){

   			displayresponses(start_backup);
   			int n;
   			printf("enter 1 to continue\n");
   			scanf("%d",&n);
   			system("clear");


   			continue;
   		}


   		
   		else{
   			start->marks = -1;
   			strcpy(start->resp,response);
   		}

   		if(start->next!=NULL){
   			start=start->next;
		}
		else{
			printf("end of the questions\n");

			
		}
		
	}

	start = start_backup;
	student.score = countscore(start);

	system("clear");
	printf("score:%d\n",student.score);


	struct node *p = start;
	int i = 1;
	FILE *studentfp = fopen(student.username,"w");

	while(p!=NULL){

		printf("%d.",i);
		printf("answer : %s\tyour response : %s\tmarks : %d\n",p->answer,p->resp,p->marks);
		fprintf(studentfp, "%d. your response : %s answer : %s marks : %d\n",i,p->resp,p->answer,p->marks);
		i++;
		p=p->next;



	}
	fclose(studentfp);

	
	
    FILE *result = fopen("result.dat","a");

	fprintf(result, "%s %d\n",student.username,student.score);    
	fclose(result);



	fclose(fp);
	system("gcc sort.c");
	system("./a.out");
	return 0;


	fp = fopen("result","r");
	i=0;
	while(!feof(fp)){
		fscanf(fp,"%s %d\n",lb[i].name,&lb[i].score);


		i++;
	}


	mergeSort(0,i);
	int rank=1;

	for (int j = 0; j <= i; ++j)
	{	
        if(strcmp(lb[j].name,"")!=0){
            printf("%d.%s %d\n",rank,lb[j].name,lb[j].score);
        
            if(lb[j+1].score==lb[j].score)
            continue;

        rank++;

        }
		
		

	}






}

