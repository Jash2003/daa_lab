#include <iostream>
using namespace std;
int main()
{
	char text[100],pattern[100];
	cout<<"Text : ";//JIN SAW ME IN A BARBER SHOP
	cin.getline(text,100,'\n');
	cout<<"Pattern : ";
	cin.getline(pattern,100,'\n');//BARBER
	
	int len1=0,len2=0;
	while(text[len1]!='\0') len1++;
	
	while(pattern[len2]!='\0') len2++;
	
	int i=1,x = len2-1,flag=1;//i=1,x = 5;
	while(x<len1)//5<27,9<27,10<27,16<27
	{
		if(text[x]==' ')
		{
			x+=len2;//16
		}
		else if(text[x] == pattern[len2-i])//text[16]==pattern[5] A!=R
		{
			if(len2-i == 0) 
			{
				cout<<"Found at : "<<x;flag=0;break;
			}
			i++;//2
			x--;//17
			
		}
		else
		{
			int shift=0,found=0;
			for(int k = len2-1;k>=0;k--)//K=5
			{
				if(pattern[k]==text[x])//E==E
				{
					shift = len2-1 - k;
					found=1;//5-1=4 , 5-4 = 1,5-3=2
					break;
				}
			}
			if(found==0) shift=len2;
			i = 1;
			x += shift;// 9, 9+1=10,16+2=18
		}
		
	}
	if(flag==1) cout<<"NOT FOUND";
	
}
