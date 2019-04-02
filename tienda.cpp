//Practica de recuperación */
//Esta practica es válida como recuperación de la práctica 3 del semestre 2018_2 */
// Si usted decide realizar esta práctica entoces su nota final en la práctica 3
//será la que obtenga en esta misma práctica de recuperación */

//1. Diseñe e implemente una aplicación de "Carrito de compras on-line". Para esto usted debe implementar
//  una clase llamada Articulo, esta clase debe tener metodos para ingresar y obtener el nombre del Articulo,
//  metodos para ingresar y obtener el precio del articulo, metodos para ingresar y obtener el tipo de Articulo
 // (Aseo, Ddeportivo, Hogar, etc...). Debe contar tambien con metodos para fijar un descuento al precio del
 // articulo, metodos para ingresar y obtener la disponiblidad de inventario del articulo. El carrito de compras
 // debe ser un vector (arreglo) de objetos de tipo Articulo. La aplicación debe tener un menu que permita ingresar
 // una lista de articulos a la tienda (el inventario de la tienda). Debe contar con una opción para agregar articulos
 // al carrito de compra. Y por último una opción que debe calcular la factura de compra calculando los descuentos
 // correspondientes de cada artículo.


#include <iostream>

using namespace std;

class Articulo{
private:
    string nombre;
    int cantidad;
    int precioUnidad;
    bool temporada;
    bool promoxdocena;
public:
    Articulo(string _nombre, int precio){
        nombre=_nombre;
        cantidad=1;
        temporada=false;
        promoxdocena=false;
        precioUnidad=precio;
    }

    Articulo(string _nombre, int precio, int _cant, bool _tem=false){
        nombre=_nombre;
        cantidad=_cant;
        temporada=_tem;
        precioUnidad=precio;
        if(temporada)
            precioUnidad=precioUnidad/3;
        if(cantidad%12==0)
            precioUnidad=precioUnidad/2;
    }

    Articulo(string _nombre, int precio, bool _temp){
        nombre=_nombre;
        cantidad=12;
        temporada=_temp;

        promoxdocena=true;
        if(temporada){
            precioUnidad=precio/2;
        }else
            precioUnidad=precio;
    }

    void imprimirOrden(){
        cout<<"Usted esta comprando"<<endl;
        cout<<"Articulo: "<<this->nombre<<endl;
        cout<<"Cantidad: "<<this->cantidad<<endl;
        if(temporada){
            cout<<"Es es un Articulo de temporada "<<endl;

        }else{
            cout<<"No es una Articulo de temporada "<<endl;
        }
        cout<<"Total:"<<precioUnidad*cantidad<<endl;
        cout<<"Gracias por su compra, vuelva pronto"<<endl;
    }
};

void compraArticulo(void){
    Articulo *miArticulo=nullptr;
    cout<<"Escoja una opcion"<<endl;
    cout<<"1. Comprar Articulo normal"<<endl;
    cout<<"2. Comprar Articulo temporada x cantidad"<<endl;
    cout<<"3. Comprar promocion x 12 unidades"<<endl;
    int opcion;
    cin>>opcion;
    int valor;
    string nombre;

    switch (opcion) {
        case 1:

            cout<<"Ingrese el nombre"<<endl;
            cin>>nombre;
            cout<<"Ingrese el valor"<<endl;
            cin>>valor;
            miArticulo= new Articulo(nombre,valor);
            miArticulo->imprimirOrden();
            delete miArticulo;
            miArticulo=nullptr;

            break;
        case 2:
            cout<<"Ingrese el nombre"<<endl;
            cin>>nombre;
            cout<<"Ingrese el valor"<<endl;
            cin>>valor;
            int cant;
            cout<<"Ingrese la cantidad a comprar"<<endl;
            cin>>cant;
            miArticulo= new Articulo(nombre,valor,cant,true);
            miArticulo->imprimirOrden();
            delete miArticulo;
            miArticulo=nullptr;
            break;
        case 3:
            cout<<"Ingrese el nombre"<<endl;
            cin>>nombre;
            cout<<"Ingrese el valor"<<endl;
            cin>>valor;
            int temp;
            cout<<"Ingrese 1 producto de tempora o 2 si no es producto de temporada"<<endl;
            cin>>temp;
            bool prodTemP=false;
            if(temp==1){
                prodTemP=true;
            }
            miArticulo= new Articulo(nombre,valor,prodTemP);
            miArticulo->imprimirOrden();
            delete miArticulo;
            miArticulo=nullptr;
            break;
    }
}

class Aseo{


private:
    string nombre;
    int cantidad;
    int precioUnidad;
    bool temporada;
    bool promoxdocena;
public:
    Aseo(string _nombre, int precio){
        nombre=_nombre;
        cantidad=1;
        temporada=false;
        promoxdocena=false;
        precioUnidad=precio;
    }

    Aseo(string _nombre, int precio, int _cant, bool _tem=false){
        nombre=_nombre;
        cantidad=_cant;
        temporada=_tem;
        precioUnidad=precio;
        if(temporada)
            precioUnidad=precioUnidad/3;
        if(cantidad%12==0)
            precioUnidad=precioUnidad/2;
    }

    Aseo(string _nombre, int precio, bool _temp){
        nombre=_nombre;
        cantidad=12;
        temporada=_temp;

        promoxdocena=true;
        if(temporada){
            precioUnidad=precio/2;
        }else
            precioUnidad=precio;
    }

    void imprimirOrden(){
        cout<<"Usted esta comprando"<<endl;
        cout<<"Aseo: "<<this->nombre<<endl;
        cout<<"Cantidad: "<<this->cantidad<<endl;
        if(temporada){
            cout<<"Es es un Articulo de Aseo de temporada "<<endl;

        }else{
            cout<<"No es una Articulo de Aseo de temporada "<<endl;
        }
        cout<<"Total:"<<precioUnidad*cantidad<<endl;
        cout<<"Gracias por su compra, vuelva pronto"<<endl;
    }
};

void compraAseo(void){
    Aseo *miAseo=nullptr;
    cout<<"Escoja una opcion"<<endl;
    cout<<"1. Comprar productos de Aseo normal"<<endl;
    cout<<"2. Comprar productos de Aseo temporada x cantidad"<<endl;
    cout<<"3. Comprar promocion de Aseo x 12 unidades"<<endl;
    int opcion;
    cin>>opcion;
    int valor;
    string nombre;

    switch (opcion) {
        case 1:

            cout<<"Ingrese el nombre"<<endl;
            cin>>nombre;
            cout<<"Ingrese el valor"<<endl;
            cin>>valor;
            miAseo= new Aseo(nombre,valor);
            miAseo->imprimirOrden();
            delete miAseo;
            miAseo=nullptr;

            break;
        case 2:
            cout<<"Ingrese el nombre"<<endl;
            cin>>nombre;
            cout<<"Ingrese el valor"<<endl;
            cin>>valor;
            int cant;
            cout<<"Ingrese la cantidad a comprar"<<endl;
            cin>>cant;
            miAseo= new Aseo(nombre,valor,cant,true);
            miAseo->imprimirOrden();
            delete miAseo;
            miAseo=nullptr;
            break;
        case 3:
            cout<<"Ingrese el nombre"<<endl;
            cin>>nombre;
            cout<<"Ingrese el valor"<<endl;
            cin>>valor;
            int temp;
            cout<<"Ingrese 1 producto de tempora o 2 si no es producto de temporada"<<endl;
            cin>>temp;
            bool prodTemP=false;
            if(temp==1){
                prodTemP=true;
            }
            miAseo= new Aseo(nombre,valor,prodTemP);
            miAseo->imprimirOrden();
            delete miAseo;
            miAseo=nullptr;
            break;
    }


};

class Hogar{

private:
    string nombre;
    int cantidad;
    int precioUnidad;
    bool temporada;
    bool promoxdocena;
public:
    Hogar(string _nombre, int precio){
        nombre=_nombre;
        cantidad=1;
        temporada=false;
        promoxdocena=false;
        precioUnidad=precio;
    }

    Hogar(string _nombre, int precio, int _cant, bool _tem=false){
        nombre=_nombre;
        cantidad=_cant;
        temporada=_tem;
        precioUnidad=precio;
        if(temporada)
            precioUnidad=precioUnidad/3;
        if(cantidad%12==0)
            precioUnidad=precioUnidad/2;
    }

    Hogar(string _nombre, int precio, bool _temp){
        nombre=_nombre;
        cantidad=12;
        temporada=_temp;

        promoxdocena=true;
        if(temporada){
            precioUnidad=precio/2;
        }else
            precioUnidad=precio;
    }

    void imprimirOrden(){
        cout<<"Usted esta comprando"<<endl;
        cout<<"Hogar: "<<this->nombre<<endl;
        cout<<"Cantidad: "<<this->cantidad<<endl;
        if(temporada){
            cout<<"Es es un Articulo de Hogar de temporada "<<endl;

        }else{
            cout<<"No es una Articulo de Hogar de temporada "<<endl;
        }
        cout<<"Total:"<<precioUnidad*cantidad<<endl;
        cout<<"Gracias por su compra, vuelva pronto"<<endl;
    }
};

void compraHogar(void){
    Hogar *miHogar=nullptr;
    cout<<"Escoja una opcion"<<endl;
    cout<<"1. Comprar utencilios de Hogar normal"<<endl;
    cout<<"2. Comprar utencilios de Hogar temporada x cantidad"<<endl;
    cout<<"3. Comprar promocion de Hogar x 12 unidades"<<endl;
    int opcion;
    cin>>opcion;
    int valor;
    string nombre;

    switch (opcion) {
        case 1:

            cout<<"Ingrese el nombre"<<endl;
            cin>>nombre;
            cout<<"Ingrese el valor"<<endl;
            cin>>valor;
            miHogar= new Hogar(nombre,valor);
            miHogar->imprimirOrden();
            delete miHogar;
            miHogar=nullptr;

            break;
        case 2:
            cout<<"Ingrese el nombre"<<endl;
            cin>>nombre;
            cout<<"Ingrese el valor"<<endl;
            cin>>valor;
            int cant;
            cout<<"Ingrese la cantidad a comprar"<<endl;
            cin>>cant;
            miHogar= new Hogar(nombre,valor,cant,true);
            miHogar->imprimirOrden();
            delete miHogar;
            miHogar=nullptr;
            break;
        case 3:
            cout<<"Ingrese el nombre"<<endl;
            cin>>nombre;
            cout<<"Ingrese el valor"<<endl;
            cin>>valor;
            int temp;
            cout<<"Ingrese 1 producto de tempora o 2 si no es producto de temporada"<<endl;
            cin>>temp;
            bool prodTemP=false;
            if(temp==1){
                prodTemP=true;
            }
            miHogar= new Hogar(nombre,valor,prodTemP);
            miHogar->imprimirOrden();
            delete miHogar;
            miHogar=nullptr;
            break;
    }

}





int main()
{
    int opcion;
    do{
    cout<<"Bienvenido al Carrito de compras on-line "<<endl;
    cout<<"que tipo deproductos desea comprar"<<endl;
    cout<<"1. Articulo"<<endl;
    cout<<"2. Aseo"<<endl;
    cout<<"3. Hogar"<<endl;
    cout<<"4. Salir"<<endl;

    cin>>opcion;

    if(opcion>=1 && opcion<=4){
        switch (opcion) {
            case 1:
                compraArticulo();
            break;
            case 2:
                compraAseo();
            break;
            case 3:
                compraHogar();
            break;

        }

    }else{
        cout<<"Producto no disponible"<<endl;
    }

    }while(opcion!=4);


    return 0;
}
