// Copyright 2021 NNTU-CS
int binarySearch(int* arr, int left, int right, int value) {
    int count = 0;
    int check;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            count++;
            check = mid - 1;
            while (check >= left && arr[check] == value) {
                count++;
                check--;
            }
            check = mid + 1;
            while (check <= right && arr[check] == value) {
                count++;
                check++;
            }
            break;
        } else if (arr[mid] < value) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
    }
    return count;
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

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int rboard = len - 1;
    for (; 1;) {
        if (arr[rboard] > value) {
            rboard--;
        } else { 
            break; 
        }
    }
    for (int i = 0; i <= rboard; i++) {
        for (int j = rboard; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}


int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int num = value - arr[i];
        if (num <= 0) {
            break;
        }
        count += binarySearch(arr, i + 1, len - 1, num);
    }
    return count;
}
