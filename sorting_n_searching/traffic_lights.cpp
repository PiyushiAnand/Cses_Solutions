#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<climits>
#include<set>
#include<map>
using namespace std;
int main(){
    long long x;
    int n;
    cin>>x>>n;
    set<long long>pos;
    pos.insert(0);
    pos.insert(x);
    map<long long,long long>longest; //pair of length and thier count;
    longest[x]=1;
    for(int i=0;i<n;i++){
        long long r ;
        cin>>r;
        pos.insert(r);
        auto it = pos.find(r);
        auto prev = it;
        prev--;
        auto next = it;
        next++;
        long long prev_len = *next - *prev;
        longest[prev_len]--;
        if(longest[prev_len]==0)longest.erase(prev_len);
        longest[*next - *it]++;
        longest[*it-*prev]++;
        // for(auto k:longest){
        //     cout<<k.first<<",";
        // }
        auto ans = longest.end();
        ans --;
        cout<<ans->first<<endl;

    }
}