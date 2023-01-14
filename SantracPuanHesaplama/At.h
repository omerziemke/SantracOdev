#ifndef AT_H
#define AT_H
#include "Taslar.h"
class At : public Taslar{
public:

	void print()override;
	At* Ekle(std::string renk, std::string adi, int x, int y)override;
	void puanHesapla(Taslar*)override;
	std::pair<int, int> getKonum()override;
	std::string getAdi()override;
	std::string getTakim()override;
	double getPuan()override;
	bool getTehtitEdildimi()override;
	void setTehtitEdildimi()override;
	void setPuan(double puan)override;
private:
};

#endif;
