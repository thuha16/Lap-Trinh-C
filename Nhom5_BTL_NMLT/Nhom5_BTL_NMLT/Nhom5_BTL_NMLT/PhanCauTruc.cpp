#include <stdio.h>
#include<conio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct Hocsinh
{
	char ms[10];
	char ten[25];
	int m, d, y;
	char ph[24];
	char quanhe[5];
	char sdt[12];
	char diachi[50];
};
typedef Hocsinh HS;

	// câu 8//
void nhapThemHS(Hocsinh* HS)
{
	printf("nhap ma hoc sinh:");
	scanf("%s", HS->ms);
	printf("nhap ten:");
	getchar();
	gets_s(HS->ten);
	printf("nhap ngay sinh:");
	scanf("%d", &HS->d);
	printf("nhap thang sinh:");
	scanf("%d", &HS->m);
	printf("nhap nam sinh:");
	scanf("%d", &HS->y);
	printf("nhap ten PH:");
	getchar();
	gets_s(HS->ph);
	printf("nhap moi quan he:");
	scanf("%s", HS->quanhe);
	printf("nhap so dien thoai:");
	scanf("%s", HS->sdt);
	printf("Nhap dia chi:");
	getchar();
	gets_s(HS->diachi);
}
struct Hocsinh nhapHS()
{
	struct Hocsinh HS;
	nhapThemHS(&HS);
	return HS;
}
    
    //Cau1//
void DocfileMangHS(HS a[], int& n)
{
	FILE* f;
	f = fopen("dsHocSinh.txt", "r");
	if (f == NULL)
	{
		printf("\nLoi mo FILE!!!");
		return;
	}
	fscanf(f, "%d", &n);
	char t[5];
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%c", &t);
		fgets(a[i].ms, 10, f);
		a[i].ms[strlen(a[i].ms) - 1] = '\0';
		fgets(a[i].ten, 25, f);
		a[i].ten[strlen(a[i].ten) - 1] = '\0';
		fscanf(f, "%d/%d/%d", &a[i].d, &a[i].m, &a[i].y);
		fscanf(f, "%c", &t);
		fgets(a[i].ph, 24, f);
		a[i].ph[strlen(a[i].ph) - 1] = '\0';
		fgets(a[i].quanhe, 5, f);
		a[i].quanhe[strlen(a[i].quanhe) - 1] = '\0';
		fgets(a[i].sdt, 12, f);
		a[i].sdt[strlen(a[i].sdt) - 1] = '\0';
		fgets(a[i].diachi, 50, f);
		a[i].diachi[strlen(a[i].diachi) - 1] = '\0';

	}
	fclose(f);
}

   //Cau2//
void xuat1HS(HS hs)
{
	printf("%13s %25s \t %2d/%2d/%4d %25s %5s %15s %50s", hs.ms, hs.ten, hs.d, hs.m,hs.y, hs.ph, hs.quanhe, hs.sdt, hs.diachi);
	printf("\n");
}
void xuatmanghs(HS a[], int n)
{
	printf("%13s %25s \t %s %22s %10s %12s %40s", "Ma So", "Ho Ten", "Nam Sinh", "PH", "QH", "SDT", "DiaChi");
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		xuat1HS(a[i]);

	}
}
    
     //Cau3+Cau14//
void soHSToanTruong(HS a[], int n)
{
	int i;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		if (strstr(a[i].ms, "HS"))
		{
			count++;
		}
	}
	printf("\n->CO %d HOC SINH TOAN TRUONG.\n", count);
}

    //Cau4//
void Xuat_thong_tin_Ph(HS a[], int n)
{
	char find[50];
	int check = 0;
	printf("\n\nnhap ma hoc sinh can tim:");
	scanf("%s", find);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(find, a[i].ms) == 0)
		{
			check++;
			printf("\n \t \t \t \t \t \t \t DANH SACH THONG TIN PHU HUYNH HOC SINH\n");
			printf("\n \t \t \t \t \t ----------------------------------------------------------------\n");
			printf("\n\tSTT \t\t Ho va ten \t\tQuan he voi phu huynh \t\tDien thoai \t\t\t Dia chi co quan\n");
			printf("\n");
			printf("%10d %25s %20s %30s %40s ", i+1, a[i].ph, a[i].quanhe, a[i].sdt, a[i].diachi);
			printf("\n");
		}
	}
	if (check == 0)
	{
		printf("-->Khong tim thay ma so %s nay", find);
	}

}

           //Cau5//
void xuat_ThongTin_Hs_Lopla(HS a[], int n)
{
	printf("\n");
	printf("\t \t \t \t \t \t-----THONG TIN HOC SINH HOC LOP LA-----\n");
	printf("\n%13s %25s \t %s %22s %10s %12s %40s", "Ma So", "Ho Ten", "Nam Sinh", "PH", "QH", "SDT", "DiaChi");
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		if (strstr(a[i].ms, "L"))
		{
			xuat1HS(a[i]);
			printf("\n");
		}
	}
}

          //Cau6//
void xuat_hs_quantp(HS a[], int n)
{
	int count=0;
	printf("\n");
	printf("\t\t\t\t\t\t-----DANH SACH HOC SINH CO BO ME LAM VIEC TAI QUAN TAN PHU-----\n");
	printf("%13s %25s \t %s %22s %10s %12s %40s", "Ma So", "Ho Ten", "Nam Sinh", "PH", "QH", "SDT", "DiaChi");
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		if (strstr(a[i].diachi, "Quan Tan Phu"))
		{
			xuat1HS(a[i]);
			printf("\n");
			count++;
		}

	}
	if(count==0)
	{
		printf("\n Khong co phu huynh lam viec tai quan Tan Phu");
	}
	else
	{
		printf("--> so luong hoc sinh co bo me lam viec o quan Tan Phu la %d",count);
	}
}

   //Cau7//
void sapXepGiam(HS a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if (a[j].d > a[j - 1].d)
			{
				struct Hocsinh HS = a[j];
				a[j] = a[j - 1];
				a[j - 1] = HS;
			}
		}
	}
}
void checkMS(HS a[], int n)
{
	int check = 0;
	int i,j;
	printf("dang check sinh vien bi trung ma so:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i != j)
			{
				if (strcmp(a[i].ms, a[j].ms) == 0)
				{
					check = 1;
					printf("%13s %25s \t %s %22s %10s %12s %40s", "Ma So", "Ho Ten", "Nam Sinh", "PH", "QH", "SDT", "DiaChi");
					printf("\n");
					xuat1HS(a[j]);
					printf("update ma so:");
					scanf("%s",a[j].ms);
				}
			}
		}
	}
	if (check == 0)
	{
		printf("khong co hoc sinh nao trung ma\n");
	}
}

     //Cau9//
void xoa(HS a[], int& n, int vt)
{
	for (int i = vt + 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	n--;
}
void xoaenter(char x[])
{
	int len = strlen(x);
	if (x[len - 1] == '\n')
	{
		x[len - 1] == '\0';
	}
}
void xoa_hs_c1(HS a[], int n)
{
	char c[50];
	int dem = 0;
	printf("nhap ms hs can xoa tai lop choi 1: ");
	do {
		scanf("%s", c);
		xoaenter(c);
	} while (strlen(c) == 0);

	for (int i = 0; i < n; i++)
	{
		if (strstr(a[i].ms, "C1")) {
			if (strstr(a[i].ms, c))
			{
				dem++;
				xoa(a, n, i);
				break;
			}
		}
	}
	if (dem == 0) printf("ko co ma so hoc sinh nao vua nhap o lop choi 1");
	else {
		printf("danh sach sau khi xoa la \n");
		xuatmanghs(a, n);
	}
}

    //Cau10//
void xuatdanhsachsinhnam2013(HS a[], int n)
{
	printf("\n");
	printf("\t\t\t\t\t\t-----DANH SACH HOC SINH SINH NAM 2013-----\n");
	printf("%13s %25s \t %s %22s %10s %12s %40s", "Ma So", "Ho Ten", "Nam Sinh", "PH", "QH", "SDT", "DiaChi");
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		if (a[i].y == 2013) {
			xuat1HS(a[i]);
			printf("\n");
		}

	}
}
 
  //Cau11//
void so_hs_hoc_Lopla(HS a[], int n)
{
	int dem = 0;;
	for (int i = 0; i < n; i++)
	{
		if (strstr(a[i].ms, "L"))
		{
			dem++;
		}
	}
	printf("\n->So hoc sinh lop la la:%d", dem);
}

    //Cau12//
void xuatSdt(HS a[], int n)
{
	int dem=0;
	printf("\n\t\tTIM KIEM SDT CUA ME HOC SINH LE HOANG YEN");
	for (int i = 0; i < n; i++)
	{
		if (strstr(a[i].ten, "Le Hoang Yen") && strstr(a[i].ms, "C1"))
		{
			printf("\nSDT cua me hoc sinh Le Hoang Yen o lop choi 1 : %s", a[i].sdt);
			dem++;
		}
	}
	if(dem==0)
		printf("\nKhong tim thay thong tin nay");
}

  //Cau13//
void xuatDSHSThang1(HS a[], int n)
{
	printf("\n");
	printf("\t\t\t\t\t\t\t\t-----DANH SACH HOC SINH SINH THANG 1-----\n");
	printf("%13s %25s \t %s %22s %10s %12s %40s", "Ma So", "Ho Ten", "Nam Sinh", "PH", "QH", "SDT", "DiaChi");
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		if (a[i].m == 1)
		{
			xuat1HS(a[i]);
			printf("\n");
		}

	}
}

           //Cau15//
void thongKeTungKhoi(HS a[], int n)
{
	int i;
	int count = 0;
	int countLa = 0;
	int countMam = 0;
	int countChoi = 0;
	float tile;
	printf("--------------------THONG KE SO HOC SINH THEO TUNG KHOI LOP--------------------");
	for (i = 0; i < n; i++)
	{
		if (strstr(a[i].ms, "HS"))
		{
			count++;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (strstr(a[i].ms, "L"))
		{
			countLa++;
		}
	}
	tile = (float)(countLa) / count * 100;
	printf("\nKhoi lop la: %d hoc sinh \t\t\t Ty Le:%2.f%%\n", countLa, tile);
	for (i = 0; i < n; i++)
	{
		if (strstr(a[i].ms, "C"))
		{
			countChoi++;
		}
	}
	tile = (float)(countChoi) / count * 100;
	printf("Khoi lop choi: %d hoc sinh \t\t\t Ty Le:%2.f%%\n", countChoi, tile);
	for (i = 0; i < n; i++)
	{
		if (strstr(a[i].ms, "M"))
		{
			countMam++;
		}
	}
	tile = (float)countMam / count * 100;
	printf("Khoi lop Mam: %d hoc sinh \t\t\t Ty Le:%2.f%%\n", countMam, tile);
}

int main()
{
	HS a[100];
	int n;
	int luachon;
	DocfileMangHS(a, n);
	do {
		printf("\n-----------MENU------------\n");
		printf("\n1.Tao file dsHocsinh.txt chua thong tin hoc sinh.Viet ham doc thong tin tu file vao mang");
		printf("\n2.Xuat thong tin hoc sinh ra man hinh");
		printf("\n3.Cho biet tong so hoc sinh toa truong");
		printf("\n4.Xuat thong tin PH khi biet ma HS theo dinh dang");
		printf("\n5.Cho biet thong tin hoc sinh lop La");
		printf("\n6.Dem va tra ve HS co cha me lam o quan Tan Phu");
		printf("\n7.Sap xep danh sach theo ngay sinh giam dan");
		printf("\n8.Them HS vao lop Mam 1");
		printf("\n9.Xoa thong tin HS lop Choi 1 khi nhap ma HS");
		printf("\n10.Hien thi danh sach HS sinh nam 2013");
		printf("\n11.Cho biet co bao nhieu HS lop La");
		printf("\n12.Tim sdt cua me HS Le Hoang Yen lop Choi 1");
		printf("\n13.Cho biet thong tin HS sinh vao thang 1");
		printf("\n14.Viet ham tinh tong so HS toan truong");
		printf("\n15.Thong ke so HS moi lop va hien thi ra man hinh");
		printf("\n0.Thoat chuong trinh");
		printf("\nNhap lua chon cua ban: ");
		scanf("%d", &luachon);
		Hocsinh HS;
		switch (luachon)
		{
		case 1:
			break;
		case 2:
			xuatmanghs(a, n);
			break;
		case 3:
			soHSToanTruong(a, n);
			break;
		case 4:
			Xuat_thong_tin_Ph(a, n);
			break;
		case 5:
			xuat_ThongTin_Hs_Lopla(a, n);
			break;
		case 6:
			xuat_hs_quantp(a, n);
			break;
		case 7:
			sapXepGiam(a, n);
			printf("\n\n\n");
			printf("\t\t\t\t\t\t\t\t--------------------DA SAP XEP---------------------");
			printf("\n\n\n");
			xuatmanghs(a, n);
			printf("\n\n\n");
			printf("\t\t\t\t\t\t\t\t---------------------------------------------------");
			break;
		case 8:
		{
			xuatmanghs(a, n);
			HS = nhapHS();
			a[n++] = HS;
			xuatmanghs(a, n);
			printf("\n");
			checkMS(a,n);
			break;
		}
		case 9:
			xoa_hs_c1(a, n);
			break;
		case 10:
			xuatdanhsachsinhnam2013(a, n);
			break;
		case 11:
			so_hs_hoc_Lopla(a, n);
			break;
		case 12:
			xuatSdt(a, n);
			break;
		case 13:
			xuatDSHSThang1(a, n);
			break;
		case 14:
			soHSToanTruong(a, n);
			break;
		case 15:
			thongKeTungKhoi(a, n);
			break;
		default:
			printf("\n Ban da chon sai!!!");
		}
	} while (luachon != 0);
	return 0;
}



