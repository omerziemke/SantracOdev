#ifndef SAH_H
#define SAH_H
#include"Taslar.h"
class Sah :public Taslar {
public:
	Sah* Ekle(std::string renk, std::string adi, int x, int y)override;
	void print()override;
	void puanHesapla(Taslar*)override;
	std::pair<int, int> getKonum()override;
	std::string getAdi()override;
	std::string getTakim()override;
	bool getTehtitEdildimi()override;
	void setTehtitEdildimi()override;
	double getPuan()override;
	void setPuan(double puan)override;
private:
};

#endif;

