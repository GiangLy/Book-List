/*
Author: Giang Ly
Student ID: C427R468
Program Number: 5

Description of Problem:
For this program, you are going to modify the Node class that you wrote
for program #3 and implement a double linked list.  The node class will 
have the same member functions as before with the addition of another 
link.  You will now have a previous link (pointer) and a next link 
(pointer).  All of the information will be written to a file.  Just as 
in the first program, you are to check to see if the file exists.  If it
does, open the file and populate the list.  Otherwise, when the program 
exits, print the information to a file.  Call the file “booklist.txt”.
*/

#include "stack.hpp"
#include "Node.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void print_menu();

int main (void)
{  
	int choice, count =0;
    string title, author, dte;
    
    // Create list.  List will be empty at this point.
    Linked_list list;
    //Attempt to open booklist.txt
	ifstream infile;
	infile.open("booklist.txt");

    //Check if file exists, if not then create the text file.
	if (infile.fail())
	{
		cout << "File not found" << endl;
		ofstream ofile;
		ofile.open("booklist.txt");
		ofile.close();
		cout << "File Created Ready for entries." << endl;
	}
	else
	{
        //Loop if text file exists and store data to linked list.
		while (infile.good())
		{
			getline(infile,title);
			count++;
		}
		infile.close();
		
		infile.open("booklist.txt");
		for (int i = 0; i < (count - 1); i+= 3)
		{
	            getline(infile, title);
	            getline(infile, author);
	            getline(infile, dte);
                list.insert_node(title,author,dte);
	    } 
	    infile.close();
	}
	
    
    //Loop until user input is valid.
	do
	{
		print_menu();
		cout << "Enter Choice: ";
	    cin >> choice;
	    cin.ignore(25, '\n');
		switch (choice)
		{
		case 1:
		 	cout << "Enter Title: ";
		    getline(cin, title);
	        cout << "Enter Author: ";
	        getline(cin, author);
	        cout << "Enter Date: ";
	        getline(cin, dte);
	        list.insert_node(title,author,dte);
			break;
		case 2:
		    cout << "Enter Title: ";
	        getline(cin, title);
	        list.delete_node(title);
			break;
		case 3:
		    cout << "Enter Title: ";
	        getline(cin, title);
	        list.retrieve(title);
			break;
		case 4:
		    list.trav_forward();
			break;
		case 5:
		    list.trav_backward();
		    break;
		case 6:cout << "writing to file..." << endl << "Exiting..." 
		    << endl;
		    list.save_list();
			break;
		default:cout << "Not a valid choice" << endl;
		}
	} while (choice != 6);

	return 0;
}

//This is the menu that is displayed for user to select a choice from.
void print_menu()
{

	cout << "1. Add a book" << endl;
	cout << "2. Delete a book" << endl;
	cout << "3. Retrieve a book" << endl;
	cout << "4. Print list forwards" << endl;
	cout << "5. Print list backwards" << endl;
	cout << "6. Exit" << endl;
}
