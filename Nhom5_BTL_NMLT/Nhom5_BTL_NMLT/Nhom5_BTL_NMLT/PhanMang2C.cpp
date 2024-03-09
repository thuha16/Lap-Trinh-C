#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctime>
#include<math.h>

#define MAXROW 100
#define MAXCOLUM 100

void MeNu();
void Nhap_mang2C_tuphim(int a[][MAXCOLUM], int& m, int& n);
void Nhap_mang2C_ngaunhien(int a[][MAXCOLUM], int& m, int& n);
void Xuatmang_2C(int a[][MAXCOLUM], int m, int n);
void docFileM2C(FILE*& f, int a[][MAXCOLUM], int& m, int& n);
       
void TBC4B(int a[][MAXCOLUM], int m, int n);
void TBCCC(int a[][MAXCOLUM], int m, int n);
void TBCCP1(int a[][MAXCOLUM],int m, int n);

void soThinhVuong(int a[][MAXCOLUM], int m, int n);

int SNT(int a);
float tbnsonguyento(int a[][MAXCOLUM], int i, int n);
int timdong(int a[][MAXCOLUM], int m, int n);

void swap(int& a, int& b);
void bai5(int a[][MAXCOLUM], int& m);

void SapXep_chantang_legiam(int a[][MAXCOLUM], int m, int n);

void mang_C(int a[][MAXCOLUM], int b[][MAXCOLUM], int& m, int& n);
void mang_D(int a[][MAXCOLUM], int c[][MAXCOLUM], int& m, int& n);

void nhapMangE(int a[][MAXCOLUM], int m, int n);
int timBTrongA(int b[][MAXCOLUM], int a[][MAXCOLUM], int bm, int bn, int am, int an);

void Ma_tran_F(int a[][MAXCOLUM], int& m, int& n);

void doi_Mang2C_ve1C(int a[][MAXCOLUM],int b[100], int m, int n,int &k);
void sapXep_Mang1C_Giam(int b[100], int k);
void xoacOc_GiamDan_NguocDongHo(int b[100], int a[][MAXCOLUM], int m, int n);

int main()
{
	int a[MAXROW][MAXCOLUM], b[MAXROW][MAXCOLUM], c[MAXROW][MAXCOLUM], f, m, n, chon, lua; 
	do
	{
		FILE * f;
		MeNu();
		printf("\n Moi ban chon chuong trinh : ");
		scanf("%d", &chon);
		switch (chon)
		{
		case 1:
			printf("\n 1.Mang 2 chieu nhap tu ban phim");
			printf("\n 2.Mang 2 chieu ngau nhien");
			printf("\n 3.Mang 2 chieu tu file text");
			printf("\n Moi ban chon chuong trinh ben trong cau 1: ");
			scanf("%d", &lua);
			switch (lua)
			{
			case 1:
				Nhap_mang2C_tuphim(a, m, n);
				printf("\n Ma tran vua nhap co gia tri:\n");
				Xuatmang_2C(a, m, n);
				break;
			case 2:
				Nhap_mang2C_ngaunhien(a, m, n);
				printf("\n Ma tran ngau nhien co gia tri:\n");
				Xuatmang_2C(a, m, n);
				break;
			case 3:
				docFileM2C(f, a, m, n);
				printf(" Ma tran co gia tri:\n");
				Xuatmang_2C(a, m, n);
			default:
					printf("\n hay chon lai chuong trinh ben trong cau 1");
				break;
			}
			break;
		case 2:
			Nhap_mang2C_tuphim(a, m, n);
			printf("\n Ma tran vua nhap co gia tri:\n");
			Xuatmang_2C(a, m, n);
			TBC4B(a, m, n);
			TBCCC(a, m, n);
			TBCCP1(a, m, n);
			break;
		case 3:
			Nhap_mang2C_tuphim(a, m, n);
			printf("\n Ma tran vua nhap co gia tri:\n");
			Xuatmang_2C(a, m, n);
			soThinhVuong(a, m, n); 
			printf("\n");
			break;
		case 4:
			 docFileM2C(f, a, m, n);
			 printf(" Ma tran co gia tri:\n");
			 Xuatmang_2C(a, m, n);
			 printf("Dong co trung binh nhan so nguyen to lon nhat:%d\n", timdong(a, m, n));
			break;
		case 5:
			docFileM2C(f, a, m, n);
			printf(" Ma tran co gia tri:\n");
			Xuatmang_2C(a, m, n);
			bai5(a, n);
			printf("\n Ma tran sau khi duoc hoan vi 2 cot C1 va C2:\n");
			Xuatmang_2C(a, m, n);
			break;
		case 6:
			Nhap_mang2C_tuphim(a ,m ,n);
			printf("\n Ma tran vua nhap co gia tri :\n");
			Xuatmang_2C(a, m, n);
			SapXep_chantang_legiam(a ,m ,n);
			printf("\n Ma tran B duoc sap xep co cac gia tri chan tang dan,le giam dan\n");
			Xuatmang_2C(a ,m ,n);
			break;
		case 7:
			Nhap_mang2C_ngaunhien(a, m, n);
			printf("\n Ma tran ngau nhien co gia tri :\n");
			Xuatmang_2C(a, m, n);
			mang_C(a, b, m, n);
			printf("\n Ma tran C chua toan bo so duong:\n");
			Xuatmang_2C(b, m, n);
			mang_D(a, c, m, n);
			printf("\n Ma tran D chua toan bo so am:\n");
			Xuatmang_2C(c, m, n);
			break;
		case 8:
		{
			int ma8,mb8;
			int	na8, nb8;
			int a8[MAXROW][MAXCOLUM], b8[MAXROW][MAXCOLUM]; 
			Nhap_mang2C_tuphim( a8, ma8,na8);
			Xuatmang_2C(a8, ma8 ,na8);
			do {
				printf("\nnhap mang E:");
				printf("\nnhap vao so dong cua ma tran E:");
				scanf("%d", &mb8);
				printf("\nnhap vao so cot cua ma tran E:");
				scanf("%d", &nb8);
			} while (mb8 <= 0 || nb8 <= 0);
			nhapMangE(b8, mb8, nb8);
			Xuatmang_2C(b8, mb8, nb8);
			printf("so lan mang con xuat hien la :%d\n", timBTrongA(b8, a8, mb8, nb8, ma8, na8));
			break;
		}
		case 9:
			docFileM2C(f, a, m, n);
			printf(" Ma tran co gia tri:\n");
			Xuatmang_2C(a, m, n);
			Ma_tran_F(a, m, n);
			printf("\n Ma tran F sau khi dich chuyen:\n");
			Xuatmang_2C(a, m, n);
			break;
		case 10:
			int h[100];
			int k;
			Nhap_mang2C_tuphim(a, m, n);
			printf("\n Ma tran vua nhap co gia tri :\n");
			Xuatmang_2C(a, m, n);
			doi_Mang2C_ve1C(a,h,m,n,k);
			sapXep_Mang1C_Giam(h,k);
			xoacOc_GiamDan_NguocDongHo(h,a,m,n);
			printf("\nMa tran xoan oc giam dan nguoc chieu kim dong ho la:\n");
			Xuatmang_2C(a, m, n);
			break;
		default:
         printf("\n Ban da chon sai!!!");
			break;
		}
	} while (chon != 0);
}

void MeNu()
{
	printf("\n=========================================================MANG 2 CHIEU=======================================================================");
	printf("\n ==========      Cau 1.Nhap,xuat mang 2 chieu tu ban phim,ngau nhien,file text                                                    ==========");
	printf("\n ==========      Cau 2.Tinh gia tri Tbc cac phan tu tren 4 bien,duong cheo chinh va duong cheo phu                                ==========");
	printf("\n ==========      Cau 3.Liet ke danh sach phan tu cua tung cot chua toan bo so thinh vuong                                         ==========");
	printf("\n ==========      Cau 4.Cho biet dong co chua gia tri trung binh nhan cua cac so nguyen to lon nhat                                ==========");
	printf("\n ==========      Cau 5.Hoan vi 2 cot c1 va c2 bat ki cua A                                                                        ==========");
	printf("\n ==========      Cau 6.Tu A tao,xuat 1 ma tran B sao cho tung dong phai duoc sap xep cac gia tri chan tang dan, le giam dan       ==========");
	printf("\n ==========      Cau 7.Tu A hay tao va xuat 2 ma tran C,D(cung kinh thuoc)sao cho ma tran C chua so duong con D chua so am        ==========");
	printf("\n ==========      Cau 8.Tao 1 ma tran E co kich thuoc X dong x Y cot.Hay dem so lan xuat hien cua E trong A                        ==========");
	printf("\n ==========      Cau 9.Tu A hay tao,xuat ma tran F duoc dich phai xoay vong cac cot theo truc dung voi chieu tu trai sang phai	  ==========");
	printf("\n ==========      Cau 10.Xuat ma tran xoan oc giam dan nguoc chieu kim dong ho                                                     ==========");
	printf("\n ==========      Chon 0 de thoat chuong trinh                                                                                     ==========");
	printf("\n============================================================================================================================================");
}

     // Cau 1//
void Nhap_mang2C_tuphim(int a[][MAXCOLUM], int& m, int& n)
{
	do
	{
		printf("\n Nhap so dong: ");
		scanf("%d", &m);
		printf("\n Nhap so cot: ");
		scanf("%d", &n);
	} while (m <= 0 || n <= 0);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("\n a[%d][%d]= ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void Nhap_mang2C_ngaunhien(int a[][MAXCOLUM], int& m, int& n)
{
	do
	{
		printf("\n Nhap so dong: ");
		scanf("%d", &m);
		printf("\n Nhap so cot: ");
		scanf("%d", &n);
	} while (m < 0 || n < 0);
	srand(time(NULL));
	int b;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			do
			{
				b=rand();
				b= b-50;
			}while(b<-100 || b>100);  
			a[i][j]=b;
		}
	}
}

void docFileM2C(FILE*& f, int a[][MAXCOLUM], int& m, int& n)
{
	f = fopen("dsMang2C.txt", "rt");
	fscanf(f, "%d", &m);
	fscanf(f, "%d", &n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fscanf(f, "%d", &a[i][j]);
	fclose(f);
}

void Xuatmang_2C(int a[][MAXCOLUM], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf(" %3d ", a[i][j]);
		}
		printf("\n");
	}
}

        //Cau 2//
void TBC4B(int a[][MAXCOLUM], int m, int n)
{
	int i, j;
	int tren = 0, duoi = 0;
	int trai = 0, phai = 0;
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
	float s;
	for (i = 0; i < n; i++)
	{
		tren = tren + a[0][i];
		count1++;
	}
	for (i = 0; i < n; i++)
	{
		duoi = duoi + a[m - 1][i];
		count2++;
	}
	for (i = 1; i < m - 1; i++)
	{
		trai = trai + a[i][0];
		count3++;
	}
	for (i = 1; i < m - 1; i++)
	{
		phai = phai + a[i][n - 1];
		count4++;
	}

	s = 1.0 * (tren + duoi + phai + trai) / (count1 + count2 + count3 + count4);

	printf("TBC 4 bien = %.2f\n", s);
}
void TBCCC(int a[][MAXCOLUM], int m, int n)
{
	int i, j;
	float count = 0;
	float  s = 0;
	float sum;
	if (m == n)
	{
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (i == j)
				{
					s = s + a[i][j];
					count++;
				}
			}
		}
		sum = (s / count);
		printf("TBC duong cheo chinh:%.2f\n", sum);
	}
	else
	{
		printf("khong phai ma tran vuong khong co duong cheo chinh\n");
	}
}
void TBCCP1(int a[][MAXCOLUM], int m,int n)
{
	float sum = 0;
	float count = 0;
	float s = 0;
	if (m == n)
	{
		for (int i = 0; i < n; i++)
		{
			sum = sum + a[i][n - 1 - i];
			count++;
		}
		s = sum / count;
		printf("TBC duong cheo phu:%.2f\n", s);
	}
	else
	{
		printf("khong phai ma tran vuong khong co duong cheo phu\n");
	}
}

         //Cau 3//
void soThinhVuong(int a[][MAXCOLUM], int m, int n)
{
	int s, count;
	int check=0;
	int cot = 0;
	int viTriCot = 0;
	int viTriCotHT;
	for (int i = 0; i < n; i++)
	{
		count = 0;
		viTriCot++;
		for (int j = 0; j < m; j++)
		{
			s = 0;
			for (int k = 1; k < a[j][i]; k++)
			{
				if (a[j][i] % k == 0)
				{
					s = s + k;
				}
			}
			if (a[j][i] < s)
			{
				count++;
				check++;
			}
		}
		if (count == m)
		{
			viTriCotHT = viTriCot;
			cot++;
			printf("\n");
			printf("cot %d \n",viTriCotHT);
			for (int j = 0; j < m; j++)
			{
				printf("%10d", a[j][i]);
				printf("\n");
			}
			printf("\n\n");
		}
	}
	if(cot==0)
	{
		printf("khong co cot nao chua toan thinh vuong \n");
	}
	if(check==0)
	{
		printf("khong co so thinh vuong trong mang\n"); 
	}
}

     //Cau 4//
int SNT(int a)
{
	if (a < 2) return 0;
	for (int i = 2; i <= sqrtf(a); i++)
	{
		if (a % i == 0) { return 0; }
	}
	return 1;
}
float tbnsonguyento(int a[][MAXCOLUM], int i, int n)
{
	int dem = 0;
	int tich = 1;
		for (int j = 0; j < n; j++)
		{
			if (SNT(a[i][j]) == 1) {
				tich = tich * a[i][j];
				dem++;
			}
		}
	return (float)pow(tich, 1.0 / dem);
}
int timdong(int a[][MAXCOLUM], int m, int n)
{
	int i; int d = 0;
	double max = tbnsonguyento(a, 0, n);
	for (i = 1; i < m; i++)
	{
		double t = tbnsonguyento(a, i, n);
		if (max < t)
		{
			max = t;
			d = i;
		}
	}return d;
}

        //Cau 5//
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void bai5(int a[][MAXCOLUM], int& m)
{
	int c1, c2;
	do
	{
		printf("\n Nhap so cot c1: ");
		scanf("%d", &c1);
		printf("\n Nhap so cot c2: ");
		scanf("%d", &c2);
	} while (c1 > m || c2 > m);
	for (int i = 0; i < m; i++)
	{
		swap(a[i][c1], a[i][c2]);
	}
}

			//Cau 6//
void SapXep_chantang_legiam(int a[][MAXCOLUM], int m, int n)
{
    for (int i = 0; i < m; i++) 
	{   
        for (int j = 0; j < n - 1; j++)        
		{
            if ( a[i][j] % 2 == 0) 
			{      
                for (int h = j; h < n; h++)
				{
                    if (a[i][h] % 2 == 0)   
					{
						if (a[i][j] > a[i][h]) 
						{	
							swap(a[i][j],a[i][h]);
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < m; i++) 
		{
			for (int j = 0; j < n - 1; j++) 
			{
				if ( a[i][j] % 2 != 0)
				{
					for (int h = j; h < n; h++)
					{
						if (a[i][h] % 2 != 0) 
						{
							if (a[i][j] < a[i][h])
							{
								swap(a[i][j],a[i][h]);
							}
						}
					}
				}
			}
		}
}

      //Cau 7//
void mang_C(int a[][MAXCOLUM], int b[][MAXCOLUM], int& m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > 0)
			{
				b[i][j] = a[i][j];
			}
			else
			{
				b[i][j] = 0;
			}
		}
	}
}
void mang_D(int a[][MAXCOLUM], int c[][MAXCOLUM], int& m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] < 0)
			{
				c[i][j] = a[i][j];
			}
			else
			{
				c[i][j] = 0;
			}
		}
	}
}

          //Cau 8//
void nhapMangE(int a[][MAXCOLUM], int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

int timBTrongA(int b[][MAXCOLUM], int a[][MAXCOLUM], int bm, int bn, int am, int an)
{
	int iAm, iAn;
	int iBm, iBn;
	bool check;
	int count = 0;
	if(bm<am && bn<an)
	{
	for (iAm = 0; iAm <= am - bm; iAm++)
	{
		for (iAn = 0; iAn <= an - bn; iAn++)
		{
			check = true;
			for (iBm = 0; iBm < bm; iBm++)
			{
				for (iBn = 0; iBn < bn; iBn++)
				{
					if (b[iBm][iBn] != a[iAm + iBm][iAn + iBn]) 
					{
						check = false;
						break;
					}
				}
				if (check == false)
				{
					break;
				}
			}
			if (check == true)
			{
				count++;
			}
		}
	}
	}
	else
	{
		printf("hay nhap so dong va cot mang E be hon mang A\n"); 
	}
	return count;
}

                    //cau 9//
void Ma_tran_F(int a[][MAXCOLUM], int& m, int& n)
{
	int k, h = 0;
	printf("\n Nhap k= ");
	scanf("%d", &k);
	while (h < k)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = n - 1; j > 0; j--)          					 
			{										
				swap(a[i][j], a[i][j - 1]);   				
			}
		}
		h++;
	}
}

               //cau 10//
void doi_Mang2C_ve1C(int a[][MAXCOLUM],int b[100], int m, int n,int &k)
{
	k = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)		// tách từng phần tử của mảng 2 chiều vô 1 chiều.
		{
			b[k++] = a[i][j];
		}
	}
}
void sapXep_Mang1C_Giam(int b[100], int k)
{
	for (int i = 0; i < k-1; i++)
	{
		int vitrilonnhat= i;
		for (int j = i + 1; j < k; j++)  // sắp xếp các số mảng 1 chiều theo thứ tự giảm dần.
		{
			if (b[vitrilonnhat]< b[j])
			{
				vitrilonnhat =j ;
			}
		}
			swap(b[i],b[vitrilonnhat]);
	}
}
void xoacOc_GiamDan_NguocDongHo(int b[100], int a[][MAXCOLUM], int m, int n)
{
	int k = 0;
	int dongMAX = m;
	int cotMAX = n;
	int dongMIN = 0;
	int cotMIN = 0;
	while (dongMIN < dongMAX && cotMIN < cotMAX)
	{
		for (int i = cotMAX-1; i >= cotMIN; i--)
		{
			a[dongMIN][i]=b[k];
			k++;
		}
		dongMIN++;
		for (int i = dongMIN; i < dongMAX ; i++)			
		{
			a[i][cotMIN] = b[k];
			k++;
		}
		cotMIN++;
		if (dongMIN < dongMAX)
		{
			for (int i = cotMIN; i < cotMAX; i++)
			{
				a[dongMAX-1][i] = b[k];
					k++;
			}
			dongMAX--;
		}
		if (cotMIN < cotMAX)
		{
			for (int i = dongMAX-1; i >= dongMIN; i--)
			{
				a[i][cotMAX-1] = b[k];
				k++;
			}
			cotMAX--;
		}
	}
}


