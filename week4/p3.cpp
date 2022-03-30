#include<iostream>
using namespace std;


class arrayQueue
{
public:
	arrayQueue(int capacity);
	bool empty();
	int size();
	void front();
	void rear();
	void enqueue(int data);
	void dequeue();

private:
	int* arr;
	int capacity;
	int frontIndex;
	int rearIndex;
	int n;

};

arrayQueue::arrayQueue(int capacity)
{
	this->capacity = capacity;
	arr = new int[capacity];
	frontIndex = rearIndex = 0;
	n = 0;
};

bool arrayQueue::empty()
{
	return (n == 0);
}

int arrayQueue::size()
{
	return n;
}
void arrayQueue::front()
{
	if (empty())
	{
		cout << "Empty" << '\n';
		return;
	}
	cout << arr[frontIndex] << '\n';
}
void arrayQueue::rear()
{
	if (empty())
	{
		cout << "Empty" << '\n';
		return;
	}
	cout << arr[rearIndex-1] << '\n';
}
void arrayQueue::enqueue(int data)
{
	if (size() == capacity)
	{
		cout << "Full" << '\n';
		return;
	}
	
		arr[rearIndex] = data;
		rearIndex = (rearIndex + 1) % capacity;
		n++;
	
	
}
void arrayQueue::dequeue()
{
	if (empty())
	{
		cout << "Empty" << '\n';
		return;
	}
	
		front();
		frontIndex = (frontIndex + 1) % capacity;
		n--;
	
	
}


int main() 
{
	int n, t;
	cin >> n >> t;
	arrayQueue arr(n);

	for (int i = 0; i < t; i++)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "enqueue") {
			int k;
			cin >> k;
			arr.enqueue(k);
		}
		else if (cmd == "dequeue") {
			arr.dequeue();
		}
		else if (cmd == "isEmpty") {
			if (arr.empty() == 1)
			{
				cout << "True" << '\n';
			}
			else
			{
				cout << "False" << '\n';
			}
		}
		else if (cmd == "size") {
			cout << arr.size() << '\n';
		}
		else if (cmd == "front") {
			arr.front();
		}
		else if (cmd == "rear") {
			arr.rear();
		}
	}

}