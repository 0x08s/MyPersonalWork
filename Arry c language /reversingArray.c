#include <stdio.h>

int main() {
  char str[40] ;
  puts("enter a string :");
  scanf("%[^\n]s",str);
  int size = 0;
  int i = 0;
  while(str[i] !='\0'){

  size++;
  i++;
  
  }

int j = size - 1;

for(int i = 0; i <= j; i++ , j--){

char temp = str[i];
str[i] = str[j];
str[j] = temp;

}
puts("the out put is :");
puts(str);

    return 0;
}