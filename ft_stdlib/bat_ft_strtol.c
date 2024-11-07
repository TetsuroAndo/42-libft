/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:03:43 by teando            #+#    #+#             */
/*   Updated: 2024/10/23 16:23:40 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	const char		*s = nptr;
	int				sign;
	unsigned long	acc;
	unsigned long	cutoff;
	int				c;
	int				any;
	int				cutlim;
	int				digit;

	sign = 1;
	acc = 0;
	any = 0;
	c = (unsigned char)*s++;
	while (isspace(c))
		c = (unsigned char)*s++;
	if (c == '-')
	{
		sign = -1;
		c = *s++;
	}
	else if (c == '+')
		c = *s++;
	if (!base)
	{
		if (c == '0')
		{
			if (*s == 'x' || *s == 'X')
			{
				base = 16;
				c = s[1];
				s += 2;
			}
			else
			{
				base = 8;
				c = *s++;
			}
		}
		else
			base = 10;
	}
	else if (base == 16 && c == '0' && (*s == 'x' || *s == 'X'))
	{
		c = s[1];
		s += 2;
		if (c == '\0')
		{
			if (endptr)
				*endptr = (char *)nptr + 1;
			return (0);
		}
	}
	if (base < 2 || base > 36)
	{
		errno = EINVAL;
		if (endptr)
			*endptr = (char *)nptr;
		return (0);
	}
	if (sign == -1)
		cutoff = -(unsigned long)LONG_MIN;
	else
		cutoff = LONG_MAX;
	cutlim = cutoff % base;
	cutoff /= base;
	any = 0;
	while (1)
	{
		if (isdigit(c))
			digit = c - '0';
		else if (isalpha(c))
			digit = tolower(c) - 'a' + 10;
		else
			break ;
		if (digit >= base)
			break ;
		if (any < 0)
			continue ;
		if (acc > cutoff || (acc == cutoff && digit > cutlim))
		{
			any = -1;
			acc = cutoff;
			errno = ERANGE;
		}
		else
		{
			any = 1;
			acc = acc * base + digit;
		}
		c = (unsigned char)*s++;
	}
	if (endptr != NULL)
	{
		if (any)
			*endptr = (char *)(s - 1);
		else
			*endptr = (char *)nptr;
	}
	if (any == 0)
	{
		errno = EINVAL;
		return (0);
	}
	else if (any == -1)
	{
		if (sign == -1)
		{
			return (LONG_MIN);
		}
		else
		{
			return (LONG_MAX);
		}
	}
	return (long)(sign * acc);
}

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void	test_case(const char *str, int base, const char *description)
{
	char *end_std, *end_ft;
	long result_std, result_ft;
	int errno_std, errno_ft;
	errno = 0;
	result_std = strtol(str, &end_std, base);
	errno_std = errno;
	errno = 0;
	result_ft = ft_strtol(str, &end_ft, base);
	errno_ft = errno;
	printf("テストケース: %s\n", description);
	printf("入力: \"%s\", ベース: %d\n", str, base);
	printf("strtol結果: %ld, エンドポインタ: %td, errno: %d\n", result_std, end_std
		- str, errno_std);
	printf("ft_strtol結果: %ld, エンドポインタ: %td, errno: %d\n", result_ft, end_ft
		- str, errno_ft);
	printf("一致: %s\n\n", (result_std == result_ft && end_std == end_ft
			&& errno_std == errno_ft) ? "はい" : "いいえ");
}

int	main(void)
{
	test_case("123", 10, "通常の10進数");
	test_case("-456", 10, "負の10進数");
	test_case("0xFF", 0, "16進数（自動検出）");
	test_case("0755", 0, "8進数（自動検出）");
	test_case("  +42", 10, "先頭の空白と正の符号");
	test_case("9999999999", 10, "オーバーフロー");
	test_case("-9999999999", 10, "アンダーフロー");
	test_case("0x1G", 16, "無効な文字を含む16進数");
	test_case("", 10, "空の文字列");
	test_case("42abc", 10, "数字の後に文字がある場合");
	test_case("42", 37, "無効なベース");
	test_case("101010", 2, "2進数");
	test_case("zzzz", 36, "36進数（最大ベース）");
	// 基本的なエラーケース
	test_case("", 10, "空の文字列");
	test_case("   ", 10, "空白のみの文字列");
	test_case("abc", 10, "数字以外の文字列");
	// オーバーフローとアンダーフロー
	test_case("9223372036854775808", 10, "LONG_MAXを超える値");
	test_case("-9223372036854775809", 10, "LONG_MINを下回る値");
	test_case("0xFFFFFFFFFFFFFFFF", 0, "16進数でのオーバーフロー");
	// 無効なベース
	test_case("123", 1, "ベースが1（無効）");
	test_case("123", 37, "ベースが37（無効）");
	// ベースと不一致の文字
	test_case("12A", 10, "10進数で無効な文字");
	test_case("1G", 16, "16進数で無効な文字");
	// 特殊なケース
	test_case("-", 10, "符号のみの入力");
	test_case("+", 10, "符号のみの入力（正）");
	test_case("0x", 16, "16進数のプレフィックスのみ");
	// エンドポインタのテスト
	test_case("123abc", 10, "有効な数字の後に無効な文字");
	test_case("0xFF  ", 0, "16進数の後に空白");
	// 極端な値
	test_case("0x7FFFFFFFFFFFFFFF", 0, "LONG_MAXに等しい16進数");
	test_case("-0x8000000000000000", 0, "LONG_MINに等しい16進数");
	// additional testcase
	test_case("0x", 0, "0xのみ（自動ベース検出）");
	test_case("0x0", 0, "0x0（自動ベース検出）");
	test_case("0x0000000000000000", 0, "多数の0（16進数）");
	test_case("000000000000000000", 0, "多数の0（8進数）");
	test_case("0b1111111111111111", 0, "2進数プレフィックス（無効）");
	test_case("\t\n\r\f\v-42", 10, "様々な空白文字と負の数");
	test_case("+0x123ABC", 0, "正の符号付き16進数");
	test_case("-0x123ABC", 0, "負の符号付き16進数");
	test_case("  +  123", 10, "複数の空白と符号");
	test_case("0x7FFFFFFFFFFFFFFF0", 0, "LONG_MAXを超える16進数");
	test_case("-0x8000000000000001", 0, "LONG_MINを下回る16進数");
	test_case("1234567890123456789", 10, "非常に大きな10進数");
	test_case("ZZZZZZZZ", 36, "36進数の最大値");
	test_case("0x1234567890ABCDEF", 0, "長い16進数");
	test_case("0777777777777777777777", 0, "長い8進数");
	test_case("\x01\x02\x03\x04", 10, "制御文字を含む入力");
	test_case("9223372036854775807", 10, "LONG_MAX");
	test_case("-9223372036854775808", 10, "LONG_MIN");
	test_case("18446744073709551615", 10, "ULONG_MAX");
	test_case("0x7FFFFFFFFFFFFFFF", 16, "LONG_MAX（16進数）");
	test_case("-0x8000000000000000", 16, "LONG_MIN（16進数）");
	test_case("0x8000000000000000", 16, "LONG_MIN + 1（16進数）");
	test_case("123\0456", 10, "ヌル文字を含む入力");
	test_case("123\t456", 10, "タブ文字を含む入力");
	test_case("123\n456", 10, "改行文字を含む入力");
	// 基本的な8進数のテスト
	test_case("0123", 0, "通常の8進数（自動検出）");
	test_case("0123", 8, "通常の8進数（ベース指定）");
	test_case("-0567", 0, "負の8進数");
	// 0のみの入力
	test_case("0", 0, "0のみ（自動検出）");
	test_case("00000", 0, "複数の0（自動検出）");
	// 無効な8進数
	test_case("089", 0, "無効な8進数（9を含む）");
	test_case("0A", 0, "無効な8進数（Aを含む）");
	// 8進数の最大値と最小値
	test_case("0777777777777777777777", 0, "8進数でのLONG_MAX");
	test_case("-01000000000000000000000", 0, "8進数でのLONG_MIN");
	// オーバーフローとアンダーフロー
	test_case("01000000000000000000000", 0, "8進数でのオーバーフロー");
	test_case("-01000000000000000000001", 0, "8進数でのアンダーフロー");
	// 先頭の空白と符号
	test_case("  +0123", 0, "先頭の空白と正の符号（8進数）");
	test_case("\t-0456", 0, "タブと負の符号（8進数）");
	// 8進数の後に無効な文字
	test_case("0123abc", 0, "8進数の後に無効な文字");
	test_case("0567  ", 0, "8進数の後に空白");
	// 特殊なケース
	test_case("0", 8, "0（ベース8指定）");
	test_case("07", 8, "7（ベース8指定）");
	test_case("010", 8, "8（ベース8指定）");
	// 自動検出と明示的な指定の比較
	test_case("0123", 0, "自動検出での8進数");
	test_case("123", 8, "明示的に指定された8進数");
	// エッジケース
	test_case("0", 0, "0のみ（自動検出）");
	test_case("00", 0, "00（自動検出）");
	test_case("0+123", 0, "0の後に+（無効）");
	test_case("0-123", 0, "0の後に-（無効）");
	// 基本的なエッジケース
	test_case("", 10, "空の文字列");
	test_case("   ", 10, "空白のみの文字列");
	test_case("\t\n\r\f\v", 10, "様々な空白文字のみ");
	test_case("+", 10, "プラス記号のみ");
	test_case("-", 10, "マイナス記号のみ");
	test_case("+-42", 10, "プラスとマイナスの両方");
	test_case("  +  42", 10, "複数の空白と符号");
	// ベースに関するエッジケース
	test_case("42", 0, "ベース0（10進数）");
	test_case("042", 0, "ベース0（8進数）");
	test_case("0x42", 0, "ベース0（16進数）");
	test_case("42", 1, "無効なベース（1）");
	test_case("42", 37, "無効なベース（37）");
	test_case("42", INT_MAX, "非常に大きなベース");
	test_case("42", INT_MIN, "負のベース");
	// 16進数のエッジケース
	test_case("0x", 0, "0xのみ（自動ベース検出）");
	test_case("0X", 0, "0Xのみ（自動ベース検出）");
	test_case("0x0", 0, "0x0（自動ベース検出）");
	test_case("0xG", 0, "無効な16進数文字");
	test_case("0x123ABC", 10, "16進数形式だが10進数ベース指定");
	test_case("+0x123ABC", 0, "正の符号付き16進数");
	test_case("-0x123ABC", 0, "負の符号付き16進数");
	// 8進数のエッジケース
	test_case("08", 0, "無効な8進数（自動検出）");
	test_case("09", 0, "無効な8進数（自動検出）");
	test_case("0", 0, "0のみ（自動検出）");
	test_case("00", 0, "00（自動検出）");
	test_case("0+123", 0, "0の後に+（無効）");
	test_case("0-123", 0, "0の後に-（無効）");
	// 極端な値
	test_case("9223372036854775807", 10, "LONG_MAX");
	test_case("-9223372036854775808", 10, "LONG_MIN");
	test_case("9223372036854775808", 10, "LONG_MAX + 1");
	test_case("-9223372036854775809", 10, "LONG_MIN - 1");
	test_case("18446744073709551615", 10, "ULONG_MAX");
	test_case("0x7FFFFFFFFFFFFFFF", 0, "LONG_MAX（16進数）");
	test_case("-0x8000000000000000", 0, "LONG_MIN（16進数）");
	test_case("0x8000000000000000", 0, "LONG_MIN + 1（16進数）");
	test_case("0777777777777777777777", 0, "LONG_MAX（8進数）");
	test_case("-01000000000000000000000", 0, "LONG_MIN（8進数）");
	// 特殊な入力
	test_case("123abc", 10, "数字の後に文字");
	test_case("0xFF  ", 0, "16進数の後に空白");
	test_case("  0xFF", 0, "16進数の前に空白");
	test_case("0x7FFFFFFFFFFFFFFF0", 0, "LONG_MAXを超える16進数");
	test_case("-0x8000000000000001", 0, "LONG_MINを下回る16進数");
	test_case("1234567890123456789", 10, "非常に大きな10進数");
	test_case("ZZZZZZZZ", 36, "36進数の最大値");
	test_case("0x1234567890ABCDEF", 0, "長い16進数");
	test_case("0777777777777777777777", 0, "長い8進数");
	// 制御文字を含む入力
	test_case("\x01\x02\x03\x04", 10, "制御文字のみ");
	test_case("123\0456", 10, "ヌル文字を含む入力");
	test_case("123\t456", 10, "タブ文字を含む入力");
	test_case("123\n456", 10, "改行文字を含む入力");
	// その他のエッジケース
	test_case("2147483647", 10, "INT_MAX");
	test_case("-2147483648", 10, "INT_MIN");
	test_case("4294967295", 10, "UINT_MAX");
	test_case("0b1010", 0, "無効な2進数プレフィックス");
	test_case("0o123", 0, "無効な8進数プレフィックス");
	test_case("   +0x123ABC", 0, "空白、符号、16進数の組み合わせ");
	test_case("+++42", 10, "複数の正の符号");
	test_case("---42", 10, "複数の負の符号");
	return (0);
}
