#!/usr/bin/env python
 
import sys
import time
sys.path.append('../gen-py')
 
from Key_Value_Database_Service import *
 
from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
 
try:
	# Make socket
	transport = TSocket.TSocket('localhost', 9090)

	# Buffering is critical. Raw sockets are very slow
	transport = TTransport.TBufferedTransport(transport)

	# Wrap in a protocol
	protocol = TBinaryProtocol.TBinaryProtocol(transport)

	# Create a client to use the protocol encoder
	client = Client(protocol)

	# Connect!
	transport.open()

	print "conectado"
	#-----------------------------------------------------------
	exitFlag = False
	entrada= ''
	command = None
	delimiter = ' '
	key= 0
	while(not exitFlag):
		entrada = raw_input(">>")
		input_split = entrada.split(delimiter)
		if len(input_split) == 0:
			continue

		command = input_split[0]
		try:
			if command  == "get" and not(input_split[1] == "") :
				key = int(input_split[1])
				print(client.get(key))
			elif command =="put" and  not(input_split[1] ==""):
				key = int(input_split[1])
				name= ""
				apellido= ""
				edad = 0
				seleccion = 0
				ciudad= City()
				name = raw_input("Ingrese el nombre: ")
				apellido = raw_input("Ingrese el apellido: ")
				while (edad == 0):
					try:
						edad = int(raw_input("Ingrese la edad: "))
					except ValueError :
						print("Error ingrese un numero entero ")
					
				
				while seleccion == 0:
					try:
						print (str("1.")+str("GUAYAQUIL")+"\n"+ str("2.")+str("QUITO")+"\n"+str("3.")+str("CUENCA")+"\n"+str("4.")+str("AMBATO"))
						seleccion = int(raw_input("Ingrese el numero de la ciudad: "))
						if seleccion == 1:
							ciudad = City.QUITO
						elif seleccion == 2:
							ciudad = City.GUAYAQUIL
						elif seleccion == 3:
							ciudad = City.AMBATO
						elif seleccion == 4:
							ciudad = City.CUENCA
						
						if ciudad == None:
							print("Error ingrese el numero correspondiente de la ciudad ")
							seleccion = 0
					except ValueError:
						print("Error ingrese el numero correspondiente de la ciudad ")
				print name , apellido, edad , ciudad
				p=Person()
				p.name=name
				p.lastName=apellido
				p.age=edad
				p.city = ciudad
				client.put(key, p)
			elif command == "list":
				for i in client.list_values():
					print i
			elif command =="delete" and not(input_split[1] ==""):
				key = int(input_split[1])
				client.delete_value(key)
			elif command =="close":
				exitFlag = True
			else :
				print("Error comando invalido")
		except :
  			print("Error comando invalido") 
		
	time.sleep(3)
	transport.close()
 
except Thrift.TException, tx:
  print "%s" % (tx.message)
