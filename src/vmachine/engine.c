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

#include <vmachine.h>
#include <asm/mips32.h>
#include <utils.h>

R_instruction* r_inst;

#define SYNTATIC_ERROR "Syntatic Error"

#define opcode r_inst->instruction->opcode
#define encode r_inst->instruction->encode
#define funct r_inst->instruction->funct
#define rd r_inst->rd->code
#define rs r_inst->rs->code
#define rt r_inst->rt->code

/**
 * Check if these two parameters are equals.
 * @param tk1
 * @param tk2
 * */
static void match(char* tk1,char* tk2)
{

	if(!equals(tk1,tk2)) printf("%s",SYNTATIC_ERROR);
}

/*
* r_procefure_Format()
*/
static void r_procedure_Format()
{

}

/**
 * r_pocedure_Sum(); 
 */
static void r_procedure_Sum()
{
	if(equals(funct,INST_ADD_FUNCT_STR))
	{
		match(funct,INST_ADD_FUNCT_STR);
	}else
	{
		match(funct,INST_ADDU_FUNCT_STR);
	}
}

/**
 * r_pocedure_Sub(); 
 */
static void r_procedure_Sub()
{
	if(equals(funct,INST_SUB_FUNCT_STR))
	{
		match(funct,INST_SUB_FUNCT_STR);
	}else
	{
		match(funct,INST_SUBU_FUNCT_STR);
	}
}

/**
 * r_pocedure_Div(); 
 */
static void r_procedure_Div()
{
	if(equals(funct,INST_DIV_FUNCT_STR))
	{
		match(funct,INST_DIV_FUNCT_STR);
	}else
	{
		match(funct,INST_DIVU_FUNCT_STR);
	}
}

/**
 * r_pocedure_Mult();
 */
static void r_procedure_Mult()
{
	if(equals(funct,INST_MULT_FUNCT_STR))
	{
		match(funct,INST_MULT_FUNCT_STR);
	}else
	{
		match(funct,INST_MULTU_FUNCT_STR);
	}
}

/**
 * r_pocedure_Arithmetic();
 */
static void r_procedure_Arithmetic()
{
	if(equals(funct,INST_ADD_FUNCT_STR) || equals(funct,INST_ADDU_FUNCT_STR)){
		r_procedure_Sum();
	}else if(equals(funct,INST_SUB_FUNCT_STR) || equals(funct,INST_SUBU_FUNCT_STR)){
		r_procedure_Sub();
	}else if(equals(funct,INST_DIV_FUNCT_STR) || equals(funct,INST_DIVU_FUNCT_STR)){
		r_procedure_Div();
	}else if(equals(funct,INST_MULT_FUNCT_STR) || equals(funct,INST_MULTU_FUNCT_STR)){
		r_procedure_Mult();
	}
}

/**
 * r_procedure_UncJump();
 */
static void r_procedure_UncJump()
{
	match(funct,INST_JR_FUNCT_STR);
}

/**
 * r_procedure_Logic();
 */
static void r_procedure_Logic()
{
	if(equals(funct,INST_AND_FUNCT_STR))
	{
		match(funct,INST_AND_FUNCT_STR);
	}else if(equals(funct,INST_NOR_FUNCT_STR))
	{
		match(funct,INST_NOR_FUNCT_STR);
	}else if(equals(funct,INST_OR_FUNCT_STR))
	{
		match(funct,INST_OR_FUNCT_STR);
	}
}

/**
 * r_procedure_ConJump();
 */
static void r_procedure_ConJump()
{
	if(equals(funct,INST_SLT_FUNCT_STR))
	{
		match(funct,INST_SLT_FUNCT_STR);
	}else if(equals(funct,INST_SLTU_FUNCT_STR))
	{
		match(funct,INST_SLTU_FUNCT_STR);
	}
}

/**
 * r_procedure_Shift(); 
 */
static void r_procedure_Shift()
{
	if(equals(funct,INST_SLL_FUNCT_STR))
	{
		match(funct,INST_SLL_FUNCT_STR);
	}else if(equals(funct,INST_SRL_FUNCT_STR))
	{
		match(funct,INST_SRL_FUNCT_STR);
	}else if(equals(funct,INST_SRA_FUNCT_STR))
	{
		match(funct,INST_SRA_FUNCT_STR);
	}
}

/**
 * r_pocedure_Function(); 
 */
static void r_pocedure_Function()
{
	if(equals(funct,INST_ADD_FUNCT_STR) || equals(funct,INST_ADDU_FUNCT_STR) || equals(funct,INST_SUB_FUNCT_STR) || 
	   equals(funct,INST_SUBU_FUNCT_STR) || equals(funct,INST_DIV_FUNCT_STR) || equals(funct,INST_DIVU_FUNCT_STR) || 
	   equals(funct,INST_MULT_FUNCT_STR) || equals(funct,INST_MULTU_FUNCT_STR))
	{
		r_procedure_Arithmetic();
	}else if(equals(funct,INST_JR_FUNCT_STR))
	{
		r_procedure_UncJump();
	}else if(equals(funct,INST_AND_FUNCT_STR) || equals(funct,INST_NOR_FUNCT_STR) || equals(funct,INST_OR_FUNCT_STR))
	{
		r_procedure_Logic();
	}else if(equals(funct,INST_SLT_FUNCT_STR) || equals(funct,INST_SLTU_FUNCT_STR))
	{
		r_procedure_ConJump();
	}else if(equals(funct,INST_SLL_FUNCT_STR) || equals(funct,INST_SRL_FUNCT_STR) || equals(funct,INST_SRA_FUNCT_STR))
	{
		r_procedure_Shift();
	}
}

/*
 * First rule of grammar and Parsing tree
*/
static void r_procedure_S()
{
	match(opcode,R_OPCODE);
	r_procedure_Format();
	r_pocedure_Function();
}

/**
 * Translate binary code MIPS32 in RV32.
 * Opening process of translate
 */
static void r_translator()
{
	r_procedure_S(r_inst);
}

/**
 * Select type of instruction.
 * Extract each word of instruction 
 * and redirects for each function corresponding
 * @param inst[] MIPS instruction of 32 bits
 * */
void select(char instruction[])
{
		
	char* op = substring(instruction,0,5);

	if(equals(op,R_OPCODE))
	{
		r_inst = init();

		opcode = op;
		rs = substring(instruction,6,10);
		rt = substring(instruction,11,15);
		rd = substring(instruction,16,20);
		encode = substring(instruction,21,25);
		funct = substring(instruction,26,31);
		r_translator();
	}
}

/**
 * The engine_run() function translates a binary code into another.
 */
word_t engine_run(uint32_t instruction)
{
	char string_instruction[32];
	itoa2(instruction,string_instruction,10);
	select(string_instruction);

	return (instruction);
}
