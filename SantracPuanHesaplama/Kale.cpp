#include"Kale.h"
#include<iostream>

using namespace std;


Kale* Kale::Ekle(string renk, string adi, int x, int y) {
    this->renk = renk;
    this->adi = adi;
    this->konum = make_pair(x, y);
    this->puan = 5;
    //cout << "renk " << renk << " Adi " << adi << " X= " << konum.first << " Y= " << konum.second << endl;
    return this;
}


void Kale::print() {
    
    cout << "renk " << this->renk << " Adi " << this->adi << " X= " << konum.first << " Y= " << konum.second << this->puan << endl;
}


void Kale::puanHesapla( Taslar* tas){}


std::pair<int, int> Kale::getKonum()
{
    return konum;
}


std::string Kale::getAdi()
{
    return this->adi;
}

string Kale::getTakim()
{
    return this->renk;
}

double Kale::getPuan()
{
    return this->puan;
}

void Kale::setPuan(double puan)
{
    this->puan = puan;
}

bool Kale::getTehtitEdildimi()
{
    return this->tehtit_edildimi;
}

void Kale::setTehtitEdildimi()
{
    this->tehtit_edildimi = !this->tehtit_edildimi;
}