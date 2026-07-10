#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long max_sum  = -1*1e15;
    long long sum=0;
    vector<long long>v(n);
    vector<long long>psum(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sum = v[0];

    for(int i=1;i<n;i++){
        if(sum+v[i]>v[i]){
            sum +=v[i];
        }
        else {
            sum = v[i];
        }
        if(sum>max_sum){
            max_sum = sum;
        }
        // cout<<sum<<endl;
    }
    if(sum>max_sum){
            max_sum = sum;
        }
    cout<<max_sum<<endl;
}