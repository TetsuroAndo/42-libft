/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:36:20 by teando            #+#    #+#             */
/*   Updated: 2024/12/06 15:56:58 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

long	ft_strtol(const char *str, char **endptr, int base)
{
	return ((long)ft_strtoll(str, endptr, base));
}

// #include <ctype.h>
// #include <errno.h>
// #include <stddef.h>
// #include <string.h>
// #include <strings.h>

// int	ft_ctoi(int c, int radix)
// {
// 	c = tolower(c);
// 	if (isdigit(c))
// 		c -= '0';
// 	else if (isalpha(c))
// 		c -= 'a' - 10;
// 	else
// 		c = -1;
// 	if (radix <= c)
// 		c = -1;
// 	return (c);
// }

// char	*ft_strnchr(const char *s, int c, size_t n)
// {
// 	while (n--)
// 	{
// 		if (*s == (char)c)
// 			return ((char *)s);
// 		if (!*s++)
// 			break ;
// 	}
// 	return (NULL);
// }

// static int	pre(const char **nptr, int *base, int *neg);
// static int	internal(const char **nptr, int neg, int base,
// unsigned long *acc);

// long	ft_strtol(const char *nptr, char **endptr, int base)
// {
// 	int				neg;
// 	unsigned long	acc;
// 	const char		*save;

// 	save = nptr;
// 	if (pre(&nptr, &base, &neg))
// 	{
// 		errno = EINVAL;
// 		*endptr = NULL;
// 		return (0);
// 	}
// 	acc = 0;
// 	if (isdigit(*nptr))
// 	{
// 		if (internal(&nptr, neg, base, &acc))
// 		{
// 			errno = EINVAL;
// 			acc = (~0ul >> 1) ^ -neg;
// 		}
// 	}
// 	else
// 		nptr = save;
// 	if (endptr)
// 		*endptr = (char *)nptr;
// 	return (acc);
// }

// static int	pre(const char **nptr, int *base, int *neg)
// {
// 	*neg = 0;
// 	while (isspace(**nptr))
// 		(*nptr)++;
// 	if (ft_strnchr("+-", **nptr, 2))
// 		*neg = *(*nptr)++ == '-';
// 	if ((*base == 0 || *base == 16) && !strncasecmp("0x", *nptr, 2))
// 	{
// 		*base = 16;
// 		*nptr += 2;
// 	}
// 	if (!*base)
// 		*base = (int[]){10, 8}[**nptr == '0'];
// 	return (*base < 2 || 36 < *base);
// }

// static int	internal(const char **nptr, int neg, int base,
// unsigned long *acc)
// {
// 	int				overflow;
// 	unsigned long	cutoff;
// 	int				cutlim;
// 	int				n;

// 	overflow = 0;
// 	cutoff = (~0ul >> 1) ^ -neg;
// 	cutlim = cutoff % base;
// 	cutoff /= base;
// 	*acc = 0;
// 	while (**nptr)
// 	{
// 		n = ft_ctoi(**nptr, base);
// 		if (n < 0)
// 			break ;
// 		if (overflow || *acc > cutoff || (*acc == cutoff && n > cutlim))
// 			overflow = 1;
// 		else
// 			*acc = *acc * base + n;
// 		(*nptr)++;
// 	}
// 	if (!overflow && neg)
// 		*acc = -*acc;
// 	return (overflow);
// }

// #include <stdio.h>
// #include <stdlib.h>

// static int	test_case(const char *str, int base, const char *description)
// {
// 	char *end_std, *end_ft;
// 	long long result_std, result_ft;
// 	int errno_std, errno_ft;
// 	errno = 0;
// 	result_std = strtol(str, &end_std, base);
// 	errno_std = errno;
// 	errno = 0;
// 	result_ft = ft_strtol(str, &end_ft, base);
// 	errno_ft = errno;
// 	if (!(result_std == result_ft && end_std == end_ft
// 			&& errno_std == errno_ft))
// 	{
// 		printf("\nテストケース: %s\n", description);
// 		printf("入力: \"%s\", ベース: %d\n", str, base);
// 		printf("strtoll結果: %lld, エンドポインタ: %td, errno: %d\n", result_std, end_std
// 			- str, errno_std);
// 		if (result_std != result_ft)
// 			printf("result error: %lld\n", result_ft);
// 		if (end_std != end_ft)
// 			printf("endptr error: %td\n", end_ft - str);
// 		if (errno_std != errno_ft)
// 			printf("errno  error: %d\n", errno_ft);
// 		return (1);
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	int ret;

// 	ret = 0;
// 	ret += test_case("123", 10, "通常の10進数");
// 	ret += test_case("-456", 10, "負の10進数");
// 	ret += test_case("0xFF", 0, "16進数（自動検出）");
// 	ret += test_case("0755", 0, "8進数（自動検出）");
// 	ret += test_case("  +42", 10, "先頭の空白と正の符号");
// 	ret += test_case("9999999999", 10, "オーバーフロー");
// 	ret += test_case("-9999999999", 10, "アンダーフロー");
// 	ret += test_case("0x1G", 16, "無効な文字を含む16進数");
// 	ret += test_case("", 10, "空の文字列");
// 	ret += test_case("42abc", 10, "数字の後に文字がある場合");
// 	ret += test_case("101010", 2, "2進数");
// 	ret += test_case("zzzz", 36, "36進数（最大ベース）");
// 	// 基本的なエラーケース
// 	ret += test_case("", 10, "空の文字列");
// 	ret += test_case("   ", 10, "空白のみの文字列");
// 	ret += test_case("abc", 10, "数字以外の文字列");
// 	// オーバーフローとアンダーフロー
// 	ret += test_case("9223372036854775808", 10, "LONG_MAXを超える値");
// 	ret += test_case("-9223372036854775809", 10, "LONG_MINを下回る値");
// 	ret += test_case("0xFFFFFFFFFFFFFFFF", 0, "16進数でのオーバーフロー");
// 	// ベースと不一致の文字
// 	ret += test_case("12A", 10, "10進数で無効な文字");
// 	ret += test_case("1G", 16, "16進数で無効な文字");
// 	// 特殊なケース
// 	ret += test_case("-", 10, "符号のみの入力");
// 	ret += test_case("+", 10, "符号のみの入力（正）");
// 	ret += test_case("0x", 16, "16進数のプレフィックスのみ");
// 	// エンドポインタのテスト
// 	ret += test_case("123abc", 10, "有効な数字の後に無効な文字");
// 	ret += test_case("0xFF  ", 0, "16進数の後に空白");
// 	// 極端な値
// 	ret += test_case("0x7FFFFFFFFFFFFFFF", 0, "LONG_MAXに等しい16進数");
// 	ret += test_case("-0x8000000000000000", 0, "LONG_MINに等しい16進数");
// 	// additional testcase
// 	ret += test_case("0x", 0, "0xのみ（自動ベース検出）");
// 	ret += test_case("0x0", 0, "0x0（自動ベース検出）");
// 	ret += test_case("0x0000000000000000", 0, "多数の0（16進数）");
// 	ret += test_case("000000000000000000", 0, "多数の0（8進数）");
// 	ret += test_case("0b1111111111111111", 0, "2進数プレフィックス（無効）");
// 	ret += test_case("\t\n\r\f\v-42", 10, "様々な空白文字と負の数");
// 	ret += test_case("+0x123ABC", 0, "正の符号付き16進数");
// 	ret += test_case("-0x123ABC", 0, "負の符号付き16進数");
// 	ret += test_case("  +  123", 10, "複数の空白と符号");
// 	ret += test_case("0x7FFFFFFFFFFFFFFF0", 0, "LONG_MAXを超える16進数");
// 	ret += test_case("-0x8000000000000001", 0, "LONG_MINを下回る16進数");
// 	ret += test_case("1234567890123456789", 10, "非常に大きな10進数");
// 	ret += test_case("ZZZZZZZZ", 36, "36進数の最大値");
// 	ret += test_case("0x1234567890ABCDEF", 0, "長い16進数");
// 	ret += test_case("0777777777777777777777", 0, "長い8進数");
// 	ret += test_case("\x01\x02\x03\x04", 10, "制御文字を含む入力");
// 	ret += test_case("9223372036854775807", 10, "LONG_MAX");
// 	ret += test_case("-9223372036854775808", 10, "LONG_MIN");
// 	ret += test_case("18446744073709551615", 10, "ULONG_MAX");
// 	ret += test_case("0x7FFFFFFFFFFFFFFF", 16, "LONG_MAX（16進数）");
// 	ret += test_case("-0x8000000000000000", 16, "LONG_MIN（16進数）");
// 	ret += test_case("0x8000000000000000", 16, "LONG_MIN + 1（16進数）");
// 	ret += test_case("123\0456", 10, "ヌル文字を含む入力");
// 	ret += test_case("123\t456", 10, "タブ文字を含む入力");
// 	ret += test_case("123\n456", 10, "改行文字を含む入力");
// 	// 基本的な8進数のテスト
// 	ret += test_case("0123", 0, "通常の8進数（自動検出）");
// 	ret += test_case("0123", 8, "通常の8進数（ベース指定）");
// 	ret += test_case("-0567", 0, "負の8進数");
// 	// 0のみの入力
// 	ret += test_case("0", 0, "0のみ（自動検出）");
// 	ret += test_case("00000", 0, "複数の0（自動検出）");
// 	// 無効な8進数
// 	ret += test_case("089", 0, "無効な8進数（9を含む）");
// 	ret += test_case("0A", 0, "無効な8進数（Aを含む）");
// 	// 8進数の最大値と最小値
// 	ret += test_case("0777777777777777777777", 0, "8進数でのLONG_MAX");
// 	ret += test_case("-01000000000000000000000", 0, "8進数でのLONG_MIN");
// 	// オーバーフローとアンダーフロー
// 	ret += test_case("01000000000000000000000", 0, "8進数でのオーバーフロー");
// 	ret += test_case("-01000000000000000000001", 0, "8進数でのアンダーフロー");
// 	// 先頭の空白と符号
// 	ret += test_case("  +0123", 0, "先頭の空白と正の符号（8進数）");
// 	ret += test_case("\t-0456", 0, "タブと負の符号（8進数）");
// 	// 8進数の後に無効な文字
// 	ret += test_case("0123abc", 0, "8進数の後に無効な文字");
// 	ret += test_case("0567  ", 0, "8進数の後に空白");
// 	// 特殊なケース
// 	ret += test_case("0", 8, "0（ベース8指定）");
// 	ret += test_case("07", 8, "7（ベース8指定）");
// 	ret += test_case("010", 8, "8（ベース8指定）");
// 	// 自動検出と明示的な指定の比較
// 	ret += test_case("0123", 0, "自動検出での8進数");
// 	ret += test_case("123", 8, "明示的に指定された8進数");
// 	// エッジケース
// 	ret += test_case("0", 0, "0のみ（自動検出）");
// 	ret += test_case("00", 0, "00（自動検出）");
// 	ret += test_case("0+123", 0, "0の後に+（無効）");
// 	ret += test_case("0-123", 0, "0の後に-（無効）");
// 	// 基本的なエッジケース
// 	ret += test_case("", 10, "空の文字列");
// 	ret += test_case("   ", 10, "空白のみの文字列");
// 	ret += test_case("\t\n\r\f\v", 10, "様々な空白文字のみ");
// 	ret += test_case("+", 10, "プラス記号のみ");
// 	ret += test_case("-", 10, "マイナス記号のみ");
// 	ret += test_case("+-42", 10, "プラスとマイナスの両方");
// 	ret += test_case("  +  42", 10, "複数の空白と符号");
// 	// ベースに関するエッジケース
// 	ret += test_case("42", 0, "ベース0（10進数）");
// 	ret += test_case("042", 0, "ベース0（8進数）");
// 	ret += test_case("0x42", 0, "ベース0（16進数）");
// 	// 16進数のエッジケース
// 	ret += test_case("0x", 0, "0xのみ（自動ベース検出）");
// 	ret += test_case("0X", 0, "0Xのみ（自動ベース検出）");
// 	ret += test_case("0x0", 0, "0x0（自動ベース検出）");
// 	ret += test_case("0xG", 0, "無効な16進数文字");
// 	ret += test_case("0x123ABC", 10, "16進数形式だが10進数ベース指定");
// 	ret += test_case("+0x123ABC", 0, "正の符号付き16進数");
// 	ret += test_case("-0x123ABC", 0, "負の符号付き16進数");
// 	// 8進数のエッジケース
// 	ret += test_case("08", 0, "無効な8進数（自動検出）");
// 	ret += test_case("09", 0, "無効な8進数（自動検出）");
// 	ret += test_case("0", 0, "0のみ（自動検出）");
// 	ret += test_case("00", 0, "00（自動検出）");
// 	ret += test_case("0+123", 0, "0の後に+（無効）");
// 	ret += test_case("0-123", 0, "0の後に-（無効）");
// 	// 極端な値
// 	ret += test_case("9223372036854775807", 10, "LONG_MAX");
// 	ret += test_case("-9223372036854775808", 10, "LONG_MIN");
// 	ret += test_case("9223372036854775808", 10, "LONG_MAX + 1");
// 	ret += test_case("-9223372036854775809", 10, "LONG_MIN - 1");
// 	ret += test_case("18446744073709551615", 10, "ULONG_MAX");
// 	ret += test_case("0x7FFFFFFFFFFFFFFF", 0, "LONG_MAX（16進数）");
// 	ret += test_case("-0x8000000000000000", 0, "LONG_MIN（16進数）");
// 	ret += test_case("0x8000000000000000", 0, "LONG_MIN + 1（16進数）");
// 	ret += test_case("0777777777777777777777", 0, "LONG_MAX（8進数）");
// 	ret += test_case("-01000000000000000000000", 0, "LONG_MIN（8進数）");
// 	// 特殊な入力
// 	ret += test_case("123abc", 10, "数字の後に文字");
// 	ret += test_case("0xFF  ", 0, "16進数の後に空白");
// 	ret += test_case("  0xFF", 0, "16進数の前に空白");
// 	ret += test_case("0x7FFFFFFFFFFFFFFF0", 0, "LONG_MAXを超える16進数");
// 	ret += test_case("-0x8000000000000001", 0, "LONG_MINを下回る16進数");
// 	ret += test_case("1234567890123456789", 10, "非常に大きな10進数");
// 	ret += test_case("ZZZZZZZZ", 36, "36進数の最大値");
// 	ret += test_case("0x1234567890ABCDEF", 0, "長い16進数");
// 	ret += test_case("0777777777777777777777", 0, "長い8進数");
// 	// 制御文字を含む入力
// 	ret += test_case("\x01\x02\x03\x04", 10, "制御文字のみ");
// 	ret += test_case("123\0456", 10, "ヌル文字を含む入力");
// 	ret += test_case("123\t456", 10, "タブ文字を含む入力");
// 	ret += test_case("123\n456", 10, "改行文字を含む入力");
// 	// その他のエッジケース
// 	ret += test_case("2147483647", 10, "INT_MAX");
// 	ret += test_case("-2147483648", 10, "INT_MIN");
// 	ret += test_case("4294967295", 10, "UINT_MAX");
// 	ret += test_case("0b1010", 0, "無効な2進数プレフィックス");
// 	ret += test_case("0o123", 0, "無効な8進数プレフィックス");
// 	ret += test_case("   +0x123ABC", 0, "空白、符号、16進数の組み合わせ");
// 	ret += test_case("+++42", 10, "複数の正の符号");
// 	ret += test_case("---42", 10, "複数の負の符号");
// 	/*.+  これやるとstrtoll本家がバグる  +.*/
// 	// 無効なベース
// 	// ret += test_case("42", 37, "無効なベース");
// 	// ret += test_case("123", 1, "ベースが1（無効）");
// 	// ret += test_case("123", 37, "ベースが37（無効）");
// 	// ret += test_case("42", 1, "無効なベース（1）");
// 	// ret += test_case("42", 37, "無効なベース（37）");
// 	// ret += test_case("42", INT_MAX, "非常に大きなベース");
// 	// ret += test_case("42", INT_MIN, "負のベース");
// 	printf("\n総Error数: %d\n", ret);
// 	return (0);
// }