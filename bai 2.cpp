#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int phanNguyen;
	int tuSo;
	int mauSo;
} HonSo;

void taoMangHonSoNgauNhien(HonSo b[], int n);
void xuatDanhSachHonSo(HonSo b[], int n);
int soSanhHonSo(HonSo hs1, HonSo hs2);
void chuyenHonSoThanhPhanSo(HonSo hs, int *tuSo, int *mauSo);
HonSo chuyenPhanSoThanhHonSo(int tuSo, int mauSo);
HonSo tinhTong(HonSo hs1, HonSo hs2);
HonSo tinhHieu(HonSo hs1, HonSo hs2);
HonSo tinhTich(HonSo hs1, HonSo hs2);
HonSo tinhThuong(HonSo hs1, HonSo hs2);
void sapXepTangDan(HonSo b[], int n);
void sapXepGiamDan(HonSo b[], int n);
void bubbleSort(HonSo b[], int n, int tang);
void insertionSort(HonSo b[], int n, int tang);
void selectionSort(HonSo b[], int n, int tang);

int main() {
	time_t t = time(NULL);
	unsigned int covertedTime = static_cast <unsigned int> (t);
	int choice;
	int n = 5; // So luong phan tu trong mang hon so, ban co the dieu chinh
	HonSo b[100];

	// Tao mang hon so ngau nhien
	taoMangHonSoNgauNhien(b, n);

	do {
		// Menu
		printf("\nMENU:\n");
		printf("1. Xuat danh sach hon so\n");
		printf("2. So sanh hai hon so\n");
		printf("3. Chuyen hon so thanh phan so\n");
		printf("4. Chuyen phan so thanh hon so\n");
		printf("5. Tinh tong hai hon so\n");
		printf("6. Tinh hieu hai hon so\n");
		printf("7. Tinh tich hai hon so\n");
		printf("8. Tinh thuong hai hon so\n");
		printf("9. Sap xep mang tang dan\n");
		printf("10. Sap xep mang giam dan\n");
		printf("0. Thoat\n");
		printf("Chon chuc nang: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("\nDanh sach hon so:\n");
			xuatDanhSachHonSo(b, n);
			break;
		case 2:
		{
				  int idx1, idx2;
				  printf("Nhap hai chi so de so sanh (0-%d): ", n - 1);
				  scanf_s("%d %d", &idx1, &idx2);
				  if (idx1 >= 0 && idx1 < n && idx2 >= 0 && idx2 < n) {
					  int cmp = soSanhHonSo(b[idx1], b[idx2]);
					  if (cmp < 0)
						  printf("Hon so %d/%d nho hon hon so %d/%d\n", b[idx1].tuSo, b[idx1].mauSo, b[idx2].tuSo, b[idx2].mauSo);
					  else if (cmp > 0)
						  printf("Hon so %d/%d lon hon hon so %d/%d\n", b[idx1].tuSo, b[idx1].mauSo, b[idx2].tuSo, b[idx2].mauSo);
					  else
						  printf("Hai hon so bang nhau\n");
				  }
				  else {
					  printf("Chi so khong hop le\n");
				  }
		}
			break;
		case 3:
		{
				  int tu, mau;
				  printf("Nhap chi so de chuyen doi thanh phan so (0-%d): ", n - 1);
				  scanf_s("%d", &tu);
				  if (tu >= 0 && tu < n) {
					  chuyenHonSoThanhPhanSo(b[tu], &tu, &mau);
					  printf("Hon so %d/%d duoc chuyen thanh phan so %d/%d\n", b[tu].tuSo, b[tu].mauSo, tu, mau);
				  }
				  else {
					  printf("Chi so khong hop le\n");
				  }
		}
			break;
		case 4:
		{
				  int tu, mau;
				  printf("Nhap tu so va mau so de chuyen thanh hon so: ");
				  scanf_s("%d %d", &tu, &mau);
				  HonSo hs = chuyenPhanSoThanhHonSo(tu, mau);
				  printf("Phan so %d/%d duoc chuyen thanh hon so %d %d/%d\n", tu, mau, hs.phanNguyen, hs.tuSo, hs.mauSo);
		}
			break;
		case 5:
		{
				  int idx1, idx2;
				  printf("Nhap hai chi so de tinh tong (0-%d): ", n - 1);
				  scanf_s("%d %d", &idx1, &idx2);
				  if (idx1 >= 0 && idx1 < n && idx2 >= 0 && idx2 < n) {
					  HonSo tong = tinhTong(b[idx1], b[idx2]);
					  printf("Tong hai hon so %d/%d va %d/%d la %d %d/%d\n", b[idx1].tuSo, b[idx1].mauSo, b[idx2].tuSo, b[idx2].mauSo, tong.phanNguyen, tong.tuSo, tong.mauSo);
				  }
				  else {
					  printf("Chi so khong hop le\n");
				  }
		}
			break;
		case 6:
		{
				  int idx1, idx2;
				  printf("Nhap hai chi so de tinh hieu (0-%d): ", n - 1);
				  scanf_s("%d %d", &idx1, &idx2);
				  if (idx1 >= 0 && idx1 < n && idx2 >= 0 && idx2 < n) {
					  HonSo hieu = tinhHieu(b[idx1], b[idx2]);
					  printf("Hieu hai hon so %d/%d va %d/%d la %d %d/%d\n", b[idx1].tuSo, b[idx1].mauSo, b[idx2].tuSo, b[idx2].mauSo, hieu.phanNguyen, hieu.tuSo, hieu.mauSo);
				  }
				  else {
					  printf("Chi so khong hop le\n");
				  }
		}
			break;
		case 7:
		{
				  int idx1, idx2;
				  printf("Nhap hai chi so de tinh tich (0-%d): ", n - 1);
				  scanf_s("%d %d", &idx1, &idx2);
				  if (idx1 >= 0 && idx1 < n && idx2 >= 0 && idx2 < n) {
					  HonSo tich = tinhTich(b[idx1], b[idx2]);
					  printf("Tich hai hon so %d/%d va %d/%d la %d %d/%d\n", b[idx1].tuSo, b[idx1].mauSo, b[idx2].tuSo, b[idx2].mauSo, tich.phanNguyen, tich.tuSo, tich.mauSo);
				  }
				  else {
					  printf("Chi so khong hop le\n");
				  }
		}
			break;
		case 8:
		{
				  int idx1, idx2;
				  printf("Nhap hai chi so de tinh thuong (0-%d): ", n - 1);
				  scanf_s("%d %d", &idx1, &idx2);
				  if (idx1 >= 0 && idx1 < n && idx2 >= 0 && idx2 < n) {
					  HonSo thuong = tinhThuong(b[idx1], b[idx2]);
					  if (thuong.phanNguyen == -1 && thuong.tuSo == 0 && thuong.mauSo == 0) {
						  printf("Khong the chia cho 0\n");
					  }
					  else {
						  printf("Thuong hai hon so %d/%d va %d/%d la %d %d/%d\n", b[idx1].tuSo, b[idx1].mauSo, b[idx2].tuSo, b[idx2].mauSo, thuong.phanNguyen, thuong.tuSo, thuong.mauSo);
					  }
				  }
				  else {
					  printf("Chi so khong hop le\n");
				  }
		}
			break;
		case 9:
		{
				  int sapXep;
				  printf("Chon cach sap xep (1. Bubble Sort, 2. Insertion Sort, 3. Selection Sort): ");
				  scanf_s("%d", &sapXep);
				  if (sapXep >= 1 && sapXep <= 3) {
					  int tangGiam;
					  printf("Chon thu tu sap xep (1. Tang dan, 2. Giam dan): ");
					  scanf_s("%d", &tangGiam);
					  if (tangGiam == 1) {
						  switch (sapXep) {
						  case 1:
							  bubbleSort(b, n, 1);
							  break;
						  case 2:
							  insertionSort(b, n, 1);
							  break;
						  case 3:
							  selectionSort(b, n, 1);
							  break;
						  }
						  printf("Mang sau khi sap xep tang dan:\n");
						  xuatDanhSachHonSo(b, n);
					  }
					  else if (tangGiam == 2) {
						  switch (sapXep) {
						  case 1:
							  bubbleSort(b, n, 0);
							  break;
						  case 2:
							  insertionSort(b, n, 0);
							  break;
						  case 3:
							  selectionSort(b, n, 0);
							  break;
						  }
						  printf("Mang sau khi sap xep giam dan:\n");
						  xuatDanhSachHonSo(b, n);
					  }
					  else {
						  printf("Lua chon khong hop le\n");
					  }
				  }
				  else {
					  printf("Lua chon khong hop le\n");
				  }
		}
			break;
		case 0:
			printf("Thoat chuong trinh\n");
			break;
		default:
			printf("Lua chon khong hop le\n");
			break;
		}
	} while (choice != 0);

	return 0;
}

void taoMangHonSoNgauNhien(HonSo b[], int n) {
	for (int i = 0; i < n; i++) {
		do {
			b[i].phanNguyen = rand() % 10 - 5; // Phan nguyen la so ngau nhien tu -5 den 4
			b[i].tuSo = rand() % 10 + 1; // Tu so la so ngau nhien tu 1 den 10
			b[i].mauSo = rand() % 10 + 1; // Mau so la so ngau nhien tu 1 den 10
		} while (b[i].phanNguyen == 0 || b[i].mauSo == 0); // Lap lai neu phan nguyen hoac mau so bang 0
	}
}

void xuatDanhSachHonSo(HonSo b[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d %d/%d\n", b[i].phanNguyen, b[i].tuSo, b[i].mauSo);
	}
}

int soSanhHonSo(HonSo hs1, HonSo hs2) {
	// Chuyen doi hai hon so ve mau chung
	int tuSo1, mauSo1, tuSo2, mauSo2;
	chuyenHonSoThanhPhanSo(hs1, &tuSo1, &mauSo1);
	chuyenHonSoThanhPhanSo(hs2, &tuSo2, &mauSo2);

	// Tinh toan so sanh
	int giaTri1 = tuSo1 * mauSo2;
	int giaTri2 = tuSo2 * mauSo1;

	if (giaTri1 < giaTri2) {
		return -1;
	}
	else if (giaTri1 > giaTri2) {
		return 1;
	}
	else {
		return 0;
	}
}

void chuyenHonSoThanhPhanSo(HonSo hs, int *tuSo, int *mauSo) {
	*tuSo = hs.phanNguyen * hs.mauSo + hs.tuSo;
	*mauSo = hs.mauSo;
}

HonSo chuyenPhanSoThanhHonSo(int tuSo, int mauSo) {
	HonSo hs;
	hs.phanNguyen = tuSo / mauSo;
	hs.tuSo = tuSo % mauSo;
	hs.mauSo = mauSo;
	return hs;
}

HonSo tinhTong(HonSo hs1, HonSo hs2) {
	// Chuyen doi hai hon so ve mau chung
	int tuSo1, mauSo1, tuSo2, mauSo2;
	chuyenHonSoThanhPhanSo(hs1, &tuSo1, &mauSo1);
	chuyenHonSoThanhPhanSo(hs2, &tuSo2, &mauSo2);

	// Tinh toan tong
	int tuSoTong = tuSo1 * mauSo2 + tuSo2 * mauSo1;
	int mauSoTong = mauSo1 * mauSo2;

	// Chuyen ve hon so
	HonSo tong = chuyenPhanSoThanhHonSo(tuSoTong, mauSoTong);
	return tong;
}

HonSo tinhHieu(HonSo hs1, HonSo hs2) {
	// Chuyen doi hai hon so ve mau chung
	int tuSo1, mauSo1, tuSo2, mauSo2;
	chuyenHonSoThanhPhanSo(hs1, &tuSo1, &mauSo1);
	chuyenHonSoThanhPhanSo(hs2, &tuSo2, &mauSo2);

	// Tinh toan hieu
	int tuSoHieu = tuSo1 * mauSo2 - tuSo2 * mauSo1;
	int mauSoHieu = mauSo1 * mauSo2;

	// Chuyen ve hon so
	HonSo hieu = chuyenPhanSoThanhHonSo(tuSoHieu, mauSoHieu);
	return hieu;
}

HonSo tinhTich(HonSo hs1, HonSo hs2) {
	// Chuyen doi hai hon so ve mau chung
	int tuSo1, mauSo1, tuSo2, mauSo2;
	chuyenHonSoThanhPhanSo(hs1, &tuSo1, &mauSo1);
	chuyenHonSoThanhPhanSo(hs2, &tuSo2, &mauSo2);

	// Tinh toan tich
	int tuSoTich = tuSo1 * tuSo2;
	int mauSoTich = mauSo1 * mauSo2;

	// Chuyen ve hon so
	HonSo tich = chuyenPhanSoThanhHonSo(tuSoTich, mauSoTich);
	return tich;
}

HonSo tinhThuong(HonSo hs1, HonSo hs2) {
	// Chuyen doi hai hon so ve mau chung
	int tuSo1, mauSo1, tuSo2, mauSo2;
	chuyenHonSoThanhPhanSo(hs1, &tuSo1, &mauSo1);
	chuyenHonSoThanhPhanSo(hs2, &tuSo2, &mauSo2);

	// Tinh toan thuong
	if (tuSo2 == 0) {
		HonSo error = { -1, 0, 0 }; // Bieu thi loi khi chia cho 0
		return error;
	}

	int tuSoThuong = tuSo1 * mauSo2;
	int mauSoThuong = mauSo1 * tuSo2;

	// Chuyen ve hon so
	HonSo thuong = chuyenPhanSoThanhHonSo(tuSoThuong, mauSoThuong);
	return thuong;
}

void bubbleSort(HonSo b[], int n, int tang) {
	int i, j;
	HonSo temp;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if ((tang && soSanhHonSo(b[j], b[j + 1]) > 0) || (!tang && soSanhHonSo(b[j], b[j + 1]) < 0)) {
				temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
			}
		}
	}
}

void insertionSort(HonSo b[], int n, int tang) {
	int i, j;
	HonSo key;
	for (i = 1; i < n; i++) {
		key = b[i];
		j = i - 1;

		while (j >= 0 && ((tang && soSanhHonSo(b[j], key) > 0) || (!tang && soSanhHonSo(b[j], key) < 0))) {
			b[j + 1] = b[j];
			j = j - 1;
		}
		b[j + 1] = key;
	}
}

void selectionSort(HonSo b[], int n, int tang) {
	int i, j, min_idx;
	HonSo temp;
	for (i = 0; i < n - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			if ((tang && soSanhHonSo(b[j], b[min_idx]) < 0) || (!tang && soSanhHonSo(b[j], b[min_idx]) > 0)) {
				min_idx = j;
			}
		}
		temp = b[min_idx];
		b[min_idx] = b[i];
		b[i] = temp;
	}
}
