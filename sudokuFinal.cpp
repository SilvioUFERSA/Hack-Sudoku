#include <stdio.h>
#include <stdlib.h>

typedef unsigned char Candidate[9];
typedef unsigned char Value;

void initMap(Candidate *c, Value v)
{
    if (v == 0)
    {
        for (int i = 0; i < 9; i++)
        {
            (*c)[i] = 1;
        }
    }
    else
    {
        for (int i = 0; i < 9; i++)
        {
            (*c)[i] = 0;
        }
        (*c)[v - 1] = 1;
    }
}

void getElementosLinha(Value L[9], int *n, Value sudoku[9][9], int x)
{
    for (size_t i = 0; i < 9; i++)
    {
        if (sudoku[x][i] != 0)
        {
            L[(*n)++] = sudoku[x][i];
        }
    }
}

void getElementosColuna(Value L[9], int *n, Value sudoku[9][9], int x)
{
    for (size_t i = 0; i < 9; i++)
    {
        if (sudoku[i][x] != 0)
        {
            L[(*n)++] = sudoku[i][x];
        }
    }
}

void getElementosGrid(Value L[9], int * n, Value sudoku[9][9], int x){
    size_t i, j; // i linha, j coluna

    if(x == 0){ // grid 0
        for(i =0 ; i< 3; i++){
            for( j =0; j< 3; j++){
                if(sudoku[i][j] != 0){    // ou if( sudoku[i][j] != 0 && sudoku[i][j] != L[(*n)])
                L[(*n)++] = sudoku[i][j];
                }
            }
        }
    }

    if(x == 1){ // grid 1
    for(i =0 ; i< 3; i++){
            for( j =3; j< 6; j++){
                if(sudoku[i][j] != 0){
                    L[(*n)++] = sudoku[i][j];
                }
            }
        }
    } 
    
    if(x == 2){ // grid 2
    for(i =0 ; i< 3; i++){
            for( j =6; j< 9; j++){
            if(sudoku[i][j] != 0){
                L[(*n)++] = sudoku[i][j];
                }
            }
        }
    }
     
     if(x == 3){ // grid 3
        for(i =3 ; i< 6; i++){
            for( j =0; j< 3; j++){
                if(sudoku[i][j] != 0){
                    L[(*n)++] = sudoku[i][j];
                }
            }
        }
    } 
    if(x == 4){ // grid 4
    for(i =3 ; i< 6; i++){
            for( j =3; j< 6; j++){
                if(sudoku[i][j] != 0){
                    L[(*n)++] = sudoku[i][j];
                }
            }    
        }
    }
    if(x == 5){ // grid 5
    for(i =3 ; i< 6; i++){
            for( j =6; j< 9; j++){
                if(sudoku[i][j] != 0){
                    L[(*n)++] = sudoku[i][j];
                }
            }
        }
    } 
    if(x == 6){ // grid 6
    for(i =6 ; i< 9; i++){
            for( j =0; j< 3; j++){
                if(sudoku[i][j] != 0){
                    L[(*n)++] = sudoku[i][j];
                }
            }
        }
    }
     if(x == 7){ // grid 7
    for(i =6 ; i< 9; i++){
            for( j=3; j< 6; j++){
                if(sudoku[i][j] != 0 ){
                    L[(*n)++] = sudoku[i][j];
                }
            }    
        }
    }  
     if(x == 8){ // grid 8
    for(i =6 ; i< 9; i++){
            for( j=6; j< 9; j++){
                if(sudoku[i][j] != 0 ){
                    L[(*n)++] = sudoku[i][j];
                }
            }
        }
    }  
}

void eliminarNumero(Candidate *c, Value v)
{
    (*c)[v] = 0;
}

void eliminarLinha(Value sudoku[9][9], Candidate mapa[9][9], int x){
    Value L[9];
    int *n = (int *)malloc(sizeof(int));
    getElementosLinha(L, n, sudoku, x);
    for (int j = 0; j < *n; j++)
    {
        int elem = L[j] - 1;
        for (int i = 0; i < 9; i++)
        {
            if (sudoku[x][i] == 0)
            {
                eliminarNumero(&mapa[x][i], elem);
            }
        }
    }
}

void eliminarColuna(Value sudoku[9][9], Candidate mapa[9][9], int x)
{
    Value L[9];
    int *n = (int *)malloc(sizeof(int));
    getElementosColuna(L, n, sudoku, x);
    for (int j = 0; j < *n; j++)
    {
        int elem = L[j] - 1;
        for (int i = 0; i < 9; i++)
        {
            if (sudoku[i][x] == 0)
            {
                eliminarNumero(&mapa[i][x], elem);
            }
        }
    }
}

void eliminarGrids(Value sudoku[9][9], Candidate mapa[9][9], int x){
    Value L[9];

    int * n = (int *)malloc (sizeof(int));
    getElementosGrid(L, n, sudoku, x);

      int a, b; //a - linha ; b-Coluna

         

          if( x== 1){ //grid 0
           for (int j = 0; j < *n; j++){
            int elem0 = L[j] - 1;
             for( a= 0; a <3; a++){ 
              for( b=0 ; b < 3; b++){
                if(sudoku[a][b] == 0){
                    eliminarNumero(&mapa[a][b], elem0);
                }
              }
            }  
         }
      }
       if(x==1){ 
          for (int j = 0; j < *n; j++){
            int elem1 = L[j] - 1;
            for( a =0;  a< 3; a++){
              for( b=3 ; b < 6; b++){
                if(sudoku[a][b] == 0){
                    eliminarNumero(&mapa[a][b], elem1);
                }
              }
            }  
          }
        }
      
         if(x==2){ 
            for (int j = 0; j < *n; j++){
            int elem2 = L[j] - 1;
            for( a =0; a < 3; a++){
              for( b=6 ; b < 9; b++){
                if(sudoku[a][b] == 0){
                    eliminarNumero(&mapa[a][b], elem2);
                }
              }
            }  
          }
        }
         if(x==3){
            for (int j = 0; j < *n; j++){
            int elem3 = L[j] - 1; 
            for( a =3; a < 6; a++){
              for( b=0 ; b < 3; b++){
                if(sudoku[a][b] == 0){
                    eliminarNumero(&mapa[a][b], elem3);
                }
              }
            }  
          }
       }
         if(x==4){ 
            for (int j = 0; j < *n; j++){
            int elem4 = L[j] - 1;
            for( a =3; a < 6; a++){
              for( b=3 ; b < 6; b++){
                if(sudoku[a][b] == 0){
                    eliminarNumero(&mapa[a][b], elem4);
                }
              }
            }  
          }
        }
         if(x==5){
            for (int j = 0; j < *n; j++){
            int elem5 = L[j] - 1; 
            for( a =3; a < 6; a++){
              for( b=6 ; b < 9; b++){
                if(sudoku[a][b] == 0){
                    eliminarNumero(&mapa[a][b], elem5);
                }
              }
            }  
          }
        }
         if(x==6){
            for (int j = 0; j < *n; j++){
            int elem6 = L[j] - 1;
            for(a =6; a < 9; a++){
              for( b=0 ; b < 3; b++){
                if(sudoku[a][b] == 0){
                    eliminarNumero(&mapa[a][b], elem6);
                }
              }
            }  
          }
        }
         if(x==7){
            for (int j = 0; j < *n; j++){
            int elem7 = L[j] - 1;
            for(a =6; a < 9; a++){
              for( b=3 ; b < 6; b++){
                if(sudoku[a][b] == 0){
                    eliminarNumero(&mapa[a][b], elem7);
                }
              }
            }
          }  
        }
         if(x==8){
            for (int j = 0; j < *n; j++){
              int elem8 = L[j] - 1;
            for( a=6; a < 9; a++){
              for( b=6 ; b < 9; b++){
                if(sudoku[a][b] == 0){
                    eliminarNumero(&mapa[a][b], elem8);
                }
              }
            }  
          }
        }
      

}

void eliminarTodasLinhas(Value sudoku[9][9], Candidate mapa[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        eliminarLinha(sudoku, mapa, i);
    }
}

void eliminarTodasColunas(Value sudoku[9][9], Candidate mapa[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        eliminarColuna(sudoku, mapa, i);
    }
}

void eliminarTodasGrids(Value sudoku[9][9], Candidate mapa[9][9]){
    for (int i = 0; i < 9 ; i++ ){
        eliminarGrids(sudoku, mapa, i);
    }
}

int Valida_Linha(Value Sudoku[9][9], int L, int num){
  int i, aux=0;
  for( i =0; i < 9; i++){
    if(Sudoku[L][i] == num){
      aux++;
    }
  }
  if( aux == 0){
    return 1;
  }else{
    return 0;
  }
}

int Valida_Coluna(Value Sudoku[9][9], int C, int num){
   int i, aux=0;
   for( i = 0; i < 9; i++){
    if(Sudoku[i][C] == num){
      aux++;
    }
  }
  if( aux == 0){
    return 1;
  }else{
    return 0;
  }
}

int Valida_Grid(Value Sudoku[9][9], int G, int num){
    int i, j , aux = 0;

     if(G == 0){ // grid 0
        for(i =0 ; i< 3; i++){ // linha
            for( j =0; j< 3; j++){ // coluna
                  if(Sudoku[i][j] == num){
                    aux++;
                  }
            }
        }
        if( aux == 0){
          return 1;
        }else{
          return 0;
        }
    }
    

    if(G == 1){ // grid 1
    for(i =0 ; i< 3; i++){
            for( j =3; j< 6; j++){
                if(Sudoku[i][j] == num){
                    aux++;
                  }
            }
        }
        if( aux == 0){
          return 1;
        }else{
          return 0;
        }
    } 
    
    if(G == 2){ // grid 2
    for(i =0 ; i< 3; i++){
            for( j =6; j< 9; j++){
            if(Sudoku[i][j] == num){
                    aux++;
                  }
            }
        }
        if( aux == 0){
          return 1;
        }else{
          return 0;
        }
    }
     
     if(G == 3){ // grid 3
        for(i =3 ; i< 6; i++){
            for( j =0; j< 3; j++){
                if(Sudoku[i][j] == num){
                    aux++;
                  }
            }
        }
        if( aux == 0){
           return 1;
        }else{
          return 0;
       }
    }

    if(G == 4){ // grid 4
    for(i =3 ; i< 6; i++){
            for( j =3; j< 6; j++){
                if(Sudoku[i][j] == num){
                    aux++;
                  }
            }    
        }
        if( aux == 0){
          return 1;
        }else{
          return 0;
        }
    }
    
    if(G == 5){ // grid 5
    for(i =3 ; i< 6; i++){
            for( j =6; j< 9; j++){
               if(Sudoku[i][j] == num){
                    aux++;
                  }
            }
        }
        if( aux == 0){
          return 1;
        }else{
          return 0;
        }
    } 
    
    if(G == 6){ // grid 6
    for(i =6 ; i< 9; i++){
            for( j =0; j< 3; j++){
                if(Sudoku[i][j] == num){
                    aux++;
                  }
            }
        }
        if( aux == 0){
          return 1;
        }else{
          return 0;
        }
    }
   
    if(G == 7){ // grid 7
    for(i =6 ; i< 9; i++){
            for( j=3; j< 6; j++){
                if(Sudoku[i][j] == num){
                    aux++;
                  }
            }    
        }
        if( aux == 0){
          return 1;
        }else{
          return 0;
        }
    }  
     if(G == 8){ // grid 8
    for(i =6 ; i< 9; i++){
            for( j=6; j< 9; j++){
                if(Sudoku[i][j] == num){
                    aux++;
                  }
            }
        }
      if( aux == 0){
        return 1;
      }else{
        return 0;
      }
    }  


}

int define_Grid( int i, int j){
  
  int grid=0;

  
  if( i >= 0 && i<3 && j>=0 && j<3 ){ //grid 0
    grid = 0;
  }
  else if( i >= 0 && i<3 && j>2 && j<6 ){ // grid 1
    grid = 1;
  }
  else if( i >= 0 && i<3 && j>5 && j<9){ // grid 2
    grid = 2;
  }


  else if(i > 2 && i < 6 && j>=0 && j<3){ // grid 3
    grid = 3;
  }
  else if(i > 2 && i < 6 && j>2 && j<6){ // grid 4
    grid = 4;
  }
  else if(i > 2 && i< 6 && j>5 && j < 9){ // grid 5
    grid = 5;
  }


  else if(i > 5 && i < 9 && j >= 0 && j < 3){ // grid 6
    grid = 6;
  }
  else if( i > 5 && i < 9 && j>2 && j<6 ){ // grid 7
    grid = 7;
  }
  else if( i > 5 && i < 9 && j > 5 && j < 9){ //grid 8
    grid = 8;
  }


  if(grid == 0){ // grid 0
    for(i =0 ; i< 3; i++){
            for( j=0; j< 3; j++){
                grid = 0;
                return grid;
            }
        }
  }
    if(grid == 1){ // grid 1
    for(i =0 ; i< 3; i++){
            for( j=3; j< 6; j++){
                grid = 1;
                return grid;
            }
        }
  }
   if(grid == 2){ // grid 2
    for(i =0 ; i< 3; i++){
            for( j=6; j< 9; j++){
                grid = 2;
                return grid;
            }
        }
  }
   if(grid == 3){ // grid 3
    for(i =3 ; i< 6; i++){
            for( j=0; j< 3; j++){
                grid = 3;
                return grid;
            }
        }
  }
   if(grid == 4){ // grid 3
    for(i =3 ; i< 6; i++){
            for( j=3; j< 6; j++){
                grid = 4;
                return grid;
            }
        }
  }
   if(grid == 5){ // grid 5
    for(i =0 ; i< 3; i++){
            for( j=6; j< 9; j++){
                grid = 5;
                return grid;
            }
        }
  }
   if(grid == 6){ // grid 6
    for(i =6 ; i< 9; i++){
            for( j=0; j< 3; j++){
                grid = 6;
                return grid;
            }
        }
  }
   if(grid == 7){ // grid 7
    for(i =6 ; i< 9; i++){
            for( j=3; j< 6; j++){
                grid = 7;
                return grid;
            }
        }
  }
   if(grid == 8){ // grid 8
    for(i =6 ; i< 9; i++){
            for( j=6; j< 9; j++){
                grid = 8;
                return grid;
            }
        }
  }

}

int valida_Numero(Value sudoku[9][9], int L, int C, int G ,int num){
    int coluna=0, linha=0, grid = 0;
    

    coluna =  Valida_Coluna(sudoku, C, num);
    linha =  Valida_Linha(sudoku, L, num);
    grid =  Valida_Grid(sudoku, G, num);
    if( linha + coluna + grid == 3 && sudoku[L][C] == 0){
        return 1;
    }else{
        return 0;
    }
}

int cadidatoDescoberto(Candidate c)
{
    int m = 0;
    int r = 0;
    for (int i = 0; i < 9; i++)
    {
        if (c[i] == 1)
        {
            m += 1;
            r = i;
        }
    }
    if (m == 1)
    {
        return r + 1;
    }
    else
    {
        return -1;
    }
}

void initGame(Value sudoku[9][9], Candidate mapa[9][9], Value *v)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            sudoku[i][j] = v[i * 9 + j];
            initMap(&mapa[i][j], v[i * 9 + j]);
        }
    }
}

void atualizarValores(Value sudoku[9][9], Candidate mapa[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int m = cadidatoDescoberto(mapa[i][j]);
            if (m != -1)
            {
                sudoku[i][j] = m;
            }
        }
    }
}
void print(Value sudoku[9][9]) {
 printf("|=================================|\n|        ->   SUDOKU HACK   <-    |\n|=================================|\n"); 
 printf("|=================================|\n| #   1  2  3   4  5  6   7  8  9 |\n|=================================|\n");

for(int i = 0; i < 9; i++) {
        if(i == 3 || i == 6) {
            printf("|   |---------:---------:---------|\n");
        }

        for(int j = 0; j < 9; j++) {
            if(j == 0) {
                printf("| %d |", i + 1);
            }

            if(sudoku[i][j] == 0) {
                printf(" _ ");
            } else {
                printf(" %d ", sudoku[i][j]);
            }

            if(j == 2 || j == 5) {
                printf("|");
            }

            if(j == 8)  {
                printf("|\n");
            }
        }

        if(i == 8) {
            printf("|=================================|\n");
        }
    }
}

void adicionar_Elemento (Value *v, int i, int j, int x){
    v[i* 9 + j] = x; 
}
int main(void){

     int op, max = 40;
     int x=0, y=0, g=0 ,z=0;
     int resposta = 0;

    Candidate mapa[9][9];
    Value sudoku[9][9];
    Value v[] = {6, 0, 2, 0, 0, 0, 0, 7, 0,
                 0, 9, 0, 2, 0, 6, 0, 3, 8,
                 7, 3, 0, 5, 0, 9, 0, 0, 0,
                 0, 1, 7, 0, 0, 0, 8, 6, 0,
                 0, 0, 0, 7, 0, 5, 0, 0, 0,
                 0, 8, 3, 0, 0, 0, 2, 5, 0,
                 0, 0, 0, 9, 0, 3, 0, 4, 2,
                 3, 2, 0, 4, 0, 1, 0, 8, 0,
                 0, 5, 0, 0, 0, 0, 1, 0, 3};

    initGame(sudoku, mapa, v);


    while ( op != 3){
        print(sudoku);
        printf("|==================================| \n");
        printf("| 1 - inserir elementos no sudoku. | \n");
        printf("| 2 - Autopreencher                | \n");
        printf("| 3 - sair .                       | \n");
        printf("|==================================| \n");

        printf("\n");
        scanf("%d", &op);
    
        system("cls");

    switch (op){
    
    case 1:
        print(sudoku);

        printf("Preencha na ordem: Linha, Coluna, Numero: \n");
        scanf("%d", &x);// linha 
        scanf("%d", &y);// coluna
        scanf("%d", &z);

        x =  x-1; // muda linha e coluna para endereçamento 
        y =  y-1;
        
        g = define_Grid( x, y);

        resposta = valida_Numero(sudoku, x, y, g, z);

        if (resposta == 1){
            adicionar_Elemento(v, x ,y, z);
            printf("\n-> Numero Valido! <- \n");
                initGame(sudoku, mapa, v);
                atualizarValores(sudoku, mapa);
        }else{
            printf("\n! Numero Invalido - Este numero ja existe ou no grid, ou na coluna ou na linha. !\n");
        }
        break;

    case 2:

       initGame(sudoku, mapa, v); 
       
        print(sudoku);

        while(max != 0){
        
        eliminarTodasLinhas(sudoku, mapa);
        atualizarValores(sudoku, mapa);
        eliminarTodasColunas(sudoku, mapa);
        atualizarValores(sudoku, mapa);
        eliminarTodasGrids(sudoku, mapa);
        atualizarValores(sudoku, mapa);
          max--;
        
        }

        print(sudoku);
        

        break;
    
    case 3:
        printf("\n Jogo Encerrado!\n");
        exit (1);
        break;
    
    default:
        printf("\nOpcao Invalidada, tente outra!\n");
        break;
    }
}
    return 0;
}