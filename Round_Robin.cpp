#include <bits/stdc++.h>
#include "SchedulingAlgorithm.h"
#include "Parameter_Functions.h"

using namespace std;

void Round_Robin(){
    int process_count, quantum;
    cout << "Enter the Number of Processes: ";
    cin >> process_count;
    cout << "Enter the Quantum Time: ";
    cin >> quantum;

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
        for (int i = 1; i <= process_count; i++) {
            if (RemainingTime[i] > 0) {
                if (RemainingTime[i] > quantum) {
                    currentTime += quantum;
                    RemainingTime[i] -= quantum;
                } else {
                    currentTime += RemainingTime[i];
                    RemainingTime[i] = 0;
                    completed++;
                    FinishTime[i] = currentTime;
                }
            }
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