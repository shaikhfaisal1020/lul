#include <bits/stdc++.h>
using namespace std;

pair<int, int> getIndex(vector<vector<char>> &matrix, char x)
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (matrix[i][j] == x)
        return {i, j};
    }
  }
  return {-1, -1};
}

string modify(string s)
{
  string ans = "";
  for (char ch : s)
  {
    if (ch != ' ')
      ans += ch;
  }
  return ans;
}

string playFairEncryption(string key, string plainText)
{
  // CAPITALIZING KEY AND plainText
  transform(key.begin(), key.end(), key.begin(), ::toupper);
  transform(plainText.begin(), plainText.end(), plainText.begin(), ::toupper);

  cout << "Plain Text : " << plainText << "\nKey : " << key << endl;

  // Creating KEY Matrix
  vector<vector<char>> keyMatrix(5, vector<char>(5, '?'));
  vector<int> visited(25, 0);

  int I = 0, J = 0, k = 0;
  for (int i = 0; i < 5 && k < key.size(); i++)
  {
    I = i;
    for (int j = 0; j < 5 && k < key.size(); j++)
    {
      J = j;
      while (visited[key[k] - 'A'] == 1 && k < key.size())
      {
        k++;
      }
      if (k == key.size())
        break;
      visited[key[k] - 'A'] = 1;
      keyMatrix[i][j] = key[k++];
      if (j == 5)
        j = 0;
    }
  }

  char alph = 'A';
  for (int i = I; i < 5 && alph <= 'Z'; i++)
  {
    for (int j = 0; j < 5 && alph <= 'Z'; j++)
    {
      if (keyMatrix[i][j] != '?')
        continue;
      while (alph <= 'Z' && (visited[alph - 'A'] || alph == 'J'))
      {
        alph++;
      }
      if (alph > 'Z')
        break;
      visited[alph - 'A'] = 1;
      keyMatrix[i][j] = alph++;
    }
  }

  cout << "Key Square Matrix(5X5) : \n";
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << keyMatrix[i][j] << " ";
    }
    cout << endl;
  }

  plainText = modify(plainText);

  // Encryption
  string cipherText = "";
  for (int i = 0; i < plainText.size(); i++)
  {
    char one, two;
    // if last character
    if (i == plainText.size() - 1 || plainText[i] == plainText[i + 1])
    {
      one = plainText[i];
      two = 'Z';
    }
    else
    {
      one = plainText[i++];
      two = plainText[i];
    }

    pair<int, int> oneIndex = getIndex(keyMatrix, one);
    pair<int, int> twoIndex = getIndex(keyMatrix, two);

    // same row
    if (oneIndex.first == twoIndex.first)
    {
      cipherText += keyMatrix[oneIndex.first][(oneIndex.second + 1) % 5];
      cipherText += keyMatrix[twoIndex.first][(twoIndex.second + 1) % 5];
    }
    // else same column
    else if (oneIndex.second == twoIndex.second)
    {
      cipherText += keyMatrix[(oneIndex.first + 1) % 5][oneIndex.second];
      cipherText += keyMatrix[(twoIndex.first + 1) % 5][twoIndex.second];
    }
    // intersection
    else
    {
      cipherText += keyMatrix[oneIndex.first][twoIndex.second];
      cipherText += keyMatrix[twoIndex.first][oneIndex.second];
    }
  }

  return cipherText;
}

string playFairDecryption(string key, string plainText)
{
  // CAPITALIZING KEY AND plainText
  transform(key.begin(), key.end(), key.begin(), ::toupper);
  transform(plainText.begin(), plainText.end(), plainText.begin(), ::toupper);

  cout << "Plain Text : " << plainText << "\nKey : " << key << endl;

  // Creating KEY Matrix
  vector<vector<char>> keyMatrix(5, vector<char>(5, '?'));
  vector<int> visited(25, 0);

  int I = 0, J = 0, k = 0;
  for (int i = 0; i < 5 && k < key.size(); i++)
  {
    I = i;
    for (int j = 0; j < 5 && k < key.size(); j++)
    {
      J = j;
      while (visited[key[k] - 'A'] == 1 && k < key.size())
      {
        k++;
      }
      if (k == key.size())
        break;
      visited[key[k] - 'A'] = 1;
      keyMatrix[i][j] = key[k++];
      if (j == 5)
        j = 0;
    }
  }

  char alph = 'A';
  for (int i = I; i < 5 && alph <= 'Z'; i++)
  {
    for (int j = 0; j < 5 && alph <= 'Z'; j++)
    {
      if (keyMatrix[i][j] != '?')
        continue;
      while (alph <= 'Z' && (visited[alph - 'A'] || alph == 'J'))
      {
        alph++;
      }
      if (alph > 'Z')
        break;
      visited[alph - 'A'] = 1;
      keyMatrix[i][j] = alph++;
    }
  }

  cout << "Key Square Matrix(5X5) : \n";
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << keyMatrix[i][j] << " ";
    }
    cout << endl;
  }

  plainText = modify(plainText);

  // Encryption
  string cipherText = "";
  for (int i = 0; i < plainText.size(); i++)
  {
    char one, two;
    // if last character
    if (i == plainText.size() - 1 || plainText[i] == plainText[i + 1])
    {
      one = plainText[i];
      two = 'Z';
    }
    else
    {
      one = plainText[i++];
      two = plainText[i];
    }

    pair<int, int> oneIndex = getIndex(keyMatrix, one);
    pair<int, int> twoIndex = getIndex(keyMatrix, two);

    // same row
    if (oneIndex.first == twoIndex.first)
    {
      cipherText += keyMatrix[oneIndex.first][(oneIndex.second + 4) % 5];
      cipherText += keyMatrix[twoIndex.first][(twoIndex.second + 4) % 5];
    }
    // else same column
    else if (oneIndex.second == twoIndex.second)
    {
      cipherText += keyMatrix[(oneIndex.first + 4) % 5][oneIndex.second];
      cipherText += keyMatrix[(twoIndex.first + 4) % 5][twoIndex.second];
    }
    // intersection
    else
    {
      cipherText += keyMatrix[oneIndex.first][twoIndex.second];
      cipherText += keyMatrix[twoIndex.first][oneIndex.second];
    }
  }

  return cipherText;
}

int main()
{
  string key;
  cout << "Enter key : " << endl;
  getline(cin, key);
  string plainText;
  cout << "Enter Plain Text : " << endl;
  getline(cin, plainText);

  cout << "\nEncryption Starting .....\n\n";

  string encryptionText = playFairEncryption(key, plainText);
  cout << "Encrypted Text : " << encryptionText << endl;

  cout << "\nDecryption Starting .....\n\n";
  string decryptedText = playFairDecryption(key, encryptionText);
  cout << "Decrypted Text : " << decryptedText << endl;
  return 0;
}
