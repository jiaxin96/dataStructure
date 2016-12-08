#include <cstdio>

using namespace std;

struct node {
    int v;
    node * l;
    node * r;
    node(int vv, node * ll = NULL, node * rr = NULL) :
        v(vv), l(ll), r(rr) {}
};

void trv(node *root) {
    if (root == NULL) return;
    printf("%d", root->v);
    trv(root->l);
    trv(root->r);
}
void clear(node *root) {
    if (!root) return;
    if(root->l) clear(root->l);
    if(root->r) clear(root->r);
    delete root;
}
void insert(node *& root, int val) {
    if (root == NULL) {
        root = new node(val);
        return;
    }
    if (val > root->v) {
        insert(root->r, val);
    } else if (val < root->v) {
        insert(root->l, val);
    }
}
int TreeHeight(node * root)
{
    int i,j;
    if( !root )
        return 0;
    else
    {
        i = TreeHeight(root->l);
        j = TreeHeight(root->r);
        if( i >= j )
            return i+1;
        else
            return j+1;
    }
}
void reFact(node &*  root) {
    if (!root) return;
    int lh = TreeHeight(root->l);
    int rh = TreeHeight(root->r);
}
int main() {
    int t = 0;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d",&n);
        node *root = NULL;
        for (int i = 0; i < n; ++i) {
            int temp;
            scanf("%d", &temp);
            if (root == NULL) {
                root = new node(temp);
            } else {
                insert(root, temp);
            }
            reFact(root);
        }
        trv(root);
        clear(root);
        printf("\n");
    }
    return 0;
}
