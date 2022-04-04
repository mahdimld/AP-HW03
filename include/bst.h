#ifndef BST_H
#define BST_H

#include <iostream>
#include <functional>

class BST
{
public:
class Node
{
public:
	Node(int value, Node* left, Node* right);
	Node();
	Node(const Node& node);
    friend std::ostream& operator<<(std::ostream& stream, const BST::Node& node);
    friend bool operator<(int data, const BST::Node& node);
    friend bool operator>(int data, const BST::Node& node);
    friend bool operator==(int data, const BST::Node& node);
    friend bool operator<=(int data, const BST::Node& node);
    friend bool operator>=(int data, const BST::Node& node);
    
    friend bool operator<(const BST::Node& node, int data);
    friend bool operator>(const BST::Node& node, int data);
    friend bool operator==(const BST::Node& node, int data);
    friend bool operator<=(const BST::Node& node, int data);
    friend bool operator>=(const BST::Node& node, int data);


	int value;
	Node* left;
	Node* right;
};
    Node*& get_root();
    void bfs(std::function<void(Node*& node)> func);
    size_t length();
    bool add_node(int value);
    Node** find_node(int value);
    Node** find_parrent(int value);
    Node** find_successor(int value);
    bool delete_node(int value);
    //std::ostream& operator<<(std::ostream& stream, const BST& bst);

private:
    Node* root;
};


#endif //BST_H