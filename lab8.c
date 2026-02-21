#include <stdio.h>
int checkscore(char std[], char keys[]);
int checkhardest(char ans[][10], char keys[]);
int no1 = 0, cur_lowest=10, lowest=10, hardest;

int main() {
    int i, j;
    char ans[8][10]={
        	{'A','B','A','C','C','D','E','E','A','D'},//7
            {'D','B','A','B','C','A','E','E','A','D'},//6
            {'E','D','D','A','C','B','E','E','A','D'},//5
            {'C','B','A','E','D','C','E','E','A','D'},//4
            {'A','B','D','C','C','D','E','E','A','D'},//8
            {'B','B','E','C','C','D','E','E','A','D'},//7
            {'B','B','A','C','C','D','E','E','A','D'},//7
            {'E','B','E','C','C','D','E','E','A','D'}};//7

        char keys[10]={'D','B','D','C','C','D','A','E','A','D'};
            for(i=0; i<8; i++) {
            	printf("std %d => %d\n", (i+1), checkscore(ans[i], keys));
            }
        printf("Number 1 correct stat => %d\n", no1);
        printf("Hardest question => %d\n", checkhardest(ans,keys));
}


int checkscore(char std[], char keys[]) {
    int i, scr=0;
    for(i=0; i<10; i++) {
        if(std[i] == keys[i]) {
            scr++;
            if(i==0) {
                no1++;
            }
        }
    }
    
    return scr;
}


int checkhardest(char ans[][10], char keys[]) {
    int i, j, correct;
    int lowest = 9, hardest = 1;

    for(i=0;i<10;i++){
        correct = 0;
        for(j=0;j<8;j++){
            if(ans[j][i] == keys[i]){
                correct++;
            }
        }
        if(correct < lowest){
            lowest = correct;
            hardest = i+1;
        }
    }

    return hardest;
}

