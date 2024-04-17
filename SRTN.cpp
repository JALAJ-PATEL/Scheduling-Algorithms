#include <bits/stdc++.h>
#include "SchedulingAlgorithm.h"
#include "Parameter_Functions.h"

using namespace std;

void ShortestRemainingTimeNext() {
    int process_count;
    cout << "Enter the Number of Processes: ";
    cin >> process_count;

    // Taking Input for the Number of Processes - Arrival & Burst Time
    int ArrivalTime[Max_Processes], BurstTime[Max_Processes];
    GetArrivalTime(ArrivalTime, process_count);
    GetBurstTime(BurstTime, process_count);

    // Initialize remaining time for each process
    int RemainingTime[Max_Processes];
    for (int i = 1; i <= process_count; i++) {
        RemainingTime[i] = BurstTime[i];
    }

    // Initialize FinishTime as an array
    int FinishTime[Max_Processes];

    int currentTime = 0, completed = 0;
    while (completed != process_count) {
        int shortest = INT_MAX, shortestIndex = -1;
        for (int i = 1; i <= process_count; i++) {
            if (ArrivalTime[i] <= currentTime && RemainingTime[i] < shortest && RemainingTime[i] > 0) {
                shortest = RemainingTime[i];
                shortestIndex = i;
            }
        }
        if (shortestIndex == -1) {
            currentTime++;
            continue;
        }
        // Process shortest job
        RemainingTime[shortestIndex]--;
        currentTime++;

        if (RemainingTime[shortestIndex] == 0) {
            completed++;
            FinishTime[shortestIndex] = currentTime;
        }
    }

    // Calling Finish Time function
    cout << "*********************************************************"<<endl;
    Finish_Time(FinishTime, process_count);

    // Calling Turn-Around Time and Waiting Time function
    int TurnAroundTime[Max_Processes];
    cout << "*********************************************************"<<endl;
    Turn_Around_Time(FinishTime, ArrivalTime, process_count, TurnAroundTime);

    // Calling Waiting Time and Waiting Time function
    cout << "*********************************************************"<<endl;
    Waiting_Time(TurnAroundTime, BurstTime, process_count);
}