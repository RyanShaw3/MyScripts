struct ListNode {
  int val;
  ListNode *next;
  ListNode(int _val) : val(_val), next(nullptr) {}
};
class MyLinkedList {
 private:
  int size;
  ListNode *head;

 public:
  MyLinkedList() {
    this->size = 0;
    this->head = new ListNode(0);
  }

  int get(int index) {
    if (index < 0 || index >= size) {
      return -1;
    }
    ListNode *cur = head;
    for (int i = 0; i <= index; i++) {
      cur = cur->next;
    }
    return cur->val;
  }

  void addAtHead(int val) { addAtIndex(0, val); }

  void addAtTail(int val) { addAtIndex(size, val); }

  void addAtIndex(int index, int val) {
    if (index > size) {
      return;
    }
    index = index < 0 ? 0 : index;
    ListNode *node = new ListNode(val);
    ListNode *pre = head;
    for (int i = 0; i < index; i++) {
      pre = pre->next;
    }
    node->next = pre->next;
    pre->next = node;
    size++;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= size) {
      return;
    }
    ListNode *pre = head;
    for (int i = 0; i < index; i++) {
      pre = pre->next;
    }
    ListNode *cur = pre->next;
    pre->next = cur->next;
    delete cur;
    size--;
  }
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