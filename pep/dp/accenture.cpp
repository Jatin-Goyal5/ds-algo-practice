
#include <bits/stdc++.h>
using namespace std;



void SieveOfEratosthenes(vector<bool> &prime,int n)
{
	for (int p = 2; p * p <= n; p++)
	{
		if (prime[p] == true)
		{
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
}

// Driver Code
int main()
{
    int l,r;
    cin>> l>> r;

	vector<bool> prime(r+1,true);
    SieveOfEratosthenes(prime,r);

    vector<int> div(r+1);
    div[0]=0;
    div[1] = 0;

    for(int i =2 ; i < div.size() ; i++){
        if(prime[i]){
            div[i] =1;
        }else{
            if(i%2 ==0){
                div[i] = (2*div[i/2])+(i/2); 
            }else{
                div[i] = (3*div[i/3])+(i/3);
            }
        }
    }



int sum =0;
for(int i =l ; i <= r; i++){
    for( int j = 2 ; j <=i ; j++)
    {
        if(i%j == 0){
            sum += div[j];
        }
    }
}
    cout<< sum << endl;

    
	return 0;
}
