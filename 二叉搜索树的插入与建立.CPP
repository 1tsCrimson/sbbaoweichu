#include<bits/stdc++.h>
using namespace std;

struct btn{ 
	int val;
	btn *lchild=nullptr,*rchild=nullptr;
    btn(int n){
    	val=n;
    }
};

btn*ninsert(btn* root,int n){
	if(root==nullptr){
    	btn*tmp=new btn(n);
        return tmp;
    }
	if(root->val>n){
    	root->lchild=ninsert(root->lchild,n);
    }
    else if(root->val<=n){
    	root->rchild=ninsert(root->rchild,n);
    }
    return root;
    
 }
 
 btn*build(vector<int> a){
	btn*root=new btn(a[0]);
    for(int i=1;i<a.size();i++){
        root=ninsert(root,a[i]);
    }
    return root;
}
