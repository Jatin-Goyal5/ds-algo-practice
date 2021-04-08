#include<bits/stdc++.h>
#define f(a,b) for(int i =a ; i < b ; i++)
#define v(t) vector<t>

using namespace std;

void test(v(int) a){
    v(int) r(a.size()),l(a.size());
    stack<int> ls,rs;
    ls.push(0);
    rs.push(a.size()-1);
    l[0] =-1;
    f(1,a.size()){
        while(ls.size() >0 && a[i] <= a[ls.top()]){
            ls.pop();
        }
        if(ls.size() == 0){
            l[i] =-1;
        }else {
            l[i] = ls.top();
        }
        ls.push(i);
    }
    r[a.size()-1] = a.size();
    for(int i = a.size()-2 ; i >= 0 ; i--){
        while(rs.size() > 0 && a[i] <= a[rs.top()]){
            rs.pop();
        }

        if(rs.size() == 0){
            r[i] =a.size();
        }else{
            r[i] = rs.top();
        }
        rs.push(i);
    }
    int area = INT_MIN;

    f(0,a.size()){
        area = max(area, (r[i]-l[i] -1)*a[i]);
    }
    cout<< area;
    // f(0,a.size())
    //     cout<< r[i]<< " ";
    
}
int main()
{
    int n;
    cin>> n;
    v(int) a(n);
    f(0,n) cin>> a[i];
    test(a);
    return 0;
}