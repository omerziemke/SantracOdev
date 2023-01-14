#include"At.h"
#include<iostream>

using namespace std;


At* At::Ekle(string renk, string adi, int x, int y) {
    this->renk = renk;
    this->adi = adi;
    this->konum = make_pair(x, y);
    this->puan = 3;
    //cout << "renk " << renk << " Adi " << adi << " X= " << konum.first << " Y= " << konum.second << endl;
    return this;
}

void At::print() {
    cout << "renk " << this->renk << " Adi " << this->adi << " X= " << konum.first << " Y= " << konum.second << this->puan << endl;
}

void At::puanHesapla( Taslar* tas)
{
    if (this->getTakim() != tas->getTakim() && !tas->getTehtitEdildimi())//Takımlar Farklı ise ve Daha Önce Tehtit Edilmedi İse 
    {
        if (this->getKonum().first - 2 > -1 && this->getKonum().first - 2 < 8 && this->getKonum().second - 1 > -1 && this->getKonum().second - 1 < 8)//At Tahta Dışına Çıkmıyorsa  
        {
            if (tas->getKonum() == make_pair(this->getKonum().first - 2, this->getKonum().second - 1))//Taş At Tarafından Tehtit Edildi mi 
            {
                tas->setPuan(tas->getPuan() * 0.5);//Edildi İse puanını 0,5 ile çarptık 
                tas->setTehtitEdildimi();//Baska Tas Tarafından da Tehtit Edildi İse  onu Engellemek için tehtit_edildimi yi true yaptım
            }
                
        }
        if (this->getKonum().first - 2 > -1 && this->getKonum().first - 2 < 8 && this->getKonum().second + 1 > -1 && this->getKonum().second + 1 < 8)
        {
            if (tas->getKonum() == make_pair(this->getKonum().first - 2, this->getKonum().second + 1))
            {
                tas->setPuan(tas->getPuan() * 0.5);
                tas->setTehtitEdildimi();
            }
        }

        if (this->getKonum().first - 1 > -1 && this->getKonum().first - 1 < 8 && this->getKonum().second - 2 > -1 && this->getKonum().second - 2 < 8)
        {
            if (tas->getKonum() == make_pair(this->getKonum().first - 1, this->getKonum().second - 2))
            {
                tas->setPuan(tas->getPuan() * 0.5);
                tas->setTehtitEdildimi();
            }
        }
        if (this->getKonum().first - 1 > -1 && this->getKonum().first - 1 < 8 && this->getKonum().second + 2 > -1 && this->getKonum().second + 2 < 8)
        {
            if (tas->getKonum() == make_pair(this->getKonum().first - 1, this->getKonum().second + 2))
            {
                tas->setPuan(tas->getPuan() * 0.5);
                tas->setTehtitEdildimi();
            }
        }

        if (this->getKonum().first + 1 > -1 && this->getKonum().first + 1 < 8 && this->getKonum().second - 2 > -1 && this->getKonum().second - 2 < 8)
        {
            if (tas->getKonum() == make_pair(this->getKonum().first + 1, this->getKonum().second - 2))
            {
                tas->setPuan(tas->getPuan() * 0.5);
                tas->setTehtitEdildimi();
            }
        }

        if (this->getKonum().first + 1 > -1 && this->getKonum().first + 1 < 8 && this->getKonum().second + 2 > -1 && this->getKonum().second + 2 < 8)
        {
            if (tas->getKonum() == make_pair(this->getKonum().first + 1, this->getKonum().second + 2))
            {
                tas->setPuan(tas->getPuan() * 0.5);
                tas->setTehtitEdildimi();
            }
        }

        if (this->getKonum().first + 2 > -1 && this->getKonum().first + 2 < 8 && this->getKonum().second - 1 > -1 && this->getKonum().second - 1 < 8)
        {
            if (tas->getKonum() == make_pair(this->getKonum().first + 2, this->getKonum().second - 1))
            {
                tas->setPuan(tas->getPuan() * 0.5);
                tas->setTehtitEdildimi();
            }
        }

        if (this->getKonum().first + 2 > -1 && this->getKonum().first + 2 < 8 && this->getKonum().second + 1 > -1 && this->getKonum().second + 1 < 8)
        {
            if (tas->getKonum() == make_pair(this->getKonum().first + 2, this->getKonum().second + 1))
            {
                tas->setPuan(tas->getPuan() * 0.5);
                tas->setTehtitEdildimi();
            }
        }

    }

}


std::pair<int, int> At::getKonum()
{
    return konum;
}


std::string At::getAdi()
{
    return this->adi;
}

string At::getTakim()
{
    return this->renk;
}

double At::getPuan()
{
    return this->puan;
}

void At::setPuan(double puan)
{
    this->puan = puan;
}

bool At::getTehtitEdildimi()
{
    return this->tehtit_edildimi;
}

void At::setTehtitEdildimi()
{
    this->tehtit_edildimi = !this->tehtit_edildimi;
}