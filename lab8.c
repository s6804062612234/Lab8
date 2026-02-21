#include <stdio.h>

int findMax(int num[]);
void printAr(int number[], int sizeNum);
void addone(int number[], int add[], int sizeNum);
void addtwo(int number[], int pos[], int x, int sizeNum, int sizePos);
void addthree(int number[], int pos[2][3], int sizeNum, int sizePos); 


int main() {
    int number[5] = {20,50,100,99,9};
    int max, length;

    length = sizeof(number) / sizeof(number[0]);
    max = findMax(number);
    printAr(number, length);

    printf("\naddone\n");
    int arr1[5] = {1, 2, 3, 4, 5};
    addone(number, arr1, length);
    printAr(number, length);

    printf("\naddtwo\n");
    int pos[] = {0, 2, 4};
    int posLength = sizeof(pos) / sizeof(pos[0]);
    int x = 5;
    addtwo(number, pos, x, length, posLength);
    printAr(number, length);

    printf("\naddthree\n");
    int pos2D[2][3] = {{0, 2, 4},{10, 20, 30}};
    int posLength2D = sizeof(pos2D[0]) / sizeof(pos2D[0][0]);
    addthree(number, pos2D, length, posLength2D);
    printAr(number, length);
}


int findMax(int num[]) {
    int maximum,i=0;
    maximum = num[i];

    for(i=0; i<5; i++) {
        if(num[i] > maximum)
            maximum = num[i];
    }
    return maximum;
}


void printAr(int number[], int sizeNum){
    int i;
    for(i=0; i<sizeNum; i++){
        printf("number[%d] : %d\n", i+1, number[i]);
    }
}


void addone(int number[], int add[], int sizeNum) {
    int i;
    for(i=0; i<sizeNum; i++) {
        number[i] += add[i];
    }
}


void addtwo(int number[], int pos[], int x, int sizeNum, int sizePos) {
    int i, j;
    for(i=0; i<sizeNum; i++) {
        for(j=0; j<sizePos; j++) {
            if(pos[j]==i) {
                number[i] += x;
            }
        }
    }
}


void addthree(int number[], int pos[2][3], int sizeNum, int sizePos) {
    int i, j;
    for(i=0; i<sizeNum; i++) {
        for(j=0; j<sizePos; j++) {
            if(i==pos[0][j]) {
                number[i] += pos[1][j];
            }
        }
    }
}

/* result
number[1] : 20
number[2] : 50
number[3] : 100
number[4] : 99
number[5] : 9
Maximum of these number is 100
*/
