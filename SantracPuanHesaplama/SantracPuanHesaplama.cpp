#include <iostream>
#include <vector>
#include"Taslar.h"
#include<string>




using namespace std;



int main()
{

    Taslar taslar;  
    auto degerler = taslar.dosyaVeriCek();
    float toplamPuanSiyah = 0;
    float toplamPuanBeyaz = 0;
   

   // hesapla(degerler[7], degerler[1]);
        //cout << degerler[7]->getPuan() << endl;
       // degerler[0]->puanHesapla(degerler[2]);
    // cout<<degerler[2]->getPuan()<<endl;


///////////////////////Puanlar Hesaplanıyor/////////////////////////////////////
     for (int i = 0; i < degerler.size(); i++)
        {
            for (int j = 0; j < degerler.size(); j++)
            {
                if (i != j)// Nesne kendisini çagırmasın diye eklendi
                    degerler[i]->puanHesapla(degerler[j]);//degerler[i] nesnesi degerler[j] nesnesini tehtit ediyor mu ediyorsa puanını 0,5 ile çarpan fonksiyonu çağırıyoruz
            }
        }
 
     for(int i=0;i<degerler.size();i++)
     {
         if(degerler[i]->getTakim()=="s")//takım siyah ise
         toplamPuanSiyah = toplamPuanSiyah + degerler[i]->getPuan();//siyahın puanını hesapla
         if (degerler[i]->getTakim() == "b")//takım beyaz ise
             toplamPuanBeyaz = toplamPuanBeyaz + degerler[i]->getPuan();//beyazın puanını hesapla
     }

    for (int i = 0; i < degerler.size(); i++)
        cout <<  degerler[i]->getAdi() << degerler[i]->getTakim() << " " << degerler[i]->getPuan() << endl;
    cout << "--------------------------------------------------------------------------------------------------\n";
    cout << "Siyah Takim Puan = " << toplamPuanSiyah << " Beyaz Takim Puan = " << toplamPuanBeyaz;

    return 0;
}


