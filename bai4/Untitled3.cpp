#include <bits/stdc++.h>
using namespace std;

class HANG {
protected:
    char maHang[20];
    char tenHang[30];
    float gia;
public:
    void Nhap() {
        cout << "Nhap ma hang: ";
        fflush(stdin);
        gets(maHang);
        cout << "Nhap ten hang: ";
        fflush(stdin);
        gets(tenHang);
        cout << "Nhap gia: ";
        cin >> gia;
    }

    void Xuat() {
        cout << "Ma hang: " << maHang << endl;
        cout << "Ten hang: " << tenHang << endl;
        cout << "Gia: " << gia << endl;
    }
};

class HANG_MM : public HANG {
protected:
    char chatLieu[30];
    char kieuDang[30];
    int soLuong;
public:
    void Nhap() {
        HANG::Nhap();
        cout << "Nhap chat lieu: ";
        fflush(stdin);
        gets(chatLieu);
        cout << "Nhap kieu dang: ";
        fflush(stdin);
        gets(kieuDang);
        cout << "Nhap so luong: ";
        cin >> soLuong;
    }

    void Xuat() {
        HANG::Xuat();
        cout << "Chat lieu: " << chatLieu << endl;
        cout << "Kieu dang: " << kieuDang << endl;
        cout << "So luong: " << soLuong << endl;
    }

    int getSoLuong() {
        return soLuong;
    }
};

class CUAHANG {
private:
    char maCH[20];
    char tenCH[30];
    int n;
    HANG_MM *x;
public:
    void Nhap() {
        cout << "Nhap ma cua hang: ";
        fflush(stdin);
        gets(maCH);
        cout << "Nhap ten cua hang: ";
        fflush(stdin);
        gets(tenCH);
        cout << "Nhap so luong hang may mac: ";
        cin >> n;
        x = new HANG_MM[n];
        for (int i = 0; i < n; i++) {
            cout << "\n-- Nhap hang may mac thu " << i + 1 << " --\n";
            x[i].Nhap();
        }
    }

    void Xuat() {
        cout << "\n=== THONG TIN CUA HANG ===\n";
        cout << "Ma cua hang: " << maCH << endl;
        cout << "Ten cua hang: " << tenCH << endl;
        cout << "So luong hang may mac: " << n << endl;
        for (int i = 0; i < n; i++) {
            cout << "\n-- Hang may mac thu " << i + 1 << " --\n";
            x[i].Xuat();
        }
    }

    void suaTen() {
        if (strcmp(tenCH, "IVY") == 0) {
            strcpy(tenCH, "IVYMODA");
        }
    }

    void hienThiSoLuongLonHon25() {
        cout << "\n=== HANG CO SO LUONG > 25 ===\n";
        for (int i = 0; i < n; i++) {
            if (x[i].getSoLuong() > 25) {
                x[i].Xuat();
            }
        }
    }

};

int main() {
    CUAHANG ch;
    ch.Nhap();
    
    cout << "\n\nTHONG TIN CUA HANG TRUOC KHI SUA:\n";
    ch.Xuat();
    
    ch.suaTen();

    cout << "\n\nTHONG TIN CUA HANG SAU KHI SUA:\n";
    ch.Xuat();

    ch.hienThiSoLuongLonHon25();

}

