#include <iostream>
using namespace std;

class TreeNode
{
public:

    int Data;
    int hight;
    TreeNode* left;
    TreeNode* right;

    void inorder(TreeNode* node);
    void preorder(TreeNode* node);
    void postorder(TreeNode* node);
    int calculateHight(TreeNode* node);
    TreeNode* makeNode(int D);
    TreeNode* rightRotation(TreeNode*Node0);
    TreeNode* leftRotation(TreeNode*Node0);
    int calculateBalanceFactor(TreeNode* node);
    TreeNode* inserteNode(TreeNode* currentNode,int value);
};

int TreeNode::calculateHight(TreeNode* node)
{
    if (node==NULL)
        return 0;
    return node->hight;



}
//create node
TreeNode* TreeNode:: makeNode(int D)
{
    TreeNode* newNode = new TreeNode();
    newNode->hight = 1;
    newNode->Data = D;
    newNode->left =newNode->right=NULL;
    return(newNode);
}


TreeNode* TreeNode::rightRotation(TreeNode*Node0)
{
    //create 2 nodes one for hold left child
    //second to hold the right child of node one(the left child)
    TreeNode* Node1=Node0->left;
    TreeNode* Node2=Node1->right;
    //then we rotate right on Node0 by let it be the right child of Node1
    //and let Node2 be the left child of Node0
    Node1->right=Node0;
    Node0->left=Node2;
    //then recalculate hight
    Node0->hight= max(calculateHight(Node0->left),calculateHight(Node0->right))+1;
    Node1->hight= max(calculateHight(Node1->left),calculateHight(Node1->right))+1;

    return Node1;

}

TreeNode* TreeNode::leftRotation(TreeNode*Node0)
{
    //create 2 nodes one for hold right child
    //second to hold the left child of node one(the right child)
    TreeNode* Node1=Node0->right;
    TreeNode* Node2=Node1->left;
    //then we rotate left on Node0 by let it be the left child of Node1
    //and let Node2 be the right child of Node0
    Node1->left=Node0;
    Node0->right=Node2;
    //then recalculate hight
    Node0->hight= max(calculateHight(Node0->left),calculateHight(Node0->right))+1;
    Node1->hight= max(calculateHight(Node1->left),calculateHight(Node1->right))+1;

    return Node1;
}
int TreeNode::calculateBalanceFactor(TreeNode* node)
{
    if(node==NULL)
        return 0;
    else
        return calculateHight(node->left) - calculateHight(node->right);
}

TreeNode* TreeNode::inserteNode(TreeNode* currentNode,int value)
{

    //tree is empty ,insert in root
    if(currentNode==NULL)
    {
        return(makeNode(value));

    }
    //if value greater than parents node then it will save in right child
    if(value>currentNode->Data)
    {
        currentNode->right=inserteNode(currentNode->right,value);
    }
    //if value less than parents node then it will save in left child
    else if(value<currentNode->Data)
    {
        currentNode->left=inserteNode(currentNode->left,value);
    }

    // handle duplicates node
    else
    {
        return(currentNode);

    }


    //recalculate hight
    currentNode->hight=max(calculateHight(currentNode->left),calculateHight(currentNode->right))+1;
    //recalculate BalanceFactor
    int BalanceFactor=calculateBalanceFactor(currentNode);
    //left rotation
    if(BalanceFactor<-1&&value > currentNode->right->Data)
    {
        return leftRotation(currentNode);
    }
    //right left rotation
    if(BalanceFactor<-1&&value < currentNode->right->Data)
    {
        currentNode->right = rightRotation(currentNode->right);
        return leftRotation(currentNode);
    }
    //right rotation
    if(BalanceFactor >1 &&value < currentNode->left->Data)
    {
        return rightRotation(currentNode);
    }
    //left right rotation
    if(BalanceFactor>1&& value > currentNode->left->Data)
    {
        currentNode->left=leftRotation(currentNode->left);
        return rightRotation(currentNode);
    }
    //in case there is not unbalanced node we return the node as it is
    else
        return currentNode;

}

//To print tree in inorder condition (left,root,right)
void TreeNode::inorder(TreeNode* node)
{
	if(node != NULL)
	{
		inorder(node->left);
		cout<<node->Data<<" ";
		inorder(node->right);
	}
}

//To print tree in preorder condition (root, left, right)
void TreeNode::preorder(TreeNode* node)
{
	if(node != NULL)
	{
	    cout<<node->Data<<" ";
		preorder(node->left);
		preorder(node->right);
	}
}

//To print tree in postorder condition (left,right,root)
void TreeNode::postorder(TreeNode* node)
{
	if(node != NULL)
	{
		postorder(node->left);
		postorder(node->right);
		cout<<node->Data<<" ";
	}
}

int main()
{

    TreeNode n, *root = NULL;
    root = n.inserteNode(root, 57);
    n.inserteNode(root, 78);
    n.inserteNode(root, 42);
    n.inserteNode(root, 25);
    n.inserteNode(root, 49);
    n.inserteNode(root, 85);
    n.inserteNode(root, 63);
    n.inserteNode(root, 72);
    n.inserteNode(root, 60);
    n.inserteNode(root, 17);
    n.inserteNode(root, 30);
    n.inserteNode(root, 45);
    n.inserteNode(root, 36);
    n.inserteNode(root, 41);

    cout<<"inorder:"<<endl;
    n.inorder(root);
	cout<<endl;
    cout<<endl;

    cout<<"preorder:"<<endl;
    n.preorder(root);
	cout<<endl;
    cout<<endl;

    cout<<"postorder:"<<endl;
    n.postorder(root);
	cout<<endl;
    cout<<endl;

    return 0;
}
