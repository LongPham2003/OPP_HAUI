#include<bits/stdc++.h> 
using namespace std;

class PhanSo{
	private: 
	int ts , ms; 
	
	public:
		PhanSo() {
        ts = 0;
        ms = 1;
    }
	PhanSo(int ts,int ms){
		this->ts = ts;
		this->ms = ms; 
	}
	
	 friend istream& operator >> (istream&x,PhanSo& ps){
	 	cout<<"nhap vao tu so"<<endl;
		x>>ps.ts;
		cout<<"nhap vao mau so" <<endl;
		x>>ps.ms; 
		
		return x; 
	 }
	 
	 friend ostream& operator << (ostream&x , PhanSo ps){
	 	x<<ps.ts<<"/"<<ps.ms; 
	 	return x; 
	 } 
	 
	 PhanSo operator +(PhanSo p){
	 	PhanSo kq;
		kq.ms = p.ms * ms;
		kq.ts = ts * p.ms + p.ts * ms ;
		return kq; 
	 } 
	 
	 PhanSo operator -(PhanSo p){
	 	PhanSo kq;
		kq.ts =  ts * p.ms - p.ts * ms ;
		kq.ms = p.ms * ms;
		return kq; 
	 } 
	 
	 
	 float operator --(){
	 	return (float)ts/ms; 
	 } 
	 
} ;

int main(){
	PhanSo a,b;
	
	
	cout<<"nhap vao ps a " <<endl;
	cin>>a;
	cout<<"nhap vao ps b " <<endl;
	cin>>b;
	
	PhanSo	tong = a + b;
	PhanSo hieu = a - b; 
    float value = --a; 
	
	cout<< tong<<endl; 
	cout<< hieu<<endl;	
	
	cout<<value<<endl; 
	
	 
} 
