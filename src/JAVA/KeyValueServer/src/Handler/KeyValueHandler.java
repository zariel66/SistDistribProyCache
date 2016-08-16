/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Handler;

import java.util.HashMap;
import java.util.logging.Level;
import java.util.logging.Logger;
import apacheThrift.City;
import apacheThrift.Person;
import java.util.ArrayList;
import java.util.List;
import key_value_database.Key_Value_Database_Service;
import org.apache.thrift.TException;

/**
 *
 * @author ricardo
 */
public class KeyValueHandler implements Key_Value_Database_Service.Iface{
    
    /* Hashmap del cual se realizarán las operaciones */
    private HashMap<Integer,Person> tablePerson;
    
    public KeyValueHandler(){
        tablePerson = new HashMap<>();
        populateHashMap();
    }
    
    /* LLena con elementos el hashmap
    */
    public void populateHashMap(){
        Person p1 = new Person("Eduardo", "Vaca", 18, City.QUITO);
        Person p2 = new Person("Luis", "Chavez", 22, City.CUENCA);
        Person p3 = new Person("Domenica", "Garcia", 25, City.GUAYAQUIL);
        Person p4 = new Person("Franco", "Mira", 30, City.QUITO);
        Person p5 = new Person("Elena", "Torres", 40, City.AMBATO);
        
        tablePerson.put(1, p1);
        tablePerson.put(2, p2);
        tablePerson.put(3, p3);
        tablePerson.put(4, p4);
        tablePerson.put(5, p5);
    }
    
    /* Devuelve la persona dado un identificador
    */
    @Override
    public Person get(int key) throws TException {
        //sleep(1);
        Person p = tablePerson.get(key);
        if(p!=null){
            System.out.println("Response GET Petition... "+key+" "+p.name + " "+p.lastName);
            return p;
        }
        return null;
    }

    @Override
    public void put(int key, Person value) throws TException {
        //sleep(1);
        tablePerson.put(key, value);
        System.out.println("Response PUT Petition... "+key+value.name + " "+value.lastName);
        
    }

    @Override
    public List<Person> list_values() throws TException {
        //sleep(1);
        System.out.println("Response LIST Petition... "+tablePerson.values());
        List<Person> list = new ArrayList<>(tablePerson.values());
        return list;
    }

    @Override
    public void delete_value(int key) throws TException {
        //sleep(1);
        Person p = tablePerson.get(key);
        if(p!=null){
            tablePerson.remove(key);
            System.out.println("Response DELETE Petition... "+key+" "+p.name + " "+p.lastName);
        }
        
    }
    
    public void sleep(int seg){
        try {
            Thread.sleep(seg*1000);
        } catch (InterruptedException ex) {
            Logger.getLogger(KeyValueHandler.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
