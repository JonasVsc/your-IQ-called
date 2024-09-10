// P.S. This file will be refactored.

#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;

	node() :data(0) {next=nullptr;}
	node(int v) :data(v) {next=nullptr;}
};



class LinkedList
{
public:
	LinkedList() :head(new node) {}
	LinkedList(int v) :head(new node(v)) {}

	void display();
	void insert(int index, int v);
	void remove(int index);

	node* get(int index);
	node* search(int v);

	// optimized linear search
	node* search_transpose(int v);
	node* search_mv_head(int v);

	int nodes();
	int sum();
	node* max();
	node* min();


private:
	node* head;
};


int main()
{
	LinkedList list(120);
	list.insert(0, 23);
	list.insert(0, 26);
	list.insert(0, 28);
	list.insert(0, 1);
	list.insert(0, 33);
	cout << "======= DISPLAY =======" << '\n';
	list.display();
	cout << endl;

	cout << "======= SEARCH =======" << '\n';
	node* res = list.search_mv_head(120);
	if(res != nullptr)
		cout << res->data << " found!" << '\n';
	else
		cout << "not found!" << '\n';

	cout << "======= DISPLAY =======" << '\n';
	list.display();
	cout << '\n';
	cout << "removing!" << '\n';
	list.remove(3);

	cout << "======= DISPLAY =======" << '\n';
	list.display();
	cout << '\n';
	

	cout << "======= GET =======" << '\n';
	node* get = list.get(2);
	if(get != nullptr)
		cout << get->data << " get!" << '\n';
	else
		cout << "nullptr!" << '\n';


	cout << "======= INFO =======" << '\n';
	cout << "nodes: " << list.nodes() << '\n';
	cout << "sum of nodes: " << list.sum() << '\n';
	cout << "min value: " << list.min()->data << '\n';
	cout << "max value: " << list.max()->data << '\n';
	cout << endl;

	return 0;
}


void LinkedList::display()
{
	node* temp = head;

	while(temp != nullptr)
	{
		cout << temp->data << ' ';
		temp = temp->next;
	}
}

void LinkedList::insert(int index, int v)
{
	int i {};
	node* temp = head;
	if(index == 0)
	{
		node* new_node = new node(v);
		new_node->next = head;	
		head = new_node;
		return;
	}

	while(temp->next != nullptr && i < index - 1)
	{
		i++;
		temp = temp->next;
	}

	node* new_node = new node(v);
	new_node->next = temp->next;	
	temp->next = new_node;
}

void LinkedList::remove(int index)
{
	if(index == 0)
	{
		head = head->next;
		delete head;
		return;
	}

	node *p, *q;
	q = p = head;
	int i {};

	while(p != nullptr && i < index)
	{
		i++;
		q = p;
		p = p->next;
	}

	q->next = p->next;
	delete p;
}

node* LinkedList::get(int index)
{
	int i {};
	node* temp = head;
	while(temp->next != nullptr && i < index)
	{	
		i++;
		temp = temp->next;
	}
	if(i == index)
		return temp;
	return nullptr;
}

node* LinkedList::search(int v)
{
	node* temp = head;

	while(temp != nullptr)
	{
		if(temp->data == v)
			return temp;
		temp = temp->next;
	}
	return nullptr;
}

// optimized search
node* LinkedList::search_transpose(int v)
{
	if(head->data == v)
		return head;
	node *p, *q, *k;
	k = p = q = head;
	while(p != nullptr)
	{
		if(p->data == v)
		{
			if(k == q)
			{
				head->next = p->next;
				p->next = head;
				head = p;
				return p;
			}
			k->next = p;
			q->next = p->next;
			p->next = q;
			return p;
		}
		k = q;
		q = p;
		p = p->next;
	}
	return nullptr;
}

node* LinkedList::search_mv_head(int v)
{
	if(head->data == v)
		return head;

	node *p, *q;
	q = p = head;
	while(p != nullptr)
	{
		if(p->data == v)
		{
			q->next = p->next;
			p->next = head;
			head = p;
			return p;
		}
		q = p;
		p = p->next;
	}
	return nullptr;
}



int LinkedList::nodes()
{
	int count {};
	node* temp = head;
	while(temp != nullptr)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

int LinkedList::sum()
{
	int sum {};
	node* temp = head;
	while(temp != nullptr)
	{
		sum += temp->data;
		temp = temp->next;
	}
	return sum;
}

node* LinkedList::max()
{
	node *max, *temp;
	max = temp = head;
	while(temp != nullptr)
	{
		if(max->data < temp->data)
			max = temp;
		temp = temp->next;
	}
	return max;
}

node* LinkedList::min()
{
	node *min, *temp;
	min = temp = head;
	while(temp != nullptr)
	{
		if(min->data > temp->data)
			min = temp;
		temp = temp->next;
	}
	return min;
}



