/**
* @file avlagaci
* @description agac
* @course 1-A
* @assignment final
* @date 01.09.2020
* @author Yasin Güllü
*/
#ifndef avlagaci_hpp
#define avlagaci_hpp

#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include "node.hpp"
#include "Kisi.hpp"

class avlagaci {
private:
    node* bas;
    int yedek = 0;
    int hareketsayisi = 0;
    int eskidugumsayisi = 0;
    node* head;
    int levelvariable = 0;
    int islemsayisi = 0;

public:
    int height(node*);
    node* r_rotat(node*);
    node* l_rotat(node*);
    node* insert(node*, int, kisi);
    void ekle(int, kisi);
    void assignoldlevel(node*);
    void printoldlevel(node*, int);
    void assignnewlevel(node*);
    void printnewlevel(node*, int);
    
    void postorder(node*);
    void postorder();
    
    void dugumhareketleri(node*, int);



    void assignheight(node*);
    void assignnewheight(node*);

    void esitle(node*);
    void removetree(node*);
    bool bosmu();
    void temizle();
    avlagaci();
    ~avlagaci();
};

#endif