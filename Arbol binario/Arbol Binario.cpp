#include <iostream>
//#include <conio.h>

using namespace std;

class vertex{
public:
    int data;
    vertex * left;
    vertex * right;

    vertex(int val) : data(val), left(NULL), right(NULL){}
    
};

void imprime_in(vertex *v){
    if(v == nullptr){
        return;
    }
    imprime_in(v->left);
    cout<<v->data<<endl;
    imprime_in(v->right);
}

void imprime_pre(vertex *v){
    if(v == nullptr){
        return;
    }
    cout<<v->data<<endl;
    imprime_pre(v->left);
    imprime_pre(v->right);
}

void imprime_post(vertex *v){
    if(v == nullptr){
        return;
    }
    imprime_post(v->left);
    imprime_post(v->right);
    cout<<v->data<<endl;
}

int main()
{
    vertex *root = new vertex(10);
    root->left = new vertex(5);
    root->right = new vertex(15);
    root->left->left = new vertex(3);
    root->left->right = new vertex(7);
    root->right->left = new vertex(13);
    root->right->right = new vertex(17);
    root->right->right->right = new vertex(19);
    imprime_pre(root); 
    cout<<endl;
    imprime_in(root); 
    cout<<endl;
    imprime_post(root); 
    return 0;
}