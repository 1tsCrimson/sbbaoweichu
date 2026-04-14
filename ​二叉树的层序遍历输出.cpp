​#include<bits/stdc++.h>
using namespace std;

vector<int> level(btn*root){
    vector<int>answer;
    if(root=nullptr){return answer;}
    queue<btn*> q;
    q.push(root);
    
    while(q.empty()!=true){
        btn*tmp=q.front();
        q.pop();
        answer.push_back(tmp->val);
        if(tmp->lchild!=nullptr){q.push(tmp->lchild);}
        if(tmp->rchild!=nullptr){q.push(tmp->rchild);}
    }
    
    return answer;
}
