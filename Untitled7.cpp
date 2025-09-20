#include<bits/stdc++.h>
using namespace std;

class CanBo{
	private:
	      char maCanBo[10];
	      char hoTen[30];
	      char ngaySinh[20];
	      int soNgayLamViec;
	      
	      public:
	      	void nhap(){
	      		cout << "nhap vao ma can bo: ";
	      		cin.getline(maCanBo,10);
	      		cout<< "nhap vao ho ten: ";
	      		cin.getline(hoTen,30);
	      		cout<<"nhap vao ngay thang nam sinh dd-mm-yyyy: ";
	      		cin.getline(ngaySinh,20);
	      		cout<< "so ngay lam viec: ";
	      		cin>> soNgayLamViec;
			  }
			
			long luong(){
				return soNgayLamViec * 250000;
			}
		    
		    void xuat(){
		    	cout<< "\n----------THONG TIN CAN BO----------\n";
		    	cout<<"\n Ma Can Bo: "<<maCanBo<<"\n";
		    	cout<<"\n Ho Ten: "<<hoTen<<"\n";
		    	cout<<"\n Ngay Sinh: "<<ngaySinh<<"\n";
		    	cout<<"\n So Ngay Lam Viec: "<<soNgayLamViec<<"\n";
		    	cout<<"\n Luong: "<<luong()<<" VND\n";
			}
};
int main(){
	CanBo cb;
	cb.nhap();
	cb.xuat(); 
}
