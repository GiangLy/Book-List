#include "Node.hpp"
#include <iostream>
#include <string>

using namespace std;

//Mutator Function
void Node :: set_nlink(Node *nlptr)
{
	nlink = nlptr;
}

void Node :: set_plink(Node *plptr)
{
	plink = plptr;
}

//Compares title, if title is the same then return true else return
//false.
bool Node :: compare_data(std::string bktitle)
{
	if (booktitle.compare(bktitle) == 0)
	{
		return 1;
	}
		return 0;
}

//Compares author, if author is the same then return true else return
//false.
bool Node :: compare_author(std::string bkauthor)
{
	if (bookauthor.compare(bkauthor) == 0)
	{
		return 1;
	}
		return 0;
}

//Accessor function to get next pointer of current node.
Node* Node :: get_nlink()
{
	return nlink;
}

//Accessor function to get prev pointer of current node.
Node* Node :: get_plink()
{
	return plink;
}

//Accessor Function to get title of current node.
string Node :: get_title()
{
	return booktitle;
}

//Accessor Function to get author of current node. 
string Node :: get_author()
{
	return bookauthor;
}

//Accessor Function to get date of current node.
string Node :: get_date()
{
	return date;
}

//Prints out data of node.
void Node::process_data()
{
	cout << booktitle << " " << bookauthor << " " 
	<< date << endl;
}
	
