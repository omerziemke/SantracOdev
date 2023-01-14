#include"Vezir.h"
#include<iostream>

using namespace std;

//////////////////////////////Dosyadan Okuduğumuz Deger Vezir İse Vezirin Degerlerini Atadığımız Yer//////////////////////////////////////////
Vezir* Vezir::Ekle(string renk, string adi, int x, int y) {  
    this->renk = renk;
    this->adi = adi;
    this->konum = make_pair(x, y);
    this->puan = 9;
    //cout << "renk " << renk << " Adi " << adi << " X= " << konum.first << " Y= " << konum.second << endl;
    return this;
}



//////////////////////////////Nesne Vezir İse Bu print() Fonksiyonu Çagrılır//////////////////////////////////////////
void Vezir::print() {  
    cout << "renk " << this->renk << " Adi " << this->adi << " X= " << konum.first << " Y= " << konum.second << this->puan << endl;
}


//////////////////////////////Gelen Tas Vezirin Yörüngesinde mi Kontrolü Yapılır //////////////////////////////////////////
void Vezir::puanHesapla( Taslar* tas)
{
    Taslar taslar;
    auto konumlar = taslar.dosyaVeriCek();
    bool onu_dolumu = false;
    bool konum_esit_mi = false;
    if (this->getTakim() != tas->getTakim() && !tas->getTehtitEdildimi()) {//Taşin takımı farklı ve daha önce tehtit edilmedi ise if'in içine gir
        for (int i = 1; (this->getKonum().second + i) < 8; i++) // Vezirin sağını kontrol eden döngü 
        {

            if (make_pair(this->getKonum().first, this->getKonum().second + i) == tas->getKonum()) // Tas Vezirin sağında ise
            {
                konum_esit_mi = true;
                for (auto j = 0; j < konumlar.size(); j++)//diğer tasların konumlarını gezen döngü
                {
                    if (this->getKonum().first == konumlar[j]->getKonum().first && 
                        (this->getKonum().second < konumlar[j]->getKonum().second && 
                        tas->getKonum().second>konumlar[j]->getKonum().second) &&
                        this->getTakim() != tas->getTakim()) //Vezir ile Tas arasında başka bir taş var mı 
                    {
                        onu_dolumu = true;//Önü dolu ise değişkeni true yaptık
                    }
                }

            }

        }

        for (int i = this->getKonum().second - 1; i > -1; i--)// Vezirin solunu kontrol eden döngü
        {
            if (make_pair(this->getKonum().first, this->getKonum().second - i) == tas->getKonum())// Tas Vezirin solunda ise
            {
                konum_esit_mi = true;
                for (auto j = 0; j < konumlar.size(); j++)//diğer tasların konumlarını gezen döngü
                {
                    if (this->getKonum().first == konumlar[j]->getKonum().first && 
                        (this->getKonum().second > konumlar[j]->getKonum().second && 
                        tas->getKonum().second < konumlar[j]->getKonum().second) && 
                        this->getTakim() != tas->getTakim())//Vezir ile Tas arasında başka bir taş var mı
                    {
                        onu_dolumu = true;//Önü dolu ise değişkeni true yaptık
                    }
                }


            }
        }

        for (int i = 1; (this->getKonum().first + i) < 8; i++)// Vezirin önunde olup olmadığını  kontrol eden döngü
        {
            if (make_pair(this->getKonum().first + i, this->getKonum().second) == tas->getKonum())// Tas Vezirin önunde ise
            {
                konum_esit_mi = true;
                for (auto j = 0; j < konumlar.size(); j++)//diğer tasların konumlarını gezen döngü
                {
                    if (this->getKonum().second == konumlar[j]->getKonum().second &&
                        (this->getKonum().first < konumlar[j]->getKonum().first && 
                        tas->getKonum().first > konumlar[j]->getKonum().first) &&
                        this->getTakim() != tas->getTakim())//Vezir ile Tas arasında başka bir taş var mı
                    {
                        onu_dolumu = true;//Önü dolu ise değişkeni true yaptık
                    }
                }


            }

        }

        for (int i = this->getKonum().first - 1; i > -1; i--)// Vezirin gerisinde olup olmadığını  kontrol eden döngü
        {
            if (make_pair(this->getKonum().first - i, this->getKonum().second) == tas->getKonum())// Tas Vezirin gerisinde ise
            {
                konum_esit_mi = true;
                for (auto j = 0; j < konumlar.size(); j++)//diğer tasların konumlarını gezen döngü
                {
                    if (this->getKonum().second == konumlar[j]->getKonum().second &&
                        (this->getKonum().first > konumlar[j]->getKonum().first &&
                        tas->getKonum().first < konumlar[j]->getKonum().first) && 
                        this->getTakim() != tas->getTakim())//Takımlar aynı mı diye bakar
                    {
                        onu_dolumu = true;//Önü dolu ise değişkeni true yaptık
                    }
                }

            }
        }


        for (int i = 1; this->getKonum().second + i < 8 && this->getKonum().first + i < 8; i++)// Vezirin ileri sağ çaprazını   kontrol eden döngü
        {
            if (make_pair(this->getKonum().first + i, this->getKonum().second + i) == tas->getKonum())// Tas Vezirin gerisinde ise
            {
                konum_esit_mi = true;
                for (int k = 1; this->getKonum().second + k < 8 && this->getKonum().first + k < 8; k++)//Vezirin konumunu degiştiren döngü
                {
                    for (auto j = 0; j < konumlar.size(); j++)//Diğer tasların konumlarını gezen döngü
                    {
                        if (make_pair(this->getKonum().first + k, this->getKonum().second + k) == konumlar[j]->getKonum() && //Bu Kontrol vezirin gittiği konumda tas var mı kontrolü yapıldı
                            tas->getKonum() != make_pair(this->getKonum().first + k, this->getKonum().second + k) &&//tasın konumu vezirin gittiği konumuna eşit olmayacak 
                            konumlar[j]->getKonum().second < tas->getKonum().second)//vezir ile taş arasına bak arkasına bakma 
                        {
                            onu_dolumu = true;//Önü dolu ise değişkeni true yaptık
                        }
                    }
                }

            }

        }


        for (int i = 1; this->getKonum().second - i > -1 && this->getKonum().first - i > -1; i++)// Vezirin Geri sol çaprazını   kontrol eden döngü
        {
            if (make_pair(this->getKonum().first - i, this->getKonum().second - i) == tas->getKonum())// Tas Vezirin çaprazında ise
            {
                konum_esit_mi = true;
                for (int k = 1; this->getKonum().second - k > -1 && this->getKonum().first - k > -1; k++)//Vezirin konumunu degiştiren döngü
                {
                    for (auto j = 0; j < konumlar.size(); j++)//Diğer tasların konumlarını gezen döngü
                    {
                        if (make_pair(this->getKonum().first - k, this->getKonum().second - k) == konumlar[j]->getKonum() &&//Bu Kontrol vezirin gittiği konumda tas var mı kontrolü yapıldı
                            tas->getKonum() != make_pair(this->getKonum().first - k, this->getKonum().second - k) &&//tasın konumu vezirin gittiği konumuna eşit olmayacak 
                            konumlar[j]->getKonum().second > tas->getKonum().second)//vezir ile taş arasına bak arkasına bakma 
                        {
                            onu_dolumu = true;//Önü dolu ise değişkeni true yaptık
                        }
                    }
                }

            }
        }



        for (int i = 1; this->getKonum().second - i > -1 && this->getKonum().first + i < 8; i++)// Vezirin ileri sol çaprazını   kontrol eden döngü
        {
            if (make_pair(this->getKonum().first + i, this->getKonum().second - i) == tas->getKonum())
            {
                konum_esit_mi = true;
                for (int k = 1; this->getKonum().second - k > -1 && this->getKonum().first + k < 8; k++)//Vezirin konumunu degiştiren döngü
                {
                    for (auto j = 0; j < konumlar.size(); j++)//Diğer tasların konumlarını gezen döngü
                    {
                        if (make_pair(this->getKonum().first + k, this->getKonum().second - k) == konumlar[j]->getKonum() &&//Bu Kontrol vezirin gittiği konumda tas var mı kontrolü yapıldı
                            tas->getKonum() != make_pair(this->getKonum().first + k, this->getKonum().second - k) && //tasın konumu vezirin  gittiği konumuna eşit olmayacak 
                            konumlar[j]->getKonum().second > tas->getKonum().second) //vezir ile taş arasına bak arkasına bakma 
                        {
                            onu_dolumu = true;//Önü dolu ise değişkeni true yaptık
                        }
                    }
                }

            }

        }


        for (int i = 1; this->getKonum().second + i <8 && this->getKonum().first - i > -1; i++)// Vezirin geri sağ çaprazını   kontrol eden döngü
        {
            if (make_pair(this->getKonum().first - i, this->getKonum().second + i) == tas->getKonum())
            {
                konum_esit_mi = true;
                for (int k = 1; this->getKonum().second + k <8 && this->getKonum().first - k > -1; k++)//Vezirin konumunu degiştiren döngü
                {
                    for (auto j = 0; j < konumlar.size(); j++)//Diğer tasların konumlarını gezen döngü
                    {
                        if (make_pair(this->getKonum().first - k, this->getKonum().second + k) == konumlar[j]->getKonum() && //Bu Kontrol vezirin gittiği konumda tas var mı kontrolü yapıldı
                            (tas->getKonum() != make_pair(this->getKonum().first - k, this->getKonum().second + k)) //tasın konumu vezirin gittiği konumuna eşit olmayacak 
                            && konumlar[j]->getKonum().second < tas->getKonum().second)//vezir ile taş arasına bak arkasına bakma 
                        {
                            onu_dolumu = true;//Önü dolu ise değişkeni true yaptık
                        }
                    }

                }
            }
        }


        if (!onu_dolumu && konum_esit_mi)// Taşla vezir arasında birşey yok ise
        {
            tas->setPuan(tas->getPuan() * 0.5); //Taşın puanını hesaplattık 
            tas->setTehtitEdildimi();//Tas tehtit edildi 
        }
    }
}

//////////////////////////////Vezirin Konumunu Döner//////////////////////////////////////////
std::pair<int, int> Vezir::getKonum()
{
    return konum;
}


//////////////////////////////Vezirin Adını Döner//////////////////////////////////////////
std::string Vezir::getAdi()
{
    return this->adi;
}


//////////////////////////////Vezirin Takımını Döner//////////////////////////////////////////
string Vezir::getTakim()
{
    return this->renk;
}


//////////////////////////////Vezirin Puanını Döner//////////////////////////////////////////
double Vezir::getPuan()
{
    return this->puan;
}


//////////////////////////////Vezirin Puanını Set Eder//////////////////////////////////////////
void Vezir::setPuan(double puan)
{
    this->puan = puan;
}


//////////////////////////////Vezir Daha Önce Baska Tas Tarafından Tehtit Edildi mi Kontrolü Yapmak için Oluşturuldu //////////////////////////////////////////
bool Vezir::getTehtitEdildimi()
{
    return this->tehtit_edildimi;
}


//////////////////////////////Vezir Daha Önce Baska Tas Tarafından Tehtit Edilmedi ise Tettit Edildi fonksiyonu Çagrılacak //////////////////////////////////////////
void Vezir::setTehtitEdildimi()
{
    this->tehtit_edildimi = !this->tehtit_edildimi;
}