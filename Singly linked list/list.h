// list.h -- ���������� ������ List - ������������ ������
#ifndef LIST_H_
#define LIST_H_

template<class T>
class List
{
public:
	List();
	~List();
	void push_back(T data);
	int getSize() const { return Size; }
	T& operator[](int index);			// ������ �������� �� �������
										// ������������ ��� - ������, ��� ��������� �-�����
	void pop_front();
	void clear();
private:
	// ��������� ���� Node, ������ ��� List
	template<class T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		// ������������� �����������
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data; 
			this->pNext = pNext;
		}
	};
	// ������ ������ (��������� Node)
	Node<T>* head;
	int Size;
};

// ���������� �������

template<class T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}
template<class T>
List<T>::~List()
{
	clear();
}

template<class T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}

	Size++;
}

template <class T>
T& List<T>::operator[](int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template <class T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template <class T>
void List<T>::clear()
{
	while (Size)
	{
		this->pop_front();
	}
}
#endif // !LIST_H_