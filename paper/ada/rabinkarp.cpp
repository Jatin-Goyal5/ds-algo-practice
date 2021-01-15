#include <bits/stdc++.h>
using namespace std;
#define d 256
void search(char str1[], char str2[], int q)
{
    int M = strlen(str1);
    int N = strlen(str2);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
    for (i = 0; i < M; i++)
    {
    p = (d * p + str1[i]) % q;
    t = (d * t + str2[i]) % q;
    }
    for (i = 0; i <= N - M; i++)
    {
        if ( p == t )
        {
            for (j = 0; j < M; j++)
            {
                if (str2[i+j] != str1[j])
                break;
            }
            if (j == M)
                cout<<"Pattern found at index "<< i<<endl;
        }
        if ( i < N-M )
        {
            t = (d*(t - str2[i]*h) + str2[i+M])%q;
            if (t < 0)
                t = (t + q);
        }
    }
}
int main()
{
    char txt[] = "my name is jatin";
    char pat[] = "jatin";
    int q = 101;
    search(pat, txt, q);
    return 0;
}