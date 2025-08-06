#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Structure to represent a process
typedef struct {
    int pid;          // Process ID
    int arrival_time; // Arrival time
    int burst_time;   // Burst time
    int priority;     // Priority (lower number = higher priority)
    int waiting_time; // Waiting time
    int turnaround_time; // Turnaround time
    int completion_time; // Completion time
    int remaining_time;  // Remaining time (for preemptive algorithms)
} Process;

// Function to calculate and display results
void calculate_times(Process processes[], int n) {
    int total_waiting = 0, total_turnaround = 0;
    
    printf("\nPID\tArrival\tBurst\tWaiting\tTurnaround\tCompletion\n");
    printf("--------------------------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        total_waiting += processes[i].waiting_time;
        total_turnaround += processes[i].turnaround_time;
        printf("%d\t%d\t%d\t%d\t%d\t\t%d\n", 
               processes[i].pid, processes[i].arrival_time, 
               processes[i].burst_time, processes[i].waiting_time,
               processes[i].turnaround_time, processes[i].completion_time);
    }
    
    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround / n);
}

// 1. FIRST COME FIRST SERVE (FCFS)
void fcfs(Process processes[], int n) {
    printf("\n=== FIRST COME FIRST SERVE (FCFS) ===\n");
    
    // Sort by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    
    int current_time = 0;
    
    for (int i = 0; i < n; i++) {
        // If current time is less than arrival time, wait
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        
        current_time = processes[i].completion_time;
    }
    
    calculate_times(processes, n);
}

// 2. SHORTEST JOB FIRST (SJF) - Non-preemptive
void sjf_non_preemptive(Process processes[], int n) {
    printf("\n=== SHORTEST JOB FIRST (Non-Preemptive) ===\n");
    
    int completed = 0, current_time = 0;
    int is_completed[n];
    memset(is_completed, 0, sizeof(is_completed));
    
    while (completed != n) {
        int shortest = -1;
        int min_burst = INT_MAX;
        
        // Find the shortest job among arrived processes
        for (int i = 0; i < n; i++) {
            if (!is_completed[i] && processes[i].arrival_time <= current_time) {
                if (processes[i].burst_time < min_burst) {
                    min_burst = processes[i].burst_time;
                    shortest = i;
                }
            }
        }
        
        if (shortest == -1) {
            current_time++;
            continue;
        }
        
        processes[shortest].waiting_time = current_time - processes[shortest].arrival_time;
        processes[shortest].completion_time = current_time + processes[shortest].burst_time;
        processes[shortest].turnaround_time = processes[shortest].completion_time - processes[shortest].arrival_time;
        
        current_time = processes[shortest].completion_time;
        is_completed[shortest] = 1;
        completed++;
    }
    
    calculate_times(processes, n);
}

// 3. SHORTEST REMAINING TIME FIRST (SRTF) - Preemptive SJF
void srtf(Process processes[], int n) {
    printf("\n=== SHORTEST REMAINING TIME FIRST (SRTF) ===\n");
    
    // Initialize remaining times
    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
    }
    
    int completed = 0, current_time = 0;
    int last_process = -1;
    
    while (completed != n) {
        int shortest = -1;
        int min_remaining = INT_MAX;
        
        // Find process with shortest remaining time
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && 
                processes[i].remaining_time > 0 && 
                processes[i].remaining_time < min_remaining) {
                min_remaining = processes[i].remaining_time;
                shortest = i;
            }
        }
        
        if (shortest == -1) {
            current_time++;
            continue;
        }
        
        processes[shortest].remaining_time--;
        current_time++;
        
        if (processes[shortest].remaining_time == 0) {
            processes[shortest].completion_time = current_time;
            processes[shortest].turnaround_time = processes[shortest].completion_time - processes[shortest].arrival_time;
            processes[shortest].waiting_time = processes[shortest].turnaround_time - processes[shortest].burst_time;
            completed++;
        }
    }
    
    calculate_times(processes, n);
}

// 4. PRIORITY SCHEDULING - Non-preemptive
void priority_non_preemptive(Process processes[], int n) {
    printf("\n=== PRIORITY SCHEDULING (Non-Preemptive) ===\n");
    
    int completed = 0, current_time = 0;
    int is_completed[n];
    memset(is_completed, 0, sizeof(is_completed));
    
    while (completed != n) {
        int highest_priority = -1;
        int min_priority = INT_MAX;
        
        // Find highest priority process (lower number = higher priority)
        for (int i = 0; i < n; i++) {
            if (!is_completed[i] && processes[i].arrival_time <= current_time) {
                if (processes[i].priority < min_priority) {
                    min_priority = processes[i].priority;
                    highest_priority = i;
                }
            }
        }
        
        if (highest_priority == -1) {
            current_time++;
            continue;
        }
        
        processes[highest_priority].waiting_time = current_time - processes[highest_priority].arrival_time;
        processes[highest_priority].completion_time = current_time + processes[highest_priority].burst_time;
        processes[highest_priority].turnaround_time = processes[highest_priority].completion_time - processes[highest_priority].arrival_time;
        
        current_time = processes[highest_priority].completion_time;
        is_completed[highest_priority] = 1;
        completed++;
    }
    
    calculate_times(processes, n);
}

// 5. ROUND ROBIN
void round_robin(Process processes[], int n, int quantum) {
    printf("\n=== ROUND ROBIN (Time Quantum = %d) ===\n", quantum);
    
    // Initialize remaining times
    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
    }
    
    int current_time = 0, completed = 0;
    
    while (completed != n) {
        int progress = 0;
        
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= current_time) {
                progress = 1;
                
                if (processes[i].remaining_time > quantum) {
                    current_time += quantum;
                    processes[i].remaining_time -= quantum;
                } else {
                    current_time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    processes[i].completion_time = current_time;
                    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    completed++;
                }
            }
        }
        
        if (!progress) current_time++;
    }
    
    calculate_times(processes, n);
}

// 6. MULTILEVEL QUEUE SCHEDULING
void multilevel_queue(Process processes[], int n) {
    printf("\n=== MULTILEVEL QUEUE SCHEDULING ===\n");
    printf("Queue 0: System processes (Priority 0-1)\n");
    printf("Queue 1: Interactive processes (Priority 2-3)\n");
    printf("Queue 2: Batch processes (Priority 4+)\n\n");
    
    // Separate processes into queues based on priority
    Process queue0[n], queue1[n], queue2[n];
    int q0_count = 0, q1_count = 0, q2_count = 0;
    
    for (int i = 0; i < n; i++) {
        if (processes[i].priority <= 1) {
            queue0[q0_count++] = processes[i];
        } else if (processes[i].priority <= 3) {
            queue1[q1_count++] = processes[i];
        } else {
            queue2[q2_count++] = processes[i];
        }
    }
    
    int current_time = 0;
    
    // Process Queue 0 (FCFS)
    printf("Processing Queue 0 (System):\n");
    for (int i = 0; i < q0_count; i++) {
        if (current_time < queue0[i].arrival_time) {
            current_time = queue0[i].arrival_time;
        }
        queue0[i].waiting_time = current_time - queue0[i].arrival_time;
        queue0[i].completion_time = current_time + queue0[i].burst_time;
        queue0[i].turnaround_time = queue0[i].completion_time - queue0[i].arrival_time;
        current_time = queue0[i].completion_time;
    }
    
    // Process Queue 1 (Round Robin with quantum 4)
    printf("Processing Queue 1 (Interactive):\n");
    for (int i = 0; i < q1_count; i++) {
        queue1[i].remaining_time = queue1[i].burst_time;
    }
    
    int q1_completed = 0;
    while (q1_completed != q1_count) {
        for (int i = 0; i < q1_count; i++) {
            if (queue1[i].remaining_time > 0 && queue1[i].arrival_time <= current_time) {
                if (queue1[i].remaining_time > 4) {
                    current_time += 4;
                    queue1[i].remaining_time -= 4;
                } else {
                    current_time += queue1[i].remaining_time;
                    queue1[i].remaining_time = 0;
                    queue1[i].completion_time = current_time;
                    queue1[i].turnaround_time = queue1[i].completion_time - queue1[i].arrival_time;
                    queue1[i].waiting_time = queue1[i].turnaround_time - queue1[i].burst_time;
                    q1_completed++;
                }
            }
        }
        if (q1_completed < q1_count && current_time < 100) current_time++; // Prevent infinite loop
    }
    
    // Process Queue 2 (FCFS)
    printf("Processing Queue 2 (Batch):\n");
    for (int i = 0; i < q2_count; i++) {
        if (current_time < queue2[i].arrival_time) {
            current_time = queue2[i].arrival_time;
        }
        queue2[i].waiting_time = current_time - queue2[i].arrival_time;
        queue2[i].completion_time = current_time + queue2[i].burst_time;
        queue2[i].turnaround_time = queue2[i].completion_time - queue2[i].arrival_time;
        current_time = queue2[i].completion_time;
    }
    
    // Display results for each queue
    if (q0_count > 0) {
        printf("\nQueue 0 Results:\n");
        calculate_times(queue0, q0_count);
    }
    if (q1_count > 0) {
        printf("\nQueue 1 Results:\n");
        calculate_times(queue1, q1_count);
    }
    if (q2_count > 0) {
        printf("\nQueue 2 Results:\n");
        calculate_times(queue2, q2_count);
    }
}

int main() {
    int n = 5; // Number of processes
    
    // Sample processes
    Process processes[] = {
        {1, 0, 8, 2, 0, 0, 0, 0},   // PID, Arrival, Burst, Priority
        {2, 1, 4, 1, 0, 0, 0, 0},
        {3, 2, 9, 3, 0, 0, 0, 0},
        {4, 3, 5, 4, 0, 0, 0, 0},
        {5, 4, 2, 0, 0, 0, 0, 0}
    };
    
    Process temp[5]; // Temporary array for each algorithm
    
    printf("SAMPLE PROCESSES:\n");
    printf("PID\tArrival\tBurst\tPriority\n");
    printf("--------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrival_time, 
               processes[i].burst_time, processes[i].priority);
    }
    
    // Test each algorithm
    
    // 1. FCFS
    memcpy(temp, processes, sizeof(processes));
    fcfs(temp, n);
    
    // 2. SJF Non-preemptive
    memcpy(temp, processes, sizeof(processes));
    sjf_non_preemptive(temp, n);
    
    // 3. SRTF (Preemptive SJF)
    memcpy(temp, processes, sizeof(processes));
    srtf(temp, n);
    
    // 4. Priority Non-preemptive
    memcpy(temp, processes, sizeof(processes));
    priority_non_preemptive(temp, n);
    
    // 5. Round Robin
    memcpy(temp, processes, sizeof(processes));
    round_robin(temp, n, 3);
    
    // 6. Multilevel Queue
    memcpy(temp, processes, sizeof(processes));
    multilevel_queue(temp, n);
    
    return 0;
}


 1. Shortest Job First (SJF) - Non-Preemptive
* **How it Works:** The scheduler selects the process from the ready queue that has the smallest **total burst time**. Once selected, the process runs until it is completely finished.
* **Analogy:** A doctor at a walk-in clinic who decides to treat all the patients with the quickest, simplest problems first to clear the waiting room faster.
* **Key Traits:**
    * **Non-Preemptive:** Doesn't interrupt a running process.
    * **Pro:** Provably optimal in minimizing the average waiting time.
    * **Con:** Can lead to **starvation** if short processes keep arriving, making a long process wait forever.

***

 2. Shortest Remaining Time First (SRTF) - Preemptive
* **How it Works:** This is the preemptive version of SJF. The scheduler always runs the process that has the least amount of **time left to execute**. It will interrupt (preempt) a currently running process if a new process arrives with a shorter remaining time.
* **Analogy:** An express checkout cashier who will pause scanning a large grocery order to let someone with just one item cut in and finish quickly.
* **Key Traits:**
    * **Preemptive:** Can interrupt a running process.
    * **Pro:** Gives an even better average waiting time than non-preemptive SJF.
    * **Con:** High overhead from frequent context switching and a high risk of **starvation** for longer processes.

***

 3. Priority Scheduling - Non-Preemptive
* **How it Works:** Each process is assigned a priority. The scheduler always picks the waiting process with the **highest priority** (typically, the lowest priority number). It runs that process to completion. Ties are broken by FCFS.
* **Analogy:** Boarding an airplane. First-class passengers (high priority) board before everyone else. Once a passenger is on the jet bridge, they aren't called back.
* **Key Traits:**
    * **Non-Preemptive:** Runs until finished.
    * **Pro:** Allows critical processes to be run first.
    * **Con:** Can lead to **starvation** of low-priority processes.

***

 4. Multilevel Queue Scheduling
* **How it Works:** The ready queue is split into multiple separate queues (e.g., a high-priority "interactive" queue and a low-priority "batch" queue). Each queue has its own scheduling algorithm (e.g., Round Robin for interactive, FCFS for batch). The scheduler gives preference to higher-priority queues.
* **Analogy:** An airport with separate, prioritized boarding lines. The first-class line is always served before the economy line. Processes don't move between lines.
* **Key Traits:**
    * **Preemptive between queues:** A batch process will be interrupted if an interactive one arrives.
    * **Pro:** Very flexible; can assign the right scheduling policy to each process type.
    * **Con:** Can lead to **starvation** of the lower-priority queues if high-priority queues are always busy.

***

 5. Round Robin (RR)
* **How it Works:** A preemptive algorithm that gives each process a small, fixed time slice called a **time quantum**. It picks a process, lets it run for one quantum, and if it's not done, moves it to the back of the ready queue.
* **Analogy:** A group of people taking turns telling a story. Each person gets to speak for exactly one minute before the turn passes to the next person in the circle.
* **Key Traits:**
    * **Preemptive:** Always interrupts a process after its time quantum expires.
    * **Pro:** Very fair, no starvation, and excellent response time for interactive systems.
    * **Con:** Performance is highly dependent on the quantum size. Too small a quantum causes too much overhead from context switching.
    * **Con:** If the quantum is too large, it behaves like FCFS, leading to poor response times for interactive processes.
    * **Con:** Can lead to high turnaround times for long processes if the quantum is too small.
    * **Con:** Can lead to high overhead from frequent context switching, especially with many short processes.




--->    Multi Tasking and Multi Processing    <---

----------------------------------------------------------------------------------------------------------------------------
Feature	            Multitasking	                                        Multiprocessing
----------------------------------------------------------------------------------------------------------------------------
CPU Cores	        One	                                                Two or more
Execution Style	    Concurrent (tasks take turns rapidly)	                Parallel (tasks run at the same time)
Core Idea	        Context Switching	                                    Parallel Processing
Goal	            Provide responsiveness and interactivity.	            Increase raw computational power and speed.
Analogy	            One person juggling multiple jobs.	                    A team of people working on different jobs.
----------------------------------------------------------------------------------------------------------------------------


Thread Lifecycle

A thread moves through several states from its creation to its termination.

1) New: The thread has been created but has not yet been started. It exists as an object but is not yet eligible to run.
2) Runnable (Ready): The thread is ready to execute and is waiting for the CPU scheduler to select it. Calling the start() method on a new thread moves it to this state.
3) Running: The thread is currently being executed by the CPU. The scheduler can move it from Runnable to Running.
4) Blocked (Waiting): The thread is temporarily inactive because it's waiting for something to happen. For example, it might be waiting for an I/O operation to complete (like reading a file) or waiting to acquire a lock held by another thread. Once the event it's waiting for occurs, it moves back to the Runnable state.
5) Terminated (Dead): The thread has completed its execution or has otherwise been terminated. It cannot be run again.



Starvation typically occurs in scheduling algorithms where a flawed or biased selection process can cause certain processes to be overlooked indefinitely. The most common cause is priority-based scheduling.

Imagine a system where high-priority processes are always executed before low-priority ones. If there is a continuous stream of high-priority tasks entering the system, the scheduler will always be busy serving them. A low-priority process waiting in the queue will never get its turn, even though it's ready to run