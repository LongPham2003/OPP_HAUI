#include <bits/stdc++.h>
using namespace std;
class sinhvien{
	private: 
	int masv;
	char hoTen[30];
	double diemToan,diemLy, diemHoa;
	
	public: 
	void nhap(){
		cout<<"nhap vao masv: ";
		cin>>masv;
		cout<<"nhap vao ho tensv: ";
		fflush(stdin);
		gets(hoTen);
		cout<<"nhap vao diem toan: ";
		cin>>diemToan;
		cout<<"nhap vao diem ly: ";
		cin>>diemLy;
		cout<<"nhap vao diem hoa: ";
		cin>>diemHoa; 
	} 
	
	friend double tongDiem(sinhvien sv); 
	
	void xuat(){
		cout<<setw(10)<<masv<<setw(20)<<hoTen<<setw(20)<<diemToan<<setw(20)<<diemLy<<setw(20)<< diemHoa<<setw(20)<<tongDiem(*this)<<endl;
	} 
	
	
}; 

double tongDiem(sinhvien sv) {
    return sv.diemHoa + sv.diemLy + sv.diemToan;
}

int main() {
	int n; 
	do{
	    cout << "Nhap so luong sinh vien: ";
	    cin >> n;
	}while(n<=0||n>=20) ;
    
    sinhvien sv[n]; 

    cout << "\n--- NHAP THONG TIN SINH VIEN ---" << endl;
    
    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin cho SV thu " << i + 1 << ":" << endl;
        sv[i].nhap();
    }
    
    cout<<setw(10)<<"masv"<<setw(20)<<"ho ten"<<setw(20)<<"diem toan"<<setw(20)<<"diem ly"<<setw(20)<< "diem hoa"<<setw(20)<<"tong diem"<<endl;
     for (int i = 0; i < n; ++i) {
        sv[i].xuat();
    }
    
}


