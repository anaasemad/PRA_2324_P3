#ifndef BSTREEDICT_
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
        }	
        friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
            out<<*bs.tree;
            return out;

        }
        V operator[](std::string key){
		return search(key);
        }
        void insert(std::string key, V value) override {
            tree->insert(TableEntry<V>(key,value));
        }
        V search(std::string key) override {
		TableEntry<V> aux1(key);
		TableEntry<V> aux2=tree->search(aux1);
			V resp=aux2.value;
			return resp;
        }
        V remove(std::string key) override{
		TableEntry<V> aux(key);
		V resp=search(key);
		tree->remove(aux);
		return resp;
        }
        int entries() override {
            return tree->size();
            
        }

        
};

#endif
