#include<stdio.h>
void main(){
    int i,n,j,bt[10],wt[20],tat[20],t,ct[20],max;
    float wt_avg=0,tat_avg=0,temp=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter Burst Time for process p%d: ",i+1);
        scanf("%d",&bt[i]);
        ct[i]=bt[i];
    }
    printf("Enter the size of the time slice:  ");
    scanf("%d",&t);
    max=bt[0];
    for(i=1;i<n;i++){
        if(max<bt[i]){
            max=bt[i];
        }
    }
    for(j=0;j<(max/t)+1;j++){
        for(i=0;i<n;i++){
            if(bt[i]!=0){
                if(bt[i]<=t){
                    tat[i]=temp+bt[i];
                    temp=temp+bt[i];
                    bt[i]=0;
                }
                else{
                    bt[i]=bt[i]-t;
                    temp=temp+t;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        wt[i]=tat[i]-ct[i];
        wt_avg+=wt[i];
        tat_avg+=tat[i];
    }
    printf("Time Slice is: %d",t);
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i=0;i<n;i++){
        printf("\n\tP%d\t\t\t%d\t\t\t%d\t\t\t%d",i+1,ct[i],wt[i],tat[i]);
    }
    printf("\nAverage Waiting Time: %f",(wt_avg/n));
    printf("\nAverage TurnAround TIme: %f",(tat_avg/n));
}
