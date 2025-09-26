#include <bits/stdc++.h>
using namespace std;

class HangHoa{
	private:
		int maHang;
		char tenHang[30];
		long tienTra;
		
		public:
       void nhap() {
        cout << "Ma hang: ";
        cin >> maHang;
        cout << "Nhap ten hang: ";
        fflush(stdin);
        gets(tenHang);
        cout << "Nhap tien tra: ";
        cin >> tienTra;
    }

    void xuat() {
        cout << "Ma hang: " << maHang << endl;
        cout << "Ten hang: " << tenHang << endl;
        cout << "Tien tra: " << tienTra << endl;
    }
    
     long getTienTra() {
        return tienTra;
    }
};

class PhieuMuaHang{
	private:
		int maPhieu;
		char tenKhach[30];
		int n;
		HangHoa *a;
	public:
		void nhap(){
			cout<<"nhap vao ma phieu: ";
			cin>>maPhieu;
			cout<<"nhap vao ten khach: ";
			fflush(stdin);
			gets(tenKhach);
			cout<<"nhap vao so hang hoa: ";
			cin>>n;
			a = new HangHoa[n];
			for(int i = 0 ;i < n ; i++){
				cout<<"nhap hang hoa thu"<<i+1<<":"<<endl;
				a[i].nhap();
		}
		
	}
	
	 void xuat() {
        cout << "\nMa phieu: " << maPhieu;
        cout << "\nTen khach: " << tenKhach;
        cout << "\nDanh sach hang hoa:\n";
        for (int i = 0; i < n; i++) {
            a[i].xuat();
        }
        
        long total = 0 ;
        for(int i = 0 ; i < n ; i++ ){
        	total += a[i].getTienTra();
		}
		
		cout<<"tong tien:"<< total;
    }
    
};

int main(){
	PhieuMuaHang phieu;
    phieu.nhap();
    phieu.xuat();
}



