#include <stdio.h>
#include <string.h>

struct VeMayBay {
    char maPNR[10];
    char tenHanhKhach[50];
    char hangVe[15];
    float trongLuongHanhLy;
    long phiPhuThu;
};

int main() {
    int n, i;
    struct VeMayBay danhSach[50];
    
    do {
        printf("Nhap so luong ve (1 - 50): ");
        scanf("%d", &n);
        if (n < 1 || n > 50) {
            printf("So luong khong hop le! Vui long nhap lai.\n");
        }
    } while (n < 1 || n > 50);
    
    while (getchar() != '\n');
    
    for (i = 0; i < n; i++) {
        printf("\n--- Nhap thong tin ve thu %d ---\n", i + 1);
        
        printf("Nhap ma PNR: ");
        fgets(danhSach[i].maPNR, sizeof(danhSach[i].maPNR), stdin);
        danhSach[i].maPNR[strcspn(danhSach[i].maPNR, "\n")] = 0;
        
        printf("Nhap ho ten hanh khach: ");
        fgets(danhSach[i].tenHanhKhach, sizeof(danhSach[i].tenHanhKhach), stdin);
        danhSach[i].tenHanhKhach[strcspn(danhSach[i].tenHanhKhach, "\n")] = 0;
        
        printf("Nhap hang ve (Eco/Deluxe/Business): ");
        fgets(danhSach[i].hangVe, sizeof(danhSach[i].hangVe), stdin);
        danhSach[i].hangVe[strcspn(danhSach[i].hangVe, "\n")] = 0;
        
        printf("Nhap trong luong hanh ly (kg): ");
        scanf("%f", &danhSach[i].trongLuongHanhLy);
        while (getchar() != '\n');
        
        if (danhSach[i].trongLuongHanhLy > 7.0) {
            danhSach[i].phiPhuThu = (long)((danhSach[i].trongLuongHanhLy - 7.0) * 50000);
        } else {
            danhSach[i].phiPhuThu = 0;
        }
    }
    
    printf("\n=== DANH SACH VE MAY BAY CHUYEN BAY ===\n");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("%-5s %-10s %-25s %-12s %-12s %-15s\n", "STT", "MA PNR", "HO TEN HANH KHACH", "HANG VE", "HANH LY(KG)", "PHI PHU THU(VND)");
    printf("-----------------------------------------------------------------------------------------\n");
    
    for (i = 0; i < n; i++) {
        printf("%-5d %-10s %-25s %-12s %-12.1f %-15ld\n", 
               i + 1, 
               danhSach[i].maPNR, 
               danhSach[i].tenHanhKhach, 
               danhSach[i].hangVe, 
               danhSach[i].trongLuongHanhLy, 
               danhSach[i].phiPhuThu);
    }
    printf("-----------------------------------------------------------------------------------------\n");
    
    char searchPNR[10];
    int foundIndex = -1;
    
    printf("\n=== CAP NHAT THONG TIN HANH LY ===\n");
    printf("Nhap ma PNR can cap nhat: ");
    fgets(searchPNR, sizeof(searchPNR), stdin);
    searchPNR[strcspn(searchPNR, "\n")] = 0;
    
    for (i = 0; i < n; i++) {
        if (strcmp(danhSach[i].maPNR, searchPNR) == 0) {
            foundIndex = i;
            break;
        }
    }
    
    if (foundIndex != -1) {
        printf("Tim thay ve cua hanh khach: %s\n", danhSach[foundIndex].tenHanhKhach);
        printf("Nhap trong luong hanh ly moi (kg): ");
        scanf("%f", &danhSach[foundIndex].trongLuongHanhLy);
        
        if (danhSach[foundIndex].trongLuongHanhLy > 7.0) {
            danhSach[foundIndex].phiPhuThu = (long)((danhSach[foundIndex].trongLuongHanhLy - 7.0) * 50000);
        } else {
            danhSach[foundIndex].phiPhuThu = 0;
        }
        
        printf("Cap nhat thanh cong! Phi phu thu moi: %ld VND\n", danhSach[foundIndex].phiPhuThu);
        
        printf("\n=== DANH SACH VE MAY BAY SAU CAP NHAT ===\n");
        printf("-----------------------------------------------------------------------------------------\n");
        printf("%-5s %-10s %-25s %-12s %-12s %-15s\n", "STT", "MA PNR", "HO TEN HANH KHACH", "HANG VE", "HANH LY(KG)", "PHI PHU THU(VND)");
        printf("-----------------------------------------------------------------------------------------\n");
        
        for (i = 0; i < n; i++) {
            printf("%-5d %-10s %-25s %-12s %-12.1f %-15ld\n", 
                   i + 1, 
                   danhSach[i].maPNR, 
                   danhSach[i].tenHanhKhach, 
                   danhSach[i].hangVe, 
                   danhSach[i].trongLuongHanhLy, 
                   danhSach[i].phiPhuThu);
        }
        printf("-----------------------------------------------------------------------------------------\n");
    } else {
        printf("Khong tim thay ma PNR hop le trong he thong!\n");
    }
    
    return 0;
}
