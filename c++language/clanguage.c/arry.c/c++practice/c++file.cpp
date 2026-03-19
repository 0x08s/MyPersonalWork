#include<iostream>
using namespace std;
// ===========================================//

// ============ simple calculator ===========//

//============================================//

int add(int a,int b){

int sum = 0;

sum = a + b;

cout <<"print the sum "<<sum;

return a + b;

}

int sub(int a,int b){

int minu = a - b;

cout <<"print the minus"<<minu;

return a - b;    

}
int multi(int a,int b){

int multiplye = a * b;

cout<<"print the multiplye"<<multiplye ;

return a * b;

}

int divide(int a,int b){

int divid = a / b ;

cout<<"print the divide"<<divid;

return a / b;

}

int suqare(int a){

int suq =  a * a;

cout <<"print the suqare"<<suq;

return a * a;

}

int cub(int a){

int cube = a * a * a;

cout <<"print the cube"<<cube;
return a * a * a;

}

int evenodd(int a){

if (a % 2 == 0){    

cout<<"print the even";

}

else {

cout <<"print the odd number ";

}

return a%2 == 0;

}

int positivenegative(int a){

if ( a >= 0){

cout<<"print the positive";

return a >= 0;

}

else {

    cout <<"print the negative number";
}

return a >= 0;

}

int exit(){

cout<<"invalid";

return 0;

}

int main (){

char choice ;

cout <<"print the choice";

cin >>choice;

cout<<"\n";

if (choice == 'y'){

cout <<"print the calculator";

cout<<"\n";

int a;

cout<<"enter your first number";

cin>>a;

cout<<"\n";

int b;

cout<<"enter your second number";

cin>>b;

cout<<"\n";

//calling the function 

add(a,b);

cout<<"\n";

sub(a,b);

cout<<"\n";

multi(a,b);

cout<<"\n";

divide(a,b);

cout<<"\n";

suqare(a);

cout<<"\n";

cub(a);

cout<<"\n";

evenodd(a);

cout<<"\n";

positivenegative(a);

cout<<"\n";

exit();

cout<<"\n";

}

else if(choice == 'N'){

cout <<"invalud";

}

return 0;
}




