//
// Created by Fangyx on 2021/12/21.
//

#ifndef MYSTL_MYLIST_H
#define MYSTL_MYLIST_H

class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode():val(0),next(nullptr){}
        ListNode(int x):val(x),next(nullptr){}
    };

    MyLinkedList() {
        dummy_ = new ListNode();//虚拟节点
        size_ = 0;
    }

    int get(int index) {
        if(index < 0||index >= size_) return -1;
        ListNode* p = dummy_->next;

        while(index--){
            p = p->next;
        }

        return p->val;
    }

    void addAtHead(int val) {

        ListNode* newNode = new ListNode(val);
        newNode->next = dummy_->next;
        dummy_->next = newNode;
        size_++;
    }

    void addAtTail(int val) {

        ListNode* newNode = new ListNode(val);

        ListNode* cur = dummy_;
        while(cur->next!=nullptr){
            cur = cur->next;
        }
        cur->next = newNode;
        size_++;

    }

    void addAtIndex(int index, int val) {
        if(index < 0){
            addAtHead(val);
            return;
        }
        if(index >= size_ ) {
            addAtTail( val) ;
            return ;
        }

        ListNode* newNode = new ListNode(val);
        ListNode* p = dummy_;

        while(index--){
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
        size_++;
    }

    void deleteAtIndex(int index) {
        if(index >= size_ || index < 0) return ;
        ListNode* p = dummy_;

        while(index--){
            p = p->next;
        }
        p->next = p->next->next;
        size_--;
    }
private:

    int size_;

    ListNode* dummy_;
};

#endif //MYSTL_MYLIST_H
