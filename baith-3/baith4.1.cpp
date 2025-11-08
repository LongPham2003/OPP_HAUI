#include<bits/stdc++.h>
using namespace std;

class Person{
	public: 
	char hoTen[30];
	char ngaySinh[30];
	char queQuan[30]; 
}; 

class KySu:public Person{
	char nganh[30]; 
	int namTN; 
	
	public:
	 void nhap() {
        cout << "Nhap ho ten: ";
        fflush(stdin);
        gets(hoTen);
        cout << "Nhap ngay sinh: ";
        fflush(stdin);
        gets(ngaySinh);
        cout << "Nhap que quan: ";
        fflush(stdin);
        gets(queQuan);
        cout << "Nhap nganh dao tao: ";
        fflush(stdin);
        gets(nganh);
        cout << "Nhap nam tot nghiep: ";
        cin >> namTN;
    }

    void xuat() {
    
        cout << setw(20) << hoTen<< setw(20) << ngaySinh << setw(20) << queQuan<< setw(20) << nganh<< setw(10) << namTN << endl;
    }
    
    friend void timKySuGanDayNhat(KySu *ds, int n);
}; 

	void timKySuGanDayNhat(KySu *ds, int n) {
	    int maxNam = ds[0].namTN;
	    for (int i = 1; i < n; i++) {
	        if (ds[i].namTN > maxNam)
	            maxNam = ds[i].namTN;
	    }
	    cout<<"ki su tot nghiep gan day nhat" <<endl; 
	    
		for (int i = 0; i < n; i++) {
	        if (ds[i].namTN == maxNam)
	            ds[i].xuat();
	    }
    } 	
	int main() {
		
		int n;
	    cout << "Nhap so luong ky su: ";
	    cin >> n;
	    
	    KySu *ds = new KySu[n];
	    
	    for (int i = 0; i < n; i++) {
	        cout << "\n=== Nhap thong tin ky su thu " << i + 1 << " ===\n";
	        ds[i].nhap();
	    }
		cout << "\n=== Thong tin ky su vua nhap ===\n";
	    cout << setw(20) << "Ho ten"<< setw(20) << "Ngay sinh"<< setw(20) << "Que quan"<< setw(20) << "Nganh"<< setw(10) << "Nam TN" << endl;
	    
		for (int i = 0; i < n; i++) {
		    ds[i].xuat();
		}
	    
	     timKySuGanDayNhat(ds, n);
	}
