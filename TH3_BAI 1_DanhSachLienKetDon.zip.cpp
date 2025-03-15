#include <iostream>
using namespace std;

// ??nh ngh?a c?u trúc m?t Node
struct Node
{
    int data;
    Node* next;
};

// ??nh ngh?a danh sách liên k?t
struct ListInt
{
    Node* head;
};

// Hàm kh?i t?o danh sách liên k?t
void KhoiTao(ListInt& list)
{
    list.head = NULL;
}

// Hàm h?y danh sách liên k?t
void HuyDanhSach(ListInt& list)
{
    Node* temp;
    while (list.head != NULL)
    {
        temp = list.head;
        list.head = list.head->next;
        delete temp;
    }
}

// Hàm thêm ph?n t? vào ??u danh sách
void ThemDau(ListInt& list, int x)
{
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = list.head;
    list.head = newNode;
}

// Hàm xóa ph?n t? có giá tr? x trong danh sách
void XoaPhanTu(ListInt& list, int x)
{
    if (list.head == NULL) return;
    Node* temp = list.head;
    Node* prev = NULL;

    // N?u ph?n t? c?n xóa n?m ? ??u danh sách
    if (temp != NULL && temp->data == x)
    {
        list.head = temp->next;
        delete temp;
        return;
    }

    // Tìm ph?n t? c?n xóa
    while (temp != NULL && temp->data != x)
    {
        prev = temp;
        temp = temp->next;
    }
    // N?u không tìm th?y ph?n t?
    if (temp == NULL) return;

    // Xóa ph?n t?
    prev->next = temp->next;
    delete temp;
}

// Hàm thêm m?t danh sách khác vào danh sách hi?n t?i
void ThemDanhSach(ListInt& list1, ListInt& list2)
{
    if (list2.head == NULL) return;
    if (list1.head == NULL)
    {
        list1.head = list2.head;
        return;
    }

    Node* temp = list1.head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = list2.head;
}

// Hàm xu?t danh sách liên k?t
void XuatDanhSach(ListInt list)
{
    Node* temp = list.head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Hàm nh?p danh sách v?i n ph?n t?
void NhapDanhSach(ListInt& list, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Nh?p ph?n t? th? " << i + 1 << ": ";
        cin >> x;
        ThemDau(list, x);
    }
}

int main()
{
    ListInt list1, list2;
    KhoiTao(list1);
    KhoiTao(list2);

    // Nh?p 10 s? nguyên vào danh sách
    cout << "Nh?p 10 s? nguyên vào danh sách th? nh?t:" << endl;
    NhapDanhSach(list1, 10);

    // Xu?t danh sách
    cout << "Danh sách th? nh?t: ";
    XuatDanhSach(list1);

    // Nh?p s? c?n xóa và xóa kh?i danh sách
    int k;
    cout << "Nh?p s? c?n xóa: ";
    cin >> k;
    XoaPhanTu(list1, k);

    // Xu?t danh sách sau khi xóa
    cout << "Danh sách sau khi xóa " << k << ": ";
    XuatDanhSach(list1);

    // Nh?p 5 s? nguyên vào danh sách th? hai
    cout << "Nh?p 5 s? nguyên vào danh sách th? hai:" << endl;
    NhapDanhSach(list2, 5);

    // Thêm danh sách th? hai vào danh sách th? nh?t
    ThemDanhSach(list1, list2);

    // Xu?t danh sách th? nh?t sau khi ghép
    cout << "Danh sách th? nh?t sau khi ghép v?i danh sách th? hai: ";
    XuatDanhSach(list1);

    // H?y danh sách
    HuyDanhSach(list1);
    HuyDanhSach(list2);
    return 0;
}