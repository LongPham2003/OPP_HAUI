#include<bits/stdc++.h>
using namespace std;

class  HangHoa{
	private:
		char maHang[5];
		char tenHang[30];
		double donGia;
		int soLuong;
		friend class PhieuMuaHang;
		
	public:
		void nhap(){
			cout<<"nhap ma hang: ";
			fflush(stdin);
			gets(maHang);
			cout<<"nhap ten hang: ";
			fflush(stdin);
			gets(tenHang);
			cout<<"nhap vao don gia: ";
			cin>>donGia;
			cout<<"nhap vao so luong: ";
			cin>>soLuong;	
		}
		
		void xuat(){
			cout<<"ma hang hoa: "<<maHang<<endl;
			cout<<"ten hang hoa: "<<tenHang<<endl;
			cout<<"don gia: "<<donGia<<endl;
			cout<<"so luong: "<<soLuong<<endl;
			cout<<"thanh tien "<<thanhTien()<<endl;
		}
		double thanhTien(){
			return donGia*soLuong;
		}
};

class PhieuMuaHang{
	private:
		char maPhieu[5];
		char maNguoiLapPhieu[5];
		char ngayLapPhieu[30];
		char hoTen[30];
		char khachHang[30]; 
		int n;
		HangHoa *h;
	public:
		void nhap(){
			cout<<"nhap ma phieu: ";
			fflush(stdin);
			gets(maPhieu);
			cout<<"nhap ma nguoi lap phieu: ";
			fflush(stdin);
			gets(maNguoiLapPhieu);
			cout<<"nhap ngay lap phieu dd/mm/yyyy: ";
			fflush(stdin);
			gets(ngayLapPhieu);
			cout<<"nhap ho ten: ";
			fflush(stdin);
			gets(hoTen);
			cout<<"nhap khach hang: ";
			fflush(stdin);
			gets(khachHang);
			cout<<"nhap so hang hoa: ";
			cin>>n;
			h = new HangHoa[n];
			for(int i = 0 ; i<n ; i++ ){
				cout<<"nhap hang hoa thu "<<i+1<<endl;
				h[i]. nhap();
			}
			
		}
		
		void xuat(){
				cout<<" ma phieu: "<<maPhieu<<endl;
				cout<<" ma nguoi lap  phieu: "<<maNguoiLapPhieu<<endl;
				cout<<" ngay lap phieu "<<ngayLapPhieu<<endl;
				cout<<" ho ten: "<<hoTen<<endl;
				cout<< "khach hang: "<<khachHang<<endl;
				cout<<"danh muc hang hoa"<<endl;
				for(int i = 0 ; i < n ; i++){
					h[i].xuat();
				}
				

				long tongTien = 0;
				for(int i = 0; i < n;i++){
					tongTien+=h[i].thanhTien();
				}
				
			    cout<<"tong tien:"<<tongTien;
		}
		
		void demMatHangMaxSoLuong() {
			    if (n == 0) {
			        cout << "Khong co hang hoa nao.\n";
			        return;
			    }
			
			    int maxSoLuong = h[0].soLuong;
			    for (int i = 1; i < n; i++) {
			        if (h[i].soLuong > maxSoLuong) {
			            maxSoLuong = h[i].soLuong;
			        }
			    }
			
			    int count = 0;
			    for (int i = 0; i < n; i++) {
			        if (h[i].soLuong == maxSoLuong) {
			            count++;
			        }
			    }
			    cout << "\nSo luong mat hang co so luong mua lon nhat (" 
			         << maxSoLuong << ") la: " << count << endl;
			}

};

int main(){
	PhieuMuaHang pmh;
	pmh.nhap();
	pmh.xuat();
	  pmh.demMatHangMaxSoLuong();
}
