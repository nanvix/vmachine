/*
 * MIT License
 *
 * Copyright(c) 2011-2020 The Maintainers of Nanvix
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _ASSEMBLER_MIPS_32_TEST_H
#define _ASSEMBLER_MIPS_32_TEST_H

	struct test 
	{
		void (*test_fn)(void);
		const char *name;
	};

	EXTERN const char *HLINE;

	EXTERN void test_parse_Uint32(void);

	EXTERN test_encode_r_instruction(void);
	
	EXTERN test_encode_mult(void);

	EXTERN test_encode_div(void);

	EXTERN test_encode_sll(void);

	EXTERN test_encode_srl(void);

	EXTERN test_encode_jr(void);

	EXTERN test_encode_i_instruction(void);

	EXTERN test_encode_lw(void);

	EXTERN test_encode_sw(void);

	EXTERN test_encode_j(void);

#endif
