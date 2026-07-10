#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    sort(vec.begin(),vec.end());
    long long x = 0;
    for(long long c:vec){
        if(c <= x+1){
            x += c;
        }
        else break;
    }
    cout<<x+1<<endl;
    

}