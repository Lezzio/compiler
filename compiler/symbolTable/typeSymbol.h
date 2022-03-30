#if ! defined ( TYPE_H )
#define TYPE_H


enum TypeSymbol {
  INT,
  INT8_T,
  CHAR, //TODO: SHOULD WE CHECK OVERFLOW ?
  VOID,
  INT64_T,
};

#endif // TYPE_H