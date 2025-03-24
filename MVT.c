#include<stdio.h>
void main(){
    int ms,mp[10],temp,i,n=0;
    char ch='y';
    printf("\nEnter the total memory available: ");
    scanf("%d",&ms);
    temp=ms;
    for(i=0;ch=='y';i++,n++){
        printf("\nEnter memory required for process %d : ",i+1);
        scanf("%d",&mp[i]);
        if(mp[i]<=temp){
            printf("memory is allocated for process %d ",i+1);
            temp=temp-mp[i];
        }
        else{
            printf("\nMemory is full");
            break;
        }
        printf("\nDo you want to continue(y/n): ");
        scanf("%s",&ch);
    }
    printf("\n\nTotal Memory Available %d ",ms);
    printf("\n\nPROCESS\t\tMEMORY ALLOCATED");
    for(i=0;i<n;i++){
        printf("\n\t%d\t\t%d",i+1,mp[i]);
    }
    printf("\n\nTotal Memory Allocated is %d: ",ms-temp);
    printf("\n Total External Fragmentation: %d",temp);
}
