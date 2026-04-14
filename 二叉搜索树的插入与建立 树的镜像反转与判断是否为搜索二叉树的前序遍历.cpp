#include<bits/stdc++.h>
using namespace std;

struct btn{
    int val;
    btn *lchild=nullptr,*rchild=nullptr;
    btn(int n):val(n){}
};

btn* ninsert(btn* root, int n){
    if(root==nullptr) return new btn(n);
    if(n<root->val) root->lchild=ninsert(root->lchild,n);
    else root->rchild=ninsert(root->rchild,n);
    return root;
}

btn* build(vector<int> a){
    btn* root=new btn(a[0]);
    for(int i=1;i<a.size();i++) root=ninsert(root,a[i]);
    return root;
}

void prt(btn* root, vector<int>& t){
    if(!root) return;
    t.push_back(root->val);
    prt(root->lchild,t);
    prt(root->rchild,t);
}

void pot(btn* root, vector<int>& t){
    if(!root) return;
    pot(root->lchild,t);
    pot(root->rchild,t);
    t.push_back(root->val);
}

btn* rev(btn* root){
    if(!root) return nullptr;
    swap(root->lchild,root->rchild);
    rev(root->lchild);
    rev(root->rchild);
    return root;
}

int main(){
    int n; cin>>n;
    vector<int> given(n);
    for(int i=0;i<n;i++) cin>>given[i];
    
    btn* root=build(given);
    vector<int> gprt,rprt,gpot;
    
    prt(root,gprt);
    pot(root,gpot);
    prt(rev(root),rprt);
    
    if(given==gprt || given==rprt){
        cout<<"YES\n";
        for(int i=0;i<gpot.size();i++){
            if(i) cout<<" ";
            cout<<gpot[i];
        }
    }else{
        cout<<"NO\n";
    }
    return 0;
}
