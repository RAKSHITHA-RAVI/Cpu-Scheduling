#include "cpu.cpp"
#include<fstream>
#include <algorithm> 
#include<iomanip> 
#include <cstring>
using namespace std;
#define MAX 10

class fcfs: public cpuschedule
{
    public:
    void compute(int n);  
};

class sjf :public cpuschedule
{
    public:  
    sjf()
    {
        memset(is_completed,0,sizeof(is_completed));
    }
    void compute(int n);
};

class round_robin: public cpuschedule
{
    protected:
    int tq;
    int burst_remaining[MAX];
    public:
     round_robin()
    {
        memset(is_completed,0,sizeof(is_completed));
    }
    void compute(int n);  
    void input(int n);
};