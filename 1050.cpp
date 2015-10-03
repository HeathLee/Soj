//
// Created by heath on 15-10-3.
//

#include <iostream>

using namespace std;
/*
 * 思路：
 * 五个数中任意合并两个数，
 * 题目分解为对四个数求解的子问题，
 * 然后对剩余的四个数递归运算
 */

int result = INT32_MIN;
int input[6];

void dfs(int deep) {
    for (int k = 0; k < 5; ++k) {
        if (input[k] == input[5]) {
            result = input[k];
            return;
        }
        if (input[k] < input[5] && result < input[k]) {
            result = input[k];
        }
    }

    //任意合并两个数的运算结果，合并后的结果存放在input[i]
    for (int i = 0; i < deep; ++i) {
        for (int j = i + 1; j < deep; ++j) {
            int left = input[i], right = input[j];
            input[j] = input[deep - 1]; //将数组尾部的数移到前面，数组规模减一
            input[i] = left + right;
            dfs(deep - 1);
            input[i] = left - right;
            dfs(deep - 1);
            input[i] = right - left;
            dfs(deep - 1);
            input[i] = left * right;
            dfs(deep - 1);
            if (right && left % right == 0) {
                input[i] = left / right;
                dfs(deep - 1);
            }
            if (left && right % left == 0) {
                input[i] = right / left;
                dfs(deep - 1);
            }
            //回溯，准备重新选取两个数
            input[i] = left;
            input[j] = right;
        }
    }
}

int main() {
    int case_number;
    cin >> case_number;
    while (case_number--) {
        result = INT32_MIN;
        for (int i = 0; i < 6; ++i) {
            cin >> input[i];
        }
        dfs(5);
        cout << result << endl;
    }
}
