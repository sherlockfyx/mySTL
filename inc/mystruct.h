//
// Created by Fangyx on 2021/12/4.
//
#ifndef HELLOWORLD_MYSTRUCT_H
#define HELLOWORLD_MYSTRUCT_H

#include <vector>
#include <queue>
//=============================struct 定义相关数据结构节点============================//
//单向链表节点
struct ListNode{
    ListNode* next;
    int val;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode* ptr):val(x),next(ptr){}
};

//二叉树节点
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* l,TreeNode* r):val(x),left(l),right(r){}
};

//测试大小端
union {
    short value;
    char arr[sizeof(value)];
} un;


//优先队列-回调函数
struct cmp{
    bool operator()(int a,int b){
        return a>b;
    }
};

std::priority_queue<int,std::vector<int>,std::greater<int>> q;//最小堆
std::priority_queue<int,std::vector<int>,cmp> q1;//最小堆

#endif //HELLOWORLD_MYSTRUCT_H
