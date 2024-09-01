# Lista todos los archivos .c en el directorio
SRC = $(wildcard *.c)

# Cambia la extensión .c por .o para obtener los archivos objeto
OBJ = $(SRC:.c=.o)

# Target principal
all: buscar

# Regla para compilar el ejecutable
buscar: $(OBJ)
	gcc -o $@ $^

# Regla genérica para compilar los archivos .o
%.o: %.c
	gcc -c -o $@ $<

# Limpieza de archivos
clean:
	rm -rf *.o buscar docs

# Generar documentación con Doxygen
doc:
	doxygen

# Abrir la documentación en el navegador
browsedoc: doc
	microsoft-edge-stable docs/html/index.html

# Instalar el paquete 
install_static: 
	gcc -c -o buscar.o search.c
	ar rcs libbuscar.a buscar.o
	sudo mv libbuscar.a /usr/local/lib
install_dinamic:
	gcc -c -fPIC -o buscar.o search.c
	gcc -shared -o libbuscar.so.1.0 buscar.o
	sudo mv libbuscar.so.1.0 /usr/local/lib
	sudo ln -s /usr/local/lib/libbuscar.so.1.0 /usr/local/lib/libbuscar.so.1
	sudo ln -s /usr/local/lib/libbuscar.so.1 /usr/local/lib/libbuscar.so
# Desinstalar el paquete
uninstall_static:
	sudo rm -f /usr/local/lib/libbuscar.a
uninstall_dinamic:
	sudo rm -f /usr/local/lib/libbuscar.so.1.0
	sudo rm -f /usr/local/lib/libbuscar.so.1
	sudo rm -f /usr/local/lib/libbuscar.so

# Compilar el programa desde la libreria creada
static:
	gcc -o buscar main.c -lbuscar
#gcc -c -o main.o main.c Verificamos que el codigo este bien en sintaxis
#gcc -o buscar main.o Crea el ejecutable apartir de los archivos objeto

#una regla es un aarchivo que existe o deberia de existir o otra regla o los dos