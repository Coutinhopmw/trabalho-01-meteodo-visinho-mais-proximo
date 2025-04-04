# Passo a passo OpenCV

## 1) Verificar se o path está configurado para a bin e a lib (ambos User e sistema)

### Exemplo:
- `C:\Users\juedu\Documents\opencv\build\x64\vc16\bin`
- `C:\Users\juedu\Documents\opencv\build\x64\vc16\lib`

## 2) Criar projeto em branco

Crie um projeto vazio com C++.

### Configuração do projeto:
1. Acesse as seguintes abas:
   - **Projeto -> Propriedades -> Propriedade de Configuração -> Versão SDK do Windows**
     - Adicione a versão mais recente (atualmente `10.0.22621.0`).
   - **Projeto -> Propriedades -> Diretórios C/C++ -> Diretórios de Inclusão**
     - Adicione o diretório `INCLUDE`.
   - **Projeto -> Propriedades -> Vinculador -> Entrada -> Dependências Adicionais**
     - Adicione `opencv_world480d.lib` e `opencv_world480.lib`.

## 3) Criar o arquivo `main.cpp`

Clique com o botão direito no projeto e selecione **Adicionar -> Novo Item**.

## 4) Compilar e rodar

1. Clique em **Compilação** ao lado de **Projeto -> Compilar Solução**.
2. Clique em **Depurador Local do Windows**.

### Prontinho!

## Bibliotecas adicionais caso não dê certo

Se houver problemas, instale bibliotecas adicionais:
- Acesse **Ferramentas -> Obter ferramentas e funcionalidades... -> Componentes Individuais**.
- Instale:
  - **SDK do Windows 11**
  - **Debug para C++**

