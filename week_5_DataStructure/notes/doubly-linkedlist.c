// Doubly-linked list allows us to move forward and backward through the list, by simply add on extra pointer to struct definition

typedef struct dllist
{
    VALUE val;
    struct dllist* prev;
    struct dllist* next;
} dllnode;

// In order to work with linked lists effectively, there are number of operations that needed to understand
    // - Create a linked list when it doesn't already exist
    // - Search through a linked list to find an element
    // - Insert a new node into the linked list
    // - Delete a single element from a linked list
    // - Delete and entire linked list

// Insert a new ndoe into the linked list
    dll node* insert(dllnode* head, VALUE val);
    // Step involved
        // - Dynamically allocate space for a new dllnode
        // - Check to make sure it didn't run out of memory
        // - Populate and insert the node at the beginning of the linked list
        // - Fix the prev pointer of the old head of the linked list
        // - Return a pointer to the new head of the linked list

// Delete a node from a linked list
    void delete(dllnode* target);
    // Steps involved
        // Fix the pointers of the surrounding nodes to "Skip over" target
        // Free target

// Linked lists, both the singly- and doubly-linked varieties, support extremely efficient insertion and deletion of elements
//     these operations can be done in constant time

// The downside is it had to find an element, and lost the ability to randomly-access list elements
//     accessing a desired element may now take linear time
