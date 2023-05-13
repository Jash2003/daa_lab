#include <iostream>
using namespace std;
int C[100][100];
int binoCoeff(int n,int r)//6,3
{

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=min(i,r);j++)
		{
			if(j==0 || j==i)
				C[i][j] = 1;
	
			else
				C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}
	return C[n][r];
}
int main()
{
	int n,r;
	cout<<"Input n and r: ";
	cin>>n>>r;
	
	int ans = binoCoeff(n,r);
	cout<<"Answer for nCr : "<<ans;
	return 0;
}

