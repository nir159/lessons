#pragma once
#define FIRST_BIGGER -1
#define EQUALES 0
#define SECOND_BIGGER 1

#define SECOND_ELEMENT 1

template <class T>
int compare(T first, T second) {
	if (second < first) {
		return FIRST_BIGGER;
	}
	else if (first == second) {
		return EQUALES;
	}
	return SECOND_BIGGER;
}

template <class T>
void bubbleSort(T arr[], int length) {
	T temp;
	bool swapped = false;
	int i = 0;
	do {
		swapped = false;
		for (i = SECOND_ELEMENT; i < length; i++) {
			if (arr[i] < arr[i - SECOND_ELEMENT]) {
				temp = arr[i];
				arr[i] = arr[i - SECOND_ELEMENT];
				arr[i - SECOND_ELEMENT] = temp;
				swapped = true;
			}
		}
	} while (swapped);
}

template <class T>
void printArray(T arr[], int length) {
	int i = 0;
	for (i = 0; i < length; i++) {
		std::cout << arr[i] << std::endl;
	}
}