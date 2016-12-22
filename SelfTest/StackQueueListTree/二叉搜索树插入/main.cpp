#include <iostream>

using namespace std;
struct BiNode {
	int Key;
	BiNode *LChild, *RChild;
};

class BSTree {
public:
	BSTree() {
		Root = NULL;
	}
	bool Insert(const int &key);
private:
	bool Insert(BiNode* &root, const int &key);
	BiNode *Root;
};

bool BSTree::Insert(const int &key)
{
	return Insert(Root, key);
}
bool BSTree::Insert(BiNode* & root, const int &key)
{
	if (root == NULL) {
		BiNode *Pt = new BiNode;
		if (Pt == NULL) return false;
		Pt->Key = key;
		Pt->LChild = Pt->RChild = NULL;
		root = Pt;
		return true;
	}
	if (key == root->Key) return false;
	if (key < root->Key) return Insert(root->LChild, key);
	return Insert(root->RChild, key);
}



int main(int argc, char const *argv[])
{
	BSTree b;
	int a[] = {5,6,4,3,1};
	b.Insert(a[0]);
	b.Insert(a[1]);
	b.Insert(a[2]);
	b.Insert(a[3]);
	b.Insert(a[4]);
	// free tree
	return 0;
}