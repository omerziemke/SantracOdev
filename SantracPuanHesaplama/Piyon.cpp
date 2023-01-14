#include"Piyon.h"
#include<iostream>

using namespace std;

//////////////////////////////Dosyadan Okuduğumuz Deger Piyon İse Vezirin Degerlerini Atadığımız Yer//////////////////////////////////////////
Piyon* Piyon::Ekle(string renk, string adi, int x, int y)
    {
    this->renk = renk;
    this->adi = adi;
    this->konum = make_pair(x, y);
    this->puan = 1;
    //cout << "renk " << renk << " Adi " << adi << " X= " << konum.first << " Y= " << konum.second << endl;
    return this;
}

//////////////////////////////Nesne Piyon İse Bu print() Fonksiyonu Çagrılır//////////////////////////////////////////
void Piyon::print() {
    cout << "renk " << this->renk << " Adi " << this->adi << " X= " << konum.first << " Y= " << konum.second << this->puan << endl;
}


//////////////////////////////Gelen Tas Piyon Yörüngesinde mi Kontrolü Yapılır //////////////////////////////////////////
void Piyon::puanHesapla( Taslar* tas)
{
    
    if (this->getTakim() != tas->getTakim() && !tas->getTehtitEdildimi())//Takımlar Farklı ise ve Daha Önce Tehtit Edilmedi İse 
    {
        if (this->getTakim() == "s")//Piyon siyah mı 
        {
            if ((this->getKonum().first + 1 < 8) && (this->getKonum().second + 1 < 8))//Piyon Tahta Dışına Çıkmıyorsa  
            {
                if (tas->getKonum() == make_pair(this->getKonum().first + 1, this->getKonum().second + 1))//Taş Piyon Tarafından Tehtit Edildi mi 
                {
                    tas->setPuan(tas->getPuan() * 0.5);//Edildi İse puanını 0,5 ile çarptık 
                    tas->setTehtitEdildimi();//Baska Tas Tarafından da Tehtit Edildi İse  onu Engellemek için tehtit_edildimi yi true yaptım
                }

            }

            if ((this->getKonum().first + 1 < 8) && (this->getKonum().second - 1 > -1))//Piyon Tahta Dışına Çıkmıyorsa  
            {
                if (tas->getKonum() == make_pair(this->getKonum().first + 1, this->getKonum().second - 1) )//Taş Piyon Tarafından Tehtit Edildi mi 
                {
                    tas->setPuan(tas->getPuan() * 0.5);//Edildi İse puanını 0,5 ile çarptık 
                    tas->setTehtitEdildimi();//Baska Tas Tarafından da Tehtit Edildi İse  onu Engellemek için tehtit_edildimi yi true yaptım
                }

            }

        }


        else
        {
            if (this->getKonum().first - 1 > -1 && this->getKonum().second - 1 > -1 )//Piyon Tahta Dışına Çıkmıyorsa  
            {
                if (tas->getKonum() == make_pair(this->getKonum().first - 1, this->getKonum().second - 1))//Taş Piyon Tarafından Tehtit Edildi mi 
                {
                    tas->setPuan(tas->getPuan() * 0.5);//Edildi İse puanını 0,5 ile çarptık 
                    tas->setTehtitEdildimi();//Baska Tas Tarafından da Tehtit Edildi İse  onu Engellemek için tehtit_edildimi yi true yaptım
                }

            }
            if (this->getKonum().first - 1 > -1 && this->getKonum().second + 1 < 8 )//Piyon Tahta Dışına Çıkmıyorsa  
            {
                if (tas->getKonum() == make_pair(this->getKonum().first - 1, this->getKonum().second + 1))//Taş Piyon Tarafından Tehtit Edildi mi 
                {
                    tas->setPuan(tas->getPuan() * 0.5);//Edildi İse puanını 0,5 ile çarptık 
                    tas->setTehtitEdildimi();//Baska Tas Tarafından da Tehtit Edildi İse  onu Engellemek için tehtit_edildimi yi true yaptım
                }

            }
        }
    }

}


//////////////////////////////Piyonun Konumunu Döner//////////////////////////////////////////
std::pair<int, int> Piyon::getKonum()
{
    return konum;
}


//////////////////////////////Piyonun Adını Döner//////////////////////////////////////////

std::string Piyon::getAdi()
{
    return this->adi;
}


//////////////////////////////Piyonun Takımını Döner//////////////////////////////////////////
string Piyon::getTakim()
{
    return this->renk;
}


//////////////////////////////Piyonun Puanını Döner//////////////////////////////////////////
double Piyon::getPuan()
{
    return this->puan;
}


//////////////////////////////Piyonun Puanını Set Eder//////////////////////////////////////////
void Piyon::setPuan(double puan)
{
    this->puan = puan;
}


//////////////////////////////Vezir Daha Önce Baska Tas Tarafından Tehtit Edildi mi Kontrolü Yapmak için Oluşturuldu //////////////////////////////////////////
bool Piyon::getTehtitEdildimi()
{
    return this->tehtit_edildimi;
}


//////////////////////////////Vezir Daha Önce Baska Tas Tarafından Tehtit Edilmedi ise Tettit Edildi fonksiyonu Çagrılacak //////////////////////////////////////////
void Piyon::setTehtitEdildimi()
{
    this->tehtit_edildimi = !this->tehtit_edildimi;
}