%{
    #include <ctype.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "tablaDeSimbolos.c"

    int yylex();
    int yywrap(){ return(1); }
    void yyerror (char const *s) {}

    FILE* yyin;

    extern int yylineno;

    char* tipoAuxiliar  = "";
    char* tipoAuxiliar1 = "";
    char* tipoAuxiliar2 = "";
    char* identificadorAuxiliar = ""; 
    int validacionBinaria = 0;

%}
/*UNION*/
%union {
    char* cadena;
    int entero;
    float real;
}

/*--------------TOKENS--------------------*/
%token <cadena> IDENTIFICADOR

%token <cadena> TIPO_DATO 

%token <cadena> SIZEOF  

%token <entero> CTE_DECIMAL                   
%token <entero> CTE_OCTAL                         
%token <entero> CTE_HEXADECIMAL               
%token <real>   CTE_REAL  

%token <cadena> OP_O_LOGICO                   
%token <cadena> OP_Y_LOGICO                  
%token <cadena> OP_O_INCLUSIVO  

%token <cadena> OP_ASIGNACION                
              
%token <cadena> OP_IGUALDAD
%token <cadena> OP_DESIGUALDAD                  
%token <cadena> OP_RELACIONAL  

%token <cadena> OP_DIVISION 
%token <cadena> OP_PORCENTAJE 

%token <cadena> OP_INCREMENTO                
%token <cadena> OP_DECREMENTO 

%token <cadena> DO               
%token <cadena> WHILE

%token <cadena> IF
%token <cadena> ELSE

%token <cadena> SWITCH
%token <cadena> CASE
%token <cadena> DEFAULT
%token <cadena> BREAK
%token <cadena> CONTINUE

%token <cadena> FOR

%token <cadena> RETURN

%token <cadena> CTE_CADENA                                      
%token <entero> CTE_CARACTER

/*--------------TYPES--------------------*/
%type <cadena> expresionSufijo
%type <cadena> declaracionVariable
%type <cadena> puntero
%type <cadena> declarador
%type <cadena> unaDeclaracion
%type <cadena> expresionPrimaria
%type <cadena> constante



// adentro del unaDeclaracion%type <cadena> declaradorDirecto


%% /* A continuacion las reglas gramaticales y las acciones */

input:    /* vacio */
        | input line
;

line: declaracion '\n'            
    | sentencia '\n'        
    | error '\n' { printf("\nError sintactico en la linea %i: %s", yylineno, $<cadena>1);}
    | error ';' { printf("\nError sintactico en la linea %i: %s", yylineno, $<cadena>1); }
    ;

/* -------------------------------------------------- EXPRESIONES -------------------------------------------------- */

expresion: expresionAsignacion 
    | expresion ',' expresionAsignacion
;

expresionAsignacion: expresionCondicional                       
    | expresionUnaria '=' expresionAsignacion 
    | expresionUnaria OP_ASIGNACION expresionAsignacion 
;

expresionCondicional: expresionOLogico 
    | expresionOLogico '?' expresion ':' expresionCondicional 
;

expresionOLogico: expresionYLogico 
    | expresionOLogico OP_O_LOGICO expresionYLogico 
;

expresionYLogico: expresionOInclusivo 
    | expresionYLogico OP_Y_LOGICO expresionOInclusivo 
;

expresionOInclusivo: expresionY
    | expresionOInclusivo OP_O_INCLUSIVO expresionY  
;

expresionY: expresionIgualdad 
    | expresionY '&' expresionIgualdad 
;

expresionIgualdad: expresionRelacional 
    | expresionIgualdad OP_IGUALDAD expresionRelacional 
    | expresionIgualdad OP_DESIGUALDAD expresionRelacional
;

expresionRelacional: expresionAditiva 
    | expresionRelacional OP_RELACIONAL expresionAditiva 
;

expresionAditiva: expresionMultiplicativa 
    | expresionAditiva '+' expresionMultiplicativa  { numeroDeLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0;}
    | expresionAditiva '-' expresionMultiplicativa  { numeroDeLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0;}
    ;

expresionMultiplicativa: expresionConversion 
    | expresionMultiplicativa '*' expresionConversion                       { numeroDeLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0;}
    | expresionMultiplicativa OP_DIVISION expresionConversion               { numeroDeLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0;}
    | expresionMultiplicativa OP_PORCENTAJE expresionConversion             { numeroDeLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0;}
    ;

expresionConversion: expresionUnaria 
    | '(' TIPO_DATO ')' expresionConversion 
    ;

expresionUnaria: expresionSufijo            
    | OP_INCREMENTO expresionUnaria
    | OP_DECREMENTO expresionUnaria
    | operadorUnario expresionConversion 
    | SIZEOF expresionUnaria    
    | SIZEOF '(' TIPO_DATO ')'    
    ;

operadorUnario:'&'
    |'*'
    |'+'
    |'-'
    |'~'
    |'!'
    ;

expresionSufijo: expresionPrimaria 
    | expresionSufijo '[' expresion ']'           
    | expresionSufijo '(' listaArgumentos_ ')'       { numeroDeLinea = yylineno; agregarSimbolo(&tablaAuxiliar, $<cadena>1, "-", 1);  tablaAuxiliar->tipoDeParametros = tablaDeParametros; controlDeInvocacion(tablaAuxiliar);  tablaDeParametros = NULL; tablaAuxiliar = NULL; }
    | expresionSufijo OP_INCREMENTO                       
    ;

listaArgumentos: expresionAsignacion            { agregarParametro(&tablaDeParametros, $<cadena>1); } 
    | listaArgumentos ',' expresionAsignacion   { agregarParametro(&tablaDeParametros, $<cadena>3); } 
    ;

expresionPrimaria: IDENTIFICADOR    { tablaAuxiliar = devolverIdentificador($<cadena>1); if(tablaAuxiliar != NULL) (validacionBinaria == 0) ? (tipoAuxiliar1 = tablaAuxiliar->tipo) : (tipoAuxiliar2 = tablaAuxiliar->tipo) ; validacionBinaria = 1; }  
    | constante                     
    | CTE_CADENA              {(validacionBinaria == 0) ? (tipoAuxiliar1 = "char*") : (tipoAuxiliar2 = "char*"); validacionBinaria = 1; }
    | '(' expresion ')'
    ;

expresionConstante: expresionCondicional /*ver lo del case*/
    ; 

constante: CTE_DECIMAL   { (validacionBinaria == 0) ? (tipoAuxiliar1 = "int"  ) : (tipoAuxiliar2 = "int"  ); validacionBinaria = 1; }      
    | CTE_OCTAL          { (validacionBinaria == 0) ? (tipoAuxiliar1 = "int"  ) : (tipoAuxiliar2 = "int"  ); validacionBinaria = 1; }
    | CTE_HEXADECIMAL    { (validacionBinaria == 0) ? (tipoAuxiliar1 = "int"  ) : (tipoAuxiliar2 = "int"  ); validacionBinaria = 1; }
    | CTE_REAL           { (validacionBinaria == 0) ? (tipoAuxiliar1 = "float") : (tipoAuxiliar2 = "float"); validacionBinaria = 1; }  
    | CTE_CARACTER       { (validacionBinaria == 0) ? (tipoAuxiliar1 = "char" ) : (tipoAuxiliar2 = "char" ); validacionBinaria = 1; }
    ;

/* -------------------------------------------------- DECLARACIONES -------------------------------------------------- */ 

declaracion: declaracionVariable
    |  declaracionFuncion
;

/*DECLARACION VARIABLES*/

declaracionVariable: TIPO_DATO  declarador  ';' { tipoAuxiliar = strdup($<cadena>1); tipoAuxiliar = insertarDeclaradores(tipoAuxiliar); agregarSimbolosSinRepetir(tipoAuxiliar,identificadorAuxiliar, 0);} 
    ;

declarador: unaDeclaracion                  
    | unaDeclaracion'=' inicializador
    ;

inicializador: expresionAsignacion
    | '{' listaInicializadores '}'
    | '{'listaInicializadores ',' listaInicializadores '}'
    ;

listaInicializadores: inicializador
    | listaInicializadores ',' inicializador  
    ;


/*DECLARACION FUNCIONES*/

declaracionFuncion: TIPO_DATO  IDENTIFICADOR '(' listaParametros_ ')' ';' { agregarSimbolosSinRepetir($<cadena>1,$<cadena>2, 1);  agregarParametros($<cadena>2); }
    | TIPO_DATO  IDENTIFICADOR '(' listaParametros_ ')' sentenciaCompuesta { agregarSimbolosSinRepetir($<cadena>1,$<cadena>2, 1);  agregarParametros($<cadena>2);}
;

listaDeParametros:   parametro                          
                    | listaDeParametros ',' parametro
;

parametro: TIPO_DATO IDENTIFICADOR  unaDeclaracion { tipoAuxiliar = strdup($<cadena>1); tipoAuxiliar = insertarDeclaradores(tipoAuxiliar); agregarParametro(&tablaDeParametros, tipoAuxiliar); }
;

unaDeclaracion:/* */
    | puntero declaradorDirecto
    ;

puntero: '*'      { contador.punteros++; }  
    | '*' puntero { contador.punteros++; }
    ;

declaradorDirecto: IDENTIFICADOR                        { identificadorAuxiliar = strdup($<cadena>1); }
    | declaradorDirecto '[' expresionConstante_ ']'     { contador.dimensiones++; }
    ;
/* -------------------------------------------------- SENTENCIAS --------------------------------------------------*/ 
sentencia:  sentenciaExpresion      
          | sentenciaCompuesta      
          | sentenciaSeleccion    
          | sentenciaIteracion    
          | sentenciaEtiquetada     
          | sentenciaSalto         
;

sentenciaExpresion: /* vacio */ ';'                                         { printf("\nLinea %i Se encontro una SENTENCIA-EXPRESION: VACIA", yylineno);   }
                    | expresion ';'                                         
;


/*aca en vez de poner listaDeDeclaraciones  y listaDeSentencias dentor de las llaves como hizo martin, se lo derive dentro del interiorSentenciaCompuesta */
sentenciaCompuesta:       '{' listaDeclaraciones_ listaSentencias_'}'                { printf("\nLinea %i Se encontro una SENTENCIA-EXPRESION: COMPUESTA", yylineno); }
;

listaDeDeclaraciones:   declaracion
                      | listaDeDeclaraciones declaracion 
;

listaDeSentencias:    sentencia
                    | listaDeSentencias sentencia
;

sentenciaSeleccion: IF '(' expresion ')' sentencia                  { printf("\nLinea %i Se encontro una SENTENCIA-SELECCION:  IF", yylineno);    }    
                    | IF '(' expresion ')' sentencia ELSE sentencia { printf("\nLinea %i Se encontro una SENTENCIA-SELECCION:  IF/ELSE", yylineno);    } 
                    | SWITCH '(' expresion ')' sentencia            { printf("\nLinea %i Se encontro una SENTENCIA-SELECCION:  SWITCH ", yylineno);    }
;

sentenciaIteracion: WHILE '(' expresion ')' sentencia                               { printf("\nLinea %i - SENTENCIA - ITERACION:  WHILE   ", yylineno);   } 
                    | DO sentencia WHILE '(' expresion ')' ';'                      { printf("\nLinea %i Se encontro una SENTENCIA-ITERACION:  DO/WHILE", yylineno);   } 
                    | FOR '(' expresion_';' expresion_ ';' expresion_ ')' sentencia { printf("\nLinea %i Se encontro una SENTENCIA-ITERACION:  FOR     ", yylineno);   }
;

sentenciaEtiquetada: CASE expresionConstante ':' sentencia 
                    | DEFAULT ':' sentencia 
;
/* saque esta linea donde estaba el IDENTIFICADOR porque creo q lo usa para el GOTO de la sentenciasalto pero como VOLAMOS el goto del FLEX no hace falta */ 


sentenciaSalto: CONTINUE ';'    { printf("\nLinea %i Se encontro la SENTENCIA-SALTO:  CONTINUE", yylineno);   }
    | BREAK ';'                 { printf("\nLinea %i Se encontro la SENTENCIA-SALTO:  BREAK   ", yylineno);   } 
    | RETURN expresion_ ';'      { printf("\nLinea %i Se encontro la SENTENCIA-SALTO:  RETURN  ", yylineno);   } 
;

/* **************************************** OPCIONALES **************************************** */
// Opcionales en "Expresiones"
listaArgumentos_: /* */
    | listaArgumentos
    ;

// Opcionales en "Declaraciones"

expresionConstante_: /* */
    | expresionConstante
    ;

listaParametros_: /* */ 
    | listaDeParametros
    ;

// Opcionales en "Sentencias"
expresion_: /* */    
    | expresion       
    ;

listaDeclaraciones_: /* */
    | listaDeDeclaraciones 
    ;

listaSentencias_: /* */ 
    | listaDeSentencias 
    ;
%%

int main(){

     #ifdef BISON_DEBUG
        yydebug = 1;
    #endif 
    
    yyin = fopen("./codigoEnC.c", "r");
    printf("\nTipos de errores: ");

    printf("\nValidacines semanticas:");
    printf("\nDoble declaraciones: ");
    imprimirSimbolos(tablaDeDobleDeclaracion);

    printf("\nTabla de simbolos:");
    imprimirSimbolos(tablaDeSimbolos);

    
    yyparse();


}