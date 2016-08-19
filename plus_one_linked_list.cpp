struct node{
  int val;
  node*next;
  node(int v):val(v),next(NULL){};
  node(int v, node* n):val(v),next(n){};
};

int main(){
 
  node * e = new node(8, NULL);
  node * d = new node(8,e);
  node * c = new node(8,d);
  node * b = new node(8,c);
  node * a = new node(8,b);
 
  node*tmp = a;
  while(tmp){
    cout<<tmp->val;
    tmp = tmp->next;
  }
  cout<<endl;
  
  node* head = a;
  node* prev = NULL;
  node* next;
  while(head){
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }
  head = prev;
  
  int carry = 1;
  prev = NULL;
  while(head){
    head->val = head->val + carry;
    if(head->val == 10){
        head->val = 0;
        carry = 1;
    }else{
      carry = 0;
    }    
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  } 
  head = prev;
  
  node* n_head;
  if(carry){
    n_head = new node(1,head);
    head = n_head;
  }
  
  
  tmp = head;
  while(tmp){
    cout<<tmp->val;
    tmp = tmp->next;
  }
  
  return 0;
}
