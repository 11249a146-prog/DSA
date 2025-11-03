#include<stdio.h>
int main()
{
 int MAX_SIZE=5;
 int Stack[MAX_SIZE];
 int Push;
 int Top=-1;
 int MAX;
 int item;
 if(Top==MAX-1)
 {
    printf("stack overflow");
    return 0;
 }
 else
 {
    Top=Top+1;
    Stack[Top]=item;
    return 0;
 }
}