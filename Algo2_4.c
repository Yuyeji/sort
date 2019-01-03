#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

void BinarySearch(int *arr, int first, int last, int findData);

int main(void) {
	int *arr; // ������ �����͸� ������ ������ ���� ����.
	int size = 1;
	FILE* f; // ����
	int i = 0;
	int input; // �Է¹��� ����


	f = fopen("test_recursive.txt", "r");

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

	printf("���ϴ� �����͸� �Է����ּ���.\n");
	scanf("%d", &input);

	BinarySearch(arr, 0, size - 1, input);

	free(arr);
	fclose(f);

	system("pause"); // �׽�Ʈ ���� ����.

}

void BinarySearch(int *arr, int first, int last, int findData)
{
	int mid;
	mid = (first + last) / 2;

	if (arr[mid] > findData)
		BinarySearch(arr, first, mid - 1, findData);
	else if (arr[mid] < findData)
		BinarySearch(arr, mid+1, last, findData);
	else {
		printf("������ ã�� SUCCESS...\n���ϴ� �����ʹ� %d�� %d��°�� �ֽ��ϴ�.\n", arr[mid], mid + 1);	
	}

}