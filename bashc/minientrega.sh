#! /bin/bash
if  [ $# == 1 ] then
    echo "No se han recibido argumentos, si necesita ayuda ejecute ./minientregas -h"
    exit 0
elif [ "$1" == "-help" ] || ["$1" == "-h"] then 
        echo "minientrega.sh: Uso: <<Recibe un ID asociado con una práctica como argumento>> \n 
        minientrega.sh: <<El programa comprobará que existen todos los ficheros relacionados con la práctica ascioada al ID
        si es el caso copiará dichos archivos a la carpeta de entrega correspondiente>>"
        exit 0
        
else
    if [ ! -d "$MINIENTREGA_CONF" ] then   
    printf "no es accesible el directorio: %s , especificado en la variable de entorno" "$MINIENTREGA_CONF"
    fi 
fi