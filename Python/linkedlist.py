# linkedlist.py
# Construtores de Lista Encadeada

# Node class
# it only has a constructor so all the linked list methods won't need to create one each time
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedList:

    # ll constructor
    # initializes a new ll with one node
    # step-by-step:
    # -> gets the newer node
    # -> updates head and tail to point to that new node
    # -> updates length
    def __init__(self, value):
        new_node = Node(value)
        self.head = new_node
        self.tail = new_node
        self.length = 1

    # 'print_list()'
    # prints all list elements
    # step-by-step:
    # -> creates a temporary variable to store the first element of the list (aka head)
    # -> iterates through it until the next value points to none (temp is updated to temp.next in every iteration)
    def print_list(self):
        temp = self.head
        while temp is not None:
            print(temp.value)
            temp = temp.next
    
    # 'make_empty()'
    # makes a list empty
    # step-by-step:
    # -> makes both head and tail nodes point to None, since it's now empty
    # -> makes length go to 0
    def make_empty(self):
        self.head = None
        self.tail = None
        self.length = 0
    # 'append()'
    # the append method is going to:
    # - add a new node to the end of the list
    # step by step:
    # -> a new node is created, which contains the value that we are going to append
    # -> if the list is empty:
    #   -> both head and tail are going to point to the new element
    # -> else
    #   -> last element and tail are going to point to the new node
    # length is updated.

    def append(self, value):
        # new node creation
        new_node = Node(value)

        # if list is empty, new node -> whole list
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        # list not empty
        else:
            self.tail.next = new_node
            self.tail = new_node
        # updated length, which happens in both cases    
        self.length += 1
        return True

    
    # the prepend method is going to:
    # - add a new node to the beginning
    # def prepend(self, value):

    # the insert method is going to:
    # - create a new node
    # - add it to the end of the list
    # def insert(self, index, value);
        
# using the linked list class and testingg
my_linked_list = LinkedList(4)
my_linked_list.append(2)
print(f"Head: {my_linked_list.head.value}")
print(f"Tail: {my_linked_list.tail.value}")
print(f"Length: {my_linked_list.length}")
