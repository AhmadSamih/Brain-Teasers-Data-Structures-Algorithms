// To execute C++, please define "int main()"
class TwoSum {

public:
  unordered_map<int,int> diff;
  
  // Add the number to an internal data structure.
  void add(int number) {
    diff[number]++;
  }

  // Find if there exists any pair of numbers which sum is equal to the value.
  bool find(int value) {
    for(auto &x: diff){
      int d = value - x.first;
      if( (d == x.first && x.second>1) || (d!=x.first && diff.find(d)!=diff.end())){
        return true;
      }
    }
    return false;
  }

};