#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <stdexcept>
#include <utility>
#include <vector>

using namespace std;

// 1. 快速排序
int partition(vector<int> &nums, int left, int right) {

  // 挖坑法
  int pivot = nums[left];

  while (left < right) {
    while (left < right && nums[right] >= pivot) {
      --right;
    }

    nums[left] = nums[right];

    while (left < right && nums[left] <= pivot) {
      ++left;
    }

    nums[right] = nums[left];
  }

  nums[right] = pivot;

  return right;
}

void quicksort(vector<int> &nums, int left, int right) {

  if (left >= right)
    return;

  int pivot = partition(nums, left, right);

  quicksort(nums, left, pivot - 1);
  quicksort(nums, pivot + 1, right);
}

// 2. 插入排序
void insertion_sort(vector<int> &nums) {
  for (int i = 1; i < nums.size(); ++i) {
    int value = nums[i];

    int j = i - 1;

    while (j >= 0 && value < nums[j]) {
      nums[j + 1] = nums[j];

      --j;
    }

    nums[j + 1] = value;
  }
}

// 3. 希尔排序

void shell_sort(vector<int> &nums) {
  int gap = nums.size() / 2;

  while (gap > 0) {
    for (int i = gap; i < nums.size(); ++i) {
      int value = nums[i];

      int j = i - gap;

      while (j >= 0 && value < nums[j]) {
        nums[j + gap] = nums[j];

        j -= gap;
      }

      nums[j + gap] = value;
    }

    gap /= 2;
  }
}

// 4. 归并排序

void merge(vector<int> &nums, int left, int mid, int right) {
  vector<int> temp(right - left + 1);

  int i = left, j = mid + 1, k = 0;

  while (i <= mid && j <= right) {
    if (nums[i] <= nums[j]) {
      temp[k++] = nums[i++];
    } else {
      temp[k++] = nums[j++];
    }
  }

  while (i <= mid) {
    temp[k++] = nums[i++];
  }

  while (j <= right) {
    temp[k++] = nums[j++];
  }

  for (int i = 0; i < right - left + 1; ++i) {
    nums[left + i] = temp[i];
  }
}

void merge_sort2(vector<int> &nums, int left, int right) {
  if (left >= right) {
    return;
  }

  int mid = (left + right) >> 1;

  merge_sort2(nums, left, mid);
  merge_sort2(nums, mid + 1, right);

  merge(nums, left, mid, right);
}

void merge_sort(vector<int> &nums) {

  int left = 0;
  int right = nums.size() - 1;

  merge_sort2(nums, left, right);
}

// 5. 堆排序

void heapnify(vector<int> &nums, int current, int heapsize) {

  int large = current;

  int left = current * 2 + 1;
  int right = current * 2 + 2;

  if (left < heapsize && nums[left] > nums[large])
    large = left;
  if (right < heapsize && nums[right] > nums[large])
    large = right;

  if (large != current) {
    swap(nums[large], nums[current]);
    heapnify(nums, large, heapsize);
  }
}

void heap_sort(vector<int> &nums) {
  int n = nums.size();

  for (int i = n / 2 - 1; i >= 0; --i) {
    heapnify(nums, i, nums.size());
  }

  for (int i = n - 1; i >= 0; --i) {
    swap(nums[0], nums[i]);
    heapnify(nums, 0, i);
  }
}

// 6. 计数排序

void count_sort(vector<int> &nums) {
  map<int, int> counts;

  for (int i = 0; i < nums.size(); ++i) {
    if (counts.count(nums[i]) == 0) {
      counts[nums[i]] = 1;
    } else {
      counts[nums[i]]++;
    }
  }

  int i = 0;

  for (auto element : counts) {
    while (element.second != 0) {
      nums[i++] = element.first;
      --element.second;
    }
  }
}

// 7. 基数排序

int bit_count(int number) {
  int count = 0;

  while (number != 0) {
    number /= 10;
    ++count;
  }

  return count;
}

void radix_sort_exp(vector<int> &nums, int exp) {
  int counts[10] = {0};
  for (auto const &x : nums) {
    counts[(x / exp) % 10]++;
  }

  for (int i = 1; i < 10; ++i) {
    counts[i] += counts[i - 1];
  }

  vector<int> output(nums.size());

  for (int i = nums.size() - 1; i >= 0; --i) {
    output[counts[(nums[i] / exp) % 10] - 1] = nums[i];

    counts[(nums[i] / exp) % 10]--;
  }

  for (int i = 0; i < nums.size(); ++i) {
    nums[i] = output[i];
  }
}

void radix_sort(vector<int> &nums) {
  int max_ele = *max_element(nums.begin(), nums.end());

  for (int i = 1; max_ele / i > 0; i *= 10) {
    radix_sort_exp(nums, i);
  }
}

int main() {
  vector<int> nums{5, 4, 6, 3, 2, 1, 7, 60};

  radix_sort(nums);

  for (auto x : nums) {
    cout << x << ' ';
  }

  cout << endl;

  return 0;
}
