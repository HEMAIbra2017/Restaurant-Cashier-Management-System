#include<iostream>
#include<string>
#include<array>
#include<fstream>
using namespace std;

class Node
{
	friend class List;
public:
	int Num;
	string Species;
	string Price;
    Node *link;
public:
    Node();
    Node(int Num,string Species,string Price, Node *n);
};
Node::Node()
{
}
Node::Node(int Num,string Species,string Price, Node *n)
{
    Num=Num;
    Species=Species;
    Price=Price;
    n=link;
}

class List
{

    Node *first;

	public:
	List();
	~List();
	bool IsEmpty();
	int Length();
	void Insert(int position, int Num,string Species,string Price);
	void Delete(int position, int &item);
	void Update(int position,int Num,string Species,string Price);

	int get(int position);
	string getPrice(int position);

	void Output();
	//void OutputNode(int position);
	void apply_changes(string SetMenu)
	{
		Node *ptr= first;
		if(SetMenu=="Sandwitches")
		{
			ofstream myfile;
			myfile.open("Sandwitches.txt");
			while(ptr != NULL)
			{
				myfile <<ptr->Num<<"|"<<ptr->Species<<"|"<<ptr->Price<<"\n";
				ptr=ptr->link;
			}
			myfile.close();
		}
		if(SetMenu=="Soft Drinks")
		{
			ofstream myfile;
			myfile.open("Soft Drinks.txt");
			while(ptr != NULL)
			{
				myfile <<ptr->Num<<"|"<<ptr->Species<<"|"<<ptr->Price<<"\n";
				ptr=ptr->link;
			}
			myfile.close();
		}
		if(SetMenu=="Appetizers")
		{
			ofstream myfile;
			myfile.open("Appetizers.txt");
			while(ptr != NULL)
			{
				myfile <<ptr->Num<<"|"<<ptr->Species<<"|"<<ptr->Price<<"\n";
				ptr=ptr->link;
			}
			myfile.close();
		}
	}
};

List::List()
{
	first=0;
}
List::~List()
{
	Node *next;
	while(first)
	{
	 next = first->link;
	 delete first;
	 first = next;
	}
}

bool List::IsEmpty()
{
	return (first==0);
}

int List::Length()
{
	Node *current = first;
	int len = 0;
	while (current)
	{
	 len++;
	 current = current -> link;
	}
	return len;
}

void List::Insert(int position, int Num,string Species,string Price) // insert item in the following position
{
	//Insert x after the k'th element.
	if(position<1)
	{
		cout <<"\n OutOfBounds\n";
		return;
	}

	//insert
	Node *newNode = new Node();
	newNode->Num = Num;
	newNode->Species=Species;
	newNode->Price=Price;
	if(position>1)//insert after current
	{
		Node * current= first;

		for(int i = 1;i<position-1 && current ;i++)
		current= current->link;

		newNode->link = current->link;
		current->link = newNode;
	}
	else//insert as first element
	{
	 newNode->link = first;
	 first = newNode;
	}
}


void List::Delete(int position, int &item) // delete item and return the deleted item   by reference
{

	if(position<1)
	{
		cout <<"\n OutOfBounds\n";
		return;
	}

	Node *current= first;
	if(position >1)//delete from position
	{
		for(int i =1;i<position-1&& current; i++)
			current = current->link;

		Node *temp=current->link;
		current->link=temp->link;
		item =temp->Num;
		delete temp;
	}
	else//delete from first
	{

	 item=first->Num;
	 first = first->link;

	}
}


void List::Update(int position,int Num,string Species,string Price)
{
    	Node * current= first;
    	for(int i = 1;i<position && current ;i++)
		current= current->link;
		current->Num=Num;
		current->Species=Species;
		current->Price=Price;
}

int List::get(int position) // get the value in the following position
{
	Node * current= first;

	for(int i = 1;i<position && current ;i++)
		current= current->link;

	return current->Num;
}
string List::getPrice(int position)
{
		Node * current= first;

	for(int i = 1;i<position && current ;i++)
		current= current->link;

	return current->Price;
}
void List::Output()    //print linked list
{
	Node *current = first;
	cout<<"ID	Species					Price"<<endl;
	cout<<"------------------------------------------------------------------"<<endl;
	while (current)
	{

		cout<<current->Num<<'\t';
		cout<<current->Species<<'\t'<<'\t'<<'\t'<<'\t'<<'\t';
		cout<<current->Price<<'\t';
		cout<<endl;
	    current = current -> link;
	}
	cout<<"------------------------------------------------------------------"<<endl;
}

//void List::OutputNode(int position)    //print linked list
//{
//	Node *current = first;
//	cout<<"ID	Species				Price"<<endl;
//	cout<<"------------------------------------------------------------------"<<endl;
//	for(int i = 1;i<position && current ;i++)
//		current= current->link;
//
//		cout<<current->Num<<'\t';
//		cout<<current->Species<<'\t'<<'\t'<<'\t'<<'\t'<<'\t';
//		cout<<current->Price<<'\t';
//		cout<<endl;
//	    current = current -> link;
//	cout<<"------------------------------------------------------------------"<<endl;
//}





