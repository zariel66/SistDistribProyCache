/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package apacheThrift;


import java.util.Map;
import java.util.HashMap;
import org.apache.thrift.TEnum;

public enum City implements org.apache.thrift.TEnum {
  GUAYAQUIL(1),
  QUITO(2),
  CUENCA(3),
  AMBATO(4);

  private final int value;

  private City(int value) {
    this.value = value;
  }

  /**
   * Get the integer value of this enum value, as defined in the Thrift IDL.
   */
  public int getValue() {
    return value;
  }

  /**
   * Find a the enum type by its integer value, as defined in the Thrift IDL.
   * @return null if the value is not found.
   */
  public static City findByValue(int value) { 
    switch (value) {
      case 1:
        return GUAYAQUIL;
      case 2:
        return QUITO;
      case 3:
        return CUENCA;
      case 4:
        return AMBATO;
      default:
        return null;
    }
  }
}
