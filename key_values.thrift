
/*
 *  Namespace of languages that the program will be implemented
 */
namespace java key_value_database
namespace py key_value_database
namespace go key_value_database
namespace js key_value_database

enum City{

	GUAYAQUIL = 1,
	QUITO = 2,
	CUENCA = 3,
	AMBATO = 4	
}

struct Person{

	1: string name,
	2: string lastName,
	3: i32 age,
	4: City city,

}

service Key_Value_Database_Service{
	
	Person get(1:i32 key),

	void put(1:i32 key , 2:Person value),

	list<Person> list_values(),

	void delete_value(1:i32 key)

}