//
// Created by Yang on 2019/8/29.
//
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

typedef struct LNode {
    int data;
    struct LNode    * next;
} LNode,* LinkList;

int GetElem_L(LNode &L,int i){
    int j=1;
    LNode p=L;
    for(;j<=i-1;j++){
        p=(*p.next);
    }
    return L.data;
}
int LinkList_insert( LinkList &L,int i, int e){
    int j=1;
    LinkList p=L;
    while(j<=i-1){
        p=(*p).next;
        ++j;
    }
    LinkList s;
    s=(LinkList)malloc(sizeof(LNode));
    (*s).data=e;
    (*s).next=(*p).next;
    (*p).next=s;
    return 0;
}//尾插
void LinkList_tailadd(LinkList &L,int e){
    LinkList p=L;
    while(p->next){
        p=p->next;
    }//遍历到最后一个元素
    LinkList s;
    s=(LinkList)malloc(sizeof(LNode));
    s->next=NULL;
    p->next=s;
}//尾插
void LinkList_headadd(LinkList &L,int e){
    LinkList p=L;
    LinkList q=L->next;//保存L-》next
    LinkList s=(LinkList)malloc(sizeof(LNode));
    s->next=p->next;
    p->next=s;

}
int main(){

}