#include<stdio.h>
#include<stdbool.h>

int main()
{

   //declare variables
   int n;
   int target;
   int sum;  
   bool NA = 1; 
   int diff;
   
   //prompt
   printf("Enter the number of elements that you would like to enter: ");
   scanf("%d", &n);
   int array[n];
   printf("Enter your %d numbers: ", n);
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &array[i]);
   } 
   printf("Enter your Target Number: ");
   scanf("%d",&target);
   
   /*logic
      #1 add every two elements,using two for loops and whenever it meets goal, just return 0
      #2 use 2 for loops, 1st for subtracting 1 element from target and 2nd to check if any element is equal to the difference.      
   */
   
   //method1
   printf("Methid 1\n");
   for (int i = 0; i < (n - 1); i++)
   {
      for (int j = i + 1; j < n; j++)
      {
           sum = array[i] + array[j];
           if(sum == target)
           {
              printf("[%d, %d]\n", i, j);
              NA = 0;
           }
      } 
   }
   if (NA)
   {
      printf("No such pair exist\n");
   }
   
   //method2
   printf("Method 2\n");
   for (int i = 0; i < (n - 1); i++)
   {
      diff = target - array[i];
      for(int j = i + 1; j < n; j++)
      {
         if(array[j] == diff)
         {
            printf("[%d, %d]\n", i, j);
            NA = 0;
         }
      }
   }
   if (NA)
   {
      printf("No such pair exist\n");
   }
   
   return 0;
}
