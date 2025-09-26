#include<bits/stdc++.h>
using namespace std; 

class tamGiac{
	double a ,b ,c;
	bool isTamGiac(){
		return a+b > c && a + c > b && b + c >  a; 
	}
	
	public:
		void nhap(){
			cout<< "nhap vao canh a ";
			cin>> a;
			cout<< "nhap vao canh b "; 
			cin>> b;
			cout<<  "nhap vao canh c ";
			cin>> c; 
		} 
		double chuVi(){
			return a + b + c; 
		} 
		
		double dienTich(){
			double p = chuVi() / 2 ;
		 return sqrt(p * (p - a) * (p - b) * (p - c));
		} 
		
		void xuat(){
			if(isTamGiac()){
				cout<<"khong la tam giac"; 
				return;
			} 
			cout << "chu vi " <<chuVi()<< endl;
			cout << "dien tich "<<dienTich()<< endl; 
		}  
};
int main(){
	tamGiac tg;
	tg.nhap();
	tg.xuat(); 
} 

