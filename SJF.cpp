#include <bits/stdc++.h>
#include "SchedulingAlgorithm.h"
#include "Parameter_Functions.h"
using namespace std;

void ShortestJobFirst() {
    int process_count;
    cout << "Enter the Number of Processes: ";
    cin >> process_count;

    // Taking Input for the Number of Processes - Arrival & Burst Time
    int ArrivalTime[Max_Processes], BurstTime[Max_Processes];
    GetArrivalTime(ArrivalTime, process_count);
    GetBurstTime(BurstTime, process_count);

    // Define a structure to hold the process information
    struct Process {
        int ProcessId;
        int ArrivalTime;
        int BurstTime;
    };

    // Initialize the processes array
    vector<Process> processes;
    for (int i = 0; i < process_count; i++) {
        processes.push_back({i + 1, ArrivalTime[i], BurstTime[i]}); // Process ID starts from 1
    }

    // Sort processes based on ArrivalTime and BurstTime for SJF
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        if (a.ArrivalTime == b.ArrivalTime)
            return a.BurstTime < b.BurstTime;
        return a.ArrivalTime < b.ArrivalTime;
    });

    // Calculate FinishTime for SJF Processes
    int FinishTime[Max_Processes] = {0}; // Initialize FinishTime array with zeros
    int currentTime = 0;                  // Initialize current time to 0
    for (int i = 0; i < process_count; i++) {
        if (processes[i].ArrivalTime > currentTime) {
        currentTime = processes[i].ArrivalTime; // Update for waiting period
        }
        currentTime += processes[i].BurstTime;
        FinishTime[processes[i].ProcessId - 1] = currentTime;
    }

    // Calling Finish Time function
    cout << "*********************************************************" << endl;
    Finish_Time(FinishTime, process_count);

    // Calling Turn-Around Time function
    int TurnAroundTime[Max_Processes];
    cout << "*********************************************************" << endl;
    Turn_Around_Time(FinishTime, ArrivalTime, process_count, TurnAroundTime);

    // Calling Waiting Time function
    cout << "*********************************************************" << endl;
    Waiting_Time(TurnAroundTime, BurstTime, process_count);
}