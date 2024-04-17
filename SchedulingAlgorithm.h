#ifndef SCHEDULING_ALGORITHMS_H
#define SCHEDULING_ALGORITHMS_H

#include <string>
const int Max_Processes = 100;

void FirstComeFirstServe();
void ShortestJobFirst();
void ShortestRemainingTimeNext();
void Round_Robin();
void Priority_Non_Preemptive();
void Priority_Preemptive();

#endif  // SCHEDULING_ALGORITHMS_H