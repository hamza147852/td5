#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Etudiant {
private:
    static int compteurMatricule;
    int matricule;
    string nom;
    int nbrNotes;
    float* tabNotes;

public:

    Etudiant() : matricule(++compteurMatricule), nom(""), nbrNotes(0), tabNotes(nullptr) {}


    Etudiant(string nom, int nbrNotes) : matricule(++compteurMatricule), nom(nom), nbrNotes(nbrNotes) {
        tabNotes = new float[nbrNotes];
    }


    ~Etudiant() {
        delete[] tabNotes;
    }

    Etudiant(const Etudiant& other) : matricule(++compteurMatricule), nom(other.nom), nbrNotes(other.nbrNotes) {
        tabNotes = new float[nbrNotes];
        for (int i = 0; i < nbrNotes; i++) {
            tabNotes[i] = other.tabNotes[i];
        }
    }


    int getMatricule() const { return matricule; }
    string getNom() const { return nom; }
    void setNom(const string& nom) { this->nom = nom; }

    int getNbrNotes() const { return nbrNotes; }
    void setNbrNotes(int nbrNotes) {
        delete[] tabNotes;
        this->nbrNotes = nbrNotes;
        tabNotes = new float[nbrNotes];
    }


    void saisie() {
        cout << "Entrez les notes pour " << nom << " (" << nbrNotes << " notes) :\n";
        for (int i = 0; i < nbrNotes; i++) {
            cout << "Note " << i + 1 << ": ";
            cin >> tabNotes[i];
        }
    }


    void affichage() const {
        cout << "Matricule: " << matricule << "\n";
        cout << "Nom: " << nom << "\n";
        cout << "Notes: ";
        for (int i = 0; i < nbrNotes; i++) {
            cout << fixed << setprecision(2) << tabNotes[i] << " ";
        }
        cout << "\nMoyenne: " << fixed << setprecision(2) << moyenne() << "\n";
        cout << (admis() ? "Admis\n" : "Non Admis\n");
    }


    float moyenne() const {
        if (nbrNotes == 0) return 0.0;
        float sum = 0.0;
        for (int i = 0; i < nbrNotes; i++) {
            sum += tabNotes[i];
        }
        return sum / nbrNotes;
    }


    bool admis() const {
        return moyenne() >= 10.0;
    }


    static bool comparer(const Etudiant& e1, const Etudiant& e2) {
        return e1.moyenne() == e2.moyenne();
    }
};

int Etudiant::compteurMatricule = 0;

int main() {

    Etudiant e1("Alice", 3);
    e1.saisie();

    Etudiant e2("Bob", 3);
    e2.saisie();

    e1.affichage();
    e2.affichage();

    cout << "Les deux étudiants ont la même moyenne: " << (Etudiant::comparer(e1, e2) ? "Oui" : "Non") << "\n";

    return 0;
}
