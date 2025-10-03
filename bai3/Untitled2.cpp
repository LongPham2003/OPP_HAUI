#include <bits/stdc++.h>
using namespace std;

class Date {
private:
    int year;
public:
    void nhap() {
        cout << "Nhap nam san xuat: ";
        cin >> year;
    }
    void xuat() {
        cout << year;
    }
    int getYear() {
        return year;
    }
};

class XeHoi {
private:
    char nhanHieu[50];
    char hangSX[50];
    char kieuDang[50];
    char mauSon[30];
    Date namSX;
    char xuatXu[50];
    long giaBan;
public:
    void nhap() {
        cout << "Nhap nhan hieu: ";fflush(stdin); 
        gets(nhanHieu);
        cout << "Nhap hang san xuat: ";fflush(stdin); 
        gets(hangSX);
        cout << "Nhap kieu dang: ";fflush(stdin); 
        gets(kieuDang);
        cout << "Nhap mau son: ";fflush(stdin); 
        gets(mauSon);
        namSX.nhap();
        cout << "Nhap xuat xu: ";fflush(stdin); 
        gets(xuatXu);
        cout << "Nhap gia ban: ";fflush(stdin); 
        cin >> giaBan;
    }

    void xuat() {
        cout << "Nhan hieu: " << nhanHieu << endl;
        cout << "Hang SX: " << hangSX << endl;
        cout << "Kieu dang: " << kieuDang << endl;
        cout << "Mau son: " << mauSon << endl;
        cout << "Nam SX: "; namSX.xuat(); cout << endl;
        cout << "Xuat xu: " << xuatXu << endl;
        cout << "Gia ban: " << giaBan << endl;
        cout << "---------------------------" << endl;
    }

    char* getHangSX() {
        return hangSX;
    }

    long getGiaBan() {
        return giaBan;
    }
};

int main() {
    int n;
    cout << "Nhap so luong xe hoi: ";
    cin >> n;

    XeHoi *ds = new XeHoi[n];

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin xe thu " << i+1 << ":\n";
        ds[i].nhap();
    }

    cout << "\n=== Danh sach xe hoi vua nhap ===\n";
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
    }

    cout << "\n=== Cac xe cua hang Toyota ===\n";
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].getHangSX(), "Toyota") == 0) {
            ds[i].xuat();
        }
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (ds[i].getGiaBan() > ds[j].getGiaBan()) {
                swap(ds[i], ds[j]);
            }
        }
    }

    cout << "\n=== Danh sach xe hoi sau khi sap xep theo gia ban tang dan ===\n";
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
    }
}

