<!DOCTYPE html>
<html lang="en">

<body>

  <h1>Scheduling Algorithms README</h1>

  <h2>First Come First Serve (FCFS)</h2>
  <p>FCFS is a non-preemptive scheduling algorithm where processes are executed based on their arrival order.</p>
  <h3>Selection Criteria</h3>
  <p>Processes are selected based on their arrival time. The process that arrives first gets executed first.</p>
  <h3>Implementation</h3>
  <p>Implementation can be found in the <code>FCFS.cpp</code> file.</p>

  <h2>Shortest Job First (SJF)</h2>
  <p>SJF is a non-preemptive scheduling algorithm where the process with the shortest burst time is executed first.</p>
  <h3>Selection Criteria</h3>
  <p>Processes are selected based on their burst time. The process with the shortest burst time is executed first.</p>
  <h3>Implementation</h3>
  <p>Implementation can be found in the <code>SJF.cpp</code> file.</p>

  <h2>Shortest Remaining Time Next (SRTN)</h2>
  <p>SRTN is a preemptive scheduling algorithm where the process with the shortest remaining burst time is executed.</p>
  <h3>Selection Criteria</h3>
  <p>Processes are selected based on their remaining burst time. The process with the shortest remaining burst time is executed next.</p>
  <h3>Implementation</h3>
  <p>Implementation can be found in the <code>SRTN.cpp</code> file.</p>

  <h2>Round-Robin</h2>
  <p>Round-Robin is a preemptive scheduling algorithm where each process is executed for a fixed time slice.</p>
  <h3>Selection Criteria</h3>
  <p>Processes are selected in a circular manner. Each process gets a turn for a fixed time slice called the quantum.</p>
  <h3>Implementation</h3>
  <p>Implementation can be found in the <code>Round_Robin.cpp</code> file.</p>

  <h2>Priority Scheduling - Non-Preemptive</h2>
  <p>Priority Non-Preemptive is a scheduling algorithm where processes are executed based on their priority, and once a process starts execution, it runs to completion.</p>
  <h3>Selection Criteria</h3>
  <p>Processes are selected based on their priority value. Higher priority processes are executed first.</p>
  <h3>Implementation</h3>
  <p>Implementation can be found in the <code>Priority_NonPreemptive.cpp</code> file.</p>

  <h2>Priority Scheduling - Preemptive</h2>
  <p>Priority Preemptive is a scheduling algorithm where a process can be interrupted and moved to the ready queue if a higher priority process arrives.</p>
  <h3>Selection Criteria</h3>
  <p>Processes are selected based on their priority value. If a higher priority process arrives, it preempts the currently running process.</p>
  <h3>Implementation</h3>
  <p>Implementation can be found in the <code>Priority_Preemptive.cpp</code> file.</p>

  <h2>Usage</h2>
  <p>To use these algorithms, follow the steps below:</p>
  <ol>
    <li>Compile the source files using a C++ compiler.</li>
    <li>Type this line in the terminal of your IDE as g++ compile will include all the .cpp files and merge them to execute by detecting their path from header files( i.e. <code>SchedulingAlgorithm.h</code> and <code>Parameter_Funtions.h</code>)
    "g++ FCFS.cpp SJF.cpp SRTN.cpp Round_Robin.cpp Priority_NonPreemptive.cpp Priority_Preemptive.cpp SchedulingAlgorithms.cpp Parameter_Functions.cpp -o Scheduler"</li>
    <li>Press ENTER</li>
    <li>Type "./Scheduler" in the new line of terminal</li>
    <li>This will start the Execution and List of Scheduling Algorithms will be displayed.</li>
    <li>Choose the desired scheduling algorithm from the menu.</li>
    <li>Enter the required parameters such as arrival time, burst time, etc., as prompted.</li>
    <li>View the results including finish time, turnaround time, and waiting time.</li>
  </ol>

  <h2>Contribution</h2>
  <p>Contributions to improve the implementations or add new algorithms are welcome! Fork this repository, make your changes, and submit a pull request.</p>

</body>

</html>