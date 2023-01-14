#include"Fil.h"
#include<iostream>

using namespace std;


Fil* Fil::Ekle(string renk, string adi, int x, int y) {
    this->renk = renk;
    this->adi = adi;
    this->konum = make_pair(x, y);
    this->puan = 3;
    //cout << "renk " << renk << " Adi " << adi << " X= " << konum.first << " Y= " << konum.second << endl;
    return this;
}



void Fil::print() {
    cout << "renk " << this->renk << " Adi " << this->adi << " X= " << konum.first << " Y= " << konum.second << this->puan << endl;
}

std::pair<int, int> Fil::getKonum()
{
    return konum;
}


void Fil::puanHesapla(Taslar* tas){}

std::string Fil::getAdi()
{
    return this->adi;
}

string Fil::getTakim()
{
    return this->renk;
}

double Fil::getPuan()
{
    return this->puan;
}

void Fil::setPuan(double puan)
{
    this->puan = puan;
}

bool Fil::getTehtitEdildimi()
{
    return this->tehtit_edildimi;
}

void Fil::setTehtitEdildimi()
{
    this->tehtit_edildimi = !this->tehtit_edildimi;
}