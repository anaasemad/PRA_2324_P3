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

        TableEnty(std::string k, V val){
            key = k;
            value = val;
        }
        TableEntry(std::string k){
            key = k;
        }
        TableEntry(){
            key="";
        }
        friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2){
            if(te1.key == te2.key){
                return true;
            }
            else return false;

        }
        friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2){
            if(te1.key == te2.key){
                return false;
            }
            else return true;

        }
        friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te){
            out << te.key << "-> " << te.value;
            return out;

        }
};

#endif