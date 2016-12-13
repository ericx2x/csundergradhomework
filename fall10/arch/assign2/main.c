#include <stdio.h>


int main(int argc, char * argv[])
{

  union float_32{
    float   floating_value_in_32_bits;
    int     floating_value_as_int;
    struct  sign_exp_mantissa{
      unsigned  mantissa:23;
      unsigned  exponent:8;
      unsigned      sign:1;
    } f_bits;
    struct single_bits{
      unsigned  b0 :1;
      unsigned  b1 :1;
      unsigned  b2 :1;
      unsigned  b3 :1;
      unsigned  b4 :1;
      unsigned  b5 :1;
      unsigned  b6 :1;
      unsigned  b7 :1;
      unsigned  b8 :1;
      unsigned  b9 :1;
      unsigned  b10:1;
      unsigned  b11:1;
      unsigned  b12:1;
      unsigned  b13:1;
      unsigned  b14:1;
      unsigned  b15:1;
      unsigned  b16:1;
      unsigned  b17:1;
      unsigned  b18:1;
      unsigned  b19:1;
      unsigned  b20:1;
      unsigned  b21:1;
      unsigned  b22:1;
      unsigned  b23:1;
      unsigned  b24:1;
      unsigned  b25:1;
      unsigned  b26:1;
      unsigned  b27:1;
      unsigned  b28:1;
      unsigned  b29:1;
      unsigned  b30:1;
      unsigned  b31:1;
    }bit;
  } float_32;

  union float_32 x, y, result ;

  char bit_string1[43];
  char bit_string2[43];
  char bit_result[43] ;

  float sum ;
  int i, j, k, shifter ;
  int exponentA, exponentB, exponent_result;
  int msA, msB, mantisresult;

    for( i = 0 ; i < 42; i++){
    bit_string1[i] = ' ';
    bit_string2[i] = ' ';
    bit_result[i]  = ' ';
    }

  bit_string1[42] = '\0';
  bit_string2[42] = '\0';
  bit_result[42]  = '\0';

  printf("Please enter 2 floating point numbers each with:\n");
  printf("    -no more than 6 significant digits\n");
  printf("    -a value between  +  10**37 and 10**-37\n");

  printf("Enter Float 1: ");
  scanf("%g", &x.floating_value_in_32_bits);

  exponentA = x.f_bits.exponent;
  msA = x.f_bits.mantissa;

  bit_string1[0] = x.bit.b31?'1':'0';

  bit_string1[2] = x.bit.b30?'1':'0';
  bit_string1[3] = x.bit.b29?'1':'0';
  bit_string1[4] = x.bit.b28?'1':'0';
  bit_string1[5] = x.bit.b27?'1':'0';

  bit_string1[7] = x.bit.b26?'1':'0';
  bit_string1[8] = x.bit.b25?'1':'0';
  bit_string1[9] = x.bit.b24?'1':'0';
  bit_string1[10] = x.bit.b23?'1':'0';

  bit_string1[12] = x.bit.b22?'1':'0';
  bit_string1[13] = x.bit.b21?'1':'0';
  bit_string1[14] = x.bit.b20?'1':'0';

  bit_string1[16] = x.bit.b19?'1':'0';
  bit_string1[17] = x.bit.b18?'1':'0';
  bit_string1[18] = x.bit.b17?'1':'0';
  bit_string1[19] = x.bit.b16?'1':'0';

  bit_string1[21] = x.bit.b15?'1':'0';
  bit_string1[22] = x.bit.b14?'1':'0';
  bit_string1[23] = x.bit.b13?'1':'0';
  bit_string1[24] = x.bit.b12?'1':'0';

  bit_string1[26] = x.bit.b11?'1':'0';
  bit_string1[27] = x.bit.b10?'1':'0';
  bit_string1[28] = x.bit.b9?'1':'0';
  bit_string1[29] = x.bit.b8?'1':'0';

  bit_string1[31] = x.bit.b7?'1':'0';
  bit_string1[32] = x.bit.b6?'1':'0';
  bit_string1[33] = x.bit.b5?'1':'0';
  bit_string1[34] = x.bit.b4?'1':'0';

  bit_string1[36] = x.bit.b3?'1':'0';
  bit_string1[37] = x.bit.b2?'1':'0';
  bit_string1[38] = x.bit.b1?'1':'0';
  bit_string1[39] = x.bit.b0?'1':'0';


  printf("Enter Float 2: ");
  scanf("%g", &y.floating_value_in_32_bits);

  exponentB = y.f_bits.exponent;
  msB = y.f_bits.mantissa;

  bit_string2[0] = y.bit.b31?'1':'0';

  bit_string2[2] = y.bit.b30?'1':'0';
  bit_string2[3] = y.bit.b29?'1':'0';
  bit_string2[4] = y.bit.b28?'1':'0';
  bit_string2[5] = y.bit.b27?'1':'0';
  
  bit_string2[7] = y.bit.b26?'1':'0';
  bit_string2[8] = y.bit.b25?'1':'0';
  bit_string2[9] = y.bit.b24?'1':'0';
  bit_string2[10] = y.bit.b23?'1':'0';

  bit_string2[12] = y.bit.b22?'1':'0';
  bit_string2[13] = y.bit.b21?'1':'0';
  bit_string2[14] = y.bit.b20?'1':'0';

  bit_string2[16] = y.bit.b19?'1':'0';
  bit_string2[17] = y.bit.b18?'1':'0';
  bit_string2[18] = y.bit.b17?'1':'0';
  bit_string2[19] = y.bit.b16?'1':'0';

  bit_string2[21] = y.bit.b15?'1':'0';
  bit_string2[22] = y.bit.b14?'1':'0';
  bit_string2[23] = y.bit.b13?'1':'0';
  bit_string2[24] = y.bit.b12?'1':'0';

  bit_string2[26] = y.bit.b11?'1':'0';
  bit_string2[27] = y.bit.b10?'1':'0';
  bit_string2[28] = y.bit.b9?'1':'0';
  bit_string2[29] = y.bit.b8?'1':'0';

  bit_string2[31] = y.bit.b7?'1':'0';
  bit_string2[32] = y.bit.b6?'1':'0';
  bit_string2[33] = y.bit.b5?'1':'0';
  bit_string2[34] = y.bit.b4?'1':'0';

  bit_string2[36] = y.bit.b3?'1':'0';
  bit_string2[37] = y.bit.b2?'1':'0';
  bit_string2[38] = y.bit.b1?'1':'0';
  bit_string2[39] = y.bit.b0?'1':'0';

  sum = x.floating_value_in_32_bits + y.floating_value_in_32_bits ;

  msA |= 1 << 23 ;
  msB |= 1 << 23 ;

  shifter = exponentA - exponentB ;

  if (shifter < 0) {
    shifter *= -1 ;
    exponent_result = exponentB;
    msA >>= shifter;
  }

  else {
    exponent_result = exponentA;
    msB >>= shifter;
  }

  mantisresult = msA + msB;

  if ( mantisresult & (1<<24) ){
    mantisresult >>= 1 ;
    exponent_result++ ;
  }

  exponent_result &= 83388607 ;

  result.f_bits.sign = 0 ;
  result.f_bits.exponent = exponent_result ;
  result.f_bits.mantissa = mantisresult ;


  bit_result[0] = result.bit.b31?'1':'0';

  bit_result[2] = result.bit.b30?'1':'0';
  bit_result[3] = result.bit.b29?'1':'0';
  bit_result[4] = result.bit.b28?'1':'0';
  bit_result[5] = result.bit.b27?'1':'0';

  bit_result[7] = result.bit.b26?'1':'0';
  bit_result[8] = result.bit.b25?'1':'0';
  bit_result[9] = result.bit.b24?'1':'0';
  bit_result[10] = result.bit.b23?'1':'0';

  bit_result[12] = result.bit.b22?'1':'0';
  bit_result[13] = result.bit.b21?'1':'0';
  bit_result[14] = result.bit.b20?'1':'0';

  bit_result[16] = result.bit.b19?'1':'0';
  bit_result[17] = result.bit.b18?'1':'0';
  bit_result[18] = result.bit.b17?'1':'0';
  bit_result[19] = result.bit.b16?'1':'0';

  bit_result[21] = result.bit.b15?'1':'0';
  bit_result[22] = result.bit.b14?'1':'0';
  bit_result[23] = result.bit.b13?'1':'0';
  bit_result[24] = result.bit.b12?'1':'0';

  bit_result[26] = result.bit.b11?'1':'0';
  bit_result[27] = result.bit.b10?'1':'0';
  bit_result[28] = result.bit.b9?'1':'0';
  bit_result[29] = result.bit.b8?'1':'0';

  bit_result[31] = result.bit.b7?'1':'0';
  bit_result[32] = result.bit.b6?'1':'0';
  bit_result[33] = result.bit.b5?'1':'0';
  bit_result[34] = result.bit.b4?'1':'0';

  bit_result[36] = result.bit.b3?'1':'0';
  bit_result[37] = result.bit.b2?'1':'0';
  bit_result[38] = result.bit.b1?'1':'0';
  bit_result[39] = result.bit.b0?'1':'0';


  printf("Original pattern of Float 1: %s\n", bit_string1) ;
  printf("Original pattern of Float 2: %s\n", bit_string2) ;
  printf("Bit pattern of result      : %s\n", bit_result) ;

  printf("\nEMULATED FLOATING RESULT FROM PRINTF ==>> %g\n", result.floating_value_in_32_bits);
  printf("HARDWARE FLOATING RESULT FROM PRINTF ==>> %g\n\n", sum);

return 0;

}



