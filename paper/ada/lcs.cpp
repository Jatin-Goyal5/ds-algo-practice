#include<bits/stdc++.h> 
using namespace std; 

int max(int a, int b); 

int lcs(string s1 ,string s2) 
{ 
    int m = s1.length();
    int n = s2.length();
	int L[m + 1][n + 1]; 
	int i, j; 
	for (i = 0; i <= m; i++) 
	{ 
		for (j = 0; j <= n; j++) 
		{ 
		if (i == 0 || j == 0) 
			L[i][j] = 0; 
	
		else if (s1[i - 1] == s2[j - 1]) 
			L[i][j] = L[i - 1][j - 1] + 1; 
	
		else
			L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
		} 
	} 
	
	return L[m][n]; 
} 

int main() 
{ 

    string s1,s2;
    cin>> s1 ,s2;
	
	
	cout << "Length of LCS is "
		<< lcs( s1, s2 ); 
	
	return 0; 
} 
