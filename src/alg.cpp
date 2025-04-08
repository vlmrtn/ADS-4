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
    } else if (sum < value) {
      left++;
    } else {
      right--;
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
      if (arr[left] == arr[right]) {
        int num = right - left + 1;
        count += (num * (num - 1)) / 2;
        break;
      } else {
        int countl = 1;
        int countr = 1;
        while (left + 1 < right && arr[left] == arr[left + 1]) {
          countl++;
          left++;
        }
        while (right - 1 > left && arr[right] == arr[right - 1]) {
          countr++;
          right--;
        }
        count += countl * countr;
        left++;
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
