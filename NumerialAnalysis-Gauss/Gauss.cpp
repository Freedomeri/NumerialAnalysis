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
//	printf("�����뷽����δ֪��������");
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
//	//�������������
//	printf("�����뷽���飬ÿһ��֮���Կո�ָ�������֮���Իس��ָ���");
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
//	//��Ԫ
//	int k = 1;
//	while (k<N)
//	{
//		if (a[k][k] == 0)
//		{
//			printf("���Խ��߳���0Ԫ�أ��㷨ʧЧ��");
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
//	//�ش�
//	x[N] = b[N] / a[N][N];
//	for (int q = N - 1; q >= 1; q--)
//	{
//		x[q] = (b[q] - sum(q))/a[q][q];
//	}
//
//
//	//������
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
