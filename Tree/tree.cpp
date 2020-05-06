//
// Created by myzj on 20-5-6.
//
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    char data;
    struct TreeNode * lchild;
    struct TreeNode * rchild;

}* Tree,Tnode;
//By  LinkList
Tnode* create_node(char data){
    Tree tnode=(Tree)malloc(sizeof(Tnode));
    tnode->data=data;
    tnode->lchild=NULL;
    tnode->rchild=NULL;
    return tnode;
}//return pointer of the new node
Tnode* tree_create_node(){
    char data;
    scanf("%c",&data);
    getchar();//flush cache
    if(data!='#'){
        return  create_node(data);
    } else{
        return NULL;
    }
}
Tnode* tree_create_preord(Tree &T)
{
    T->lchild=tree_create_node();
    T->rchild=tree_create_node();
    if(T->lchild!=NULL)
    {
        tree_create_preord(T->lchild);

    }
    if(T->rchild!=NULL){
        tree_create_preord(T->rchild);
    }

    return 0;
}//recur

int tree_traverse_preord(Tree T){
    if(T!=NULL){
        printf("%c",T->data);
        tree_traverse_preord(T->lchild);
        tree_traverse_preord(T->rchild);
    }

    return 0;
}
int main() {
    Tree T=tree_create_node();
    tree_create_preord(T);
    tree_traverse_preord(T);
    return 0;
}
