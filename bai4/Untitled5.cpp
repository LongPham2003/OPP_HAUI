#include <bits/stdc++.h>
using namespace std;

class STU;

class SCH {
private:
    char name[30], Date[30];
    
    friend class FAC;
    friend class STU;
    friend void sua(STU &a);
};

class FAC {
private:
    char name[30], Date[30];
    SCH x;
public:
    void nhap() {
        cout << "Nhap Ten khoa: ";
        cin.getline(name, 30);
        cout << "Nhap Ngay TL khoa: ";
        cin.getline(Date, 30);
    }
    void xuat() {
        cout << "Ten khoa: " << name << endl;
        cout << "Ngay TL khoa: " << Date << endl;
        cout << "Ten truong: " << x.name << endl;
        cout << "Ngay TL truong: " << x.Date << endl;
    }
    friend class STU;
    friend void sua(STU &a);
};

class PER {
protected:
    char name[30], birt[30], add[30];
public:
    void nhap() {
        cout << "Nhap Ten SV: ";
        cin.getline(name, 30);
        cout << "Nhap Ngay sinh: ";
        cin.getline(birt, 30);
        cout << "Nhap Dia chi: ";
        cin.getline(add, 30);
    }
    void xuat() {
        cout << "Ten SV: " << name << endl;
        cout << "Ngay sinh: " << birt << endl;
        cout << "Dia chi: " << add << endl;
    }
    PER() {
        strcpy(name, "Le Van Hoa");
        strcpy(birt, "12/03/2005");
        strcpy(add, "123 Le Duan");
    }
};

class STU : public PER {
private:
    FAC y;
    char Class[10];
    float score;
public:
    void nhap() {
        PER::nhap();
        y.nhap();
        cout << "Nhap Lop: ";
        cin.getline(Class, 10);
        cout << "Nhap Diem: ";
        cin >> score;
        cin.ignore();
    }
    void xuat() {
        PER::xuat();
        y.xuat();
        cout << "Lop: " << Class << endl;
        cout << "Diem: " << score << endl;
    }
    STU() : PER() {
        strcpy(y.name, "CNTT");
        strcpy(y.Date, "3/3/2000");
        strcpy(y.x.name, "DHBKHN");
        strcpy(y.x.Date, "2/2/1990");
        strcpy(Class, "HTTT1");
        score = 9.5;
    }
    
   friend void sua(STU &a) {
    strcpy(a.y.x.name, "DHCNHN");
    }
};



int main() {
    STU a;
    cout << "--- Thong tin khoi tao: ---" << endl;
    a.xuat();

    cout << "\n--- Bat dau nhap thong tin moi: ---" << endl;
    a.nhap();

    sua(a);

    cout << "\nSV sau khi sau ten truong: " << endl;
    a.xuat();
    return 0;
}

