## Pipex

**Pipex** es un proyecto desarrollado en 42 Madrid que explora el manejo de pipes en UNIX. Su objetivo es implementar un programa en C que replique el comportamiento de una secuencia de comandos de shell usando redirección y tuberías.

![Logo 42 Madrid](42-Madrid.jpeg)

### Descripción del Proyecto

El programa ejecuta comandos encadenados utilizando pipes, simulando la siguiente estructura:
```bash
< archivo1 comando1 | comando2 > archivo2
```

#### Características Principales

- **Encadenamiento de procesos:** Ejecuta dos comandos conectados mediante pipes.
- **Manejo de errores:** Gestión cuidadosa de fallos en llamadas del sistema y validación de parámetros.
- **Ampliabilidad:** Soporte para múltiples comandos en la parte bonus.

### Archivos Incluidos

- `pipex.c`: Contiene la lógica principal del programa.
- `execute_commands.c`: Implementa la ejecución de comandos y búsqueda de ejecutables.
- `handle_errors.c`: Gestión centralizada de errores.
- `pipex.h`: Prototipos y definiciones necesarias.
- `Makefile`: Compila el proyecto y gestiona reglas como `all`, `clean`, `fclean`, `re`.

### Cómo Usarlo

1. **Compilación:**
   Utiliza el siguiente comando para compilar:
   ```bash
   make
   ```

2. **Ejecución:**
   Llama al programa con los argumentos necesarios:
   ```bash
   ./pipex archivo1 "comando1" "comando2" archivo2
   ```
   Ejemplo:
   ```bash
   ./pipex infile "ls -l" "wc -l" outfile
   ```
   Este comando realiza lo mismo que:
   ```bash
   < infile ls -l | wc -l > outfile
   ```

### Funciones Permitidas

El proyecto permite el uso de las siguientes funciones estándar de UNIX:
- `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`.

### Aclaración

Este proyecto sigue los estándares de la **Norma de 42**.
