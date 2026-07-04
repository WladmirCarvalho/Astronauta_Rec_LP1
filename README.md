# Atividade de Recuperação: Sistema de Astronautas (Extensão)

Projeto desenvolvido para a disciplina de **Linguagem de Programação 1 (LP1)** do Instituto Metrópole Digital (IMD/UFRN), ministrada pelo Prof. Isaac Franco Fernandes.

Esta é uma extensão do projeto da Unidade 1, que expande o sistema de gerenciamento da Agência Espacial Brasileira Digital implementando conceitos de Programação Orientada a Objetos, como Herança e Polimorfismo.

## 🚀 Recursos Adicionados

O sistema original foi refatorado e expandido para incluir as duas camadas de requisitos solicitadas na especificação:

### Camada 1: Funções dos Astronautas (Herança e Polimorfismo)
* **Classes Derivadas:** A classe `Astronauta` foi transformada em uma classe base. Foram criadas quatro classes filhas: `Comandante`, `Engenheiro`, `Cientista` e `Turista`.
* **Polimorfismo:** Implementação do método `virtual string funcao()` na classe base e o uso de `override` nas classes filhas para identificação de cada cargo.
* **Armazenamento Seguro:** Uso de `vector<Astronauta*>` (ponteiros) para permitir o comportamento polimórfico na lista de tripulantes globais e nos voos.
* **Novas Regras de Lançamento:** O comando `LANCAR_VOO` agora valida obrigatoriamente a presença de pelo menos **um Comandante** e **um Engenheiro** na tripulação para autorizar o lançamento.
* **Listagens Atualizadas:** Os comandos `LISTAR_VOOS` e `LISTAR_MORTOS` agora exibem também a função específica de cada astronauta.

### Camada 2: Naves e Limite de Capacidade
* **Nova Classe:** Criação da classe `Nave` contendo código, capacidade máxima de tripulantes e nome.
* **Novos Comandos:** 
  * `CADASTRAR_NAVE`: Registra uma nave no sistema verificando duplicidade de código e capacidade válida (maior que zero).
  * `ASSOCIAR_NAVE`: Vincula uma nave existente a um voo na fase de planejamento.
* **Validação de Lotação:** O comando `ADICIONAR_ASTRONAUTA` agora bloqueia a inserção de novos tripulantes caso o limite de capacidade da nave associada ao voo seja atingido.
* **Dependência de Lançamento:** O voo só pode ser lançado se possuir uma nave devidamente associada.

## 🛠️ Como compilar e executar

O projeto foi dividido modularmente em arquivos `.h` e `.cpp`. Para compilar e testar via terminal, siga os passos abaixo:

1. Compile todos os arquivos C++ juntos:
   ```bash
   g++ *.cpp -o sistema