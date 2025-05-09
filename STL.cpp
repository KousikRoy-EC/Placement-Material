#include <iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

/*
int main() {
  
  int basic[3] ={1,2,3};

  array<int,4> a = {1,2,3,4};

  int size = a.size();

  for(int i=0;i<size;i++ ){ 
    cout<<a[i]<<endl;
  }

  cout<<"Element at 2nd Index-> "<<a.at(2)<<endl;

  cout<<"Empty or not-> "<<a.empty()<<endl;

  cout<<"First Element-> "<<a.front()<<endl;
  cout<<"last Element-> "<<a.back()<<endl;

}







// Vector:


int main() {
  
  vector<int> v;

  vector<int> a(5,1);

  vector<int> last(a);
  
   cout<<"print last"<<endl;
  for(int i:last) {
    cout<<i<<" ";
  }cout<<endl;

  cout<<"Capacity-> "<<v.capacity()<<endl;

  v.push_back(1);
  cout<<"Capacity-> "<<v.capacity()<<endl;

  v.push_back(2);
  cout<<"Capacity-> "<<v.capacity()<<endl;

  v.push_back(3);
  cout<<"Capacity-> "<<v.capacity()<<endl;
  cout<<"Size-> "<<v.size()<<endl;

  cout<<"Elemetn at 2nd Index" <<v.at(2)<<endl;

  cout<<"front " <<v.front()<<endl;
  cout<<"back " <<v.back()<<endl;

 cout<<"before pop"<<endl;
  for(int i:v) {
    cout<<i<<" ";
  }cout<<endl;

  v.pop_back();

  cout<<"after pop"<<endl;
  for(int i:v) {
    cout<<i<<" ";
  }

  cout<<"before clear size "<<v.size()<<endl;
  v.clear();
  cout<<"after clear size "<<v.size()<<endl;



}












// Deque:
 
int main() {
  
  deque<int> d;

d.push_back(1);
d.push_front(2);

d.pop_front();
cout<<endl;

cout<<"Print First INdex Element-> "<<d.at(1)<<endl;

cout<<"front "<<d.front()<<endl;
cout<<"back "<<d.back()<<endl;

cout<<"Empty or not" <<d.empty()<<endl;

cout<<"before erase" <<d.size()<<endl;
d.erase(d.begin(),d.begin()+1);
cout<<"after erase" <<d.size()<<endl;
for(int i:d){
  cout<<i<<endl;
}

}


*/

// List:

int main() {
  list<int> l;

  list<int> n(5,100);
  cout<<"Printing n"<<endl;

 
 for(auto i =n.begin();i!=n.end();i++) {
   cout<<*i<<" ";
    }cout<<endl;
  


  for(int i:n) {
    cout<<i<<" ";
  }cout<<endl;
  l.push_back(1);
  l.push_front(2);

  for(int i:l) {
    cout<<i<<" ";
  }
  cout<<endl;
  l.erase(l.begin(),l.end());
  cout<<"after erase"<<endl;
  for(int i:l) {
    cout<<i<<" ";
  }

  cout<<"size of list"<<l.size()<<endl;
}





/*

// Stack:

int main() {
  stack<string> s;

  s.push("love");
  s.push("babbar");
  s.push("Kumar");

  cout<<"Top Element-> "<<s.top()<<endl;

  s.pop();
  cout<<"Top Element-> "<<s.top()<<endl;

  cout<<"size of stack"<<s.size()<<endl;

  cout<<"Empty or not "<<s.empty()<<endl;

}










// Queue:

int main() {
  
  queue<string> q;

  q.push("love");
  q.push("Babbar");
  q.push("Kumar");

  cout<<"Size before pop" <<q.size()<<endl;
  
  cout<<"First Element "<<q.front()<<endl;
  q.pop();
  cout<<"First Element "<<q.front()<<endl;

  cout<<"Size after pop" <<q.size()<<endl;

}








// Priority_queue:

int main() {
  //max heap
  priority_queue<int> maxi;

  //min - heap
  priority_queue<int,vector<int> , greater<int> > mini;

  maxi.push(1);
  maxi.push(3);
  maxi.push(2);
  maxi.push(0);
  cout<<"size-> "<<maxi.size()<<endl;
  int n = maxi.size();
  for(int i=0;i<n;i++) {
    cout<<maxi.top()<<" ";
    maxi.pop();
  }cout<<endl;

  mini.push(5);
  mini.push(1);
  mini.push(0);
  mini.push(4);
  mini.push(3);

  int m = mini.size();
  for(int i=0;i<m;i++) {
    cout<<mini.top()<<" ";
    mini.pop();
  }cout<<endl;

cout<<"khaali h kya bhai  ?? -> "<<mini.empty()<<endl;


}
// Set:

int main() {
  set<int> s;

  s.insert(5);
  s.insert(5);
  s.insert(5);
  s.insert(1);
  s.insert(6);
  s.insert(6);
  s.insert(0);
  s.insert(0);
  s.insert(0);

  for(auto i : s) {
    cout<<i<<endl;
  }cout<<endl;

set<int>::iterator it = s.begin();
it++;

  s.erase(it);

  for(auto i : s) {
    cout<<i<<endl;
  }
cout<<endl;
cout<<"-5 is present or not -> "<<s.count(-5)<<endl;

set<int>::iterator itr = s.find(5);

for(auto it=itr;it!=s.end();it++) {
  cout<<*it<<" ";
}cout<<endl;

}


// Map:

int main() {
  map<int,string> m;

  m[1]= "babbar";
  m[13]="kumar";
  m[2]="love";

  m.insert( {5,"bheem"});

  cout<<"before erase"<<endl; 
  for(auto i:m) {
    cout<<i.first<<" "<<i.second<<endl;
  }

  cout<<"finding -13 -> " <<m.count(-13)<<endl;

 // m.erase(13);
  cout<<"after erase"<<endl;
  for(auto i:m) {
    cout<<i.first<<" "<<i.second<<endl;
  }cout<<endl<<endl;

  auto it = m.find(5);

  for(auto i=it;i!=m.end();i++) {
    cout<<(*i).first<<endl;
  }

}







// Algo:

int main() {
  
  vector<int> v;

  v.push_back(1);
  v.push_back(3);
  v.push_back(6);
  v.push_back(7);

  cout<<"Finding 6-> "<<binary_search(v.begin(),v.end(),6)<<endl;

  cout<<"lower bound-> "<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;
  cout<<"Uppper bound-> "<<upper_bound(v.begin(),v.end(),4)-v.begin()<<endl;

  int a =3;
  int b =5;

  cout<<"max -> "<<max(a,b);

  cout<<"min -> "<<min(a,b);

  swap(a,b);
  cout<<endl<<"a-> "<<a<<endl;

  string abcd = "abcd";
  reverse(abcd.begin(),abcd.end());
  cout<<"string-> "<<abcd<<endl;

  rotate(v.begin(),v.begin()+1,v.end());
  cout<<"after rotate"<<endl;
  for(int i:v){
    cout<<i<<" ";
  }

  sort(v.begin(),v.end());
  cout<<"after sorting"<<endl;
for(int i:v){
    cout<<i<<" ";
  }









  #include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Implementing BST from scratch

//       42
//     /     \
//    35     56
//   /  \   /  \
//  24  36 50  66

struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

void inorderTraversal(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);
}

void preorderTraversal(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->data << " ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout << root->data << " ";
}

void printLevelOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  queue<Node *> q;
  q.push(root);

  while (!q.empty())
  {
    Node *curr = q.front();
    q.pop();
    cout << curr->data << " ";
    if (curr->left != NULL)
    {
      q.push(curr->left);
    }
    if (curr->right != NULL)
    {
      q.push(curr->right);
    }
  }
}

void findNode(Node *root, int key)
{
  if (root == NULL)
  {
    return;
  }
  else if (root->data == key)
  {
    cout << "Node Exist" << endl;
  }
  else if (root->data > key)
  {
    findNode(root->left, key);
  }
  else
  {
    findNode(root->right, key);
  }
}

Node *insertNode(Node *root, int key)
{
  if (root == NULL)
  {
    Node *curr = new Node(key);
    return curr;
  }
  else if (root->data > key)
  {
    root->left = insertNode(root->left, key);
  }
  else
  {
    root->right = insertNode(root->right, key);
  }
  return root;
}

Node *deleteNode(Node *root, int key)
{
  if (root == NULL)
  {
    return root;
  }
  else if (root->data == key)
  {
    if (root->left == NULL && root->right == NULL)
    {
      delete root;
      return NULL;
    }
    else if (root->left == NULL)
    {
      Node *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == NULL)
    {
      Node *temp = root->left;
      delete root;
      return temp;
    }
    else
    {
      Node *temp = root->right;
      while (temp->left != NULL)
      {
        temp = temp->left;
      }
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }
  else if (root->data > key)
  {
    root->left=deleteNode(root->left, key);
  }
  else
  {
    root->right=deleteNode(root->right, key);
  }
  return root;
}

int main()
{
  Node *root = new Node(42);
  root->left = new Node(35);
  root->right = new Node(56);
  root->left->left = new Node(24);
  root->left->right = new Node(36);
  root->right->left = new Node(50);
  root->right->right = new Node(66);

  // Traversal

  // inorderTraversal(root);
  // cout << endl;
  // preorderTraversal(root);
  // cout << endl;
  // postorderTraversal(root);
  // cout << endl;
  // printLevelOrder(root);
  // cout<< endl;

  // find node with val Exist or Not
  // findNode(root, 20);

  // Insert a Node
  // insertNode(root, 2);
  // printLevelOrder(root);

  // Delete a Node
  // deleteNode(root, 35);
  // printLevelOrder(root);

  return 0;
}

}

*/
