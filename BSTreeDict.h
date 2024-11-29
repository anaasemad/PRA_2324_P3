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

        }
        ~BSTreeDict(){

        }	
        friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){

        }
        V operator[](std::string key){

        }
        void insert(std::string key, V value){

        }
        V search(std::string key){

        }
        V remove(std::string key){

        }
        int entries(){
            
        }

        
};

#endif