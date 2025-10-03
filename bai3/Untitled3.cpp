#include <bits/stdc++.h>
using namespace std;

class Date{
	private: 
   int ngay, thang, nam;
   public:
   void nhap() {
   	cout<<"nhap ngay thang nam: ";
	cin>>ngay>>thang>>nam; 
   }
   void xuat(){
   	cout<<"ngay lap:"<<ngay<<"/"<<thang<<"/"<<nam<<endl; 
   } 
   
}; 

class NhaCungCap{
	char maNhaCungCap[30];
	char tenNhaCungCap[30];
	friend class  PhieuMuaHang;
}; 

class DiaChi{
	char dienThoai[10]; 
	char quan[30];
	char thanhPho[30]; 
	friend class  PhieuMuaHang;
}; 

class SanPham{
	private: 
	char maSanPham[10];
	char tenSanPham[30];
	int soLuong;
	long donGia;
	friend class  PhieuMuaHang;
	
	public:
	long thanhTien(){
		return soLuong*donGia; 
	} 
	 void nhap() {
        cout << "Nhap ma san pham: ";fflush(stdin);
        gets(maSanPham);
        cout << "Nhap ten san pham: ";fflush(stdin);
        gets(tenSanPham);
        cout << "Nhap so luong: ";
        cin >> soLuong;
        cout << "Nhap don gia: ";
        cin >> donGia;
    }

       void xuat() {
          cout<< setw(10) << maSanPham
         << setw(20) << tenSanPham
         << setw(8) << soLuong
         <<setw(10) << donGia
         << setw(12) << thanhTien() << endl;

    }
    
}; 


class PhieuMuaHang{
	private: 
	char maPhieu[10];
	NhaCungCap nhaCungCap; 
	DiaChi diaChi; 
	Date date; 
	int n; 
	SanPham* sanPham; 
	
	public:
	void nhap(){
		cout<<"ma phieu:";fflush(stdin);
		gets(maPhieu);
		date.nhap();
		cout<<"nhap ma nha cc:";fflush(stdin);
		gets(nhaCungCap.maNhaCungCap);
		cout<<"nhap ten nha cc:";fflush(stdin);
		gets(nhaCungCap.tenNhaCungCap);
		cout << "Nhap quan: ";fflush(stdin); 
        gets(diaChi.quan);
        cout << "Nhap thanh pho: "; fflush(stdin); 
        gets(diaChi.thanhPho); 
        cout<<"nhap dien thoai:";fflush(stdin);
		gets(diaChi.dienThoai);
		cout << "Nhap so luong san pham: ";
        cin >> n;
        sanPham = new SanPham[n];
		for (int i = 0; i < n; i++) {
            cout << "\nNhap san pham thu " << i + 1 << ":\n";
            sanPham[i].nhap();
        }	 
	} 
	 void xuat() {
        cout << "\nMa phieu: " << maPhieu << endl;
        cout << "\nNgay lap: ";
		 date.xuat();
         cout << "\nMa nha cc: " << nhaCungCap.maNhaCungCap << endl;
          cout << "\nTen  nha cc: " << nhaCungCap.tenNhaCungCap << endl;
          cout << "\nDia chi:  " << diaChi.quan<<" "<<diaChi.thanhPho << endl;
          cout<<"\n SDT: "<<diaChi.dienThoai<<endl; 
        cout << "Danh sach san pham:\n";
       cout<< setw(10) << "masp"
         << setw(20) << "tensp"
         << setw(8) << "so luong"
         <<setw(10) << "don gia"
         << setw(12) << "thanh tien" << endl;
        long tongTien = 0;
        for (int i = 0; i < n; i++) {
            sanPham[i].xuat();
            tongTien += sanPham[i].thanhTien();
        }
        cout << "                    Tong tien phieu: " << tongTien << endl;
    }
    
    int demSoLuongSanPhamBeHon80(){
    	int count = 0 ; 
    	for(int i = 0 ;i< n;i++){
    		if(sanPham[i].soLuong<80){
    			count++; 
			} 
		} 
		return count; 
	} 
	
	void sapXepTheoDonGiaGiamDan() {
     for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sanPham[i].donGia < sanPham[j].donGia) {
                swap(sanPham[i], sanPham[j]);
            }
        }
     }
   }
    
    void  suaTenNhaCungCap(char* tenMoi){
    	strcpy(nhaCungCap.tenNhaCungCap,tenMoi) ;
	} 
	
}; 

int main(){
	PhieuMuaHang phieuMuaHang;
	phieuMuaHang.nhap();
	phieuMuaHang.xuat(); 
    cout << "\nSo san pham co so luong < 80: "
    << phieuMuaHang.demSoLuongSanPhamBeHon80() << endl;
    phieuMuaHang.sapXepTheoDonGiaGiamDan();
	phieuMuaHang.xuat(); 
	phieuMuaHang.suaTenNhaCungCap("Cong ty TNHH Thanh Do");
	phieuMuaHang.xuat(); 
    
	 
} 
