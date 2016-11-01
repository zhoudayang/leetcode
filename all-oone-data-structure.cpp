//key idea: hash map and sorted map 
class AllOne {
 public:
  /** Initialize your data structure here. */
  AllOne() : words(), times() {

  }

  /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
  void inc(string key) {
    int count = ++words[key];
    int before = count - 1;
    if(count != 1){
      times[before].erase(key);
      if(times[before].empty()){
        times.erase(before);
      }
    }
    times[count].insert(key);
  }

  /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
  void dec(string key) {
    if(!words.count(key))
      return;
    int count = --words[key];
    int before = count + 1;
    times[before].erase(key);
    if(times[before].empty()){
      times.erase(before);
    }
    if(count == 0){
      words.erase(key);
    }
    else{
      times[count].insert(key);
    }
  }

  /** Returns one of the keys with maximal value. */
  string getMaxKey() {
    auto it = times.rbegin();
    if(it==times.rend())
      return "";
    return *(it->second.begin());
  }

  /** Returns one of the keys with Minimal value. */
  string getMinKey() {
    auto it = times.begin();
    if(it==times.end())
      return "";
    return *(it->second.begin());
  }
 private:
  unordered_map<string, int> words;
  map<int, unordered_set<string>> times;

};