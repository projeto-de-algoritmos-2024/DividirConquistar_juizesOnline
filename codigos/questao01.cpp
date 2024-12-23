#include <iostream>
#include <vector>
using namespace std;

long long merge_and_count(vector<int> &arr, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    long long inversions = 0;
    vector<int> temp(right - left + 1);

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }

    return inversions;
}

long long count_inversions(vector<int> &arr, int left, int right) {
    long long inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inversions += count_inversions(arr, left, mid);
        inversions += count_inversions(arr, mid + 1, right);
        inversions += merge_and_count(arr, left, mid, right);
    }
    return inversions;
}

int main() {
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        long long inversions = count_inversions(arr, 0, N - 1);

        if (inversions % 2 == 0) {
            cout << "Carlos" << endl;
        } else {
            cout << "Marcelo" << endl;
        }
    }

    return 0;
}