/**
* @file avltree
* @description agac
* @course 1-A
* @assignment  FİNAL
* @date 25.08.2020
* @author Yasin Güllü
*/
#ifndef node_hpp
#define node_hpp
#include "stack.hpp"
#include "Kisi.hpp"


class node {
public:
    int d;
    node* l;
    node* r;
    kisi *k; 

    Stack *s;

   
    
    int eskiyukseklik = 0;
     int yeniyukseklik = 0;
     int ds = 0;
     int eskilevel = 0;
     int yenilevel = 0;
     bool tek = false;
     

     void display();


    node(kisi);
    ~node();
   
    void Yharfi();
    void Aharfi();
    void Dharfi();
    void pop();

};

#endif