#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <assert.h>

void test_strtol(void)
{
    char *endptr;
    long int result;

    // 基本的な変換テスト
    // result = strtol("+", &endptr, 10);
    // printf("result: %ld\n %s\n", result, endptr);
    // assert(result == 123 && *endptr == '\0');

    // 負の数のテスト
    result = strtol("", &endptr, 10);
    printf("result: %ld\n %s\n", result, endptr);
    if (!*endptr || result < INT_MIN || INT_MAX < result)
        printf("result: %ld\n %s\n", result, endptr);
    assert(result == -456 && *endptr == '\0');

    // 異なる基数のテスト
    result = strtol("1010", &endptr, 2);
    assert(result == 10 && *endptr == '\0');

    result = strtol("FF", &endptr, 16);
    assert(result == 255 && *endptr == '\0');

    // 先頭の空白文字を無視するテスト
    result = strtol("  789", &endptr, 10);
    assert(result == 789 && *endptr == '\0');

    // 無効な入力のテスト
    // result = strtol("abc", &endptr, 10);
    // assert(result == 0 && endptr == "abc");

    // オーバーフローのテスト
    errno = 0;
    result = strtol("9999999999999999999", &endptr, 10);
    assert(result == LONG_MAX && errno == ERANGE);

    // アンダーフローのテスト
    errno = 0;
    result = strtol("-9999999999999999999", &endptr, 10);
    assert(result == LONG_MIN && errno == ERANGE);

    printf("すべてのテストが成功しました。\n");
}

int main(void)
{
    test_strtol();
    return 0;
}