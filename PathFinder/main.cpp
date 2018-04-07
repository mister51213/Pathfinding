#include <vector>
#include <iostream>

using namespace std;

class Node
{
public:
	vector<Node*> children;

	int depth = 0;

	Node* InsertNode()
	{
		children.push_back(new Node());
		children.back()->depth = depth + 1;
		return children.back();
	}
};

int FindPathToNode(Node* From, Node* To, int depth = 0)
{
	// Successfully found the node we are looking for, so pass it up the call stack.
	if (From == To)
	{
		return depth;
	}

	// Reached a dead end, so return -1.
	if (!From)
	{
		return -1;
	}

	for (int i = 0; i < From->children.size(); ++i)
	{	
		int result = FindPathToNode(From->children[i], To, depth + 1);

		// If there is no child at that index (deadend), try the next indices.
		if (result == -1) 
			continue;
		else // we found the node, so pass it back up the call stack.
			return result;
	}

	// Looped through everything and found nothing, so return -1.
	return -1;
}

int main()
{
	Node* head = new Node();

	head->InsertNode();
	head->InsertNode();
	head->InsertNode();

	head->children[0]->InsertNode();
	head->children[0]->InsertNode();
	head->children[0]->InsertNode();

	head->children[0]->children[0]->InsertNode();
	head->children[0]->children[0]->InsertNode();
	head->children[0]->children[0]->InsertNode();

	head->children[0]->children[0]->children[0]->InsertNode();
	head->children[0]->children[0]->children[0]->InsertNode();
	Node* destination = head->children[0]->children[0]->children[0]->InsertNode();

	int depth = FindPathToNode(head, destination);

	return 0;
}