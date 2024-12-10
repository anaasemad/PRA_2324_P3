#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
#include <list>
#include <memory>
#include "../PRA_2425_P1/ListLinked2.h"
//template < class T, class Alloc = allocator<T> > class list; //En el caso de que no funcione mi ListLinked.h
//std::list<T>
template <typename V>
class HashTable: public Dict<V> {

    private:
        int n;
        int max;
        ListLinked<TableEntry<V>>* table;
        int h(std::string key){
            int sum=0;
            char c;
            for(int i=0;i<key.size();i++){
                sum+=(int)key[i];
            }
            return sum%n; 
        }

    public:
        HashTable(int size){
            table=new ListLinked<TableEntry<V>>[size];
            max=size;
            n=0;
        }
        ~HashTable(){
            delete[] table;
        }
        int capacity(){
            return n;
        }
        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
            for(int i=0;i<th.max;i++){
                out << th.table[i] << "\n";
            }
            return out;

        }
        V operator[](std::string key){
            if(key==" "){
                throw std::runtime_error("Error en key");}
            else{
                int pos=h(key);
		int postable=table[pos].search(key);
                return table[pos][postable].value;}
        }
        void insert(std::string key, V value){
            int pos=h(key);
            if(table[pos].search(key)!=-1)
                throw std::runtime_error("Key ocupada");
            if(n==max)
                throw std::runtime_error("Tabla llena");
            else{
                TableEntry<V> nueva(key, value);
                table[pos].insert(0, nueva);
                n++;
            }
        }
        V search(std::string key){
            int pos=h(key);
	    int postable=table[pos].search(key);
            if(postable!=-1)
                return table[pos][postable].value;
            else
                throw std::runtime_error("Key no encontrada");
        }
        V remove(std::string key){
            int pos=h(key);
	    int postable=table[pos].search(key);
            if(postable!=-1){
                V aux=table[pos][postable].value;
                table[pos].remove(postable);
                n--;
                return aux;
            }else
                throw std::runtime_error("Key no encontrada");

        }
        int entries(){
            return capacity();
        }
};

#endif
