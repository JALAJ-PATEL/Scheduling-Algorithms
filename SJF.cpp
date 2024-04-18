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
        processes.push_back({i, ArrivalTime[i], BurstTime[i]});
    }

    // Sort processes based on ArrivalTime for SJF
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.ArrivalTime < b.ArrivalTime;
    });

    // Calculate FinishTime for SJF Processes
    int FinishTime[Max_Processes];
    int currentTime = processes[0].ArrivalTime;  // Initialize current time to the first process arrival time
    for (const Process& proc : processes) {
        currentTime = max(currentTime, proc.ArrivalTime); // Ensure we wait until the process arrives
        FinishTime[proc.ProcessId] = currentTime + proc.BurstTime;
        currentTime += proc.BurstTime;
    }

    // Calling Finish Time function
    cout << "*********************************************************" << endl;
    Finish_Time(FinishTime, process_count);

    // Calling Turn-Around Time and Waiting Time function
    int TurnAroundTime[Max_Processes];
    cout << "*********************************************************" << endl;
    Turn_Around_Time(FinishTime, ArrivalTime, process_count, TurnAroundTime);

    // Calling Waiting Time function
    cout << "*********************************************************" << endl;
    Waiting_Time(TurnAroundTime, BurstTime, process_count);
}