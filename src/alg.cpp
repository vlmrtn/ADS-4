// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
        while (j + 1 < len && arr[j] == arr[j + 1]) {
          j++;
        };
      }
    }
  }
  return count;
}

void bubbleSort(int *arr, int len) {
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  bubbleSort(arr, len);
  int left = 0;
  int right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      count++;
      left++;
      right--;
      while (left < right && arr[left] == arr[left - 1]) {
        left++;
      }
      while (left < right && arr[right] == arr[right - 1]) {
        right--;
      }
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int binarySearch(int *arr, int len, int target, int left) {
  int low = left;
  int high = len - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int number = value - arr[i];
    int index = binarySearch(arr, len, number, i + 1);
    if (index != -1) {
      count++;
    }
    while (i < len - 1 && arr[i] == arr[i + 1]) {
      i++;
    }
  }
  return count;
}
