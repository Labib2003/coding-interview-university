// - [x] Implement using linked-list, with tail pointer:
//   - enqueue(value) - adds value at a position at the tail
//   - dequeue() - returns value and removes least recently added element
//   (front)
//   - empty()

#include <bits/stdc++.h>
using namespace std;

template <typename T> struct Node {
  T data;
  Node<T> *next;
};

template <typename T> class RingBuffer {
private:
  int length;
  Node<T> *head, *tail;

public:
  RingBuffer() {
    length = 0;
    head = tail = nullptr;
  }

  bool empty() { return length == 0; }

  T dequeue() {
    if (length <= 0) {
      cout << "Underflow Condition: Cannot pop from an empty list." << endl;
      return T();
    }

    Node<T> *temp = head;

    T data = temp->data;
    head = head->next;

    delete temp;
    length--;

    return data;
  }

  void enqueue(T val) {
    Node<T> *newNode = new Node<T>();

    newNode->data = val;
    newNode->next = nullptr;

    if (length == 0)
      head = tail = newNode;
    else {
      tail->next = newNode;
      tail = newNode;
    }

    length++;
  }
};

int main() {
  RingBuffer<int> list;

  list.enqueue(1);
  list.enqueue(2);
  list.enqueue(3);
  cout << list.dequeue() << endl;
  cout << list.dequeue() << endl;
  cout << list.dequeue() << endl;

  return 0;
}
