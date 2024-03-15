//DELETE WITHOUT HEAD POINTER


class Node
{
	int data ;
	Node next;
	Node(int d)
	{
		data = d;
		next = null;
	}
}


//Function to delete a node without any reference to head pointer.
class Solution
{
    void deleteNode(Node del_node)
    {
         // Your code here
         Node t = del_node.next;
         del_node.data = t.data;
         del_node.next = t.next;;
         
         t = null;
    }
}
