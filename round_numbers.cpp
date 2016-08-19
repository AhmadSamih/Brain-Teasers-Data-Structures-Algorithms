bool cmp(pair<int, float>a, pair<int, float>b){  
  return (a.second - floor(a.second)) > (b.second - floor(b.second));
}
vector<int> roundNumbers2(vector<float>input){

    int rounded_sum = 0;  float sum = 0;
    vector<int>res(input.begin(), input.end());

  vector<pair<int,float>>tmp; // to sort items based on each one's fraction
    for(uint32_t i=0; i<input.size();i++){      
      tmp.emplace_back(i, input[i]);
    }
  
  sum = accumulate(input.begin(), input.end(), 0.0);
  rounded_sum= accumulate(res.begin(), res.end(), 0);
  int remain = round(sum) - rounded_sum;
  
  sort(tmp.begin(), tmp.end(), cmp);
  
  int tmp_idx = 0;
  while(remain-->0){
    res[tmp[tmp_idx++].first]++;
  }  

  return res;
}

vector<int>  roundNumbers(vector<float>&input){

  float f_sum = 0;
  int i_sum = 0;
  vector<pair<float, int>>base(input.size());
  for(uint32_t i=0;i<input.size();i++){
    i_sum+= input[i];
    f_sum+= input[i];
    int num = input[i];
    float rem = input[i] - num;
    base[i] = make_pair(rem,i);
  }
  f_sum = round(f_sum);
  
  int round = f_sum - i_sum;
  sort(base.begin(), base.end(), [](pair<float,int>&a, pair<float,int>&b){return a.first > b.first;});

  vector<int>output(input.size());
  for(uint32_t i=0; i<base.size(); i++){
    output[i] = floor(input[base[i].second]);
    if(round-->0){
      ++output[i];
    }
  }
  
  return output;
}

int main() {

  vector<float>input = {5.9,2.2,3.3,2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 10.5, 10.1, 10.9};
  //vector<int>output = roundNumbers(input);
  vector<int>output = roundNumbers(input);

  int final = 0;
  for(auto &x:output)  
    final +=x;
  cout<<final;

  return 0;
}
