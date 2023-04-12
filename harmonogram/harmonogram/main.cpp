#include "czas.h"
#include "harmonogram.h"

using namespace std;

Harmonogram copybynumber(const Harmonogram& _copy)
{
    Harmonogram temp;
    int h;
    do
    {
        cout << "Podaj ilo�� czas�w do skopiowania: ";
        cin >> h;
        if (h > _copy.number|| h<1) cout << "Podano z�� liczb�!" << endl;
    } while (_copy.number < h || h < 1);
    temp.number = h;
    temp.tab = new Czas[h];
    for (int i = 0; i < h; i++)
    {
       temp[i] = _copy[i];
    }
    temp.number = h;
    
    return temp;
}

Harmonogram copybytime(Harmonogram& _copy)
{
    Czas temp1,suma; 
    cout << "Ustaw do jakiego zakresu sumy czas�w si� skopiuj�: " << endl;
    temp1.ustawczas();
    Harmonogram temp;
    int i=0,p=0;
    suma = _copy[p];
    while (suma < temp1)
    { 
        suma += _copy[p];
        p++;
    }
    if (p == 0) cout << "Nie skopiowano, �adnego czasu :(" << endl;
    temp.number = p;
    suma = _copy[i];
    temp.tab = new Czas[p];
    while(suma<temp1 && i < _copy.number)
    {
        temp[i] = _copy[i];
        i++;
        suma += _copy[i];
    }
    temp.number = i;
    return temp;
}




int main()
{
    setlocale(LC_CTYPE, "Polish");
    int choose,w,s;
    Harmonogram h;
    Czas c1(543, 7, 43), c2(54, 7, 65), c3(54, 76, 21), c4(987, 12), c5(19);
    h.add(c1); h.add(c2); h.add(c3); h.add(c4); h.add(c5);
   
    do {
        cout << "<---------------------------------------------------------------------->" << endl;
        cout << "1 --> Utw�rz kopi� harmonogramu zawieraj�c� tylko wybran� ilo�� czas�w" << endl << "2 --> Utw�rz kopi� harmonogramu zawieraj�c� tylko czasy, kt�rych suma nie przekracza podanemu zakresowi" << endl << "3 --> Dodaj do wybranego czasu z harmonogramu okre�lon� liczb� sekund" << endl << "4 --> Nie poddawaj si�"<<endl<< "0 --> Wyj�cie z programu"<< endl;
        cout << endl << "Co chcesz zrobi�? "; cin >> choose;
       
            switch (choose) {
            case 1:

            {Harmonogram copy(copybynumber(h)); copy.show(); }

                break;
            case 2:

            {Harmonogram copy2(copybytime(h)); copy2.show(); }

                break;
            case 3:
                do {
                    cout << "Podaj, kt�ry czas z harmonogramu chcesz powi�kszy�: ";
                    cin >> w;
                    if (w > h.GetNumber() || w < 1) cout << "Nie ma takiego czasu! Podaj jeszcze raz: " << endl;
                    
                } while (w>h.GetNumber()||w<1);
                cout << endl << "O ile sekund chcesz powi�szy� wybrany czas: ";
                cin >> s;
                h[w-1] += s;
                h[w-1].pokazczas();

                break;
            case 4:
                system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ");
                break;
            case 0: break;

            default:
                cout << "Wybierz liczb� od 0 do 3!" << endl;
                break;
            }
        
            
    } while (choose != 0);
  
    return 0;
}

