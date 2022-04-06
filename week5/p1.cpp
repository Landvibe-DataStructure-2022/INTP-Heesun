#include<iostream>
using namespace std;

// vector sequence
// erase가 틀린 것 같은데 보기가 틀린 느낌?ㅇㅁㅇ 모르겠습니다,,
class arrayVector
{
public:
	arrayVector();
	bool empty();
	int size();
	int at(int idx);
	void set(int idx, int data);
	void erase(int idx);
	void insert(int idx, int data);
private:
	int capacity;
	int n;
	int* arr;
	void reserve(int size);
};

arrayVector::arrayVector()
{
	capacity = 1;
	n = 0;
	arr = NULL;
}

bool arrayVector::empty()
{
	return (n == 0);
}

int arrayVector::size()
{
	return n;
}

int arrayVector::at(int idx)
{
	if (idx < 0 || n <= idx)
	{
		return -1;
	}
	return arr[idx];
}

void arrayVector::set(int idx, int data)
{
	if (idx < 0 || n <= idx)
	{
		return;
	}
	arr[idx] = data;
}

void arrayVector::erase(int idx)
{
	if (idx < 0 || n <= idx)
	{
		return;
	}
	for (int i = idx + 1; i < n; i++)
	{
		arr[i - 1] = arr[i];
	}
	n--;
}
void arrayVector::insert(int idx, int data)
{
	if (idx < 0 || n <= idx)
	{
		return;
	}
	if (n == capacity)
	{
		reserve(2 * capacity);
	}
	for (int i = n - 1; i >= idx; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[idx] = data;
	n++;
}

void arrayVector::reserve(int size)
{
	if (size <= capacity)
	{
		return;
	}
	int* arrTemp = new int[size];
	for (int i = 0; i < n; i++)
	{
		arrTemp[i] = arr[i];
	}

	if (arr != NULL)
	{
		delete[] arr;
	}
	arr = arrTemp;
	capacity = size;
}


// listsequence

struct node 
{
	int data;
	node* prev;
	node* next;
};

class nodeList
{
public:
	nodeList();
	bool empty();
	int size();
	node* begin();
	node* end();
	void insert(node* pos, int data);
	void erase(node* pos);
	void nextP(node* pos);
	void prevP(node* pos);
	void print();
	void find(int data);

private:
	node* header;
	node* trailer;
	int n;
};

nodeList::nodeList()
{
	header = new node();
	trailer = new node();
	header->next = trailer;
	trailer->prev = header;
	header->prev = trailer->next = NULL;
	n = 0;
}

bool nodeList::empty()
{
	return (n == 0);
}

int nodeList::size()
{
	return n;
}
node* nodeList::begin()
{
	return header->next;
}
node* nodeList::end()
{
	return trailer;
}

void nodeList::insert(node* pos, int data)
{
	
	node* newNode = new node();
	newNode->data = data;
	newNode->prev = pos->prev;
	newNode->next = pos;
	pos->prev->next = newNode;
	pos->prev = newNode;
	n++;
}


void nodeList::erase(node* pos)
{
	if (pos == trailer)
	{
		return;
	}
	else if (empty())
	{
		cout << "Empty" << '\n';
		return;
	}
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	delete pos;
	n--;
}


void nodeList::nextP(node* p)
{
	if (p != trailer)
		p = p->next;
}
void nodeList::prevP(node* p)
{
	if (p != header)
		p = p->prev;
}
void nodeList::print()
{
	if (empty())
	{
		cout << "Empty" << '\n';
		return;
	}
	node* k;
	k = header->next;
	while (k != trailer)
	{
		cout << k->data << " ";
		k = k->next;
	}
	cout << '\n';
}
void nodeList::find(int find)
{
	node* k;
	bool use = 0;
	int cnt=0;
	k = header->next;
	while (k != trailer)
	{
		if (find == k->data)
		{
			cout << cnt << " ";
			use = 1;
			break;
		}
		
		k = k->next;
		cnt++;
	}
	if (use == 0)
	{
		cout << "-1";
	}
	cout << '\n';
}

int main()
{
	nodeList list;
	node* p = list. begin();

	int n;
	cin >> n;

	while (n--)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "begin")
		{
			p = list.begin();
		}
		else if (cmd == "end")
		{
			p = list.end();
		}
		else if (cmd == "insert")
		{
			int data;
			cin >> data;
			list.insert(p , data);
		
			
		}
		else if (cmd == "erase")
		{
			list.erase(p);
			p = list.begin();
		}
		else if (cmd =="nextP")
		{
			list.nextP(p);
		}
		else if (cmd == "prevP")
		{
			list.prevP(p);
		}
		else if (cmd == "print")
		{
			list.print();
		}
		else if (cmd == "find")
		{
			int data;
			cin >> data;
			list.find(data);
		}
		
	}
	
	
}