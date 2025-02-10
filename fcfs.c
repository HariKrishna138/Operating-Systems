#include <stdio.h>
struct Process {
    int id;           
    int at;  
    int bt;    
    int wt;  
    int tat;
};

void WaitingTime(struct Process proc[], int n) {
    proc[0].wt = 0;
    for (int i = 1; i < n; i++) {
        proc[i].wt = proc[i - 1].wt + proc[i - 1].bt;
    }
}
void TurnaroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].tat = proc[i].bt + proc[i].wt;
    }
}
void AvgTime(struct Process proc[], int n) {
    int t_wt = 0, t_tat = 0;
    for (int i = 0; i < n; i++) {
        t_wt += proc[i].wt;
        t_tat += proc[i].tat;
    }
    printf("\nAverage waiting time: %.2f", (float)t_wt / n);
    printf("\nAverage turnaround time: %.2f", (float)t_tat / n);
}
void display(struct Process proc[], int n) {
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d                  %d               %d        %d             %d\n", proc[i].id, proc[i].at,
               proc[i].bt, proc[i].wt, proc[i].tat);
    }
}
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process proc[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for process %d\n", i + 1);
        proc[i].id = i + 1;
        printf("Arrival time: ");
        scanf("%d", &proc[i].at);
        printf("Burst time: ");
        scanf("%d", &proc[i].bt);
    }
    WaitingTime(proc, n);
    TurnaroundTime(proc, n);
    display(proc, n);
    AvgTime(proc, n);
    return 0;
}
