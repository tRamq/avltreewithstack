/**
* @file test
* @description main
* @course 1-A
* @assignment  FİNAL
* @date 25.08.2020
* @author yasin güllü
*/
#include<iostream>
#include<cstdio>
#include<sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Kisi.hpp"
#include "avlagaci.hpp"
#include<algorithm>
using namespace std;


int main() {
	
	
	kisi k;

	avlagaci agac;

	ifstream dosya("Kisiler.txt", ios::in);
    ifstream file("Kisiler.txt", ios::in);
	  int sayi;
    int sayac = 0;

	std::string satir;
	int satirsayisi=0;


	string line;
    if (dosya.is_open())
    {
        while (getline(dosya, line))
        {
			
			file>> satir;
			
		std::string delimiter = "#";

		size_t pos = 0;
		std::string token;
		pos = satir.find(delimiter);
   	 	token = satir.substr(0, pos);
		k.isim=token;
    	
    	satir.erase(0, pos + delimiter.length());
		pos = satir.find(delimiter);
		token = satir.substr(0, pos);
		k.dogumtarihi=std::stoi(token);
	
		satir.erase(0, pos + delimiter.length());
		pos = satir.find(delimiter);
		token = satir.substr(0, pos);
		k.kilo=std::stoi(token);

		agac.ekle(k.dogumtarihi,k);

	
		}
	}
	


	
	agac.postorder();


	
	


	return 0;
}