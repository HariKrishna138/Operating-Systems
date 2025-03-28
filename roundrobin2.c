#include<stdio.h>
void main(){
    int tt=0,i,r=0,ct[10],rt[10],bt[10],wt[10],n,t,p=0;
    float a_wt=0,a_tat=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter process burst times: ");
    for(i=0;i<n;i++){
        printf("\nEnter the burst time for p%d: ",i+1);
        scanf("%d",&bt[i]);
    }
    printf("Enter Time Quantum: ");
    scanf("%d",&t);
    for(i=0;i<n;i++){
        tt+=bt[i];
        rt[i]=bt[i];
    }
    ct[0]=0;
    while(r<tt){
        for(i=0;i<n;i++){
            if(rt[i]!=0){
                if(rt[i]<t){
                    ct[i]=ct[p]+rt[i];
                    p=i;
                    r+=rt[i];
                    rt[i]=0;
                }
                else{
                    ct[i]=ct[p]+t;
                    rt[i]-=t;
                    p=i;
                    r+=t;
                }
            }
        }
    }
    printf("\nPROCESS\t\t\tBURST TIME\t\t\tWAITING TIME\t\tTURNAROUND TIME");
    for(i=0;i<n;i++){
        wt[i]=ct[i]-bt[i];
        a_wt+=wt[i];
        a_tat+=ct[i];
        printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",i+1,bt[i],wt[i],ct[i]);
    }
    a_wt/=n;
    a_tat/=n;
    printf("\nAverage Waiting Time is: %f",a_wt);
    printf("\nAverage Turn Around TIme: %f",a_tat);
}
