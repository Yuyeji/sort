#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

void BinarySearch(int *arr, int first, int last, int findData);

int main(void) {
	int *arr; // 파일의 데이터를 저장할 포인터 변수 선언.
	int size = 1;
	FILE* f; // 파일
	int i = 0;
	int input; // 입력받을 변수


	f = fopen("test_recursive.txt", "r");

	if (f == NULL) {
		printf("파일이 열리지 않습니다.");
		exit(1);
	}

	arr = (int *)malloc(sizeof(int));

	while (feof(f) == 0) {
		arr = (int *)realloc(arr, (size) * sizeof(int));
		fscanf(f, "%d", &arr[i]);
		size++;
		i++;
	}

	printf("원하는 데이터를 입력해주세요.\n");
	scanf("%d", &input);

	BinarySearch(arr, 0, size - 1, input);

	free(arr);
	fclose(f);

	system("pause"); // 테스트 보기 위해.

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
		printf("데이터 찾기 SUCCESS...\n원하는 데이터는 %d는 %d번째에 있습니다.\n", arr[mid], mid + 1);	
	}

}