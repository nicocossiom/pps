#! /bin/bash
if  [ $# != 1 ]; then
    echo "minientrega.sh: Error(EX_USAGE), uso incorrecto del mandato. \"Success\"" >&2
    echo "minientrega.sh+ Número de argumentos incorrecto" >&2
    exit 64
else 
    if [ $1 == "-help" ] || [ $1 == "-h" ]; then
        echo "minientrega.sh: Uso: $0 {nombre_archivo} o -h/--help para la ayuda"
        echo "minientrega.sh: Copia ficheros a entregar de un directorio a otro de entrega"
        exit 0
    fi
fi

if [ ! -d "$MINIENTREGA_CONF" ]; then   
    echo "minientrega.sh: Error, no se pudo realizar la entrega" >&2
    echo "minientrega.sh+ no es accesible el directorio \"$MINIENTREGA_CONF\"" >&2
    exit 64
fi

echo  "$MINIENTREGA_CONF/$1"

if [ ! -f "$MINIENTREGA_CONF/$1" ]; then
    echo "minientrega.sh: Error, no se pudo realizar la entrega" >&2
    echo "minientrega.sh+ no es accesible el fichero \"$1\"" >&2
    exit 66
fi    

#Cogemos las variavles de entorno dentro del fichero
source $MINIENTREGA_CONF/$1

for file in $MINIENTREGA_FICHEROS; do
    if [ ! -r "$file" ];
    echo "minientrega.sh: Error, no se pudo realizar la entrega" >&2
    echo "minientrega.sh+ no es accesible el fichero \"$1\"" >&2
    exit 66
    fi
done

if [ ! -w  $MINIENTREGA_DESTINO ]
