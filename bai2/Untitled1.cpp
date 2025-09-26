#include <bits/stdc++.h>
using namespace std;
class Date {
	private: 
	char thoiGian[20];
	
	public:
		void nhap(){
			cout<<"nhap vao ngay thang nam: ";
			fflush(stdin);
			gets(thoiGian);
		} 
		void xuat(){
			cout<<thoiGian<<endl; 
		} 
}; 

class  XeHoi{
	private:
	char hangSanXuat[30];
	Date date;
	double giaBan;
	int soLuongBan;
	
	public:
	void nhap(){
		cout<<"nhap vao hangsx: ";
		fflush(stdin);
		gets(hangSanXuat);
		date.nhap();
		cout<<"nhap vao gia ban: ";
		cin>>giaBan;
		cout<<"nhap vao so luong";
		cin>>soLuongBan;
	} 
	
	void xuat(){
		cout<<"hang sx: " << hangSanXuat<<endl;
		cout<<"date sx: ";
		date.xuat();
		cout<<"gia ban: "<< giaBan<<endl;
		cout<<"so luong ban: "<<soLuongBan<<endl;
	}
	
}; 

int main(){
	XeHoi xh;
	xh.nhap();
	cout<<"thong tin xe hoi la"<<endl;
	xh.xuat();
}
 
