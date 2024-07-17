//////#include <stdio.h>
//////#include <stdlib.h>
//////#include <time.h>
//////
//////// Ham tao mang ngau nhien
//////void generateRandomArray(int a[], int n, int lower, int upper) {
//////	for (int i = 0; i < n; i++) {
//////		a[i] = lower + rand() % (upper - lower + 1);
//////	}
//////}
//////
//////// Ham tao mang chua toan so chan
//////void generateEvenArray(int a[], int n, int lower, int upper) {
//////	int count = 0;
//////	while (count < n) {
//////		int num = lower + rand() % (upper - lower + 1);
//////		if (num % 2 == 0) {
//////			a[count++] = num;
//////		}
//////	}
//////}
//////
//////// Ham tim kiem tuyen tinh
//////int linearSearch(int a[], int n, int x) {
//////	for (int i = 0; i < n; i++) {
//////		if (a[i] == x) {
//////			return i;
//////		}
//////	}
//////	return -1;
//////}
//////
//////// Ham sap xep Interchange Sort
//////void interchangeSort(int a[], int n) {
//////	for (int i = 0; i < n - 1; i++) {
//////		for (int j = i + 1; j < n; j++) {
//////			if (a[i] > a[j]) {
//////				int temp = a[i];
//////				a[i] = a[j];
//////				a[j] = temp;
//////			}
//////		}
//////	}
//////}
//////
//////// Ham tim kiem nhi phan
//////int binarySearch(int a[], int n, int x) {
//////	int left = 0, right = n - 1;
//////	while (left <= right) {
//////		int mid = left + (right - left) / 2;
//////		if (a[mid] == x) {
//////			return mid;
//////		}
//////		if (a[mid] < x) {
//////			left = mid + 1;
//////		}
//////		else {
//////			right = mid - 1;
//////		}
//////	}
//////	return -1;
//////}
//////
//////// Ham sap xep Selection Sort
//////void selectionSort(int a[], int n) {
//////	for (int i = 0; i < n - 1; i++) {
//////		int minIdx = i;
//////		for (int j = i + 1; j < n; j++) {
//////			if (a[j] < a[minIdx]) {
//////				minIdx = j;
//////			}
//////		}
//////		int temp = a[minIdx];
//////		a[minIdx] = a[i];
//////		a[i] = temp;
//////	}
//////}
//////
//////// Ham sap xep Quick Sort
//////void quickSort(int a[], int left, int right) {
//////	if (left < right) {
//////		int pivot = a[right];
//////		int i = left - 1;
//////		for (int j = left; j < right; j++) {
//////			if (a[j] <= pivot) {
//////				i++;
//////				int temp = a[i];
//////				a[i] = a[j];
//////				a[j] = temp;
//////			}
//////		}
//////		int temp = a[i + 1];
//////		a[i + 1] = a[right];
//////		a[right] = temp;
//////
//////		quickSort(a, left, i);
//////		quickSort(a, i + 2, right);
//////	}
//////}
//////
//////// Ham in mang
//////void printArray(int a[], int n) {
//////	for (int i = 0; i < n; i++) {
//////		printf("%d ", a[i]);
//////	}
//////	printf("\n");
//////}
//////
//////// Menu
//////void menu() {
//////	printf("1. Tao mang ngau nhien\n");
//////	printf("2. Tao mang chua toan so chan\n");
//////	printf("3. Tim kiem tuyen tinh\n");
//////	printf("4. Sap xep tang dan bang Interchange Sort\n");
//////	printf("5. Tim kiem nhi phan\n");
//////	printf("6. Sap xep tang dan bang Selection Sort\n");
//////	printf("7. Sap xep tang dan bang Quick Sort\n");
//////	printf("8. Thoat\n");
//////}
//////
//////int main() 
//////{
//////	time_t t = time(0);
//////	unsigned int covertedTime = static_cast <unsigned int> (t);
//////	int n =15;
//////	int a[100];
//////	int choice, x, result;
//////	do {
//////		menu();
//////		printf("Chon mot tuy chon: ");
//////		scanf_s("%d", &choice);
//////
//////		switch (choice) {
//////		case 1:
//////			generateRandomArray(a, n, 0, 100);
//////			printf("Mang ngau nhien: ");
//////			printArray(a, n);
//////			break;
//////		case 2:
//////			generateEvenArray(a, n, 0, 100);
//////			printf("Mang chua toan so chan: ");
//////			printArray(a, n);
//////			break;
//////		case 3:
//////			printf("Nhap gia tri can tim: ");
//////			scanf_s("%d", &x);
//////			result = linearSearch(a, n, x);
//////			if (result != -1) {
//////				printf("Gia tri %d duoc tim thay tai vi tri %d\n", x, result);
//////			}
//////			else {
//////				printf("Gia tri %d khong co trong mang\n", x);
//////			}
//////			break;
//////		case 4:
//////			interchangeSort(a, n);
//////			printf("Mang sau khi sap xep tang dan: ");
//////			printArray(a, n);
//////			break;
//////		case 5:
//////			printf("Nhap gia tri can tim: ");
//////			scanf_s("%d", &x);
//////			result = binarySearch(a, n, x);
//////			if (result != -1) {
//////				printf("Gia tri %d duoc tim thay tai vi tri %d\n", x, result);
//////			}
//////			else {
//////				printf("Gia tri %d khong co trong mang\n", x);
//////			}
//////			break;
//////		case 6:
//////			selectionSort(a, n);
//////			printf("Mang sau khi sap xep tang dan bang Selection Sort: ");
//////			printArray(a, n);
//////			break;
//////		case 7:
//////			quickSort(a, 0, n - 1);
//////			printf("Mang sau khi sap xep tang dan bang Quick Sort: ");
//////			printArray(a, n);
//////			break;
//////		case 8:
//////			printf("Thoat chuong trinh.\n");
//////			break;
//////		default:
//////			printf("Tuy chon khong hop le. Vui long chon lai.\n");
//////			break;
//////		}
//////	} while (choice != 8);
//////
//////	return 0;
//////}
