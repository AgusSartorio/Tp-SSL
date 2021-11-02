%{
    #include "integrador.tab.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
%}

%option yylineno
%option noyywrap


CAR_SIMPLES (","|"?"|":"|"("|")"|"["|"]"|"="|"{"|"}"|";"|"*"|"&"|"+"|"-"|"~"|"!")
STRUCT ("struct")

OP_DE_ASIGNACION ("*="|"/="|"%="|"+="|"*=") 
OP_O_LOGICO "||"
OP_Y_LOGICO "&&"
OP_O_INCLUSIVO "|"
OP_IGUALDAD ("==")
OP_DESIGUALDAD ("!=")
OP_RELACIONAL ("<"|">"|"<="|">=")
OP_DIVISION ("/")
OP_PORCENTAJE ("%")
OP_INCREMENTO ("++")
OP_DECREMENTO ("--")
SIZEOF "sizeof"

TIPO_DATO ("void"|"char"|"short"|"int"|"long"|"float"|"double"|"signed"|"unsigned")

DECIMAL_CON_CERO [0-9]
DECIMAL_SIN_CERO [1-9]
OCTAL [0-7] 
HEXADECIMAL [a-fA-F0-9] 
CONSTANTE_REAL (({DECIMAL_CON_CERO}+)"."{DECIMAL_CON_CERO}*)
/* Revisar por secuencia de escapes para el codigo SECUENCIA_ESCAPE_SIMPLE (a|b|f|n|r|t|v|\'|\"|\?|\\)

%%

"\n" { return '\n'; }
" "|"\t"
 
{CAR_SIMPLES} { return yytext[0]; }
{STRUCT}      {return STRUCT}
"if"          { return IF;        }
"else"        { return ELSE;      }
"switch"      { return SWITCH;    }
"while"       { return WHILE;     }
"do"          { return DO;        }
"for"         { return FOR;       }
"case"        { return CASE;      }
"default"     { return DEFAULT;   }
"continue"    { return CONTINUE;  }
"break"       { return BREAK;     }
"return"      { return RETURN;    }


{TIPO_DATO}                     { yylval.cadena = strdup(yytext); return TIPO_DATO; }
                        
{OP_ASIGNACION}           { return OP_ASIGNACION;           }       
{OP_O_LOGICO}             { return OP_O_LOGICO;             }         
{OP_Y_LOGICO}             { return OP_Y_LOGICO;             }         
{OP_O_INCLUSIVO}          { return OP_O_INCLUSIVO;          }      
{OP_IGUALDAD}             { return OP_IGUALDAD;             }         
{OP_DESIGUALDAD}          { return OP_DESIGUALDAD;          }         
{OP_RELACIONAL}           { return OP_RELACIONAL;           }       
{OP_DIVISION}             { return OP_DIVISION;             }       
{OP_PORCENTAJE}           { return OP_PORCENTAJE;           }       
{OP_INCREMENTO}           { return OP_INCREMENTO;           }                  
{OP_DECREMENTO}           { return OP_DECREMENTO;           }                  
{SIZEOF}                  { return SIZEOF;               }           

[a-zA-Z_][a-zA-Z0-9_]*  { yylval.cadena = strdup(yytext); return IDENTIFICADOR;  }

\"(([^\"]|\\\")*[^\\])?\"                                                                                   { yylval.cadena =   strdup(yytext);             return CONSTANTE_CADENA;        }
{DECIMAL_SIN_CERO}{DECIMAL_CON_CERO}*                                                                       { yylval.entero =   atoi(yytext);               return CONSTANTE_DECIMAL;       }
0{OCTAL}*                                                                                                   { yylval.entero =   atoi(yytext);               return CONSTANTE_OCTAL;         }
0[xX]{HEXADECIMAL}+                                                                                         { yylval.entero =   atoi(yytext);               return CONSTANTE_HEXADECIMAL;   }
\'([^\\\']|\\{SECUENCIA_ESCAPE_SIMPLE}|\\{OCTAL}{1,3}|\\x{HEXADECIMAL}{1,2})\'                              { yylval.entero =   atoi(yytext);               return CONSTANTE_CARACTER;      }
({CONSTANTE_REAL})                                                                                          { yylval.real =     strtol(yytext, NULL, 0);    return CONSTANTE_REAL;          }

. {printf("\nEl caracter %c no fue reconocido.", yytext[0]);}

%%