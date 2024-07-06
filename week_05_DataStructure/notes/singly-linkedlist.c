#include <stdio.h>
// chrome-extension://efaidnbmnnnibpcajpcglclefindmkaj/https://cdn.cs50.net/2017/fall/shorts/singly_linked_lists/singly_linked_lists.pdf
// A linked list node is a special kind of struct with two members
typedef struct sllist
{
    VALUE val;              // Data of some data type (int, char, float...)
    struct sllist* next;    // A pointer to another node of the same type
} sllnode;

// In order to work with linked lists effectively, there are a number of operations need to under stand
    // - Create a linked list when a when it doesn't really exist
    // - Search through a linked list to find an element
    // - Insert a new node into the linked list
    // - Delete a single element from a linked list
    // Delete and entire linked list

// Create a linked list
    sllnode* create(VALUE val);
// Steps involved
    // - Dynamically allocate space for a new sllnode
    // - Check to make sure we didn't run out of memory
    // - Initialize the node's val field
    // - Initialize the node's next field
    // - Return a pointer to the newly created sllnode.

// Search through a linked list to find an element
    bool find(sllnode* head, VALUE val);
// Steps involved
    // - Create a traversal pointer pointing to the list's head
    // - If the current node's val field is what we're looking for, report success
    // - If not, set the traversal pointer to the next pointer in the list and go back to above step
    // - If reach the end of the list, report failure

// Insert a new node into the linked list
    sllnode* insert(sllnode* head, VALUE val);
// Steps involved
    // - Dynamically allocate space for a new sllnode
    // - Check to make sure it didn't run out of memory
    // - Populate and insert the node at the beginning of the linked list
    // - Return a pointer to the new head of the linked list

// Delete an entire linked list
    void destroy(sllnode* head);
// Steps involved
    // - If reached a null pointer, stop
    // - Delete the rest of the list
    // - Free the current node
