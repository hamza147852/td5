#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    float x, y;

public:

    Point(float x = 0, float y = 0) : x(x), y(y) {}


    Point(const Point& p) : x(p.x), y(p.y) {}


    void affiche() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }


    float getX() const { return x; }
    float getY() const { return y; }
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }


    friend bool comparer(const Point& p1, const Point& p2);


    friend float distance(const Point& p1, const Point& p2);


    friend Point milieu(const Point& p1, const Point& p2);
};


bool comparer(const Point& p1, const Point& p2) {
    return (p1.x == p2.x && p1.y == p2.y);
}


float distance(const Point& p1, const Point& p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}


Point milieu(const Point& p1, const Point& p2) {
    return Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
}

class Cercle {
private:
    float rayon;
    Point centre;

public:

    Cercle(float r, const Point& c) : rayon(r), centre(c) {}


    Cercle(float r, float x, float y) : rayon(r), centre(Point(x, y)) {}


    void affiche() const {
        cout << "Cercle de rayon: " << rayon << ", Centre: ";
        centre.affiche();
    }


    float getRayon() const { return rayon; }
    void setRayon(float r) { rayon = r; }


    Point getCentre() const { return centre; }
    void setCentre(const Point& c) { centre = c; }


    void translater(float dx, float dy) {
        centre.setX(centre.getX() + dx);
        centre.setY(centre.getY() + dy);
    }


    float surface() const {
        return M_PI * rayon * rayon;
    }


    float perimetre() const {
        return 2 * M_PI * rayon;
    }


    friend bool egalite(const Cercle& c1, const Cercle& c2) {
        return (c1.rayon == c2.rayon && comparer(c1.centre, c2.centre));
    }


    bool appartient(const Point& p) const {
        return distance(centre, p) <= rayon;
    }
};

int main() {

    Cercle c1(1, 10, 10);
    c1.affiche();


    cout << "Périmètre: " << c1.perimetre() << endl;
    cout << "Surface: " << c1.surface() << endl;


    c1.setRayon(c1.getRayon() * 2);
    cout << "Après doublement du rayon:" << endl;
    cout << "Périmètre: " << c1.perimetre() << endl;
    cout << "Surface: " << c1.surface() << endl;


    c1.translater(-10, -10);
    cout << "Après translation vers l'origine:" << endl;
    c1.affiche();


    Point p1(1, 1);
    Point p2(3, 3);
    cout << "Le point (1,1) est dans le cercle: " << (c1.appartient(p1) ? "Oui" : "Non") << endl;
    cout << "Le point (3,3) est dans le cercle: " << (c1.appartient(p2) ? "Oui" : "Non") << endl;


    Cercle c2(2, 0, 0);
    cout << "Le cercle est identique au cercle de centre (0,0) et de rayon 2: " << (egalite(c1, c2) ? "Oui" : "Non") << endl;

    return 0;
}
