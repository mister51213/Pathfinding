#include <vector>
#include <iostream>

using namespace std;

class Node
{
public:
	vector<Node*> children;

	int depth;

	Node* InsertNode()
	{
		children.push_back(new Node());
		return children.back();
	}
};

int FindPathToNode(Node* From, Node* To, int depth = 0)
{
	// base case
	if (From == To)
	{
		return depth;
	}

	if (!From)
	{
		return -1;
	}

	for (int i = 0; i < From->children.size(); ++i)
	{	
		//if (From == To)
		//{
		//	break;
		//}

		//if (!From)
		//{
		//	return -1;
		//}

		return FindPathToNode(From->children[i], To, depth + 1);
	}

	return depth;
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

	Node* destination = head->children[0]->children[0]->children[0]->InsertNode();
	head->children[0]->children[0]->children[0]->InsertNode();
	head->children[0]->children[0]->children[0]->InsertNode();

	int depth = FindPathToNode(head, destination);

	return 0;
}