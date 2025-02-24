#include <stdio.h>
int main(){
    int i,j,bt[10],wt[10],n,tat[10];
    float a_wt=0,a_tat=0;
    printf("Enter number of processes(max=10): ");
    scanf("%d",&n);
    printf("Enter process burst time ");
    for(i=0;i<n;i++){
        printf("\nEnter p %d burst time ",i+1);
        scanf("%d",&bt[i]);
    }
    wt[0]=0;//Waiting Time
    for(i=1;i<n;i++){
        wt[i]=0;
        for(j=0;j<i;j++){
            wt[i]+=bt[j];
        }
    }
    printf("\nProcess\t\tBurst time\twaiting time\tturnaround time");
    for(i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
        a_wt+=wt[i];
        a_tat+=tat[i];
        printf("\np%d\t\t\t%d\t\t\t\t%d\t\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
    a_wt/=n;
    a_tat/=n;
    printf("\nAverage Waiting Time: %f",a_wt);
    printf("\nAverage TurnAround Time %f",a_tat);
    return 0;
}
