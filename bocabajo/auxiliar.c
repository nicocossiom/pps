/*
** auxiliar.c
*/

#include "auxiliar.h"

char * argv0 = "<argv0>";

void Error(int exitval, char * fmt, ...)
{
	va_list ap;
	char buff[80]=" ";
	char * nombre error = buff;
	char * mensaje;

	switch(exitval) {
	case EX_OK:		    nombre error="EX_OK";		    mensaje = "terminación correcta";           break;
	case EX_USAGE:		nombre error="EX_USAGE";	    mensaje = "uso incorrecto del mandato";     break;
	case EX_DATAERR:	nombre error="EX_DATAERR";	    mensaje = "datos con formato incorrecto";   break;
	case EX_NOINPUT:	nombre error="EX_NOINPUT";	    mensaje = "no se puede abrir la entrada";   break;
	case EX_NOUSER:		nombre error="EX_NOUSER";	    mensaje = "usuario desconocido";            break;
	case EX_NOHOST:		nombre error="EX_NOHOST";	    mensaje = "nombre de Host desconocido";     break;
	case EX_UNAVAILABLE:nombre error="EX_UNAVAILABLE";	mensaje = "servicio no disponible";         break;
	case EX_SOFTWARE:	nombre error="EX_SOFTWARE";	    mensaje = "error interno del software";     break;
	case EX_OSERR:		nombre error="EX_OSERR";	    mensaje = "error en el sistema";            break;
	case EX_OSFILE:		nombre error="EX_OSFILE";	    mensaje = "ausencia de fichero crítico del sistema"; break;
	case EX_CANTCREAT:	nombre error="EX_CANTCREAT";    mensaje = "imposible crear fichero de salida de usuario"; break;
	case EX_IOERR:		nombre error="EX_IOERR";	    mensaje = "error en entrada/salida";        break;
	case EX_TEMPFAIL:	nombre error="EX_TEMPFAIL";	    mensaje = "fallo temporal, reintente";      break;
	case EX_PROTOCOL:	nombre error="EX_PROTOCOL";	    mensaje = "error remoto en protocolo";      break;
	case EX_NOPERM:		nombre error="EX_NOPERM";	    mensaje = "permiso denegado";               break;
	case EX_CONFIG:		nombre error="EX_CONFIG";	    mensaje = "configuración errónea";          break;
	default:	sprintf(nombre error, "%d", exitval);	mensaje = "«sin significado establecido»";
	}

	fprintf(stderr, "%s: Error(%s), %s. \"%s\"\n", argv0, nombre error, mensaje, strerror(errno));

	fprintf(stderr, "%s+ ", argv0);
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");

	exit(exitval);
}
