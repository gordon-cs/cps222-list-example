/* Simple singly-linked list example: a forward-only list of integer values.
 * (Use std::forward_list for real code.)
 */

class List {
 public:
  List();                 // Create an empty list
  // Be careful of big 3!  Don't allow a default for just some of them.
  List(List &) = delete;             // No copy constructor
  void operator=(List &) = delete;   // No assignment operator
  ~List();                // Delete list, including its contents
  bool empty();           // Returns true iff list is empty
                          // "iff" means "if and only if"

  void * first();         // Return pointer to first node in list
  void * next(void *ptr); // Return pointer to node after ptr, or nullptr
                          // if there is no such node.

  int value(void *ptr);   // Return value of node at ptr.
                          // Crash if ptr is null.

  // Insert value after node at ptr
  void insert_after(int value, void *ptr);
  // Delete the node after node at ptr
  void delete_after(void *ptr);

  // Insert a new node containing value in front of the first node
  void push_front(int value);
  int pop_front();       // Delete the first node and return its value
                         // Crash if list is empty.

 private:
  // List is a list of Nodes, each of which holds a single int value.
  // A struct is like a class without methods or protection (scope).
  struct Node {
    Node *_next;
    int _value;
  };

  Node *_first;
};
