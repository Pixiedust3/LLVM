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
// abstract syntax rtreee//
namespace {
  class ExprAST{
  virtual ~ExprAST() = default; 
  };
  class NumberExprAST: public ExprAST{
    double Val;

    public NumberExprAST(double Val)
      : Val(Val)
    {}
  };
  class VariableExprAST :ExprAST{
    std::string Name;

    public:
    VariableExprAST(const std::string &Name)
      :Name(Name)
    {}
  };
  class BinaryExprAST : public ExprAST {
  char Op;
  std::unique_ptr<ExprAST> LHS, RHS;

    public:
    BinaryExprAST(char Op, std::unique_ptr<ExprAST> LHS,
                std::unique_ptr<ExprAST> RHS)
      : Op(Op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}
};
  class CallExprAST : public ExprAST {
  std::string Callee;
  std::vector<std::unique_ptr<ExprAST>> Args;

    public:
    CallExprAST(const std::string &Callee,
              std::vector<std::unique_ptr<ExprAST>> Args)
      : Callee(Callee), Args(std::move(Args)) {}
};
  class PrototypeAST {
  std::string Name;
  std::vector<std::string> Args;

    public:
    PrototypeAST(const std::string &Name, std::vector<std::string> Args)
      : Name(Name), Args(std::move(Args)) {}

  const std::string &getName() const { return Name; }
};
  class FunctionAST {
  std::unique_ptr<PrototypeAST> Proto;
  std::unique_ptr<ExprAST> Body;

    public:
    FunctionAST(std::unique_ptr<PrototypeAST> Proto,
              std::unique_ptr<ExprAST> Body)
      : Proto(std::move(Proto)), Body(std::move(Body)) {}
};
}
// namespace ends here 
  
}
