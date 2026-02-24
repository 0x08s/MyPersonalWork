#include<stdio.h>

// void print_table(int);
// void print_n_tables(int, int);


// int main(){
//     int a = 1;
//     int b= 20;
//     a = 2;
//     print_n_tables(a, b);

// }


// void print_table(int num){
//     for(int i = 1 ; i<=10;i++){
//         printf("%d\n",num*i);
//     }
//     printf("\n");
//     return;
// }
// void print_n_tables(int starting_num, int ending_num){
//     while(starting_num <= ending_num){
//         print_table(starting_num);
//         starting_num++;
//     }
// } 

// int add(int, int);

// int main(){
//     int sum = add(1, 2);
//     printf("%d", sum);
// }

// int add(int x, int y){
//     int sum = x + y;
//     return sum;
// }



// int find_avg(int, int, int);

// int main(){
//     find_avg(1,2,3);
//     find_avg(2,3,4);
// }



// int find_avg(int a, int b, int c){
//     int average = (a + b + c) / 3;
//     printf("%d\n", average);
// }




int is_even(int n ){
    return (n % 2 == 0);
}

int main(){
    if(is_even(10)){
        printf("yes");
    } else{
        printf("no");
    }
}
