# FdF - Renderizador de Wireframe 3D

<p align="center">
  <a href="README.md">
    <img src="https://img.shields.io/badge/Read%20in-English-blue?style=for-the-badge" alt="Read in English">
  </a>
</p>

<p align="center">
  <img src="https://github.com/magalhaesm/fdf/assets/32808884/5675bd55-4211-4a20-95ed-c251c8f1fe59" alt="Banner do Projeto FdF" width="800">
</p>

## Visão Geral

FdF (Fil de Fer, "wireframe" em francês) é um renderizador de wireframe 3D que cria uma representação gráfica de uma paisagem a partir de um arquivo contendo dados de elevação. Este projeto faz parte do currículo da 42 e concentra-se nos fundamentos da programação gráfica computacional, incluindo:

- Criar e gerenciar uma janela com a MiniLibX
- Desenhar linhas com o algoritmo de Bresenham
- Projeções 3D para 2D (isométrica e ortográfica)
- Transformações 3D básicas (translação, rotação, escala)
- Tratamento de cores e gradientes

## Funcionalidades

- Leitura e análise de arquivos de mapa com informações de altura
- Renderização de paisagens em wireframe 3D em projeções isométricas e ortográficas
- Interpretação de cores a partir de arquivos de mapa (quando especificado) ou esquema padrão baseado na elevação
- Capacidades de transformação em tempo real:
  - Rotação em torno dos eixos X, Y e Z
  - Zoom de aproximação/afastamento
  - Translação (movimentação do modelo em qualquer direção)
  - Ajuste da escala de altura
- Controles interativos com legenda na tela
- Gerenciamento responsivo de janelas
- Cor gradiente para linhas baseada na elevação

## Uso

```bash
# Compilar o programa
make

# Executar o programa com um arquivo de mapa
./fdf maps/42.fdf

# Mostrar os controles
Pressione '/' durante a execução
```

## Controles

### Movimentação da Câmera
- **Teclas de Seta**: Movem o modelo nas quatro direções

### Rotação
- **W/S**: Rotação em torno do eixo X
- **A/D**: Rotação em torno do eixo Y
- **Q/E**: Rotação em torno do eixo Z

### Zoom
- **+**: Aproximar
- **-**: Afastar

### Ajuste de Altitude
- **[**: Aumentar a escala de altura
- **]**: Diminuir a escala de altura

### Projeção
- **I**: Projeção isométrica
- **O**: Projeção ortográfica

### Outros
- **R**: Resetar para a visualização padrão
- **ESC**: Fechar o programa
- **/**: Mostrar/esconder painel de controles

## Formato do Mapa

Os mapas são representados como arquivos de texto em formato de grade, onde cada número representa um ponto no espaço 3D:
- A posição horizontal corresponde à coordenada X
- A posição vertical corresponde à coordenada Y
- O valor corresponde à coordenada Z (altura/elevação)

Valores hexadecimais opcionais após uma vírgula determinam a cor de cada ponto:

```
0  0  0  0  0  0  0  0  0  0
0 10,0xFF0000 10 10 10 10 10 10 10  0
0 10 10,0x00FF00 10 10 10 10 10 10  0
0 10 10 10,0x0000FF 10 10 10 10 10  0
0 10 10 10 10 10 10 10 10  0
0  0  0  0  0  0  0  0  0  0
```

## Implementação Técnica

### Componentes Principais

- **MiniLibX**: Uma API simples de programação X-Window usada para renderização
- **Sistema de Análise**: Parsing de arquivos robusto com tratamento de erros
- **Algoritmo de Linha de Bresenham**: Otimizado para desenhar linhas entre pontos
- **Transformações de Matriz**: Para rotações, escala e translações
- **Gradiente de Cor**: Interpolação entre pontos para transições suaves de cor

### Estrutura do Projeto

- **src/**: Arquivos fonte
  - **main.c**: Ponto de entrada
  - **scene.c**: Gerenciamento de cena 3D
  - **load_data.c**: Análise de arquivos de mapa
  - **draw_line.c**: Algoritmo de desenho de linha
  - **rotation.c**: Matemática de rotação 3D
  - **transform.c**: Transformações do modelo
  - **events.c**: Tratamento de entrada do usuário
  - **controls.c**: Controles de UI e legenda
- **include/**: Arquivos de cabeçalho
- **libft/**: Biblioteca C personalizada com funções utilitárias
- **maps/**: Arquivos de mapa de exemplo

## Compilação

O projeto compila com as seguintes flags:
```
-Wall -Wextra -Werror -O3
```

E é vinculado a:
```
-lmlx -lXext -lX11 -lm
```

## Desenvolvido por
Marcelo Magalhães (mdias-ma) - 42 São Paulo
