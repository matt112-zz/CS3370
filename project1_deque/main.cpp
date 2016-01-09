#include <cctype>       // Provides toupper
#include <iostream>

#include "deque.h"


using namespace std;

// PROTOTYPES for functions used by this test program:
void print_menu();
// Postcondition: A menu of choices for this program has been written to cout.

char get_user_command();
// Postcondition: The user has been prompted to enter a one character command.
// The next character has been read (skipping blanks and newline characters),
// and this character has been returned.

int get_number();
// Postcondition: The user has been prompted to enter a real number. The
// number has been read, echoed to the screen, and returned by the function.



int main()
{
	Deque<int> test; // A AVL that we'll perform tests on
	char choice;   // A command character entered by the user

	cout << "I have initialized an empty Deque" << endl;

	do
	{
		print_menu();
		choice = toupper(get_user_command());
		switch (choice)
		{

		case 'S': cout << "Size is " << test.size() << endl;
			break;
		case 'F': test.push_front(get_number());
			break;
		case 'B': test.push_back(get_number());
			break;
		case 'P': test.print();
			break;
		case '1': test.pop_front();
			break;
		case '2': test.pop_back();
			break;
		case 'C': cout << "Capacity: " << test.capacity();
			break;
		case 'Q': cout << "Thanks for playing!" << endl;
			break;
		default:  cout << choice << " is invalid." << endl;
		}
	} while ((choice != 'Q'));

	return 0;
}

void print_menu()
// Library facilities used: iostream.h
{
	cout << endl; // Print blank line before the menu
	cout << "The following choices are available: " << endl;
	cout << " S   Print the result from the size( ) function" << endl;
	cout << " F   push_front() function" << endl;
	cout << " B   push_back() function" << endl;
	cout << " P   Print the array" << endl;
	cout << " 1   pop_front() function" << endl;
	cout << " 2   pop_back() function" << endl;
	cout << " C   capacity() function" << endl;
	cout << " Q   Quit this test program" << endl;
}

char get_user_command()
// Library facilities used: iostream
{
	char command;

	cout << "Enter choice: ";
	cin >> command; // Input of characters skips blanks and newline character

	return command;
}

int get_number()
// Library facilities used: iostream
{
	int result;

	cout << "Please enter an integer: ";
	cin >> result;
	cout << result << " has been read." << endl;
	return result;
}
