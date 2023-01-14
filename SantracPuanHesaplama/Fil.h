#ifndef FIL_H
#define FIL_H
#include "Taslar.h"
class Fil : public Taslar {
public:
	Fil* Ekle(std::string renk, std::string adi, int x, int y)override;
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

