#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>pos(n,-1);
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        pos[num-1]=i;
    }

    int round =1;
    for(int i=0;i<n-1;i++){
        if(pos[i]>pos[i+1])round++;
    }
    cout<<round<<endl;
}