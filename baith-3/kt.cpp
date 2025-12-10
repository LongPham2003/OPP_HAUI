#include<bits/stdc++.h>
using namespace std;

class Phieu; 
class SanPham{
	char maSP[30]; 
	char tenSP[30]; 
	int soLuong; 
	double donGia;
	
	public:
	  void nhap() {
	  	
        cout << "Nhap ma san pham: ";
        fflush(stdin); gets(maSP);

        cout << "Nhap ten san pham: ";
        fflush(stdin); gets(tenSP);

        cout << "Nhap so luong: ";
        cin >> soLuong;

        cout << "Nhap don gia: ";
        cin >> donGia;
    }

    void xuat() {
    	cout<<setw(20)<<maSP<<setw(20)<<tenSP<<setw(20)<<soLuong<<setw(20)<<donGia<<setw(20)<<soLuong * donGia<<endl; 
    }
    
    friend class Phieu; 
    friend  double tinhTongTien(Phieu p); 
    friend int demThanhTien (Phieu p);
    friend void sapXep(Phieu &p);
		  
}; 
class Phieu{
	private:
	char maPhieu[30];
	char ngayLap[30]; 
	char maNhaCungCap[30]; 
	char tenNhaCungCap[30]; 
	char diaChi[30]; 
	char SDT[30]; 
	SanPham *sp;
	int n; 
	
	public:
	void nhap(){
		cout<<"nhap vao ma phieu: ";
	fflush(stdin); gets(maPhieu);
		cout<<"nhap vao ngay lap phieu: ";
	fflush(stdin); gets(ngayLap);
		cout<<"nhap vao ma nha cc : ";
	fflush(stdin); gets(maNhaCungCap);
		cout<<"nhap vao ten nha cc phieu: ";
	fflush(stdin); gets(tenNhaCungCap);
		cout<<"nhap vao dc: ";
	fflush(stdin); gets(diaChi);
		cout<<"nhap vao sdt: ";
	fflush(stdin); gets(SDT);
	
		do{
			cout<<"nhap vao sl hang hoa: ";
			cin>>n; 
		} while(n<0) ;
		
		sp = new SanPham[n]; 
		
		for (int i = 0 ; i < n ; i++){
			cout<<"nhap vao sl hang hoa thu: "<<i+1<<endl;
			sp[i].nhap(); 
		}	
	}
	
	void xuat(){
		cout<<"ma phieu:"<<maPhieu<<endl;
		cout<<"ngayLap:"<<ngayLap<<endl;
		cout<<"ma nha cc:"<<maNhaCungCap<<endl;
		cout<<"ten nha cc:"<<tenNhaCungCap<<endl;
		cout<<"dia chi :"<<diaChi<<endl;
		cout<<"sdt:"<<SDT<<endl;
		cout<<setw(20)<<"ma sp"<<setw(20)<<"ten sp "<<setw(20)<<"so luong"<<setw(20)<<"don gia"<<setw(20)<<"thanh  tien"<<endl; 
		for (int i = 0 ; i < n ; i++){
			sp[i].xuat(); 
		}
	} 
	
	friend  double tinhTongTien(Phieu p); 
	friend int demThanhTien (Phieu p);
	friend void sapXep(Phieu &p); 
	friend void sua(Phieu &p);
	
}; 

// s?a l?i ten  
void sua(Phieu &p){
		 strcpy(p.tenNhaCungCap,"okokok") ;
		}

// tính tong tien  
double tinhTongTien(Phieu p) {
    double sum = 0;
    for (int i = 0; i < p.n; i++)
        sum += p.sp[i].soLuong * p.sp[i].donGia;
    return sum;
}

// dem thanh tien < 500 
 int demThanhTien (Phieu p){
 	int count = 0 ;
	  for (int i = 0; i < p.n; i++){
	  	if(p.sp[i].soLuong * p.sp[i].donGia <= 500){
	  		count++; 
		  } 
	  }
	  return count; 
 };
 
 // s?p x?p  
 void sapXep(Phieu &p){
 	for(int i = 0 ; i < p.n ; i++){
 		for(int j = i + 1  ; j < p.n ; j++){
 		if(p.sp[i].soLuong < p.sp[j].soLuong){
 			  swap(p.sp[i], p.sp[j]);
		 }
	 } 
	 } 
 } 



int main() {
    Phieu phieu;
    phieu.nhap();

    cout << "\n=== PHIEU BAN DAU ===\n";
    phieu.xuat();

    cout << "\nTong tien: " << tinhTongTien(phieu) << endl;
    cout << "So SP thanh tien <= 500: " << demThanhTien(phieu) << endl;

    sapXep(phieu);
    cout << "\n=== SAU KHI SAP XEP ===\n";
    phieu.xuat();

    sua(phieu);
    cout << "\n=== SAU KHI SUA NHA CUNG CAP ===\n";
    phieu.xuat();

    return 0;
}


