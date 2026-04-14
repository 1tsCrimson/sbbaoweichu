#include<bits/stdc++.h>
using namespace std;

struct btn{
    int val;
    btn*lchild=nullptr;
    btn*rchild=nullptr;
    btn(int n){
    val=n;
    }
};

int rtIndex(vector<int> io,int tag){
    for(int i=0;i<io.size();i++){
        if(io[i]==tag){
            return i;
        }
    }
    return -1;
}

int poindex=0;

btn*build(vector<int> po,vector<int> io,int lindex,int rindex){
    if(lindex>rindex){return nullptr;}
    
    btn*root=new btn(po.at(poindex));
    poindex++;
    
    int i=rtIndex(io,root->val);
    root->lchild=build(po,io,lindex,i-1);
    root->rchild=build(po,io,i+1,rindex);
    
    return root;
}

btn*slt(vector<int> po,vector<int> io){
    poindex=0;
    btn*root=build(po,io,0,po.size()-1);
    return root;
}
