#include <stdio.h>

//Numeros de páginas na memória (memória física)
#define NUM_PAGES 4 

// Numeros de páginas na memória (memória física)
#define NUM_REFS 8 

// Inicializa memória
void memStart(int memory[], int size){
    for(int i = 0; i < size; i++){
        memory[i] = -1;
        // Indicar que memória está livre para ser usada
        // não foi alocada
    }    
}

// Função para verificar se a página está na memória
int memIsPresent(int memory[], int size, int page){
    for (int i = 0; i < size;i++) {
        if (memory[i] == page) {
            return 1;
        }
    }
    return 0;
}

void switchPage(int memory[], int size, int page){
    for(int i = 0; i < size-1;i++){
        // deslocando as páginas uma posição para a esquerda
        memory[i] = memory[i+1];
    }
    //inserindo a nova página na última posição
    memory[size-1] = page;
}


int main() {
    
    int memory[NUM_PAGES]; //memória
    int refs[]= {0,1,2,3,4,5,6,7}; //referencia página

    memStart(memory, NUM_PAGES);

    printf("Referências de Página: \n");
    for(int i = 0; i < NUM_REFS; i++){
      int page = refs[i];
      printf("Referências %d: Página %d\n", i+1, page);


        // Verifica se está na memória
        if(!memIsPresent(memory, NUM_PAGES, page)){
            printf("Página %d não está na memória.\n", page);
            printf("Substituíndo...\n");
            
            // substitui página
            switchPage(memory, NUM_PAGES, page);
        }else{
            printf("Página %d já está na memória", page);
        }
        printf("Estado atual da memória: [");
        for (int j = 0;j < NUM_PAGES;j++ ) {
            printf("%d, ", memory[j]);
        }
        printf("]\n\n");
    }
        

        
    return 0;
}
