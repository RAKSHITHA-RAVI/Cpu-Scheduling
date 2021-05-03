#include "algorithm.h"
#include <queue>
void fcfs:: compute(int n)
{
    sort(arrival_time.begin(),arrival_time.begin()+n);
    for(int i = 0; i < n; i++) 
    {
        start_time[i] = (i == 0)?arrival_time[i]: max(completion_time[i-1],arrival_time[i]);
        completion_time[i] = start_time[i] + burst_time[i];
        turnaround_time[i] = completion_time[i] -arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
      
        total_turnaround_time += turnaround_time[i];
        total_waiting_time += waiting_time[i];
    }
    avg_turnaround_time = (float) total_turnaround_time / n;
    avg_waiting_time = (float) total_waiting_time / n; 
     sort(pid.begin(),pid.begin()+n);
}


void sjf:: compute(int n)
{
    int current_time = 0;
    int completed = 0;
    int prev = 0;
    while(completed != n) {
        int idx = -1;
        int mn = 10000000;
        for(int i = 0; i < n; i++) {
            if(arrival_time[i]<= current_time && is_completed[i] == 0) {
                if(burst_time[i]< mn) {
                    mn = burst_time[i];
                    idx = i;
                }
                if(burst_time[i] == mn) {
                    if(arrival_time[i] < arrival_time[idx]) {
                        mn = burst_time[i];
                        idx = i;
                    }
                }
            }
        }
        if(idx != -1) {
           start_time [idx]=current_time;
            completion_time [idx] = start_time[idx]+ burst_time[idx];
           turnaround_time[idx] = completion_time[idx] - arrival_time[idx];
            waiting_time[idx] = turnaround_time[idx] - burst_time[idx];
            
            
            total_turnaround_time +=turnaround_time[idx];
            total_waiting_time += waiting_time[idx];
           

            is_completed[idx] = 1;
            completed++;
            current_time = completion_time[idx];
            prev = current_time;
        }
        else {
            current_time++;
        }
        
    }

    int min_arrival_time = 10000000;
    int max_completion_time = -1;
    for(int i = 0; i < n; i++) {
        min_arrival_time = min(min_arrival_time,arrival_time[i]);
        max_completion_time = max(max_completion_time,completion_time[i]);
    }

   avg_turnaround_time = (float) total_turnaround_time / n;
   avg_waiting_time = (float) total_waiting_time / n;
}
bool compare_arrival(int p1, int p2) 
{ 
    return p1 < p2;
}

bool compare_ID(int p1, int p2) 
{  
    return p1< p2;
}
void round_robin::input(int n){
        
        int i;
         cout<<"Enter time quantum: ";
        cin>>tq;
   for(i=0;i<n;i++)
	{
		cout<<"Enter The BurstTime for Process p["<<i<<"]: ";
		cin>>burst_time[i];  
         burst_remaining[i] = burst_time[i];
        cout<<"Enter The ArivalTime for Process p["<<i<<"]:	";
		cin>>arrival_time[i];
        pid[i]=i;
        cout<<endl;
	}
}
void round_robin:: compute(int n){

    sort(arrival_time.begin(),arrival_time.begin()+n);
    queue<int> q;
    int current_time = 0;
    q.push(0);
    int completed = 0;
    is_completed[0] = 1;

    while(completed != n) {
        int idx = q.front();
        q.pop();

        if(burst_remaining[idx] == burst_time[idx]) {
            start_time[idx] = max(current_time,arrival_time[idx]);
            current_time = start_time[idx];
        }

        if(burst_remaining[idx]-tq > 0) {
            burst_remaining[idx] -= tq;
            current_time += tq;
        }
        else {
            current_time += burst_remaining[idx];
            burst_remaining[idx] = 0;
            completed++;

           completion_time[idx] = current_time;
            turnaround_time[idx] = completion_time[idx] - arrival_time[idx];
            waiting_time[idx] = turnaround_time[idx]-burst_time[idx];
            
            total_turnaround_time += turnaround_time[idx];
            total_waiting_time += waiting_time[idx];
        }

        for(int i = 1; i < n; i++) {
            if(burst_remaining[i] > 0 && arrival_time[idx] <= current_time && is_completed[i] == 0) {
                q.push(i);
                is_completed[i] = 1;
            }
        }
        
        if(burst_remaining[idx] > 0) {
            q.push(idx);
        }

        if(q.empty()) {
            for(int i = 1; i < n; i++) {
                if(burst_remaining[i] > 0) {
                    q.push(i);
                    is_completed[i] = 1;
                    break;
                }
            }
        }


    }

    avg_turnaround_time = (float) total_turnaround_time / n;
    avg_waiting_time = (float) total_waiting_time / n;
    sort(pid.begin(),pid.begin()+n);

}