#include <cstdint>
#include <cstdio>

class Node
{
public:
  uint8_t data  {};
  Node*   left  {};
  Node*   right {};

  Node( uint8_t data );

  Node( uint8_t data,
        Node*   left,
        Node*   right );

  ~Node();

  static void Print  ( Node* node );
  static void Invert ( Node* node );
};

Node::Node( uint8_t data ) : data  (  data   ),
                             left  ( nullptr ),
                             right ( nullptr ) {}

Node::Node( uint8_t data,
            Node*   left,
            Node*   right) : data  ( data  ),
                             left  ( left  ),
                             right ( right ) {}

Node::~Node() {}

void Node::Print( Node* node )
{
  if ( node == NULL ) { return; }

  Node::Print( node->left  );
  Node::Print( node->right );

  printf( "%d ", node->data );
}

void Node::Invert( Node* node )
{
  if ( node == NULL ) { return; }

  else
  {
    Node* temp;

    Node::Invert( node->left  ); 
    Node::Invert( node->right );

    temp        = node->left;
    node->left  = node->right;
    node->right = temp;
  }
}

/* INPUT */

/*
     2
    / \
   /   \
  1     4
 / \   / \
7   9 3   5
*/

/* OUTPUT */

/*
     2
    / \
   /   \
  4     1
 / \   / \
5   3 9   7
*/

int main()
{
  Node* root         = new Node( 2 );

  root->left         = new Node( 1 );
  root->right        = new Node( 4 );

  root->left->left   = new Node( 7 );
  root->left->right  = new Node( 9 );

  root->right->left  = new Node( 3 );
  root->right->right = new Node( 5 );

  Node::Print( root );

  printf( "\n" );

  Node::Invert( root );

  printf( "\n" );

  Node::Print( root );

  return 0;
}
