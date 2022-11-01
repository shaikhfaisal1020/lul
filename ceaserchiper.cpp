#include <iostream>
#include <string>
using namespace std;
int main()
{
  int i, j, k;
  string r, s, t;
  int key;
  cout << "Enter the key : ";
  cin >> key;
  cin.ignore();
  cout << "Enter the message : ";
  getline(cin, s);
  for (i = 0; i < s.size(); i++)
  {
    if (s[i] == ' ')
    {
      t += s[i];
      continue;
    }
    s[i] = tolower(s[i]);
    t += (s[i] - 'a' + key) % 26 + 'a';
  }
  cout << "\nEncrypted message is " << t << '\n';
  for (i = 0; i < t.size(); i++)
  {
    if (t[i] == ' ')
    {
      r += s[i];
      continue;
    }
    r += (t[i] - 'a' - key + 26) % 26 + 'a';
  }
  cout << "Decrypted message is " << r << '\n';

  return 0;
}
