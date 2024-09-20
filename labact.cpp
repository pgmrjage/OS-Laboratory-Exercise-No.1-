#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;


int main()
{
    int processes;
    cout << "Input how many processes: "; cin >> processes;

    int at[processes], bt[processes], wt[processes];
    string processName[processes];
    cout << "Input ARRIVAL TIME & BURST TIME in each processes: "; 
    cout << "\n==================================="<<endl;
    for (int i=0; i<processes; i++)
    {
        processName[i] = "P" + to_string(i);
        cout << "Process" << "[" << i << "]" ; //process header
        cout << "\nArrival Time" << "[" << i + 1 << "]" << ": "; cin >> at[i]; // Arrival Time
        cout << "Burst Time" << "[" << i + 1<< "]" << ": "; cin >> bt[i]; // Burst Time
        cout << "\n==================================="<<endl;
    }

    // Initialize storage for sorted processes
    vector<tuple<int, int, string>> sortedATBT;
    for (int i = 0; i < processes; i++){
        sortedATBT.push_back(make_tuple(at[i], bt[i], processName[i]));
    }

    // Sort Processes by Arrival Time
    sort(sortedATBT.begin(), sortedATBT.end());

    // Update AT[] and BT[] with sorted values
    for (int i = 0; i < processes; i++){
        at[i] = get<0>(sortedATBT[i]);
        bt[i] = get<1>(sortedATBT[i]);
        processName[i] = get<2>(sortedATBT[i]);
    }

    // Computing for Waiting Time
    float wtTotal = 0;
    wt[0] = 0;
    for (int i=1; i<processes; i++){
        wt[i] = wt[i - 1] + bt[i - 1];  //Waiting Time = Constant Zero (0) + Burst Time
        wtTotal += wt[i];
    }

    // Output Section
    cout << "Process\tArrival Time\tBurst Time\tWaiting Time";
    for (int i=0; i<processes; i++){
        cout << "\n" << processName[i] << "\t" << at[i] << "\t\t" << bt[i] << "\t\t" << wt[i];
    }

    // Display Average Waiting Time
    cout << "\n\nAverage Waiting Time: (";
    for (int i = 0; i < processes - 1; i++){
        cout << wt[i] << " + ";
    }
    cout << wt[processes - 1] << ") / "<< processes <<" = " << wtTotal / processes;

    // Gantt Chart
    // cout << "\nGantt Chart for Schedule: "<< endl;
    // for (int i = 0; i < processes; i++){
    //     cout << " | " << processName[i] << "\t";
    // }
    // cout << "|\n ";
    // for (int i = 0; i < processes; i++){
    //     cout << wt[i] << "\t";
    // }
    
    cout << "\nGantt Chart for Schedule: " << endl;
    
    // Print top border
    for (int i = 0; i < processes; i++) {
        cout << "--------";
    }
    cout << "-" << endl;

    // Print process names
    cout << "|";
    for (int i = 0; i < processes; i++) {
        cout << " " << processName[i] << "\t|";
    }
    cout << endl;

    // Print bottom border
    for (int i = 0; i < processes; i++) {
        cout << "|-------";
    }
    cout << "|" << endl;

    // Print start times
    for (int i = 0; i < processes; i++) {
        cout << wt[i] << "\t";
    }
    cout << bt[processes - 1] + wt[processes - 1] << endl; // Print the last completion time


}