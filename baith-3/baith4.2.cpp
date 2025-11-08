#include<bits/stdc++.h>
using namespace std;


class DotPrinter;
class LaserPrinter;

class Printer{
	public:
	
	double trongLuong;
	char namSX[30];
	char tocDo[30]; 
}; 




class DotPrinter:private Printer{
	char matDoKim[30];
	public: 
	 void nhap() {
        cout << "\n=== Nhap thong tin may in kim ===\n";
        cout << "Nhap trong luong: ";
        cin >> trongLuong;
        cout << "Nhap nam san xuat: ";
        fflush(stdin);
        gets(namSX);
        cout << "Nhap toc do (trang/phut): ";
        fflush(stdin);
        gets(tocDo);
        cout << "Nhap mat do kim: ";
        fflush(stdin);
        gets(matDoKim);
    }

    void xuat() {
        cout << "\n--- May in kim ---\n";
        cout << "Trong luong: " << trongLuong << " kg" << endl;
        cout << "Nam san xuat: " << namSX << endl;
        cout << "Toc do: " << tocDo << " trang/phut" << endl;
        cout << "Mat do kim: " << matDoKim << endl;
    }
    
   void friend  suaNamSX(DotPrinter &d);
	 
}; 

class LaserPrinter:private Printer{
	char doPhanGiai[30]; 
	
	public:
    void nhap() {
        cout << "\n=== Nhap thong tin may in laser ===\n";
        cout << "Nhap trong luong: ";
        cin >> trongLuong;
        cout << "Nhap nam san xuat: ";
        cin >> namSX;
        cout << "Nhap toc do (trang/phut): ";
        cin >> tocDo;
        cout << "Nhap do phan giai: ";
        fflush(stdin);
        gets(doPhanGiai);
    }

    void xuat() {
        cout << "\n--- May in laser ---\n";
        cout << "Trong luong: " << trongLuong << " kg" << endl;
        cout << "Nam san xuat: " << namSX << endl;
        cout << "Toc do: " << tocDo << " trang/phut" << endl;
        cout << "Do phan giai: " << doPhanGiai << endl;
    }
   void friend  suaNamSX(LaserPrinter &l);
}; 

void suaNamSX(DotPrinter &d) {
    strcpy(d.namSX, "2020");
}

void suaNamSX(LaserPrinter &l) {
    strcpy(l.namSX, "2020");
}

int main(){
	DotPrinter d;
    LaserPrinter l;

    d.nhap();
    l.nhap();

    d.xuat();
    l.xuat();
    
     suaNamSX(d);
    suaNamSX(l);

    cout << "\n--- Sau khi sua nam san xuat thanh 2020 ---\n";
    d.xuat();
    l.xuat();
} 
