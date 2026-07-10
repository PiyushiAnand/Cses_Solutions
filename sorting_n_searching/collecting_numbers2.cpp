#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<climits>
#include<set>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>pos(n,-1);
    vector<int>vec(n,-1);
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        pos[num-1]=i;
        vec[i] = num-1;
    }

    int round =1;
    for(int i=0;i<n-1;i++){
        if(pos[i]>pos[i+1])round++;
    }

    for(int i=0;i<m;i++){
        set<pair<int,int> >s;
        int a,b;
        cin>>a>>b;
        int pos_a,pos_b;
        int num_a,num_b;
        num_a = vec[a-1];
        num_b = vec[b-1];
        pos_a = pos[num_a];
        pos_b = pos[num_b];
        if(num_a>0)s.insert(make_pair(num_a-1,num_a));
        if(num_a<n-1)s.insert(make_pair(num_a,num_a+1));
        if(num_b>0)s.insert(make_pair(num_b-1,num_b));
        if(num_b<n-1)s.insert(make_pair(num_b,num_b+1));

        for(auto &it:s){
            if(pos[it.first]>pos[it.second]){
                round--;
            }
        }
        swap(pos[num_a],pos[num_b]);
        swap(vec[a-1], vec[b-1]);
        for(auto &it:s){
            if(pos[it.first]>pos[it.second]){
                round++;
            }
        }

        cout<<round<<endl;
    }


}