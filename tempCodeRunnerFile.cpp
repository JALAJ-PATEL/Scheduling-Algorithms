for (const Process& proc : processes) {
        currentTime = max(currentTime, proc.ArrivalTime); // Ensure we wait until the process arrives
        FinishTime[proc.ProcessId] = currentTime + proc.BurstTime;
        currentTime += proc.BurstTime;
    }