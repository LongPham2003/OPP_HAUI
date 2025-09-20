#include<bits/stdc++.h> 
using namespace std;
class HocSinh{
	private:
		
	char hoTen[30];
    int ngay, thang, nam;
    char gioiTinh[10];
    float diemTB;
    char xepLoai[20];
		
		public:
		void nhap(){
			cout << "nhap vao ho ten ";
			cin.getline(hoTen,30);
			cout << "Nhap ngay sinh: ";
			cin >> ngay;
            cout << "Nhap thang sinh: ";
		    cin >> thang;
            cout << "Nhap nam sinh: "; 
		    cin >> nam;
		    cin.ignore(); 
		    cout << "nhap vao gioi tinh: ";
		    cin.getline(gioiTinh,10);
		    cout<<"nhap vao diem trung binh: ";
			cin>>diemTB; 
			cin.ignore(); 
		    cout << "nhap vao xep loai dao duc: ";
		    cin.getline(xepLoai,20);
		}	
     	const char* xepLoaiHocLuc(){
		if (diemTB < 5) return "Yeu";
        if (diemTB < 6.5) return "Trung binh";
        if (diemTB < 8) return "Kha";
        return "Gioi";
		} 
		void xuat(){
		 cout << "\n===== THONG TIN HOC SINH =====\n";
		 cout << "Ho ten: " << hoTen << "\n";
         cout << "Ngay sinh: " << ngay << "/" << thang << "/" << nam << "\n";
         cout << "Gioi tinh: " << gioiTinh << "\n";
         cout << "Diem trung binh: " << diemTB << "\n";
         cout << "Xep loai dao duc: " << xepLoai<< "\n";
         cout << "Xep loai hoc luc: " << xepLoaiHocLuc() << "\n";
		}
};

int main(){
	HocSinh hs;
	hs.nhap();
	hs.xuat();
}
