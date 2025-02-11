# Tic-Tac-Toe cu AI (XO Game)

Acesta este un joc de Tic-Tac-Toe (sau XO), implementat folosind C++ și framework-ul Qt. Jocul permite un jucător să joace împotriva unui AI simplu care folosește algoritmul Minimax pentru a face mutări optimizate. Acest joc are o interfață grafică realizată cu Qt, care permite jucătorilor să joace pe o tablă 3x3.

## Caracteristici

- **Joc cu un singur jucător**: Jucătorul joacă împotriva unui AI.
- **Algoritmul Minimax pentru AI**: AI-ul folosește un algoritm de căutare recursivă pentru a calcula cele mai bune mutări.
- **Interfață grafică cu Qt**: Folosind Qt Creator, interfața grafică permite interacțiunea ușoară cu jocul.
- **Joc pentru 2 jucători** (posibil de extins pentru modul 2 jucători pe aceeași mașină).
- **Funcție de resetare**: Posibilitatea de a reseta jocul pentru a începe o nouă rundă.
- **Validarea mutărilor**: Nu sunt permise mutările într-o locație deja ocupată.

## Cum să rulezi jocul

Pentru a rula acest joc, trebuie să ai instalat:
- [Qt Creator](https://www.qt.io/download)
- Un compilator C++ compatibil cu Qt (de exemplu, MinGW pe Windows, sau GCC pe Linux/macOS)
