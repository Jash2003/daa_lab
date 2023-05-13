#include <iostream>
using namespace std;
int main()
{
	int n,arr[25],count[25],sorted[25];
	cout<<"Enter number of numbers : ";
	cin>>n;
	cout<<"Enter array to sort : "<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	for(int i=0;i<n;i++)
		count[i]=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]<arr[j])
				count[j]++;
			else 
				count[i]++;
		}
	}
	for(int i=0;i<n;i++)
		sorted[count[i]] = arr[i];
	
	cout<<"Sorted Array is : ";
	for(int i=0;i<n;i++)
		cout<<sorted[i]<<" ";
	return 0;
}
