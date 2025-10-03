#include <bits/stdc++.h>
using namespace std;

class HocSinh {
private:
    char hoTen[50];
    int tuoi;
    float diemToan, diemLy, diemHoa;

public:
    HocSinh() {
        strcpy(hoTen, "");
        tuoi = 0;
        diemToan = diemLy = diemHoa = 0.0;
    }

    HocSinh(const char* ht, int t, float toan, float ly, float hoa) {
        strcpy(hoTen, ht);
        tuoi = t;
        diemToan = toan;
        diemLy = ly;
        diemHoa = hoa;
    }

    void xuat() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "Diem Toan: " << diemToan << endl;
        cout << "Diem Ly: " << diemLy << endl;
        cout << "Diem Hoa: " << diemHoa << endl;
    }
};

int main() {
	// khoi tao bang co doi 
    HocSinh hs1("Nguyen Van A", 18, 8.5, 7.5, 9.0);
    hs1.xuat();
    
    // khoi tao k doi mac dinh 
    HocSinh hs2;
    hs2.xuat();

    return 0;
}

