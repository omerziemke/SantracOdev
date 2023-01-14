#include"Sah.h"
#include<iostream>

using namespace std;


Sah* Sah::Ekle(string renk, string adi, int x, int y) {
    this->renk = renk;
    this->adi = adi;
    this->konum = make_pair(x, y);
    this->puan = 100;
    //cout << "renk " << renk << " Adi " << adi << " X= " << konum.first << " Y= " << konum.second << endl;
    return this;
}



void Sah::print() {
    cout << "renk " << this->renk << " Adi " << this->adi << " X= " << this->konum.first << " Y= " << this->konum.second << this-> puan<<endl;
}

void Sah::puanHesapla(Taslar* tas){}

std::pair<int, int> Sah::getKonum()
{
    return konum;
}

std::string Sah::getAdi()
{
    return this->adi;
}

string Sah::getTakim()
{
    return this->renk;
}


double Sah::getPuan()
{
    return this->puan;
}

void Sah::setPuan(double puan)
{
    this->puan = puan;
}

bool Sah::getTehtitEdildimi()
{
    return this->tehtit_edildimi;
}

void Sah::setTehtitEdildimi()
{
    this->tehtit_edildimi = !this->tehtit_edildimi;
}