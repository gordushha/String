#pragma once
#include<iostream>
using namespace std;
class TString
{
public:
  TString();
  TString( char* str);
  TString(const TString& other);
  ~TString();
  TString operator+(const TString& other);
  
  const char& operator[](size_t i);
  bool operator==(const TString& other);
  bool operator!=(const TString& other);
  bool operator<(const TString& other);
  bool operator>(const TString& other);
  TString& operator=(const TString& other);
  int find(const char* e);
  TString* Tstrtok(const char* c);
  friend ostream& operator <<(ostream& stream, const TString& self);
  friend istream& operator >>(istream& stream, TString& self);
private:
  size_t m_size = 0;
  char* m_data = nullptr;
};
