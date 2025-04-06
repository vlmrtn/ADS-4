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

int countPairs1(int *arr, int len, int value) {
  insertionsort(arr, len);
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = 1 + i; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  insertionsort(arr, len);
  int count = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      count++;
      int leftvalue = arr[left];
      int rightvalue = arr[right];
      while (left < right && arr[left] == leftvalue) {
        left++;
      }
      while (left < right && arr[right] == rightvalue) {
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

int binarysearch(int *arr, int len, int target, int start) {
  int low = start;
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
  insertionsort(arr, len);
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    if (i > 0 && arr[i] == arr[i - 1]) {
      continue;
    }
    int number = value - arr[i];
    int index = binarysearch(arr, len, number, i + 1);
    if (index != -1) {
      count++;
      while (index + 1 < len && arr[index + 1] == number) {
        count++;
        index++;
      }
    }
  }
  return count;
}
