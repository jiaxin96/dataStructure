void List::insert(int toadd, int pos) {
	ListNode *ht = head;

	for (int i = 0; i < pos - 1; ++i)
	{
		ht = ht->next;
	}
	ListNode *pos =ht->next;
	ListNode *now = new ListNode;
	now->data = toadd;
	now->next = pos;
	ht->next = now;
}