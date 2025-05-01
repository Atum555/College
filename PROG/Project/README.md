# Programming project

## Group elements

-   up202307150 Ana Francisca Fontes Pacheco
-   up202306618 Cláudio Daniel Ferreira Meireles
-   up202307797 Vasco Vaz Vieira



## Accomplished tasks

-   Conseguimos rodar os testes todos com sucesso.

A nossa hierarquia é da forma:

```
                         SVGElement
                             |
    ____________________________________________________________
    |          |             |              |                  |
 Ellipse    PolyLine      PolyGon      GroupElement        UseElement
    |          |             |
 Circle      Line        Rectangle

```
-   SVGElement
Esta classe é a class base dos elementos.
Contem um ID e um vetor de transformações que estão associadas
aquele elemento.

-   Ellipse
Esta class representa ellipses.
Contem um raio, um centro e uma cor.

-   Circle
Esta class representa circulos.
Não acrescenta qualquer funcionalidade, é apenas uma interface.

-   PolyLine
Esta class representa conjuntos de linhas.
Contem um vetor de pontos que formam a figura e contem a cor da linha.

-   Line
Esta class representa uma única linha.
Não acrescenta funcionalidade, é apenas uma interface.

-   PolyGon
Esta class representa um poligono.
Contem um vetor de pontos e a cor.

-   Rectangle
Esta class representa um retangulo.
Não acrescenta funcionalidade, é apenas uma interface.

-   GroupElement
Esta class representa um grupo de elementos.
Contem um vetor de referencias para elementos.

-   UseElement
Esta class representa uma cópia de um outro elemento.
Contem uma referencia para um elemento.


-   Transform
Implementamos ainda uma class que representa uma transformação.
São atribuidos valores na sua criação e tem funções get.



Todas as classes que não são interfaces possuem uma função draw
e uma função copy. 

A função draw fazes uma cópia dos seus 
atributos, aplica-lhes as suas transformações e depois 
desenha a figura formada na imagem.

A função copy, cria um elemento do mesmo tipo, atribui-lhe
os seus valores e atribui-lhe a transformação base do elemento,
não copiando as transformações previamente herdadas, adicionando
ainda as novas transformações.


A nossa função de leitura do ficheiro (readSVG) interpreta o ficheiro
XML, vai buscar o primeiro filho do elemento `<svg>` e depois enquanto 
existirem vai chamando a função parseElement com todos os irmãos.

A função parseElement encarrega-se de interpretar um objeto XMLElement,
gerando um objeto SVGElement. Adiciona-lhe as transformações que recebe,
ou seja, que herda. Após isso adiciona-o à lista que recebeu. Caso
o elemento possuia um ID adiciona-o também à lista global que contem todos
os elementos com ID.

Temos ainda uma função transform que gera um objeto Transform a partir de
um objeto XMLElement. Estas são apenas aplicadas na hora do desenho, sem
nunca alterar os elementos em si.
