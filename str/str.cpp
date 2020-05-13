#include <iostream>
#pragma warning(disable:4996)
#include "Header.h"

size_t my_strlen(const char* str)
{
  size_t size = 0;
  while (*str != '\0')
  {
    ++str;
    ++size;
  }
  return size;
}
TString::TString() = default;

  TString( char* str)
  {
    m_size = my_strlen(str);
    m_data = new char[m_size + 1]{};
    for (size_t i = 0; i < m_size + 1; ++i)
    {
      m_data[i] = str[i];
    }
  }

  TString::TString(const TString& other)
    : TString(other.m_data)
  {
  }

  TString::~TString()
  {
    if (m_data != nullptr)
      delete[] m_data;
  }

  size_t size() const
  {
    return m_size;
  }

  const char* data() const
  {
    return m_data;
  }

  TString::TString operator+(const TString& other)
  {
    TString newStr;

    int thisLength = strlen(this->m_data);
    int otherLength = strlen(other.m_data);

    newStr.m_size = thisLength + otherLength;

    newStr.m_data = new char[thisLength + otherLength + 1];

    int i = 0;
    for (; i < thisLength; i++)
    {
      newStr.m_data[i] = this->m_data[i];
    }

    for (int j = 0; j < otherLength; j++, i++)
    {
      newStr.m_data[i] = other.m_data[j];
    }

    newStr.m_data[thisLength + otherLength] = '\0';

    return newStr;
  }

  char& TString::operator[](size_t i)
  {
    return m_data[i];
  }

  const char& TString::operator[](size_t i) const
  {
    if (i < 0 || i >= m_size)
      throw "nil'zya(";
    else
      return m_data[i];
  }

  bool TString::operator==(const TString& other)
  {
    if (m_size != other.m_size)
      return false;
    for (size_t i = 0; i < m_size; ++i)
    {
      if (m_data[i] != other.m_data[i])
        return false;
    }
    return true;
  }

  bool TString:: operator!=(const TString& other)
  {
    return !(*this == other);
  }

  size_t my_min(size_t a, size_t b)
  {
    if (a < b)
      return a;
    return b;
  }

  bool TString::operator<(const TString& other)
  {
    for (size_t i = 0; i < my_min(m_size, other.m_size); ++i)
    {
      if (m_data[i] != other.m_data[i])
        return m_data[i] < other.m_data[i];
    }
    return m_size < other.m_size;
  }

  bool TString::operator>(const TString& other)
  {
    if (*this < other)
      return false;
    return *this != other;
  }

  TString& TString::operator=(const TString& other)
  {
    if (this == &other) //проверка на самокопирование
      return *this;

    m_size = other.m_size;
    if (m_data)
      delete[] m_data;
    m_data = new char[m_size + 1]{};
    for (size_t i = 0; i < m_size + 1; ++i)
    {
      m_data[i] = other.m_data[i];
    }
    return *this;
  }

  int TString::find(const char* e)
  {
    return 0;
  }

  TString* TString::Tstrtok(const char* c)
  {
    return nullptr;
  }
  
  //Возвращает позицию
  int find(const char* e) {
    char* t = strstr(m_data, e);
    if (t != NULL)
      return t - m_data + 1;
    else
      return NULL;
  }

  TString* Tstrtok(const char* c) {
    int count = 0;

    TString tmp = m_data;

    char* istr = strtok(tmp.m_data, c);
    while (istr != NULL)
    {
      count += 1;
      istr = strtok(NULL, c);
    }

    tmp = m_data;

    TString* result = new TString[count];

    count = 0;

    istr = strtok(tmp.m_data, c);
    while (istr != NULL)
    {
      result[count] = istr;
      count += 1;
      istr = strtok(NULL, c);
    }

    return result;
  }


std::ostream& operator<<(std::ostream& stream, const TString& self)
{
  stream << self.data();
  return stream;
}

std::istream& operator>>(std::istream& stream, TString& self)
{
  char buf[1024] = {};
  stream >> buf;
  self = buf;
  return stream;
};
private:
  size_t m_size = 0;
  char* m_data = nullptr;

