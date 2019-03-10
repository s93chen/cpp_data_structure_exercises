#include <iostream>
#include <stdexcept>

/* Since a binary search tree maps KEYS to VALUES, each Node 
 * actually has two types: K (key type) and V (value type).
 */
template <typename K, typename V>
struct Node {
    Node(K key, V val);

    K key;
    V val;
    Node<K, V> *left;
    Node<K, V> *right;
};

template <typename K, typename V>
Node<K, V>::Node(K key, V val):
    key(key),
    val(val),
    left(nullptr),
    right(nullptr)
{ }

/* Note: the key type K should be comparable via <, >, ==, etc. */
template <typename K, typename V>
class BinarySearchTree {
public:
    /* constructor */
    BinarySearchTree();
    
    /* destructor */
    ~BinarySearchTree();

    int size();
    int height();
    bool empty();
    
    /* insert new node */
    void insert(K key, V val);

    /* get value at key */
    V& get(K key);

    /* remove node at key */
    void remove(K key);

    /* check if key exists */
    bool exists(K key); 

    /* destruct bst */
    void destructTree();
    
    void inOrder();

private:
    
    Node<K, V> *root;
    
    int bstSize;
    
    /*
     * helper method for recursively
     * deleting all nodes in tree
     */
    // void destructTree(Node *leaf);
    
    /* helper method for recursively
     * traversing the tree and check
     * for given key
     */
    V& get(Node<K, V> *rootNode, K key);

    /* helper method for recursively
     * traversing the tree and inserting
     * given node
     */
    Node<K, V>* insert(Node<K, V> *rootNode, K key, V val);

    /* helper method for recursively
     * traversing the tree and checking
     * if given key exists
     */
    bool exists(Node<K, V> *rootNode, K key);
    
    void inOrder(Node<K, V> *rootNode);
};


template <typename K, typename V>
BinarySearchTree<K, V>::BinarySearchTree():
    root(nullptr),
    bstSize(0)
{ }

template <typename K, typename V>
BinarySearchTree<K, V>::~BinarySearchTree()
{
    std::cout << "destructor called" << std::endl;
    //destructTree();
}

template <typename K, typename V>
int BinarySearchTree<K, V>::size() 
{
    return bstSize;    
}

template <typename K, typename V>
int BinarySearchTree<K, V>::height()
{
    //return bstHeight;
    return 0;
}

template <typename K, typename V>
bool BinarySearchTree<K, V>::empty()
{
    return (bstSize == 0);
}

template <typename K, typename V>
V& BinarySearchTree<K, V>::get(K key)
{
    if (!bstSize) {
        throw std::logic_error("Empty tree!");
    } else {
        return get(root, key);
    }
}

template <typename K, typename V>
V& BinarySearchTree<K, V>::get(Node<K, V> *rootNode, K key)
{
    if (!rootNode) {
        throw std::logic_error("Key does not exist.");    

    } else if (key == rootNode->key) {
        return rootNode->val;    
 
    } else if (key > rootNode->key) {
        return get(rootNode->right, key);
 
    } else {
        return get(rootNode->left, key);
    }
}

template <typename K, typename V>
bool BinarySearchTree<K, V>::exists(K key)
{
    if (!bstSize) {
        return false;
    } else {
        return exists(root, key);
    }
}

template <typename K, typename V>
bool BinarySearchTree<K, V>::exists(Node<K, V> *rootNode, K key)
{
    if (!rootNode) {
        return false;
 
    } else if (key == rootNode->key) {
        return true;
 
    } else if (key > rootNode->key) {
        return exists(rootNode->right, key);
    
    } else {
        return exists(rootNode->left, key);
    }
}

template <typename K, typename V>
void BinarySearchTree<K, V>::insert(K key, V val)
{
    root = insert(root, key, val);
}

template <typename K, typename V>
Node<K, V>* BinarySearchTree<K, V>::insert(Node<K, V> *rootNode, K key, V val)
{
    if (!rootNode) {
        bstSize++;
        return new Node<K, V>(key, val);

    } else if (key < rootNode->key) {
        rootNode->left = insert(rootNode->left, key, val);

    } else if (key > rootNode->key) {
        rootNode->right = insert(rootNode->right, key, val);    

    } else {
        rootNode->val = val;    
    }

    return rootNode;
}

template <typename K, typename V>
void BinarySearchTree<K, V>::inOrder()
{
    inOrder(root);   
}

template <typename K, typename V>
void BinarySearchTree<K, V>::inOrder(Node<K, V> *rootNode)
{
    if (!rootNode) {
        return;
    }
    
    inOrder(rootNode->left);
    std::cout << rootNode->val << std::endl;
    inOrder(rootNode->right);
}

int main()
{
    Node<int, int> *node = new Node<int, int>(10, 20);
    std::cout << "key: " << node->key
        << ", val: " << node->val
        << ", left: " << node->left
        << ", right: " << node->right
        << '\n';

    delete node;

    BinarySearchTree<int, int> bst;
    bst.insert(10, 10);
    bst.insert(2, 2);
    bst.insert(15, 15);
    bst.insert(7, 7);
    bst.insert(500, 500);
    bst.insert(200, 200);
    
    bst.inOrder();
    
    std::cout << bst.get(500) << std::endl;
    std::cout << bst.get(7) << std::endl;
}
