#include <bits/stdc++.h>
using namespace std;

class SCHOOL {
private:
    char name[50];
    char date[20];
public:
    void nhap() {
        cout << "Nhap ten truong: ";
        fflush(stdin);
        gets(name);
        cout << "Nhap ngay thanh lap truong: ";
        fflush(stdin);
        gets(date);
    }

    void xuat() {
        cout << "Ten truong: " << name << endl;
        cout << "Ngay thanh lap: " << date << endl;
    }

    void setName() {
        strcpy(name, "DHCNHN");
    }
};

class FACULTY {
private:
    char name[50];
    char date[20];
    SCHOOL x; 
public:
    void nhap() {
        cout << "Nhap ten khoa: ";
        fflush(stdin);
        gets(name);
        cout << "Nhap ngay thanh lap khoa: ";
        fflush(stdin);
        gets(date);
        cout << "=== Nhap thong tin truong ===\n";
        x.nhap();
    }

    void xuat() {
        cout << "Ten khoa: " << name << endl;
        cout << "Ngay thanh lap khoa: " << date << endl;
        x.xuat();
    }
    
     void doiTenTruong() {
        x.setName();
    }

};

class PERSON {
protected:
    char name[50];
    char birth[20];
    char address[100];
public:
    void nhap() {
        cout << "Nhap ho ten: ";
        fflush(stdin);
        gets(name);
        cout << "Nhap ngay sinh: ";
        fflush(stdin);
        gets(birth);
        cout << "Nhap dia chi: ";
        fflush(stdin);
        gets(address);
    }

    void xuat() {
        cout << "Ho ten: " << name << endl;
        cout << "Ngay sinh: " << birth << endl;
        cout << "Dia chi: " << address << endl;
    }
    

};

class STUDENT : public PERSON {
private:
    FACULTY y;
    char className[20];
    float score;
public:
    void nhap() {
        cout << "=== Nhap thong tin sinh vien ===\n";
        PERSON::nhap();
        cout << "Nhap ten lop: ";
        fflush(stdin);
        gets(className);
        cout << "Nhap diem: ";
        cin >> score;
        y.nhap();
    }

    void xuat() {
        cout << "\n=== THONG TIN SINH VIEN ===\n";
        PERSON::xuat();
        cout << "Lop: " << className << endl;
        cout << "Diem: " << score << endl;
        y.xuat();
    }
    
     void suaTenTruong() {
        y.doiTenTruong();
    }
    
    
};

int main() {
    STUDENT sv;

    sv.nhap();

    cout << "\n\n--- THONG TIN SINH VIEN VUA NHAP ---\n";
    sv.xuat();
    sv.suaTenTruong(); 
    cout << "\n\n--- SAU KHI SUA TEN TRUONG ---\n";
    sv.xuat();

}

