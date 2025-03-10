#include<stdio.h>
void main(){
    int m=3,n,i,j,k,count=0;
    int allocation[5][3],max[5][3],need[5][3],available[3],finish[5],ans[5];
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter allocation matrix: \n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&allocation[i][j]);
        }
    }
    printf("Enter the Max matrix: \n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }
    for(i=0;i<n;i++){
        finish[i]=0; //0-false 1=true
        for(j=0;j<m;j++){
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    jump:
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(need[i][j]<=available[j]){
                finish[i]=1;
                available[j]+=allocation[i][j];
                if(j==m)
                {
                    ans[count]=i;
                }
                count++;
                break;
            }
        }
    }
    for(k=0;k<n;k++){
        if(finish[i]==0){
            goto jump;
        }
        else if(finish[i]=0){
            printf("The System is not in safe state");
        }
        else{
            printf("The System is in safe state");
            break;
        }
    }
    printf("\nThe process sequence is: ");
    for(k=0;k<n;k++){
        printf("\np%d \n",ans[k]);
    }
}//not completed
