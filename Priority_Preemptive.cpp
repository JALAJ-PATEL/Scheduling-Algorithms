#include <bits/stdc++.h>
#include "SchedulingAlgorithm.h"
#include "Parameter_Functions.h"
using namespace std;

void Priority_Preemptive() {
    int process_count;
    cout << "Enter the Number of Processes: ";
    cin >> process_count;

    int priority_choice;
    cout << "Enter 1 for Greater Number as Higher Priority\n\t\tOR\nEnter 2 for Smaller Number as Higher Priority.\n";
    cin >> priority_choice;

    // Taking Input for the Number of Processes - Arrival & Burst Time
    int ArrivalTime[Max_Processes], BurstTime[Max_Processes], Priority[Max_Processes];
    GetArrivalTime(ArrivalTime, process_count);
    GetBurstTime(BurstTime, process_count);

    if (priority_choice == 1) {
        GetPriority(Priority, process_count);
    } else if (priority_choice == 2) {
        GetPrioritySmaller(Priority, process_count);
    } else {
        cout << "Invalid choice. Exiting..." << endl;
        return;
    }

    // Initialize remaining time for each process
    int RemainingTime[Max_Processes];
    for (int i = 1; i <= process_count; i++) {
        RemainingTime[i] = BurstTime[i];
    }

    // Initialize FinishTime as an array
    int FinishTime[Max_Processes] = {0}; // Initialize all elements to 0

    int Time = 0;
    int completed = 0;
    while (completed < process_count) {
        int MaxPriority = (priority_choice == 1) ? INT_MIN : INT_MAX;
        int MaxPriorityIndex = -1;

        // Find the process with the highest priority that has arrived and is not completed
        for (int j = 1; j <= process_count; j++) {
            if (ArrivalTime[j] <= Time && RemainingTime[j] > 0) {
                if (priority_choice == 1 && Priority[j] > MaxPriority) {
                    MaxPriority = Priority[j];
                    MaxPriorityIndex = j;
                } else if (priority_choice == 2 && Priority[j] < MaxPriority) {
                    MaxPriority = Priority[j];
                    MaxPriorityIndex = j;
                }
            }
        }

        // If no process is available to execute, increment the time and continue
        if (MaxPriorityIndex == -1) {
            Time++;
            continue;
        }

        // Execute the process with the highest priority for one time unit
        Time += 1;
        RemainingTime[MaxPriorityIndex] -= 1;

        // If the process is completed, update its finish time
        if (RemainingTime[MaxPriorityIndex] == 0) {
            FinishTime[MaxPriorityIndex] = Time;
            completed++;
        }
    }

    // Calling Finish Time function
    cout << "*********************************************************"<<endl;
    Finish_Time(FinishTime, process_count);

    // Calling Turn-Around Time function
    int TurnAroundTime[Max_Processes];
    cout << "*********************************************************" << endl;
    Turn_Around_Time(FinishTime, ArrivalTime, process_count, TurnAroundTime);

    // Calling Waiting Time function
    cout << "*********************************************************" << endl;
    Waiting_Time(TurnAroundTime, BurstTime, process_count);
}