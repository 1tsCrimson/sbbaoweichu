​int maxdepth(btn* root){
    if(root==nullptr){
        return 0;
    }
    int l=maxdepth(root->lchild);
    int r=maxdepth(root->rchild);
    return r>l?r:l;
}
