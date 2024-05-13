#include<stdio.h>
#include<string.h>
int sum = 0;

int tar, num2, call = 0;
//there is a fault in this function, it just checks consecutive ascending values.
/*void possibilities (int arr1[], int num1, int arr2[], int num)
{
	call++;
	printf("f1. Function possibilities called with call = %d\n", call);
	int temp;
	printf("f0. tar = %d, num2 = %d\n", tar, num2);
	int i;
	printf("f2. num1 = %d\n", num1);
	for(int k = 0; k < num1; k++)
	{
		printf("f3. arr1[%d] = %d\n", k, arr1[k]);
	}
	for(int k = 0; k < num1; k++)
	{
		printf("f4. arr2[%d] = %d\n", k, arr2[k]);
	} 
	printf("f5. num = %d\n", num); 
	for(i = 0; i < num1; i++)
	{
		if(arr1[i] != 0)
		{
			temp = arr1[i];
			arr1[i] = 0;
			arr2[num2] = i;
			break;
		}
	}
	printf("f6. temp = %d\n", temp);
	
	tar = tar - temp;
	printf("f7. tar = %d\n", tar);
	if(tar == 0)
	{
		printf("f8. num2 = %d\n", num2);
		arr2[num2] = i;
		printf("\nOUTPUT: \nINDEX = ");
		for(int j = 0; j < num2 + 1; j++)
		{
			printf("%d ", arr2[j]);
		}
		printf("\n\n");
		return;
	}
	num2++;
	num--;
	printf("f9. num = %d\n", num);
	if(num == 0)
	return;
	possibilities(arr1, num1, arr2, num);
}*/

//we can use 2d array thing, but my concepts of dynamic memory allocation are not very clear yet...so dropping that idea.
void combinations(int n, int r, int arr[])
{
	//the number of such combinations is nCr
	//let first set of combinations mandatorily include n.
	//use a recursive function and put n = n - 1 this time coz n is already included.
	//do it till n - r.
	//so maintain 2 variables---> temp_n, temp_r.
	int temp_n, temp_r;
	temp_n = n;
	temp_r = r;
	
	arr[num2] = n;
	num2++;
	while(num2 <= temp_r)
	combination(temp_n - 1, temp_r - 1);
	
	
}


int main()
{
	printf("Entering main function\n");
    //declaring variables
    int n;
    int target;
    
	//prompt
	int status2;
	printf("1. Right now status 2 = %d\n", status2);
	printf("Enter the number of elements that you would like to enter: ");
    scanf("%d", &n);
    printf("2. n = %d\n", n);
    int array[n];
    printf("Enter your %d numbers: ", n);
    do 
    {
    	status2 = 1;
    	for (int i = 0; i < n; i++)
    	{
    	   scanf("%d", &array[i]);
    	   printf("3. array[%d] = %d\n", i, array[i]);
    	}    	
    	//if any element = 0, status2 = 0
    	for (int i = 0; i < n; i++)
    	{
    		if(array[i] <= 0) 
    		{
    			printf("4. array[%d] = %d\n", i, array[i]);
    			printf("Enter another set of values, because they should be natural numbers.\n");
    			status2 = 0;
    			printf("5. status2 = %d\n", status2);
    			break;
    		}
    	}
    }
    while (!status2);
    printf("6. status2 = %d\n", status2);
    printf("Enter your Target Number: ");
    scanf("%d",&target);
    printf("7. target = %d\n", target);
    
    
    int temp_array2[n];
    for(int i = 0; i < n; i++)
    {
    	temp_array2[i] = 0;
    }
    int j = 0;
    int status = 0;
    
    for(int i = 0; i < n; i++)
    {
    	printf("8. i = %d, status = %d, j = %d\n", i, status, j);
    	printf("9. is array[i] < target: %d\n", (array[i] < target));
    	if (array[i] < target)
    	{
    		temp_array2[j] = array[i];
    		printf("10. temp_array2[%d] = %d\n", j, temp_array2[j]);
    		j++;
    		
    	}
    	printf("11. is array[i] == target: %d\n", (array[i] == target));
    	if (array[i] == target)
    	{
    		printf("\nOUTPUT: \nINDEX = %d\n\n", i);
			status = 1;
    	}
    }
    printf("12. j = %d, status = %d\n", j, status);
    printf("13. is ((j == 0) | (j == 1)) && status == 0: %d\n", ((j == 0) | (j == 1)) && status == 0);
    if(((j == 0) | (j == 1)) && status == 0)
    {
        printf("No such indices exist\n");
        return 0;
    }
    int array2[j];
    for(int i = 0; i < j; i++)
    {
    	array2[i] = temp_array2[i];
    	printf("14. array2[%d] = %d\n", i, array[i]);
    }
    int array3[j];
    for(int i = 0; i < j; i++)
    {
    	array3[i] = array2[i];
    	printf("15. array3[%d] = %d\n", i, array3[i]);
    }
    for (int i = 2; i <= j; i++)
    {
    	printf("16. ************************i = %d*********************\n", i);
    	for(int k = 0; k < j; k++)
    	{
    		array3[k] = array2[k];
    	}
    	call = 0;
    	tar = target;
    	num2 = 0;
    	int arr2[n];
    	for(int k = 0; k < n; k++)
    	{
    		arr2[k] = -1;
    		printf("17. arr2[%d] = %d\n", k, arr2[k]);
    	}
    	//possibilities(array3, j, arr2, i);
    	//what does this function do: enlist all the combinations of n numbers taken r at a time, so we give n and r and it stores it in an array which is global.
    	num2 = 0;
    	combinations(n,r,arr2);
    }
    return 0;
}
