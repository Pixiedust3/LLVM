#include<map>
#include<cstudio>
#include<cstdlib>
#include<memory>
#include<string>
#include<utility>
#include<vector>

enum Token{
  tok_eof=-1;

  tok_def=-2;
  tok_extern =-3;

  tok_identifier=-4;
  tok_number=-5;
};
static std:string IdentifierStr;
static double NumVal;

static int gettok()
{
  static int LastCharacter =' ';
  
  while(isspace(LastCharacter))
    LastCharacter = getchar();

  if (isalpha(LastCharacter)){
    IdentifierStr =LastCharacter;
    while( isalnum(LastCharacter =getchar()))
      IdentifierStr += LastCharacter;

  if (IdentifierStr == "def")
  {
    return tok_def;
  }
  if(IdentifierStr == "extern")
  {
    return tok_extern;
  }
  return tok_identifier;
  }
  if (isdigit(LastCharacter) || LastCharacter == '.') {
    std::string NumStr;
    do{
      NumStr + =LastCharacter;
      LastCharacter = getchar();
    }
    while(isdigit(LastCharacter) || LastCharacter=='.');

    NumVal =strtod(NumStr.c_str(),nullptr);
    return tok_number;

    }
    
  }
if (LastCharacter == '#')
{
  do LastCharacter =getchar();
  while LastCharacter!=EO && LastCharacter !='\n' && LastCharacter !='\r');

  if(LastCharacter !=EOF)
    return gettok();
}
if(LastCharacter==EOF)
return tok_eof;

  int ThisChar =LastCharacter;
  LastCharacter =getchar();
  return ThisChar;
}
