#include<bits/stdc++.h>
using namespace std;
class Phieu;
class TaiSan{
	char tenTaiSan[30];
	int soLuong;
	char tinhTrang[30];
	
	friend class Phieu;
	friend void suaThongTin(Phieu &p);
	friend void sapXep(Phieu &p);

	public:
	void nhap(){
		cout<<"nhap vao ten ts: ";
		fflush(stdin);
		gets(tenTaiSan);
		cout<<"nhap vao so luong ts: ";
		cin>>soLuong;
		cout<<"nhap vao tinh trang tai san: ";
		fflush(stdin);
		gets(tinhTrang);
	} 
	void xuat(){
		cout<<setw(20)<<tenTaiSan<<setw(20)<<soLuong<<setw(20)<<tinhTrang<<endl;
	}
}; 

class Phieu{
	char maPhieu[20];
	char ngayKiemKe[30];
	char nhanVienKiemKe[30];
	char chucVu[30];
	char kiemKeTaiPhong[30];
	char maPhong[30];
	char truongPhong[30];
	
	TaiSan *ts;
	
	int n;
	
	public:
		void nhap(){
			cout<<"nhap vao ma phieu: ";
			fflush(stdin);
			gets(maPhieu);
			cout<<"nhap vao ngay kiem ke: ";
			fflush(stdin);
			gets(ngayKiemKe);
			cout<<"nhap vao nhan vien kiem ke: ";
			fflush(stdin);
			gets(nhanVienKiemKe);
			cout<<"nhap vao chuc vu: ";
			fflush(stdin);
			gets(chucVu);
			cout<<"nhap vao kiem tra tai phong: ";
			fflush(stdin);
			gets(kiemKeTaiPhong);
			cout<<"nhap vao ma phong: ";
			fflush(stdin);
			gets(maPhong);
			cout<<"nhap vao truong phong: ";
			fflush(stdin);
			gets(truongPhong);
			
			cout << "Nhap so luong tai san: ";
			cin >> n;
			ts = new TaiSan[n];
			for (int i = 0; i < n; i++) {
			    cout << "\nNhap tai san thu " << i + 1 << ":\n";
			    ts[i].nhap();
			}
		}
		
		
		void xuat() {
        cout << "\n===== PHIEU KIEM KE =====\n";
        cout << "Ma phieu: " << maPhieu << endl;
        cout << "Ngay kiem ke: " << ngayKiemKe << endl;
        cout << "Nhan vien: " << nhanVienKiemKe <<endl;
        cout << "Chuc vu: " << chucVu<<endl;
        cout << "Tai phong: " << kiemKeTaiPhong<<endl;
        cout << "Ma phong: " << maPhong<<endl;
        cout << "Truong phong: " << truongPhong << endl;
        
        

        cout << "\nDanh sach tai san:\n";
        cout << setw(20) << "Ten tai san" << setw(20) << "So luong" << setw(20) << "Tinh trang" << endl;
        	for (int i = 0; i < n; i++) {
			    ts[i].xuat();
			}
			
		cout<<"so tai san kiem Ke:"<<n<<"tong so tai san: "<<tongSoLuong()<<endl; 
		
	
    }
    
		int tongSoLuong(){
			int tong = 0 ;
			for(int i = 0; i < n ; i++){
				tong+=ts[i].soLuong; 
			} 
			return tong; 
		} 
	
    
    friend void suaThongTin(Phieu &p);
    friend void sapXep(Phieu &p);
};

	void suaThongTin(Phieu &p) {
	    for (int i = 0; i < p.n; i++) {
	        
	        if (strcasecmp(p.ts[i].tenTaiSan, "mayvitinh") == 0) {
	            p.ts[i].soLuong = 20;
	            return; // sau khi s?a xong thì thoát hàm
	        }
	    }
	    cout << "\nKhong tim thay tai san co ten 'mayvitinh'!\n";
	}
	
	void sapXep(Phieu &p){
		for(int i = 0 ; i < p.n ; i++){
			for(int j = i + 1 ; j < p.n ; j++) {
			if (p.ts[i].soLuong > p.ts[j].soLuong) {
                swap(p.ts[i], p.ts[j]);
            }
			}
		}
	};


int main(){
	Phieu p;
	p.nhap();
	p.xuat();
	cout<<"thong tin sau khi sua: "<<endl;
	suaThongTin(p);
	p.xuat();
	cout<<"thong tin sau khi sap xep"<<endl;
	sapXep(p);
	p.xuat();
}
