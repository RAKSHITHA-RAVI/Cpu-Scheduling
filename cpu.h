#include <vector>
using namespace std;

#define MAX 10

class cpuschedule{
    protected:
    vector<int>pid,
    arrival_time,
    burst_time,
    start_time,
    completion_time,
    turnaround_time,
    waiting_time;
	float avg_turnaround_time,avg_waiting_time;
    int total_turnaround_time;
    int total_waiting_time;
    int is_completed[MAX];
    public:
 
        cpuschedule(): pid(MAX),arrival_time(MAX),burst_time(MAX),completion_time(MAX) ,start_time(MAX),turnaround_time(MAX),waiting_time(MAX)
         {
        total_turnaround_time=0; 
        total_waiting_time=0;
    }
     virtual void input(int n);
    void output(int n);    //result (awt and atat)
    virtual void compute(int n )=0; //pure virtual 
    void output_table(int n); //table table
};