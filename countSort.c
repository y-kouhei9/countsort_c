# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>


int findMax(int A[], int n)
{
	int max = INT32_MIN;
	int i;
	for (i = 0; i < n; i++) 
	{
		if (A[i] > max) 
		{
			max = A[i];
		}
	}
	return max;
}

void CountSort(int A[], int n)
{
	int i, j, max, *C;

	max = findMax(A, n);
	C = (int *)malloc(sizeof(int)*(max+1));

	for (i = 0; i < max+1; i++) 
	{
		C[i] = 0;
	}

	for (i = 0; i < n; i++) 
	{
		C[A[i]]++;
	}

	i = 0; j = 0;
	while (j < max+1) 
	{
		if (C[j] > 0) 
		{
			A[i++] = j;
			C[j]--;
		} 
		else 
		{
			j++;
		}
	}

}


int main(void)
{
	int A[] = {11, 14, 5, 18, 9, 35, 20, 9, 4, 52, 69, 1, 0};
	int n   = sizeof(A)/sizeof(A[0]);
	int i;

	CountSort(A, n);

	for (i = 0; i < n; i++) 
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	return 0;
}