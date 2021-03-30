#include <iostream>
#include <string.h>

using namespace std;


//Declaring main function and passing the argument as parameter
int main(int argc, char* argv[])
{
    // declaring variable
    string word;
    string line;
    
    // checking if it count the number of parameter in argv[] and then displaying the usage message
    if (argc != 2) {
        cout << "Usage message: 'filedisp -d' or 'filedisp -f' or 'filedisp -b'" << endl;
        return -1;
    }
     //checking for the path of the file with option -d , -f , -b and printing out the word that matches

    if (strcmp (argv[1], "-d") == 0)
        word = "directories";
    else if (strcmp (argv[1], "-f") == 0)
        word = "files";
    else if (strcmp (argv[1], "-b") == 0)
        word = "bytes";
    else {
        cout << "Usage message: 'filedisp -d' or 'filedisp -f' or 'filedisp -b'" << endl;
       // return -1;
    }

    // to extract the string form the input line and read the line.
    while (getline (cin, line))
        if (!cin.bad())
             
               // check for search word
            if (line.find(word) != string::npos)
                
                //Displaying the line output
                cout << line << endl;

    return 0;
}
