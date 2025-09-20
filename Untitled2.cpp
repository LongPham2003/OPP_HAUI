#include<bits/stdc++.h> 
using namespace std;

class HinhTron{
	private:
		
		double banKinh;
	
	public:
		void nhap(){
			cout<<"nhap ban kinh hinh tron ";
			cin>> banKinh; 
		} 
		
		double dienTich(){
			return   M_PI * banKinh * banKinh; 
		} 
		
		double chuVi(){
			return  2 * M_PI * banKinh; 
		} 	 
		
		void xuat(){
			cout<<"chu vi ht la : " <<chuVi()<< endl; 
			cout<<"dien tich ht la : " <<dienTich() <<endl; 
		} 
}; 
 
 int main(){
 	HinhTron ht ;
	  ht.nhap(); 
	  ht.xuat();
 } 
