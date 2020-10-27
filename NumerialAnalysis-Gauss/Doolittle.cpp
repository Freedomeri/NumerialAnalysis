#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int N;
double** a;
double* x;
double* b;
double* y;

double sum1(int k,int j);
double sum2(int k,int i);
double sum3(int i);
double sum4(int i);

int main()
{
	printf("请输入方程个数：");
	scanf("%d", &N);

	//数组分配空间
	a = (double**)malloc(sizeof(double*) * (N + 1));
	b = (double*)malloc(sizeof(double) * (N + 1));
	x = (double*)malloc(sizeof(double) * (N + 1));
	y = (double*)malloc(sizeof(double) * (N + 1));

	for (int i = 1; i <= N; i++)
	{
		a[i] = (double*)malloc(sizeof(double) * (N + 1));
	}

	//获取输入
	printf("请输入方程组，每一项之间以空格分隔，方程之间以回车分隔：");
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%lf", &a[i][j]);
		}
		scanf("%lf", &b[i]);
	}

	//Doolittle分解
	for (int k = 1; k <= N; k++)
	{
		for (int j = k; j <= N; j++)
		{
			a[k][j] = a[k][j] - sum1(k,j);
		}
		if (k < N)
		{
			for (int i = k + 1; i <= N; i++)
			{
				a[i][k] = (a[i][k] - sum2(k, i)) / a[k][k];
			}
		}
		
	}

	//回代求解
	y[1] = b[1];
	for (int i = 2; i <= N; i++)
	{
		y[i] = b[i] - sum3(i);
	}

	x[N] = y[N] / a[N][N];
	for (int i = N - 1; i >= 1; i--)
	{
		x[i] = (y[i] - sum4(i))/a[i][i];
	}

	//输出解向量
	for (int i = 1; i <= N; i++)
	{
		printf("x%d=%lf ", i, x[i]);
	}
	
	system("PAUSE");
	return 0;
}

double sum1(int k,int j)
{
	double result = 0;
	for (int t = 1; t <= k - 1; t++)
	{
		result += a[k][t] * a[t][j];
	}
	return result;
}

double sum2(int k,int i)
{
	double result = 0;
	for (int t = 1; t <= k - 1; t++)
	{
		result += a[i][t] * a[t][k];
	}
	return result;
}

double sum3(int i)
{
	double result = 0;
	for (int t = 1; t <= i - 1; t++)
	{
		result += a[i][t] * y[t];
	}
	return result;
}

double sum4(int i)
{
	double result = 0;
	for (int t = i + 1; t <= N; t++)
	{
		result += a[i][t] * x[t];
	}
	return result;
}
