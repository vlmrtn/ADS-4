// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
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

void bubblesort(int *arr, int len) {
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
  bubblesort(arr, len);
  int count = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      count++;
      while (left < right && arr[left] == arr[left + 1]) {
        left++;
      }
      while (left < right && arr[right] == arr[right - 1]) {
        right--;
      }
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

int binarysearch(int *arr, int len, int target, int start) {
  int low = start;
  int high = len - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
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
  bubblesort(arr, len);
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
