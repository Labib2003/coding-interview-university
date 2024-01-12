// - [ ] Implement a vector (mutable array with automatic resizing):
//   - [ ] Practice coding using arrays and pointers, and pointer math to jump
//   to an index instead of using indexing.
//   - [x] New raw data array with allocated memory
//     - can allocate int array under the hood, just not use its features
//     - start with 16, or if the starting number is greater, use power of 2 -
//     16, 32, 64, 128
//   - [x] size() - number of items
//   - [x] capacity() - number of items it can hold
//   - [x] is_empty()
//   - [x] at(index) - returns the item at a given index, blows up if index out
//   of bounds
//   - [x] push(item)
//   - [x] insert(index, item) - inserts item at index, shifts that index's
//   value and trailing elements to the right
//   - [x] prepend(item) - can use insert above at index 0
//   - [x] pop() - remove from end, return value
//   - [x] delete(index) - delete item at index, shifting all trailing elements
//   left
//   - [x] remove(item) - looks for value and removes index holding it (even if
//   in multiple places)
//   - [x] find(item) - looks for value and returns first index with that value,
//   -1 if not found
//   - [x] resize(new_capacity) // private function
//     - when you reach capacity, resize to double the size
//     - when popping an item, if the size is 1/4 of capacity, resize to half

#include <bits/stdc++.h>

using namespace std;

class MyVector {
private:
  int len = 0, cap = 16;
  int *arr = new int[cap];

  void resize(double mod) {
    if (mod < 0)
      cout << "Invalid modifier: Only positive numbers are allowd." << endl;
    cap = cap * mod;
    arr = (int *)realloc(arr, sizeof(int) * cap);
  }

public:
  int size() { return len; }

  int capacity() { return cap; }

  bool is_empty() { return len == 0; }

  int at(int idx) {
    if (idx < len)
      return arr[idx];
    else {
      cout << "Invalid index." << endl;
      return '\0';
    }
  }

  void push(int val) {
    if (len >= cap)
      resize(2);
    arr[len++] = val;
  }

  void insert(int idx, int val) {
    if (idx > len || idx >= cap * 2) {
      cout << "Invalid index." << endl;
      return;
    }

    if (idx >= cap)
      resize(2);

    for (int i = len; i >= idx; i--)
      arr[i + 1] = arr[i];
    arr[idx] = val;
    len++;
  }

  void prepend(int val) { insert(0, val); }

  int pop() {
    if (len == 0) {
      cout << "Underflow: List is empty." << endl;
      return '\0';
    }
    int val = arr[len - 1];
    len--;

    if (len <= cap / 4)
      resize(.5);

    return val;
  };

  void del(int idx) {
    if (len == 0) {
      cout << "Underflow: List is empty." << endl;
      return;
    }

    for (int i = idx; i < len; i++)
      arr[i] = arr[i + 1];
    len--;

    if (len <= cap / 4)
      resize(.5);
  }

  void remove(int val) {
    for (int i = 0; i < len;) {
      if (arr[i] == val)
        del(i);
      else
        i++;
    }
  };

  int find(int val) {
    for (int i = 0; i < len; i++) {
      if (arr[i] == val)
        return i;
    }
    return -1;
  }
};

int main() {
  MyVector v;

  v.push(6);
  v.push(5);
  v.push(5);
  v.push(5);
  v.push(4);
  v.push(3);
  v.push(2);
  v.push(1);

  v.insert(2, 10);
  v.del(2);
  v.remove(5);
  v.prepend(100);
  int popped = v.pop();
  cout << popped << endl;

  for (int i = 0; i < v.size(); i++)
    cout << v.at(i) << " ";
  cout << endl;
  cout << v.find(69) << endl;

  return 0;
}
