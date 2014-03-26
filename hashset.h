#define LEN 10
struct Node
{
	int data;		//element
	Node *next;		//next element
};

class HashSet
{
	public :
		HashSet();					//constructor
		HashSet(int len = LEN);		//constructor 
		~HashSet();						//deconstructor 
		void add(int data);				//add data
		void del(int data);				//delete data
		void output();					//printf elements
	protected :
		// to be add code
	private :
		int size;			//the length of list
		Node **head;		//
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
	while (p -> next && p -> data != data)
	{
		p = p -> next;			//find insert position
	}
	if (data == p -> data)
		return;
	Node *q = new Node;
	q -> data = data;			//insert data
	q -> next = NULL;
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

void HashSet::output()				//output the elements
{
	Node *p;
	for (int i = 0; i < size; i++)	//scan
	{
		p = head[i] -> next;
		if (NULL == p)				//skip empty ones
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

