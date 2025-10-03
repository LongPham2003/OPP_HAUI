#include <bits/stdc++.h>
using namespace std;
class Date{
	private:
	int day , month, year;
	public:
		void nhap(){
			cout<<"nhap vao ngay thang nam ";
			cin>>day>>month>>year;
			
		}
		void xuat(){
			cout<<day<<"/"<<month<<"/"<<year<<endl;
		}
		
		int getYear(){
			return year; 
		} 
		
};

class DiaChi{
	private: 
	char dienThoai[10];
	char phuong[30];
	char quan[30];
	char thanhPho[30];
	
	// doanh nghiep co the truy cap truc tiep
	// den thuoc tinh cua diaChi 
	friend class DN; 
};

class DN{
	private:
	int maDn;
	char tenDn[60];
	Date ngayTl;
	DiaChi diaChi;
	char giamDoc[30];
	long doanhThu;
	
	public:
	void nhap() {
        cout << "Nhap ma DN: ";
        fflush(stdin); 
        cin >> maDn;
        cout << "Nhap ten DN: ";
        fflush(stdin); 
        gets(tenDn);
        ngayTl.nhap();
        cout << "Nhap so dien thoai: ";
        fflush(stdin); 
        gets(diaChi.dienThoai);
        cout << "Nhap phuong: ";
        fflush(stdin); 
        gets(diaChi.phuong);
        cout << "Nhap quan: ";
        fflush(stdin); 
        gets(diaChi.quan);
        cout << "Nhap thanh pho: ";
        fflush(stdin); 
        gets(diaChi.thanhPho);
        cout << "Nhap ten giam doc: ";
        fflush(stdin); 
        gets(giamDoc);
        cout << "Nhap doanh thu: ";
        fflush(stdin);
        cin >> doanhThu;
    }
        
    void xuat(){
		cout<<"Ma dn:" <<maDn<<endl;
		cout<<" Ten doanh nghiep:"<<tenDn<<endl;
		cout<<" Ngay thanh lap:";
		ngayTl.xuat();
		cout<<" Dia chi doanh nghiep:"<<diaChi.phuong<<" "<<diaChi.quan<<" "<<diaChi.thanhPho<<endl;
		cout<<" Giam doc:"<<giamDoc<<endl;
		cout << "Doanh thu: " << doanhThu << endl;
		cout<<"--------------------------"<<endl; 
		 
	} 
	
	char* getThanhPho(){
		return diaChi.thanhPho; 
	} 
	
	long getDoanhThu(){
		return doanhThu; 
	} 
	
	int getYear(){
			return ngayTl.getYear(); 
	} 
	
	void suaThongTin(int ma){
	if (maDn == ma) {
            cout << "Nhap lai thong tin DN co ma " << ma << ":\n";
            nhap();
        }
	} 
	
};

int main(){
	int n ;
	do {
		 cout << "Nhap so DN (0 < n < 20): ";
        cin >> n;
        if (n <= 0 || n >= 20) {
            cout << "So luong DN khong hop le! Vui long nhap lai.\n";
        }
	} while (n <= 0 || n >= 20);
	
	DN dn[n];
    for(int i = 0; i < n; i++){
		cout<<"nhap thong tin doanh nghiep"<<i+1<<endl; 
		dn[i].nhap(); 
	} 
	
	for(int i = 0 ; i < n ; i++){
		dn[i].xuat(); 
	} 
	   
    for(int i = 0; i < n; i++){
		if(strcmp(dn[i].getThanhPho(),"Ha Noi") ==  0 ){
			dn[i].xuat(); 
		} 
	} 
	
	long dt = 0; 
    for(int i = 0; i < n; i++){
		if(dn[i].getYear()==2015) {
				dt+=dn[i].getDoanhThu();
					cout<<"doanh thu cua doanh nghiep 2015 la:"<<dt<<endl; 
		}
	} 
	
	int madnSua;
	cout<<"nhap ma dn can sua";
	cin>>madnSua; 
    for(int i = 0; i < n; i++){
	 	dn[i].suaThongTin(madnSua);
	}
	
	cout <<" danh sach sau sua"<<endl; 
    for(int i = 0; i < n; i++){
		dn[i].xuat(); 
	} 
	 
	
	
	
	 
	
}


