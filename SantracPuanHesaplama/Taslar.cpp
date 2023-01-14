#include"Taslar.h"
#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include"Piyon.h"
#include"At.h"
#include"Kale.h"
#include"Fil.h"
#include"Vezir.h"
#include"Sah.h"
#include<iterator>
#include<initializer_list>
#include <sstream>
#include <utility>

using namespace std;



vector<Taslar*> Taslar::dosyaVeriCek()
{

    std::string filename = "C:/Users/ELVAN/source/repos/SantracPuanHesaplama/OrnekVeriler/board3.txt";
        vector<Taslar*> taslarim;

        string satir = "";
        string kelime = "";
        size_t index_satir = 0, index_sutun = 0;
        std::ifstream dosyaOku{ filename };
        if (!dosyaOku)
        {
            cout << "Dosya Acilamiyor\n";
        }
        else
        {
            while (std::getline(dosyaOku, satir, '\n'))//Dosyadan Satırı Okudu
            {

                index_sutun = 0;
                std::istringstream iss(satir);
                while (std::getline(iss, kelime, ' '))//Satırı Kelimelere ayırdık
                {

                    if (kelime != "--")
                    {
                        if (kelime.substr(0, 1) == "p")//Eger Kelimenin ilk harfi p ise  yani okunan deger piyon ise 
                        {
                            Piyon* myPiyon = new Piyon;//Piyon Nesnesi Oluşturuldu
                            myPiyon->Ekle(kelime.substr(1, 1), kelime.substr(0, 1), index_satir, index_sutun);//Piyon Nesnesinin Ekle Fonk Cagrıldı fonksiyona renk,adı,x konumu ,y konumu gönderildi 
                            taslarim.push_back(myPiyon);//Vectore yüklendi
                            
                        }

                        else if (kelime.substr(0, 1) == "a")//Eger Kelimenin ilk harfi a ise yani okunan deger at ise 
                        {
                            At* myAt = new At;
                            myAt->Ekle(kelime.substr(1, 1), kelime.substr(0, 1), index_satir, index_sutun);//At Nesnesinin Ekle Fonk Cagrıldı fonksiyona renk,adı,x konumu ,y konumu gönderildi 
                            taslarim.push_back(myAt);
                            //myAt.print();
                        }

                        else if (kelime.substr(0, 1) == "k")//Eger Kelimenin ilk harfi k ise yani okunan deger kale ise 
                        {
                            Kale* myKale = new Kale;
                            myKale->Ekle(kelime.substr(1, 1), kelime.substr(0, 1), index_satir, index_sutun);//Kale Nesnesinin Ekle Fonk Cagrıldı fonksiyona renk,adı,x konumu ,y konumu gönderildi 
                            taslarim.push_back(myKale);
                            //myKale.print();
                        }
                        else if (kelime.substr(0, 1) == "f")//Eger Kelimenin ilk harfi f ise yani okunan deger fil ise 
                        {
                            Fil* myFil = new Fil;
                            myFil->Ekle(kelime.substr(1, 1), kelime.substr(0, 1), index_satir, index_sutun);//Fil Nesnesinin Ekle Fonk Cagrıldı fonksiyona renk,adı,x konumu ,y konumu gönderildi 
                            taslarim.push_back(myFil);
                            //myFil.print();
                        }
                        else if (kelime.substr(0, 1) == "v")//Eger Kelimenin ilk harfi v ise yani okunan deger vezir ise 
                        {
                            Vezir* myVezir = new Vezir;
                            myVezir->Ekle(kelime.substr(1, 1), kelime.substr(0, 1), index_satir, index_sutun);//Vezir Nesnesinin Ekle Fonk Cagrıldı fonksiyona renk,adı,x konumu ,y konumu gönderildi 
                            taslarim.push_back(myVezir);
                            //myVezir.print();
                        }
                        else if (kelime.substr(0, 1) == "s")//Eger Kelimenin ilk harfi s ise yani okunan deger sah ise 
                        {
                            Sah* mySah = new Sah;
                            mySah->Ekle(kelime.substr(1, 1), kelime.substr(0, 1), index_satir, index_sutun);//Sah Nesnesinin Ekle Fonk Cagrıldı fonksiyona renk,adı,x konumu ,y konumu gönderildi 
                            taslarim.push_back(mySah);
                            //mySah.print();
                        }
                        //tas.print();



                    }index_sutun++;//Sütun bilgisi tutuluyor

                }index_satir++;//satır bilgisi tutuluyor
            }



        }

        return taslarim;
}




Taslar* Taslar::Ekle(string renk, string adi, int x, int y) {
    this->renk = renk;
    this->adi = adi;
    this->konum = make_pair(x, y);
    //cout << "renk " << renk << " Adi " << adi << " X= " << konum.first << " Y= " << konum.second << endl;
    return this;
}


void Taslar::print() {

    cout << "renk " << renk << " Adi " << adi << " X= " << konum.first << " Y= " << konum.second << endl;
}

std::pair<int, int> Taslar::getKonum()
{
    return make_pair(-1, -1);
}

void Taslar::puanHesapla(Taslar* tas){}


string Taslar::getAdi()
{
    return this->adi;
}


string Taslar::getTakim()
{
    return this->renk;
}

double Taslar::getPuan(){
    return this->puan;
}

void Taslar::setPuan(double puan)
{
    this->puan = puan;
}


bool Taslar::getTehtitEdildimi()
{
    return this->tehtit_edildimi;
}

void Taslar::setTehtitEdildimi()
{
    this->tehtit_edildimi= !this->tehtit_edildimi;
}