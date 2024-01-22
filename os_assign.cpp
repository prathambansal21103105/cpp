#include <algorithm> 
#include <iostream> 
#include <vector> 
using namespace std;

struct Process { 
    int pid;
    int arrival_time; 
    int burst_time;
    int priority;
    int completion_time; 
    int waiting_time; 
    int turnaround_time; 
    int remaining_time;
};

void fcfs(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), [](const Process& p1, const Process& p2) {
        return p1.arrival_time < p2.arrival_time; 
    });
    
    int current_time = 0;
    for (auto& p : processes) {
        if(current_time < p.arrival_time) { 
            current_time = p.arrival_time;
        }
        p.completion_time = current_time + p.burst_time;
        p.turnaround_time = p.completion_time - p.arrival_time;
        p.waiting_time = p.turnaround_time - p.burst_time;
        current_time = p.completion_time;
    } 
}

void sjf(vector<Process>& processes) {
    
    sort(processes.begin(), processes.end(), [](const Process& p1, const Process& p2) {
        return p1.burst_time < p2.burst_time;
    });

    fcfs(processes); 
}

void non_preemptive_priority(vector<Process>& processes) { 
    sort(processes.begin(), processes.end(), [](const Process& p1, const Process& p2) {
        return p1.priority > p2.priority;
    });
    
    fcfs(processes); 
}

void round_robin(vector<Process>& processes, int quantum){ 
    vector<int> remaining_times(processes.size());
    for (int i = 0; i < processes.size(); i++) {
        remaining_times[i] = processes[i].burst_time; 
    }
    int current_time = 0;
    int completed = 0;
    while (completed < processes.size()){
        bool flag = false;
            for (int i = 0; i < processes.size(); i++){
                if (remaining_times[i] > 0){ 
                    flag = true;
                    if (remaining_times[i] > quantum){ 
                        current_time += quantum; 
                        remaining_times[i] -= quantum;
                    } 
                    else{
                        current_time += remaining_times[i]; 
                        processes[i].completion_time = current_time; 
                        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time; 
                        remaining_times[i] = 0;
                        completed++; 
                    }
                } 
            }
        if(!flag){
            break;
        } 
    }
}

void print_results(const vector<Process>& processes) { double avg_waiting_time = 0;
    double avg_turnaround_time = 0;
    for (const auto& p : processes) {
        avg_waiting_time += p.waiting_time;
        avg_turnaround_time += p.turnaround_time;
        cout << "Process " << p.pid << ":\n";
        cout << "Arrival time: " << p.arrival_time << "\n";
        cout << "Burst time: " << p.burst_time << "\n";
        cout << "Priority: " << p.priority << "\n";
        cout << "Completion time: " << p.completion_time << "\n"; cout << "Waiting time: " << p.waiting_time << "\n";
        cout << "Turnaround time: " << p.turnaround_time << "\n\n";
    }
    int n = processes.size(); 
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    cout << "Average waiting time: " << avg_waiting_time << "\n";
    cout << "Average turnaround time: " << avg_turnaround_time << "\n"; 
}

int main() {
    int n, quantum;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter time quantum for round robin scheduling: ";
    cin >> quantum;
    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time, burst time, and priority for process " << i + 1 << ": ";
        cin >> processes[i].arrival_time >> processes[i].burst_time >> processes[i].priority;
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time; 
    }
    vector<Process> processes_copy(processes); 
    fcfs(processes);
    cout << "\nFCFS scheduling:\n"; 
    print_results(processes);
    processes = processes_copy;
    sjf(processes);
    cout << "\nSJF scheduling:\n"; 
    print_results(processes);
    processes = processes_copy; 
    non_preemptive_priority(processes);
    cout << "\nNon-preemptive priority scheduling:\n"; 
    print_results(processes);
    processes = processes_copy;
    round_robin(processes, quantum);
    cout << "\nRound robin scheduling:\n"; 
    print_results(processes);
    return 0;
}