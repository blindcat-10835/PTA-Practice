List Reverse(List L)
{
	List r1, r2 = NULL;
	r1 = L;
	while (r1)
	{
		L = r2;
		r2 = r1;
		r1 = r1->Next;
		r2->Next = L;
	}
	L = r2;
	return L;
}