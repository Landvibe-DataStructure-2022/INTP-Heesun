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
		return 0;
	}
	return frontNode->data;
}
int listQueue::rear()
{
	if (empty())
	{
		return 0;
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
	int t;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		int sum1 = 0, sum2 = 0;
		int p1 = 0, p2 = 0;
		listQueue list1;
		listQueue list2;
		for (int j = 0; j < n; j++)
		{
			int k;
			cin >> k;
			list1.enqueue(k);
		}
		for (int j = 0; j < n; j++)
		{
			int k;
			cin >> k;
			list2.enqueue(k);
		}
		for (int j = 0; j < n; j++)
		{
			if ((list1.front()+sum1) > (list2.front()+sum2))
			{
				sum1 = (list1.front() + sum1) - (list2.front() + sum2);
				sum2 = 0;
				p1++;

			}
			else if ((list1.front() + sum1) == (list2.front() + sum2))
			{
				sum1 = sum2 = 0;
			}
			else if((list1.front() + sum1) < (list2.front() + sum2))
			{
				sum2 = (list2.front() + sum2) - (list1.front() + sum1);
				sum1 = 0;
				p2++;
			}
			
			list1.dequeue();
			list2.dequeue();
			cout << "Round" << j + 1 << " " << p1 << ":" << p2<<'\n';
		}
		if (p1 > p2)
		{
			cout << "Winner P1" << endl;
		}
		else if (p2 > p1)
		{
			cout << "Winner P2" << endl;
		}
		else
		{
			cout << "Draw" << endl;
		}
		
	}
	

}