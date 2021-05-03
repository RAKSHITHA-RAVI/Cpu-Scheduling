#include "cpu.h"
#include<iostream>
#include <algorithm> 
#include<iomanip> 
#include <cstring>
#include <vector>
using namespace std;


void cpuschedule :: input(int n)
{
   int i;
   for(i=0;i<n;i++)
	{
		cout<<"Enter The BurstTime for Process p["<<i<<"]: ";
		cin>>burst_time[i];
        cout<<"Enter The ArivalTime for Process p["<<i<<"]:	";
        
       try {cin>>arrival_time[i];
      
      if (arrival_time[i] < 0)
      {
         throw arrival_time[i];
         
      }
       }
     catch (int arrival_time ) 
        {
            cout << "Time cannot be negative \n";
           
        } 
        pid[i]=i;
        cout<<endl;
	}
}

void cpuschedule :: output(int n)
{
    cout<<"------Result------\n";
    cout<<"Average Turnaround Time = "<<avg_turnaround_time<<endl;
    cout<<"Average Waiting Time = "<<avg_waiting_time<<endl;
}

void cpuschedule ::output_table(int n)
{
   cout<<"#P\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"\n"<<endl;
    for(int i = 0; i < n; i++) {
        cout<<pid[i]<<"\t"<<arrival_time[i]<<"\t"<<burst_time[i]<<"\t"<<start_time[i]<<"\t"<<completion_time[i]<<"\t"<<turnaround_time[i]<<"\t"<<waiting_time[i]<<"\t"<<"\n"<<endl;
    }
}
