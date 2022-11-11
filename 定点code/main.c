//#include<stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#define W_ord 2000
//#define H1_TRUE_ORD 18
//#define Sec_ord 12
//#define Q 16
//
//const int A[H1_TRUE_ORD] = {
//	0.06438408701907 * 65536, -0.02519421477958 * 65536,  0.04155370049251 * 65536, -0.04324502214555 * 65536,
//	0.06668137412364 * 65536, -0.07960309326041 * 65536,   0.1270708646786 * 65536,   -0.204569835881 * 65536,
//	 0.6403536044635 * 65536,   0.6403536044635 * 65536,   -0.204569835881 * 65536,   0.1270708646786 * 65536,
//   -0.07960309326041 * 65536,  0.06668137412364 * 65536, -0.04324502214555 * 65536,  0.04155370049251 * 65536,
//   -0.02519421477958 * 65536,  0.06438408701907 * 65536
//};
//const int C[Sec_ord] = {
//	-0.1026896085809 * 65536, 0.05829573485312 * 65536, -0.08077890047296 * 65536, 0.1199333831213 * 65536,
//		-0.2076756622808 * 65536, 0.6350878447541 * 65536, 0.6350878447541 * 65536, -0.2076756622808 * 65536,
//		0.1199333831213 * 65536, -0.08077890047296 * 65536, 0.05829573485312 * 65536, -0.1026896085809 * 65536
//};
//
//
//int main()
//{
//	int i,j;
//	int point;
//	short vi;
//	int  y_err=0;
//	int d_n, y_n,  y1_n, v_x1;
//	int x_dn[H1_TRUE_ORD] = { 0 };
//	int w[W_ord] = { 0 };
//	int x_yn[W_ord] = { 0 };
//	int x1_n[W_ord] = { 0 };
//	int y_y1n[Sec_ord] = { 0 };
//	int STEP = 6554;
//	long long xt1, xt, x_yn2;
//	FILE* f_x,*f_y;
//	f_x = fopen("whitenoise.pcm", "rb");
//	if (f_x == NULL) { printf("Cann't open the nosie file!!!\n");  exit(0); } 
//	f_y = fopen("out.pcm", "wb");
//	if (f_y == NULL) { printf("Cann't open the out file!!!\n");  exit(0); }
//	for (point = 0;; point++) {
//
//		if (fread(&vi, sizeof(short), 1L, f_x) != 1L)  break;
//		//if (fread(&vi1, sizeof(Word16), 1L, f_x1) != 1L)  break;
//
//		//if (fscanf(f_x, "%ld", &vi) == EOF) break;
//
//		//if ((point % 8000) == 0)  printf("%d points have been processed...          % d\n",  point, y_err);
//		
//		//求d(n)-Q
//		for (i = H1_TRUE_ORD - 1; i > 0; i--) x_dn[i] = x_dn[i - 1];
//		x_dn[0] = vi;
//		for (d_n = i = 0; i < H1_TRUE_ORD; i++)
//		{
//			d_n = d_n + A[i] * x_dn[i];
//
//		}
//
//		//求y(n)-Q
//		for (i = W_ord - 1; i > 0; i--) x_yn[i] = x_yn[i - 1];
//		x_yn[0] = vi;
//		for (y_n = i = 0; i < W_ord; i++) y_n = y_n + w[i] * x_yn[i];
//		//求y1(n)-Q
//		for (i = Sec_ord - 1; i > 0; i--) y_y1n[i] = y_y1n[i - 1];
//		y_y1n[0] = y_n;
//		for (xt = i = 0; i < Sec_ord; i++)
//		{
//			xt = xt + (long long)C[i] * (long long)y_y1n[i];
//		}
//		y1_n =( xt >> Q );
//
//		//求x1(n)-Q
//		for (v_x1 = i = 0; i < Sec_ord; i++) v_x1 = v_x1 + C[i] * x_dn[i];
//		for (i = W_ord - 1; i > 0; i--) x1_n[i] = x1_n[i - 1];//倒序
//		x1_n[0] = v_x1>>Q;
//		//x1_n[0] = vi1;
//
//		//w(n)
//		for (i = 0, x_yn2 = 0; i < W_ord; i++) x_yn2 +=x1_n[i] *x1_n[i];
//		//xt1 = (xt1 >> Q);
//
//		y_err = (d_n - y1_n);
//		
//		for (i = 0; i < W_ord; i++)
//		{
//			xt1 =((((long long)STEP * (long long)x1_n[i])* (long long)y_err)>>Q)/ x_yn2; 
//			w[i] = w[i] + xt1 ;
//		}
//		j = y_err >> Q;
//		if ((point % 8000) == 0)
//			printf("%d points have been processed...          %d\n", point, y_err/65536);
//		 //if ((point < 500))  printf("%d points have been processed...          % d\n", point, y_err);
//		fwrite(&j, sizeof(short), 1L, f_y);
//	}
//
//	
//	for (i = 0; i < W_ord; i++) printf("%f    %d\n", w[i]/65536.0, i);
//	//for (i = 0; i < W_ord; i++) printf("%d\n", y_err);
//	fclose(f_x);
//	fclose(f_y);
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>
#define W_ord 200
#define H1_TRUE_ORD 18
#define Sec_ord 12
#define Q 15

const int A[H1_TRUE_ORD] = {
                2109,-825,1361,-1417,2185,-2608,4163,-6703,20983,20983 ,-6703,4163 ,-2608 ,2185, -1417,1361, -825, 2109
};

const int C[Sec_ord] = {
                -3364, 1910 ,-2646 ,3929 ,-6805 ,20810 ,20810 ,-6805 , 3929,-2646 ,-1910 ,-3364 
};


int main()
{
    int i ,k;
    int point;
    short vi;
    int  y_err = 0;
    int d_n, y_n, y1_n, v_x1, x_yn2;
    int x_dn[H1_TRUE_ORD] = { 0 };
    int w[W_ord] = { 0 };
    int x_yn[W_ord] = { 0 };
    int x1_n[W_ord] = { 0 };
    int y_y1n[Sec_ord] = { 0 };
    int STEP = 3277;
    long long xt;
    //long long xt1, xt;
    FILE* f_x,*f_y;
    f_x = fopen("whitenoise.pcm", "rb");
    if (f_x == NULL) { printf("Cann't open the nosie file!!!\n");  exit(0); }
    f_y = fopen("out.pcm", "wb");
    if (f_y == NULL) { printf("Cann't open the out file!!!\n");  exit(0); }
  // for (i = 0;i < 200;i++) w[i] = 1<<Q;

    for (point = 0;; point++) {
        if (fread(&vi, sizeof(short), 1L, f_x) == 0) break; 
        //d(n)-Q
        for (i = H1_TRUE_ORD - 1; i > 0; i--) x_dn[i] = x_dn[i - 1];
        x_dn[0] = vi;
        for (d_n = i = 0; i < H1_TRUE_ORD; i++) d_n = d_n + A[i] * x_dn[i];
        d_n = d_n >> Q;
        //y(n)-Q
        for (i = W_ord - 1; i > 0; i--) x_yn[i] = x_yn[i - 1];
        x_yn[0] = vi;
        for (y_n = i = 0; i < W_ord; i++) y_n = y_n + w[i] * x_yn[i];
        y_n = y_n >> Q;
        //y1(n)-Q
        for (i = Sec_ord - 1; i > 0; i--) y_y1n[i] = y_y1n[i - 1];
        y_y1n[0] = y_n;
        for (y1_n = i = 0; i < Sec_ord; i++)  y1_n = y1_n +C[i] * y_y1n[i];
        y1_n = y1_n >> Q;
        //x1(n)-Q
        for (v_x1 = i = 0; i < Sec_ord; i++) v_x1 = v_x1 + C[i] * x_dn[i];
        for (i = W_ord - 1; i > 0; i--) x1_n[i] = x1_n[i - 1];
        x1_n[0] = v_x1 >> Q;
        //w(n)
        for (i = 0, xt = 0; i < W_ord; i++) xt += (long long)x1_n[i] * (long long)x1_n[i];
        x_yn2 = xt>>Q;
        if (x_yn2 == 0) x_yn2 = 1;
        x_yn2 = (33554432) / x_yn2;
        y_err = (d_n - y1_n);
        //#pragma cgra map(to: STEP,x1_n,y_err,x_yn2) map(tofrom: w)
        for (int j = 0; j < W_ord; j++)
        {
            k = ((((STEP * x1_n[j]) * y_err) >> Q) * x_yn2) >> 25;
            w[j] = w[j]+k;
            

          //  w[j] = w[j] >> Q;
            
        }
        if ((point % 8000) == 0)
            printf("%d points have been processed...          %d\n", point, y_err);
        fwrite(&y_err, sizeof(short), 1L, f_y);
    }
    for (i = 0; i < W_ord; i++) printf("%d    %d\n", w[i], i);

    fclose(f_x);
    return 0;
}
