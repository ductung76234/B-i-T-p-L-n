#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class MatHang {
public:
    string maHang;   // Mã hàng
    string tenHang;  // Tên hàng
    float gia;       // Giá hàng
    int soLuong;     // S? l??ng hàng

    void nhap() {
        // Hàm nh?p thông tin m?t hàng
        cout << "Nhap ma hang: ";
        cin >> maHang;
        cout << "Nhap ten hang: ";
        cin.ignore();
        getline(cin, tenHang);
        cout << "Nhap gia: ";
        cin >> gia;
        cout << "Nhap so luong: ";
        cin >> soLuong;
    }

    void hienThi() const {
        // Hàm hi?n th? thông tin m?t hàng
        cout << "Ma hang: " << maHang << endl;
        cout << "Ten hang: " << tenHang << endl;
        cout << "Gia: " << gia << endl;
        cout << "So luong: " << soLuong << endl;
    }
};

void themMoi(vector<MatHang> &danhSach) {
    // Hàm thêm m?i m?t m?t hàng vào danh sách
    MatHang mh;
    mh.nhap();
    danhSach.push_back(mh);
}

void sua(vector<MatHang> &danhSach) {
    // Hàm s?a thông tin m?t m?t hàng
    string maHang;
    cout << "Nhap ma hang can sua: ";
    cin >> maHang;
    for (auto &mh : danhSach) {
        if (mh.maHang == maHang) {
            mh.nhap();
            return;
        }
    }
    cout << "Khong tim thay mat hang co ma " << maHang << endl;
}

void xoa(vector<MatHang> &danhSach) {
    // Hàm xóa m?t m?t hàng kh?i danh sách
    string maHang;
    cout << "Nhap ma hang can xoa: ";
    cin >> maHang;
    for (auto it = danhSach.begin(); it != danhSach.end(); ++it) {
        if (it->maHang == maHang) {
            danhSach.erase(it);
            cout << "Da xoa mat hang co ma " << maHang << endl;
            return;
        }
    }
    cout << "Khong tim thay mat hang co ma " << maHang << endl;
}

void timKiem(const vector<MatHang> &danhSach) {
    // Hàm tìm ki?m m?t hàng theo mã hàng
    string maHang;
    cout << "Nhap ma hang can tim: ";
    cin >> maHang;
    for (const auto &mh : danhSach) {
        if (mh.maHang == maHang) {
            mh.hienThi();
            return;
        }
    }
    cout << "Khong tim thay mat hang co ma " << maHang << endl;
}

void sapXep(vector<MatHang> &danhSach) {
    // Hàm s?p x?p m?t hàng theo giá t?ng d?n
    sort(danhSach.begin(), danhSach.end(), [](const MatHang &a, const MatHang &b) {
        return a.gia < b.gia;
    });
    cout << "Da sap xep xong." << endl;
}

void luuFile(const vector<MatHang> &danhSach, const string &fileName) {
    // Hàm l?u danh sách m?t hàng vào file
    ofstream file(fileName);
    if (file.is_open()) {
        for (const auto &mh : danhSach) {
            file << mh.maHang << " " << mh.tenHang << " " << mh.gia << " " << mh.soLuong << endl;
        }
        file.close();
        cout << "Da luu du lieu vao file " << fileName << endl;
    } else {
        cout << "Khong the mo file " << fileName << endl;
    }
}

void docFile(vector<MatHang> &danhSach, const string &fileName) {
    // Hàm ??c d? li?u t? file vào danh sách
    ifstream file(fileName);
    if (file.is_open()) {
        danhSach.clear();
        MatHang mh;
        while (file >> mh.maHang >> mh.tenHang >> mh.gia >> mh.soLuong) {
            danhSach.push_back(mh);
        }
        file.close();
        cout << "Da doc du lieu tu file " << fileName << endl;
    } else {
        cout << "Khong the mo file " << fileName << endl;
    }
}

void thongKe(const vector<MatHang> &danhSach) {
    // Hàm th?ng kê t?ng giá tr? hàng hóa trong kho
    float tongGiaTri = 0;
    for (const auto &mh : danhSach) {
        tongGiaTri += mh.gia * mh.soLuong;
    }
    cout << "Tong gia tri hang hoa trong kho: " << tongGiaTri << endl;
}

int main() {
    vector<MatHang> danhSach;
    int luaChon;
    string fileName = "danhSachMatHang.txt";

    do {
        // Menu ?? ng??i dùng ?i?u khi?n ch??ng trình
        cout << "1. Them moi mat hang" << endl;
        cout << "2. Sua thong tin mat hang" << endl;
        cout << "3. Xoa mat hang" << endl;
        cout << "4. Tim kiem mat hang" << endl;
        cout << "5. Sap xep mat hang" << endl;
        cout << "6. Luu danh sach vao file" << endl;
        cout << "7. Doc danh sach tu file" << endl;
        cout << "8. Thong ke gia tri hang hoa" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch(luaChon) {
            case 1:
                themMoi(danhSach);
                break;
            case 2:
                sua(danhSach);
                break;
            case 3:
                xoa(danhSach);
                break;
            case 4:
                timKiem(danhSach);
                break;
            case 5:
                sapXep(danhSach);
                break;
            case 6:
                luuFile(danhSach, fileName);
                break;
            case 7:
                docFile(danhSach, fileName);
                break;
            case 8:
                thongKe(danhSach);
                break;
            case 0:
                cout << "Thoat chuong trinh" << endl;
                break;
            default:
                cout << "Lua chon khong hop le" << endl;
        }
    } while(luaChon != 0);

    return 0;
}

