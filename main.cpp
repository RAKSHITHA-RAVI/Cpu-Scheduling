#include "algorithm.cpp"
#include<iostream>
#include<fstream>
#include<cctype>
#include <algorithm> 
#include<iomanip> 
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    int ch,n;
    char opt; 
    fstream fcfs_file; 
    fstream sjf_file;
    fstream rr_file;
    cpuschedule *cpu;

    cout << setprecision(4) << fixed; 
    cout<<"---CPU SCHEDULING---"<<endl;
    do{
        cout<<"1.FCFS\n2.SJF\n3.Round Robin\n4.Exit\nEnter Your Choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1: { 
                cpu= new fcfs(); 
                cout<<"Enter the number of processes: ";
                cin>>n;
                cpu->input(n);
                cpu->compute(n);
                fcfs_file.open("fcfs.txt",ios::in | ios::out);
                fcfs_file.write((char*)cpu,sizeof(fcfs));
                fcfs_file.close();
                cpu->output(n);
                cout<<"Do you want to see the table ?";
                cin>>opt;
                if(toupper(opt)=='Y'){
                    fcfs temp;
                    fcfs_file.open("fcfs.txt",ios::in | ios::out);
                    fcfs_file.read((char*)&temp,sizeof(fcfs));
                    temp.output_table(n);
                    fcfs_file.close(); 
                }
                
                
        break;            
        }
        case 2: {
            cpu= new sjf();
            cout<<"Enter the number of processes: ";
                cin>>n;
                cpu->input(n);
                cpu->compute(n);
                sjf_file.open("sjf.txt" );
                sjf_file.write((char*)cpu,sizeof(sjf));
                sjf_file.close();
                cpu->output(n);
                cout<<"Do you want to see the table ?";
                cin>>opt;
                if(opt=='Y' || opt=='y'){
                    sjf temp2;
                    sjf_file.open("sjf.txt");
                    sjf_file.read((char*)&temp2,sizeof(sjf));
                    temp2.output_table(n);
                    sjf_file.close();
                
                }
                 break;
        }
        case 3:{
            cpu= new round_robin();
            cout<<"Enter the number of processes: ";
                cin>>n;
                cpu->input(n);
                cpu->compute(n);
                rr_file.open("round.txt" );
                rr_file.write((char*)cpu,sizeof(round_robin));
                rr_file.close();
                cpu->output(n);
                cout<<"Do you want to see the table ?";
                cin>>opt;
                if(opt=='Y' || opt=='y'){
                    round_robin temp3;
                    rr_file.open("round_robin.txt");
                    rr_file.read((char*)&temp3,sizeof(round_robin));
                    temp3.output_table(n);
                    rr_file.close();
                }
                 break;
        }
        case 4: cout<<"Thank You"<<endl;break;
        default: cout<<"Wrong choice..Try again";
            break;
        }
    }while (ch!=4);
return 0;
}
