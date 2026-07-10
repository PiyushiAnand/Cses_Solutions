#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long>arr(n);
    vector<long long>dep(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        cin>>dep[i];
    }
 
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
 
    int i=0,j=0;
    int count = 0;
    int max_count = INT_MIN;
    while(i<n&&j<n){
        if(arr[i]<dep[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        max_count = max(count,max_count);
    }
    cout<<max_count<<endl;
}