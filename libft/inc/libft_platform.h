/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_platform.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 04:57:21 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/12 16:36:35 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PLATFORM_H
# define LIBFT_PLATFORM_H

# define FT_ARCH_UNKNOWN 0
# define FT_ARCH_IA64 1
# define FT_ARCH_IA32 2
# define FT_ARCH_ARM 3
# define FT_ARCH_ARM64 4
# define FT_ARCH_AMD64 5

# define FT_ARCH_UNKNOWN_NAME "Unknown"
# define FT_ARCH_IA64_NAME "Intel itanium x64"
# define FT_ARCH_IA32_NAME "Intel itanium x32"
# define FT_ARCH_ARM_NAME "ARM"
# define FT_ARCH_ARM64_NAME "ARM x64"
# define FT_ARCH_AMD64_NAME "AMD64"

# if defined(__ia64__) || defined(_IA64) || defined(__IA64__)			\
	|| defined(__ia64) || defined(_M_IA64) || defined(__itanium__)
#  define FT_ARCH FT_ARCH_IA64
#  define FT_ARCH_NAME FT_ARCH_IA64_NAME
# elif defined(i386) || defined(__i386) || defined(__i386__)			\
	|| defined(__i486__) || defined(__i586__) || defined(__i686__)		\
	|| defined(__IA32__) || defined(_M_I86) || defined(_M_IX86)			\
	|| defined(__X86__) || defined(_X86_) || defined(__THW_INTEL__)		\
	|| defined(__I86__) || defined(__INTEL__)
#  define FT_ARCH FT_ARCH_IA32
#  define FT_ARCH_NAME FT_ARCH_IA32_NAME
# elif defined(__aarch64__)
#  define FT_ARCH FT_ARCH_ARM64
#  define FT_ARCH_NAME FT_ARCH_ARM64_NAME
# elif defined(__arm__) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) \
	|| defined(__TARGET_ARCH_THUMB) || defined(_ARM) || defined(_M_ARM) \
	|| defined(_M_ARMT)
#  define FT_ARCH FT_ARCH_ARM
#  define FT_ARCH_NAME FT_ARCH_ARM_NAME
# elif defined(__amd64__) || defined(__amd64) || defined(__x86_64__) \
	|| defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
#  define FT_ARCH FT_ARCH_AMD64
#  define FT_ARCH_NAME FT_ARCH_AMD64_NAME
# else
#  define FT_ARCH FT_ARCH_UNKNOWN
#  define FT_ARCH_NAME FT_ARCH_UNKNOWN_NAME
# endif

#endif
