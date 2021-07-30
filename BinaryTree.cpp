// clang++ -target x86_64-pc-windows-gnu main.cpp

#include <iostream>
#include <ios>
#include <sugar>

using namespace std;

struct Node
{
    i32   data;
    Node *left;
    Node *right;

    Node ( i32 );
    Node ( i32, Node*, Node* );
};

Node::Node( i32 data )
{
    this->data  = data;
    this->left  = nullptr;
    this->right = nullptr;
}

Node::Node( i32 data, Node *left, Node *right )
{
    this->data  = data;
    this->left  = left;
    this->right = right;
}

void NodeLevel ( Node *node,
                 i32   level );
void PrintNode ( Node *node );

void PrintNode( Node *node )
{
    for ( i32 i = 1; i <= node->data ; i++ )
    {
        NodeLevel( node, i );
        cout << endl;
    }
}

void NodeLevel( Node *node, i32 level )
{
    if      ( node == NULL ) { return; }
    if      ( level == 1 )   { cout << node->data; }
    else if ( level > 1 )
    {
        NodeLevel( node->left,  level - 1 );
        NodeLevel( node->right, level - 1 );
    }
}

// root = [4,2,7,1,3,6,9]

/*
          4
        /   \
       2     7
      / \   / \
     1   3 6   9
*/

int main()
{
    Node* root = new Node( 4 );

    root->left  = new Node( 2 );
    root->right = new Node( 7 );

    root->left->left  = new Node( 1 );
    root->left->right = new Node( 3 );

    root->right->left  = new Node( 6 );
    root->right->right = new Node( 9 );

    PrintNode(root);

    return 0;
}
