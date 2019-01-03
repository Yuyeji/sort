#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int * arr, int first, int last);

int main(void) {
	int *arr; // 파일의 데이터를 저장할 포인터 변수 선언.
	int size = 1;
	FILE* f; // 파일
	int i = 0;
	int num = 0;
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

	BubbleSort(arr, 0, size - 1);

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

void BubbleSort(int * arr, int first, int last)
{
	int i, j; // 반복문을 돌리기 위한 변수
	int m = last - 1;
	int temp; // 임시 변수

	for (i = first; i < last; i++) { // 데이터 개수만큼 반복
		for (j = first; j < m; j++) { // 데이터 -1 만큼 반복
			if (arr[j] > arr[j+1]) { //앞의 수가 더 크면 앞뒤 위치를 바꿔준다.
				temp = arr[j]; 
				arr[j] = arr[j + 1];
				arr[j + 1] = temp; 
			}
		}
	}
}
