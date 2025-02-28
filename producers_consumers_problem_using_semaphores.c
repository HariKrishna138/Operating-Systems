#include <stdio.h>
#include <stdlib.h>
int mutex=1,x=0;
int full=0,empty=10;
void producer(){
    --mutex;
    --empty;
    full++;
    printf("Producer produces item %d",x);
     x++;
    mutex++;
}
void consumer(){
    --mutex;
    ++empty;
    --full;
    printf("Consumer consumes item %d",x);
    x--;
    ++mutex;
}
int main(){
    int ch;
    printf("1.Producer \n 2.Consumer \n 3.Exit");
    do{
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                if((mutex==1)&&(empty!=0)){
                    producer();
                }
                else{
                    printf("buffer is full");
                }
                break;
            case 2:
                if((mutex==1)&&(full!=0)){
                    consumer();
                }
                else{
                    printf("buffer is empty");
                }
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("invalid");
        }
    }while(ch!=3);
    return 0;
}
