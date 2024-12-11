#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"
#include "BSNode.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
        BSTree<TableEntry<V>> *tree;

    public:
        BSTreeDict(){
            tree = new BSTree<TableEntry<V>>();
        }
        ~BSTreeDict(){
            delete tree;
            //delete [] tree;??
        }	
        friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
            out<<bs.tree;
            return out;

        }
        V operator[](std::string key){
		return search(key);
        }
        void insert(std::string key, V value) override {
            tree->insert(TableEntry<V>(key,value));
        }
        V search(std::string key) override {
            BSNode<TableEntry<V>>  *aux= tree->search(key);
            if(aux==nullptr)
                throw std::runtime_error("Elemento no encontrado");
            else
                return aux->elem.value;//aux.value?? tiene q devolver el valor o el nodo?
        }
        V remove(std::string key) override{
            TableEntry<V>* aux= tree->search(root, TableEntry<V>(key,V());
            if(aux==nullptr)
                throw std::runtime_error("Elemento no encontrado");
            else
                return tree->remove(*aux);

        }
        int entries() override {
            return tree->size();
            
        }

        
};

#endif
