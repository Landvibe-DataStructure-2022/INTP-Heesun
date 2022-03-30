#include<iostream>
using namespace std;


struct node
{
	int data;
	node* next;
};

class listQueue
{
public:
	listQueue();
	bool empty();
	int size();
	int front();
	int rear();
	void enqueue(int data);
	void dequeue();
private:
	node* frontNode;
	node* rearNode;
	int n;
};

listQueue::listQueue()
{
	frontNode = NULL;
	rearNode = NULL;
	n = 0;
}

bool listQueue::empty()
{
	return (n == 0);
}
int listQueue::size()
{
	return n;
}
int listQueue::front()
{
	if (empty())
	{
		return -1;
	}
	return frontNode->data;
}
int listQueue::rear()
{
	if (empty())
	{
		return -1;
	}
	return rearNode->data;
}
void listQueue::enqueue(int data)
{
	node* newNode = new node;
	newNode->data = data;
	newNode->next = NULL;
	if (empty())
	{
		frontNode = rearNode = newNode;
	}
	else
	{
		rearNode->next = newNode;
		rearNode = newNode;
	}

	n++;
}

void listQueue::dequeue()
{
	if (empty())
	{
		cout << "Empty" << '\n';
		return;
	}
	cout << front() << '\n';
	node* curNode = frontNode;
	if (size() == 1)
	{
		frontNode = rearNode = NULL;
	}
	else
	{
		frontNode = frontNode->next;
	}
	delete curNode;
	n--;
}


int main() 
{
	int cnt;
	cin >> cnt;
	listQueue list;

	for (int i = 0; i < cnt; i++)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "size") 
		{
			cout << list.size() << '\n';
		}
		else if (cmd == "isEmpty")
		{
			if (list.empty() == 1)
			{
				cout << "True" << '\n';
			}
			else
			{
				cout << "False" << '\n';
			}
		}
		else if (cmd == "front") 
		{
			if (list.rear() == -1)
			{
				cout << "Empty" << '\n';
			}
			else
			{
				cout << list.front() << '\n';
			}
		}
		else if (cmd == "rear") 
		{
			if (list.rear() == -1)
			{
				cout << "Empty" << '\n';
			}
			else
			{
				cout << list.rear() << '\n';
			}
			
		}
		else if (cmd == "enqueue") 
{
			int k;
			cin >> k;
			list.enqueue(k);
		}
		else if (cmd == "dequeue") 
		{
			list.dequeue();
		}
		
		
	}

}