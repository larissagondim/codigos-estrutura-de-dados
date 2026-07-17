# linkedlist.py
# Construtores de Lista Encadeada

# Node class
# it only has a constructor so all the linked list methods won't need to create one each time
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedList:

    def __init__(self, value):
        new_node = Node(value)
        self.head = new_node
        self.tail = new_node
        self.length = 1

    def print_list(self):
        temp = self.head
        while temp is not None:
            print(temp.value)
            temp = temp.next
    
    # the append method is going to:
    # - add a new node to the end of the list
    def append(self, value):
        new_node = Node(value)
        self.tail = new_node
    
    # the prepend method is going to:
    # - add a new node to the beginning
    # def prepend(self, value):

    # the insert method is going to:
    # - create a new node
    # - add it to the end of the list
    # def insert(self, index, value);
        
# using the linked list class
my_linked_list = LinkedList(4)
print(f"Head: {my_linked_list.head.value}")
print(f"Tail: {my_linked_list.tail.value}")
print(f"Length: {my_linked_list.length}")
