#include <iostream>
using namespace std;
int main (){

int c [100];
int z ; 
int i = 1 ;
for(i = 1;i < 100;i++){

cout<<"please ente the number"<<endl;
cin>>z;

if(z == -1){

break;
}
c[i] = z;

}
cout<<"the total number of positive integer "<<i-1;
return 0;
}