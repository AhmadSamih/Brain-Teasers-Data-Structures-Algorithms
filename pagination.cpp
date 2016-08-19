bool cmp(string &a, string &b){
 
  vector<string>tmp = {a,b};
  vector<float>score(2);
  for(uint32_t k=0; k<2; k++){
    int commas = 0; uint32_t left =0;
    for(uint32_t i=0; i<tmp[k].size();i++){
      if(tmp[k][i] == ','){
        commas++;
        if(commas == 2)
          left = i+1;
        if(commas == 3){
          score[k] = stof(tmp[k].substr(left, i-left));
          break;
        }
      }
    }
  }
  return score[0] > score[1];
   
  float score[2];
  string tmp[2] = {a,b};
  
  for(int i=0; i<2; i++){
    int cnt =2;
    char *str = strdup(tmp[i].c_str());
    char *token = strtok(str,",");
    while(token){
      if(!cnt--){
        score[i] = stof(token);
        break;
      }
      token = strtok(NULL, ",");
    }
  }
  return score[0] > score[1];
}

list<string> pagination(list<string> &str_list){
  
  str_list.sort(cmp);
  list<string>output;
  int processed = 0;
  int size= str_list.size();
  while(processed < size){
    int count = 12;
    unordered_map<int, bool>visited;
    for(auto itr=str_list.begin(); itr != str_list.end();){
     int del = 0;
      int id = stoi((*itr).substr(0,(*itr).find_first_of(',')));
      if(!visited[id]){
        output.push_back(*itr);
        processed++;
        visited[id] = true;
        del = 1;
        count--;
      }
      del ? str_list.erase(itr++) : itr++;
    }
     output.push_back("\nnew page\n");
  }
  return output;
}

int main() {

      vector<string> strs = {              
      "1,16,205.1,SanFrancisco",
      "6,29,204.1,SanFrancisco",
      "7,20,203.1,SanFrancisco",
      "8,21,202.1,SanFrancisco",
      "2,18,201.1,SanFrancisco",
      "2,30,200.1,SanFrancisco",
      "15,27,109.1,Oakland",
      "10,13,108.1,Oakland",
      "11,26,107.1,Oakland",
      "12,9,106.1,Oakland",
      "13,1,105.1,Oakland",
      "22,17,104.1,Oakland",
      "1,2,103.1,Oakland",
      "28,24,102.1,Oakland",
      "18,14,11.1,SanJose",
      "6,25,10.1,Oakland",
      "19,15,9.1,SanJose",
      "3,19,8.1,SanJose",
      "3,11,7.1,Oakland",
      "27,12,6.1,Oakland",
      "1,3,5.1,Oakland",
      "25,4,4.1,SanJose",
      "5,6,3.1,SanJose",
      "29,22,2.1,SanJose",
      "30,23,1.1,SanJose",
      "1,28,300.1,SanFrancisco",
      "4,5,209.1,SanFrancisco",
      "20,7,208.1,SanFrancisco",
      "23,8,207.1,SanFrancisco",
      "16,10,206.1,Oakland",
    };
  
  
  list<string> str_list(strs.begin(), strs.end()); 
  
  list<string> output = pagination(str_list);
  for(auto &x:output)
    cout<<x<<endl;
  
  return 0;
}
