#ifndef TASLAR_H
#define TASLAR_H
#include <iostream>
#include <string>
#include<vector>




class Taslar {
public:
	Taslar()=default;
	std::vector<Taslar*> dosyaVeriCek();
	virtual Taslar* Ekle(std::string renk, std::string adi, int x, int y);
    virtual void print();
	virtual  void puanHesapla(Taslar*);
	virtual std::string getAdi();
	virtual double getPuan();
	virtual void setPuan(double puan);
	virtual std::string getTakim();
	virtual std::pair<int,int> getKonum();
	virtual bool getTehtitEdildimi();
	virtual void setTehtitEdildimi();
	std::vector<std::pair<int, int>> getKonumlar;

protected:
	std::pair<int, int> konum;
	std::string adi;
	std::string renk;
	bool tehtit_edildimi =false;
	double puan;
	

};

#endif
