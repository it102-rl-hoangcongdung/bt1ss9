# Bao cao bai tap thuc hanh: Xay dung Module Quan ly va Check-in Ve May bay bang Mang Struct

> 👤 **Học viên:** Hoàng Công Dũng | **Mã SV:** PTIT-HCM-009
> 🏫 **Môn học:** it102-rl-hoangcongdung

---

## 📊 Sơ đồ thiết kế hệ thống (Activity Diagram)

> 💡 *Sơ đồ dưới đây được render tự động trực tiếp trên GitHub bằng Mermaid. Bạn cũng có thể tải file **`bt1.drawio`** trong repository này để mở và chỉnh sửa trực tiếp trên [Draw.io (diagrams.net)](https://app.diagrams.net).* 

```mermaid
graph TD
  Start([Bat dau chuong trinh]) --> InputN[Nhap so luong ve n hop le: 1 <= n <= 50]
  InputN --> LoopInit{For i = 0 den n - 1}
  LoopInit -- Con tiep --> ReadInfo[Nhap ma PNR, Ho ten, Hang ve, Trong luong]
  ReadInfo --> CleanBuffer[Xoa bo ky tu xuong dong trong bo dem fflush hoac getchar]
  CleanBuffer --> CalcFee{Trong luong > 7.0kg?}
  CalcFee -- Dung --> FeeYes[Phi phu thu = (Trong luong - 7.0) * 50000]
  CalcFee -- Sai --> FeeNo[Phi phu thu = 0]
  FeeYes --> NextLoop[Tang bien dem i]
  FeeNo --> NextLoop
  NextLoop --> LoopInit
  LoopInit -- Hoan tat --> PrintTable[Xuat bang danh sach ve may bay]
  PrintTable --> AskSearch[Nhap ma PNR can tim kiem]
  AskSearch --> SearchLinear{Tim kiem tuyen tinh trong mang struct}
  SearchLinear -- Tim thay --> ShowFound[Hien thi thong tin cu & Nhập trong luong moi]
  ShowFound --> UpdateFee[Tinh lai phi phu thu moi & Cap nhat vao struct]
  UpdateFee --> PrintNewTable[Xuat lai bang danh sach sau khi cap nhat]
  SearchLinear -- Khong thay --> ShowError[In thong bao Khong tim thay ma PNR hop le!]
  PrintNewTable --> End([Ket thuc chuong trinh])
  ShowError --> End
```

---

## 1. Muc tieu va Phan tich nghiep vu bai toan

Bai tap thuc hanh nay giup minh nam vung ky thuat su dung mang cau truc (Array of Struct) trong ngon ngu lap trinh C de giai quyet cac bai toan quan ly thuc te tai quay lam thu tục san bay.

He thong yeu cau luu tru thong tin ve may bay gom ma dat cho, ten hanh khach, hang ve, trong luong hanh ly va tu dong tinh toan phi phu thu dua tren han muc quy dinh cua hang hang khong.

- Ap dung cau truc struct VeMayBay luu tru danh sach toi da 50 ve.
- Xu ly triet de van de tro trôi bo dem ban phim khi dung ket hop scanf va fgets.
- Tu dong tinh tien phu thu neu hanh ly vuot qua 7.0 kg voi don gia 50000 VND / kg.

## 2. Giai phap ky thuat xu ly bo dem va Thuat toan tim kiem

Trong qua trinh viet code bang C, viec doc du lieu so bang scanf() de lai ky tu xuong dong '\n' trong bo dem ban phim. Neu khong xu ly bang lenh while (getchar() != '\n');, ham fgets() tiep theo se bi nuot mat ky tu dau tien.

Thuat toan tim kiem tuyen tinh (Linear Search) duoc su dung de duyet qua mang struct, ket hop ham strcmp() trong thu vien string.h de doi chieu ma PNR do nguoi dung nhap vao voi du lieu trong he thong.

- Su dung vong lap do-while de kiem tra rang buoc nhap so luong ve n trong khoang tu 1 den 50.
- Cai dat ham strcmp() dung chuan de so sanh chuoi khong bi loi ky tu.
- Dinh dang chuoi format trong printf() voi cac thong so nhu %-10s hoac %-12.1f de xuat bang thang hang chuyen nghiep.

## 3. Bang dac ta cac chuc nang chinh trong ham main()

Do chua hoc ve ham (Functions), toan bo logic chuong trinh duoc trien khai gon gang va mach lac ben trong ham main() theo cac buoc cu the sau:

| Chuc nang | Thao tac thuc hien | Dieu kien & Xu ly ky thuat | Ket qua dat duoc |
| --- | --- | --- | --- |
| Nhap so luong | Yeu cau nhap n | 1 <= n <= 50, dung do-while bat nhap lai neu sai | Xac dinh kich thuoc mang struct |
| Nhap danh sach | Duyet for nhap tung truong | Dung fgets va xoa bo dem '\n' an toan | Luu tru day du thong tin hanh khach |
| Tinh phu thu | Kiem tra trongLuongHanhLy | Neu > 7.0 thi tinh tien, neu <= 7.0 thi gan bang 0 | Hoan thien du lieu tai chinh ve |
| In danh sach | Dung printf can chinh cot | Su dung format %-10s, %-25s, %-12.1f | Hien thi bang terminal ro rang, dep mat |
| Tim kiem & Cap nhat | Nhap ma PNR va strcmp | Neu tim thay cho nhap lai trong luong va cap nhat | In lai bang du lieu moi nhat |

## 4. Huong dan bien dich va Kiem tra ma nguon

Ma nguon duoc luu tai file 'main.c' va co the bien dich truc tiep tren terminal cua he dieu hành Linux, macOS hoac Windows thong qua trinh bien dich GCC.

Cau lenh bien dich: 'gcc main.c -o main' va chay chuong trinh voi './main'.

- Dam bao repository GitHub dung to chuc 'it102-rl-hoangcongdung' va nop day du file.
- Kiem tra ky cac truong hop bien nhu nhap du lieu tran bo dem hoac tim kiem ma PNR khong ton tai.

---

## 📁 Danh sách tệp tin nộp bài trong Repository
- 📝 `bt1.docx`: Báo cáo tài liệu phân tích nghiệp vụ hoàn chỉnh.
- 🎨 `bt1.drawio`: File thiết kế sơ đồ chuẩn theo quy định đề bài (mở trực tiếp bằng [Draw.io](https://app.diagrams.net) hoặc Lucidchart).
- 💻 `main.c`: Mã nguồn chương trình.
