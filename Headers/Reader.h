//
// Created by mavros on 3/5/21.
//

#ifndef C_TEXT_EDITOR_READER_H
#define C_TEXT_EDITOR_READER_H


#include <string>

/**
 * Interpreta los objetos creados en el editor de texto línea por línea
 */
class Reader {

private:

    /**
     * Línea escaneada del editor de texto
     */
    std::vector<std::string> TextEditorLine;

    /**
     * Array con el nombre de los tipos de texto compatibles
     */
    const std::string typeArray[5] = {"char", "int", "long", "float", "double"};

//    std::string type;
//    std::string name;
//    std::string value;
//    int scope;
//    int references;

public:

    /**
     * Al construir el objeto, le añade 3 espacios vacíos al vector que lee línea por línea, ya que el código espera que
     * el vector siempre contenga 3 strings o más.
     */
    Reader();

    /**
     * Elimina el Reader
     */
    virtual ~Reader();

    /**
     * Divide la línea del editor de texto en 3 partes: primera palabra, cuerpo y última palabra Luego lo integra a un
     * vector
     * @param inStr Línea del editor de texto
     */
    void strSplitter(std::string inStr);

    /**
     * Confirma si la primera palabra en el vector es un tipo válido y si el valor del último elemento del vector
     * coincide con el tipo
     */
    void confirmType();

    /**
     * Si el objeto es un número, elimina los ceros a la izquierda y define los elementos que se pueden ingresar después
     * de la coma en un float o un double.
     * @param data Valor del objeto (número)
     */
    void deleteZeroes(const std::string &data);

    /**
     * Etiqueta el tipo de dato, su nombre y el valor de cada objeto que se ingrese en cada línea para mostrarlo en el
     * RAM Live View, Si no es un objeto válido, muestra un error en el StdOut y el Applog
     * @param isType Verifica si la línea es un objeto válido o no
     */
    void labelObject(bool isType);

    /**
     * retorna el vector con el contenido de la línea del editor de texto
     * @return Vector
     */
    const std::vector<std::string> &getStringVector() const;
};


#endif //C_TEXT_EDITOR_READER_H
