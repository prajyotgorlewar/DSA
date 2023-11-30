#include <stdio.h>

void printArray(int arr[100][100], int m, int n) 
{
    printf("Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}

void matmulti(int arrA[100][100], int arrB[100][100], int m, int n)
{
    int arrD[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arrD[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
    printf("Multiplied Matrix :\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arrD[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int arr1[100][100], int m, int n, int brr[100][100]) 
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            brr[i][j] = arr1[j][i];
        }
    }
    printf("Transposed\n");
    printArray(brr, n, m);
}

void addArrays(int m, int n) 
{
    int arrA[100][100], arrB[100][100], arrC[100][100];

    printf("Enter the elements of array A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arrA[i][j]);
        }
    }

    printf("Enter the elements of array B:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arrB[i][j]);
        }
    }

    printf("Addition of Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
            printf("%3d", arrC[i][j]);
        }
        printf("\n");
    }
    matmulti(arrA, arrB, m, n);
}



void diagonalsum(int arr1[100][100], int m, int n)
{
  int diasum = 0;
   for (int i = 0; i < m; i++) 
   {
        for (int j = 0; j < n; j++) 
        {
            if(i == j)
            {
              diasum += arr1[i][j];
            }
        }
    }
    printf("Sum of Diagonal Elements : %d\n",diasum);
}

void uppertriangular(int m, int n)
{
  int updia[100][100];
  printf("Upper triangular matrix:\n");
  for (int i = 0; i < m; i++) 
  {
        for (int j = 0; j < n; j++) {
            if(j>=i)
            {
              updia[i][j] = 0;
            }
            else
            {
               updia[i][j] = 1;
            }

        }
    }

    printf("Upper diagonal matrix is:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
           printf("%3d", updia[i][j]);
        }
        printf("\n");
    }

   
}

int main() {
    int m, n;
    printf("Enter number of rows m: ");
    scanf("%d", &m);
    printf("Enter number of columns n: ");
    scanf("%d", &n);

    int arr1[100][100];
    int brr[100][100];

    printf("Enter the elements of array 1:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Original\n");
    printArray(arr1, m, n);
    transposeMatrix(arr1, m, n, brr);
    diagonalsum(arr1,m,n);
    uppertriangular(m, n);
    addArrays(m, n);

   
    return 0;
}



