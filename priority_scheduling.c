#include<stdio.h>
void main(){
    int p[20],bt[20],wt[20],pri[20],tat[20],i,n,temp,k;
    float wt_avg=0,tat_avg=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p[i]=i;
        printf("Enter process burst time and priority for P%d: ",i+1);
        scanf("%d %d",&bt[i],&pri[i]);
    }
    for(i=0;i<n;i++){
        for(k=i+1;k<n;k++){
            if(pri[i]>pri[k]){
                temp=p[i];
                p[i]=p[k];
                p[k]=temp;
                temp=bt[i];
                bt[i]=bt[k];
                bt[k]=temp;
                temp=pri[i];
                pri[i]=pri[k];
                pri[k]=temp;
            }
        }
    }
    wt_avg = wt[0] = 0;
    tat_avg = tat[0] = bt[0];
    printf("\nPROCESS\t\tBURST TIME\t\tPRIORITY\t\t WAITING TIME\t\tTURNAROUND TIME");
    for(i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=tat[i-1]+bt[i];
        wt_avg+=wt[i];
        tat_avg+=tat[i];
    }
    for(i=0;i<n;i++){
         printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d",i+1,bt[i],pri[i],wt[i],tat[i]);
    }
    printf("\nAverage Waiting Time: %f",(wt_avg/n));
    printf("\nAverage TurnAround Time: %f",(tat_avg/n));
    
}
