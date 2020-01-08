#include <iostream>

// Aleksandra Chesiak
#include<iostream>
#include<string>
using namespace std;

const int banana = 1;
const int pear = 2;
const int apple = 4;
const int raspberry = 8;
const int strawberry = 16;
const int cherry = 32;

/*
const int cyjan = 1;
const int magneta = 2;
const int zolty = 4;
const int czarny = 8;
 */

string colour;

int print ( int x ) {
    cout << colour << ":";
    // 1 1 1 1 1 1 = 63;
    int licz = 0;
    licz += ( x & banana ) ? 1:0;
    licz += ( x & pear ) ? 1:0;
    licz += ( x & apple ) ? 1:0;
    licz += ( x & raspberry ) ? 1:0;
    licz += ( x & strawberry ) ? 1:0;
    licz += ( x & cherry ) ? 1:0;

    cout << licz << ":";

    ( x & banana ) ? cout << "b" : cout << "";
    ( x & pear ) ? cout << "g" : cout << "";
    ( x & apple ) ? cout << "j" : cout << "";
    ( x & raspberry ) ? cout << "m" : cout << "";
    ( x & strawberry ) ? cout << "t" : cout << "";
    ( x & cherry ) ? cout << "w" : cout << "";
    return 0;
}

int read ( int i ) {
	string s = "";
    char c;
    cin >> c;
    s += ( c == 'C' || c == 'c' ) ? "C":"";
    s += ( c == 'M' || c == 'm' ) ? "M":"";
    s += ( c == 'Y' || c == 'y' ) ? "Y":"";
    s += ( c == 'K' || c == 'k' ) ? "K":"";
    colour = ( i == 1 ) ? s : colour;
//    colour = s;
    s += ":";

    string temp;
    cin >> temp;

    s += ( temp.find("b") != string::npos || temp.find("B") != string::npos ) ? "b":"";
    s += ( temp.find("g") != string::npos || temp.find("G") != string::npos ) ? "g":"";
    s += ( temp.find("j") != string::npos || temp.find("J") != string::npos ) ? "j":"";
    s += ( temp.find("m") != string::npos || temp.find("M") != string::npos ) ? "m":"";
    s += ( temp.find("t") != string::npos || temp.find("T") != string::npos ) ? "t":"";
    s += ( temp.find("w") != string::npos || temp.find("W") != string::npos ) ? "w":"";

    int fruit = 0;
    fruit += ( s.find ("b",2) != string::npos ) ? banana: 0;
    fruit += ( s.find ("g",2) != string::npos ) ? pear: 0;
    fruit += ( s.find ("j",2) != string::npos ) ? apple: 0;
    fruit += ( s.find ("m",2) != string::npos ) ? raspberry: 0;
    fruit += ( s.find ("t",2) != string::npos ) ? strawberry: 0;
    fruit += ( s.find ("w",2) != string::npos ) ? cherry: 0;

    return fruit;

}

int changeColour( int fruit ) {
    string c="";
    cin >> c;
    colour="";
    colour += ( c == "c" || c == "C" ) ? "C":"";
    colour += ( c == "m" || c == "M" ) ? "M":"";
    colour += ( c == "y" || c == "Y" ) ? "Y":"";
    colour += ( c == "k" || c == "K" ) ? "K":"";
    print( fruit );

}

int add ( int &fruit ) {
    int x = read( 0 );
    // colour zostaje ten sam
    int temp = 0;
    temp += ( (x & banana) || fruit & banana ) ? banana :0;
    temp += ( x & pear || fruit & pear ) ? pear:0;
    temp += ( x & apple || fruit & apple )? apple:0;
    temp += ( x & raspberry || fruit & raspberry ) ? raspberry:0;
    temp += ( x & strawberry || fruit & strawberry ) ? strawberry :0;
    temp += ( x & cherry || fruit& cherry ) ? cherry :0;

    fruit = temp;
    print( fruit);
}

int subtract ( int &fruit ) {
    int x = read( 1 );
    // jest  wkoszyku i jest do odjecia to subtract
    fruit -= ( fruit & banana && x & banana ) ? banana :0;
    fruit -= ( fruit & pear && x & pear ) ? pear:0;
    fruit -= ( fruit & apple && x & apple ) ? apple:0;
    fruit -= ( fruit & raspberry && x & raspberry ) ? raspberry :0;
    fruit -= ( fruit & strawberry && x & strawberry ) ? strawberry :0;
    fruit -= ( fruit & cherry && x & cherry ) ? cherry :0;

    print( fruit );
}

int intersect ( int &fruit ) {
    int x = read( 0 );
    // colour to MAGNETA
    colour = "M";
    int temp = 0;
    temp += ( (x & banana) && fruit & banana ) ? banana :0;
    temp += ( x & pear && fruit & pear ) ? pear:0;
    temp += ( x & apple && fruit & apple )? apple:0;
    temp += ( x & raspberry && fruit & raspberry ) ? raspberry:0;
    temp += ( x & strawberry && fruit & strawberry ) ? strawberry :0;
    temp += ( x & cherry && fruit& cherry ) ? cherry :0;

    fruit = temp;
    print( fruit);
}

int fullUp ( int &fruit ){
//    colour cyklicznie
    string s = "";
    s += ( colour == "C" ) ? "M":"";
    s += ( colour == "M" ) ? "Y":"";
    s += ( colour == "Y" ) ? "K":"";
    s += ( colour == "K" ) ? "C":"";

    colour = s;
    fruit = 63 - fruit;
    print( fruit);
}


int komendy ( int &x ) {
    int end = 0;
    string com = "";
    cin >> com;

    // komendy 1- argumentowe
    end = ( com == "changeColour" ) ? changeColour( x ) : 0;
    end = ( com == "add" ) ? add( x ) : 0;
    end = ( com == "subtract" ) ? subtract( x ) : 0;
    end = ( com == "intersect" ) ? intersect( x ) : 0;

    // komendy 0- argumentowe
    end = ( com == "fullUp" ) ? fullUp( x ) : 0;
    end = ( com == "stop" ) ? 1 : 0;

    end == 0 ? komendy( x ) : 0; // kolejna komenda
    return 0;

}

int main () {

    int lista = 0;

    lista = read( 1 );
    print( lista );

    komendy( lista );


    return 0;
}
