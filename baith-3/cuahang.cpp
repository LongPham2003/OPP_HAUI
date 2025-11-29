#include<bits/stdc++.h>
using namespace std;

class CuaHang; 
class Hang{
	protected:
	int maHang;
	char  tenHang[30];
	long gia; 
	
	public:
		void nhap(){
			cout<<"nhap vao ma hang"<<endl;
			cin>>maHang;
			cout<<"nhap vao ten hang"<<endl;
			fflush(stdin);
			gets(tenHang);
			cout<<"nhap vao gia thanh"<<endl;
			cin>>gia;
		}
		
		void xuat(){
			cout<<"ma hang la: "<<maHang<<endl;
			cout<<"ten hang la: "<<tenHang<<endl;
			cout<<"gia thanh la: "<<gia<<endl;
		}
}; 

class HangMM:public Hang{
	private:
			char  chatLieu[30];
			char  kieuDang[30];
			int soLuong;
			
	public:
		void nhap(){
			Hang::nhap();
				cout<<"nhap vao chat lieu"<<endl;
			fflush(stdin);
			gets(chatLieu);
				cout<<"nhap vao kieu dang"<<endl;
			fflush(stdin);
			gets(kieuDang);
				cout<<"nhap vao so luong"<<endl;
			cin>>soLuong;
		}
		
		void xuat(){
			cout<<setw(20)<<chatLieu<<setw(20)<<kieuDang<<setw(20)<<soLuong<<endl;
		}
		
		friend class CuaHang; 
		friend void sapXep(CuaHang& cuaHang);
		
};

class CuaHang{
	int maCuaHang;
	char tenCuaHang[30];
	HangMM * x;
	int n;
	
	public:
		void nhap(){
			cout<<"nhap vao ma cua hang"<<endl;
			cin>>maCuaHang;
			cout<<"nhap vao ten cua hang"<<endl;
			fflush(stdin);
			gets(tenCuaHang);
			do{
				cout<<"nhap vao so luong hangMM: ";
				cin>>n;	
			}while(n<=0||n>=20);
			
			x = new HangMM[n];
			
			for(int i = 0  ; i < n;i++){
				cout<<"thong tin hangMM thu tu:"<<i+1<<endl;
				x[i].nhap();
			}
		}
		
		void xuat(){
			cout<<"ma cua hang la: "<<maCuaHang<<endl;
			cout<<"ten cua hang la: "<<tenCuaHang<<endl;
			cout<<setw(20)<<"chatLieu"<<setw(20)<<"kieuDang"<<setw(20)<<"soLuong"<<endl;
			for(int i = 0  ; i < n;i++){
				x[i].xuat();
			}
		}
		
		friend void suaTenCuaHang(CuaHang& cuaHang); 
	    friend void sapXep(CuaHang& cuaHang);
		
};

 void suaTenCuaHang(CuaHang& cuaHang){
 	   strcpy(cuaHang.tenCuaHang,"IVY"); 
 }
 
 void sapXep(CuaHang& cuaHang){ 
    for(int i = 0; i < cuaHang.n - 1; i++){
        for(int j = i+1; j < cuaHang.n; j++){
            if(cuaHang.x[i].soLuong < cuaHang.x[j].soLuong){
                swap(cuaHang.x[i], cuaHang.x[j]);
            }
        }
    }
}


int main(){
	CuaHang cuaHang;
	cuaHang.nhap();
	cuaHang.xuat();
	cout<<"sau khi sua thong tin:"<<endl;
	suaTenCuaHang(cuaHang);
	cuaHang.xuat(); 
	cout << "\nSau khi sap xep HangMM theo so luong:\n";
    sapXep(cuaHang);
    cuaHang.xuat();
}
