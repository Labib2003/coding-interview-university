// - [ ] Singly Linked List:
//   - [x] size() - returns the number of data elements in the list
//   - [x] empty() - bool returns true if empty
//   - [x] value_at(index) - returns the value of the nth item (starting at 0
//   for first)
//   - [x] push_front(value) - adds an item to the front of the list
//   - [x] pop_front() - remove the front item and return its value
//   - [x] push_back(value) - adds an item at the end
//   - [x] pop_back() - removes end item and returns its value
//   - [x] front() - get the value of the front item
//   - [x] back() - get the value of the end item
//   - [x] insert(index, value) - insert value at index, so the current item at
//   that index is pointed to by the new item at the index
//   - [x] erase(index) - removes node at given index
//   - [x] value_n_from_end(n) - returns the value of the node at the nth
//   position from the end of the list
//   - [x] reverse() - reverses the list
//   - [x] remove_value(value) - removes the first item in the list with this
//   value

#include <bits/stdc++.h>
using namespace std;

template <typename T> struct Node {
  T data;
  Node<T> *next;
};

template <typename T> class LinkedList {
private:
  int length;
  Node<T> *head, *tail;

public:
  LinkedList() {
    length = 0;
    head = tail = nullptr;
  }

  int size() { return length; }

  bool empty() { return length == 0; }

  T value_at(int idx) {
    if (idx < 0 || idx >= length) {
      cout << "Invalid index." << endl;
      return T();
    }

    Node<T> *temp = head;
    for (int i = 0; i < idx; i++)
      temp = temp->next;

    return temp->data;
  }

  void push_front(T val) {
    Node<T> *newNode = new Node<T>();

    newNode->data = val;
    newNode->next = nullptr;

    if (length == 0)
      head = tail = newNode;
    else {
      newNode->next = head;
      head = newNode;
    }

    length++;
  }

  T pop_front() {
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

  void push_back(T val) {
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

  T pop_back() {
    if (length <= 0) {
      cout << "Underflow Condition: Cannot pop from an empty list." << endl;
      return T();
    }

    Node<T> *temp = tail;
    Node<T> *nodeBeforeTail = head;

    T data = temp->data;

    // length - 1 is the index of tail, hence length - 2 is the node before tail
    for (int i = 0; i < length - 2; i++)
      nodeBeforeTail = nodeBeforeTail->next;

    tail = nodeBeforeTail;

    delete temp;
    length--;

    return data;
  }

  void insert(int idx, T val) {
    if (idx < 0 || idx >= length) {
      cout << "Invalid index." << endl;
      return;
    }

    if (idx == 0) {
      push_front(val);
      return;
    }
    if (idx == length - 1) {
      push_back(val);
      return;
    }

    Node<T> *newNode = new Node<T>();
    Node<T> *temp = head;

    newNode->data = val;
    newNode->next = nullptr;

    for (int i = 0; i < idx - 1; i++)
      temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    length++;
  }

  T front() { return head->data; }

  T back() { return tail->data; }

  T erase(int idx) {
    if (idx < 0 || idx >= length) {
      cout << "Invalid index." << endl;
      return T();
    }

    if (idx == 0) {
      return pop_front();
    }
    if (idx == length - 1) {
      return pop_back();
    }

    Node<T> *prevNode = head;
    for (int i = 0; i < idx - 1; i++)
      prevNode = prevNode->next;

    Node<T> *currNode = prevNode->next;
    T data = currNode->data;
    prevNode->next = currNode->next;
    delete currNode;
    length--;

    return data;
  }

  void value_n_from_end(int idx) {
    for (int i = 0; i < length; i++) {
      if (i >= idx)
        cout << value_at(i) << " ";
    }
    cout << endl;
  }

  void reverse() {
    Node<T> *current = head;
    Node<T> *prev = tail, *next = nullptr;

    for (int i = 0; i < length; i++) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    Node<T> *temp = head;
    head = prev;
    tail = temp;
  }

  T remove_value(T val) {
    Node<T> *temp = head;
    int i;

    for (i = 0; i < length && temp->data != val; i++)
      temp = temp->next;

    return erase(i);
  }
};

int main() {
  LinkedList<int> list;

  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  list.push_front(5);

  list.push_back(10);
  list.push_back(20);
  list.push_back(30);
  list.push_back(40);
  list.push_back(50);

  cout << "Popped front: " << list.pop_front() << endl;
  cout << "Popped back: " << list.pop_back() << endl;
  cout << "Head: " << list.front() << endl;
  cout << "Tail: " << list.back() << endl;

  list.insert(4, 69);
  list.erase(4);
  list.remove_value(30);
  list.remove_value(3);

  for (int i = 0; i < list.size(); i++) {
    cout << list.value_at(i) << " ";
  }
  cout << endl;

  list.reverse();
  list.value_n_from_end(0);

  return 0;
}
