#include <iostream>
#include <set>
#include <queue>
#include <string>
using namespace std;
struct node {
  char data;
  int weight;
  node *lc;
  node *rc;
  string hafmCode;
  node(char d = '#', int w = 1, node *l = NULL, node *r = NULL) :
  data(d), weight(w), lc(l), rc(r) {
    hafmCode = "";
  }
  bool operator < (const node & ot) const {
    return weight < ot.weight;
  }
};


struct Cmp
{
        bool operator () ( node * const & x,  node * const & y) 
        {
                if (x->weight < y->weight)
                        return true;
                else
                        return false;
        }
};


int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  int ans[26] = {0};
  std::multiset<node*, Cmp> s;
  // 输入点
  for (int i = 0; i < t; ++i) {
    char temp;
    int cweight;
    cin >> temp >> cweight;
    s.insert(new node(temp,cweight));
  }
  node * root;

  // 构建树 利用set自动排序
  while (s.size()) {
    multiset<node*,Cmp>::iterator it = s.begin();
    ++it;
    multiset<node*,Cmp>::iterator it2 = it;
    it = s.begin();
    node * temp = new node('#',(*it)->weight + (*(it2))->weight, *it, *(it2));
    s.erase(it);
    it = s.begin();
    s.erase(it);
    if (s.size() == 0) {
      root = temp;
      break;
    } else {
      s.insert(temp);
    }
  }



  // 层次遍历的到编码
  queue<node*> q;
  q.push(root);
  int gggt = 0;
  while (q.size()) {
    node*temp = q.front();
    if(temp->data != '#') {
      // cout << temp->data << " " << temp->weight << " " << temp->hafmCode << endl;
      gggt += (temp->weight) * ((temp->hafmCode).length());
    }
    q.pop();
    if (temp->rc) {
      temp->rc->hafmCode = temp->hafmCode +  "1";
      q.push(temp->rc);
    }
    if (temp->lc) {
      temp->lc->hafmCode =temp->hafmCode + "0";
      q.push(temp->lc);
    }
  }
  cout << gggt << endl;
  return 0;
}
