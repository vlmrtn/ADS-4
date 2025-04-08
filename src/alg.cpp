// Copyright 2021 NNTU-CS
void insertionsort(int* arr, int len) {
  for (int i = 1; i < len; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
  }
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
  insertionsort(arr, len);
  int left = 0;
  int right = len-1;
  int count = 0;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      count++;
      for (int i = left+1; i < right; i++) {
        if (arr[i] == value - arr[left]) {
          count++;
        }
      }
      left++;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}


int countPairs3(int *arr, int len, int value) {
  insertionsort(arr, len);
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int num = value - arr[i];
    if (num <= 0) {
      break;
    }
    count += binarySearch(arr, i+1, len-1, num);
  }
  return count;
}
