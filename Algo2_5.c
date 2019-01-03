#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Merge(int * arr, int lef, int mid, int rig);
void MergeSortIterative(int* arr, int count);
int Min(int a, int b);

int sorted[100000];

int main(void) {
	int *arr; // 파일의 데이터를 저장할 포인터 변수 선언.
	int size = 1;
	FILE* f; // 파일
	int i = 0;
	int startTime = 0, endTime = 0;
	float gap;

	f = fopen("test_10000.txt", "r");

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

	startTime = clock();

	MergeSortIterative(arr, size-1);

	endTime = clock();
	gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);


	for (int j = 0; j < size - 1; j++) {
		printf("%d\n", arr[j]);
	}

	printf("측정 시간 : %f\n", gap);

	free(arr);
	fclose(f);

	system("pause"); // 테스트 보기 위해.

}
int Min(int a, int b) {
	return a <= b ? a : b;
}

void MergeSortIterative(int* arr, int count) {
	int crr; // 현재 사이즈
	int left, right, mid;
	for (crr = 1; crr <= count - 1; crr = 2 * crr)
	{
		for (left = 0; left < count - 1; left += 2 * crr)
		{
			right = Min(left + 2 * crr - 1, count - 1);
			mid = left + crr - 1;
			Merge(arr, left, mid, right);
		}
	}
}

void Merge(int * arr, int lef, int mid, int rig)
{
	int i = lef; // 왼쪽 리스트에 대한 인덱스
	int j = mid + 1; // 오른쪽 리스트에 대한 인덱스
	int k = lef; // 리스트에 대한 인덱스
	int l;


	/* 분할 정렬된 리스트 합병*/
	while (i <= mid && j <= rig) {
		if (arr[i] <= arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}

	if (i > mid)
		for (l = j; l <= rig; l++)
			sorted[k++] = arr[l];
	else
		for (l = i; l <= mid; l++)
			sorted[k++] = arr[l];

	/*배열 sorted[]의 리스트를 배열 arr[]로 복사*/
	for (l = lef; l <= rig; l++)
		arr[l] = sorted[l];

}