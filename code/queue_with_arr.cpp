#include <bits/stdc++.h>
using namespace std;

template <typename T> class RingBuffer {
private:
  static const int MAX = 10;
  int frontIdx, rearIdx;
  T queue[MAX] = {0};

public:
  RingBuffer<T>() { frontIdx = rearIdx = 5; }

  bool empty() { return frontIdx == rearIdx; }

  void enqueue(T val) {
    rearIdx++;
    if (rearIdx >= MAX) {
      rearIdx -= MAX;
    }
    queue[rearIdx] = val;
  }

  T dequeue() {
    frontIdx++;
    if (frontIdx >= MAX) {
      frontIdx -= MAX;
    }
    return queue[frontIdx];
  }
};

int main() {
  RingBuffer<int> list;

  list.enqueue(1);
  list.enqueue(2);
  list.enqueue(3);
  list.enqueue(4);
  list.enqueue(5);
  list.enqueue(6);
  list.enqueue(7);
  list.enqueue(8);
  list.enqueue(9);
  list.enqueue(10);
  // 1 is overwritten with 0
  list.enqueue(11);

  cout << list.dequeue() << endl;
  cout << list.dequeue() << endl;
  cout << list.dequeue() << endl;
  cout << list.dequeue() << endl;
  cout << list.dequeue() << endl;
  cout << list.dequeue() << endl;
  cout << list.dequeue() << endl;
  cout << list.dequeue() << endl;
  cout << list.dequeue() << endl;
  cout << list.dequeue() << endl;

  return 0;
}
