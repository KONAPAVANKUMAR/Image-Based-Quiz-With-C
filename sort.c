#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct leaderboard{
	int rank;
	int score;
	char name[30];
}lb[100];


void merge(int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp lbays */
    struct leaderboard L[n1], R[n2]; 
  
    /* Copy data to temp lbays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = lb[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = lb[m + 1+ j]; 
  
    /* Merge the temp lbays back into lb[l..r]*/
    i = 0; // Initial index of first sublbay 
    j = 0; // Initial index of second sublbay 
    k = l; // Initial index of merged sublbay 
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
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        lb[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        lb[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-lbay of lb to be sorted */
void mergeSort(int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(l, m); 
        mergeSort(m+1, r); 
  
        merge(l, m, r); 
    } 
} 
int main(int argc, char const *argv[])
{
	FILE *fp;
	fp = fopen("result.dat","r");
	int i=0;
	while(!feof(fp)){
		fscanf(fp,"%s %d\n",lb[i].name,&lb[i].score);


		i++;
	}


	mergeSort(0,i);
	int rank=1;
    printf("\n\n\t\t...........leaderboard...........\n\n");

	for (int j = 0; j <= i; ++j)
	{	
        if(strcmp(lb[j].name,"")!=0){
            printf("%d.%s %d\n",rank,lb[j].name,lb[j].score);
        
            if(lb[j+1].score==lb[j].score)
            continue;

        rank++;

        }
		
		

	}

	return 0;
}