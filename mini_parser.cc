/*
	This solution uses a stack to record the NestedInteger's.
	At the very beginning, an empty NestedInteger is placed in the stack. This NestedInteger will be regarded as a list that holds one but only one NestedInteger, which will be returned in the end.
	Logic: When encountering '[', the stack has one more element. When encountering ']', the stack has one less element.
*/
class Solution {
 public:
  NestedInteger deserialize(string s) {
    //a lambda function to judge if the given is a part of number
    auto isnumber = [](char ch) { return ch == '-' || isdigit(ch); };
    stack<NestedInteger> container;
    container.push(NestedInteger());
    for (auto it = s.begin(); it != s.end();) {
      char ch = *it;
      if (isnumber(ch)) {
        // pointer to point first pos that is not digit or the end of the string
        auto end = it;
        while(end != s.end() and isnumber(*end)){
          ++end;
        }
        string number = string(it,end);
        int value = stoi(number);
        container.top().add(NestedInteger(value));
        it = end;
      }
      else {
        if (ch == '[') {
          container.push(NestedInteger());
        }
        else if (ch == ']') {
          NestedInteger cur = container.top();
          container.pop();
          container.top().add(cur);
        }
        ++it;
      }
    }
    NestedInteger result = container.top().getList().front();
    return result;
  }
};
