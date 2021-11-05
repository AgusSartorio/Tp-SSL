%{
    #include <ctype.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "validaciones_semanticas.c"

    int yylex();
    int yywrap(){ return(1); }
    void yyerror (char const *s) {}

    FILE* yyin;

    extern int yylineno;

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

%token <cadena> STRUCT
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
%type <cadena> declarador
%type <cadena> expresionPrimaria
%type <cadena> constante

// %type <cadena> decla
// %type <cadena> puntero
// adentro del decla %type <cadena> declaradorDirecto


%% /* A continuacion las reglas gramaticales y las acciones */

input:    /* vacio */
        | input line
;

line: declaracion '\n'            
    | sentencia '\n'        
    | error caracterDeCorte   {ver como implementar aca el cod C  }  
    ;

/*me parecio mejor ponerlo asi con un caracter de corte para variar, igual discutirlo */

caracterDeCorte: ';'  { printf("\n***Error sintactico - Linea %i: %s***", yylineno, $<cadena>1); }
                |'\n' { printf("\n***Error sintactico - Linea %i: %s***", yylineno, $<cadena>1); }
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
                    | expresion ';'                                         { printf("\nLinea %i Se encontro una SENTENCIA-EXPRESION", yylineno);   }
;


/*aca en vez de poner listaDeDeclaraciones  y listaDeSentencias dentor de las llaves como hizo martin, se lo derive dentro del interiorSentenciaCompuesta */
sentenciaCompuesta:       '{' interiorSentenciaCompuesta '}'                { printf("\nLinea %i Se encontro una SENTENCIA-EXPRESION: COMPUESTA", yylineno); }
;

interiorSentenciaCompuesta:        /* vacio */                              {printf("Se encontro una SENTENCIA COMPUESTA VACIA\n");}
                                | listaDeDeclaraciones                      
                                | listaDeSentencias                         
                                | listaDeDeclaraciones listaDeSentencias    
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
                    
/* saque esta linea donde estaba el IDENTIFICADOR porque creo q lo usa para el GOTO de la sentenciasalto pero como VOLAMOS el goto del FLEX no hace falta */ 
;

sentenciaSalto: CONTINUE ';'    { printf("\nLinea %i Se encontro la SENTENCIA-SALTO:  CONTINUE", yylineno);   }
    | BREAK ';'                 { printf("\nLinea %i Se encontro la SENTENCIA-SALTO:  BREAK   ", yylineno);   } 
    | RETURN expresion ';'      { printf("\nLinea %i Se encontro la SENTENCIA-SALTO:  RETURN  ", yylineno);   } 
/* VOLE EL GOTO IDENTIFICADOR */
;


/* -------------------------------------------------- DECLARACIONES -------------------------------------------------- */ 

/*dsps discutir las declaraciones*/

declaracion: declaracionVariable
            | declaracionFuncion
;

/*DECLARACION VARIABLES*/

declaracionVariable: TIPO_DATO  declarador  ';' { tipoAuxiliar = strdup($<cadena>1); tipoAuxiliar = agregadorDeclaradores(tipoAuxiliar); pushSimboloSinRepetir(identificadorAuxiliar, tipoAuxiliar, 0);} 
    ;

declarador: IDENTIFICADOR                   
    | IDENTIFICADOR '=' inicializador
    ;

inicializador: expresionAsignacion
    | '{' listaInicializadores '}'
    | '{'listaInicializadores ',' listaInicializadores '}'
    ;

listaInicializadores: inicializador
    | listaInicializadores ',' inicializador  
    ;


/*DECLARACION FUNCIONES*/

declaracionFuncion: TIPO_DATO  IDENTIFICADOR parametros finDeDeclaracion  { pushSimboloSinRepetir($<cadena>2, $<cadena>1, 1);  pushParametros($<cadena>2); }
;

parametros: '(' listaDeParametros ')'
            | '(' ')'
;

listaDeParametros:   parametro                          
                    | listaDeParametros ',' parametro
;

parametro: TIPO_DATO IDENTIFICADOR              { tipoAuxiliar = strdup($<cadena>1); tipoAuxiliar = agregadorDeclaradores(tipoAuxiliar); pushParametro(&tablaParametros, tipoAuxiliar); }
  /*esto seria el decla directo de martin */

finDeDeclaracion:     ';'                                           
                    | sentenciaCompuesta   {completar}             
                    | '{' error '}'        {completar}              
                    | error                {completar} 
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
    | expresionAditiva '+' expresionMultiplicativa  { numeroLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0; }
    | expresionAditiva '-' expresionMultiplicativa  { numeroLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0; }
    ;

expresionMultiplicativa: expresionConversion 
    | expresionMultiplicativa '*' expresionConversion                       { numeroLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0; }
    | expresionMultiplicativa OP_DIVISION expresionConversion               { numeroLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0; }
    | expresionMultiplicativa OP_PORCENTAJE expresionConversion             { numeroLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0; }
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
    | expresionSufijo '[' expresion ']' /* arreglo */           
    | expresionSufijo '(' listaArgumentos ')'       { numeroLinea = yylineno; pushSimbolo(&tablaAuxiliar, $<cadena>1, "-", 1);  tablaAuxiliar->tiposParametros = tablaParametros; validacionInvocacion(tablaAuxiliar);  tablaParametros = NULL; tablaAuxiliar = NULL; }
    | expresionSufijo OP_INCREMENTO                       
    ;

listaArgumentos: expresionAsignacion            { pushParametro(&tablaParametros, $<cadena>1); } 
    | listaArgumentos ',' expresionAsignacion   { pushParametro(&tablaParametros, $<cadena>3); } 
    ;

expresionPrimaria: IDENTIFICADOR    { tablaAuxiliar = obtenerIdentificador($<cadena>1); if(tablaAuxiliar != NULL) (validacionBinaria == 0) ? (tipoAuxiliar1 = tablaAuxiliar->tipo) : (tipoAuxiliar2 = tablaAuxiliar->tipo) ; validacionBinaria = 1; }  
    | constante                     
    | CTE_CADENA              { (validacionBinaria == 0) ? (tipoAuxiliar1 = "char*") : (tipoAuxiliar2 = "char*"); validacionBinaria = 1; }
    | '(' expresion ')'
    ;

expresionConstante: expresionCondicional /* ver lo del CASE
    ; 

constante: CTE_DECIMAL   { (validacionBinaria == 0) ? (tipoAuxiliar1 = "int"  ) : (tipoAuxiliar2 = "int"  ); validacionBinaria = 1; }      
    | CTE_OCTAL          { (validacionBinaria == 0) ? (tipoAuxiliar1 = "int"  ) : (tipoAuxiliar2 = "int"  ); validacionBinaria = 1; }
    | CTE_HEXADECIMAL    { (validacionBinaria == 0) ? (tipoAuxiliar1 = "int"  ) : (tipoAuxiliar2 = "int"  ); validacionBinaria = 1; }
    | CTE_REAL           { (validacionBinaria == 0) ? (tipoAuxiliar1 = "float") : (tipoAuxiliar2 = "float"); validacionBinaria = 1; }  
    | CTE_CARACTER       { (validacionBinaria == 0) ? (tipoAuxiliar1 = "char" ) : (tipoAuxiliar2 = "char" ); validacionBinaria = 1; }
    ;