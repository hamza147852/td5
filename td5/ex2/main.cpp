#include <iostream>
#include <cmath>
using namespace std;

class Vecteur3D {
private:
    float x, y, z;

public:

    Vecteur3D(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    void affichage() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }


    Vecteur3D somme(const Vecteur3D& v) const {
        return Vecteur3D(x + v.x, y + v.y, z + v.z);
    }

    float produitScalaire(const Vecteur3D& v) const {
        return x * v.x + y * v.y + z * v.z;
    }


    bool coincide(const Vecteur3D& v) const {
        return x == v.x && y == v.y && z == v.z;
    }


    float norme() const {
        return sqrt(x * x + y * y + z * z);
    }

    Vecteur3D normaxValeur(const Vecteur3D& v) const {
        return (this->norme() >= v.norme()) ? *this : v;
    }

    Vecteur3D* normaxAdresse(const Vecteur3D* v) const {
        return (this->norme() >= v->norme()) ? const_cast<Vecteur3D*>(this) : const_cast<Vecteur3D*>(v);
    }


    Vecteur3D& normaxReference(Vecteur3D& v) const {
        return (this->norme() >= v.norme()) ? const_cast<Vecteur3D&>(*this) : v;
    }
};

int main() {

    Vecteur3D v1(3, 4, 0);
    Vecteur3D v2(1, 2, 2);


    cout << "Vecteur 1 : ";
    v1.affichage();
    cout << "Vecteur 2 : ";
    v2.affichage();


    Vecteur3D somme = v1.somme(v2);
    cout << "Somme : ";
    somme.affichage();


    cout << "Produit scalaire : " << v1.produitScalaire(v2) << endl;


    cout << "Les vecteurs coïncident : " << (v1.coincide(v2) ? "Oui" : "Non") << endl;


    cout << "Norme de Vecteur 1 : " << v1.norme() << endl;
    cout << "Norme de Vecteur 2 : " << v2.norme() << endl;


    cout << "Normax par valeur : ";
    v1.normaxValeur(v2).affichage();

    cout << "Normax par adresse : ";
    v1.normaxAdresse(&v2)->affichage();

    cout << "Normax par référence : ";
    v1.normaxReference(v2).affichage();

    return 0;
}
