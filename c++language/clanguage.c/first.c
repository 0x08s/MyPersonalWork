#include <stdio.h>
int main(){ 
    int n;

    for(int i = 1; i <= 20; i++) {
        printf("Enter your number: ");
        scanf("%d", &n);

        if(n % 2 != 0) {  // Agar number odd hai
            printf("Odd number mila, loop stop!\n");
            break;  // Loop yahan stop ho jayega
        }

        printf("Even number, loop continue...\n");
    }

    printf("End\n");

return 0;
}
