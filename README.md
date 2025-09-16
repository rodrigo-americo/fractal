# fract-ol 🎨🌀

Projeto da 42 para explorar **fractais** em C usando a **MiniLibX**.

---

## 📌 Objetivo
Implementar um programa que renderiza diferentes fractais interativos:
- **Mandelbrot**
- **Julia**
- **Burning Ship** (bônus)

O usuário pode navegar, aplicar zoom e trocar paletas de cor em tempo real.

---

## 🚀 Como compilar

### Pré-requisitos
- Linux (ou WSL2)  
- `make`, `gcc/clang`  
- Bibliotecas X11:  
  ```bash
  sudo apt-get install gcc make xorg libxext-dev libx11-dev zlib1g-dev
  ```

### Compilar o projeto
```bash
make        # versão obrigatória
make bonus  # versão bônus (com Burning Ship, cores extras, etc.)
make clean  # remove objetos
make fclean # remove objetos e binário
make re     # recompila do zero
```

### Modos adicionais (apenas local)
```bash
make release # compila otimizado (-O3)
make debug   # compila com debug e sanitizers
```

---

## 🖥️ Como usar
```bash
./fractol mandelbrot [width height]
./fractol julia <c_re> <c_im> [width height]
./fractol ship [width height]
```

### Exemplos
```bash
./fractol mandelbrot
./fractol julia -0.8 0.156
./fractol ship 1920 1080
```

---

## 🎮 Controles

| Tecla / Ação   | Função                          |
|----------------|---------------------------------|
| `ESC`          | Sair                            |
| `← ↑ ↓ →`      | Mover a viewport                |
| Scroll (mouse) | Zoom in / Zoom out no cursor    |
| `Espaço`       | Troca paleta de cores           |

---

## 🌈 Funcionalidades bônus
- Burning Ship fractal  
- Paletas de cor alternáveis  
- Smooth coloring (cores contínuas)  
- Zoom dinâmico ajusta automaticamente as iterações  
- Estrutura organizada em **mandatory** e **bonus**

---

## 📂 Estrutura
```
.
├── include/          # headers (frac.h, etc.)
├── libft/            # biblioteca de funções C (projeto 42)
├── printf/           # ft_printf
├── minilibx-linux/   # MiniLibX (gráficos)
├── src/
│   ├── mandatory/    # arquivos obrigatórios
│   └── bonus/        # arquivos bônus
└── Makefile
```

---

## 📖 Teoria rápida
- **Mandelbrot**: `z0 = 0`, `c = pixel`  
- **Julia**: `z0 = pixel`, `c = constante`  
- **Burning Ship**: `z0 = 0`, mas `Re/Im` com valor absoluto antes do quadrado  
- Escape se `|z|² > 4`  
- Smooth coloring: `nu = iters + 1 - log2(log(sqrt(z²)))`

---

## ✨ Créditos
Projeto implementado como parte do currículo da **42**.  
Desenvolvido por [Seu Nome].
