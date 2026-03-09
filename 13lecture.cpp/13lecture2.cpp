#include<iostream>
using namespace std;

int main(){
    int salary[5];
    int empID[5];
    int minSalary;
    int unluckyEmp;
    
    // Input employee IDs and salaries
    cout<<"Enter Employee ID and Salary for 5 Employees:\n";
    for(int i=0; i<5; i++){
        cout<<"Employee "<<i+1<<" ID: ";
        cin>>empID[i];
        cout<<"Employee "<<i+1<<" Salary: ";
        cin>>salary[i];
    }
    
    // Display all employees

    cout<<"\nEmployee Record\n";
    
    cout<<"ID\tSalary\n";

    for(int i=0; i<5; i++)
        cout<<empID[i]<<"\t"<<salary[i]<<"\n";
    
    // Find minimum salary (unlucky employee)

    minSalary = salary[0];
    unluckyEmp = empID[0];
    
    for(int i=1; i<5; i++){
        if(salary[i] < minSalary){
            minSalary  = salary[i];
            unluckyEmp = empID[i];
        }
    }
    
    // Display result

    cout<<"\n Result \n";
    cout<<"Unlucky Employee ID : "<<unluckyEmp<<"\n";
    cout<<"Lowest Salary       : "<<minSalary<<"\n";
    
    return 0;
}