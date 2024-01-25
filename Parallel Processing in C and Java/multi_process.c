// CPP code to create three child
// process of a parent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int *minProcess(int arr[], int size, int fdMin[])
{
	int min = arr[0];

	// Loop through the array
	for (int i = 0; i < size; i++)
	{
		// Compare elements of array with min
		if (arr[i] < min)
			min = arr[i];
	}
	write(fdMin[1], &min, sizeof(int));
	close(fdMin[1]);
	return 0;
}

int *maxProcess(int arr[], int size, int fdMax[])
{
	int max = arr[0];

	// Loop through the array
	for (int i = 0; i < size; i++)
	{
		// Compare elements of array with max
		if (arr[i] > max)
			max = arr[i];
	}
	write(fdMax[1], &max, sizeof(int));
	close(fdMax[1]);
	return 0;
}

int *avgProcess(int arr[], int size, int fdAvg[])
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	int avg = sum / size;

	write(fdAvg[1], &avg, sizeof(int));
	close(fdAvg[1]);
	return 0;
}

int *medProcess(int arr[], int size, int fdMed[])
{
	int a[size];

	// Copying all elements of one array into another
	for (int i = 0; i < size; i++)
	{
		a[i] = arr[i];
	}

	int median, t;

	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (a[i] > a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}

	/* calculation of median */
	if (size % 2 == 0)
		median = (a[size / 2] + a[size / 2 + 1]) / 2.0;
	else
		median = a[size / 2 + 1];

	write(fdMed[1], &median, sizeof(float));
	close(fdMed[1]);
	return 0;
}

// Driver code
int main()
{
	int length;
	printf("Enter the total numbers of input values:\n");
	scanf("%d", &length);

	int arr[length];
	printf("Start entering your input numbers:\n");
	for (int i = 0; i < length; i++)
	{
		scanf("%d", &arr[i]);
	}

	// Creating pipe to communicat between each process
	int fdMin[2], fdMax[2], fdAvg[2], fdMed[2];
	pipe(fdMin);
	pipe(fdMax);
	pipe(fdAvg);
	pipe(fdMed);

	int pid, pid1, pid2, pid3;
	pid = fork();

	if (pid == 0)
	{
		// First Child process to find min value
		minProcess(arr, length, fdMin);
	}
	else
	{
		pid1 = fork();
		if (pid1 == 0)
		{
			// Second Child process to find max value
			maxProcess(arr, length, fdMax);
		}
		else
		{
			pid2 = fork();
			if (pid2 == 0)
			{
				// Third child process to find avg value
				avgProcess(arr, length, fdAvg);
			}
			else
			{
				pid3 = fork();
				if (pid3 == 0)
				{
					// Fourth child process to find median value
					medProcess(arr, length, fdMed);
				}
				else
				{
					// Parent process to print all the returned values
					close(fdAvg[1]);
					int avgVal;
					read(fdAvg[0], &avgVal, sizeof(int));
					close(fdAvg[0]);
					printf("The average value is %d\n", avgVal);

					close(fdMin[1]);
					int minVal;
					read(fdMin[0], &minVal, sizeof(int));
					close(fdMin[0]);
					printf("The minimum value is %d\n", minVal);

					close(fdMax[1]);
					int maxVal;
					read(fdMax[0], &maxVal, sizeof(int));
					close(fdMax[0]);
					printf("The maximum value is %d\n", maxVal);

					close(fdMed[1]);
					int medVal;
					read(fdMed[0], &medVal, sizeof(float));
					close(fdMed[0]);
					printf("The medium value is %d\n", medVal);
				}
			}
		}
	}
	return 0;
}
