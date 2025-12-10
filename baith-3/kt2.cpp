#include<bits/stdc++.h>
using namespace std;

class NhiThuc{
	float a ;
	float b ;
	
	public:
	NhiThuc(){
		a = 1 ; 
		b= 3;
	};
	NhiThuc(float x , float y){
		a = x;
		b = y; 
	};
	~NhiThuc(){
	};
	
	friend istream& operator >> (istream& in, NhiThuc & x){
		cout<<"nhap vao a";
		in>>x.a;
		cout<<"nhap vao b";
		in>>x.b; 
		return  in; 
	} 
		friend ostream& operator << (ostream& out, NhiThuc x){
		out<<x.a<<x.b; 
	} 
}; 

int main() {
    NhiThuc a, b;
    cin >> a;
    cin >> b;

    cout << "A = " << a << endl;
    cout << "B = " << b << endl;

    return 0;
}
