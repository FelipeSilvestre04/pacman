#include <stdio.h>
#include <stdlib.h>

char** mapa;
int linhas;
int colunas;


int acabou(){
return 0;
}



void alocamapa(){
    // alocação do mapa dinamicamente
    mapa = malloc(sizeof(char*) * linhas);
    for (int  i = 0; i < linhas; i++){
    mapa[i] = malloc(sizeof(char) * (colunas + 1));
    }
}

void lermapa(){
        FILE* f;
    f = fopen("mapa.txt", "r");
    if (f == 0) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);  
    }
    fscanf(f, "%d %d", &linhas, &colunas);

alocamapa();
   for(int i = 0; i<5; i++){
             fscanf(f, "%s", mapa[i]);
        }
fclose(f);
}



void liberamapa(){
    for (int i = 0; i < linhas; i++){
    free(mapa[i]);
}
free(mapa);
}

void imprimirmapa(){
for(int i = 0; i<5; i++){
 printf("%s\n", mapa[i]);
}

}

void  mover(char comando){
int x;
int y;

for(int i = 0; i<linhas; i++){
    for(int j = 0; j<colunas; j++){
        if (mapa[i][j] == '@'){
            x = i;
            y = j;
            break;
        }
    }
}


switch (comando)
{
case 'a':
   if(mapa[x][y-1] == '.'){
    mapa[x][y-1] = '@';
    mapa[x][y] = '.';

   }else{
    printf("posicao invalida\n");
    mapa[x][y] = '@'; 
   }
    break;

case 'd':
  
  if(mapa[x][y+1] == '.'){
    mapa[x][y+1] = '@';
    mapa[x][y] = '.';

   }else{
    printf("posicao invalida\n");
    mapa[x][y] = '@'; 
   }

    break;

case 's':
   if(mapa[x+1][y] == '.'){
    mapa[x+1][y] = '@';
    mapa[x][y] = '.';

   }else{
    printf("posicao invalida\n");
    mapa[x][y] = '@'; 
   }
    break;

case 'w':
if(mapa[x-1][y] == '.'){
    mapa[x-1][y] = '@';
    mapa[x][y] = '.';

   }else{
    printf("posicao invalida\n");
    mapa[x][y] = '@'; 
   }

    break;
}  
}

void fantasma(){

int x;
int y;
int m;
int n;
char comando;

for(int i = 0; i<linhas; i++){
    for(int j = 0; j<colunas; j++){
        if (mapa[i][j] == '#'){
            x = i;
            y = j;
            break;
        }
    }
}

for(int z = 0; z<linhas; z++){
    for(int w = 0; w<colunas; w++){
        if (mapa[z][w] == '@'){
            m = z;
            n = w;
            break;
        }
    }
}


if ((m<x)&&(mapa[m-1][n]=='.')){
comando = 'w';
if (mapa[m-1][n]=='@'){
    printf("\nfantasma !\n");
    mapa[m-1][n] = '@';
    acabou();
}

}else if((m>x)&&(mapa[m+1][n]=='.')){
comando = 's';
if (mapa[m+1][n]=='@'){
    printf("\nfantasma atingido!\n");
    mapa[m+1][n] = '@';
    acabou();
}

}else if((n>y)&&(mapa[m][n+1]=='.')){
comando = 'd';
if (mapa[m][n+1]=='@'){
    printf("\nfantasma atingido!\n");
    mapa[m][n+1] = '@';
    acabou();
}

}else if((n<y)&&(mapa[m][n-1]=='.')){
comando = 'a';
if (mapa[m][n-1]=='@'){
    printf("\nfantasma atingido!\n");
    mapa[m][n-1] = '@';
    acabou();

}
}

switch (comando)
{
case 'a':
   if(mapa[x][y-1] == '.'){
    mapa[x][y-1] = '#';
    mapa[x][y] = '.';

   }else{
    printf("posicao invalida\n");
    mapa[x][y] = '#'; 
   }
    break;

case 'd':
  
  if(mapa[x][y+1] == '.'){
    mapa[x][y+1] = '#';
    mapa[x][y] = '.';

   }else{
    printf("posicao invalida\n");
    mapa[x][y] = '#'; 
   }

    break;

case 's':
   if(mapa[x+1][y] == '.'){
    mapa[x+1][y] = '#';
    mapa[x][y] = '.';

   }else{
    printf("posicao invalida\n");
    mapa[x][y] = '#'; 
   }
    break;

case 'w':
if(mapa[x-1][y] == '.'){
    mapa[x-1][y] = '#';
    mapa[x][y] = '.';

   }else{
    printf("posicao invalida\n");
    mapa[x][y] = '#'; 
   }

    break;
}  


}

int main(){

lermapa();     

do
{
imprimirmapa();
char comando;
scanf(" %c", &comando);
fantasma();
mover(comando);
fantasma();


} while (!acabou());


liberamapa();


return 0;
}