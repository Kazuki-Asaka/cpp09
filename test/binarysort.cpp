#include <iostream>
#include <vector>

// 二分探索で挿入位置を見つける関数
int binarySearch(const std::vector<int>& arr, int key, int start, int end) {
    while (start < end) {
        int mid = (start + end) / 2;
        if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid;
    }
    return start;
}

// バイナリ挿入ソート
void binaryInsertionSort(std::vector<int>& arr) {
    int n = arr.size();
    // for (int i = 1; i < n; ++i) {
        int key = 3;
        // 挿入位置を二分探索で求める
        int pos = binarySearch(arr, key, 0, n - 1);
		std::cout << "pos :" << pos << std::endl;
        // 挿入位置までの要素を後ろにずらす
        // for (int j = i; j > pos; --j) {
        //     arr[j] = arr[j - 1];
        // }
        // arr[pos] = key;
    // }
}

int main() {
	std::vector<int> vec = {1, 2};

    std::cout << "Before sorting: ";
    for (int num : vec) std::cout << num << " ";
    std::cout << std::endl;

    binaryInsertionSort(vec);

    std::cout << "After sorting: ";
    for (int num : vec) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
