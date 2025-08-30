
------>     Schedule Algorithms in C    <------

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
How it Works: The scheduler selects the process from the ready queue that has the smallest total burst time. Once selected, the process runs until it is completely finished.
Analogy: A doctor at a walk-in clinic who decides to treat all the patients with the quickest, simplest problems first to clear the waiting room faster.
Key Traits:
    Non-Preemptive: Doesn't interrupt a running process.
    Pro: Provably optimal in minimizing the average waiting time.
    Con: Can lead to starvation if short processes keep arriving, making a long process wait forever.


 2. Shortest Remaining Time First (SRTF) - Preemptive
How it Works: This is the preemptive version of SJF. The scheduler always runs the process that has the least amount of time left to execute. It will interrupt (preempt) a currently running process if a new process arrives with a shorter remaining time.
Analogy: An express checkout cashier who will pause scanning a large grocery order to let someone with just one item cut in and finish quickly.
Key Traits:
    Preemptive: Can interrupt a running process.
    Pro: Gives an even better average waiting time than non-preemptive SJF.
    Con: High overhead from frequent context switching and a high risk of starvation for longer processes.


 3. Priority Scheduling - Non-Preemptive
How it Works: Each process is assigned a priority. The scheduler always picks the waiting process with the highest priority (typically, the lowest priority number). It runs that process to completion. Ties are broken by FCFS.
Analogy: Boarding an airplane. First-class passengers (high priority) board before everyone else. Once a passenger is on the jet bridge, they aren't called back.
Key Traits:
    Non-Preemptive: Runs until finished.
    Pro: Allows critical processes to be run first.
    Con: Can lead to starvation of low-priority processes.


 4. Multilevel Queue Scheduling
How it Works: The ready queue is split into multiple separate queues (e.g., a high-priority "interactive" queue and a low-priority "batch" queue). Each queue has its own scheduling algorithm (e.g., Round Robin for interactive, FCFS for batch). The scheduler gives preference to higher-priority queues.
Analogy: An airport with separate, prioritized boarding lines. The first-class line is always served before the economy line. Processes don't move between lines.
Key Traits:
    Preemptive between queues: A batch process will be interrupted if an interactive one arrives.
    Pro: Very flexible; can assign the right scheduling policy to each process type.
    Con: Can lead to starvation of the lower-priority queues if high-priority queues are always busy.


 5. Round Robin (RR)
How it Works: A preemptive algorithm that gives each process a small, fixed time slice called a time quantum. It picks a process, lets it run for one quantum, and if it's not done, moves it to the back of the ready queue.
Analogy: A group of people taking turns telling a story. Each person gets to speak for exactly one minute before the turn passes to the next person in the circle.
Key Traits:
    Preemptive: Always interrupts a process after its time quantum expires.
    Pro: Very fair, no starvation, and excellent response time for interactive systems.
    Con: Performance is highly dependent on the quantum size. Too small a quantum causes too much overhead from context switching.
    Con: If the quantum is too large, it behaves like FCFS, leading to poor response times for interactive processes.
    Con: Can lead to high turnaround times for long processes if the quantum is too small.
    Con: Can lead to high overhead from frequent context switching, especially with many short processes.



------>     Multi Tasking and Multi Processing      <------

----------------------------------------------------------------------------------------------------------------------------
Feature	            Multitasking	                                        Multiprocessing
----------------------------------------------------------------------------------------------------------------------------
CPU Cores	        One	                                                Two or more
Execution Style	    Concurrent (tasks take turns rapidly)	                Parallel (tasks run at the same time)
Core Idea	        Context Switching	                                    Parallel Processing
Goal	            Provide responsiveness and interactivity.	            Increase raw computational power and speed.
Analogy	            One person juggling multiple jobs.	                    A team of people working on different jobs.
----------------------------------------------------------------------------------------------------------------------------


------>     Thread Lifecycle       <------

A thread moves through several states from its creation to its termination.

1) New: The thread has been created but has not yet been started. It exists as an object but is not yet eligible to run.
2) Runnable (Ready): The thread is ready to execute and is waiting for the CPU scheduler to select it. Calling the start() method on a new thread moves it to this state.
3) Running: The thread is currently being executed by the CPU. The scheduler can move it from Runnable to Running.
4) Blocked (Waiting): The thread is temporarily inactive because it's waiting for something to happen. For example, it might be waiting for an I/O operation to complete (like reading a file) or waiting to acquire a lock held by another thread. Once the event it's waiting for occurs, it moves back to the Runnable state.
5) Terminated (Dead): The thread has completed its execution or has otherwise been terminated. It cannot be run again.


Starvation typically occurs in scheduling algorithms where a flawed or biased selection process can cause certain 
processes to be overlooked indefinitely. The most common cause is priority-based scheduling.

Imagine a system where high-priority processes are always executed before low-priority ones. If there is a continuous stream of high-priority tasks entering the system, the scheduler will always be busy serving them. 
A low-priority process waiting in the queue will never get its turn, even though it's ready to run. This leads to starvation, where the low-priority process is starved of CPU time and never gets executed.


'------>     What is IPC?       <------

Inter Process Communication (IPC) is a set of methods used by processes to communicate with each other.
IPC is essential in multitasking and multiprocessing systems where multiple processes need to share data or synchronize their actions.

Inter-Process Communication (IPC) refers to the mechanisms an operating system provides to allow different 
processes to manage shared data and communicate with each other. By default, processes are isolated from each 
other for security and stability. IPC provides a safe and structured way to break this isolation when needed.

1. Pipes 
-----------
 
Pipes are the simplest form of IPC. A pipe is a unidirectional (one-way) communication channel that connects two related processes (usually a parent and child). Data is written to one end and read from the other as a continuous stream of bytes.

  Key Characteristics:
      Unidirectional: Data flows in one direction only.
      Related Processes: Requires a common ancestor process (usually created before a `fork()`).
      Byte Stream: No concept of message boundaries. If you write 10 bytes then 20 bytes, the reader might get all 30 bytes in one go.
      Synchronized: The OS handles it. The `read()` call will wait if the pipe is empty.
  Best For: Simple, one-way communication between a parent and child process, like redirecting the output of one command to the input of another (`ls -l | grep .c`).

# Example Code with Comments

#include <stdio.h>
#include <unistd.h>

int main() {
    int pipefd[2]; // Array to hold file descriptors: pipefd[0] is for reading, pipefd[1] is for writing.
    pid_t pid;
    char buffer[30];

    // Create the pipe. This must be done BEFORE forking.
    pipe(pipefd);

    // Create a child process. Both parent and child now have the pipe file descriptors.
    pid = fork();

    if (pid == 0) {
        // --- CHILD PROCESS --- (Will only read)
        // Close the unused write end of the pipe. It's good practice.
        close(pipefd[1]);

        // Read from the pipe. This call will BLOCK (wait) until the parent writes something.
        read(pipefd[0], buffer, sizeof(buffer));
        printf("CHILD RECEIVED: %s\n", buffer);

        // Clean up by closing the read end.
        close(pipefd[0]);

    } else {
        // --- PARENT PROCESS --- (Will only write)
        // Close the unused read end of the pipe.
        close(pipefd[0]);

        // Write a string into the pipe. This data is now available for the child to read.
        write(pipefd[1], "Hello from parent", 18);

        // Close the write end. This sends an "end-of-file" to the reader.
        close(pipefd[1]);
    }
    return 0;
}


2. Message Queues
-------------------

A message queue is a linked list of messages maintained by the kernel. Any process with the right permissions can add or remove messages from the queue. Unlike pipes, processes dont need to be related.

  Analogy: A restaurant ticket rail. Waiters (producers) put order tickets (messages) on the rail. Chefs (consumers) pick them up when ready.
  Key Characteristics:
      Unrelated Processes: Any process can access a queue if it has the key.
      Message Boundaries: Preserves message structure. If you send a 10-byte message, you receive a 10-byte message.
      Asynchronous: The sender can place a message and continue without waiting for a receiver.
      Persistent: The queue and its messages exist in the kernel and persist even if no process is currently using them.
      Types/Priorities: Messages can be tagged with a type, allowing receivers to selectively retrieve messages.
  Best For: Communication between multiple, unrelated processes that might not be running at the same time. Good for when you need structured, message-based communication.


3. Shared Memory
-------------------

Shared memory is the fastest IPC method. It allows multiple processes to map the same block of physical RAM into their own virtual address spaces. Once mapped, communication is as fast as reading from or writing to a regular variable.

  Analogy: A shared whiteboard. Everyone in the room can read from or write to the same board instantly.
  Key Characteristics:
      Fastest IPC: No kernel involvement is needed after the initial setup. Data is not copied.
      Unrelated Processes: Any process can attach a shared memory segment.
      No Synchronization: This is its biggest challenge. It provides no mechanism to prevent two processes from writing at the same time (a race condition). You must implement your own synchronization using tools like semaphores or mutexes.
  Best For: High-performance applications sharing large amounts of data, like databases, video processing, or scientific computing.



------->    Thread Synchronization      <-------

Mutex (Mutual Exclusion)

A mutex acts like a key to a specific section of code, ensuring that only one thread can execute it at a time. It is a simple binary lock (locked or unlocked). 
A thread must acquire the lock before entering the critical section and release it upon exiting. Importantly, only the thread that locked the mutex is allowed to unlock it. 
Other threads that try to acquire a locked mutex will be put to sleep by the OS until the lock is released.

Semaphore

A semaphore is a more general synchronization tool that acts as a counter for a pool of available resources. 
It is used to control access for a limited number of threads.

Counting Semaphore: Manages access to 'N' identical resources. A thread "waits" on the semaphore, which decrements the count. If the count is zero, the thread sleeps. When a thread is finished, it "posts" to the semaphore, incrementing the count and potentially waking up a sleeping thread.
Binary Semaphore: A semaphore with a count of 1, which behaves very similarly to a mutex.

Spinlock

A spinlock is a type of lock where a waiting thread does not go to sleep. Instead, it "spins" in a tight loop, repeatedly checking if the lock is available. 
This busy-waiting consumes CPU cycles but avoids the overhead of a context switch (the process of the OS putting a thread to sleep and waking it up later). 
Spinlocks are highly efficient but only suitable for critical sections that are extremely short.

Condition Variable

A condition variable allows threads to synchronize based on the actual state of data, not just on access control. It enables threads to wait efficiently until a specific condition becomes true. 
It must always be used in conjunction with a mutex. A thread locks the mutex, checks a condition, and if the condition isn't met, it calls `wait()`. 
This atomically releases the mutex and puts the thread to sleep. Another thread can later change the data, lock the mutex, and then call `signal()` or `broadcast()` on the condition variable to wake up the waiting thread(s).


------>     Memory Management in C    ------

 Stack Memory
The stack is a region of memory that stores temporary variables created by functions. It operates on a Last-In-First-Out (LIFO) principle.

Characteristics:
- Automatic management: Variables are automatically created when entering a function and destroyed when exiting
- Fast access: Direct memory access through stack pointer manipulation
- Limited size: Typically 1-8 MB per thread
- Stores: Function parameters, return addresses, local variables

Example:

void function1() {
    int a = 10;        // Allocated on stack
    char buffer[100];  // Allocated on stack
    function2();       // Stack grows
}  // Variables automatically deallocated when function ends

void function2() {
    int b = 20;        // New stack frame created
    return;            // Stack frame destroyed
}


Stack Layout:

High Memory Address
|------------------|
| function2 frame  |  <- Current Stack Pointer
|   int b = 20     |
|------------------|
| function1 frame  |
|   char buffer[]  |
|   int a = 10     |
|------------------|
| Return address   |
|------------------|
Low Memory Address


 Heap Memory
The heap is a region for dynamic memory allocation where data can be allocated and deallocated in any order.

Characteristics:
- Manual management: Programmer must explicitly allocate and free memory
- Slower access: Requires pointer dereferencing and memory management overhead
- Large size: Limited only by available system memory
- Stores: Dynamic data structures, large objects

Example:

void heapExample() {
    // Dynamic allocation on heap
    int* ptr = (int*)malloc(sizeof(int) * 100);
    
    if (ptr != NULL) {
        ptr[0] = 42;  // Accessing heap memory
        ptr[99] = 100;
        
        // Must manually free
        free(ptr);
    }
}

## Dynamic vs Static Memory Allocation

 Static Memory Allocation
Memory is allocated at compile time and remains fixed throughout program execution.

Characteristics:
- Compile-time allocation: Size determined before program runs
- Fixed size: Cannot be changed during execution
- Automatic management: No need for malloc/free
- Fast access: Direct memory access

Example:

// Global static allocation
int globalArray[1000];  // 4000 bytes allocated at compile time

void staticExample() {
    // Local static allocation
    static int counter = 0;     // Allocated once, persists across calls
    int localArray[50];         // Stack allocation, fixed size
    
    counter++;
}

 Dynamic Memory Allocation
Memory is allocated at runtime based on program needs.

Characteristics:
- Runtime allocation: Size can be determined during execution
- Variable size: Can allocate exactly what's needed
- Manual management: Requires explicit allocation/deallocation
- Flexible: Can grow/shrink as needed

Example:

void dynamicExample() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    
    // Dynamic allocation based on user input
    int* dynamicArray = (int*)malloc(size * sizeof(int));
    
    if (dynamicArray != NULL) {
        // Use the array
        for (int i = 0; i < size; i++) {
            dynamicArray[i] = i * 2;
        }
        
        // Resize if needed
        dynamicArray = (int*)realloc(dynamicArray, size * 2 * sizeof(int));
        
        free(dynamicArray);  // Must free manually
    }
}


## Fragmentation

Fragmentation occurs when memory becomes divided into small, unusable pieces.

 Internal Fragmentation
Wasted space within allocated memory blocks.

Causes:
- Fixed-size allocation schemes
- Padding for alignment requirements
- Allocating more memory than requested

Example:

// If allocator uses 64-byte blocks
char* ptr = malloc(10);  // Only 10 bytes needed
// But 64 bytes allocated, 54 bytes wasted (internal fragmentation)

Visual representation:

|-- 64-byte block --|
|used(10)|waste(54) |


 External Fragmentation
Free memory exists but is scattered in small, non-contiguous chunks.

Example scenario:

void fragmentationDemo() {
    char* ptr1 = malloc(100);  // Block A
    char* ptr2 = malloc(100);  // Block B  
    char* ptr3 = malloc(100);  // Block C
    
    free(ptr2);  // Frees middle block
    
    // Now we have: [A][FREE(100)][C]
    // If we need 200 bytes, we can't allocate even though
    // total free space might be available
    char* ptr4 = malloc(200);  // Might fail due to fragmentation
}

Memory layout:

Before fragmentation:
|Block A(100)|Block B(100)|Block C(100)|Free Space|

After freeing Block B:
|Block A(100)|Free(100)   |Block C(100)|Free Space|
             ↑ Can't use for large allocation


 Solutions to Fragmentation:

1. Compaction: Moving allocated blocks to eliminate gaps
2. Buddy System: Using power-of-2 sized blocks
3. Memory Pools: Pre-allocating fixed-size chunks

## Memory Protection and Segmentation

 Memory Protection
Mechanisms to prevent unauthorized access to memory regions.

Protection Mechanisms:

1. Base and Limit Registers

// Each process has base and limit registers
struct process_memory {
    void* base_address;     // Starting address
    size_t limit;          // Maximum offset
};

// Hardware checks on every memory access:
// if (address < base || address >= base + limit)
//     generate_protection_fault();
```

2. Protection Bits
```c
// Memory pages have protection attributes
typedef enum {
    READ_ONLY    = 0x1,
    READ_WRITE   = 0x3,
    EXECUTE      = 0x4,
    USER_ACCESS  = 0x8
} protection_flags_t;
```

 Segmentation
Dividing program memory into logical segments with different purposes.

Common Segments:
- Code Segment: Contains executable instructions
- Data Segment: Contains global and static variables
- Stack Segment: Contains local variables and function calls
- Heap Segment: Contains dynamically allocated memory

Example Program Layout:

// Global variables (Data segment)
int globalVar = 42;
static int staticVar = 100;

// Function code (Code segment)
void exampleFunction() {
    // Local variables (Stack segment)
    int localVar = 10;
    char buffer[256];
    
    // Dynamic allocation (Heap segment)
    int* heapVar = malloc(sizeof(int));
    *heapVar = 20;
    
    free(heapVar);
}

int main() {
    exampleFunction();
    return 0;
}


Memory Layout with Segmentation:

High Memory
|-------------------|
| Stack Segment     | ← Growing downward
| (Local variables) |
|-------------------|
| Free Space        |
|-------------------|
| Heap Segment      | ← Growing upward
| (malloc'd memory) |
|-------------------|
| Data Segment      |
| (Global vars)     |
|-------------------|
| Code Segment      |
| (Program code)    |
|-------------------|
Low Memory



-------> what is paging in os <--------

Paging is a memory management scheme used by operating systems to eliminate the need for contiguous allocation of physical memory. It allows processes to be stored in non-contiguous memory blocks, optimizing memory utilization and enabling features like virtual memory.

---

### Core Concepts
1. Pages and Frames:
   - Logical Memory (Virtual Memory): Divided into fixed-size blocks called pages.
   - Physical Memory (RAM): Divided into fixed-size blocks called frames, matching page sizes.
   - *Example*: If a system uses 4KB pages, both logical and physical memory are split into 4KB chunks.

2. Page Table:
   - A data structure maintained by the OS for each process.
   - Maps logical page numbers to physical frame numbers.
   - Each entry contains metadata (e.g., validity, permissions).

3. Address Translation:
   - A logical address is split into:
     - Page Number: Indexes the page table.
     - Offset: Specifies the location within the page/frame.
   - The OS translates the logical address to a physical address using the page table.

---

### How Paging Manages Memory
#### Step-by-Step Process
1. Process Initialization:
   - When a process starts, the OS allocates frames in physical memory.
   - The page table is initialized with mappings between logical pages and physical frames.

2. Address Translation:
   - Suppose a process references a logical address `0x12345`.
   - The OS splits this into:
     - Page Number: `0x12` (determines which page table entry to use).
     - Offset: `0x345` (location within the page).
   - The page table entry for page `0x12` returns a frame number (e.g., `0x56`).
   - The physical address is calculated as:  
     `(Frame Number × Page Size) + Offset` → `(0x56 × 4096) + 0x345`.

3. Handling Page Faults:
   - If a process accesses a page not in physical memory (invalid bit set):
     - Trap to OS: The CPU triggers a page fault interrupt.
     - OS Actions:
       1. Check if the access is valid (e.g., no permission violation).
       2. Find a free frame (or evict a page via algorithms like LRU).
       3. Load the required page from disk into the free frame.
       4. Update the page table with the new mapping.
       5. Resume the interrupted instruction.

4. Memory Protection:
   - Page table entries include read/write/execute permissions.
   - Attempts to violate these trigger protection faults.

---

### Advantages of Paging
1. Eliminates External Fragmentation:
   - Processes can occupy non-contiguous frames, avoiding wasted gaps between allocations.

2. Simplifies Allocation:
   - Any free frame can be assigned to a process, reducing allocation complexity.

3. Enables Virtual Memory:
   - Pages can reside on disk (swap space) when not actively used, allowing processes to exceed physical RAM limits.

4. Isolation and Security:
   - Page tables enforce memory isolation between processes; one process cannot access another’s pages.

---

### Challenges & Solutions
1. Internal Fragmentation:
   - Wasted space within the last page of a process (fixed page size).
   - *Mitigation*: Use smaller page sizes (trade-off with increased page table size).

2. Page Table Overhead:
   - Large page tables consume significant memory.
   - *Solutions*:
     - Multi-Level Paging: Hierarchical page tables (e.g., 2-level for 32-bit systems).
     - Inverted Page Tables: Single table shared across processes (used in 64-bit systems).
     - Translation Lookaside Buffer (TLB): Hardware cache storing recent translations to reduce page table lookups.

3. Page Replacement Algorithms:
   - Deciding which page to evict during a page fault (e.g., FIFO, LRU, Clock Algorithm).



-----------------  What is Deadlock in OS?  -----------------

Deadlock in operating systems is a situation where a set of processes are blocked because each process is holding a resource and waiting for another resource held by another process. In other words, a deadlock occurs when two or more processes are unable to proceed because each is waiting for the other to release a resource.

Conditions for Deadlock

For a deadlock to occur, the following four conditions must hold simultaneously:
1. **Mutual Exclusion**: At least one resource must be held in a non-shareable mode.
2. **Hold and Wait**: A process holding at least one resource is waiting to acquire additional resources.
3. **No Preemption**: Resources cannot be forcibly taken from a process holding them.
4. **Circular Wait**: There must be a circular chain of processes, each waiting for a resource held by the next process in the chain.

Deadlock Prevention Strategies

1. Resource Allocation Graph : Use a graph to represent resource allocation and requests. If a request would create a cycle, it is denied.
2. Banker's Algorithm : A dynamic approach that checks resource availability before allocation, ensuring the system remains in a safe state.
3. Avoidance of Hold and Wait : Require processes to request all resources at once, preventing hold and wait conditions.

Deadlock Prevention Techniques

1. Attacking Mutual Exclusion
This is often not possible. Some resources, like printers or files being written to, are inherently non-sharable. Forcing them to be sharable could lead to data corruption. However, for resources that can be managed (e.g., read-only files), sharing can be allowed.

2. Attacking Hold and Wait
To prevent this condition, you can enforce a rule that a process must either request all its required resources at once or release all its currently held resources before requesting new ones.

Method 1: Request all resources initially. A process must acquire all the resources it will ever need before it begins execution. This can lead to low resource utilization.

Method 2: Release resources before new requests. A process must release any resources it's holding before it can request any new ones.

3. Attacking No Preemption
If a process holding some resources requests another resource that cannot be immediately allocated to it, the OS could preempt (take away) all resources currently held by this process. These preempted resources are added to the list of resources for which the process is waiting. The process will be restarted only when it can regain its old resources, as well as the new ones it is requesting. This is often difficult to implement and may not be suitable for all resource types.

4. Attacking Circular Wait 
This is the most practical and commonly used deadlock prevention technique. The strategy is to impose a total ordering of all resource types and require that each process requests resources in an increasing order of enumeration.

For example, if the resource order is R_1,R_2,R_3, a process can request R_1 and then R_2, but it cannot request R_2 and then R_1. This ensures that a circular dependency can never form.
 