#include <iostream>
using namespace std;
int main (){

int i = 1;
int age[10];
int height[10];
int length[10];

// use the condition through the for loop ;

for(i = 1;i<10;i++){

cout<<"please enter your age student "<<i<<"=";
cin>>age[i];

}
int totalage = 0;
for(i = 1;i<10;i++){

totalage += age[i];

}
cout <<"totalage"<<"="<< totalage;
return 0;
}