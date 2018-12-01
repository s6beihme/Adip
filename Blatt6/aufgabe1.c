/* Matrix multiplication */
#include <stdio.h>
#include <stdlib.h>

/**
 * Allocates the memory for a new matrix of size dim1 x dim2
 */
double **allocMatrix(int dim1, int dim2) {
  double **res;
  if ((res = (double **) malloc(dim1*sizeof(double *))) == NULL) {
    printf("allocMatrix: Error allocating memory.\n");
    return NULL;
  }
  for (int i=0; i<dim1; i++) {
    if ((res[i] = (double *) malloc(dim2*sizeof(double))) == NULL) {
      printf("allocMatrix: Error allocating memory.\n");
      for (int j=0; j<i; i++) {
        free(res[i]);
      }
      free(res);
      return NULL;
    }
  }

  return res;
}

/**
 * Frees the memory of a Matrix
 */
void freeMatrix(double **matrix, int dim1, int dim2) {
  for (int i=0; i<dim1; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

double **multiply(double **A, int dim1A, int dim2A, double **B, int dim1B, int dim2B) {
  if (dim2A != dim1B) {
    printf("multiply: Dimensions do not match.\n");
    return NULL;
  }

  double **res = allocMatrix(dim1A, dim2B);

  for (int i=0; i<dim1A; i++) {
    for (int j=0; j<dim2B; j++) {
      double sum = 0;
      for (int k=0; k<dim2A; k++) {
        sum += A[i][k] * B[k][j];
      }
      res[i][j] = sum;
    }
  }

  return res;
}

void printMatrix(double **matrix, int dim1, int dim2) {
  for (int i=0; i<dim1; i++) {
    for (int j=0; j<dim2; j++) {
      printf("%lf ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  return 0;
}
