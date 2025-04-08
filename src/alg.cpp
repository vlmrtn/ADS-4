// Copyright 2021 NNTU-CS
void insertionsort(int* arr, int size) {
  for (int i = 1; i < size; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
  }
  arr[j + 1] = key;
}

int binarySearch(int* arr, int left, int right, int value) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == value) {
      return mid;
    }
    if (arr[mid] < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  insertionsort(arr, len);
  for (int i = 0; i < len; i++) {
    if (i > 0 && arr[i] == arr[i - 1]) {
      continue;
    }
    int num = value - arr[i];
    if (binarySearch(arr, i + 1, len - 1, num) != -1) {
      count++;
    }
  }
  return count;
}


int countPairs3(int *arr, int len, int value) {
  int count = 0;
  insertionsort(arr, len);
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      count++;
      left++;
      right--;
      while (left < right && arr[left] == arr[left - 1]) left ++;
      while (left < right && arr[right] == arr[right + 1]) right--;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}
