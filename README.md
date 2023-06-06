# Projeto de Estrutura de Dados I

## Objetivos
- Realizar uma simulação de uma troca de pacotes entre dois hosts.
- Calcular o caminho mínimo que o pacote deve percorrer por meio dos algoritmos de roteamento.
- Rebalancear as arestas do grafo conforme o pacote é transimitido.
- Mostrar a tabela com as informações que os roteadores tem do caminho mínimo.(1)
- Interessante deixar por parte do usuário escolher quando transmitir o pacote e ver as particularidades de cada algoritmo.(2)

(1) Obs: No Link State (Dijkstra) ele dissemina as informações referentes ao roteamento para
    todos os roteadores na rede, já o Distance Vector (Bellman-Ford) dissemina as informações
    referentes ao roteamento apenas para os vizinhos.

(2) Obs: Ideia inicial de realizar uma interface no terminal, mas caso o Leoni faça a boa e 
    aprenda ncurses eu fecho com a ideia.

## TODO

### Implementação dos componentes da rede
- [ ] Hosts (Computadores)
- [ ] Pacote Transmitido
- [ ] Roteadores

### Grafo
- [ ] Grafo para os roteadores da rede

### Interface
- [ ] Interface normal de um terminal
- [ ] Interface usando ncurses (Boa sorte Leoni!!!!)

### Algoritmos de roteamento
- [ ] Distance Vector
- [ ] Link State

## Considerações finais
- Acredito que o projeto já tenha um grau de complexidade e de aplicações interessante, mas caso
  alguém tiver alguma ideia/crítica ela será sempre bem vinda.
- Eu formulei uma estrutura para o projeto, mas caso alguém queira mudar alguma coisa sinta-se 
  livre para alterar o que achar necessário.
- Se der tempo, o Adriano deu a ideia de falar sobre o problema de contagem ao infinito do algoritmo
  distance vector, que acontece quando existe uma falha na topologia da rede e as informações do
  roteamento não são atualizadas corretamente (contagem incorreta de saltos até o destino).

## Slides interessantes sobre os algoritmos de roteamento 
- https://homepages.dcc.ufmg.br/~jmarcos/cursos/redes/Telecom2008/cap04a-Camada-de-Rede.pdf
- Obs: Não precisa ler tudo, tem algumas coisas que não são necessárias para o projeto.
