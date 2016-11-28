#include <iostream>
#include <cstdio>
#include <map>
struct node
{
	int id;
	char data;
	int lid;
	int rid;
	node *l;
	node *r;
	node(int i = 0, char d = 0, int l= 0, int r = 0, node * tl = NULL, node * tr = NULL) :
	id(i), data(d), lid(l), rid(r) , l(tl), r(tr){}
};

void destory(node * root) {
	if (!root) return;
	if (root->l) destory(root->l);
	if (root->r) destory(root->r);
	delete root;
}

void trv(node * root) {
	if (root) {
		printf("%c", root->data);
	} else {
		return;
	}
	if (root->l) trv(root->l);
	if (root->r) trv(root->r);
}

int main()
{
	int t;
	while(scanf("%d", &t) != EOF) {
		std::map<int, node*> m;
		while(t--) {
			int tId;
			char tData;
			int tLid;
			int tRid;
			std::cin >> tId >> tData >> tLid >> tRid;
			node *temp = new node(tId, tData, tLid, tRid);
			m[tId] = temp;
		}
		while(m.size() != 1) {
			std::map<int, node*>::iterator it = m.begin();
			while (it->second->rid == 0 && it->second->lid == 0) ++it;
			if (it->second->lid) {
				std::map<int, node*>::iterator t = m.find(it->second->lid);
				it->second->l = t->second;
				m.erase(t);
			}
			if (it->second->rid) {
				std::map<int, node*>::iterator t = m.find(it->second->rid);
				it->second->r = t->second;
				m.erase(t);
			}
		}
		node *root = m[m.begin()->first];
		trv(root);
		printf("\n");
		destory(root);
	}
	return 0;
}