//
//  main.cpp
//  Ch11TheDrill
//
//  Created by Stefan Diaconu on 23/06/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "../../std_lib_facilities.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << "Please enter your birth year: " << endl;
    int birth_year;
    cin >> birth_year;
    cout << birth_year << "\t(decimal)\n"
        << hex << birth_year << "\t(hexadecimal)\n"
        << oct << birth_year << "\t(octal)\n";

    int my_age = 33;
    cout << my_age << endl;

    cout << dec;
    cout << my_age << endl;

    int a, b, c, d;
    cout << "Plaese enter 4 numbers: " << endl;
    cin >> a >> oct >> b >> hex >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

    float my_float = 1234567.89;
    cout << my_float << "\t(defaultfloat)\n"
        << fixed << my_float << "\t(fixed)\n"
        << scientific << my_float << "\t(scientific)\n";

    cout << dec;
    
    cout << "First name:" << setw(14) << "\tStefan" << "\tLast name:" << setw(14) << "\tDiaconu" << "\tTelephone number:" << "\t0777724111" << "\tEmail: " << "\tstefan@email.com\n"
    <<"First name:" << setw(10) << "\tGica" << "\tLast name:" << setw(14) << "\tDiaconu" << "\tTelephone number:" << "\t0777724111" << "\tEmail: " << "\tgica@email.com\n"
    <<"First name:" << setw(14) << "\tCostel" << "\tLast name:" << setw(14) << "\tDiaconu" << "\tTelephone number:" << "\t0777724111" << "\tEmail: " << "\tcostel@email.com\n"
    <<"First name:" << setw(14) << "\tIonel" << "\tLast name:" << setw(14) << "\tDiaconu" << "\tTelephone number:" << "\t0777724111" << "\tEmail: " << "\tionel@email.com\n"
    <<"First name:" << setw(14) << "\tAurica" << "\tLast name:" << setw(14) << "\tDiaconu" << "\tTelephone number:" << "\t0777724111" << "\tEmail: " << "\taurica@email.com\n"
    <<"First name:" << setw(14) << "\tGabriel" << "\tLast name:" << setw(14) << "\tHoreica" << "\tTelephone number:" << "\t0777724111" << "\tEmail: " << "\tgabriel@email.com\n"
    <<"First name:" << setw(14) << "\tPetrica" << "\tLast name:" << setw(14) << "\tHoreica" << "\tTelephone number:" << "\t0777724111" << "\tEmail: " << "\tpetrica@email.com\n"
    <<"First name:" << setw(14) << "\tPetricaPetrica" << "\tLast name:" << setw(14) << "\tHoreicaHoreica" << "\tTelephone number:" << "\t0777724111" << "\tEmail: " << "\tpetrica@email.com\n";
    
    return 0;
}
