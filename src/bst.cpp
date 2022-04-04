#include "bst.h"



BST::Node::Node(int value, Node* left, Node* right){
    this->value = value;
    this->left = left;
    this->right = right;
}
BST::Node::Node(){
    
    this->value = 0;
    this->left = nullptr;
    this->right = nullptr;

}

BST::Node::Node(const Node& node){

    this->value = node.value;
    this->left = node.left;
    this->right = node.right;
}

BST::Node*& BST::get_root(){
    return root;
}
std::ostream& operator<<(std::ostream& stream, const BST::Node& node){

    stream << "adress of node: "<<&node<<std::endl;
    return stream;
}
bool operator<(int data, const BST::Node& node){

    if(data < node.value){
        return true;
    }
    return false;
}
bool operator>(int data, const BST::Node& node){

    if(data > node.value){
        return true;
    }
    return false;
}
bool operator==(int data, const BST::Node& node){

    if(data == node.value){
        return true;
    }
    return false;
}
bool operator<=(int data, const BST::Node& node){

    if(data <= node.value){
        return true;
    }
    return false;
}
bool operator>=(int data, const BST::Node& node){

    if(data >= node.value){
        return true;
    }
    return false;
}
bool operator<(const BST::Node& node, int data){

    if(node.value < data){
        return true;
    }
    return false;
}
bool operator>(const BST::Node& node, int data){

    if(node.value > data){
        return true;
    }
    return false;
}
bool operator==(const BST::Node& node, int data){

    if(node.value == data){
        return true;
    }
    return false;
}
bool operator<=(const BST::Node& node, int data){

    if(node.value <= data){
        return true;
    }
    return false;
}
bool operator>=(const BST::Node& node, int data){

    if(node.value >= data){
        return true;
    }
    return false;
}
/*void BST::bfs(std::function<void(Node*& node)> func){

    

}


/*size_t BST::length(){

size_t cnt{},i{};
BST::Node* temp{root},temp_R{root},temp_L{root};
if(temp == nullptr){
    return 0;
}
else{
    while(temp != nullptr){
        cnt++;
        temp_R = temp_R->right;
            while(temp_R != nullptr){
            cnt++;
            temp_R = temp_R->right;
            temp_L = temp;
            while(temp_L != nullptr){
            cnt++;
            temp_L = temp_L->left;
        }
        }
            while(temp_L->left != nullptr){
            cnt++;
            temp_L = temp_L->left;
        }
}
}
*/
bool BST::add_node(int value){

if(root == nullptr){
    root = new Node(value,nullptr,nullptr);
    return true;
}   

BST::Node* temp{root};
while(true){
    
        if(value == temp->value){
            return false;
        }
        if(value > temp->value){
            if(temp->right == nullptr){
            temp->right = new Node(value,nullptr,nullptr);
            temp = temp->right;
            }
            else {
                temp = temp->right;
            }
            
        }
        else if(value < temp->value){
            if(temp->left == nullptr){
            temp->left = new Node(value,nullptr,nullptr);
            temp = temp->left;
            }
            else{
                temp = temp->left;
            }
        }
        
}
return true;
}
BST::Node** BST::find_node(int value){

BST::Node** temp{&root};

while(true){

 if((*temp)->value == value){
     return temp;
 }
 else if((*temp)->value < value){
     if((*temp)->right == nullptr){
         return nullptr;
     }
     temp = &(*temp)->right;
 }

 else{
     if((*temp)->left == nullptr){
         return nullptr;
     }
     temp = &(*temp)->left;
 }

}


}
BST::Node** BST::find_parrent(int value){
    BST::Node** temp{&root};

if(value == (*temp)->value){
    return nullptr;
}

while(true){

 if((*temp)->right->value == value || (*temp)->left->value == value){
     return temp;
 }
 else if((*temp)->value < value){
     if((*temp)->right == nullptr){
         return nullptr;
     }
     temp = &(*temp)->right;
 }

 else{
     if((*temp)->left == nullptr){
         return nullptr;
     }
     temp = &(*temp)->left;
 }

}




}
BST::Node** BST::find_successor(int value){

BST::Node** temp{find_node(value)};
if((*temp)->left == nullptr){
    return temp;
}
if((*temp)->left->right == nullptr){
    return &(*temp)->left;
}
    if((*temp)->left != nullptr){
        temp = &(*temp)->left;
    }
    while(true){
        if((*temp)->right != nullptr){
        temp = &(*temp)->right;
    }
    else{
        return temp;
    }
    }
    
}
/*bool BST::delete_node(int value){

BST::Node** temp{find_node(value)},suc{};
if((*temp)->right == nullptr && (*temp)->left == nullptr){
    delete(*temp);
    return true;
}
        
if((*temp)->right == nullptr && (*temp)->left != nullptr){
    temp = &(*temp)->left;
    delete((*temp)->left);
    return true;

}

if((*temp)->right != nullptr && (*temp)->left == nullptr){
    temp = &(*temp)->right;
    delete((*temp)->right);
    return true;

}
if((*temp)->right != nullptr && (*temp)->left != nullptr){
    suc = find_successor(value);
    temp = suc;
    delete(suc);
    return true;

}

return false;

}
/*BST::~BST()
 {
 	std::vector<Node*> nodes;
 	bfs([&nodes](BST::Node*& node){nodes.push_back(node);});
 	for(auto& node: nodes)
 		delete node;
 }*/

/* std::ostream& operator<<(std::ostream& stream, const BST& bst){

    stream << "********************************************************************************"<<std::endl<<&bst<<"       => "<<bst.value<<"        "<<bst.left<<"        "<<bst.right<<std::endl;
    stream <<"binary search tree size:  "<<bst.length()<<std::endl<<"********************************************************************************";
    return stream;
 }*/
