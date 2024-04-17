#include <bits/stdc++.h>
#include "SchedulingAlgorithm.h"
#include "Parameter_Functions.h"
using namespace std;

void GetArrivalTime(int ArrivalTime[], int process_count){
    cout << "*********************************************************"<<endl;
    for(int i = 1; i <= process_count; i++){
        cout<<"Arrival-Time for Pr-"<<i<<" : ";
        cin>>ArrivalTime[i];
    }
}

void GetBurstTime(int BurstTime[], int process_count){
    cout << "*********************************************************"<<endl;
    for(int i = 1; i <= process_count; i++){
        cout<<"Burst-Time for Pr-"<<i<<" : ";
        cin>>BurstTime[i];
    }
}

void GetPriority(int Priority[], int process_count){
    cout << "*********************************************************"<<endl;
    for(int i = 1; i <= process_count; i++){
        cout<<"Priority for Pr-"<<i<<" : ";
        cin>>Priority[i];
    }
}

void GetPrioritySmaller(int Priority[], int process_count){
    cout << "*********************************************************"<<endl;
    for(int i = 1; i <= process_count; i++){
        cout<<"Priority for Pr-"<<i<<" : ";
        cin>>Priority[i];
    }
}

void Finish_Time(int FinishTime[], int process_count){
    cout << "Finish Time for Individual Processes:" << endl;
    for (int i = 1; i <= process_count; i++) {
        cout << "Finish-Time of Pr-" <<i<< " : " <<FinishTime[i]<<endl;
    }
}

void Turn_Around_Time(int FinishTime[], int ArrivalTime[], int process_count, int TurnAroundTime[]){
    
    int Sum_TAT = 0;

    cout<<"Turn-Around Time for Individual Processes : "<<endl;
    for(int i = 1; i <= process_count; i++){
        TurnAroundTime[i] = FinishTime[i] - ArrivalTime[i];
        cout<<"Turn-Around Time of Pr-"<<i<<" : "<<TurnAroundTime[i]<<endl;

        Sum_TAT += TurnAroundTime[i];
    }

    float AvgTurnAroundTime = static_cast<float>(Sum_TAT) / process_count;
    cout<<"Average TURN-AROUND Time : "<<AvgTurnAroundTime<<endl;
}


void Waiting_Time(int TurnAroundTime[], int BurstTime[], int process_count){
    int WaitingTime[Max_Processes];
    int Sum_WT = 0;

    cout<<"Waiting Time for Individual Processes : "<<endl;
    for(int i = 1; i <= process_count; i++){
        WaitingTime[i] = TurnAroundTime[i] - BurstTime[i];
        cout<<"Waiting Time of Pr-"<<i<<" : "<<WaitingTime[i]<<endl;

        Sum_WT += WaitingTime[i];
    }
    float AvgWaitingTime = static_cast<float>(Sum_WT) / process_count;
    cout<<"Average WAITING Time : "<<AvgWaitingTime<<endl;
}