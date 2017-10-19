#include "link_list.hpp"
#include <iostream>
#include <string>
#include "Node.hpp"
#include <fstream>

// Create the linked list.
Linked_list::Linked_list()
{
   count = 0;
   head = tail = NULL;
}

// Insert a node in the list.
bool Linked_list::insert_node(std::string title, std::string author,std::string dte)
{
   // Create a new node with a NULL ptr.
   Node *node_ptr = new Node(title, author, dte);
   
   // If there are no entries in the linked list,
   // add it to the head.
   if (head == NULL)
   {
      tail = head = node_ptr;
      count ++;
   }
   else
   // If there is a head entry set new node to point to next node
   // and also point to back to NULL. Set new node as head pointer.
   // set next node to point back to new pointer.
   {
	   tail->set_nlink(node_ptr);
	   node_ptr->set_plink(tail);
	   node_ptr->set_nlink(NULL);
	   tail = node_ptr;
	   count ++;
   }
   return true;
}

//delete a node in linked list.
bool Linked_list::delete_node (std::string title)
{
   Node *curr, *prev;
   int found = 0;
   std::string confirm;
   
   // Start at the head pointer.
   curr = prev = head;
   
   // Go until the end of the list, everytime the data is found
   // print to screen.
   while (curr != NULL)
   {
      if (curr->compare_data(title))
      {
		  curr->process_data();
		  found++;
	  }
      curr = curr->get_nlink();
   }
   
   //If some entries are found, ask for confirmation of deletion.
   if (found > 0)
   {
	   std::cout << "Confirm delete (y/n)?";
	   std::cin >> confirm;
	   if (confirm == "y")
	   {
		   //Start back at head pointer
           curr = prev = head;
           // Go until the end of the list or the data is found
           while (curr != NULL)
           {
              if (curr->compare_data(title))
              {
		          // If the data is in the one pointed to by head,
                  // then delete it and modify the head pointer.
                  if (curr == head)
                  {  
				       if (head != tail)
					   {
						   head = curr->get_nlink();
						   head->set_plink(NULL);
                           delete curr;
                           prev = curr = head;
					   }
					   // Set everything to NULL after deleting node.
					   // Only 1 Node.
					   else
					   {
						   head = NULL;
						   tail = NULL;
						   delete curr;
						   curr = NULL;
					   }
                       
                       count --;
                  }
                  // Otherwise set the link of the next one
                  else 
                  {
                       prev->set_nlink(curr->get_nlink());
                       delete curr;
                       curr = prev->get_nlink();
                       if (curr == NULL)
                       {
						   tail = prev; //sets tail pointer to last item
					   }
					   else
					   {
						   curr->set_plink(prev);
					   }
                       count --;
                  }
	          }
	          //move to next entry in linked list.
	          else
	          {
				  prev = curr;
                  curr = curr->get_nlink();
			  }
           }
	   }
       else
       {
		   return 0; //no deletion
	   }
   // If the node is not found, then return out of the routine
   // letting the calling function know the node was not found.
   }
   else
   {
      std::cout << "no entries found." << std::endl;
      return 0;
   }   
   return 0;
}

void Linked_list::retrieve(std::string title)
{
   Node *curr, *prev;
   int found = 0;

   // Start at the head pointer.
   curr = prev = head;
   
   // Go until the end of the list, everytime the data is found
   // print to screen.
   while (curr != NULL)
   {
      if (curr->compare_data(title) == 1)
      {
		  curr->process_data();
		  found++;
	  }
      curr = curr->get_nlink();
   }
   
   // If no entries were found print message on screen.
   if (found < 1)
   {
	   std::cout << "No entries found." << std::endl;
   }
}

void Linked_list::trav_forward()
{
   Node *curr, *prev;
   
   // Start at the head pointer.
   curr = prev = head;
   
   // if linked list is empty print message.
   if (count == 0)
   {
	  std::cout << "No entries found." << std::endl;
   }
   else
   {
	   std::cout << count << " entries found" << std::endl;
   }
   // Go until the end of the list, print data from beginning.
   while (curr != NULL)
   {
      curr->process_data();
      curr = curr->get_nlink();
   }
}

void Linked_list::trav_backward()
{
   Node *curr, *prev;
   
   // Start at the tail pointer.
   curr = prev = tail;
   
   // if linked list is empty print message.
   if (count == 0)
   {
	  std::cout << "No entries found." << std::endl;
   }
   else
   {
	   std::cout << count << " entries found" << std::endl;
   }
   
   // Go until the end of the list, print data from end.
   while (curr != NULL)
   {
      curr->process_data();
      curr = curr->get_plink();
   }
}

void Linked_list::save_list()
{
   Node *curr, *prev;
   
   // Start at the tail pointer.
   curr = prev = head;
   
   //Write information back to booklist.txt
   std::ofstream ofile;
   ofile.open("booklist.txt", std::ios::trunc);
   // Go until the end of the list, save data from beginning.
   while (curr != NULL)
   {
        ofile << curr->get_title() << std::endl << 
            curr->get_author() << std::endl <<
			curr->get_date() << std::endl;
	    curr = curr->get_nlink();
   }
   ofile.close();
}
