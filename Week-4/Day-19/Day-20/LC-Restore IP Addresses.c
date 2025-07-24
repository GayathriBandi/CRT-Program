A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

Example 1:
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Example 2:
Input: s = "0000"
Output: ["0.0.0.0"]

Example 3:
Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char** res;
int resSize;

bool isValid(char* s, int start, int end) {
    if (start > end) return false;
    if (s[start] == '0' && start != end) return false;
    int num = 0;
    for (int i = start; i <= end; i++) {
        if (s[i] < '0' || s[i] > '9') return false;
        num = num * 10 + (s[i] - '0');
        if (num > 255) return false;
    }
    return true;
}

void backtrack(char* s, int start, int dots, char* path, int pathLen) {
    if (dots == 3) {
        int len = strlen(s);
        if (!isValid(s, start, len - 1)) return;
        strncpy(path + pathLen, s + start, len - start);
        path[pathLen + len - start] = '\0';
        res[resSize] = strdup(path);
        resSize++;
        return;
    }

    int len = strlen(s);
    for (int i = start; i < len && i - start <= 2; i++) {
        if (!isValid(s, start, i)) continue;
        int segLen = i - start + 1;
        strncpy(path + pathLen, s + start, segLen);
        path[pathLen + segLen] = '.';
        backtrack(s, i + 1, dots + 1, path, pathLen + segLen + 1);
    }
}

char** restoreIpAddresses(char* s, int* returnSize) {
    int len = strlen(s);
    res = (char**)malloc(1000 * sizeof(char*));
    resSize = 0;
    if (len < 4 || len > 12) {
        *returnSize = 0;
        return res;
    }
    char* path = (char*)malloc(len + 4);
    backtrack(s, 0, 0, path, 0);
    free(path);
    *returnSize = resSize;
    return res;
}
