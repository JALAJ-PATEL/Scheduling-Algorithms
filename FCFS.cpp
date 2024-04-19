#include <bits/stdc++.h>
#include "SchedulingAlgorithm.h"
#include "Parameter_Functions.h"
using namespace std;

void FirstComeFirstServe(){
    int process_count;
    cout<<"Enter the Number of Process : "<<endl;
    cin>>process_count;

    // Taking Input for the Number of Processes - Arrival & Burst Time
    int ArrivalTime[Max_Processes], BurstTime[Max_Processes];
    GetArrivalTime(ArrivalTime, process_count); 
    GetBurstTime(BurstTime, process_count);

    // Calculating the Finish-Time for FCFS Processes
    int FinishTime[Max_Processes];
    FinishTime[0] = ArrivalTime[0] + BurstTime[0];
    for(int i = 1; i <= process_count; i++){
        FinishTime[i] = max(ArrivalTime[i], FinishTime[i-1]) + BurstTime[i]; 
    }

    // Calling Finish Time function
    cout << "*********************************************************"<<endl;
    Finish_Time(FinishTime, process_count);

    // Calling Turn-Around Time function
    int TurnAroundTime[Max_Processes];
    cout << "*********************************************************"<<endl;
    Turn_Around_Time(FinishTime, ArrivalTime, process_count, TurnAroundTime);

    // Calling Waiting Time function
    cout << "*********************************************************"<<endl;
    Waiting_Time(TurnAroundTime, BurstTime, process_count);
}