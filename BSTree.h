#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T> 
class BSTree {
    private:
        int nelem;//num elementos almacenados en ABB
        BSNode<T> *root;//raiz de ABB
        BSNode<T>* search(BSNode<T>* n, T e) const{
            if(n==nullptr)
                return std::runtime_error("Elemento no encontrado");
            if(n.elem<e)
                return search(n->right,e);
            if(n.elem>e)
                return search(n->left,e);
            else
                return n;
        }
        BSNode<T>* insert(BSNode<T>* n, T e){
            if(n==nullptr)
                return new BSNode<T>(e);
            if(n.elem==e)
                return std::runtime_error("Ya existe");
            if(n.elem<e)
                n->right=insert(n->right,e);
            else
                n->left=insert(n->left,e);
            return n;
        }
        void print_inorder(std::ostream &out, BSNode<T>* n) const{//revisar
            if(n!=nullptr){
                print_inorder(out,n->left);
                out << n->elem << " ";
                print_inorder(out,n->right);
            }
        }
        BSNode<T>* remove(BSNode<T>* n, T e){

        }
        T max(BSNode<T>* n) const{

        }
        BSNode<T>* remove_max(BSNode<T>* n){

        }
        void delete_cascade(BSNode<T>* n){

        }

    public:
        BSTree(){
            nelem=0;
            root=nullptr;
        }
        int size() const{
            return nelem;
        }
        T search(T e) const{
            return search(root,e).elem;

        }
        T operator[](T e) const{
            return search(e);
        }
        void insert(T e){
            insert(root,e);
        }
        friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
            print_inorder(out, bst.root);
            return out;
        }
        void remove(T e){
            remove(root,e);
        }
        ~BSTree(){
            delete_cascade(root);
        }
};

#endif