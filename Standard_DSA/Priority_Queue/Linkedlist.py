class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class LinkedList:
    def __init__(self):
        self.head=None

    def insert_at_beginning(self,data):
        new_node=Node(data)
        new_node.next=self.head
        self.head=new_node

    def insert_at_end(self,data):
        new_node=Node(data)
        if not self.head:
            self.head=new_node
            return
        last_node=self.head
        while last_node.next:
            last_node=last_node.next
        last_node.next=new_node

    def delete_node(self,key):
        current_node=self.head
        if current_node and current_node.data==key:
            self.head=current_node.next
            current_node=None
            return
        prev=None
        while current_node and current_node.data!=key:
            prev=current_node
            current_node=current_node.next
        if current_node is None:
            return
        prev.next=current_node.next
        current_node=None

    def search(self,key):
        current_node=self.head
        while current_node:
            if current_node.data==key:
                return True
            current_node=current_node.next
        return False

    def display(self):
        current_node=self.head
        while current_node:
            print(current_node.data,end=" -> ")
            current_node=current_node.next
        print("None")


def main():
    # Create a linked list
    ll=LinkedList()

    # Insert elements
    ll.insert_at_beginning(10)
    ll.insert_at_beginning(20)
    ll.insert_at_end(30)
    ll.insert_at_end(40)

    ll.display()

main()
