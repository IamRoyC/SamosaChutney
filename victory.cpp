    #include <iostream>

    #include <string>

    using namespace std;

     

    class Encpt

    {

        public:

            string key;

     

            Encpt(string key)

            {

                for (int i = 0; i < key.size(); ++i)

                {

                    if (key[i] >= 'A' && key[i] <= 'Z')

                        this->key += key[i];

                    else if (key[i] >= 'a' && key[i] <= 'z')

                        this->key += key[i] + 'A' - 'a';

                }

            }


            string decrypt(string text)

            {

                string out;

     

                for (int i = 0, j = 0; i < text.length(); ++i)

                {

                    char c = text[i];

     

                    if (c >= 'a' && c <= 'z')

                        c += 'A' - 'a';

                    else if (c < 'A' || c > 'Z')

                        continue;

     

                    out += (c - key[j] + 26) % 26 + 'A';

                    j = (j + 1) % key.length();

                }

     

                return out;

            }

    };

     

    int main(int argc, char* argv[])

    {

        Encpt cipher("Winner is here");

    
        string original =

                "Congrats Roy, you are at the end of line. You have successfully identified the imposter. Now spread the word";
	
	if(argc==1)
		cout<<"Did you include everything\n";

	else

	{

        string decrypted = cipher.decrypt(argv[1]);

	string help = "Type the answer along with the object given in the pastebin";

	string format = "Person_nameObject_name";

        cout << "Result: " << decrypted << endl;

	}

    }
