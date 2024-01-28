#include <stdio.h>

void calculateWaitingTime(int processes[], int n, int burstTime[], int waitingTime[]) {
    waitingTime[0] = 0;

    for (int i = 1; i < n; i++)
        waitingTime[i] = burstTime[i - 1] + waitingTime[i - 1];
}

void calculateTurnaroundTime(int processes[], int n, int burstTime[], int waitingTime[], int turnaroundTime[]) {
    for (int i = 0; i < n; i++)
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
}

void calculateAverageTimes(int processes[], int n, int burstTime[]) {
    int waitingTime[n], turnaroundTime[n], totalWaitingTime = 0, totalTurnaroundTime = 0;

    calculateWaitingTime(processes, n, burstTime, waitingTime);
    calculateTurnaroundTime(processes, n, burstTime, waitingTime, turnaroundTime);

    printf("Processes\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];

        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
    }

    float averageWaitingTime = (float)totalWaitingTime / (float)n;
    float averageTurnaroundTime = (float)totalTurnaroundTime / (float)n;

    printf("\nAverage Waiting Time = %.2f\n", averageWaitingTime);
    printf("Average Turnaround Time = %.2f\n", averageTurnaroundTime);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];

    int burstTime[] = {10, 5, 8};

    calculateAverageTimes(processes, n, burstTime);

    return 0;
}
