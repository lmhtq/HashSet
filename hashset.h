#define LEN 10
struct Node
{
	int data;		//element
	Node *next;		//next element
};

class HashSet
{
	public :
		HashSet();						//constructor
		HashSet(int len);				//constructor 
		~HashSet();						//deconstructor 
		void add(int data);				//add data in increasing order
		void del(int data);				//delete data
		void clear();					//clear all the elements
		bool empty();					//whether the set is empty
		bool hasdata(int data);			//whether has the data or not
		bool equal(HashSet &A);			//whether equal to HashSet A
		void Union(HashSet &A);			//Union Set
		void Insect(HashSet &A);		//Insect Set
		void Diff(HashSet &A);			//Diff Set
		bool IsChildOf(HashSet &A);		//Child Set
		bool IsSuperOf(HashSet &A);		//Super Set
		void copy(HashSet &A);			//copy from HashSet A
		void output();					//printf elements
		void output2();					//printf elements
		int size;						//the length of list
		Node **head;					//
	protected :
		// to be add code
	private :
		// to be add code
};


HashSet::HashSet()						//constructor
{
	size = LEN;				//the default length is LEN:10
	head = new Node *[size];			//malloc
	for (int i = 0; i < size; i++)
	{
		head[i] = new Node;				//init
		head[i] -> next = NULL;			//head node
	}
}

HashSet::HashSet(int len)	//constructor
{
	if (LEN > len)
		size = LEN; //the length is at least 100
	else
		size = len;
	head = new Node *[size];		//malloc
	for (int i = 0; i < size; i++)
	{
		head[i] = new Node;			//init
		head[i] -> next = NULL;		//head node
	}
}

HashSet::~HashSet()		//deconstructor
{
	Node *p;
	Node *q;
	for (int i = 0; i < size; i++)	//scan
	{
		p = head[i] -> next;
		if (NULL == p)
			continue;
		q = p -> next;
		while (NULL != q)
		{
			delete p;				//free the node with next isn't empty
			p = q;
			q = p -> next;
		}
		delete p;					//free the last one
	}
	delete [] head;					//free the Head
}

void HashSet::add(int data)		//insert a data
{
	int it = data % size;		//index
	Node* p = head[it];
	while (p -> next && p -> next -> data < data)
	{
		p = p -> next;			//find insert position
	}
	if (p -> next && data == p -> next -> data)
		return;
	Node *q = new Node;
	q -> data = data;			//insert data
	q -> next = p -> next;
	p -> next = q;
}

void HashSet::del(int data)		//delete a data
{
	int it = data % size;		//index
	Node *p = head[it];
	if (NULL == p -> next)		//return when empty
		return;
	Node *q = p -> next;
	while (q -> data != data && q -> next != NULL)
	{
		p = q;
		q = q -> next;			//find delete position
	}
	if (q -> next == NULL && q -> data != data)		//the data isn't in the Hashset
	{
		return;
	}
	//q's position is to be delete
	p -> next = q -> next;
	delete q;
}

void HashSet::clear()				//clear all the elements
{
	Node *p;
	Node *q;
	for (int i = 0; i < size; i++)	//scan
	{
		p = head[i] -> next;
		if (NULL == p)
			continue;
		q = p -> next;
		while (NULL != q)
		{
			delete p;				//free the node with next isn't empty
			p = q;
			q = p -> next;
		}
		delete p;					//free the last one
	}	
	for (int i = 0; i < size; i++)	//scan
		head[i] -> next = NULL;
}

bool HashSet::empty()				//whether the set is empty
{
	for (int i = 0; i < size; i++)
	{
		if (head[i] -> next != NULL)
			return false;
	}
	return true;
}

bool HashSet::hasdata(int data)		//whether has the data or not
{
	int it = data % size;
	Node *p = head[it];
	while (p -> next && p -> next -> data <= data)
		p = p -> next;
	//p->next point to the little bigger data or NULL
	if (p -> next == NULL)
	{
		if (p -> data == data)
			return true;
		else
			return false;
	}
	else if (p -> data == data)
		return true;
	else
		return false;
}

void HashSet::copy(HashSet &A)		//copy from HashSet A
{
	this -> size = A.size;
	Node *p;
	for (int i = 0; i < size; i++)	//scan
	{
		p = A.head[i] -> next;
		if (NULL == p)
			continue;
		while (p)
		{
			this -> add(p -> data);
			p = p -> next;
		}
	}
}

bool HashSet::equal(HashSet &A)
{
	HashSet tA;
	tA.size = size;
	Node *p;
	for (int i = 0; i < A.size; i++)	//scan
	{
		p = A.head[i] -> next;
		if (NULL == p)
			continue;
		while (p)
		{
			tA.add(p -> data);
			p = p -> next;
		}
	}
	
	Node *q;
	for (int i = 0; i < size; i++)		//scan
	{
		p = head[i] -> next;
		q = tA.head[i] -> next;
		if (p == NULL && q == NULL)
			continue;
		else if (p == NULL && q != NULL)
			return false;
		else if (p != NULL && q == NULL)
			return false;
		while (p && q)
		{
			if (p -> data != q -> data)
				return false;
			else
			{
				p = p -> next;
				q = q -> next;
			}
		}
	}
	
	return true;
}

void HashSet::Union(HashSet &A)			//Union Set
{
	Node *p;
	for (int i = 0; i < A.size; i++)	//scan
	{
		p = A.head[i] -> next;
		if (NULL == p)					//skip empty ones
			continue;
		while (p)
		{
			add(p -> data);				//merge
			p = p -> next;
		}
	}
}

void HashSet::Insect(HashSet &A)		//Insect Set
{
	Node *p;
	for (int i = 0; i < size; i++)		//scan
	{
		p = head[i] -> next;
		if (NULL == p)					//skip empty ones
			continue;
		while (p)
		{
			if (A.hasdata(p -> data) == false)
				del(p -> data);			//delete the ones are not in A
			p = p -> next;
		}
	}
}

void HashSet::Diff(HashSet &A)			//Diff Set
{
	Node *p;
	for (int i = 0; i < A.size; i++)	//scan
	{
		p = A.head[i] -> next;
		if (NULL == p)					//skip empty ones
			continue;
		while (p)
		{
			del(p -> data);				//delete the ones in A
			p = p -> next;
		}
	}
}

bool HashSet::IsChildOf(HashSet &A)		//Child Set
{
	Node *p;
	for (int i = 0; i < size; i++)		//scan
	{
		p = head[i] -> next;
		if (NULL == p)					//skip empty ones
			continue;
		while (p)
		{
			if(A.hasdata(p -> data) == false)
				return false;			//false when A doesn't constains the data
			p = p -> next;
		}
	}
	return true;
}

bool HashSet::IsSuperOf(HashSet &A)		//Super Set
{
	Node *p;
	for (int i = 0; i < A.size; i++)	//scan
	{
		p = A.head[i] -> next;
		if (NULL == p)					//skip empty ones
			continue;
		while (p)
		{
			if(hasdata(p -> data) == false)				
				return false;			//false when this set doesn't contains the data
			p = p -> next;
		}
	}
	return true;
}

void HashSet::output()					//output the elements
{
	Node *p;
	for (int i = 0; i < size; i++)		//scan
	{
		p = head[i] -> next;
		if (NULL == p)					//skip empty ones
			continue;
		cout << "Index " << i << ":";
		while (p)
		{
			cout << " " << p -> data;
			p = p -> next;
		}
		cout << endl;
	}
}

void HashSet::output2()					//output the elements
{
	Node *p;
	for (int i = 0; i < size; i++)		//scan
	{
		p = head[i] -> next;
		if (NULL == p)					//skip empty ones
			continue;
		while (p)
		{
			cout << " " << p -> data;
			p = p -> next;
		}
	}
	cout << endl;
}

