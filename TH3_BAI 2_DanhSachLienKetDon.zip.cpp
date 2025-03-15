#include <iostream>
#include <cstring>

using namespace std;

// Cấu trúc SinhVien
struct SinhVien
{
    char HoTen[50];
    char DiaChi[70];
    char Lop[10];
    int Khoa;
};

// Cấu trúc Node cho danh sách liên kết
struct Node
{
    SinhVien data;
    Node* next;
};

// Khởi tạo danh sách liên kết
void KhoiTaoDanhSach(Node*& head)
{
    head = NULL;
}

// Hàm tạo một sinh viên
SinhVien TaoSinhVien(const char* hoten, const char* diachi, const char* lop, int khoa)
{
    SinhVien sv;
    strcpy(sv.HoTen, hoten);
    strcpy(sv.DiaChi, diachi);
    strcpy(sv.Lop, lop);
    sv.Khoa = khoa;
    return sv;
}

// Hàm thêm sinh viên vào đầu danh sách
void ThemSinhVien(Node*& head, SinhVien sv)
{
    Node* p = new Node;
    p->data = sv;
    p->next = head;
    head = p;
}

// Hàm xuất danh sách sinh viên
void XuatDanhSach(Node* head)
{
    Node* p = head;
    while (p != NULL)
    {
        cout << "Ho Ten: " << p->data.HoTen << ", Dia Chi: " << p->data.DiaChi
            << ", Lop: " << p->data.Lop << ", Khoa: " << p->data.Khoa << endl;
        p = p->next;
    }
}

// Hàm xóa sinh viên theo tên
void XoaSinhVienTheoTen(Node*& head, const char* hoten)
{
    Node* p = head;
    Node* truoc = NULL;
    while (p != NULL)
    {
        if (strcmp(p->data.HoTen, hoten) == 0)
        {
            if (p == head)
                head = p->next;
            else
                truoc->next = p->next;
            delete p;
            return;
        }
        truoc = p;
        p = p->next;
    }
}

// Hàm xóa sinh viên theo địa chỉ
void XoaSinhVienTheoDiaChi(Node*& head, const char* diachi)
{
    Node* p = head;
    Node* truoc = NULL;
    while (p != NULL)
    {
        if (strcmp(p->data.DiaChi, diachi) == 0)
        {
            if (p == head)
                head = p->next;
            else
                truoc->next = p->next;
            delete p;
            return;
        }
        truoc = p;
        p = p->next;
    }
}

// Hàm sắp xếp danh sách theo họ tên
void SapXepTheoHoTen(Node*& head) {
    for (Node* p = head; p != NULL; p = p->next)
    {
        for (Node* q = p->next; q != NULL; q = q->next)
        {
            if (strcmp(p->data.HoTen, q->data.HoTen) > 0)
            {
                swap(p->data, q->data);
            }
        }
    }
}

// Hàm xóa toàn bộ danh sách
void XoaToanBoDanhSach(Node*& head)
{
    Node* p;
    while (head != NULL)
    {
        p = head;
        head = head->next;
        delete p;
    }
}


int main()
{
    Node* danhSach;
    KhoiTaoDanhSach(danhSach);

    // Nhập 10 sinh viên vào danh sách
    ThemSinhVien(danhSach, TaoSinhVien("Nguyen Van A", "Ha Noi", "CTK45", 2020));
    ThemSinhVien(danhSach, TaoSinhVien("Le Thi B", "Hai Phong", "CTK44", 2019));
    ThemSinhVien(danhSach, TaoSinhVien("Tran Van C", "Da Nang", "CTK43", 2018));
    ThemSinhVien(danhSach, TaoSinhVien("Pham Thi D", "Can Tho", "CTK42", 2017));
    ThemSinhVien(danhSach, TaoSinhVien("Nguyen Van Teo", "TP HCM", "CTK41", 2016));
    ThemSinhVien(danhSach, TaoSinhVien("Bui Thi E", "Nghe An", "CTK40", 2015));
    ThemSinhVien(danhSach, TaoSinhVien("Do Van F", "Thanh Hoa", "CTK39", 2014));
    ThemSinhVien(danhSach, TaoSinhVien("Ngo Thi G", "Binh Dinh", "CTK38", 2013));
    ThemSinhVien(danhSach, TaoSinhVien("Pham Van H", "Khanh Hoa", "CTK37", 2012));
    ThemSinhVien(danhSach, TaoSinhVien("Vu Thi I", "Bac Giang", "CTK36", 2011));

    cout << "Danh sach sinh vien ban dau:\n";
    XuatDanhSach(danhSach);

    // Xóa sinh viên có tên "Nguyen Van Teo"
    XoaSinhVienTheoTen(danhSach, "Nguyen Van Teo");

    // Xóa sinh viên có địa chỉ "Nguyen Van Cu"
    XoaSinhVienTheoDiaChi(danhSach, "Nguyen Van Cu");

    // Thêm sinh viên mới
    ThemSinhVien(danhSach, TaoSinhVien("Tran Thi Mo", "25 Hong Bang", "TT0901", 2009));

    // Sắp xếp danh sách theo họ tên
    SapXepTheoHoTen(danhSach);

    cout << "\nDanh sach sau khi sap xep:\n";
    XuatDanhSach(danhSach);

    // Giải phóng bộ nhớ
    XoaToanBoDanhSach(danhSach);
    return 0;
}