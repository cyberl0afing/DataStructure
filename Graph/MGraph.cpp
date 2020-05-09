//
// Created by myzj on 20-5-10.
//

//
// Created by myzj on 20-5-10.
//

//
// Created by Yang on 2020/5/9.
//

#include <stdio.h>
#include <stdlib.h>

//

typedef struct GraphNode{
    int node_num;
    int data;
};//node
typedef struct MGraph{
    GraphNode node[5];
    int edge[5][5];//5*5邻接矩阵
    bool visited[5];

};//

int Graph_ini(MGraph &G) {
    //直接定义一个图
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <5; j++) {

            G.edge[i][j] = 1;
            G.edge[j][i] = 1;
        }
        G.edge[i][i]=0;
        G.node[i].node_num=i;
        G.node[i].data=i;
    }
    printf("generate age");
    return 0;
}//生成无向图
int Graph_reset_visited(MGraph &G){
    for (int i = 0; i < 5; ++i) {
        G.visited[i]= true;
    }
    return 0;
}

int DFS(MGraph G,int i){
    printf("%d",G.node[i].data);//打印节点值
    G.visited[i]= false;//设置访问标记
    //判断和i邻接的顶点，对相邻顶点调用DFS算法
    for (int j = 0; j <5; j++) {
        if((G.edge[i][j])!=0 && (G.visited[j])){
            DFS(G,j);
        }//判断是否有通向相邻节点的路径，同时该节点是否被访问
    }
    return 0;

}//遍历I
int main(){
    MGraph G;
    Graph_ini(G);
    Graph_reset_visited(G);
    DFS(G,0);
}