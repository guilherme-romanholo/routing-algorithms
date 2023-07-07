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
- [ ] Pacote Transmitido
- [ ] Roteadores
- [ ] IP

### Grafo
- [ ] Grafo para os roteadores da rede

### Interface
- [ ] Interface normal de um terminal

### Algoritmos de roteamento
- [ ] Distance Vector
    - Inicialização: Cada roteador começa com uma tabela de roteamento que contém os custos diretos conhecidos para seus vizinhos. Os custos para destinos desconhecidos são inicializados como infinito ou um valor alto.
    - Atualização do vetor de distância: Periodicamente ou quando ocorrerem alterações na rede, cada roteador envia seu vetor de distância para seus vizinhos. Os vizinhos recebem o vetor de distância, calculam o custo mínimo para cada destino e atualizam suas próprias tabelas de roteamento, se necessário.
    - Propagação das alterações: Quando uma tabela de roteamento é atualizada, as alterações devem ser propagadas para os vizinhos. Isso pode ser feito por meio do envio do vetor de distância atualizado.
    - Controle de loop: Para evitar loops, podem ser implementados mecanismos, como a contagem de saltos máxima ou o uso de um valor de sequência em cada vetor de distância, para garantir que as informações de roteamento sejam atualizadas corretamente e que os loops sejam evitados.
- [ ] Link State
    - Descoberta da topologia: Cada roteador coleta informações sobre os vizinhos e os custos das conexões usando mecanismos como o protocolo de descoberta de vizinhos.
    - Construção do grafo de topologia: Cada roteador usa as informações coletadas para construir um grafo de topologia completo da rede. Isso pode ser feito por meio de uma matriz de adjacência ou uma lista de adjacência.
    - Execução do algoritmo de Dijkstra: Cada roteador executa o algoritmo de Dijkstra para calcular o caminho mais curto para todos os outros roteadores na rede, com base nas informações de custo coletadas anteriormente.
    - Construção das tabelas de roteamento: Com as informações do caminho mais curto calculadas, cada roteador constrói sua tabela de roteamento, indicando o próximo salto para cada destino na rede.
