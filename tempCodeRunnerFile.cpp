    // Calculate the Finish-Time for SJF Processes
    int FinishTime[Max_Processes], remainingTime[Max_Processes];
    for (int i = 0; i < process_count; i++) {
        remainingTime[i] = BurstTime[i];
    }

    int currentTime = 0;
    int completed = 0;

    while (completed < process_count) {
        int shortestJob = -1;
        int shortestTime = INT_MAX;
        for (int i = 0; i < process_count; i++) {
            if (ArrivalTime[i] <= currentTime && remainingTime[i] < shortestTime && remainingTime[i] > 0) {
                shortestJob = i;
                shortestTime = remainingTime[i];
            }
        }
        if (shortestJob == -1) {
            currentTime++;
        } else {
            FinishTime[shortestJob] = currentTime + remainingTime[shortestJob];
            currentTime = FinishTime[shortestJob];
            remainingTime[shortestJob] = 0;
            completed++;
        }
    }