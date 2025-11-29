#include<bits/stdc++.h>
using namespace std;
class MayIn{
	char TenMayIn[30];
	char MauSac[30];
	long GiaThanh;
	
	public:
	MayIn(){
		strcpy(TenMayIn,"");
		strcpy(MauSac,"");
		GiaThanh =  0;
	} 
	
	MayIn( char* ten , char* mau,long gia){
	    strcpy(TenMayIn,ten);
		strcpy(MauSac,mau);
		GiaThanh = gia;
	}
	
	friend istream& operator >> (istream& x , MayIn& mayIn){
		cout<<"nhap  vao ten may in: ";
		x>>mayIn.TenMayIn;
		cout<<"nhap  vao mau sac: ";
		x>>mayIn.MauSac;
		cout<<"nhap vao gia thanh: ";
		x>>mayIn.GiaThanh;
		return x;
	}
	
	friend ostream& operator << (ostream& x , MayIn mayIn){
		
		x<<"ten may in: "<<mayIn.TenMayIn<<endl;
		x<<"mau sac may in: "<<mayIn.MauSac<<endl;
		x<<"gia thanh may in: "<<mayIn.GiaThanh<<endl;
		return x;
		
	}
	
	bool operator ++(){
		if(strcmp(MauSac,"trang")==0&&GiaThanh>95){
			return true;
		}else{
			return false;
		}
	}
	
	bool operator ==(MayIn mayIn){
		if(strcmp(MauSac,mayIn.MauSac)==0){
			return true;
		}else{
			return false;
		}
	}
}; 

int main(){
	MayIn mayIn,mayIn1;
	cin>>mayIn;
	cout<<mayIn;
	cin>>mayIn1;
	cout<<mayIn1;
	
	if(++mayIn){
		cout<<"may in co  mau trang va gia lon hon 95";
	}else{
		cout<<"khong co may thoa man yeu cau";
	}
	
	if(mayIn==mayIn1){
		cout<<"may in cung ten";
	}else{
		cout<<"may in khac ten";
	}
}
