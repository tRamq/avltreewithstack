/**
* @file avltree
* @description agac
* @course 1-A
* @assignment FiNAL
* @date 01.09.2020
* @author Yasin Güllü
*/
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include "node.hpp"
#include "avlagaci.hpp"


avlagaci::avlagaci() {
     head = NULL;
     bas = NULL;
   
}


void avlagaci::temizle() {
    removetree(bas);
}

void avlagaci::postorder(node* dugum) {
    if (dugum == NULL)
        return;
    postorder(dugum->l);
    postorder(dugum->r);

    dugum->display();

    
    std::cout << std::endl;

}

void avlagaci::postorder() {
    postorder(bas);

}

void avlagaci::removetree(node* Ptr)
{
    if(Ptr != NULL)
    {
        if(Ptr->l !=NULL)
        {
            removetree(Ptr->l);
        }
        if(Ptr->r != NULL)
        {
            removetree(Ptr->r);
        }
        delete Ptr;

    }
   
}


int avlagaci::height(node* dugum) {
  
    if (dugum == NULL) {
        return -1;
    }
    return 1 + std::max(height(dugum->l), height(dugum->r));
}

node* avlagaci::r_rotat(node* parent) {

    node* t;
    t = parent->r;
    parent->r = t->l;
    t->l = parent;

    parent->yeniyukseklik = height(parent);
    t->yeniyukseklik = std::max(height(t->r), parent->yeniyukseklik) + 1;

    return t;
}
node* avlagaci::l_rotat(node* parent) {

    node* t;
    t = parent->l;
    parent->l = t->r;
    t->r = parent;

    parent->yeniyukseklik = height(parent);
    t->yeniyukseklik = std::max(height(t->l), parent->yeniyukseklik) + 1;

    return t;
}

void avlagaci::dugumhareketleri(node* nod, int data) {
    if (nod == NULL) {

        return;
    }


     if (nod->yenilevel < nod->eskilevel && nod->yeniyukseklik == nod->eskiyukseklik)
    {
        nod->Yharfi();
        dugumhareketleri(nod->l, data);
        dugumhareketleri(nod->r, data);
    }

     else if (nod->yenilevel > nod->eskilevel && nod->yeniyukseklik < nod->eskiyukseklik)
    {
        nod->Aharfi();
        dugumhareketleri(nod->l, data);
        dugumhareketleri(nod->r, data);

    }
     else if (nod->yenilevel > nod->eskilevel && nod->yeniyukseklik == nod->eskiyukseklik)
    {
        if(nod->eskilevel !=0)
        nod->Aharfi();
        dugumhareketleri(nod->l, data);
        dugumhareketleri(nod->r, data);

    }


    else if ( nod->yeniyukseklik > nod->eskiyukseklik && nod->yenilevel < nod->eskilevel )
    {
        nod->Yharfi();
        dugumhareketleri(nod->l, data);
        dugumhareketleri(nod->r, data);
    }

    else if ((nod->yeniyukseklik > nod->eskiyukseklik) &&nod->yenilevel == nod->eskilevel ) {

        nod->Dharfi();
        dugumhareketleri(nod->l, data);
        dugumhareketleri(nod->r, data);

    }

    else if (  nod->yeniyukseklik == nod->eskiyukseklik && nod->yenilevel == nod->eskilevel)
    {

        nod->Dharfi();
        dugumhareketleri(nod->l, data);
        dugumhareketleri(nod->r, data);

    }


   
    else
    {
        dugumhareketleri(nod->l, data);
        dugumhareketleri(nod->r, data);
    }





}

void avlagaci::printoldlevel(node* t, int level) {///////// agactaki tüm dugumleri gezerek dugumlerin hangi seviyede oldugunu dugum icinde tutar.

    if (t == NULL) {
        return;
    }
    if (level == 0) {
        t->eskilevel = levelvariable;

    }
    else {

        printoldlevel(t->l, level - 1);
        printoldlevel(t->r, level - 1);

    }

}

void avlagaci::printnewlevel(node* dgm, int level) {

    if (dgm == NULL) {
        return;
    }
    if (level == 0) {
        dgm->yenilevel = levelvariable;

    }
    else {

        printnewlevel(dgm->l, level - 1);
        printnewlevel(dgm->r, level - 1);

    }

}

void avlagaci::assignheight(node* nod)
{
    if (nod == NULL) {
        return;
    }

    nod->eskiyukseklik = height(nod);
    assignheight(nod->r);
    assignheight(nod->l);
    

}

void avlagaci::assignnewheight(node* nod)
{
    if (nod == NULL) {
        return;
    }

    nod->yeniyukseklik = height(nod);
    assignnewheight(nod->r);
    assignnewheight(nod->l);
    

}

void avlagaci::esitle(node* y)
{
    if (y == NULL) {
        return;
    }
    y->eskiyukseklik = y->yeniyukseklik;
    y->eskilevel = y->yenilevel;
    esitle(y->l);
    esitle(y->r);

}

void avlagaci::assignoldlevel(node* y)
{
    for (int level = 0; level <= y->eskiyukseklik; level++) {
        levelvariable = level;
        printoldlevel(y, level);

    }
}

void avlagaci::assignnewlevel(node* y)
{
    for (int level = 0; level <= y->yeniyukseklik; level++) {
        levelvariable = level;
        printnewlevel(y, level);

    }
}

node* avlagaci::insert(node* r, int v, kisi k) {


        v=2020-k.dogumtarihi;
    if (r == NULL) {//eğer kök boşsa yeni kök olarak ekler
        r = new node(k);
        r->d = v;
        r->l = NULL;
        r->r = NULL;
        r->eskiyukseklik = 0;
        eskidugumsayisi++;
     
    }



    else if (v <= r->d)//küçükse sola eklenir.
    {

        r->l = insert(r->l, v, k); //sol alt çocuk yerine yeni bir ağaç oluşturur
        if (height(r->l) - height(r->r) == 2) {//yükseklik farkı birden büyükse dengeler
                // Sol Sol Durumu 
            if (v <= r->l->d)
                r = l_rotat(r);//tek dönüş
            else { //Sol Sağ Durumu
                r->l = r_rotat(r->l); //çift dönüş
                r = l_rotat(r);
            }

        }
    }

    else if (v > r->d) {//büyükse sağa ekler, sağ durumu
        r->r = insert(r->r, v, k);

        if (height(r->r) - height(r->l) == 2) {
            if (v > r->r->d)// Sağ Sağ Durumu
                r = r_rotat(r);//Tek dönüş
            else {// Sağ Sol Durumu 
                r->r = l_rotat(r->r);//çift dönüş
                r = r_rotat(r);
            }

        }


    }
    return r;
}

void avlagaci::ekle(int data, kisi k) {

    if (bas!=NULL && (bas->r !=NULL || bas->l !=NULL )) {
        head = bas;
       assignheight(bas);
        assignoldlevel(bas);
    }
    bas = insert(bas, data, k);
    if (bas!=NULL && (bas->r !=NULL || bas->l !=NULL )) {
        assignnewheight(bas);
        assignnewlevel(bas);
        dugumhareketleri(bas, bas->d);
        esitle(bas);
        head = bas;




    }

}




avlagaci::~avlagaci() {
    temizle();
}
