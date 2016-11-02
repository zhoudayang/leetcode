//key idea: 维护一个最小堆来存放较大的那一半数，一个最小堆来存放较小的那一半数。

class MedianFinder {
 public:
  MedianFinder() :smaller(),bigger()
  {}

  // Adds a number into the data structure.
  void addNum(int num) {
      long number = static_cast<long>(num);
      smaller.push(number);
      bigger.push(smaller.top());
      smaller.pop();
      if(smaller.size() < bigger.size()){
          smaller.push(bigger.top());
          bigger.pop();
      }
  }

  // Returns the median of current data stream
  double findMedian() {
    if(smaller.size() > bigger.size())
      return smaller.top();
    return static_cast<double>(smaller.top() + bigger.top())/2.0;
  }
 private:
  priority_queue<long> smaller;
  priority_queue<long,vector<long>,greater<long>> bigger;
};
