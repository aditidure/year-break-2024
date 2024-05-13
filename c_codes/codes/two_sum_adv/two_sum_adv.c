#include<stdio.h>
void printCombination(int arr[], int data[], int start, int end, int index, int r, int tar) 
{
    if (index == r) 
    {
    	int sum = 0;
        for (int i = 0; i < r; ++i)
        	sum = sum + arr[data[i]];
        if(sum == tar)
        {
        	printf("INDEX = ");
			for(int j = 0; j < r; j++)
				printf("%d ", data[j]);
			printf("\n");
        }
        return;
    }
    for (int i = start; i < end && end - i >= r - index; ++i) 
    {
        data[index] = i;
        printCombination(arr, data, i+1, end, index+1, r, tar);
    }
}

void generateCombinations(int arr[], int n, int r, int tar) 
{
    int data[r]; 
    printCombination(arr, data, 0, n, 0, r, tar);
}



int main()
{
    int n, target, status;
	printf("Enter the number of elements that you would like to enter: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter your %d numbers: ", n);
    do 
    {
    	status = 1;
    	for (int i = 0; i < n; i++)
    	scanf("%d", &array[i]);  	
    	for (int i = 0; i < n; i++)
    	{
    		if(array[i] <= 0) 
    		{
    			printf("Enter another set of values, because they should be natural numbers: ");
    			status = 0;
    			break;
    		}
    	}
    }
    while (!status);
    printf("Enter your Target Number: ");
    scanf("%d",&target);    
    for(int i = 1; i < n; i++)
    generateCombinations(array, n, i, target); 
    return 0;
}
