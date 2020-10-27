//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int N;
//double** a;
//double* x;
//double* b;
//
//double sum(int k);
//int main()
//{
//	printf("请输入方程组未知数个数：");
//	scanf("%d", &N);
//
//	b = (double*)malloc(sizeof(double) * (N + 1));
//	x = (double*)malloc(sizeof(double) * (N + 1));
//
//	a = (double**)malloc(sizeof(double*) * (N + 1));
//	for (int i = 1; i <= N; i++)
//	{
//		a[i] = (double*)malloc(sizeof(double) * (N + 1));
//	}
//
//	//将输入存入数组
//	printf("请输入方程组，每一项之间以空格分隔，方程之间以回车分隔：");
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			scanf("%lf", &a[i][j]);
//		}
//		scanf("%lf", &b[i]);
//	}
//
//	
//	//消元
//	int k = 1;
//	while (k<N)
//	{
//		if (a[k][k] == 0)
//		{
//			printf("主对角线出现0元素，算法失效。");
//			return -1;
//		}
//		double m;
//		for (int i = k + 1; i <= N; i++)
//		{
//			m = a[i][k] / a[k][k];
//			for (int j = k + 1; j <= N; j++)
//			{
//				a[i][j] = a[i][j] - a[k][j] * m;
//			}
//			b[i] = b[i] - m * b[k];
//		}
//
//		k++;
//	}
//
//	//回代
//	x[N] = b[N] / a[N][N];
//	for (int q = N - 1; q >= 1; q--)
//	{
//		x[q] = (b[q] - sum(q))/a[q][q];
//	}
//
//
//	//输出结果
//	for (int i = 1; i <= N; i++)
//	{
//		printf("%lf ", x[i]);
//	}
//	system("PAUSE");
//	return 0;
//}
//
//double sum(int k)
//{
//	double result = 0.0;
//	for (int j = k + 1; j <= N; j++)
//	{
//		result += a[k][j] * x[j];
//	}
//	return result;
//}
