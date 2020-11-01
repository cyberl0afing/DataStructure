#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

void insertSort(int *a, int lenth) {


    for (int i = 2; i < lenth; i++) {
        a[0] = a[i];//保存当前元素
        int j = i - 1;
        for (; j >= 0 && a[j] > a[0]; --j) {
            a[j + 1] = a[j];//移动元素
        }//把比a[i]小的元素进行位移，当j指向比当前更小的元素时，将a[0]放在j+1处
        //printf("\n-------\nj==%d",j);
        a[j + 1] = a[0];

    }//从第二个元素开始，将元素插入有序集合a[0...i-1]中,当i=length-1时

}

void shellSort(int *a, int length) {
    length = length - 1;//a[0]不能用

    for (int i = length / 2; i >= 1; i = i / 2) {
        //空出a0
        for (int j = 1 + i; j <= length; j++) {
            //从子表的最后一个元素开始元素开始，j标明子表编号,同时保证j-i不会越界
            //j隐含上界，k隐含下界
            if (a[j] < a[j - i]) {
                a[0] = a[j];//保存当前指向的元素
                int k = j - i;//指向前一个元素
                //需要进行顺序调整
                for (; a[0] < a[k] && k>=1; k = k - i) {
                    //如果表中元素比a[0]大，那么则将表中的元素向后进行移动
                    a[k+i] = a[k];
                }//将元素进行移动
                a[k + i] = a[0];//元素写回
            }
        }//对子表内容进行插入排序
    }//增量为i时的插入排序，子表为1,1+i,1+2i,1+3i,... 2,2+i,2+2i,...
}//初始增量为n的希尔排序

void switchSort(int *a,int length){

}
//repeat the procedure of selecting the maxium

void bubbleSort(int *a,int length){
    for(int i=length;i>=1;i--){
        for(int j=0;j<i;j++){

            if(a[j]>a[j+1]){
                a[0]=a[j];
                a[j]=a[j+1];
                a[j+1]=a[0];
            }//当前元素大于下一个元素则交换元素顺序，当j=i-1时，完成最后一次判断

        }
    }//每次冒泡都使待排序的表长减一，最高位变成最大值
}
//bubble


int main() {
    int a[9] = {0, 5, 87, 56, 1, 8, 7, 5, 9};
    bubbleSort(a, 9);
    for (int k = 0; k < 9; k++) {
        printf("%d", a[k]);
        printf("\t");
    }
}
