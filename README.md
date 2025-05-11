## Pipex

**Pipex** es un proyecto desarrollado en 42 Madrid que explora el manejo de *pipes* en UNIX. Su objetivo es implementar un programa en C que replique el comportamiento de una secuencia de comandos de shell utilizando redirección y tuberías.

![Logo 42 Madrid](42-Madrid.jpeg)

### Descripción del Proyecto

El programa ejecuta comandos encadenados mediante pipes, simulando estructuras de shell como:

```bash
< archivo1 comando1 | comando2 > archivo2
```

En la versión bonus, también se soportan múltiples comandos:

```bash
< archivo1 comando1 | comando2 | ... | comandoN > archivo2
```

Y la redirección `here_doc`:

```bash
./pipex here_doc LIMITADOR comando1 comando2 archivo
```

Que se comporta como:

```bash
comando1 << LIMITADOR | comando2 >> archivo
```

---

### Características Principales

* ✅ **Encadenamiento de procesos:** ejecución de múltiples comandos enlazados por pipes.
* ✅ **Redirección de entrada/salida:** soporte para `<`, `>`, `>>`, y `<<`.
* ✅ **here\_doc:** simula la funcionalidad `<<` de shell.
* ✅ **Manejo de errores robusto:** evita fugas de memoria, segmentation faults y errores silenciosos.
* ✅ **Validación de comandos vacíos o inexistentes.**
* ✅ **Código modular y organizado por funcionalidades.**

---

### Archivos Incluidos

* `pipex.c`: Lógica principal, parsing y entrada al programa.
* `execute_commands.c`: Ejecución de múltiples comandos y control de procesos.
* `exec_child.c`: Lógica de procesos hijos y redirección de pipes.
* `files.c`: Manejo de archivos de entrada/salida.
* `heredoc.c`: Implementación de la funcionalidad `here_doc`.
* `find_path.c`: Búsqueda de rutas de ejecutables en el entorno.
* `manage_parser.c`: Gestión de la estructura de comandos.
* `frees.c`: Liberación de memoria y recursos.
* `utils.c`: Funciones auxiliares.
* `pipex.h`: Definiciones y prototipos.
* `Makefile`: Compilación del proyecto.

---

### Cómo Usarlo

#### 1. Compilación

```bash
make
```

#### 2. Ejecución básica

```bash
./pipex archivo1 "comando1" "comando2" archivo2
```

Ejemplo:

```bash
./pipex infile "ls -l" "wc -l" outfile
```

#### 3. Ejecución con múltiples comandos (bonus)

```bash
./pipex archivo1 "cmd1" "cmd2" "cmd3" ... archivo2
```

#### 4. Ejecución con here\_doc (bonus)

```bash
./pipex here_doc LIMITADOR "cmd1" "cmd2" archivo
```

---

### Funciones Permitidas

* `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`
* `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`
* (Además puedes usar tu propia `libft`)

---

### Requisitos

* Sin fugas de memoria.
* Sin errores inesperados (segfaults, double free, etc.).
* Norminette.
* Redirección y ejecución precisa como en shell real.
