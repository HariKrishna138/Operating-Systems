#include<stdio.h>
void main(){
    int ms,bs,ef,nob,n,mp[10],tif=0;    // ms - memory size,bs-block size,
    int i,p=0;
    printf("Enter the total memory available: ");
    scanf("%d",&ms);
    printf("Enter the block size: ");
    scanf("%d",&bs);
    printf("Enter number of processes: ");
    scanf("%d",&n);
    nob = ms/bs;
    ef=ms-nob*bs;
    for(i=0;i<n;i++){
        printf("Enter memory required gor process %d : ",i+1);
        scanf("%d",&mp[i]);
    }
    printf("\n No.of Block available in memory  %d: ",nob);
    printf("\n\nPROCESS\tMEMORY REQUIRED\t ALLOCATED\tINTERNAL FRAGMENTATION");
    for(i=0;i<n&&p<nob;i++){
        printf("\n%d\t\t%d",i+14,mp[i]);
        if(mp[i]>bs)
        {
            printf("\t\tNO\t\t--");
        }
        else{
            printf("\t\tYES\t%d",bs-mp[i]);
            tif=tif+bs-mp[i];
            p++;
        }
    }
    if(i<n){
        printf("\n Memory is full,Remaining Processes cannot be accomodated");
        printf("\n\nTotal Internal Fragmentation is %d",tif);
        printf("\nTotal External Fragmentation is %d",ef);
    }
}
