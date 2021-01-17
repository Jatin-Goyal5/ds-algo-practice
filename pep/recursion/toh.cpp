#include<iostream>
 #include<vector>
 using namespace std;
 void toh(string src, string aux, string des, int n) {
     if(n == 0){
         return;
     }
     toh(src,des,aux,n-1);
     cout<<"Move disk "<<n<<" from rod "<<src<<" to rod "<<des<< endl;
     toh(aux,src,des,n-1);
 
 
     //Write your code here.
 
 
 
 }
 
 
 
 int main(int argc,char** argv){
     int n;
     cin>>n;
     toh("1","2","3",n);
  
 }