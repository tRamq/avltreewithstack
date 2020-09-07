/**
* @file node
* @description dugum 
* @course 1-A
* @assignment 2.ÖDEV FİNAL
* @date 01.09.2020
* @author Yasin Güllü
*/
#include "node.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>



node::node(kisi kis) {
	
	s = new Stack();
	s->stackelemanEkle('O');
	
	k = new kisi();
	k->dogumtarihi=kis.dogumtarihi;
	k->isim=kis.isim;
	k->kilo=kis.kilo;
	
}

node::~node(){
	delete s;
	delete k;
}
void node::Yharfi() {
	s->stackelemanEkle('Y');
}

void node::Dharfi() {
	s->stackelemanEkle('D');
}

void node::Aharfi() {
	s->stackelemanEkle('A');
}



void node::display() {
	std::cout<<k->isim<<","<<k->dogumtarihi<<","<<k->kilo;
	std::cout <<" Yigit.: "<< std::setw(4);
	s->stackYaz();
	std::cout<<std::endl;
	
}


