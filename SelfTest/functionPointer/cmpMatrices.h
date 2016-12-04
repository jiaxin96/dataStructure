#define MAX_SIZE 4
#define MAX_TOTAL 10
#include <stdio.h>
int cmpMatrices(const void *firstMatrixPtr, const void *secondMatrixPtr, void *sizePtr) {
	int *Tsize = (int *)(sizePtr);
	int size = *Tsize;
	int (*first)[MAX_SIZE] = (int (*)[MAX_SIZE])(firstMatrixPtr);
	int sum1 = 0;
	int (*second)[MAX_SIZE] = (int (*)[MAX_SIZE])(secondMatrixPtr);
	int sum2 = 0;
	for (int i = 0; i < size; ++i) {
		sum1 += (   ( *(first+i) )[i]  + ( *(first+i) )[size-1-i]     );
		sum2 += (   ( *(second+i) )[i]  + ( *(second+i) )[size-1-i]     );
	}
	return (sum1 > sum2);
}
void inputMatrices(int matrix[][MAX_SIZE], size_t size) {
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
}
void printMatrices(int matrix[][MAX_SIZE], size_t size) {
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}