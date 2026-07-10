#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<climits>
#include<map>
using namespace std;
bool custom_c(vector<long long>a,vector<long long>b){
    if(a[0]==b[0]){
        return a[1]>b[1];
    }
    return a[0]<b[0];
}
int main(){
    int n;
    cin>>n;
    vector<vector<long long> >ranges(n,vector<long long>(3));
    for(int i=0;i<n;i++){
        cin>>ranges[i][0]>>ranges[i][1];
        ranges[i][2]=i;
    }
    sort(ranges.begin(),ranges.end(),custom_c);
    long long minend = ranges.back()[1];
    long long maxend = ranges[0][1];
    vector<int>ans1(n);
    vector<int>ans2(n);
    for(int i=n-2;i>=0;i--){
        if(ranges[i][1]>=minend){
            ans1[ranges[i][2]]=1;
        }
        else{
            minend = ranges[i][1];
        }
        
    }

    for(int i=1;i<n;i++){
         if(ranges[i][1]<=maxend){
            ans2[ranges[i][2]]=1;
        }
        else{
            maxend = ranges[i][1];
        }
    }
    for(int i=0;i<ans1.size();i++){
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<ans1.size();i++){
        cout<<ans2[i]<<" ";
    }
}