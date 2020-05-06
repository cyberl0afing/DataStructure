#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define INILENGTH 100
#define INCREMENT 10
typedef struct {
    int * elem;
    int listsize;
    int length;
}SqList;

int SqList_ini(SqList &L) {
    L.elem=(int *)malloc(sizeof(int)*INILENGTH);
    L.length=0;
    L.listsize=INILENGTH;
    return 1;
}
void SqList_insert(SqList &L,int i,int e) {
    if(i<1||i>L.length+1) {
    }//检测插入位置是否合法
    if(L.length>=L.listsize) {
        int * newbase;
        newbase=(int *)realloc(L.elem,sizeof(int)*(INCREMENT+L.length));
        //if(!newbase) { return;}
        L.elem=newbase;
    }
    int * q;
    int * p;
    q=&L.elem[i-1];
    p=&L.elem[L.length-1];
    for (int j = 0; p>=q ; p--) {
        *(p+1)=*p;
    }
    *q=e;
    ++L.length;
}
void SqList_del(SqList &L,int i) {
    //if (i<1||i>=L.length+1){}
    int * q=&L.elem[L.length-1];//指向最后一个元素
    int * p=&L.elem[i-1];//指向第i个元素
    for(;p<=q-1;p++) {
        *p=*(p+1); //将后一个元素的值不断赋给其前驱
    }
    L.length--;
    //return OK;
}
void SqList_print(SqList &L) {
    for(int i=1;i<=L.length;++i){
        printf("%d",L.elem[i-1]);
    }
}
//&L == fun(SqList * mole){
// SqList L;
// *L=mole;
//
// }

int main() {
    SqList test;
    SqList_ini(test);
    for(int i=1;i<=20;i++){
        SqList_insert(test,i,i);
    }
    SqList_del(test,20);
    SqList_print(test);

}
