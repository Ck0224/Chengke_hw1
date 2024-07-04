#include "algebra.h"
#include <stdio.h>
#include <math.h>

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{
    // ToDo
    if (a.cols!=b.cols||a.rows!=b.rows)
    {
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0, 0);
    }
    Matrix m;
    for (int i = 0; i < a.rows; i++)
        for (int j = 0; j < a.cols; j++)
        {
           m.data[i][j]=a.data[i][j]+ b.data[i][j];
        }
    m.cols=a.cols;
    m.rows=a.rows;
    return m;
}

Matrix sub_matrix(Matrix a, Matrix b)
{
    // ToDo
    if (a.cols!=b.cols||a.rows!=b.rows)
    {
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0, 0);
    }
    Matrix m;
    for (int i = 0; i < a.rows; i++)
        for (int j = 0; j < a.cols; j++)
        {
           m.data[i][j]=a.data[i][j]- b.data[i][j];
        }
    m.cols=a.cols;
    m.rows=a.rows;
    return m;
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    // ToDo
    if (a.cols!=b.rows)
    {
        printf("Error: The number of cols of matrix a must be equal to the number of rows of matrix b.\n");
        return create_matrix(0, 0);
    }
    Matrix m;
    m.rows=a.rows,m.cols=b.cols;
	for(int i=0; i<m.rows; i++)
		for(int j=0; j<m.cols; j++) {
			m.data[i][j]=0;
			int k=0;
			while(k<a.cols)
				m.data[i][j]+=a.data[i][k]*b.data[k][j],k++;
		}
    return m;
}

Matrix scale_matrix(Matrix a, double k)
{
    // ToDo
    Matrix c;
    for (int i = 0; i < a.rows; i++)
        for (int j = 0; j < a.cols; j++)
        {
           c.data[i][j]=a.data[i][j]*k;
        }
    c.cols=a.cols;
    c.rows=a.rows;
    return c;
}

Matrix transpose_matrix(Matrix a)
{
    // ToDo
    Matrix c; 
    c.rows=a.cols; 
    c.cols=a.rows; 
    for (int i = 0; i < a.rows; i++)
        for(int j = 0; j < a.cols; j++)
            c.data[j][i] = a.data[i][j];
    return c;
}

double det_matrix(Matrix a)
{
    // ToDo
    if (a.cols!=a.rows)
    {
        printf("Error: The matrix must be a square matrix.\n");
        return 0;
    }
    
}

Matrix inv_matrix(Matrix a)
{
    // ToDo
    return create_matrix(0, 0);
}

int rank_matrix(Matrix a)
{
    // ToDo
    return 0;
}

double trace_matrix(Matrix a)
{
    // ToDo
    return 0;
}

void print_matrix(Matrix a)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}
