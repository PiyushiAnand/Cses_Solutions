#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<climits>
#include<set>
#include<map>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<int>s;
    for(int i=0;i<n;i++){
        s.insert(i+1);
    }
    auto curr = s.begin();
    while(!s.empty()){
        curr++;
        if(curr==s.end()){
            curr = s.begin();
        }
        cout<<*curr<<" ";
        curr = s.erase(curr);
        if(curr==s.end()){
            curr = s.begin();
        }
    }
}