#include <stdio.h>
void sortByBurstTime(int bt[], int p[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}
int main() {
    int bt[30], wt[30], tat[30], p[30], n;
    float a_wt = 0, a_tat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter processes burst time:\n");
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter p%d burst time: ", i + 1);
        scanf("%d", &bt[i]);
    }
    sortByBurstTime(bt, p, n);
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = 0;
        for (int j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        a_wt += wt[i];
        a_tat += tat[i];
        printf("p%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    a_wt /= n;
    a_tat /= n;
    printf("\nAverage Waiting Time: %.2f", a_wt);
    printf("\nAverage Turnaround Time: %.2f", a_tat);
    return 0;
}
