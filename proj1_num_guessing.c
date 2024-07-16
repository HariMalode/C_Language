#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int num,guess,nguess=1;
    srand(time(0));
    num=rand()%100+1;
   //printf("\n The Number is:%d",num);
    do{ printf("\n Guess The Number Between[1-100]:");
     scanf("%d",&guess);
     if(guess>num){
        printf("\n Your Number is Greater,Put Lower Number:");
     }
     else if(guess<num){
        printf("\n Your Number is Smaller,Put Greater Number:");
     }
     else{
        printf("\n Congrats!!!, You Guess it in %d Guesses",nguess);
       }
        nguess++;
    }while(guess!=num);
    return 0;
}