#ifndef PARAMETER_FUNCTIONS_H
#define PARAMETER_FUNCTIONS_H

void GetArrivalTime(int ArrivalTime[], int process_count);
void GetBurstTime(int BurstTime[], int process_count);
void Finish_Time(int FinishTime[], int process_count);
void Turn_Around_Time(int FinishTime[], int ArrivalTime[], int process_count, int TurnAroundTime[]);
void Waiting_Time(int TurnAroundTime[], int BurstTime[], int process_count);
void GetPriority(int Priority[], int process_count);
void GetPrioritySmaller(int Priority[], int process_count);

#endif  // PARAMETER_FUNCTIONS_H