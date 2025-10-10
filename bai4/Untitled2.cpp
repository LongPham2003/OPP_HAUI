#include<bits/stdc++.h>
using namespace std;

class IdSach{
	public: 
	char tenSach[30];
	int maSach;
	
	public:
		void nhap(){
			cout<<"nhap vao ten sach: ";
			fflush(stdin);
			gets(tenSach);
			cout<<"nhap vao ma sach: ";
			cin>>maSach ;
		}
		
		void xuat(){
			cout<<"ten sach la: "<<tenSach<<endl;
			cout<<"ma sach la: "<<maSach<<endl;
		}
};
class TacGia{
	private:
	char tenTacGia[30];
	char diaChiTG[30];
	friend class SachGK; 
};

class NXB{
	private:
	char tenNXB[30];
	char diaChiNXB[30];
	friend class SachGK; 
};


class SachGK:public IdSach{
	private:
	TacGia tg;
	NXB nxb;
	
	public:
		void nhap(){
			IdSach::nhap();
			cout<<"nhap vao ten tac gia: ";
			fflush(stdin);
			gets(tg.tenTacGia);
			cout<<"nhap vao dia chi tac gia: ";
			fflush(stdin);
			gets(tg.diaChiTG);
			cout<<"nhap vao ten nxb: ";
			fflush(stdin);
			gets(nxb.tenNXB);
			cout<<"nhap vao dia chi nxb: ";
			fflush(stdin);
			gets(nxb.diaChiNXB);
			
		}
		
	   void xuat(){
	   	   IdSach::xuat();
	   	   cout<<"ten tac gia la: "<<tg.tenTacGia<<endl;
	   	   cout<<"dia chi tac gia la: "<<tg.diaChiTG<<endl;
	   	   cout<<"ten nxb: "<<nxb.tenNXB<<endl;
	   	   cout<<"dia chi nxb: "<<nxb.diaChiNXB<<endl;
	   }
	   
	   char* getTenNhaXB(){
	    	return nxb.tenNXB;
	   }
	   char* getTenTG(){
	    	return tg.tenTacGia;
	   } 
	   
	   int getMaSach(){
	   	return maSach; 
	   } 
	   
};

int main(){
	int n;
	do{
		cout<<"nhap vao so sach: "<<endl;
		cin>>n;
	}while(n<=0||n>=100);
	
	SachGK sgk[n];
	
	for(int i = 0 ; i < n ; i++){
		cout<<"nhap thong tin sach thu "<<i+1<<endl;
		sgk[i].nhap();
	}
	for(int i = 0 ; i < n ; i++){
		cout<<"------Thong tin sach-----"<<i+1<<endl;
		sgk[i].xuat();
	}
	cout<<"TEN SACH CO NXB KIMDONG VA TENTG PHAM VAN AT"<<endl ;
	for(int i = 0 ; i < n ; i++){
		if(strcmp(sgk[i].getTenNhaXB(),"KIMDONG") == 0 && strcmp(sgk[i].getTenTG(),"Pham Van At")==0){
			sgk[i].xuat(); 
		}
	}
	
	
	for(int i = 0 ; i < n-1 ; i++){
		for(int j = i+1;j<n;j++){
			if(sgk[i].getMaSach()<sgk[j].getMaSach()){
				SachGK tam = sgk[i];
				sgk[i]=sgk[j];
				sgk[j]=tam; 
			} 
		} 
	}
	cout<<"Sap xep sach theo chieu giam dan cua ma sach" <<endl; 
	  for (int i = 0; i < n; i++) {
        cout << "\n--- Sach thu " << i + 1 << " ---\n";
        sgk[i].xuat();
    }
	
	
	
	
}
