/*
Function: Node
Constructor: defaults title and author to predetermined string value.
Defaults the date to January 1st, 2016. Make ptr NULL. 
Inputs: None
Outputs: None data is going to be zeroed
Return: N/A
	Zero out data

Function: Node
Constructor: Accepts title, author, and date. Set ptr to NULL.
Inputs: Title, Author, and Date
Outputs: None
Return: None

Function: set_l
Description: Mutator function to set ptr.
Inputs: lptr
Outputs: None
Return: None

Function: get_l
Description: Accessor function to get ptr.
Inputs: None
Outputs: None
Return: lptr

Function: get_title
Description: Accessor function to get book title.
Inputs: None
Outputs: None
Return: btitle

Function: get_author
Description: Accessor function to get book author.
Inputs: None
Outputs: None
Return: bauthor

Function: get_date
Description: Accessor function to get book date.
Inputs: None
Outputs: None
Return: bdate

Function: compare_data
Description: compare the title of a book passed to the function 
against the book in the class
Inputs: bktitle1,bktitle2
Outputs: None
Return: True if title matches, False if title does not match.

Function: process_data
Description: Prints data to the screen
Inputs: None
Outputs: Book title, Author, Date.
Return: None
*/
#include <string>

#ifndef __NODE__
#define __NODE__
class Node
{
	//Declare class variables *Private
	std::string booktitle;
	std::string bookauthor;
	std::string date;
	Node *plink, *nlink;
	
	//Public allows access to data
	public:
        //default constructor if no values given.
		Node()
		{
			booktitle = "The Great Divorce";
			bookauthor = "C. S. Lewis";
			date = "2/17/2016";
			plink = NULL;
			nlink = NULL;
		}
		//constructor if values given.
		Node(std::string title, std::string author,std::string dte)
		{
			booktitle = title;
			bookauthor = author;
			date = dte;
			plink = NULL;
			nlink = NULL;
		}
        //Function Prototypes
		void set_nlink(Node *nlptr);
		void set_plink(Node *plptr);
		Node* get_nlink();
		Node* get_plink();
		std::string get_title();
		std::string get_author();
		std::string get_date();
		bool compare_data(std::string bktitle);
		bool compare_author(std::string bkauthor);
		void process_data();
};
#endif
