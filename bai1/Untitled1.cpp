#include <iostream>
using namespace std;

class HinhThang{
	private:
		double dayLon;
		double dayNho;
		double chieuCao;
	
	public:
		void nhap(){
			cout << "nhap do dai day lon ";
			cin >> dayLon;
			cout << "nhap do dai day nho ";
			cin >> dayNho;
			cout << "nhap do dai chieu cao ";
			cin >> chieuCao;
		}
		
		double dienTich(){
			return((dayLon + dayNho) * chieuCao) / 2;
		} 
		
		void xuat(){
			cout << "dien tich hinh thang la"  <<dienTich()<<endl;
		}	
};


	int main(){
			HinhThang ht ;
			ht.nhap();
			ht.xuat();
			return 1;
		}
