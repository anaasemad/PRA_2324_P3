#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "C:\Users\anaas\Desktop\Ana\GIIROB\2º\Programación Avanzada\practicas\PRA_2425_P1\ListLinked.h" // ¡¡¡¡MODIFICAR!!!!
//template < class T, class Alloc = allocator<T> > class list; //En el caso de que no funcione mi ListLinked.h
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
                c=at(key[i]);
                sum+=(int)c;
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
            if(!key){
                return std::runtime_error("Error en key");}
            else{
                int pos=h(key);
                return table[pos].value;}
        }
        void insert(std::string key, V value){
            int pos=h(key);
            if(table[pos].valor!=NULL)
                return std::runtime_error("Key ocupada");
            if(n==max)
                return std::runtime_error("Tabla llena");
            else{
                table[pos].key=key;
                table[pos].value=value;
                n++;
            }
        }
        V search(std::string key){
            int pos=h(key);
            if(table[pos].key==key)
                return table[pos].value;
            else
                return std::runtime_error("Key no encontrada");
        }
        V remove(std::string key){
            int pos=h(key);
            if(table[pos].key==key){
                V aux=table[pos].value;
                table[pos].key="";
                table[pos].value=NULL;
                n--;
                return aux;
            }else
                return std::runtime_error("Key no encontrada");

        }
        int entries(){
            return capacity();
        }
};

#endif