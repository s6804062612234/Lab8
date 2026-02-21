#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int random1to100();
void printAr(int numAr[],int numArSize);
int checkNum(int numAr[],int numArSize);
int searchNum(int numAr[],int numArSize,int target);
void sort(int arr[], int length);
void swap(int *a, int *b);


int main() {
    int N,i;
    int A[100];
    scanf("%d",&N);
    if (N>100) 
        N=100;
    srand(time(NULL));
    for (i=0;i<N;i++)
        A[i]=checkNum(A,i);
       
    printf("\n********\n");
    printAr(A,N);
    
    int length = N;
    sort(A, N);
    printf("\n3 best score are:");
    for(i = length-1; i >= length-3; i--) {
        printf(" %d", A[i]);
    }
    
    return 0;
}
void printAr(int numAr[],int numArSize) {
    int i;
    for (i=0;i<numArSize;i++)
        printf("%d ",numAr[i]);
} 

int checkNum(int numAr[],int numArSize) {
    int rnum;
    rnum=random1to100();
    while (searchNum(numAr,numArSize,rnum)) {
        rnum=random1to100();
    }
    return rnum;
}

int searchNum(int numAr[],int numArSize, int target) {
    //sol1* use Linear search
    //sol2 use binary search  see.Lab6no9-10 
    int i,found=0;
    for (i=0;i<numArSize;i++) {
        if(target == numAr[i]){
            found = 1;
        }
    }
    
    return found;
}

int random1to100() {
    int random_num = (rand() % 100) + 1;
    printf("%d ", random_num);
    return random_num;
}

void sort(int arr[], int length) {
    int i, j;

    for(i=length-1; i>0; i--) {
        for(j=0; j<i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


