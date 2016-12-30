 template <typename E>
class LinkedList
{
private:
 
  // inner class: linked-list node
  class Node
  {
  public:
    E data;
    Node * next;
  };
 
  Node * first;
 
public:
  LinkedList() {
    first = 0;
  }
 LinkedList(const LinkedList & that);
  ~LinkedList() {
    while (first != 0) {
      removeFirst();
    }
  }
  LinkedList<E> & operator= (const LinkedList & that);
 void removeFirst();
  E getFirst() {
    return first->data;
  }
 
  bool isEmpty() {
    return first == 0;
  }
  void addFirst(E data);
};
template<typename E>
LinkedList<E>::LinkedList(const LinkedList & that) {
  	if (!that.first) {
  		first = 0;
  		return;
  	}
  	first = new Node;
  	first->data = that.first->data;
  	Node * otH = that.first;
  	Node * myH = first;
  	while (otH->next) {
  		otH = otH->next;
  		myH->next = new Node;
  		myH->next->data = otH->data;
  		myH = myH->next;
  	}
  	myH->next = 0;
}
template <typename E>
LinkedList<E> & LinkedList<E>::operator= (const LinkedList & that) {
 	Node * tH = first;
 	Node * pre = tH->next;
    while (first != 0) {
      removeFirst();
    }

   	if (!that.first) {
  		first = 0;
  		return *this;
  	}


  	first = new Node;
  	first->data = that.first->data;
  	Node * otH = that.first;
  	Node * myH = first;
  	while (otH->next) {
  		otH = otH->next;
  		myH->next = new Node;
  		myH->next->data = otH->data;
  		myH = myH->next;
  	}
  	myH->next = 0;
  	return *this;
 }
template<typename E>
void LinkedList<E>::removeFirst() {
 	if (!first) return;
 	Node * th = first->next;
 	delete first;
 	first = th;
  }
template<typename E>
void LinkedList<E>::addFirst(E data) {
 	if (!first) {
 		first = new Node;
 		first->data = data;
 		first->next = 0;
 		return;
 	}
 	Node *th = new Node;
 	th->data =data;
 	th->next = first;
 	first = th;
 }

 int main(int argc, char const *argv[])
 {
 	LinkedList<int> a;
 	LinkedList<int> b = a;
 	a.addFirst(1);
 	a.addFirst(2);
 	a.removeFirst();
 	a.removeFirst();

 	return 0;
 }