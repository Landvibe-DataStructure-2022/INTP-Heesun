#include<iostream>
using namespace std;

// 배열 이용 스택
class arrayStack
{
public:
	arrayStack(int capacity);
	bool empty();
	int top();
	void push(int data);
	void pop();

private:
	int* arr; // 스택원소 저장
	int capacity; // 스택 최대 크기 저장
	int topIndex; // 배열에서 스택의 topㅣ 저장되어 있는 인덱스 저장
};

arrayStack::arrayStack(int capacity)
{
	this->capacity = capacity;
	arr = new int[capacity];
	topIndex = -1;
}

bool arrayStack::empty()
{
	if (topIndex == -1)
		return 1;
	else
		return 0;
}

int arrayStack::top()
{
	if (empty())
		return -1;
	return arr[topIndex];
}

void arrayStack::push(int data)
{
	if (size() == capacity)
		cout << "FULL" << '\n';
	else
		arr[++topIndex] = data;
}

void arrayStack::pop()
{
	if (empty())
	{
		cout << "-1" << '\n';
	}
	else
	{
		cout << arr[topIndex] << '\n';
		topIndex--;
	}

}


int main()
{
	int t, n;
	cin >> t >> n;
	arrayStack arraystack(t);

	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;

		if (cmd == "empty") {
			cout << arraystack.empty() << '\n';
		}
		else if (cmd == "top") {
			cout << arraystack.top() << '\n';
		}
		else if (cmd == "push") {
			int x;
			cin >> x;
			arraystack.push(x);
		}
		else if (cmd == "pop") {
			arraystack.pop();
		}
	}

	return 0;
}