#include <iostream>
#include <string>
#include <stdio.h>
#include <chrono>
using namespace std;

template <class T>

class No {
    public:
        T valor;
        No *next;
 
        No(T v) {
            valor = v;
        }
};
template <class T>
class stack {
    public:
        No<T> *topo;
 
        stack() {
            topo = NULL;
        }
 
        void push(T valor){
            No<T> *aux = new No<T>(valor);
            if (topo == nullptr){
                topo = aux;
            } else {
                aux->next = topo;
                topo = aux;
            }
        }
 
        T pop(){
            if (topo != nullptr){
                T retorno = topo->valor;
                topo = topo->next;
                return  retorno;
            }else {
              T ora;
              return ora;
            }
        }
 
        T top(){
            if (topo == NULL){
              T ora;
              return ora;
            } else {
                return topo->valor;
            }
        }

      int size(){
        int size=0;
        No<T> *reserva = topo;
        while(topo != nullptr){
          topo = topo->next;
          size++;
        }
        topo = reserva;
        return size;
      }
 
};

stack<int> criar() {
  stack<int> pilha;
  for(int i=0;i<=1000000;i++){
    pilha.push(i);
  }
  return pilha;
};

void soma_cima(stack<int>* pilha){
  int soma=0;
  while(pilha->top()){
    pilha->push(soma);
    soma = pilha->pop() + pilha->pop();
  }
  pilha->push(soma);
}

stack<int> inverte(stack<int>* pilha){
  stack<int> pilha_reserva;
  while(pilha->top()){
    pilha_reserva.push(pilha->pop());
  }
  return pilha_reserva;
}

void soma_baixo(stack<int>* pilha){
  *pilha = inverte(pilha);
  soma_cima(pilha);
}

int main() {
  auto inicio = std::chrono::high_resolution_clock::now();
  stack<int> pilha = criar();
  auto resultado = std::chrono::high_resolution_clock::now() - inicio;
  long long liliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(resultado).count();
  cout << "preenchimento da pilha: " << liliseconds << " miliseconds" << endl;
  inicio = std::chrono::high_resolution_clock::now();
  soma_cima(&pilha);
  resultado = std::chrono::high_resolution_clock::now() - inicio;
  liliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(resultado).count();
  cout << "soma de cima para baixo: " << liliseconds << " miliseconds" << endl;
  cout << "resultado da soma: " << pilha.top() << endl;
  inicio = std::chrono::high_resolution_clock::now();
  stack<int> pilha_1 = criar();
  resultado = std::chrono::high_resolution_clock::now() - inicio;
  liliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(resultado).count();
  cout << "preenchimento 2: " << liliseconds << " miliseconds" << endl;
  inicio = std::chrono::high_resolution_clock::now();
  soma_baixo(&pilha_1);
  resultado = std::chrono::high_resolution_clock::now() - inicio;
  liliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(resultado).count();
  cout << "soma de baixo para cima: " << liliseconds << " miliseconds" << endl;
  cout << "resultado da soma: " << pilha.top() << endl;
  
}
