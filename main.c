/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:53:05 by vlad              #+#    #+#             */
/*   Updated: 2017/04/03 09:37:17 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <locale.h>
#include <limits.h>
#include <string.h>


int		main(void)
{
    int		len_1 = 0;
    int		len_2 = 0;

//	len_1 = printf("Test origin     [%s]\n", "Hello world");
//	len_2 = printf("Test my_version [%s]\n", "Hello world");
//	printf("len origin      [%d]\n", len_1);
//	printf("len my_version  [%d]\n", len_2);
    wchar_t		*str;
    char		str_1;
    wchar_t		ch;
    wint_t		ch_1;

    ch = L'\x1000';

    str = L"Добро пожаловать!";
    str_1 = '4';

//    ch = L'';
    ch_1 = 126333;
    setlocale (LC_ALL, "");
    long int test;

//    test = -2147483649;
//    len_2 = ft_printf("{%C}\n", 0);
//    len_1 =    printf("{%C}\n", 0);
//
////    len_2 = ft_printf("{%t yyyy W ffdsgs}\n", 123);
////    len_1 =    printf("{%qq t t 44 .55 yyyy W gsdgsg}\n", 123);
//
//    printf("len origin      [%d]\n", len_1);
//    printf("len my_version  [%d]\n", len_2);

//    len_2 = ft_printf("% +.0d\n", -1995);
//    len_1 =    printf("% +.0d\n", -1995);
    // printf("----------[%x]--------\n", ch);

//    printf("\nINTN_64MIN [%lld]\n", INT64_MIN);
//    printf("INTN_64MAX [%lld]\n", INT64_MAX);
//    printf("INTN_32MIN [%d]\n", INT32_MIN);
//    printf("INTN_32MAX [%d]\n", INT32_MAX);
//    printf("INTN_16MIN [%d]\n", INT16_MIN);
//    printf("INTN_16MAX [%d]\n\n", INT16_MAX);
//
//    printf("UINT64_MAX [%llu]\n", UINT64_MAX);
//    printf("UINT32_MAX [%u]\n", UINT32_MAX);
//    printf("UINT16_MAX [%u]\n\n", UINT16_MAX);

//    printf("-----TEST 72-----\n");

    len_2 = ft_printf("%015.8S\n", L"我是一只猫。");
    len_1 =    printf("%015.8S\n", L"我是一只猫。");
    printf("len origin      [%d]\n", len_1);
    printf("len my_version  [%d]\n", len_2);

//
//
//    printf("len origin      [%d]\n", len_1);
//    printf("len my_version  [%d]\n", len_2);

    return (0);
}
