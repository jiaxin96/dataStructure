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

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  std::set<node*> s;
  for (int i = 0; i < t; ++i) {
    char temp;
    cin >> temp;
    bool hasBeen = false;
    for (set<node*>::iterator it = s.begin(); it != s.end(); ++it) {
      if ((*it)->data == temp) {
        (*it)->weight += 1;
        hasBeen = true;
        break;
      }
    }
    if (!hasBeen) {
      s.insert(new node(temp));
    }
  }
  node * root = new node();
  while (s.size()) {
    set<node*>::iterator it = s.begin();
    set<node*>::iterator it2 = it++;
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
  queue<node*> q;
  q.push(root);
  while (q.size()) {
    node*temp = q.front();
    if(temp->data != '#') {
      cout << temp->data << " " << temp->weight << " " << temp->hafmCode << endl;
    }
    q.pop();
    if (root->rc) {
      root->rc->hafmCode += "1";
      q.push(root->rc);
    }
    if (root->lc) {
      root->lc->hafmCode += "0";
      q.push(root->lc);
    }
  }
  return 0;
}
