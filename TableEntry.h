#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V> 
class TableEntry {
    public:
        // miembros públicos
        std::string key;
        V value;

        TableEnty(std::string key, V value){
            
        }
        TableEntry(std::string key){

        }
        TableEntry(){

        }
        friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2){

        }
        friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te){

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