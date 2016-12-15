#include<stdio.h>
#include<stdlib.h>
double** sum(double ** a, int n, int m, double ** b, int n2, int m2)
{
	if((n == m) && (n2 == m2))
	{
		int i, j;	
		double** c;
		c = (double**)malloc(n*sizeof(double*));
		for (i = 0; i < n; i++)
	        {
	                c[i] = (double*)malloc(m*sizeof(double));
	                for (j = 0; j < m; j++)
	                {
	                        c[i][j] = a[i][j] + b[i][j];
	                }
	        }
		return c;
	}
	else
	{
		return NULL;
	}
}
double** razn(double ** a, int n, int m, double ** b, int n2, int m2)
{
        if((n == m) && (n2 == m2))
        {
                int i, j;
                double** c;
                c = (double**)malloc(n*sizeof(double*));
                for (i = 0; i < n; i++)
                {
                        c[i] = (double*)malloc(m*sizeof(double));
                        for (j = 0; j < m; j++)
                        {
                                c[i][j] = a[i][j] - b[i][j];
                        }
                }
                return c;
        }
        else
        {
                return NULL;
        }
}
double** proizv(double ** a, int n, int m, double ** b, int n2, int m2)
{
        if(m == n2)
        {
                int i, j, k;
                double** c;
                c = (double**)malloc(n*sizeof(double*));
                for (i = 0; i < n; i++)
                {
                        c[i] = (double*)malloc(m2*sizeof(double));
			for (j = 0; j < m2; j++)
                        {
				c[i][j] = 0;
				for(k = 0; k < m; k++)
				{ 
                                	c[i][j] += a[i][k]*b[k][j];
                        	}
			}
                }
                return c;
        }
        else
        {
                return NULL;
        }
}

int main()
{
	int n, m, i, j, n2, m2;
	double** mas;
	double** mas2;	
	printf("Matr a - n str m stolb\n");
	scanf("%d%d", &n, &m);
        mas = (double**)malloc(n*sizeof(double*));
        for (i = 0; i < n; i++)
        {
                mas[i] = (double*)malloc(m*sizeof(double));

                for (j = 0; j < m; j++)
                {
                        scanf("%lf",&mas[i][j]);
                }
        }
	printf("Matr b - n2 str m2 stolb\n");
        scanf("%d%d", &n2, &m2);
        mas2 = (double**)malloc(n*sizeof(double*));
        for (i = 0; i < n2; i++)
        {
                mas2[i] = (double*)malloc(m2*sizeof(double));

                for (j = 0; j < m2; j++)
                {
                        scanf("%lf",&mas2[i][j]);
                }
        }
	for (i = 0; i < n; i++)
        {
                for (j = 0; j < m; j++)
                {
                        printf("%lf ",mas[i][j]);
                }
		printf("\n");
        }
	printf("\n");
	double ** c = sum(mas, n, m, mas2, n2, m2);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m2; j++)
		{
			printf("%lf ", c[i][j]);
		}
		printf("\n");
	}
	double ** c = razn(mas, n, m, mas2, n2, m2);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m2; j++)
		{
			printf("%lf ", c[i][j]);
		}
		printf("\n");
	}

	double ** c = proizv(mas, n, m, mas2, n2, m2);
	for (i = 0; i < n; i++)
        {
                for (j = 0; j < m2; j++)
                {
                        printf("%lf ",c[i][j]);
                }
                printf("\n");
        }


	return 0;
}
