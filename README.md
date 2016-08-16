# SistDistribProyCache
Proyecto de la materia Sistemas Distribuidos ESPOL, FIEC año 2016 Primer Término
## Servidor (JAVA)
Para poder correr el servidor solo es necesario ejecutar el comando **"java -jar KeyValueServer.jar -port -type"**, en donde **-port** es el puerto de escucha del servidor mientras que **-type** es un parámetro opcional, al enviarle **simple** se levantará un servidor simple bloqueante mientras que si no setea este parámetro se levantará un servidor multihilo.

## Cliente
### JAVA
Para el caso del cliente en JAVA solo es necesario ejecutar el comando **"java -jar KeyValueClient.jar -ip -port"**.

### PYTHON
Primero se deberá instalar el módulo thrift con **"pip install thrift"**, para luego ejecutar el comando **"python clientePython.py"**.

### C# 
Para poder ejecutar el archivo **cliente.exe** del cliente en C# se puede utilizar [monodevelop](http://www.monodevelop.com/download/linux/)
y luego ejecutarlo mediante: **"mono cliente.exe"**


##Notas
Los archivos necesarios para la ejecución se encuentran en los subdirectorios correspondientes de la carpeta exe.

Los comandos disponibles son los siguientes:
* Put numero_persona  se reemplazaran los valores  de la persona que se selecciona.
* Get numero_persona se mostraran los datos de la persona que se selecciona.
* List se mostrara la lista de las personas que han sido registradas.
* Delete numero_persona se eliminara la persona que se selecciona.