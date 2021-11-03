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


%union {
    char* cadena;
    int entero;
    float real;
}

%token <cadena> IDENTIFICADOR


%token <cadena> OP_ASIGNACION                
%token <cadena> OP_O_LOGICO                   
%token <cadena> OP_Y_LOGICO                  
%token <cadena> OP_O_INCLUSIVO                
%token <cadena> OP_O_EXCLUSIVO               
%token <cadena> OP_IGUALDAD                  
%token <cadena> OP_RELACIONAL                
%token <cadena> OP_DIVISION 
%token <cadena> OP_PORCENTAJE 
%token <cadena> OP_INCREMENTO                
%token <cadena> SIZEOF  

%token <cadena> CONSTANTE_CADENA                    
%token <entero> CONSTANTE_DECIMAL                   
%token <entero> CONSTANTE_OCTAL                         
%token <entero> CONSTANTE_HEXADECIMAL               
%token <real>   CONSTANTE_REAL                        
%token <entero> CONSTANTE_CARACTER                   

%token <cadena> TIPO_DATO 

%token <cadena> IF
%token <cadena> ELSE
%token <cadena> SWITCH
%token <cadena> WHILE
%token <cadena> DO
%token <cadena> FOR
%token <cadena> CASE
%token <cadena> DEFAULT
%token <cadena> CONTINUE
%token <cadena> BREAK
%token <cadena> RETURN

%token <cadena> STRUCT


%% /* A continuacion las reglas gramaticales y las acciones */

input:    /* vacio */
        | input line
;

line: declaracion '\n'            
    | sentencia '\n'        
    | error caracterDeCorte   {ver como implementar aca el cod C  }  
    ;

/*me parecio mejor ponerlo asi con un caracter de corte para variar, igual discutirlo */
caracterDeCorte: ';'
                |'\n'
;


/* -------------------------------------------------- SENTENCIAS -------------------------------------------------- */ 


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

declaracionFuncion: TIPO_DATO  IDENTIFICADOR parametros final  { pushSimboloSinRepetir($<cadena>2, $<cadena>1, 1);  pushParametros($<cadena>2); }
;

parametros: '(' listaDeParametros ')'
            | '(' ')'
;

listaDeParametros:   parametro                          
                    | listaDeParametros ',' parametro
;

parametro:  TIPO_DATO
            | TIPO_DATO IDENTIFICADOR  /*esto seria el decla directo de martin */

final:  ';'                                           
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
    ;

/* -------------------HASTA ACA OKKK. LO Q SIGUE SOLO ES COPYPASTE FALTA ARREGLAR------------------------------------------- */

expresionRelacional: expresionCorrimiento 
    | expresionRelacional OP_RELACIONAL expresionCorrimiento 
;

expresionCorrimiento: expresionAditiva 
    | expresionCorrimiento OP_CORRIMIENTO expresionAditiva 
    ;

expresionAditiva: expresionMultiplicativa 
    | expresionAditiva '+' expresionMultiplicativa  { numeroLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0; }
    | expresionAditiva '-' expresionMultiplicativa  { numeroLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0; }
    ;

expresionMultiplicativa: expresionConversion 
    | expresionMultiplicativa '*' expresionConversion                       { numeroLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0; }
    | expresionMultiplicativa OPERADOR_MULTIPLICATIVO expresionConversion   { numeroLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0; }
    ;

expresionConversion: expresionUnaria 
    | '(' TIPO_DATO ')' expresionConversion 
    ;

expresionUnaria: expresionSufijo            
    | OPERADOR_INCREMENTO expresionUnaria
    | operadorUnario expresionConversion 
    | OPERADOR_SIZEOF expresionUnaria    
    | OPERADOR_SIZEOF '(' TIPO_DATO ')'    
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
    | expresionSufijo '(' listaArgumentos_ ')' { numeroLinea = yylineno; pushSimbolo(&tablaAuxiliar, $<cadena>1, "-", 1);  tablaAuxiliar->tiposParametros = tablaParametros; validacionInvocacion(tablaAuxiliar);  tablaParametros = NULL; tablaAuxiliar = NULL; }
    | expresionSufijo OPERADOR_INCREMENTO                       
    ;

listaArgumentos: expresionAsignacion            { pushParametro(&tablaParametros, $<cadena>1); } 
    | listaArgumentos ',' expresionAsignacion   { pushParametro(&tablaParametros, $<cadena>3); } 
    ;

expresionPrimaria: IDENTIFICADOR    { tablaAuxiliar = obtenerIdentificador($<cadena>1); if(tablaAuxiliar != NULL) (validacionBinaria == 0) ? (tipoAuxiliar1 = tablaAuxiliar->tipo) : (tipoAuxiliar2 = tablaAuxiliar->tipo) ; validacionBinaria = 1; }  
    | constante                     
    | CONSTANTE_CADENA              { (validacionBinaria == 0) ? (tipoAuxiliar1 = "char*") : (tipoAuxiliar2 = "char*"); validacionBinaria = 1; }
    | '(' expresion ')'
    ;

expresionConstante: expresionCondicional
    ; 

constante: CONSTANTE_DECIMAL   { (validacionBinaria == 0) ? (tipoAuxiliar1 = "int"  ) : (tipoAuxiliar2 = "int"  ); validacionBinaria = 1; }      
    | CONSTANTE_OCTAL          { (validacionBinaria == 0) ? (tipoAuxiliar1 = "int"  ) : (tipoAuxiliar2 = "int"  ); validacionBinaria = 1; }
    | CONSTANTE_HEXADECIMAL    { (validacionBinaria == 0) ? (tipoAuxiliar1 = "int"  ) : (tipoAuxiliar2 = "int"  ); validacionBinaria = 1; }
    | CONSTANTE_REAL           { (validacionBinaria == 0) ? (tipoAuxiliar1 = "float") : (tipoAuxiliar2 = "float"); validacionBinaria = 1; }  
    | CONSTANTE_CARACTER       { (validacionBinaria == 0) ? (tipoAuxiliar1 = "char" ) : (tipoAuxiliar2 = "char" ); validacionBinaria = 1; }
    ;