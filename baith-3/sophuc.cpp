#include<bits/stdc++.h>
using namespace std;
class SoPhuc{
	int phanAo;
	int phanThuc;
	
	public:
	friend istream& operator >> (istream&x,SoPhuc& sp){
		cout<<"nhap vao phan thuc va phan ao";
		x>>sp.phanAo>>sp.phanThuc;
		return x; 
	} 
	
	friend ostream& operator << (ostream&x,SoPhuc sp){
		x<<sp.phanThuc<<"+"<<sp.phanAo<<"*I"<<endl;
		return x; 
	} 
	
	SoPhuc operator +(SoPhuc sp){
		SoPhuc kq;
		kq.phanThuc = sp.phanThuc + phanThuc;
		kq.phanAo = sp.phanAo + phanAo;
		return kq; 
	} 
	
	
	bool operator=(SoPhuc sp){
		if(phanThuc==sp.phanThuc && phanAo==sp.phanAo){
		return true;
		}
		else{
			return false; 
		} 
	} 
}; 

int main(){
	SoPhuc sp1,sp2; 
	cout<<"nhap vao so phuc 1"<<endl;
	cin>>sp1; 
	cout<<"nhap vao so phuc 2"<<endl;
	cin>>sp2;
    cout << "So phuc 1 = " << sp1 << endl;
    cout << "So phuc 2 = " << sp2 << endl; 
    SoPhuc cong = sp1+sp2; 
    cout << "Tong 2 so phuc" << cong << endl; 
    
	if(sp2=sp1){
		cout<<"so phuc duong" ;
	} else  {
		cout<<"so phuc am" ;
	}
} ;
