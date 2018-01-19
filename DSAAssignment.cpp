#include <iostream>
#include "Tree.h";
using namespace std;

int add(int);

void removingNode(Tree);

void menu();

int main() {
	bool displaymenu = true;
	Tree tree;
	int userinput,count;
	cout << "Please enter an integer: ";
	cin >> userinput;
	count = add(userinput);
	for (int i = 1;i <= count;i++)
		tree.insert(i);
	// Stops only when the user inputs 0
	while(displaymenu)
	{
		menu();
		int opt;
		cin >> opt;
		switch(opt)
		{
			case 1:
			{
				int val;
				cout << "Please enter a value to search: ";
				cin >> val;
				tree.search(val);
				//similar to system("PAUSE")
				// to pause the system
				cin.get();
				cin.ignore();
				break;
			}
			case 2:
			{
				int val;
				tree.display();
				cout << "Duplicate values are not supported!" << endl;
				cout << "Please enter a value to add: ";
				cin >> val;
				tree.insert(val);
				cout << val << " has been added to the tree";
				cin.get();
				cin.ignore();
				break;
			}
			case 3:
			{
				removingNode(tree);
				cin.get();
				cin.ignore();
				break;
			}
			case 4:
			{
				tree.displayAscending();
				cin.get();
				cin.ignore();
				break;
			}
			case 5:
			{
				int val;
				cout << "Please enter a value to search for using level-by-level traversal: ";
				cin >> val;
				tree.leveltraversal(val);
				cin.get();
				cin.ignore();
				break;
			}
			case 6:
			{
				tree.display();
				cin.get();
				cin.ignore();
				break;
			}
			case 0:
			{
				cout << "Bye Bye!" << endl;
				displaymenu = false;
				break;
			}
			default:

			{
				cout << "INVALID INPUT" << endl;
				cin.get();
				cin.ignore();
				break;
			}

		}
	}

	return 0;
}


// Displaying of Menu
void menu()
{
	 cout << endl;
	   cout << "DSA Assignment Demo \n";
	   cout << "--------------------------------\n";
	   cout << "1. Search for a value \n";
	   cout << "2. Add a new value \n";
	   cout << "3. Delete a value \n";
	   cout << "4. Display all the value in ascending order \n";
	   cout << "5. Search for a value using level-by-level traversal \n";
	   cout << "6. Display the tree \n";
	   cout << "0 Exit \n";
	   cout << "--------------------------------\n";
	   cout << "Enter option : ";
}

/* Populate the tree with sum of integers to
 * obtain the value of the user's input
 */
int add(int userinput)
{
	int m = 1,count = 1;

	while(m <= userinput)
	{
		count++;
		m += count;
	}
	return count;
}
/*
 * Ask user for validation when removing a node
 */
void removingNode(Tree tree)
{
	int val;
	string input;
	cout << "Please enter a value to remove: ";
	cin >> val;
	cout << "Are you sure you want to remove " << val << "? (Y/N): ";
	cin >> input;
	// recursive when the input is not Y
	if (input != "Y")
	{
		if (input != "N")
			cout << "Please enter a valid answer" << endl;
		removingNode(tree);
	}
	else
	{
		tree.remove(val);
		cout << "Value has been successfully removed." << endl;
	}


}

