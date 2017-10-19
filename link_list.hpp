/*
Function: Linked_list
Constructor: defaults count to 0, Head and Tail to NULL.
Inputs: None
Outputs: None data is going to be zeroed
Return: N/A
	Zero out data and create a linked list

Function: insert_node
Description: adds item to linked list
Inputs: title, author, date
Outputs: None
Return: None

Function: delete_node
Description: deletes item from linked list
Inputs: title
Outputs: None
Return: None

Function: trav_forward
Description: Goes through linked list and prints information from begin
ning of list to the end of list.
Inputs: None
Outputs: Book information from beginning to end.
Return: None

Function: trav_backward
Description: Goes through linked list and prints information from end
to the beginning of list.
Inputs: None
Outputs: Book information from end to beginning.
Return: None

Function: retrieve
Description: Goes through linked list and print any books matching the
title taken from user. 
Inputs: title
Outputs: Book information with title matching.
Return: None

Funtion: save_list
Description: Saves data to linked list from beginning to end.
Inputs: None
Outputs: Book information to booklist.txt
Return: None 
*/

#include <string>
#include "Node.hpp"


#ifndef __ll__
#define __ll__
class Linked_list
{
   // Keep track of how many are in list.
   int count;
   Node *head, *tail;
 public:
   Linked_list();
   bool insert_node(std::string title, std::string author,std::string dte); 
   bool delete_node (std::string title);
   void trav_forward(); 
   void trav_backward();
   void retrieve(std::string title);   
   void save_list();
};
#endif
