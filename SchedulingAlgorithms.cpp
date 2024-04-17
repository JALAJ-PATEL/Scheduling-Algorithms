#include <bits/stdc++.h>
#include "SchedulingAlgorithm.h"

using namespace std;

const string ALGORITHMS[6] = {"FCFS", "SJF", "SRTN", "Round-Robin", "Priority-Preemptive", "Priority-NonPreemptive"};

int main()
{
    cout << "*********************************************************"<<endl;
    cout << "Select a Scheduling Algorithm:" << endl;
    cout << "1. FCFS - First Come First Serve." << endl;
    cout << "2. SJF - Shortest Job First." << endl;
    cout << "3. SRTN - Shortest Remaining Time Next." << endl;
    cout << "4. Round-Robin." << endl;
    cout << "5. Priority Scheduling - Non-Preemptive." << endl;
    cout << "6. Priority Scheduling - Preemptive." << endl;
    cout << "*********************************************************"<<endl;

    int choice;
    cin >> choice;

    if(choice < 1 || choice > 6){
        cout<< "Invalid choice! \nPlease Select it from Index(1 to 6)";
        return 1;
    }

    switch (choice) {
        case 1: // FCFS
            FirstComeFirstServe();
            break;

        case 2: // SJF
            ShortestJobFirst();
            break;

        case 3: // SRTN
            ShortestRemainingTimeNext();
            break;

        case 4: // Round-Robin
            Round_Robin();
            break;

        case 5: // Priority-NonPreemptive
            Priority_Non_Preemptive();
            break;
        
        case 6: // Priority-NonPreemptive
            Priority_Preemptive();
            break;
    }

    return 0;
}