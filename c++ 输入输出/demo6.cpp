#include<iostream>
using namespace std;
int arr[100][5];
int func(int b,int n)
{
	int ans=0;
	int a[n][5];
	for(int i=0;i<n;i++) 
	{
		if(i>=b && i<b+5)
		{
			for(int j=0;j<5; j++) 
			{
				if(arr[i][j]==2) 
                    a[i][j]=0;
				else
                    a[i][j]=arr[i][j];
			}
		}
		else 
            for(int j=0;j<5;j++)
                a[i][j]=arr[i][j];
	}
	//for(int i=0;i<n;i++) {{for(int j=0;j<5;j++) cout<<a[i][j]<<" ";}cout<<endl;}
	int p[5]={-1,-1,0,-1,-1};
	int c[5]={-1,-1,-1,-1,-1};
	for(int i=n-1;i>=0;i--)
	{	
		//cout<<"level "<<i+1<<" :";
		for (int j=0;j<5;j++)
		{
			if(a[i][j]==2)
            {
                 c[j]=-1;
                 continue;
            }
			for(int k=max(j-1,0);k<=min(j+1,4);k++)
			{
				if(p[k]!=-1) 
                    c[j]=max(c[j],(p[k]+a[i][j]));
			}
			ans=max(ans,c[j]);
		}
		for(int l=0;l<5;l++)
            p[l]=c[l];
	}
	return ans;
}
int main()
{
	int n,m=5;

	int ans=0;
    int arr[6][5] = 
    {
        {0,1,0,2,0},
        {0,2,2,2,1},
        {0,2,1,1,1},
        {1,0,1,0,0},
        {0,0,1,2,1},
        {1,1,0,0,1},
    };

	for(int i=0;i<n-4;i++)
    {
        ans=max(ans,func(i,n));
    }
	cout<<ans<<endl;
	return 0;
}