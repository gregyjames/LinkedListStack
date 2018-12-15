/*
	Author: Greg James
	Date: 12/13/2018
	Title: Stack using LinkedList
*/
#include<iostream>
using namespace std;

//Generic Template for the Node struct
template <typename T>
struct node
{
	T data;
	struct node<T> *next;
};

//Generic Template for the class Struct
template <typename T>
class stack
{
	node<T> *top;
	node<T> *tail;
public:
	stack() // constructor
	{
		top = NULL;
	}
	void push(); // to insert an element
	void pop();  // to delete an element
	void show(); // to show the contents stack
};

// Implementation of the push Operation
template <typename T>
void stack<T>::push()
{
	//The value to insert and the pointer to the new node
	T value;
	node<T> *ptr;

	//Get the value to insert
	cout << "\nPUSH";
	cout << "Enter a value add to stack: ";
	cin >> value;
	
	//Create the new node for the new value
	ptr = new node<T>;
	ptr->data = value;
	ptr->next = NULL;
	
	//Appends the current top to the next of the new node
	//Adds the new node to the top
	if (top != NULL)
		ptr->next = top;
	top = ptr;
	cout << "\nItem was inserted successfully!";

}

// POP Operation
template <typename T>
void stack<T>::pop()
{
	//The temp node to hold the old head
	node<T> *temp;

	//Checks that the stack is not empty
	if (top == NULL)
	{
		cout << "\nThe stack is empty! Can't pop!";
	}
	else {
		//Replaces the current top element with the next one
		temp = top;
		top = top->next;

		//Prints the old top data
		cout << "\nPOP Operation........\nPoped value is " << temp->data;

		//Deletes the old top
		delete temp;
	}
}

// Show the contents of the stack
template <typename T>
void stack<T>::show()
{
	//A pointer to the current top node
	node<T> *ptr1 = top;
	cout << "\nThe stack is\n";

	//Print out values of all the nodes while its not null
	while (ptr1 != NULL)
	{
		cout << ptr1->data << " ->";
		ptr1 = ptr1->next;
	}
	cout << "NULL\n";
}

// Main function
int main()
{
	stack<int> s;
	int choice;

	cout << "\n\t\tSTACK USING LINKED LIST\n\n" << endl;

	while (1)
	{
		cout << "\n-----------------------------------------------------------" << endl;
		cout << "1:PUSH\n2:POP\n3:DISPLAY STACK\n4:EXIT";
		cout << "\nEnter your choice(1-4): ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			s.push();
			break;
		case 2:
			s.pop();
			break;
		case 3:
			s.show();
			break;
		case 4:
			return 0;
			break;
		default:
			cout << "\nPlease enter correct choice(1-4)!!";
			break;
		}
	}
	return 0;
}

//CODE OUTPUT
/*

				STACK USING LINKED LIST



-----------------------------------------------------------
1:PUSH
2:POP
3:DISPLAY STACK
4:EXIT
Enter your choice(1-4): 1

PUSHEnter a value add to stack: 5

Item was inserted successfully!
-----------------------------------------------------------
1:PUSH
2:POP
3:DISPLAY STACK
4:EXIT
Enter your choice(1-4): 3

The stack is
5 ->NULL

-----------------------------------------------------------
1:PUSH
2:POP
3:DISPLAY STACK
4:EXIT
Enter your choice(1-4): 1

PUSHEnter a value add to stack: 6

Item was inserted successfully!
-----------------------------------------------------------
1:PUSH
2:POP
3:DISPLAY STACK
4:EXIT
Enter your choice(1-4): 2

POP Operation........
Poped value is 6
-----------------------------------------------------------
1:PUSH
2:POP
3:DISPLAY STACK
4:EXIT
Enter your choice(1-4): 3

The stack is
5 ->NULL

-----------------------------------------------------------
1:PUSH
2:POP
3:DISPLAY STACK
4:EXIT
Enter your choice(1-4):
*/