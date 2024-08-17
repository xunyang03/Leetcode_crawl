class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int a) : val(a), next(nullptr) {}
    };

    MyLinkedList() { 
        dummyHead = new ListNode(0); 
        size_ = 0;    
    }

    int get(int index) {
        ListNode* cur = dummyHead->next;
        if (index < 0 || index > size_-1)
            return -1;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        ListNode* newhead = new ListNode(val);
        newhead->next = dummyHead->next;
        dummyHead->next = newhead;
        size_++;
        return;
    }

    void addAtTail(int val) {
        ListNode* tail = new ListNode(val);
        ListNode* cur = dummyHead;
        while (cur->next)
            cur = cur->next;
        cur->next = tail;
        size_++;
        return;
    }

    void addAtIndex(int index, int val) {
        ListNode* cur = dummyHead;
        if (index < 0 || index > size_)
            return;
        if (index == size_){
            addAtTail(val);
            return;
        }
        while (index--){
            cur = cur->next;
        }
        ListNode* node = new ListNode(val);
        ListNode* temp = cur->next;
        node->next = temp;
        cur->next = node;
        size_++;
        return;
    }

    void deleteAtIndex(int index) {
        ListNode* cur = dummyHead;
        if (index < 0 || index > size_-1)
            return;
        while (index--) {
            cur = cur->next;
        }
        ListNode* temp = cur->next;
        ListNode* temp2 = cur->next->next;
        cur->next = temp2;
        delete temp;
        size_--;
        return;
    }

private:
    ListNode* dummyHead;
    int size_;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */