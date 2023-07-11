#include<iostream>
using namespace std;
void selectionSort(int *arr, int n)
{
	int min,temp;
	for (int i = 0; i < n - 2; i++)
	{
		min = arr[i];
		cout << endl;
		for (int j = i + 1; j < n - 1; j++)
		{
			if (arr[j] < min)
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << "|";
		}
		cout << endl;
	}
}
int bubbleSort(int *arr, int n)
{
	return 0;
}
void display(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "|";
	}
}
int main()
{
	int *arr;
	int n, ch, res;
	cout << "\nEnter the size of the array:";
	cin >> n;
	arr = new int[n];
	cout << "\nEnter the Elements in the Array";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	while (1)
	{
		cout << "\n***MENU***";
		cout << "\n1.Selection Sort";
		cout << "\n2.Bubble Sort";
		cout << "\n3.Display";
		cout << "\n4.Exit";
		cout << "\nEnter your choice";
		cin >> ch;
		switch (ch)
		{
			case 1:
			{
				selectionSort(arr, n);
				break;
			}
			case 2:
			{
				res = bubbleSort(arr, n);
				break;
			}
			case 3:
			{
				display(arr, n);
				break;
			}
			case 4:
			{
				cout << "\nProgram ends";
				exit(0);
				break;
			}
		}
	}
	return 0;
}
