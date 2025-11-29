#include <bits/stdc++.h>
using namespace std;

class PhanSo {
    int ts, ms;

public
    friend istream& operator>>(istream& x, PhanSo& y) {
        cout << "Nhap vao tu so: ";
        x >> y.ts;
        cout << "Nhap vao mau so: ";
        x >> y.ms;

        while (y.ms == 0) {
            cout << "Mau so khong duoc bang 0! Nhap lai: ";
            x >> y.ms;
        }

        return x;
    }

    friend ostream& operator<<(ostream& x, const PhanSo& y) {
        x << y.ts << "/" << y.ms;
        return x;
    }


    PhanSo operator+(PhanSo p) {
        PhanSo kq;
        kq.ms = ms * p.ms;
        kq.ts = ts * p.ms + p.ts * ms;
        return kq;
    }
};

int main() {
    PhanSo a, b;

    cout << "Nhap vao phan so 1:\n";
    cin >> a;

    cout << "\nNhap vao phan so 2:\n";
    cin >> b;

    PhanSo cong = a + b;

    cout << "\nKet qua cong 2 phan so: ";
    cout << cong << endl;

}

