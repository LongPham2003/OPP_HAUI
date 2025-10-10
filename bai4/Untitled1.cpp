#include <bits/stdc++.h>
 using namespace std;
 
 class SanPham {
 	public:
 	char  maSp[30];
	char tenSp[30];
	char ngaySx[30];
	double trongLuong;
	char mauSac[30];
	public:
		void nhap(){
			cout<<"nhap masp";
			fflush(stdin);
			gets(maSp);
			cout<<"nhap tensp";
			fflush(stdin);
			gets(tenSp);
			cout<<"nhap vao ngay sx";
			fflush(stdin);
			gets(ngaySx);
			cout<<"nhap vao trong luong";
			fflush(stdin);
			cin>>trongLuong;
			cout<<"nhap vao mau sac";
			fflush(stdin);
			gets(mauSac);
		}
		void xuat(){
			cout<<"masp la: "<<maSp<<endl;
				cout<<"tensp la: "<<tenSp<<endl;
					cout<<"ngay sx la: "<<ngaySx<<endl;
						cout<<"trong luong la: "<<trongLuong<<endl;
							cout<<"mau sac la: "<<mauSac<<endl;
			
		}
 }; 
 
 class HangDienTu:public SanPham{
 	private:
 		int congSuat;
 		int dongDienSD;
 		
 	public:
 		void nhap(){
 			SanPham::nhap();
 			cout<<"nhap cong suat";
 			cin>>congSuat;
 			cout<<"nhap dong dien";
 			cin>>dongDienSD;
		 }
		 void xuat(){
		 	SanPham::xuat();
		 	cout<<"cong suat la: "<<congSuat;
		 	cout<<"dong dien sd la: "<<dongDienSD;
		 }
		 
		  double getTrongLuong() {
            return trongLuong;
    }
 };
 
 int main(){
 	int n;
 	do{
 		cout<<"nhap vao n";
 		cin>>n;
	 }while(n<=0||n>=50);
	 
	 HangDienTu hdt[n];
 	
 	for(int i= 0 ; i<n ;i++){
 		cout<<"nhap thong tin phieu dien tu";
 		hdt[i].nhap();
	 }
	 
	cout << "\n=== DANH SACH HANG DIEN TU ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nHang dien tu thu " << i + 1 << ":\n";
        hdt[i].xuat();
    }
    
    double minTL = hdt[0].getTrongLuong();
    for (int i = 1; i < n; i++) {
        if (hdt[i].getTrongLuong() < minTL)
            minTL = hdt[i].getTrongLuong();
    }
    
    cout << "\n=== CAC HANG DIEN TU CO TRONG LUONG THAP NHAT ===\n";
    for (int i = 0; i < n; i++) {
        if (hdt[i].getTrongLuong() == minTL)
        {
          hdt[i].xuat();
		}
           
    }
	 
 }
  
