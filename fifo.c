#include<stdio.h>
void main(){
    int f,n,a[10],i,j,hit=0,fault=0,index=0,frames[10];
    printf("Enter number of pages: ");
    scanf("%d",&n);
    printf("Enter page number: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d",&f);
    for(i=0;i<f;i++){
        frames[i]=-1;
    }
    for(j=0;j<n;j++){
        if(index == f){
            index = 0;
        }
        int flag = 0;
        for(i=0;i<f;i++){
            if(frames[i]==a[j]){
                hit++;
                flag=1;
                break;
            }
        }
        if(flag==0){
                frames[index++]=a[j];
                fault++;
            
        }
        for(i=0;i<f;i++){
            printf("%d ",frames[i]);
        }
        printf("\n");
    }
    printf("Hits: %d",hit);
    printf("Faults: %d",fault);
}
