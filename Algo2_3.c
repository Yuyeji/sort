#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int * arr, int first, int last);

int main(void) {
	int *arr; // ������ �����͸� ������ ������ ���� ����.
	int size = 1;
	FILE* f; // ����
	int i = 0;
	int num = 0;
	int startTime = 0, endTime = 0;
	float gap;


	f = fopen("test_10000.txt", "r");

	if (f == NULL) {
		printf("������ ������ �ʽ��ϴ�.");
		exit(1);
	}

	arr = (int *)malloc(sizeof(int));

	while (feof(f) == 0) {
		arr = (int *)realloc(arr, (size) * sizeof(int));
		fscanf(f, "%d", &arr[i]);
		size++;
		i++;
	}

	startTime = clock();

	BubbleSort(arr, 0, size - 1);

	endTime = clock();

	gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);

	for (int j = 0; j < size - 1; j++) {
		printf("%d\n", arr[j]);
	}

	printf("���� �ð� : %f\n", gap);

	free(arr);
	fclose(f);

	system("pause"); // �׽�Ʈ ���� ����.

}

void BubbleSort(int * arr, int first, int last)
{
	int i, j; // �ݺ����� ������ ���� ����
	int m = last - 1;
	int temp; // �ӽ� ����

	for (i = first; i < last; i++) { // ������ ������ŭ �ݺ�
		for (j = first; j < m; j++) { // ������ -1 ��ŭ �ݺ�
			if (arr[j] > arr[j+1]) { //���� ���� �� ũ�� �յ� ��ġ�� �ٲ��ش�.
				temp = arr[j]; 
				arr[j] = arr[j + 1];
				arr[j + 1] = temp; 
			}
		}
	}
}
