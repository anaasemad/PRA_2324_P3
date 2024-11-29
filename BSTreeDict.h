#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
        BSTree<TableEntry<V>>* tree;

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
        void insert(std::string key, V value){
            tree.insert(TalbeEntry(key,value));
        }
        V search(std::string key){
            TableEntry<T> aux= tree.search(key);
            if(aux==nullptr)
                return std::runtime_error("Elemento no encontrado");
            else
                return aux;//aux.value?? tiene q devolver el valor o el nodo?
        }
        V remove(std::string key){
            TableEntry<T> aux= tree.search(key);
            ir(aux==nullptr)
                return std::runtime_error("Elemento no encontrado");
            else
                return tree.remove(aux);
 

        }
        int entries(){
            return tree.size();
            
        }

        
};

#endif