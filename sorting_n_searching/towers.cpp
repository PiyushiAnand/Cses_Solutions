#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<climits>
#include<set>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long top=-1;
    long long ans = 0;
    multiset<long long>towers;
    for(int i=0;i<n;i++){
        long long k;
        cin>>k;
        if(towers.empty()){
            towers.insert(k);
        }
        else {
            auto it = towers.upper_bound(k);
            if(it==towers.end()){
                towers.insert(k);
            }
            else {
                towers.erase(it);
                towers.insert(k);
            }
        }
        
    }
    cout<<towers.size()<<endl;
}