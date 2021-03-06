# FIBONACCI

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  int a=0, b=1, n, i, user_input;
  pid_t pid;

  printf("Enter the number of a Fibonacci Sequence:\n");
  scanf("%d", &user_input);

  if (user_input < 0)
     printf("Please enter a non-negative integer!\n");
  else
  {
     pid = fork();
     
     if(pid < 0){
        printf("fork failed");
     }
     else if (pid == 0)
     {
        printf("Child is producing the Fibonacci Sequence...\n");
        printf("%d %d ",a,b);
        for (i=0;i<user_input;i++)
        {
           n=a+b;
           printf("%d ", n);
           a=b;
           b=n;
        }
        printf("Child complete\n"); 
     }
     else 
     {
        printf("Parent is waiting for child to complete...\n");
        wait(NULL);
        printf("Parent ends\n");
     }
  }
  return 0;
}
//
////
//////
/////////
/////////////
