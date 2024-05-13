
#include<stdio.h>

int sum, tar;
//understand this comb thing!!!!
void printCombination(int arr[], int data[], int start, int end, int index, int r) {
    // Current combination is ready to be printed, print it
    if (index == r) {
    	sum = 0;
        for (int i = 0; i < r; ++i)
        {
        	sum = sum + arr[data[i]];
            //printf("arr[%d] = %d ", data[i],arr[data[i]]);
        }
        if(sum == tar)
        {
        	printf("INDEX = ");
			for(int j = 0; j < r; j++)
			{
				printf("%d ", data[j]);
			}
			printf("\n");
        }
        return;
    }

    // Replace index with all possible elements. The condition end-i+1 >= r-index
    // makes sure that including one element at index will make a combination with
    // remaining elements at remaining positions
    for (int i = start; i <= end && end - i + 1 >= r - index; ++i) {
        data[index] = i;
        printCombination(arr, data, i+1, end, index+1, r);
    }
}

void generateCombinations(int arr[], int n, int r) {
    int data[r]; // Temporary array to store the combination
    printCombination(arr, data, 0, n-1, 0, r);
}



int main()
{
	//printf("Entering main function\n");
    //declaring variables
    int n;
    int target;
    
	//prompt
	int status2;
	//printf("1. Right now status 2 = %d\n", status2);
	printf("Enter the number of elements that you would like to enter: ");
    scanf("%d", &n);
    //printf("2. n = %d\n", n);
    int array[n];
    printf("Enter your %d numbers: ", n);
    do 
    {
    	status2 = 1;
    	for (int i = 0; i < n; i++)
    	{
    	   scanf("%d", &array[i]);
    	   //printf("3. array[%d] = %d\n", i, array[i]);
    	}    	
    	//if any element = 0, status2 = 0
    	for (int i = 0; i < n; i++)
    	{
    		if(array[i] <= 0) 
    		{
    			//printf("4. array[%d] = %d\n", i, array[i]);
    			printf("Enter another set of values, because they should be natural numbers: ");
    			status2 = 0;
    			//printf("5. status2 = %d\n", status2);
    			break;
    		}
    	}
    }
    while (!status2);
    //printf("6. status2 = %d\n", status2);
    printf("Enter your Target Number: ");
    scanf("%d",&target);
    //printf("7. target = %d\n", target);
    
    
    
    for(int i = 1; i < n; i++)
    {
    	tar = target;
    	generateCombinations(array, n, i);
    }    
    return 0;
}
