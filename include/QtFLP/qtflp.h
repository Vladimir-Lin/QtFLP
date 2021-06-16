/****************************************************************************
 *                                                                          *
 * Copyright (C) 2001 ~ 2016 Neutrino International Inc.                    *
 *                                                                          *
 * Author : Brian Lin <lin.foxman@gmail.com>, Skype: wolfram_lin            *
 *                                                                          *
 ****************************************************************************/

#ifndef QT_FLP_H
#define QT_FLP_H

#include <QtCore>
#include <QtNetwork>
#include <QtSql>
#include <QtScript>
#include <Essentials>
#include <Mathematics>

QT_BEGIN_NAMESPACE

#ifndef QT_STATIC
#    if defined(QT_BUILD_QTFLP_LIB)
#      define Q_FLP_EXPORT Q_DECL_EXPORT
#    else
#      define Q_FLP_EXPORT Q_DECL_IMPORT
#    endif
#else
#      define Q_FLP_EXPORT
#endif

namespace N                                                                  {

namespace LP                                                                 {

/****************************************************************************\
 *                                                                          *
 *                     C++ Functional Programming System                    *
 *                                                                          *
\****************************************************************************/

typedef unsigned int RefCount                                                ;

class Q_FLP_EXPORT   IRefable                                                ;
class Q_FLP_EXPORT   Void                                                    ;
class Q_FLP_EXPORT   SmartFunctoid                                           ;
class Q_FLP_EXPORT   SmartFunctoid0                                          ;
class Q_FLP_EXPORT   SmartFunctoid1                                          ;
class Q_FLP_EXPORT   SmartFunctoid2                                          ;
class Q_FLP_EXPORT   SmartFunctoid3                                          ;
class Q_FLP_EXPORT   AutoCurryType                                           ;
class Q_FLP_EXPORT   CallableWithoutArguments                                ;
class Q_FLP_EXPORT   WrongNumberOfSigArgs                                    ;
class Q_FLP_EXPORT   PlaceholderForZeroArguments                             ;

template <class T              > class Value                                 ;
template <class Fun, class Args> class Call                                  ;

template <class T> class Ref                                                 ;
template <class T> class IRef                                                ;
template <class U, class T> Ref<U> ref_dynamic_cast( const Ref<T> & r )      ;
template <class T, class U> struct ConversionHelper                          ;
template <class T, class U> struct Conversion                                ;
template <class T         > struct Conversion<T, T>                          ;
template <class D, class B> struct Inherits                                  ;
template < class A1,class A2,class A3,class A4,class A5,class A6,class R     >
struct FunType                                                               ;
template < class A1, class A2, class A3, class A4, class A5, class R         >
struct FunType < A1,   A2,   A3,   A4,   A5,    R, Void>                     ;
template < class A1, class A2, class A3, class A4, class R                   >
struct FunType < A1,   A2,   A3,   A4,    R, Void, Void>                     ;
template < class A1, class A2, class A3, class R                             >
struct FunType < A1,   A2,   A3,    R, Void, Void, Void>                     ;
template < class A1, class A2, class R                                       >
struct FunType < A1,   A2,    R, Void, Void, Void, Void >                    ;
template < class A1, class R                                                 >
struct FunType < A1,    R, Void, Void, Void, Void, Void >                    ;
template < class R                                                           >
struct FunType < R , Void, Void, Void, Void, Void, Void >                    ;

template < class A1,class A2,class A3,class A4,class A5,class A6,class R     >
struct CfpType                                                               ;
template < class A1, class A2, class A3, class A4, class A5, class R         >
struct CfpType < A1,   A2,   A3,   A4,   A5,    R, Void>                     ;
template < class A1, class A2, class A3, class A4, class R                   >
struct CfpType < A1,   A2,   A3,   A4,    R, Void, Void>                     ;
template < class A1, class A2, class A3, class R                             >
struct CfpType < A1,   A2,   A3,    R, Void, Void, Void>                     ;
template < class A1, class A2, class R                                       >
struct CfpType < A1,   A2,    R, Void, Void, Void, Void>                     ;
template < class A1, class R                                                 >
struct CfpType < A1,    R, Void, Void, Void, Void, Void>                     ;
template < class R                                                           >
struct CfpType <  R, Void, Void, Void, Void, Void, Void>                     ;

template  < class T,class A1,class A2,class A3,class A4,class A5,class A6    >
struct RT                                                                    ;
template  < class T, class A1, class A2, class A3, class A4, class A5        >
struct RT < T,   A1,   A2,   A3,   A4,   A5, Void >                          ;
template  < class T, class A1, class A2, class A3, class A4                  >
struct RT < T,   A1,   A2,   A3,   A4, Void, Void >                          ;
template  < class T, class A1, class A2, class A3                            >
struct RT < T,   A1,   A2,   A3, Void, Void, Void >                          ;
template  < class T, class A1, class A2                                      >
struct RT < T,   A1,   A2, Void, Void, Void, Void >                          ;
template  < class T, class A1                                                >
struct RT < T,   A1, Void, Void, Void, Void, Void >                          ;
template  < class T                                                          >
struct RT < T, Void, Void, Void, Void, Void, Void >                          ;

template <class F, bool b> class NeededASmartFunctoidButInsteadGot           ;
template <class F        > class NeededASmartFunctoidButInsteadGot<F,true>   ;

template <bool b> class Ensure                                               ;
template <      > class Ensure<true>                                         ;

template <class F> class Full0                                               ;
template <class F> class Full1                                               ;
template <class F> class Full2                                               ;
template <class F> class Full3                                               ;

template <class F> Full0<F> makeFull0( const F & f )                         ;
template <class F> Full1<F> makeFull1( const F & f )                         ;
template <class F> Full2<F> makeFull2( const F & f )                         ;
template <class F> Full3<F> makeFull3( const F & f )                         ;

// Handy helper 'nothing' class.
class Q_FLP_EXPORT Void                        { }                           ;
class Q_FLP_EXPORT CallableWithoutArguments    { }                           ;
class Q_FLP_EXPORT WrongNumberOfSigArgs        { }                           ;
class Q_FLP_EXPORT SmartFunctoid               { }                           ;
class Q_FLP_EXPORT PlaceholderForZeroArguments { }                           ;
class Q_FLP_EXPORT AutoCurryType               { }                           ;

template<class T>
class Ref
{
  public:

    typedef T WrappedType ;

    explicit Ref ( T * p = 0 ) : ptr   (p)
                               , count (0)
    {
      if (NotNull(ptr)) newref() ;
    }

    Ref (const Ref<T> & other) : ptr   (other.ptr)
                               , count (0        )
    {
      if (NotNull(ptr))     {
        count = other.count ;
        inc ( )             ;
      }                     ;
    }

    virtual ~Ref (void)
    {
      if (NotNull(ptr) && dec()) {
        delete count             ;
        delete ptr               ;
      }                          ;
      count = NULL               ;
      ptr   = NULL               ;
    }

    Ref<T> & operator = (const Ref<T> & other)
    {
      T * tp = other.ptr          ;
      RefCount * tc = other.count ;
      if ( NotNull(tp) ) ++(*tc)  ;
      if (NotNull(ptr) && dec())  {
        delete count              ;
        delete ptr                ;
      }                           ;
      ptr   = tp                  ;
      count = tc                  ;
      return *this                ;
    }

        operator T * () const { return ptr; }
    T * operator ->  () const { return ptr; }

    template <class U>
    Ref (const Ref<U> & other) : ptr   (implicit_cast<T *>(other.ptr))
                               , count (0                            )
    {
      if (NotNull(ptr))     {
        count = other.count ;
        inc ( )             ;
      }                     ;
    }

    bool operator == (const Ref<T> & other) const
    {
       return ( ptr == other.ptr ) ;
    }

    bool operator != (const Ref<T> & other) const
    {
       return ( ptr != other.ptr ) ;
    }

  protected:

    T        * ptr   ;
    RefCount * count ;

   void newref (void) { count = new RefCount ( 1 ) ; }
   void inc    (void) { ++ (*count) ; }
   bool dec    (void) { return 0 == -- (*count) ; }

   template <class U> friend class Ref ;

   template <class U, class V>
   friend Ref<U> ref_dynamic_cast(const Ref<V> & r) ;

};

template <class U, class T>
Ref<U> ref_dynamic_cast (const Ref<T> & r)
{
  Ref<U> temp                            ;
  temp.ptr = dynamic_cast<U *> ( r.ptr ) ;
  if (NotNull(temp.ptr))                 {
    temp . count = r . count             ; // Is it dangerous ?
    temp . inc ( )                       ;
  }                                      ;
  return temp                            ;
}

template<class T>
class IRef
{
  public:

    typedef T WrappedType ;

    static void swap ( IRef<T> & x , IRef<T> & y )
    {
       T * tmp = x . ptr ;
       x . ptr = y . ptr ;
       y . ptr = tmp     ;
    }

    static void rotate ( IRef<T> & x, IRef<T> & y, IRef<T> & z )
    {
      T * tmp = x . ptr ;
      x . ptr = y . ptr ;
      y . ptr = z . ptr ;
      z . ptr = tmp     ;
    }

   explicit IRef ( T * p = 0 ) : ptr ( p )
   {
     if (NotNull(ptr)) ptr->inc() ;
   }

   IRef(const IRef<T> & other) : ptr ( other . ptr )
   {
     if (NotNull(ptr)) ptr->inc() ;
   }

   virtual ~IRef(void)
   {
     if (NotNull(ptr)) ptr->dec() ;
   }

   IRef<T> & operator = (const IRef<T> & other)
   {
      if (NotNull(other.ptr)) other.ptr->inc() ;
      if (NotNull(ptr      ))       ptr->dec() ;
      ptr = other . ptr                        ;
      return *this                             ;
   }

       operator T * () const { return ptr; }
   T * operator ->  () const { return ptr; }

   bool operator == (const IRef<T> & other) const
   {
     return ( ptr == other.ptr ) ;
   }

   bool operator != (const IRef<T> & other) const
   {
     return ( ptr != other.ptr ) ;
   }

  protected:

    T * ptr ;

};

class Q_FLP_EXPORT IRefable
{
  public:

             IRefable (RefCount x = 0) ;
    virtual ~IRefable (void) ;

    void     inc      (void) const ;
    void     dec      (void) const ;

  protected:

    mutable RefCount RefC ;

  private:

};

// Inheritance detection

template <class T, class U>
struct ConversionHelper                  {
   typedef char Small                    ;
   struct       Big   { char dummy[2]; } ;
   static       Small Test ( const U * ) ;
   static       Big   Test ( ...       ) ;
   static const T * MakeT  (           ) ;
}                                        ;

template <class T, class U>
struct Conversion                                                   {
   typedef ConversionHelper<T,U> H                                  ;
   static const int  lhs      = sizeof ( H::Test((T*) H::MakeT()) ) ;
   static const int  rhs      = sizeof ( typename H::Small        ) ;
   static const bool exists   = ( lhs == rhs )                      ;
   static const bool sameType = false                               ;
}                                                                   ;

template <class T>
struct Conversion<T, T>              {
   static const bool exists   = true ;
   static const bool sameType = true ;
}                                    ;

template <class Derived, class Base>
struct Inherits                                  {
   static const bool value                       =
       Conversion < Derived , Base > :: exists  &&
      !Conversion < Base    , void > :: sameType ;
}                                                ;

/*****************************************************************************\
 * Here are the classes with "nested typedefs" which just help us use        *
 * our own type system; these classes are just inherited.                    *
 *                                                                           *
 * Note that although the sigs support a large number of arguments, most     *
 * of the rest of the library only supports functions of 0-3 arguments.      *
 *                                                                           *
\*****************************************************************************/

// This set names functoid arguments and results

template < class A1, class A2 = Void, class A3 = Void, class A4 = Void ,
                     class A5 = Void, class A6 = Void, class R  = Void >
struct FunType         {
   typedef R  ResultType ;
   typedef A1 Arg1Type   ;
   typedef A2 Arg2Type   ;
   typedef A3 Arg3Type   ;
   typedef A4 Arg4Type   ;
   typedef A5 Arg5Type   ;
   typedef A6 Arg6Type   ;
}                        ;

template < class A1, class A2, class A3, class A4, class A5, class R >
struct FunType <A1, A2, A3, A4, A5, R, Void> {
   typedef R  ResultType                     ;
   typedef A1 Arg1Type                       ;
   typedef A2 Arg2Type                       ;
   typedef A3 Arg3Type                       ;
   typedef A4 Arg4Type                       ;
   typedef A5 Arg5Type                       ;
}                                            ;

template <class A1, class A2, class A3, class A4, class R>
struct FunType<A1, A2, A3, A4, R, Void, Void> {
   typedef R  ResultType                      ;
   typedef A1 Arg1Type                        ;
   typedef A2 Arg2Type                        ;
   typedef A3 Arg3Type                        ;
   typedef A4 Arg4Type                        ;
}                                             ;

template <class A1, class A2, class A3, class R>
struct FunType<A1, A2, A3, R, Void, Void, Void> {
   typedef R  ResultType                        ;
   typedef A1 Arg1Type                          ;
   typedef A2 Arg2Type                          ;
   typedef A3 Arg3Type                          ;
}                                               ;

template <class A1, class A2, class R>
struct FunType<A1, A2, R, Void, Void, Void, Void> {
  typedef R  ResultType                           ;
  typedef A1 Arg1Type                             ;
  typedef A2 Arg2Type                             ;
}                                                 ;

template <class A1, class R>
struct FunType<A1, R, Void, Void, Void, Void, Void> {
  typedef R  ResultType                             ;
  typedef A1 Arg1Type                               ;
}                                                   ;

template <class R>
struct FunType<R, Void, Void, Void, Void, Void, Void> {
  typedef R ResultType                                ;
}                                                     ;

/*****************************************************************************\
 *                                                                           *
 *                               Concrete versions                           *
 *                                                                           *
 * This set is used for monomorphic direct functoids; the type names         *
 * are inherited as-is, and also a template-Sig is defined so that           *
 * monomorphic direct functoids can mix freely with polymorphic functoids    *
 * since the latter require a template-Sig member                            *
 *                                                                           *
\*****************************************************************************/

template < class A1, class A2 = Void, class A3 = Void, class A4 = Void ,
                     class A5 = Void, class A6 = Void, class R  = Void >
struct CfpType : public FunType<A1,A2,A3,A4,A5,A6,R>
{
  template <class P1, class P2, class P3, class P4, class P5, class P6>
  struct Sig : public FunType<A1,A2,A3,A4,A5,A6,R> { }                ;
}                                                                     ;

template <class A1, class A2, class A3, class A4, class A5, class R>
struct CfpType<A1, A2, A3, A4, A5, R, Void> : public FunType<A1,A2,A3,A4,A5,R>
{
   template <class P1, class P2, class P3, class P4, class P5>
   struct Sig : public FunType<A1,A2,A3,A4,A5,R> { }         ;
}                                                            ;

template <class A1, class A2, class A3, class A4, class R>
struct CfpType<A1, A2, A3, A4, R, Void, Void> : public FunType<A1,A2,A3,A4,R>
{
  template <class P1, class P2, class P3, class P4>
  struct Sig : public FunType<A1,A2,A3,A4,R> { }  ;
}                                                 ;

template <class A1, class A2, class A3, class R>
struct CfpType<A1, A2, A3, R, Void, Void, Void> : public FunType<A1,A2,A3,R>
{
  template <class P1, class P2, class P3>
  struct Sig : public FunType<A1,A2,A3,R> { } ;
}                                             ;

template <class A1, class A2, class R>
struct CfpType<A1, A2, R, Void, Void, Void, Void> :
  public FunType<A1,A2,R>, public std::binary_function<A1,A2,R>
{
  template <class P1, class P2>
  struct Sig : public FunType<A1,A2,R> { } ;
}                                          ;

template <class A1, class R>
struct CfpType<A1, R, Void, Void, Void, Void, Void>
     : public FunType<A1,R>
     , public std::unary_function<A1,R>
{
  template <class P1>
  struct Sig : public FunType<A1,R> { } ;
}                                       ;

template <class R>
struct CfpType<R, Void, Void, Void, Void, Void, Void>
     : public CallableWithoutArguments
     , public FunType<R>
{
  template < class Dummy1 = Void , class Dummy2 = Void  >
  struct Sig : public FunType<WrongNumberOfSigArgs> { } ;
  template < class Dummy                                >
  struct Sig<Void,Dummy> : public FunType<R>        { } ;
}                                                       ;

/*****************************************************************************\
 *                                                                           *
 *                              Icky helpers                                 *
 *                                                                           *
 * These are strictly unnecessary, but they avoid a bug in the g++           *
 * compiler and also make some things shorter to type.                       *
 * RT<T, args> means "return type of T when passed argument types <args>"    *
 *                                                                           *
\*****************************************************************************/

template <class T, class A1 = Void, class A2 = Void, class A3 = Void,
                   class A4 = Void, class A5 = Void, class A6 = Void>
struct RT                                                                      {
typedef typename T::template Sig<A1, A2, A3, A4, A5, A6>::ResultType ResultType;
typedef typename T::template Sig<A1, A2, A3, A4, A5, A6>::Arg1Type   Arg1Type  ;
typedef typename T::template Sig<A1, A2, A3, A4, A5, A6>::Arg2Type   Arg2Type  ;
typedef typename T::template Sig<A1, A2, A3, A4, A5, A6>::Arg3Type   Arg3Type  ;
typedef typename T::template Sig<A1, A2, A3, A4, A5, A6>::Arg4Type   Arg4Type  ;
typedef typename T::template Sig<A1, A2, A3, A4, A5, A6>::Arg5Type   Arg5Type  ;
typedef typename T::template Sig<A1, A2, A3, A4, A5, A6>::Arg6Type   Arg6Type  ;
}                                                                              ;

template <class T, class A1, class A2, class A3, class A4, class A5>
struct RT<T, A1, A2, A3, A4, A5, Void>                                         {
  typedef typename T::template Sig<A1, A2, A3, A4, A5>::ResultType ResultType  ;
  typedef typename T::template Sig<A1, A2, A3, A4, A5>::Arg1Type   Arg1Type    ;
  typedef typename T::template Sig<A1, A2, A3, A4, A5>::Arg2Type   Arg2Type    ;
  typedef typename T::template Sig<A1, A2, A3, A4, A5>::Arg3Type   Arg3Type    ;
  typedef typename T::template Sig<A1, A2, A3, A4, A5>::Arg4Type   Arg4Type    ;
  typedef typename T::template Sig<A1, A2, A3, A4, A5>::Arg5Type   Arg5Type    ;
}                                                                              ;

template <class T, class A1, class A2, class A3, class A4>
struct RT<T, A1, A2, A3, A4, Void, Void>                                       {
  typedef typename T::template Sig<A1, A2, A3, A4>::ResultType ResultType      ;
  typedef typename T::template Sig<A1, A2, A3, A4>::Arg1Type   Arg1Type        ;
  typedef typename T::template Sig<A1, A2, A3, A4>::Arg2Type   Arg2Type        ;
  typedef typename T::template Sig<A1, A2, A3, A4>::Arg3Type   Arg3Type        ;
  typedef typename T::template Sig<A1, A2, A3, A4>::Arg4Type   Arg4Type        ;
}                                                                              ;

template <class T, class A1, class A2, class A3>
struct RT<T, A1, A2, A3, Void, Void, Void>                                     {
  typedef typename T::template Sig<A1, A2, A3>::ResultType ResultType          ;
  typedef typename T::template Sig<A1, A2, A3>::Arg1Type   Arg1Type            ;
  typedef typename T::template Sig<A1, A2, A3>::Arg2Type   Arg2Type            ;
  typedef typename T::template Sig<A1, A2, A3>::Arg3Type   Arg3Type            ;
}                                                                              ;

template <class T, class A1, class A2>
struct RT<T, A1, A2, Void, Void, Void, Void>                                   {
  typedef typename T::template Sig<A1, A2>::ResultType ResultType              ;
  typedef typename T::template Sig<A1, A2>::Arg1Type   Arg1Type                ;
  typedef typename T::template Sig<A1, A2>::Arg2Type   Arg2Type                ;
}                                                                              ;

template <class T, class A1>
struct RT<T, A1, Void, Void, Void, Void, Void>                                 {
  typedef typename T::template Sig<A1>::ResultType ResultType                  ;
  typedef typename T::template Sig<A1>::Arg1Type   Arg1Type                    ;
}                                                                              ;

template <class T>
struct RT<T, Void, Void, Void, Void, Void, Void>                               {
  typedef typename T::template Sig<>::ResultType ResultType                    ;
}                                                                              ;

/****************************************************************************\
 *                                                                          *
 *                             Feature: Smartness                           *
 *                                                                          *
 * If F is smart, then we can refer to these entities:                      *
 *                                                                          *
 *   FunctoidTraits<F>::template accepts<N>::args                           *
 *                                                                          *
 * A bool which says whether F can accept N arguments                       *
 *                                                                          *
 *   FunctoidTraits<F>::max_args                                            *
 *                                                                          *
 * An int which says what the most arguments F can accept is                *
 *                                                                          *
 *   FunctoidTraits<F>::template ensure_accepts<N>::args()                  *
 *                                                                          *
 * A no-op call that compiles only if F can accept N args                   *
 *                                                                          *
 * We use traits so that if you happen to ask a non-smart functoid these    *
 * questions, you will hopefully get a literate error message.              *
 *                                                                          *
\****************************************************************************/

class AUniqueTypeForNil
{
  public:

    bool operator==( AUniqueTypeForNil ) const { return true  ; }
    bool operator< ( AUniqueTypeForNil ) const { return false ; }

};

Q_FLP_EXPORT extern AUniqueTypeForNil        nul              ;

/****************************************************************************\
 * We add crazy identifiers to ensure that users don't accidentally talk    *
 * to functoids directly; they should always be going through the traits    *
 * class to ask for info.                                                   *
\****************************************************************************/

class Q_FLP_EXPORT SmartFunctoid0 : public SmartFunctoid
{
  public                                                 :
    template <class Dummy, int i> struct crazy_accepts   {
      static const bool args = false                     ;
    }                                                    ;
    template <class Dummy> struct crazy_accepts<Dummy,0> {
      static const bool args = true                      ;
    }                                                    ;
    static const int crazy_max_args = 0                  ;
}                                                        ;

class Q_FLP_EXPORT SmartFunctoid1 : public SmartFunctoid
{
  public                                                 :
    template <class Dummy, int i> struct crazy_accepts   {
      static const bool args = false                     ;
    }                                                    ;
    template <class Dummy> struct crazy_accepts<Dummy,1> {
      static const bool args = true                      ;
    }                                                    ;
    static const int crazy_max_args = 1                  ;
}                                                        ;

class Q_FLP_EXPORT SmartFunctoid2 : public SmartFunctoid
{
  public                                                 :
    template <class Dummy, int i> struct crazy_accepts   {
      static const bool args = false                     ;
    }                                                    ;
    template <class Dummy> struct crazy_accepts<Dummy,1> {
      static const bool args = true                      ;
    }                                                    ;
    template <class Dummy> struct crazy_accepts<Dummy,2> {
      static const bool args = true                      ;
    }                                                    ;
    static const int crazy_max_args = 2                  ;
}                                                        ;

class Q_FLP_EXPORT SmartFunctoid3 : public SmartFunctoid
{
  public                                                 :
    template <class Dummy, int i> struct crazy_accepts   {
       static const bool args = false                    ;
    }                                                    ;
    template <class Dummy> struct crazy_accepts<Dummy,1> {
      static const bool args = true                      ;
    }                                                    ;
    template <class Dummy> struct crazy_accepts<Dummy,2> {
      static const bool args = true                      ;
    }                                                    ;
    template <class Dummy> struct crazy_accepts<Dummy,3> {
      static const bool args = true                      ;
    }                                                    ;
    static const int crazy_max_args = 3                  ;
}                                                        ;

template <class F, bool b> class NeededASmartFunctoidButInsteadGot {};
template <class F        > class NeededASmartFunctoidButInsteadGot<F,true>
{
  public:

    typedef F Type ;

};

template <> class Ensure<true> { } ;

template <class MaybeASmartFunctoid>
class FunctoidTraits                                                         {
  public                                                                     :
    typedef
      typename NeededASmartFunctoidButInsteadGot                             <
               MaybeASmartFunctoid                                           ,
               Inherits<MaybeASmartFunctoid,SmartFunctoid >::value>::Type F  ;
    template <int i> struct accepts                                          {
       static const bool args = F::template crazy_accepts<int,i>::args       ;
    }                                                                        ;
    template <int i> struct ensure_accepts                                   {
       static const bool ok = F::template crazy_accepts<int,i>::args         ;
       inline static void args() { (void) Ensure<ok> ( ) ;                   }
    }                                                                        ;
    static const int max_args = F::crazy_max_args                            ;
}                                                                            ;

// Here is a 'cute' kludge to make "_*_" represent a 'nothing' argument

inline PlaceholderForZeroArguments operator * ( AutoCurryType , AutoCurryType )
{
  return PlaceholderForZeroArguments ( ) ;
}

template <class T, class U>
class ImplicitlyConvertibleHelper        {
  public                                 :
    typedef char Small                   ;
    struct       Big  { char dummy[2]; } ;
    static       Small Test  ( const U ) ;
    static       Big   Test  ( ...     ) ;
    static const T     MakeT (         ) ;
}                                        ;

template <class T, class U>   // T converts to U
class ImplicitlyConvertible                                      {
  public                                                         :
    typedef ImplicitlyConvertibleHelper<T,U> H                   ;
    //static const int lhs = sizeof(H::Test((const T) H::MakeT()));
    static const int  lhs   = sizeof ( H::Test((T) H::MakeT()) ) ;
    static const int  rhs   = sizeof ( typename H::Small       ) ;
    static const bool value =        ( lhs == rhs              ) ;
}                                                                ;

class NIL { } ;

template <class H, class T> class CONS
{
  public:

    H head ;
    T tail ;

    CONS ( const H & h               ) : head ( h )              { }
    CONS ( const H & h , const T & t ) : head ( h ) , tail ( t ) { }

};

template <class LA, class LB> class AppendList ;

template <class LB> class AppendList<NIL,LB>
{
  public:

    typedef    LB Result                                              ;

    static inline Result go ( const NIL &, const LB & x )
    {
      return x                                                        ;
    }
}                                                                     ;

template <class H, class T, class LB> class AppendList < CONS < H , T > , LB >
{
  public:

    typedef CONS<H,typename AppendList<T,LB>::Result> Result  ;

    static inline Result go ( const CONS<H,T>& x, const LB& y )
    {
      return Result( x.head, AppendList<T,LB>::go(x.tail,y) ) ;
    }

}                                                             ;

template <class L> class Length;

template <> class Length < NIL >
{
  public                       :

    static const int value = 0 ;

}                              ;

template <class H, class T> class Length< CONS<H,T> >
{
  public                                          :

    static const int value = 1 + Length<T>::value ;

} ;

template <class A, class T> class Remove ;

template <class T> class Remove < NIL , T >
{
  public                             :

    typedef NIL Result ;

}                                    ;

template <class AH, class AT, class T> class Remove < CONS < AH , AT > , T >
{
  public                                                              :

    typedef CONS < AH , typename Remove < AT , T > :: Result > Result ;

}                                                                     ;

template <class AT, class T> class Remove < CONS < T , AT > , T >
{
  public                                                :

    typedef typename Remove < AT , T > :: Result Result ;

}                                                       ;

template <class A, class B> class ListDifference;

template <class A> class ListDifference < A , NIL >
{
  public             :

    typedef A Result ;

}                    ;

template <class A, class T, class Rest>
class ListDifference < A , CONS < T , Rest > >
{
  public                                                               :

    typedef typename Remove         < A      , T    > :: Result APrime ;
    typedef typename ListDifference < APrime , Rest > :: Result Result ;

}                                                                      ;

template <class L> class RemoveDuplicates ;

template <> struct RemoveDuplicates < NIL >
{
  public                             :

    typedef NIL Result ;

}                                    ;

template <class H, class Rest> class RemoveDuplicates < CONS < H , Rest > >
{
  public                                                               :

    typedef CONS < H , typename Remove < Rest , H > :: Result > Result ;

}                                                                      ;

class LEBase { } ; // Base type for all LEs

template <class T, bool b> class EnsureLEHelper
{
  public                          :

    static inline void go (void) {}

}                                 ;

template <class T> class EnsureLEHelper < T , false > { } ;

template <class T> struct EnsureLE
{
  public:

    static inline void go(void)
    {
      EnsureLEHelper < T , Inherits < T , LEBase > :: value > :: go ( ) ;
    }

};

template <class LEL> class EnsureLEList ;

template <> class EnsureLEList < NIL >
{
  public                      :

    static inline void go() { }

}                             ;

template <class H, class T> class EnsureLEList < CONS < H , T > >
{
  public:

    static inline void go(void)
    {
      EnsureLE     < H > :: go ( ) ;
      EnsureLEList < T > :: go ( ) ;
    }

} ;

template <int i, class TypeThunk> class TEPair
{
  public:

    static const int my_lv = i;
    typedef TypeThunk MyTypeThunk;

};

template <int i, class LE> class BEPair
{
  public:

    typedef LE MyLE ;

    static const int my_lv = i ;
    LE               value     ;

    BEPair ( const LE & x ) : value(x)
    {
      EnsureLE < LE > :: go ( ) ;
    }

};

template <class LEL> class AccumFreeVars ;

template <> class AccumFreeVars < NIL >
{
  public                             :

    typedef NIL Result ;

}                                    ;

template <class H, class T> class AccumFreeVars < CONS < H , T > >
{
  public                                                :
    typedef typename AppendList<typename H::FreeVars,
      typename AccumFreeVars<T>::Result>::Result Result ;
};

template <int i, class LE> class Binder
{
  public                          :

    static const int lvnum = i    ;
    LE               exp          ;

    Binder( const LE & e ) : exp(e)
    {
      EnsureLE < LE > :: go ( )   ;
    }

}                                 ;

template <class BL> class EnsureBinderList;

template <> class EnsureBinderList < NIL >
{
  public                        :

    static inline void go ( ) { }

}                               ;

template <int i, class LE, class Rest>
class EnsureBinderList < CONS < Binder < i , LE > , Rest > >
{
  public:

    static inline void go(void)
    {
      EnsureBinderList < Rest > :: go ( ) ;
    }

};

template <int i, class LE>
class Gets
{
  public:
    static const int lvnum = i ;
    LE               exp       ;

    Gets( const LE & e ) : exp(e)
    {
      EnsureLE < LE > :: go ( ) ;
    }

} ;

template <class X, class Y> class AlwaysFirst
{
  public:

    typedef X Type ;

}                  ;

template <bool b, class T>
class LEifyHelper
{
  public:

    typedef T Type ;

    static inline Type go( const T& x )
    {
      return x ;
    }

};

template <class T>
class LEifyHelper<false,T>
{
  public:

    typedef Value<T> Type ;

    static inline Type go ( const T& x )
    {
      return Type(x) ;
    }

};

template <class T>
class LEify
{
  public:

    static const bool b = Inherits<T,LEBase>::value;
    typedef typename LEifyHelper<b,T>::Type Type;

    static inline Type go ( const T & x )
    {
      return LEifyHelper < b , T > :: go ( x ) ;
    }

}                                              ;

template <class T>
class LEListify
{
  public:

   typedef typename LEify < T > :: Type LE ;

   typedef CONS < LE , NIL > Type;

   static inline Type go( const T & x )
   {
     return Type ( LEify < T > :: go ( x ) ) ;
   }

} ;

template <>
class LEListify < PlaceholderForZeroArguments >
{
  public:

   typedef NIL Type ;

   static inline Type go ( const PlaceholderForZeroArguments & )
   {
     return Type();
   }

};

template <>
class LEListify < NIL >
{
  public:

    typedef NIL Type ;

    static inline Type go ( const NIL & )
    {
      return Type ( ) ;
    }

} ;

template <class LE, class Rest>
class LEListify < CONS < LE , Rest > >
{
  public:

    typedef CONS < LE , Rest > Type ;

    static inline Type go( const Type& x )
    {
      EnsureLEList < Type > :: go ( ) ;
      return x                        ;
    }

} ;

template <class B> class BinderListify ;

template <int i, class LE>
class BinderListify < Binder < i , LE > >
{
  public:

    typedef CONS < Binder < i , LE > , NIL > Type ;

    static inline Type go ( const Binder < i , LE > & b )
    {
      return Type ( b ) ;
    }

};

template <class B, class Rest>
class BinderListify < CONS < B , Rest > >
{
  public:

    typedef CONS < B , Rest > Type;

    static inline Type go ( const Type& x )
    {
      return x;
    }

};

template <class This, class Arg>
class BracketCallable
{
  public:

    typedef typename LEify < This > :: Type ThisLE ;

    typedef Call < ThisLE , typename LEListify < Arg > :: Type > Result ;

    static inline Result go ( const This & me, const Arg & arg )
    {
      return Result ( LEify <This> :: go (me) , LEListify <Arg> :: go (arg) ) ;
    }

} ;

template <bool b, class List> class FilterHelp ;

template <class H, class T>
class FilterHelp < true , CONS < H , T > >
{
  public:

    typedef CONS < H , T > Result ;

    static inline Result go ( const CONS < H , T > & x )
    {
      return x ;
    }

};

template <class H, class T>
class FilterHelp < false , CONS < H , T > >
{
  public:

    typedef T Result ;
    static inline Result go ( const CONS < H , T > & x )
    {
      return x . tail ;
    }

} ;

template <class PredThunk, class List> class Filter ;

template <class PT>
class Filter < PT , NIL >
{
  public:

    typedef NIL Result ;

    static inline Result go ( const NIL & x )
    {
      return x ;
    }

} ;

template <class PT, class H, class T>
class Filter < PT , CONS < H , T > >
{
  public:

    static const bool b = (bool)( PT::template Go<int,H>::value ) ;

    typedef FilterHelp < b , CONS < H , T > > Help   ;
    typedef typename Help :: Result           Result ;

    static inline Result go ( const CONS < H , T > & x )
    {
      return Help :: go ( x ) ;
    }

} ;

template <class List, class E> class Contains ;

template <class E>
class Contains < NIL , E >
{
  public:
    static const bool value = false ;
} ;

template <class H, class T, class E>
class Contains < CONS < H , T > , E >
{
  public:
    static const bool value = Contains<T,E>::value ;
} ;

template <class T, class E>
class Contains < CONS < E , T > , E >
{
  public:
    static const bool value = true ;
} ;

template <class F, class List> class Map ;

template <class F>
class Map<F,NIL>
{
  public:

    typedef NIL Result;

    static inline Result go( const NIL & x )
    {
      return x ;
    }
} ;

template <class F, class H, class T>
class Map<F,CONS<H,T> >
{
  public:

    typedef CONS<typename F::template Go<H>::Result,
                 typename Map<F,T>::Result> Result;

    static inline Result go ( const CONS<H,T>& x )
    {
      return Result( F::template Go<H>::go( x.head ),Map<F,T>::go( x.tail ) ) ;
    }

} ;

template <class Op, class E, class List> class Foldr ;

template <class Op, class E>
class Foldr < Op , E , NIL >
{
  public:
    typedef E Result ;
} ;

template <class Op, class E, class H, class T> struct Foldr<Op,E,CONS<H,T> >
{
  public:

    typedef typename Foldr<Op,E,T>::Result          Tmp    ;
    typedef typename Op::template Go<H,Tmp>::Result Result ;

} ;

/****************************************************************************\
 *                                                                          *
 * This file implements currying for functoids.  Included here are          *
 *  - bindMofN   for currying the Mth of N arguments                        *
 *  - Const      for turning a value into a constant function               *
 *  - curryN     curries the first k arguments of an N-arg functoid, where  *
 *               k is the number of arguments "curryN" was called with      *
 *  - CurryableN new way to curry with underscores (e.g. f(_,y,_); )        *
 *                                                                          *
\****************************************************************************/

// Important to implementation of CurryableN classes

Q_FLP_EXPORT extern AutoCurryType _ ; // this is a legal identifier as fcpp::_

//////////////////////////////////////////////////////////////////////
// Const
//////////////////////////////////////////////////////////////////////

template <class T>
class ConstHelper : public CfpType<T>
{
  public:

    ConstHelper ( const T& a ) : x(a) { }

    T operator()() const { return x; }

  protected:

    const T x ;

};

class Const
{
  public:

    template <class T>
    struct Sig : public FunType<T,Full0<ConstHelper<T> > > {} ;

   template <class T>
   Full0<ConstHelper<T> > operator()( const T& x ) const
   {
      return makeFull0( ConstHelper<T>(x) );
   }

};

//////////////////////////////////////////////////////////////////////
// Binders (through "...of2")
//////////////////////////////////////////////////////////////////////

template <class Unary, class Arg>
class binder1of1 : public CfpType<typename RT<Unary,Arg>::ResultType>
{
  public:

   binder1of1( const Unary& x, const Arg& y ) : f(x), a(y) {}
   typename RT<Unary,Arg>::ResultType operator()() const { return f(a); }

  protected:

   const Unary f ;
   const Arg   a ;

};

class Bind1of1
{
  public:

    template <class Unary, class Arg>
    struct Sig : public FunType< Unary, Arg, Full0<binder1of1<Unary,Arg> > > {};

    template <class Unary, class Arg>
    inline Full0<binder1of1<Unary,Arg> >
    operator()( const Unary & f, const Arg & a ) const
    {
      return makeFull0( binder1of1<Unary,Arg>(f,a) ) ;
    }

};

template <class Binary, class Arg1>
class binder1of2
{
  public:

    binder1of2( const Binary& a, const Arg1& b ) : f(a), x(b) {}

    template <class Arg2>
    struct Sig
    : public FunType<typename Binary::template Sig<Arg1,Arg2>::Arg2Type,
                     typename Binary::template Sig<Arg1,Arg2>::ResultType>
    {
    } ;

    template <class Arg2>
    typename Binary::template Sig<Arg1,Arg2>::ResultType
    operator()( const Arg2& y ) const
    {
      return f(x,y);
    }

  protected:

    const Binary f ;
    const Arg1   x ;

};

class Bind1of2
{
  public:

    template <class Binary, class Arg1>
    struct Sig : public FunType<Binary,Arg1,Full1<binder1of2<Binary,Arg1> > > {};

    template <class Binary, class Arg1>
    Full1<binder1of2<Binary,Arg1> >
    operator()( const Binary& f, const Arg1& x ) const
    {
      return makeFull1( binder1of2<Binary,Arg1>(f,x) ) ;
    }
};

template <class Binary, class Arg2>
class binder2of2
{
  public:

    binder2of2( const Binary& a, const Arg2& b ) : f(a), y(b) {}

    template <class Arg1>
    struct Sig
    : public FunType<typename Binary::template Sig<Arg1,Arg2>::Arg1Type,
                     typename Binary::template Sig<Arg1,Arg2>::ResultType>
    {
    };

    template <class Arg1>
    typename Binary::template Sig<Arg1,Arg2>::ResultType
    operator()( const Arg1& x ) const
    {
      return f(x,y);
    }

  protected:

    const Binary f ;
    const Arg2   y ;
};

class Bind2of2
{
  public:

    template <class Binary, class Arg2>
    struct Sig : public FunType<Binary,Arg2,Full1<binder2of2<Binary,Arg2> > > {};

    template <class Binary, class Arg2>
    Full1<binder2of2<Binary,Arg2> >
    operator()( const Binary & f, const Arg2 & y ) const
    {
      return makeFull1( binder2of2<Binary,Arg2>(f,y) );
    }

};

template <class Binary, class Arg1, class Arg2>
class binder1and2of2
: public CfpType<typename RT<Binary,Arg1,Arg2>::ResultType >
{
  public:

    binder1and2of2( const Binary& x, const Arg1& y, const Arg2& z )
    : f(x), a1(y), a2(z)
    {
    }

    typename RT<Binary,Arg1,Arg2>::ResultType
    operator()() const { return f(a1,a2); }

  protected:

    const Binary f  ;
    const Arg1   a1 ;
    const Arg2   a2 ;

};

class Bind1and2of2
{
  public:

    template <class Binary, class Arg1, class Arg2>
    struct Sig
    : public FunType< Binary, Arg1, Arg2,
                      Full0<binder1and2of2<Binary,Arg1,Arg2> > >
    {
    };

    template <class Binary, class Arg1, class Arg2>
    Full0<binder1and2of2<Binary,Arg1,Arg2> >
    operator()( const Binary& f, const Arg1& a1, const Arg2& a2 ) const
    {
      return makeFull0( binder1and2of2<Binary,Arg1,Arg2>(f,a1,a2) ) ;
    }

};

//////////////////////////////////////////////////////////////////////
// Now that bindNof2 are defined, we can define Curryable2, which then
// some of the later binders can use.
//////////////////////////////////////////////////////////////////////

template <class R, class F, class X, class Y>
class Curryable2Helper
{
  public:

    static inline R go ( const F & f , const X & x , const Y & y )
    {
      return f(x,y);
    }

};

template <class R, class F, class Y>
class Curryable2Helper<R,F,AutoCurryType,Y>
{
  public:

    static R go( const F & f, const AutoCurryType & , const Y & y )
    {
      return makeFull1( binder2of2<F,Y>(f,y) );
    }

};

template <class R, class F, class X>
class Curryable2Helper<R,F,X,AutoCurryType>
{
  public:

    static R go ( const F & f, const X & x, const AutoCurryType & )
    {
      return makeFull1( binder1of2<F,X>(f,x) ) ;
    }

};

template <class F>
class Curryable2
{
  public:

    Curryable2( const F& ff ) : f(ff) {}

    template <class X, class Y=void>
    struct Sig
    : public FunType<typename F::template Sig<X,Y>::Arg1Type,
                     typename F::template Sig<X,Y>::Arg2Type,
                     typename RT<F,X,Y>::ResultType> { } ;

    template <class X>
    struct Sig<X,void> : public FunType<X,Full1<binder1of2<F,X> > > { } ;

    template <class Y>
    struct Sig<AutoCurryType,Y>
    : public FunType<AutoCurryType,Y,Full1<binder2of2<F,Y> > >  { } ;

    template <class X>
    struct Sig<X,AutoCurryType>
    : public FunType<X,AutoCurryType,Full1<binder1of2<F,X> > > { } ;

    template <class X>
    typename Sig<X>::ResultType operator()( const X& x ) const
    {
      return makeFull1( binder1of2<F,X>(f,x) ) ;
    }

    template <class X, class Y>
    inline typename Sig<X,Y>::ResultType
    operator()( const X & x, const Y & y ) const
    {
      // need partial specialization, so defer to a class helper
      return Curryable2Helper<typename Sig<X,Y>::ResultType,F,X,Y>::go(f,x,y) ;
    }

  protected:

    const F f ;

};

//////////////////////////////////////////////////////////////////////
// With Curryable2 out of the way, we can go back to the 3-arg binders.
//////////////////////////////////////////////////////////////////////

template <class Ternary, class A1, class A2, class A3>
class binder1and2and3of3 : public CfpType<typename RT<Ternary,A1,A2,A3>::ResultType>
{
  public:
    binder1and2and3of3( const Ternary& w, const A1& x, const A2& y, const A3& z )
    : f(w), a1(x), a2(y), a3(z)
    {
    }

    typename RT<Ternary,A1,A2,A3>::ResultType operator()() const
    {
      return f(a1,a2,a3) ;
    }

  protected:

    const Ternary f  ;
    const A1      a1 ;
    const A2      a2 ;
    const A3      a3 ;

};

class Bind1and2and3of3
{
  public:

    template <class Ternary, class A1, class A2, class A3>
    struct Sig
    : public FunType<Ternary,A1,A2,A3,
                    Full0<binder1and2and3of3<Ternary,A1,A2,A3> > > {};

    template <class Ternary, class A1, class A2, class A3>
    Full0<binder1and2and3of3<Ternary,A1,A2,A3> >
    operator()( const Ternary & f  , const A1 & a1 ,
                const A2      & a2 , const A3 & a3 ) const
    {
      return makeFull0( binder1and2and3of3<Ternary,A1,A2,A3>(f,a1,a2,a3) );
    }
};

template <class Ternary, class Arg1, class Arg2>
class binder1and2of3
{
  public:

    template <class Arg3>
    struct Sig
    : public FunType<typename Ternary::template Sig<Arg1,Arg2,Arg3>::Arg3Type,
                     typename Ternary::template Sig<Arg1,Arg2,Arg3>::ResultType>
    {
    };

    binder1and2of3(const Ternary& w, const Arg1& x, const Arg2& y)
     : f(w), a1(x), a2(y)
    {
    }

    template <class Arg3>
    typename Sig<Arg3>::ResultType
    operator()(const Arg3& z) const { return f(a1,a2,z); }

  protected:

    const Ternary f  ;
    const Arg1    a1 ;
    const Arg2    a2 ;

};

class Bind1and2of3
{
  public:

    template <class Ternary, class A1, class A2>
    struct Sig
    : public FunType<Ternary,A1,A2,Full1<binder1and2of3<Ternary,A1,A2> > >
    {
    };

    template <class Ternary, class A1, class A2>
    Full1<binder1and2of3<Ternary,A1,A2> >
    operator()( const Ternary& f, const A1& a1, const A2& a2 ) const
    {
      return makeFull1( binder1and2of3<Ternary,A1,A2>(f,a1,a2) ) ;
    }

};

template <class Ternary, class Arg2, class Arg3>
class binder2and3of3
{
 public:

    template <class Arg1>
    struct Sig
    : public FunType<typename Ternary::template Sig<Arg1,Arg2,Arg3>::Arg1Type,
                     typename RT<Ternary,Arg1,Arg2,Arg3>::ResultType>
    {
    };
                    // need RT above due to g++ bug on line below
                    // typename Ternary::Sig<Arg1,Arg2,Arg3>::ResultType> {};

    binder2and3of3(const Ternary& w, const Arg2& y, const Arg3& z)
      : f(w), a2(y), a3(z) {}
    template <class Arg1>
    typename Sig<Arg1>::ResultType
    operator()(const Arg1& x) const
    {
      return f(x,a2,a3) ;
    }

  protected:

    const Ternary f  ;
    const Arg2    a2 ;
    const Arg3    a3 ;
};

class Bind2and3of3
{
  public:

    template <class Ternary, class A2, class A3>
    struct Sig
    : public FunType<Ternary,A2,A3,Full1<binder2and3of3<Ternary,A2,A3> > >
    {
    };

    template <class Ternary, class A2, class A3>
    Full1<binder2and3of3<Ternary,A2,A3> >
    operator()( const Ternary& f, const A2& a2, const A3& a3 ) const
    {
      return makeFull1( binder2and3of3<Ternary,A2,A3>(f,a2,a3) ) ;
    }
};

template <class Ternary, class Arg1, class Arg3>
class binder1and3of3
{
  public:

    template <class Arg2>
    struct Sig
    : public FunType<typename Ternary::template Sig<Arg1,Arg2,Arg3>::Arg2Type,
                     typename RT<Ternary,Arg1,Arg2,Arg3>::ResultType>
    {
    };
                    // need RT above due to g++ bug on line below
                    // typename Ternary::Sig<Arg1,Arg2,Arg3>::ResultType> {};

    binder1and3of3(const Ternary& w, const Arg1& x, const Arg3& z)
      : f(w), a1(x), a3(z)
    {
    }

    template <class Arg2>
    typename Sig<Arg2>::ResultType
    operator()(const Arg2& y) const
    {
      return f ( a1 , y , a3 ) ;
    }

  protected:

    const Ternary f  ;
    const Arg1    a1 ;
    const Arg3    a3 ;
};

class Bind1and3of3
{
  public:

    template <class Ternary, class A1, class A3>
    struct Sig
    : public FunType<Ternary,A1,A3,Full1<binder1and3of3<Ternary,A1,A3> > >
    {
    };

    template <class Ternary, class A1, class A3>
    Full1<binder1and3of3<Ternary,A1,A3> >
    operator()( const Ternary& f, const A1& a1, const A3& a3 ) const
    {
      return makeFull1( binder1and3of3<Ternary,A1,A3>(f,a1,a3) );
    }
};

template <class Ternary, class Arg1>
class binder1of3
{
  public:

    binder1of3( const Ternary& a, const Arg1& b ) : f(a), x(b) {}

    template <class Arg2, class Arg3>
    struct Sig
    : public FunType<typename Ternary::template Sig<Arg1,Arg2,Arg3>::Arg2Type,
                     typename Ternary::template Sig<Arg1,Arg2,Arg3>::Arg3Type,
                     typename Ternary::template Sig<Arg1,Arg2,Arg3>::ResultType>
    {
    };

    template <class Arg2, class Arg3>
    typename RT<Ternary,Arg1,Arg2,Arg3>::ResultType
    operator()( const Arg2& y, const Arg3& z ) const
    {
      return f(x,y,z);
    }

  protected:

    const Ternary f ;
    const Arg1    x ;

};

class Bind1of3
{
  public:

    template <class Ternary, class Arg1>
    struct Sig
    : public FunType<Ternary,Arg1,Full2<binder1of3<Ternary,Arg1> > >
    {
    };

    template <class Ternary, class Arg1>
    typename Sig<Ternary,Arg1>::ResultType
    operator()( const Ternary& f, const Arg1& x ) const
    {
      return makeFull2( binder1of3<Ternary,Arg1>(f,x) ) ;
    }

};

template <class Ternary, class Arg2>
class binder2of3
{
  public:

    binder2of3( const Ternary& a, const Arg2& b ) : f(a), x(b) {}

    template <class Arg1, class Arg3>
    struct Sig
    : public FunType<typename Ternary::template Sig<Arg1,Arg2,Arg3>::Arg1Type,
                     typename Ternary::template Sig<Arg1,Arg2,Arg3>::Arg3Type,
                     typename Ternary::template Sig<Arg1,Arg2,Arg3>::ResultType>
    {
    };

    template <class Arg1, class Arg3>
    typename RT<Ternary,Arg1,Arg2,Arg3>::ResultType
    operator()( const Arg1 & y, const Arg3 & z ) const
    {
      return f(y,x,z);
    }

  protected:

    const Ternary f ;
    const Arg2    x ;

};

class Bind2of3
{
  public:

    template <class Ternary, class Arg2>
    struct Sig
    : public FunType<Ternary,Arg2,Full2<binder2of3<Ternary,Arg2> > > {};

    template <class Ternary, class Arg2>
    typename Sig<Ternary,Arg2>::ResultType
    operator()( const Ternary& f, const Arg2& x ) const
    {
      return makeFull2( binder2of3<Ternary,Arg2>(f,x) );
    }
};

template <class Ternary, class Arg3>
class binder3of3
{
  public:

    binder3of3( const Ternary & a, const Arg3 & b ) : f(a), x(b) { }

    template <class Arg1, class Arg2>
    struct Sig
    : public FunType<typename Ternary::template Sig<Arg1,Arg2,Arg3>::Arg1Type,
                     typename Ternary::template Sig<Arg1,Arg2,Arg3>::Arg2Type,
                     typename Ternary::template Sig<Arg1,Arg2,Arg3>::ResultType>
    {
    };

    template <class Arg1, class Arg2>
    typename RT<Ternary,Arg1,Arg2,Arg3>::ResultType
    operator()( const Arg1 & y, const Arg2 & z ) const
    {
      return f ( y , z , x ) ;
    }

  protected:

    const Ternary f ;
    const Arg3    x ;

};

class Bind3of3
{
  public:

    template <class Ternary, class Arg3>
    struct Sig
    : public FunType<Ternary,Arg3,Full2<binder3of3<Ternary,Arg3> > > { } ;

    template <class Ternary, class Arg3>
    typename Sig<Ternary,Arg3>::ResultType
    operator()( const Ternary& f, const Arg3& x ) const
    {
      return makeFull2( binder3of3<Ternary,Arg3>(f,x) ) ;
    }

};

/****************************************************************************\
 *                                                                          *
 * "curry" versions. Now that we have auto-currying, you rarely need to     *
 * call curry() explicitly, unless you are trying to get lazy evaulation    *
 * in examples like                                                         *
 *    curry2( map, f, l ).                                                  *
 * It used to be the case that you might also do                            *
 *    curry2( map, f ),                                                     *
 * but nowadays you can say the same thing with just                        *
 *    map(f).                                                               *
 *                                                                          *
\****************************************************************************/

class Curry3
{
  public:

    template <class Ternary, class A1, class A2 = void, class A3 = void>
    struct Sig
      : public FunType<Ternary, A1, A2, A3,
                       Full0<binder1and2and3of3<Ternary,A1,A2,A3> > >
    {
    };

    template <class Ternary, class A1, class A2>
    struct Sig<Ternary, A1, A2, void>
    : public FunType<Ternary, A1, A2, Full1<binder1and2of3<Ternary,A1,A2> > >
    {
    };

    template <class Ternary, class A1>
    struct Sig<Ternary, A1, void, void>
      : public FunType<Ternary, A1, Full2<binder1of3<Ternary,A1> > >
    {
    };

    template <class Ternary, class A1, class A2, class A3>
    typename Sig<Ternary, A1, A2, A3>::ResultType
    operator()( const Ternary& f, const A1& a1, const A2& a2,
                const A3& a3 ) const
    {
      return makeFull0( binder1and2and3of3<Ternary,A1,A2,A3>(f,a1,a2,a3) ) ;
    }

    template <class Ternary, class A1, class A2>
    typename Sig<Ternary, A1, A2>::ResultType
    operator()( const Ternary& f, const A1& a1, const A2& a2 ) const
    {
      return makeFull1( binder1and2of3<Ternary,A1,A2>(f,a1,a2) ) ;
    }

    template <class Ternary, class A1>
    typename Sig<Ternary, A1>::ResultType
    operator()( const Ternary& f, const A1& a1 ) const
    {
      return makeFull2( binder1of3<Ternary,A1>(f,a1) ) ;
    }

};

class Curry2
{
  public:

    template <class Binary, class A1, class A2 = void>
    struct Sig
    : public FunType<Binary, A1, A2, Full0<binder1and2of2<Binary,A1,A2> > >
    {
    };

    template <class Binary, class A1>
    struct Sig<Binary, A1, void>
    : public FunType<Binary, A1, Full1<binder1of2<Binary,A1> > >
    {
    };

    template <class Binary, class A1, class A2>
    typename Sig<Binary, A1, A2>::ResultType
    operator()( const Binary& f, const A1& a1, const A2& a2 ) const
    {
      return makeFull0( binder1and2of2<Binary,A1,A2>(f,a1,a2) ) ;
    }

    template <class Binary, class A1>
    typename Sig<Binary, A1>::ResultType
    operator()( const Binary& f, const A1& a1 ) const
    {
      return makeFull1( binder1of2<Binary,A1>(f,a1) );
    }

};

class Curry1
{
  public:

    template <class Unary, class A1>
    struct Sig : public FunType<Unary, A1, Full0<binder1of1<Unary,A1> > >
    {
    };

    template <class Unary, class A1>
    typename Sig<Unary, A1>::ResultType
    operator()( const Unary& f, const A1& a1 ) const
    {
      return makeFull0( binder1of1<Unary,A1>(f,a1) ) ;
    }

};

template <class R, class F, class X, class Y, class Z>
class Curryable3Helper
{
  public:

    static inline R go( const F& f, const X& x, const Y& y, const Z& z )
    {
      return f(x,y,z) ;
    }

};

template <class R, class F, class X>
class Curryable3Helper<R,F,X,AutoCurryType,AutoCurryType>
{
  public:

    static R go( const F             & f ,
                 const X             & x ,
                 const AutoCurryType &   ,
                 const AutoCurryType &   )
    {
      return makeFull2( binder1of3<F,X>(f,x) ) ;
    }

};

template <class R, class F, class Y>
class Curryable3Helper<R,F,AutoCurryType,Y,AutoCurryType>
{
  public:

    static R go( const F             & f ,
                 const AutoCurryType &   ,
                 const Y             & y ,
                 const AutoCurryType &   )
    {
      return makeFull2( binder2of3<F,Y>(f,y) ) ;
    }

};

template <class R, class F, class Z>
class Curryable3Helper<R,F,AutoCurryType,AutoCurryType,Z>
{
  public:

    static R go( const F             & f ,
                 const AutoCurryType &   ,
                 const AutoCurryType &   ,
                 const Z             & z )
    {
      return makeFull2( binder3of3<F,Z>(f,z) ) ;
    }

};

template <class R, class F, class Y, class Z>
class Curryable3Helper<R,F,AutoCurryType,Y,Z>
{
  public:

    static R go( const F             & f ,
                 const AutoCurryType &   ,
                 const Y             & y ,
                 const Z             & z )
    {
      return makeFull1( binder2and3of3<F,Y,Z>(f,y,z) ) ;
    }
};

template <class R, class F, class X, class Z>
class Curryable3Helper<R,F,X,AutoCurryType,Z>
{
  public:

    static R go( const F             & f ,
                 const X             & x ,
                 const AutoCurryType &   ,
                 const Z             & z )
    {
      return makeFull1( binder1and3of3<F,X,Z>(f,x,z) ) ;
    }
};

template <class R, class F, class X, class Y>
class Curryable3Helper<R,F,X,Y,AutoCurryType>
{
  public:

    static R go( const F             & f ,
                 const X             & x ,
                 const Y             & y ,
                 const AutoCurryType &   )
    {
      return makeFull1( binder1and2of3<F,X,Y>(f,x,y) ) ;
    }
};

template <class R, class F, class X, class Y>
class Curryable3Helper2
{
  public:

    static R go( const F & f ,
                 const X & x ,
                 const Y & y )
    {
      return makeFull1( binder1and2of3<F,X,Y>(f,x,y) ) ;
    }

};

template <class R, class F, class Y>
class Curryable3Helper2<R,F,AutoCurryType,Y>
{
  public:

    static R go( const F             & f ,
                 const AutoCurryType &   ,
                 const Y             & y )
    {
      return makeFull2(binder2of3<F,Y>(f,y)) ;
    }

};

template <class R, class F, class X>
class Curryable3Helper2<R,F,X,AutoCurryType>
{
  public:

    static R go( const F             & f ,
                 const X             & x ,
                 const AutoCurryType &   )
    {
      return makeFull2(binder1of3<F,X>(f,x));
    }
};

template <class F>
class Curryable3
{
  public:

     Curryable3( const F& ff ) : f(ff)
     {
     }

     template <class X, class Y=void, class Z=void>
     struct Sig
     : public FunType<typename F::template Sig<X,Y,Z>::Arg1Type,
                      typename F::template Sig<X,Y,Z>::Arg2Type,
                      typename F::template Sig<X,Y,Z>::Arg3Type,
                      typename RT<F,X,Y,Z>::ResultType>
     {
     };

     template <class X,class Y> struct Sig<X,Y,void>
     : public FunType<X,Y,Full1<binder1and2of3<F,X,Y> > >
     {
     };

     template <class X> struct Sig<X,AutoCurryType,void>
     : public FunType<X,AutoCurryType,Full2<binder1of3<F,X> > >
     {
     };

     template <class Y> struct Sig<AutoCurryType,Y,void>
     : public FunType<AutoCurryType,Y,Full2<binder2of3<F,Y> > >
     {
     };

     template <class X> struct Sig<X,void,void>
     : public FunType<X,Full2<binder1of3<F,X> > >
     {
     };

     template <class X> struct Sig<X,AutoCurryType,AutoCurryType>
     : public FunType<X,AutoCurryType,AutoCurryType,
                      Full2<binder1of3<F,X> > >
     {
     };

     template <class Y> struct Sig<AutoCurryType,Y,AutoCurryType>
     : public FunType<AutoCurryType,Y,AutoCurryType,
                      Full2<binder2of3<F,Y> > >
     {
     };

     template <class Z> struct Sig<AutoCurryType,AutoCurryType,Z>
     : public FunType<AutoCurryType,AutoCurryType,Z,
                      Full2<binder3of3<F,Z> > >
     {
     };

     template <class X,class Z> struct Sig<X,AutoCurryType,Z>
     : public FunType<X,AutoCurryType,Z,Full1<binder1and3of3<F,X,Z> > >
     {
     };

     template <class Y,class Z> struct Sig<AutoCurryType,Y,Z>
     : public FunType<AutoCurryType,Y,Z,Full1<binder2and3of3<F,Y,Z> > >
     {
     };

     template <class X,class Y> struct Sig<X,Y,AutoCurryType>
     : public FunType<X,Y,AutoCurryType,Full1<binder1and2of3<F,X,Y> > >
     {
     };

     template <class X,class Y>
     typename Sig<X,Y>::ResultType operator()( const X& x, const Y& y ) const
     {
       // need partial specialization, so defer to a class helper
       return Curryable3Helper2<typename Sig<X,Y>::ResultType,F,X,Y>::go(f,x,y);
     }

     template <class X>
     typename Sig<X>::ResultType operator()( const X& x ) const
     {
       return makeFull2(binder1of3<F,X>(f,x));
     }

     template <class X, class Y, class Z>
     inline typename Sig<X,Y,Z>::ResultType
     operator()( const X& x, const Y& y, const Z& z ) const
     {
       // need partial specialization, so defer to a class helper
       return Curryable3Helper<typename Sig<X,Y,Z>::ResultType,F,X,Y,Z>
              :: go ( f , x , y , z ) ;
     }

  protected:

    const F f ;

};

/*****************************************************************************\
 *                                                                           *
 *                               Full functoids                              *
 *                                                                           *
 * Just as Curryable2/Curryable3 serve as wrappers which decorate            *
 * functoids to give them 'curryability', FullN are wrappers to give         *
 * functoids _all_ the 'features' that functoids can have.  The current      *
 * "extra feature set" for functoids is                                      *
 * - curryability     (ability to call with fewer args)                      *
 * - lambda-awareness (operator[] for use inside lambda)                     *
 * - smartness        (inherited typedefs to answer introspective questions) *
 * The FullN classes just combine all of the features into one               *
 * uber-wrapper which does it all.                                           *
 *                                                                           *
 * Don't forget that any features added here need to be added to             *
 * the indirect functoids in function.h, too.                                *
 * And also to the Uncurryable class in prelude.h.                           *
 * FIX THIS take a good look at Uncurry; it may have pre-dated smartness     *
 * and can now be written more sanely...?                                    *
 *                                                                           *
\*****************************************************************************/

template <class F>
class Full0 : public SmartFunctoid0
            , public CfpType<typename RT<F>::ResultType>
{
  public:

    Full0 ( void         ) : f (    ) { }
    Full0 ( const F & ff ) : f ( ff ) { }

    typedef Full0 This ;

    template <class A> typename BracketCallable<This,A>::Result
    operator[]( const A & a ) const
    {
      return BracketCallable < This , A > :: go ( *this , a ) ;
    }

    inline typename RT<F>::ResultType operator()() const
    {
      return f ( ) ;
    }

  protected:

    F f ;
};

template <class F>
class Full1 : public SmartFunctoid1
{
  public:

    Full1 (              ) : f (    ) { }
    Full1 ( const F & ff ) : f ( ff ) { }

    typedef Full1 This ;

    template <class A> typename BracketCallable<This,A>::Result
    operator[]( const A & a ) const
    {
      return BracketCallable<This,A>::go( *this , a ) ;
    }

    template <class T> struct Sig
       : public FunType<typename RT<F,T>::Arg1Type,
                        typename RT<F,T>::ResultType>
    {
    };

    template <class T>
    inline typename Sig<T>::ResultType operator()( const T & x ) const
    {
      return f(x);
    }

  protected:

     F f ;
};

template <class F>
class Full2 : public SmartFunctoid2
{
  public:

    Full2 (              ) : f (    ) { }
    Full2 ( const F & ff ) : f ( ff ) { }

    typedef Full2 This ;

    template <class A> typename BracketCallable<This,A>::Result
    operator[]( const A& a ) const
    {
      return BracketCallable<This,A>::go( *this , a ) ;
    }

    template <class X, class Y=void>
    struct Sig
    : public FunType<typename F::template Sig<X,Y>::Arg1Type,
                     typename F::template Sig<X,Y>::Arg2Type,
                     typename RT<F,X,Y>::ResultType>
    {
    };

    template <class X>
    struct Sig<X,void> : public FunType<X,Full1<binder1of2<F,X> > >
    {
    };

    template <class Y>
    struct Sig<AutoCurryType,Y>
    : public FunType<AutoCurryType,Y,Full1<binder2of2<F,Y> > >
    {
    };

    template <class X>
    struct Sig<X,AutoCurryType>
    : public FunType<X,AutoCurryType,Full1<binder1of2<F,X> > >
    {
    };

    template <class X>
    typename Sig<X>::ResultType operator()( const X & x ) const
    {
      return makeFull1( binder1of2<F,X>(f,x) ) ;
    }

    template <class X, class Y>
    inline typename Sig<X,Y>::ResultType
    operator()( const X & x, const Y & y ) const
    {
      // need partial specialization, so defer to a class helper
      return Curryable2Helper<typename Sig<X,Y>::ResultType,F,X,Y>::go(f,x,y) ;
    }

  protected:

    F f ;

};

template <class F>
class Full3 : public SmartFunctoid3
{
  public:

    Full3 (              ) : f (    ) { }
    Full3 ( const F & ff ) : f ( ff ) { }

    typedef Full3 This ;

    template <class A> typename BracketCallable<This,A>::Result
    operator[]( const A & a ) const
    {
      return BracketCallable<This,A>::go( *this , a ) ;
    }

    template <class X, class Y=void, class Z=void>
    struct Sig
    : public FunType<typename F::template Sig<X,Y,Z>::Arg1Type,
                     typename F::template Sig<X,Y,Z>::Arg2Type,
                     typename F::template Sig<X,Y,Z>::Arg3Type,
                     typename RT<F,X,Y,Z>::ResultType>
    {
    };

    template <class X,class Y> struct Sig<X,Y,void>
    : public FunType<X,Y,Full1<binder1and2of3<F,X,Y> > >
    {
    };

    template <class X> struct Sig<X,AutoCurryType,void>
    : public FunType<X,AutoCurryType,Full2<binder1of3<F,X> > >
    {
    };

    template <class Y> struct Sig<AutoCurryType,Y,void>
    : public FunType<AutoCurryType,Y,Full2<binder2of3<F,Y> > >
    {
    };

    template <class X> struct Sig<X,void,void>
    : public FunType<X,Full2<binder1of3<F,X> > >
    {
    };

    template <class X> struct Sig<X,AutoCurryType,AutoCurryType>
    : public FunType<X,AutoCurryType,AutoCurryType,
                     Full2<binder1of3<F,X> > >
    {
    };

    template <class Y> struct Sig<AutoCurryType,Y,AutoCurryType>
    : public FunType<AutoCurryType,Y,AutoCurryType,
                     Full2<binder2of3<F,Y> > >
    {
    };

    template <class Z> struct Sig<AutoCurryType,AutoCurryType,Z>
    : public FunType<AutoCurryType,AutoCurryType,Z,
                     Full2<binder3of3<F,Z> > >
    {
    };

    template <class X,class Z> struct Sig<X,AutoCurryType,Z>
    : public FunType<X,AutoCurryType,Z,Full1<binder1and3of3<F,X,Z> > >
    {
    };

    template <class Y,class Z> struct Sig<AutoCurryType,Y,Z>
    : public FunType<AutoCurryType,Y,Z,Full1<binder2and3of3<F,Y,Z> > >
    {
    };

    template <class X,class Y> struct Sig<X,Y,AutoCurryType>
    : public FunType<X,Y,AutoCurryType,Full1<binder1and2of3<F,X,Y> > >
    {
    };

    template <class X,class Y>
    typename Sig<X,Y>::ResultType operator()( const X & x, const Y & y ) const
    {
      // need partial specialization, so defer to a class helper
      return Curryable3Helper2<typename Sig<X,Y>::ResultType,F,X,Y>::go(f,x,y) ;
    }

    template <class X>
    typename Sig<X>::ResultType operator()( const X& x ) const
    {
      return makeFull2(binder1of3<F,X>(f,x)) ;
    }

    template <class X, class Y, class Z>
    inline typename Sig<X,Y,Z>::ResultType
    operator() ( const X& x, const Y& y, const Z& z ) const
    {
      // need partial specialization, so defer to a class helper
      return Curryable3Helper<typename Sig<X,Y,Z>::ResultType,F,X,Y,Z>
             ::go(f,x,y,z) ;
    }

  protected:

    F f ;

};

template <class F> Full0<F> makeFull0( const F& f ) { return Full0<F>(f); }
template <class F> Full1<F> makeFull1( const F& f ) { return Full1<F>(f); }
template <class F> Full2<F> makeFull2( const F& f ) { return Full2<F>(f); }
template <class F> Full3<F> makeFull3( const F& f ) { return Full3<F>(f); }

/****************************************************************************\
 *                                                                          *
 * Literate error messages look nicer when emitted as compiler              *
 * diagnostics when they're not deeply nested inside classes, so we move    *
 * them all out to the 'top' level of this namespace here.                  *
 *                                                                          *
\****************************************************************************/

template <class Actual, class Given, bool b>
class TheActualTypeOfTheLambdaExpressionIsNotConvertibleToItsGivenType ;

template <class Actual, class Given>
class TheActualTypeOfTheLambdaExpressionIsNotConvertibleToItsGivenType
<Actual,Given,true>
{
  public:

    typedef int Error ;

} ;

template <class FreeVars>
class YouCannotInvokeALambdaContainingFreeVars { } ;

template <class Dummy, bool b>
class TheTypeSpecYouHaveGivenIsIncompatibleWithItsLE ;

template <class Dummy>
class TheTypeSpecYouHaveGivenIsIncompatibleWithItsLE<Dummy,true>
{
  public:

    typedef int Error ;

} ;

template <class EE, bool b>
class IfExpressionMustHaveTypeConvertibleToBool ;

template <class EE>
class IfExpressionMustHaveTypeConvertibleToBool<EE,true>
{
  public:

    typedef EE Type ;

};

template <class TT, class FF, bool b>
class ActualTypeOfFalseBranchMustBeImplicitlyConvertibleToTypeOfTrueBranch ;

template <class TT, class FF>
class ActualTypeOfFalseBranchMustBeImplicitlyConvertibleToTypeOfTrueBranch
<TT,FF,true>
{
  public:

    typedef TT Error ;

};

template <class FF, class TT, bool b>
class ActualTypeOfTrueBranchMustBeImplicitlyConvertibleToTypeOfFalseBranch ;

template <class FF, class TT>
class ActualTypeOfTrueBranchMustBeImplicitlyConvertibleToTypeOfFalseBranch
<FF,TT,true>
{
  public:

    typedef FF Error ;

};

template <class TT, class FF>
class TrueAndFalseBranchOfIfMustHaveSameType ;

template <class TT>
class TrueAndFalseBranchOfIfMustHaveSameType<TT,TT>
{
  public:
    typedef TT Type ;
};

template <bool b>
class YouCannotPassTheSameLambdaVarTo_lambda_MoreThanOnce ;

template <>
class YouCannotPassTheSameLambdaVarTo_lambda_MoreThanOnce<false>
{
  public:

    static inline void go() {}

};

//////////////////////////////////////////////////////////////////////
// Useful helpers
//////////////////////////////////////////////////////////////////////

template <int   i> class LambdaVar;
template <class T> class Value;

template <class T>
class ThunkifyType
{
  public:

    struct Result
    {
      template <class Dummy> struct Go
      {
         typedef T Type ;
      };
    };

};

//////////////////////////////////////////////////////////////////////
// Environment stuff
//////////////////////////////////////////////////////////////////////

// I seem to recall that
//   ET - Environment Thunk
//   BE - Binding Environment
//   TE - Type Environment
// Yes.  See pre_lambda.h for a little more explanation.

class NIL_ET
{
  public:

    template <class Dummy> struct Go
    {
      typedef NIL TE;
      typedef NIL BE;
    };

};

template <class OldET, class LVList>
class EraseLVsFromET
{
  public:

   struct Result
   {
     template <class Dummy> struct Go
     {
       typedef typename OldET::template Go<Dummy>::TE TE1 ;
       typedef typename OldET::template Go<Dummy>::BE BE1 ;

       struct BPred
       {
         template <class DumDum, class BEP> struct Go;
         template <class D, int i, class LE> struct Go<D,BEPair<i,LE> >
         {
           static const bool value = !(Contains<LVList,LambdaVar<i> >::value) ;
         } ;
       } ;

       typedef Filter<BPred,BE1>   BF ;
       typedef typename BF::Result BE ;
       static inline BE go( const BE1& x ) { return BF::go(x); }

       struct TPred
       {
         template <class DumDum, class TEP> struct Go;
         template <class D, int i, class T> struct Go<D,TEPair<i,T> >
         {
           static const bool value = !(Contains<LVList,LambdaVar<i> >::value) ;
         } ;
       } ;

       typedef Filter<TPred,TE1>   TF ;
       typedef typename TF::Result TE ;

     } ;
   } ;

} ;

template <class ET1, int i, class X>
class ETUpdateX
{
  public:

    struct Result
    {
      template <class Dummy> class Go
      {
        public:

          typedef CONS<LambdaVar<i>,NIL>                   BoundVars ;
          typedef typename ET1::template Go<Dummy>::BE           BE1 ;
          typedef typename EraseLVsFromET<ET1,BoundVars>::Result ET2 ;
          typedef typename ET2::template Go<Dummy>::TE           TE2 ;
          typedef typename ET2::template Go<Dummy>::BE           BE2 ;
//          typedef typename Value<X>                              LEX ;
          typedef Value<X>                                       LEX ;
          typedef BEPair<i,LEX>                                  BEX ;
          typedef CONS<BEX,BE2>                                  BE  ;
          typedef typename ThunkifyType<X>::Result               XTT ;
          typedef TEPair<i,XTT>                                  TEX ;
          typedef CONS<TEX,TE2>                                  TE  ;

          static inline BE go( const BE1 & be, const X & x )
          {
            return BE( BEX(LEX(x)), ET2::template Go<Dummy>::go(be) ) ;
          }
      } ;
    } ;
};

template <class ET1, int i, class X, int j, class Y>
class ETUpdateXY
{
  public:

    class Result
    {
      public:

        template <class Dummy> class Go
        {
          public:

            typedef CONS<LambdaVar<i>,CONS<LambdaVar<j>,NIL> > BoundVars ;
            typedef typename ET1::template Go<Dummy>::BE             BE1 ;
            typedef typename EraseLVsFromET<ET1,BoundVars>::Result   ET2 ;
            typedef typename ET2::template Go<Dummy>::TE             TE2 ;
            typedef typename ET2::template Go<Dummy>::BE             BE2 ;
//            typedef typename Value<X>                                LEX ;
            typedef Value<X>                                         LEX ;
            typedef BEPair<i,LEX>                                    BEX ;
//            typedef typename Value<Y>                                LEY ;
            typedef Value<Y>                                         LEY ;
            typedef BEPair<j,LEY>                                    BEY ;
            typedef CONS<BEY,BE2>                                    YBE ;
            typedef CONS<BEX,YBE>                                    BE  ;
            typedef typename ThunkifyType<X>::Result                 XTT ;
            typedef TEPair<i,XTT>                                    TEX ;
            typedef typename ThunkifyType<Y>::Result                 YTT ;
            typedef TEPair<j,YTT>                                    TEY ;
            typedef CONS<TEX,CONS<TEY,TE2> >                         TE  ;

            static inline BE go( const BE1 & be, const X & x, const Y & y )
            {
              return BE( BEX(LEX(x)), YBE( BEY(LEY(y))       ,
                         ET2::template Go<Dummy>::go(be) ) ) ;
            }

        } ;
    } ;

} ;

template <class ET1, int i, class X, int j, class Y, int k, class Z>
class ETUpdateXYZ
{
  public:

    class Result
    {
      public:

        template <class Dummy> class Go
        {
          public:

            typedef CONS<LambdaVar<i>,CONS<LambdaVar<j> ,
                    CONS<LambdaVar<k>,NIL> >            >    BoundVars ;
            typedef typename ET1::template Go<Dummy>::BE           BE1 ;
            typedef typename EraseLVsFromET<ET1,BoundVars>::Result ET2 ;
            typedef typename ET2::template Go<Dummy>::TE           TE2 ;
            typedef typename ET2::template Go<Dummy>::BE           BE2 ;
//            typedef typename Value<X>                              LEX ;
            typedef Value<X>                                       LEX ;
            typedef BEPair<i,LEX>                                  BEX ;
//            typedef typename Value<Y>                              LEY ;
            typedef Value<Y>                                       LEY ;
            typedef BEPair<j,LEY>                                  BEY ;
//            typedef typename Value<Z>                              LEZ ;
            typedef Value<Z>                                       LEZ ;
            typedef BEPair<k,LEZ>                                  BEZ ;
            typedef CONS<BEZ,BE2>                                  ZBE ;
            typedef CONS<BEY,ZBE>                                  YBE ;
            typedef CONS<BEX,YBE>                                  BE  ;
            typedef typename ThunkifyType<X>::Result               XTT ;
            typedef TEPair<i,XTT>                                  TEX ;
            typedef typename ThunkifyType<Y>::Result               YTT ;
            typedef TEPair<j,YTT>                                  TEY ;
            typedef typename ThunkifyType<Z>::Result               ZTT ;
            typedef TEPair<k,ZTT>                                  TEZ ;
            typedef CONS<TEX,CONS<TEY,CONS<TEZ,TE2> > >            TE  ;

            static inline BE go( const BE1 & be ,
                                 const X   & x  ,
                                 const Y   & y  ,
                                 const Z   & z  )
            {
              return BE( BEX ( LEX ( x      )                         ) ,
                         YBE ( BEY ( LEY(y) ) , ZBE ( BEZ ( LEZ ( z ) ) ,
                         ET2::template Go<Dummy>::go(be)          ) ) ) ;
            }
        } ;
    } ;
} ;

//////////////////////////////////////////////////////////////////////
// The lambda expression types, all defined right together here
// in one big batch
//////////////////////////////////////////////////////////////////////

template <class X>
class LambdaExp : public LEBase
{
  public:

    LambdaExp( const X & xx ) : x(xx) { EnsureLE<X>::go(); }

    typedef typename X::FreeVars FreeVars;

    template <class EnvThunk> struct MyType
    {
      typedef typename X::template MyType<EnvThunk>::TypeThunk TypeThunk;
    };

    template <class EnvThunk> struct RecheckType
    {
      typedef typename X::template RecheckType<EnvThunk>::Ok Ok;
    };

    template <class EnvThunk>
    typename MyType<EnvThunk>::TypeThunk::template Go<int>::Type
    eval( const typename EnvThunk::template Go<int>::BE & be ) const
    {
      return x.template eval<EnvThunk>( be );
    }

    typedef LambdaExp This;
    template <class A> typename BracketCallable<This,A>::Result
    operator[]( const A & a ) const
    {
      return BracketCallable<This,A>::go( *this , a );
    }

  protected:

    X x ;

};

template <class T>
class Value : public LEBase
{
  public:

    Value ( const T& x ) : data(x) { }

    typedef NIL FreeVars ;

    template <class EnvThunk> struct MyType
    {
      struct TypeThunk
      {
        template <class Dummy> struct Go
        {
          typedef T Type ;
        };
      };
    };

    template <class EnvThunk> struct RecheckType { typedef int Ok; } ;

    template <class EnvThunk>
    typename MyType<EnvThunk>::TypeThunk::template Go<int>::Type
    eval( const typename EnvThunk::template Go<int>::BE & ) const
    {
      return data ;
    }

    typedef Value This ;

    template <class A> typename BracketCallable<This,A>::Result
    operator[]( const A& a ) const
    {
      return BracketCallable<This,A>::go( *this , a ) ;
    }

  protected:

    T data ;

};

template <int i>
class LambdaVar : public LEBase
{ // 'ii' is used to get around what appears to be a g++ bug...
  public:

    template <class Dummy, int ii, class TE> struct Lookup;

    template <class D, int ii, class T, class Rest>
    struct Lookup<D,ii,CONS<TEPair<ii,T>,Rest> >
    {
      typedef typename T::template Go<int>::Type Type ;
    } ;

    template <class D, int ii, class TEP, class Rest>
    struct Lookup<D,ii,CONS<TEP,Rest> >
    {
      typedef typename Lookup<D,ii,Rest>::Type Type ;
    } ;

  private:

    template <class Dummy    ,
              int   ii       ,
              class Result   ,
              class EnvThunk ,
              class BE       ,
              class WBE      > struct Find ;

    template <class D    ,
              int   ii   ,
              class R    ,
              class ET   ,
              class LE   ,
              class Rest ,
              class WBE  >
    struct Find<D,ii,R,ET,CONS<BEPair<ii,LE>,Rest>,WBE>
    {
      static inline R go( const CONS<BEPair<ii,LE>,Rest> & be  ,
                          const WBE                      & wbe )
      {
        return be.head.value.template eval<ET>(wbe) ;
      }
    } ;

    template <class D    ,
              int   ii   ,
              class R    ,
              class ET   ,
              class BEP  ,
              class Rest ,
              class WBE  >
    struct Find<D,ii,R,ET,CONS<BEP,Rest>,WBE>
    {
      static inline R go( const CONS<BEP,Rest>& be, const WBE & wbe )
      {
        return Find<D,ii,R,ET,Rest,WBE>::go( be.tail , wbe ) ;
      }
    };

  public:

    typedef CONS<LambdaVar,NIL> FreeVars ;

    template <class EnvThunk> struct MyType
    {
      struct TypeThunk
      {
        template <class Dummy> struct Go
        {
          typedef typename EnvThunk::template Go<Dummy>::TE TE   ;
          typedef typename Lookup<int,i,TE>::Type           Type ;
        } ;
      } ;
    } ;

    template <class EnvThunk> struct RecheckType { typedef int Ok; } ;

    template <class EnvThunk>
    typename MyType<EnvThunk>::TypeThunk::template Go<int>::Type
    eval ( const typename EnvThunk::template Go<int>::BE& be ) const
    {
      typedef
         typename MyType<EnvThunk>::TypeThunk::template Go<int>::Type Result ;
      typedef typename EnvThunk::template Go<int>::BE BE;
      return Find<int,i,Result,EnvThunk,BE,BE>::go(be,be) ;
    }

    typedef LambdaVar This;
    template <class A> typename BracketCallable<This,A>::Result
    operator[] ( const A & a ) const
    {
      return BracketCallable<This,A>::go( *this , a );
    }

};

template <class Fun, class Args>
class Call : public LEBase
{
  public:

    template <class ET, class F, class A> struct TypeHelper ;

    template <class ET, class F>
    struct TypeHelper<ET,F,NIL>
    {
      typedef typename RT<F>::ResultType Type;
    } ;

    template <class ET, class F, class A1>
    struct TypeHelper<ET,F,CONS<A1,NIL> >
    {
      typedef typename A1::template MyType<ET>::TypeThunk XTT  ;
      typedef typename XTT::template Go<int>::Type        X    ;
      typedef typename RT<F,X>::ResultType                Type ;
    } ;

    template <class ET, class F, class A1, class A2>
    struct TypeHelper<ET,F,CONS<A2,CONS<A1,NIL> > >
    {
      typedef typename A1::template MyType<ET>::TypeThunk XTT  ;
      typedef typename XTT::template Go<int>::Type        X    ;
      typedef typename A2::template MyType<ET>::TypeThunk YTT  ;
      typedef typename YTT::template Go<int>::Type        Y    ;
      typedef typename RT<F,X,Y>::ResultType              Type ;
    } ;

    template <class ET, class F, class A1, class A2, class A3>
    struct TypeHelper<ET,F,CONS<A3,CONS<A2,CONS<A1,NIL> > > >
    {
      typedef typename A1::template MyType<ET>::TypeThunk XTT  ;
      typedef typename XTT::template Go<int>::Type        X    ;
      typedef typename A2::template MyType<ET>::TypeThunk YTT  ;
      typedef typename YTT::template Go<int>::Type        Y    ;
      typedef typename A3::template MyType<ET>::TypeThunk ZTT  ;
      typedef typename ZTT::template Go<int>::Type        Z    ;
      typedef typename RT<F,X,Y,Z>::ResultType            Type ;
    } ;

    template <class ET, class LEL> struct CheckHelper ;

    template <class ET>
    struct CheckHelper<ET,NIL> { typedef int Result; } ;

    template <class ET, class H, class T>
    struct CheckHelper<ET,CONS<H,T> >
    {
      typedef typename AlwaysFirst<typename H::template RecheckType<ET>::Ok,
         typename CheckHelper<ET,T>::Result>::Type Result;
    };

    template <class Result, class ET, class BE, class Args_> struct EvalHelp ;

    template <class R, class ET, class BE>
    struct EvalHelp<R,ET,BE,NIL>
    {
      static inline R go( const Fun& f, const NIL&, const BE& be )
      {
        return (f.template eval<ET>(be))() ;
      }
    };

    template <class R, class ET, class BE, class A1>
    struct EvalHelp<R,ET,BE,CONS<A1,NIL> >
    {
      static inline R go( const Fun& f, const CONS<A1,NIL>& a, const BE& be )
      {
        return (f.template eval<ET>(be))(a.head.template eval<ET>(be)) ;
      }
    };

    template <class R, class ET, class BE, class A1, class A2>
    struct EvalHelp<R,ET,BE,CONS<A2,CONS<A1,NIL> > >
    {
      static inline R go( const Fun                    & f  ,
                          const CONS<A2,CONS<A1,NIL> > & a  ,
                          const BE                     & be )
      {
        return (f.template eval<ET>(be))            (
                a.tail.head.template eval<ET>(be)   ,
                a     .head.template eval<ET>(be) ) ;
      }
    };

    template <class R, class ET, class BE, class A1, class A2, class A3>
    struct EvalHelp<R,ET,BE,CONS<A3,CONS<A2,CONS<A1,NIL> > > >
    {
      static inline R go( const Fun                              & f  ,
                          const CONS<A3,CONS<A2,CONS<A1,NIL> > > & a  ,
                          const BE                               & be )
      {
        return (f.template eval<ET>(be))                 (
                a.tail.tail.head.template eval<ET>(be)   ,
                a.     tail.head.template eval<ET>(be)   ,
                a.          head.template eval<ET>(be) ) ;
      }
    };

    struct FoldrOp
    {
      template <class LE, class FVList> struct Go
      {
        typedef typename AppendList<typename LE::FreeVars,FVList>::Result
          Result ;
      } ;
    } ;

    typedef typename Foldr<FoldrOp,NIL,CONS<Fun,Args> >::Result
      AccumulatedFreeVars ;

    Call( const Fun& f, const Args& a ) : fun(f), args(a)
    {
      EnsureLE<Fun>::go(); EnsureLEList<Args>::go() ;
    }

    typedef typename RemoveDuplicates<AccumulatedFreeVars>::Result FreeVars;
    template <class EnvThunk> struct MyType
    {
      struct TypeThunk
      {
        template <class Dummy> struct Go
        {
          typedef typename Fun::template MyType<EnvThunk>::TypeThunk FTT  ;
          typedef typename FTT::template Go<Dummy>::Type             F    ;
          typedef typename TypeHelper<EnvThunk,F,Args>::Type         Type ;
        } ;
      } ;
    } ;

    template <class EnvThunk>
    struct RecheckType
    {
      typedef typename CheckHelper<EnvThunk,CONS<Fun,Args> >::Result Ok ;
    } ;

    template <class ET>
    typename MyType<ET>::TypeThunk::template Go<int>::Type
    eval ( const typename ET::template Go<int>::BE& be ) const
    {
      typedef typename ET::template Go<int>::BE                      BE     ;
      typedef typename MyType<ET>::TypeThunk::template Go<int>::Type Result ;
      return EvalHelp<Result,ET,BE,Args>::go(fun,args,be)                   ;
    }

    typedef Call This;

    template <class A> typename BracketCallable<This,A>::Result
    operator[]( const A& a ) const
    {
      return BracketCallable<This,A>::go( *this , a ) ;
    }

  protected:

    Fun  fun  ;
    Args args ;

};

// This is a weird special class only BindingEnvExp below uses...
template <class RealET, class LE, class FV, class BE1, class B>
class AddEnvLE : public LEBase
{
  public:

    AddEnvLE( const LE& e, const BE1& x, const B& y ) : exp(e), be1(x), b(y)
    {
    }

    typedef FV FreeVars ;

    template <class EnvThunk> struct MyType
    {
      struct TypeThunk
      {
        template <class Dummy> struct Go
        {
          typedef typename LE   :: template MyType<RealET>::TypeThunk LETT ;
          typedef typename LETT :: template Go    <Dummy >::Type      Type ;
        };
      };
    };

    template <class EnvThunk> struct RecheckType
    {
      typedef typename LE::template RecheckType<RealET>::Ok Ok ;
    };

    template <class EnvThunk>
    typename MyType<RealET>::TypeThunk::template Go<int>::Type
    eval( const typename EnvThunk::template Go<int>::BE& ) const
    {
      return exp.template eval<RealET>( RealET::template Go<int>::go(be1,b) ) ;
    }

    typedef AddEnvLE This;

    template <class A> typename BracketCallable<This,A>::Result
    operator[]( const A & a ) const
    {
      return BracketCallable<This,A>::go( *this , a ) ;
    }

  protected:

    LE  exp ;
    BE1 be1 ;
    B   b   ;

} ;

template <class B, class LE>
class BindingEnvExp : public LEBase
{ // letrec semantics
  protected:

    B  binders ;
    LE exp     ;

    template <class Dummy, class BinderList> struct AccumFree ;

    template <class D> struct AccumFree<D,NIL>
    {
      typedef NIL Result ;
    } ;

    template <class D, int i, class LEa, class Rest>
    struct AccumFree<D,CONS<Binder<i,LEa>,Rest> >
    {
      typedef typename AppendList<typename LEa::FreeVars,
         typename AccumFree<D,Rest>::Result>::Result Result ;
    } ;

    template <class Dummy, class BinderList> struct AccumBound ;

    template <class D> struct AccumBound<D,NIL>
    {
      typedef NIL Result ;
    } ;

    template <class D, int i, class LEa, class Rest>
    struct AccumBound<D,CONS<Binder<i,LEa>,Rest> >
    {
      typedef CONS<LambdaVar<i>,typename AccumBound<D,Rest>::Result> Result ;
    } ;

  public:

    typedef typename AccumBound<int,B>::Result NewlyBoundVars    ;
    typedef typename AccumFree <int,B>::Result FreeVarsInBinders ;

    // In order to compute the environment for "exp", we must follow
    // these steps:
    //  - Call the outer env E1
    //  - foreach lv in lhs of binders, erase lv-entries from E1 => E2
    //  - foreach binder in binders, add <binder.lhs,AddEnvLE<E3>(binder.rhs)>
    //    BE/TE pair to E2 => E3
    // Now exp should be evaled in E3.

    template <class Inner, class ET3>
    struct UnusualTTHelper
    {
      template <class DumDum>
      struct Go
      {
        typedef typename Inner::template MyType<ET3   >::TypeThunk ITT  ;
        typedef typename ITT  ::template Go    <DumDum>::Type      Type ;
      } ;
    };

    // Note the trick; we take the very result we are computing (ET3) as
    // a template parameter!  Ha ha!  Darn I'm clever.  :)
    template <class ET2, class ET3, class BinderList, class NBV,
              class BE1, class BB> struct Env3FromEnv2 ;

    template <class ET2, class ET3, class NBV, class BE1, class BB>
    struct Env3FromEnv2<ET2,ET3,NIL,NBV,BE1,BB>
    {
      struct Result
      {
        template <class Dummy> struct Go
        {
          typedef typename ET2::template Go<Dummy>::TE TE ;
          typedef typename ET2::template Go<Dummy>::BE BE ;
          static inline BE go( const BE  & x ,
                               const NIL &   ,
                               const BE1 &   ,
                               const BB  &   )
          {
            return x ;
          }
        } ;
      } ;
    } ;

    template <class ET2  ,
              class ET3  ,
              int   i    ,
              class LEa  ,
              class Rest ,
              class NBV  ,
              class BE1  ,
              class BB   >
    struct Env3FromEnv2<ET2,ET3,CONS<Binder<i,LEa>,Rest>,NBV,BE1,BB>
    {
      struct Result
      {
        template <class Dummy> struct Go
        {
          typedef typename ET2::template Go<Dummy>::BE         BE2     ;

          typedef typename
            Env3FromEnv2<ET2,ET3,Rest,NBV,BE1,BB>::Result      Recurse ;

          typedef typename
            ListDifference<typename LEa::FreeVars,NBV>::Result LEFV    ;

          // Inner will capture the letrec environment (by value)
          typedef AddEnvLE<ET3,LEa,LEFV,BE1,BB> Inner;

          typedef BEPair<i,Inner> BEP;

          typedef CONS<BEP,typename Recurse::template Go<Dummy>::BE> BE ;

          typedef UnusualTTHelper<Inner,ET3> TT ;
          typedef TEPair<i,TT> TEP ;
          typedef CONS<TEP,typename Recurse::template Go<Dummy>::TE> TE ;

          static inline BE go( const BE2                      & be      ,
                               const CONS<Binder<i,LEa>,Rest> & binders ,
                               const BE1                      & be1     ,
                               const BB                       & b       )
          {
            return BE( BEP(Inner(binders.head.exp,be1,b))                   ,
                   Recurse::template Go<Dummy>::go(be,binders.tail,be1,b) ) ;
          }

        } ;
      } ;
    } ;

    template <class OrigET>
    struct MakeNewET
    {
      struct Result
      {
        template <class Dummy> struct Go
        {
          typedef typename OrigET::template Go<Dummy>::BE BE1 ;

          typedef typename EraseLVsFromET<OrigET,NewlyBoundVars>::Result E2 ;

          // Here is the trick to tie the recursive knot:
          typedef typename
            Env3FromEnv2<E2,Result,B,NewlyBoundVars,BE1,B>::Result E3 ;

          typedef typename E3::template Go<Dummy>::BE BE;

          typedef typename E3::template Go<Dummy>::TE TE;

          static inline BE go ( const BE1 & be, const B & binders )
          {
            return E3::template Go<Dummy>::go(
                   E2::template Go<Dummy>::go(be), binders, be, binders );
          }
        } ;
      } ;
    } ;

  private:

    template <class NewET, class BinderList> struct CheckHelp ;

    template <class ET> struct CheckHelp<ET,NIL>
    {
      typedef int Result;
    } ;

    template <class ET, int i, class LEa, class Rest>
    struct CheckHelp<ET,CONS<Binder<i,LEa>,Rest> >
    {
      typedef typename LEa::template RecheckType<ET>::Ok ThisOne ;
      typedef typename AlwaysFirst<ThisOne,
         typename CheckHelp<ET,Rest>::Result>::Type Result ;
    } ;

  public:

    BindingEnvExp( const B& g, const LE& e ) : binders(g), exp(e)
    {
      EnsureBinderList < B  > :: go ( ) ;
      EnsureLE         < LE > :: go ( ) ;
    }

    typedef typename RemoveDuplicates<typename ListDifference<
      typename AppendList<FreeVarsInBinders,typename LE::FreeVars>::Result,
      NewlyBoundVars>::Result>::Result FreeVars ;

    template <class ET> struct MyType
    {
      typedef typename LE::template MyType<typename
         MakeNewET<ET>::Result>::TypeThunk TypeThunk ;
    };

    template <class ET> struct RecheckType
    {
      typedef typename MakeNewET<ET>::Result NET;
      typedef typename AlwaysFirst<
         typename LE::template RecheckType<NET>::Ok,
         typename CheckHelp<NET,B>::Result>::Type Ok ;
    } ;

    template <class EnvThunk>
    typename MyType<EnvThunk>::TypeThunk::template Go<int>::Type
    eval( const typename EnvThunk::template Go<int>::BE & be ) const
    {
      typedef typename MakeNewET<EnvThunk>::Result NET;
      return exp.template eval<NET>( NET::template Go<int>::go(be,binders) );
    }

    typedef BindingEnvExp This ;

    template <class A> typename BracketCallable<This,A>::Result
    operator[]( const A& a ) const
    {
      return BracketCallable<This,A>::go( *this , a ) ;
    }

} ;

template <class LE, class TBBV>  // To-Be-Bound Vars, in correct order
class LambdaExpWithFreeVars : public LEBase
{
  protected:
    // This class's name isn't great; nearly every kind of lambda
    // expression has free variables. Specifically, this class is about
    // such LEs which are created like so:
    //    lambda(X)[ f[X,Y] ]
    // LEs which, when evaluated, will result in a functoid which
    // captures a particular outer binding environment.
    LE exp ;

  public:

    template <class LEa, class ET>
    class Lambda0WithFreeVars : public CfpType<typename LEa::template
            MyType<ET>::TypeThunk::template Go<int>::Type>
    {
      protected:

        typedef typename ET::template Go<int>::BE BE  ;
        LEa                                       exp ;
        BE                                        env ;

      public:

        Lambda0WithFreeVars( const LEa& e, const BE& be ) : exp(e), env(be) {}

        typename AlwaysFirst<typename LEa::template MyType<ET>::TypeThunk
          ::template Go<int>::Type, typename LEa::template
          RecheckType<ET>::Ok>::Type
        operator()() const
        {
          return exp.template eval<ET>( env ) ;
        }

    } ;

    template <class LEa, class ET, int i>
    class Lambda1WithFreeVars
    {
      protected:

        typedef typename ET::template Go<int>::BE BE  ;
        LEa                                       exp ;
        BE                                        env ;

        template <class X> struct NewET
        {
          typedef typename ETUpdateX<ET,i,X>::Result Result ;
        } ;

      public:

         Lambda1WithFreeVars( const LEa& e, const BE& be ) : exp(e), env(be)
         {
         }

         template <class X> struct Sig : public FunType<X,
            typename LEa::template MyType<typename NewET<X>::Result>
            ::TypeThunk::template Go<int>::Type>
         {
         } ;

         template <class X>
         typename Sig<X>::ResultType
         operator()( const X& x ) const
         {
           return exp.template eval<typename NewET<X>::Result>
            ( NewET<X>::Result::template Go<int>::go( env, x ) ) ;
         }

    } ;

    template <class LEa, class ET, int i, int j>
    class Lambda2WithFreeVars
    {
      protected:

        typedef typename ET::template Go<int>::BE BE  ;
        LEa                                       exp ;
        BE                                        env ;

        template <class X, class Y> struct NewET
        {
          typedef typename ETUpdateXY<ET,i,X,j,Y>::Result Result ;
        } ;

      public:

        Lambda2WithFreeVars( const LEa& e, const BE& be ) : exp(e), env(be)
        {
        }

        template <class X, class Y> struct Sig : public FunType<X,Y,
          typename LEa::template MyType<typename NewET<X,Y>::Result>
          ::TypeThunk::template Go<int>::Type>
        {
        } ;

        template <class X, class Y>
        typename Sig<X,Y>::ResultType
        operator()( const X& x, const Y& y ) const
        {
          return exp.template eval<typename NewET<X,Y>::Result>
            ( NewET<X,Y>::Result::template Go<int>::go( env, x, y ) ) ;
        }

    } ;

    template <class LEa, class ET, int i, int j, int k>
    class Lambda3WithFreeVars
    {
      protected:

        typedef typename ET::template Go<int>::BE BE  ;
        LEa                                       exp ;
        BE                                        env ;

        template <class X, class Y, class Z> struct NewET
        {
          typedef typename ETUpdateXYZ<ET,i,X,j,Y,k,Z>::Result Result ;
        } ;

      public:

        Lambda3WithFreeVars( const LEa& e, const BE& be ) : exp(e), env(be)
        {
        }

        template <class X, class Y, class Z> struct Sig
            : public FunType<X,Y,Z,
              typename LEa::template MyType<typename NewET<X,Y,Z>::Result>
              ::TypeThunk::template Go<int>::Type>
        {
        } ;

        template <class X, class Y, class Z>
        typename Sig<X,Y,Z>::ResultType
        operator()( const X& x, const Y& y, const Z& z ) const
        {
          return exp.template eval<typename NewET<X,Y,Z>::Result>
            ( NewET<X,Y,Z>::Result::template Go<int>::go( env, x, y, z ) ) ;
        }

    } ;

    template <class LEa, class ET, class TBBVars>
    struct NumBoundVarsHelp ;

    template <class LEa, class ET>
    struct NumBoundVarsHelp<LEa,ET,NIL>
    {
      typedef Lambda0WithFreeVars<LEa,ET> Lam  ;
      typedef Full0<Lam>                  Full ;
    };

    template <class LEa, class ET, int i>
    struct NumBoundVarsHelp<LEa,ET,CONS<LambdaVar<i>,NIL> >
    {
      typedef Lambda1WithFreeVars<LEa,ET,i> Lam  ;
      typedef Full1<Lam>                    Full ;
    };

    template <class LEa, class ET, int i, int j>
    struct NumBoundVarsHelp<LEa,ET,CONS<LambdaVar<i>,CONS<LambdaVar<j>,
            NIL> > >
    {
      typedef Lambda2WithFreeVars<LEa,ET,i,j> Lam  ;
      typedef Full2<Lam>                      Full ;
    };

    template <class LEa, class ET, int i, int j, int k>
    struct NumBoundVarsHelp<LEa,ET,CONS<LambdaVar<i>,CONS<LambdaVar<j>,
            CONS<LambdaVar<k>,NIL> > > >
    {
      typedef Lambda3WithFreeVars<LEa,ET,i,j,k> Lam;
      typedef Full3<Lam> Full;
    };

    LambdaExpWithFreeVars( const LE& e ) : exp(e)
    {
      EnsureLE<LE>::go() ;
    }

    typedef typename RemoveDuplicates<typename ListDifference<typename
      LE::FreeVars,TBBV>::Result>::Result FreeVars ;

    template <class ET> struct MyType
    {
      typedef typename NumBoundVarsHelp<LE,ET,TBBV>::Full Full      ;
      typedef typename ThunkifyType<Full>::Result         TypeThunk ;
    };

    template <class ET> struct RecheckType
    {
      typedef typename LE::template RecheckType<ET>::Ok Ok ;
    } ;

    template <class EnvThunk>
    typename MyType<EnvThunk>::TypeThunk::template Go<int>::Type
    eval( const typename EnvThunk::template Go<int>::BE& be ) const
    {
      typedef NumBoundVarsHelp<LE,EnvThunk,TBBV> NBVH ;
      typedef typename NBVH::Lam                 Lam  ;
      typedef typename NBVH::Full                Full ;
      return Full ( Lam(exp,be) )                     ;
    }

    YouCannotInvokeALambdaContainingFreeVars<FreeVars>
    operator()() const
    {
      return 0 ;
    }

    template <class X>
    YouCannotInvokeALambdaContainingFreeVars<FreeVars>
    operator()(const X&) const
    {
      return 0 ;
    }

    template <class X, class Y>
    YouCannotInvokeALambdaContainingFreeVars<FreeVars>
    operator()(const X&, const Y&) const
    {
      return 0 ;
    }

    template <class X, class Y, class Z>
    YouCannotInvokeALambdaContainingFreeVars<FreeVars>
    operator() (const X&, const Y&, const Z&) const
    {
      return 0 ;
    }

    template <class AA=Void, class BB=Void, class CC=Void> struct Sig
    {
      typedef typename YouCannotInvokeALambdaContainingFreeVars<FreeVars>
         ::AndThusYouShouldNotBeTryingToUseItsSigEither Arg1Type;
      typedef typename YouCannotInvokeALambdaContainingFreeVars<FreeVars>
         ::AndThusYouShouldNotBeTryingToUseItsSigEither Arg2Type;
      typedef typename YouCannotInvokeALambdaContainingFreeVars<FreeVars>
         ::AndThusYouShouldNotBeTryingToUseItsSigEither Arg3Type;
      typedef typename YouCannotInvokeALambdaContainingFreeVars<FreeVars>
         ::AndThusYouShouldNotBeTryingToUseItsSigEither ResultType;
    } ;

    typedef LambdaExpWithFreeVars This ;

    template <class A> typename BracketCallable<This,A>::Result
    operator[]( const A& a ) const
    {
      return BracketCallable<This,A>::go ( *this , a ) ;
    }

};

template <class E, class T, class F, IfKind deduction_method>
class IfLE : public LEBase
{
  protected:

    E e ;
    T t ;
    F f ;

  public:

    template <class ET, IfKind deduct_method> struct XType        ;
    template <class ET, IfKind deduct_method> struct XRecheckType ;

    // Normal if type deduction
    template <class ET> struct XType<ET,IfNormal>
    {
      typedef typename T::template MyType<ET>::TypeThunk TypeThunk ;
    } ;

    template <class ET> struct XRecheckType<ET,IfNormal>
    {
      typedef typename E::template MyType<ET>::TypeThunk ETT;
      typedef typename T::template MyType<ET>::TypeThunk TTT;
      typedef typename F::template MyType<ET>::TypeThunk FTT;
      typedef typename ETT::template Go<int>::Type EType;
      typedef typename TTT::template Go<int>::Type TType;
      typedef typename FTT::template Go<int>::Type FType;
      static const bool b = ImplicitlyConvertible<EType,bool>::value;
      typedef typename AlwaysFirst<typename AlwaysFirst<typename AlwaysFirst<
         typename AlwaysFirst<typename
         TrueAndFalseBranchOfIfMustHaveSameType<TType,FType>::Type, typename
         IfExpressionMustHaveTypeConvertibleToBool<EType,b>::Type>::Type,
         typename E::template RecheckType<ET>::Ok>::Type,
         typename T::template RecheckType<ET>::Ok>::Type,
         typename F::template RecheckType<ET>::Ok>::Type Ok;
    } ;

    // Type deduction based on true-branch
    template <class ET> struct XType<ET,IfTrue>
    {
      typedef typename T::template MyType<ET>::TypeThunk TypeThunk ;
    } ;

   template <class ET> struct XRecheckType<ET,IfTrue>
    {
      typedef typename E::template MyType<ET>::TypeThunk ETT   ;
      typedef typename T::template MyType<ET>::TypeThunk TTT   ;
      typedef typename F::template MyType<ET>::TypeThunk FTT   ;
      typedef typename ETT::template Go<int>::Type       EType ;
      typedef typename TTT::template Go<int>::Type       TType ;
      typedef typename FTT::template Go<int>::Type       FType ;

      static const bool bx = ImplicitlyConvertible<EType,bool>::value ;

      typedef typename
         IfExpressionMustHaveTypeConvertibleToBool<EType,bx>::Type Foo ;

      static const bool b = ImplicitlyConvertible<FType,TType>::value ;

      typedef typename
         ActualTypeOfFalseBranchMustBeImplicitlyConvertibleToTypeOfTrueBranch
         <FType,TType,b>::Error Tmp ;

      typedef typename AlwaysFirst<typename AlwaysFirst<
         typename AlwaysFirst<typename AlwaysFirst<Tmp,Foo>::Type,
         typename E::template RecheckType<ET>::Ok>::Type,
         typename T::template RecheckType<ET>::Ok>::Type,
         typename F::template RecheckType<ET>::Ok>::Type Ok ;

    } ;

    // Type deduction based on false-branch
    template <class ET> struct XType<ET,IfFalse>
    {
      typedef typename F::template MyType<ET>::TypeThunk TypeThunk ;
    } ;

    template <class ET> struct XRecheckType<ET,IfFalse>
    {
      typedef typename E::template MyType<ET>::TypeThunk ETT   ;
      typedef typename T::template MyType<ET>::TypeThunk TTT   ;
      typedef typename F::template MyType<ET>::TypeThunk FTT   ;
      typedef typename ETT::template Go<int>::Type       EType ;
      typedef typename TTT::template Go<int>::Type       TType ;
      typedef typename FTT::template Go<int>::Type       FType ;

      static const bool bx = ImplicitlyConvertible<EType,bool>::value ;

      typedef typename
         IfExpressionMustHaveTypeConvertibleToBool<EType,bx>::Type Foo ;

      static const bool b = ImplicitlyConvertible<TType,FType>::value ;

      typedef typename
         ActualTypeOfTrueBranchMustBeImplicitlyConvertibleToTypeOfFalseBranch
         <TType,FType,b>::Error Tmp ;

      typedef typename AlwaysFirst<typename AlwaysFirst<
         typename AlwaysFirst<typename AlwaysFirst<Tmp,Foo>::Type,
         typename E::template RecheckType<ET>::Ok>::Type,
         typename T::template RecheckType<ET>::Ok>::Type,
         typename F::template RecheckType<ET>::Ok>::Type Ok ;

    } ;

    IfLE( const E& ee, const T& tt, const F& ff ) : e(ee), t(tt), f(ff)
    {
      EnsureLE < E > :: go ( ) ;
      EnsureLE < T > :: go ( ) ;
      EnsureLE < F > :: go ( ) ;
    }

    typedef typename RemoveDuplicates<typename AppendList<typename E::FreeVars,
      typename AppendList<typename T::FreeVars, typename F::FreeVars>::Result
      >::Result>::Result FreeVars ;

    template <class ET> struct MyType
    {
      typedef typename XType<ET,deduction_method>::TypeThunk TypeThunk ;
    } ;

    template <class ET> struct RecheckType
    {
      typedef typename XRecheckType<ET,deduction_method>::Ok Ok ;
    } ;

    template <class ET>
    typename MyType<ET>::TypeThunk::template Go<int>::Type
    eval( const typename ET::template Go<int>::BE & be ) const
    {
      if( e.template eval<ET>(be) ) return t.template eval<ET>(be) ;
                               else return f.template eval<ET>(be) ;
    }

    typedef IfLE This ;

    template <class A> typename BracketCallable<This,A>::Result
    operator[]( const A& a ) const
    {
      return BracketCallable<This,A>::go( *this , a ) ;
    }

} ;

// operator, overloads
//
// Koenig lookup will only find these overloads if one of the arguments
// to comma is an LE (a type defined in this namespace).
// Either the LHS is already a CONS...

template <class H, class T, class RHS>
CONS<typename LEify<RHS>::Type,CONS<H,T> >
operator,( const CONS<H,T>& lhs, const RHS& rhs )
{
  return CONS<typename LEify<RHS>::Type,CONS<H,T> >
      ( LEify<RHS>::go(rhs), lhs ) ;
}

// ... or it's not
template <class LHS, class RHS>
CONS<typename LEify<RHS>::Type,typename LEListify<LHS>::Type>
operator,( const LHS& lhs, const RHS& rhs )
{
  return CONS<typename LEify<RHS>::Type,typename LEListify<LHS>::Type>
         ( LEify<RHS>::go(rhs), LEListify<LHS>::go(lhs) ) ;
}

//////////////////////////////////////////////////////////////////////
// lambda() and the functoids that get made when all the vars are bound
// and we make it back out into "C++ space"
//////////////////////////////////////////////////////////////////////

template <class LE>
class Lambda0 : public CfpType<typename LE::template
                   MyType<NIL_ET>::TypeThunk::template Go<int>::Type>
{
  protected:

    LE exp ;

  public:

    Lambda0( const LE& e ) : exp(e)
    {
      EnsureLE < LE > :: go ( ) ;
    }

    typename LE::template MyType<NIL_ET>::TypeThunk::template Go<int>::Type
    operator()() const
    {
      return exp.template eval<NIL_ET>( NIL() ) ;
    }

};

template <class LE, int i>
class Lambda1
{
  protected:

    LE exp;
    template <class X> struct NewET
    {
      typedef typename ETUpdateX<NIL_ET,i,X>::Result Result ;
    } ;

  public:

    Lambda1( const LE& e ) : exp(e)
    {
      EnsureLE<LE>::go() ;
    }

    template <class X> struct Sig : public FunType<X,typename LE::template
      MyType<typename NewET<X>::Result>::TypeThunk::template Go<int>::Type>
    {
    } ;

    template <class X>
    typename Sig<X>::ResultType
    operator()( const X& x ) const
    {
      typedef typename NewET<X>::Result NET;
      return exp.template eval<NET>( NET::template Go<int>::go(NIL(),x) ) ;
    }

} ;

template <class LE, int i, int j>
class Lambda2
{
  protected:

    LE exp ;

    template <class X, class Y> struct NewET
    {
      typedef typename ETUpdateXY<NIL_ET,i,X,j,Y>::Result Result ;
    } ;

  public:

    Lambda2( const LE& e ) : exp(e)
    {
      EnsureLE < LE > :: go ( ) ;
    }

    template <class X, class Y> struct Sig : public FunType<X,Y,
      typename LE::template MyType<typename NewET<X,Y>::Result>
      ::TypeThunk::template Go<int>::Type>
    {
    } ;

    template <class X, class Y>
    typename Sig<X,Y>::ResultType
    operator()( const X& x, const Y& y ) const
    {
      typedef typename NewET<X,Y>::Result NET ;
      return exp.template eval<NET>( NET::template Go<int>::go(NIL(),x,y) ) ;
    }

};

template <class LE, int i, int j, int k>
class Lambda3
{
  protected:

    LE exp ;

    template <class X, class Y, class Z> struct NewET
    {
      typedef typename ETUpdateXYZ<NIL_ET,i,X,j,Y,k,Z>::Result Result ;
    } ;

  public:

    Lambda3( const LE& e ) : exp(e)
    {
      EnsureLE < LE > :: go ( ) ;
    }

    template <class X, class Y, class Z> struct Sig
      : public FunType<X,Y,Z,
               typename LE::template MyType<typename NewET<X,Y,Z>::Result>
               ::TypeThunk::template Go<int>::Type>
    {
    } ;

    template <class X, class Y, class Z>
    typename Sig<X,Y,Z>::ResultType
    operator()( const X & x, const Y & y, const Z & z ) const
    {
      typedef typename NewET<X,Y,Z>::Result NET ;
      return exp.template eval<NET>( NET::template Go<int>::go(NIL(),x,y,z) ) ;
    }

};

// LambdaThingy is the temporary object that lambda() returns which
// understands operator[] calls.
template <class TBBV>
class LambdaThingy
{
  public:

    typedef TBBV VarsThisLambdaBinds;

    template <class LE, class FV, class TBBVars>
    struct Help2
    {
      typedef LambdaExpWithFreeVars<LE,VarsThisLambdaBinds> Result ;
      typedef Result                                        Full   ;
    } ;

    template <class LE>
    struct Help2<LE,NIL,NIL>
    {
      typedef Lambda0<LE>   Result ;
      typedef Full0<Result> Full   ;
    };

    template <class LE, int i>
    struct Help2<LE,NIL,CONS<LambdaVar<i>,NIL> >
    {
      typedef Lambda1<LE,i> Result ;
      typedef Full1<Result> Full   ;
    };

    template <class LE, int i, int j>
    struct Help2<LE,NIL,CONS<LambdaVar<i>,CONS<LambdaVar<j>,NIL> > >
    {
      typedef Lambda2<LE,i,j> Result ;
      typedef Full2<Result>   Full   ;
    };

    template <class LE, int i, int j, int k>
    struct Help2<LE,NIL,CONS<LambdaVar<i>,CONS<LambdaVar<j>,
                       CONS<LambdaVar<k>,NIL> > > >
    {
      typedef Lambda3<LE,i,j,k> Result ;
      typedef Full3<Result>     Full   ;
    } ;

    template <class LE>
    struct Helper
    {
      typedef typename ListDifference<typename LE::FreeVars,
         VarsThisLambdaBinds>::Result                  FreeVars ;
      typedef typename Help2<LE,FreeVars,TBBV>::Result Result   ;
      typedef typename Help2<LE,FreeVars,TBBV>::Full   Full     ;
    } ;

  public:

    template <class E>
    struct RT
    {
      typedef typename Helper<typename LEify<E>::Type>::Full Type ;
    } ;

    template <class E>
    typename RT<E>::Type
    operator[]( const E & e ) const
    {
      typedef typename Helper<typename LEify<E>::Type>::Result Result ;
      typedef typename Helper<typename LEify<E>::Type>::Full   Full   ;
      return Full ( Result( LEify<E>::go(e) ) )                       ;
    }

};

inline LambdaThingy<NIL> lambda()
{
  return LambdaThingy<NIL>();
}

template <int i>
LambdaThingy<CONS<LambdaVar<i>,NIL> >
lambda( const LambdaVar<i>& )
{
  return LambdaThingy<CONS<LambdaVar<i>,NIL> >();
}

template <int i, int j>
LambdaThingy<CONS<LambdaVar<i>,CONS<LambdaVar<j>,NIL> > >
lambda( const LambdaVar<i>&, const LambdaVar<j>& )
{
  YouCannotPassTheSameLambdaVarTo_lambda_MoreThanOnce<(i==j)>::go() ;
  return LambdaThingy<CONS<LambdaVar<i>,CONS<LambdaVar<j>,NIL> > >() ;
}

template <int i, int j, int k>
LambdaThingy<CONS<LambdaVar<i>,CONS<LambdaVar<j>,CONS<LambdaVar<k>,NIL> > > >
lambda( const LambdaVar<i>&, const LambdaVar<j>&, const LambdaVar<k>& )
{
  YouCannotPassTheSameLambdaVarTo_lambda_MoreThanOnce<
      (i==j || i==k || j==k) >::go() ;
  return LambdaThingy<CONS<LambdaVar<i>,CONS<LambdaVar<j>,
            CONS<LambdaVar<k>,NIL> > > >() ;
}

//////////////////////////////////////////////////////////////////////
// lambda language constructs
//////////////////////////////////////////////////////////////////////

template <IfKind k>
class IfLambdaoid
{
  public:

    template <class E, class T, class F>
    IfLE<E,T,F,k>
    operator[]( const CONS<F,CONS<T,CONS<E,NIL> > >& x ) const
    {
      EnsureLE < E > :: go ( ) ;
      EnsureLE < T > :: go ( ) ;
      EnsureLE < F > :: go ( ) ;
      return IfLE<E,T,F,k>( x.tail.tail.head, x.tail.head, x.head ) ;
    }

};

Q_FLP_EXPORT extern IfLambdaoid < IfNormal > if0 ;
Q_FLP_EXPORT extern IfLambdaoid < IfTrue   > if1 ;
Q_FLP_EXPORT extern IfLambdaoid < IfFalse  > if2 ;

template <int i, class E>
Binder<i,typename LEify<E>::Type>
operator==( LambdaVar<i>, const E& e )
{
 return Binder<i,typename LEify<E>::Type>( LEify<E>::go(e) ) ;
}

template <class LHS, int i, class LE>
CONS<Binder<i,LE>,typename BinderListify<LHS>::Type>
operator,( const LHS& lhs, const Binder<i,LE>& b )
{
  return CONS<Binder<i,LE>,typename BinderListify<LHS>::Type>
           ( b, BinderListify<LHS>::go(lhs) ) ;
}

template <class H, class T, int i, class LE>
CONS<Binder<i,LE>,CONS<H,T> >
operator,( const CONS<H,T>& lhs, const Binder<i,LE>& b )
{
  return CONS<Binder<i,LE>,CONS<H,T> >( b, lhs ) ;
}

//////////////////////////////////////////////////////////////////////
// LEType stuff
//////////////////////////////////////////////////////////////////////

template <class F, class X=Void, class Y=Void, class Z=Void> class CALL ;
template <int i> class LV ;
template <class E, class T, class F> class IF0 ;
template <class E, class T, class F> class IF1 ;
template <class E, class T, class F> class IF2 ;
template <class A, class B=Void, class C=Void, class D=Void> class LAM ;

template <class T>
class LEType
{
  public:

    typedef T Type ;

} ;

template <class A, class B=Void, class C=Void, class D=Void>
class LET_LEListify
{
  public:

    typedef typename LEify<typename LEType<D>::Type>::Type LE_D ;
    typedef CONS<LE_D,typename LET_LEListify<A,B,C>::Type> Type ;

} ;

template <class A, class B, class C>
class LET_LEListify<A,B,C,Void>
{
  public:

    typedef typename LEify<typename LEType<C>::Type>::Type LE_C ;
    typedef CONS<LE_C,typename LET_LEListify<A,B>::Type>   Type ;

} ;

template <class A, class B>
class LET_LEListify<A,B,Void,Void>
{
  public:

    typedef typename LEify<typename LEType<B>::Type>::Type LE_B ;
    typedef CONS<LE_B,typename LET_LEListify<A>::Type>     Type ;

} ;

template <class A>
class LET_LEListify<A,Void,Void,Void>
{
  public:

    typedef typename LEListify<typename LEType<A>::Type>::Type Type ;

} ;

template <class F, class X, class Y, class Z>
class LEType< CALL<F,X,Y,Z> >
{
  public:

    typedef typename LEify<typename LEType<F>::Type>::Type FF   ;
    typedef Call<FF,typename LET_LEListify<X,Y,Z>::Type>   Type ;

} ;

template <class F, class X, class Y>
class LEType< CALL<F,X,Y,Void> >
{
  public:

    typedef typename LEify<typename LEType<F>::Type>::Type FF   ;
    typedef Call<FF,typename LET_LEListify<X,Y>::Type>     Type ;

};

template <class F, class X>
class LEType< CALL<F,X,Void,Void> >
{
  public:

    typedef typename LEify<typename LEType<F>::Type>::Type FF   ;
    typedef Call<FF,typename LET_LEListify<X>::Type>       Type ;
};

template <class F>
class LEType< CALL<F,Void,Void,Void> >
{
  public:

    typedef typename LEify<typename LEType<F>::Type>::Type FF   ;
    typedef Call<FF,NIL>                                   Type ;

};

template <int i>
class LEType< LV<i> >
{
  public:

    typedef LambdaVar<i> Type ;

} ;

template <class E, class T, class F>
class LEType< IF0<E,T,F> >
{
  public:

    typedef typename LEify<typename LEType<E>::Type>::Type EE   ;
    typedef typename LEify<typename LEType<T>::Type>::Type TT   ;
    typedef typename LEify<typename LEType<F>::Type>::Type FF   ;
    typedef IfLE<EE,TT,FF,IfNormal>                        Type ;

};

template <class E, class T, class F>
class LEType< IF1<E,T,F> >
{
  public:

   typedef typename LEify<typename LEType<E>::Type>::Type EE   ;
   typedef typename LEify<typename LEType<T>::Type>::Type TT   ;
   typedef typename LEify<typename LEType<F>::Type>::Type FF   ;
   typedef IfLE<EE,TT,FF,IfTrue>                          Type ;

};

template <class E, class T, class F>
class LEType< IF2<E,T,F> >
{
  public:

    typedef typename LEify<typename LEType<E>::Type>::Type EE   ;
    typedef typename LEify<typename LEType<T>::Type>::Type TT   ;
    typedef typename LEify<typename LEType<F>::Type>::Type FF   ;
    typedef IfLE<EE,TT,FF,IfFalse>                         Type ;

};

template <int i, int j, int k, class E>
class LEType< LAM<LV<i>,LV<j>,LV<k>,E> >
{
  public:

    typedef typename LEType<E>::Type EE;
    typedef typename LambdaThingy<CONS<LambdaVar<i>,CONS<LambdaVar<j>,
      CONS<LambdaVar<k>,NIL> > > >::template RT<EE>::Type Type;
};

template <int i, int j, class E>
class LEType< LAM<LV<i>,LV<j>,E,Void> >
{
  public:

    typedef typename LEType<E>::Type EE;
    typedef typename LambdaThingy<CONS<LambdaVar<i>,CONS<LambdaVar<j>,
      NIL> > >::template RT<EE>::Type Type;
};

template <int i, class E>
class LEType< LAM<LV<i>,E,Void,Void> >
{
  public:

    typedef typename LEType<E>::Type EE;
    typedef typename LambdaThingy<CONS<LambdaVar<i>,
      NIL> >::template RT<EE>::Type Type;
};

template <class E>
class LEType< LAM<E,Void,Void,Void> >
{
  public:

    typedef typename LEType<E>::Type                          EE   ;
    typedef typename LambdaThingy<NIL>::template RT<EE>::Type Type ;

};

//////////////////////////////////////////////////////////////////////
// more lambda language constructs
//////////////////////////////////////////////////////////////////////

class LetLambdaoid
{
  public:

    template <class BL>
    struct InLambdaoid
    {
      class Help
      {
        protected:

          BL bl ;

        public:

          template <class B, class LE> struct Lambdify;

          template <int i, class LEa, class LE>
          struct Lambdify<CONS<Binder<i,LEa>,NIL>,LE>
          {
            typedef typename LEType<CALL<LAM<LV<i>,LE>,LEa> >::Type R;
            static inline R go( const CONS<Binder<i,LEa>,NIL>& binders,
                                const LE& le )
            {
              LambdaVar<i> X;
              return lambda(X)[ le ][ binders.head.exp ] ;
            }
          };

          template <int i, class LEa, class Rest, class LE>
          struct Lambdify<CONS<Binder<i,LEa>,Rest>,LE>
          {
            typedef typename LEType<CALL<LAM<LV<i>,LE>,LEa> >::Type Inner;
            typedef typename Lambdify<Rest,Inner>::R R;
            static inline R go( const CONS<Binder<i,LEa>,Rest>& binders,
                                const LE& le )
            {
              LambdaVar<i> X;
              return Lambdify<Rest,Inner>::go( binders.tail,
                lambda(X)[ le ][ binders.head.exp ] ) ;
            }
          } ;

          Help( const BL& l ) : bl(l)
          {
          }

          template <class E> struct RT
          {
            typedef typename Lambdify<BL,typename LEify<E>::Type>::R Type ;
          } ;

          template <class E>
          typename RT<E>::Type
          operator[]( const E & e )
          {
            return Lambdify<BL,typename LEify<E>::Type>::go
               ( bl, LEify<E>::go(e) ) ;
          }

      } ;

      Help in ;

      InLambdaoid( const BL& l ) : in(l)
      {
      }

    } ;

    template <class BL> struct RT
    {
      typedef InLambdaoid<typename BinderListify<BL>::Type> Type ;
    } ;

    template <class BL>
    typename RT<BL>::Type
    operator[]( const BL& bl ) const
    {
      EnsureBinderList<typename BinderListify<BL>::Type>::go() ;
      return InLambdaoid<typename BinderListify<BL>::Type>
         ( BinderListify<BL>::go(bl) ) ;
    }

};

Q_FLP_EXPORT extern LetLambdaoid let ;

class LetRecLambdaoid
{
  public:

    template <class BL>
    struct InLambdaoid
    {
      class Help
      {
        public:

          Help( const BL & l ) : bl(l)
          {
          }

          template <class E>
          class RT
          {
            typedef BindingEnvExp<BL,typename LEify<E>::Type> Type;
          } ;

          template <class E>
          typename RT<E>::Type
          operator[]( const E & e )
          {
            return BindingEnvExp<BL,typename LEify<E>::Type>
               ( bl, LEify<E>::go(e) );
          }

        protected:

          BL bl ;

      };

      Help in ;

      InLambdaoid ( const BL& l ) : in(l)
      {
      }

    } ;

    template <class BL> struct RT;

    template <class BL> friend struct RT;

    template <class BL> struct RT
    {
      typedef InLambdaoid<typename BinderListify<BL>::Type> Type ;
    } ;

    template <class BL>
    typename RT<BL>::Type
    operator[]( const BL & bl ) const
    {
      EnsureBinderList<typename BinderListify<BL>::Type>::go() ;
      return InLambdaoid<typename BinderListify<BL>::Type>
         ( BinderListify<BL>::go(bl) );
    }

};

template <int   i, class LE                           > class BIND   ;
template <class A, class B, class C=Void, class D=Void> class LET    ;
template <class A, class B, class C=Void, class D=Void> class LETREC ;

template <class A, class B=Void, class C=Void, class D=Void>
class LET_BinderListify
{
  public:

    typedef CONS<D,typename LET_BinderListify<A,B,C>::Type> Type ;

};

template <class A, class B, class C>
class LET_BinderListify<A,B,C,Void>
{
  public:

    typedef CONS<C,typename LET_BinderListify<A,B>::Type> Type ;

};

template <class A, class B>
class LET_BinderListify<A,B,Void,Void>
{
  public:

    typedef CONS<B,typename LET_BinderListify<A>::Type> Type ;

};

template <class A>
class LET_BinderListify<A,Void,Void,Void>
{
  public:

    typedef typename BinderListify<A>::Type Type ;

};

template <int i, class A, class LE>
class LEType< LET<BIND<i,A>,LE,Void,Void> >
{
  public:

    typedef typename LEType<LE>::Type LELE;
    typedef Binder<i,typename LEify<typename LEType<A>::Type>::Type> AA;
    typedef typename LetLambdaoid::template RT<typename
      LET_BinderListify<AA>::Type>::Type::Help::template RT<LELE>::Type Type;

};

template <int i, class A, int j, class B, class LE>
class LEType< LET<BIND<i,A>,BIND<j,B>,LE,Void> >
{
  public:

    typedef typename LEType<LE>::Type LELE;
    typedef Binder<i,typename LEify<typename LEType<A>::Type>::Type> AA;
    typedef Binder<j,typename LEify<typename LEType<B>::Type>::Type> BB;
    typedef typename LetLambdaoid::template RT<typename
      LET_BinderListify<AA,BB>::Type>::Type::Help::template RT<LELE>::Type Type;

};

template <int i, class A, int j, class B, int k, class C, class LE>
class LEType< LET<BIND<i,A>,BIND<j,B>,BIND<k,C>,LE> >
{
  public:

    typedef typename LEType<LE>::Type LELE;
    typedef Binder<i,typename LEify<typename LEType<A>::Type>::Type> AA;
    typedef Binder<j,typename LEify<typename LEType<B>::Type>::Type> BB;
    typedef Binder<k,typename LEify<typename LEType<C>::Type>::Type> CC;
    typedef typename LetLambdaoid::template RT<typename
      LET_BinderListify<AA,BB,CC>::Type>::Type::Help::template
      RT<LELE>::Type Type ;

};

template <int i, class A, class LE>
class LEType< LETREC<BIND<i,A>,LE,Void,Void> >
{
  public:

    typedef typename LEType<LE>::Type LELE;
    typedef Binder<i,typename LEify<typename LEType<A>::Type>::Type> AA;
    typedef typename LetRecLambdaoid::template RT<typename
      LET_BinderListify<AA>::Type>::Type::Help::template RT<LELE>::Type Type ;

};

template <int i, class A, int j, class B, class LE>
class LEType< LETREC<BIND<i,A>,BIND<j,B>,LE,Void> >
{
  public:

    typedef typename LEType<LE>::Type LELE ;
    typedef Binder<i,typename LEify<typename LEType<A>::Type>::Type> AA ;
    typedef Binder<j,typename LEify<typename LEType<B>::Type>::Type> BB ;
    typedef typename LetRecLambdaoid::template RT<typename
      LET_BinderListify<AA,BB>::Type>::Type::Help::template RT<LELE>::Type Type;

};

template <int i, class A, int j, class B, int k, class C, class LE>
class LEType< LETREC<BIND<i,A>,BIND<j,B>,BIND<k,C>,LE> >
{
  public:

    typedef typename LEType<LE>::Type LELE;
    typedef Binder<i,typename LEify<typename LEType<A>::Type>::Type> AA;
    typedef Binder<j,typename LEify<typename LEType<B>::Type>::Type> BB;
    typedef Binder<k,typename LEify<typename LEType<C>::Type>::Type> CC;
    typedef typename LetRecLambdaoid::template RT<typename
      LET_BinderListify<AA,BB,CC>::Type>::Type::Help::template
      RT<LELE>::Type Type ;

};

/*****************************************************************************\
 *                                                                           *
 *                    syntactic sugar for infix operators                    *
 *                                                                           *
 * The syntax                                                                *
 *    arg1 ^fun^ arg2     means     fun( arg1, arg2 )                        *
 * like Haskell's backquotes.                                                *
 *                                                                           *
 * I feel justified in this convenient abuse of operator overloading in      *
 * that it's complete nonsense for someone to try to XOR a value with a      *
 * 2-argument full functoid.  Put another way, I own Full2<F>s; I can do     *
 * whatever I want with them, darn it!  :)                                   *
 *                                                                           *
 * Note that it also works on Full3s (with currying).                        *
 *                                                                           *
\*****************************************************************************/

template <class LHS, class Fun>
class InfixOpThingy
{
  public:

    // Note that storing const&s here relies on the fact that temporaries
    // are guaranteed to live for the duration of the full-expression in
    // which they are created.  There's no need to create copies.

    const LHS & lhs ;
    const Fun & f   ;

    InfixOpThingy( const LHS& l, const Fun& ff ) : lhs(l), f(ff)
    {
    }

} ;

template <class LHS, class F>
inline InfixOpThingy<LHS,Full2<F> >
operator^( const LHS & lhs, const Full2<F> & f )
{
  return InfixOpThingy<LHS,Full2<F> >(lhs,f) ;
}

template <class LHS, class F>
inline InfixOpThingy<LHS,Full3<F> >
operator^( const LHS& lhs, const Full3<F>& f )
{
  return InfixOpThingy<LHS,Full3<F> >(lhs,f) ;
}

template <class LHS, class FF, class RHS>
inline typename RT<FF,LHS,RHS>::ResultType
operator^( const InfixOpThingy<LHS,FF>& x, const RHS& rhs )
{
  return x.f( x.lhs, rhs ) ;
}

template <class LHS, class FF, class G>
inline typename RT<FF,LHS,Full2<G> >::ResultType
operator^( const InfixOpThingy<LHS,FF>& x, const Full2<G>& rhs )
{
  return x.f( x.lhs, rhs ) ;
}

template <class LHS, class FF, class G>
inline typename RT<FF,LHS,Full3<G> >::ResultType
operator^( const InfixOpThingy<LHS,FF>& x, const Full3<G>& rhs )
{
  return x.f( x.lhs, rhs ) ;
}

/*****************************************************************************\
 * Furthermore, I just can't help myself from making                         *
 *   arg1 %fun% arg2     mean     fun[ arg1 ][ arg2 ]                        *
 * for use in lambda expressions.  % is a good choice because it binds       *
 * more tightly than <=, so it's less likely to interfere with "gets"        *
 * bindings.                                                                 *
\*****************************************************************************/

template <class LHS, class Fun>
class InfixOpWhatzit
{
  public:

    // See comment in InfixOpThingy

    const LHS & lhs ;
    const Fun & f   ;

    InfixOpWhatzit( const LHS& l, const Fun& ff ) : lhs(l), f(ff)
    {
    }

};

template <class LHS, class F>
inline InfixOpWhatzit<LHS,Full2<F> >
operator%( const LHS& lhs, const Full2<F>& f )
{
  return InfixOpWhatzit<LHS,Full2<F> >(lhs,f) ;
}

template <class LHS, class F>
inline InfixOpWhatzit<LHS,Full3<F> >
operator%( const LHS& lhs, const Full3<F>& f )
{
  return InfixOpWhatzit<LHS,Full3<F> >(lhs,f) ;
}

template <class LHS, class FF, class RHS>
inline typename LEType<CALL<CALL<FF,LHS>,RHS> >::Type
operator%( const InfixOpWhatzit<LHS,FF>& x, const RHS& rhs )
{
  return x.f[ x.lhs ][ rhs ] ;
}

template <class LHS, class FF, class G>
inline typename LEType<CALL<CALL<FF,LHS>,Full2<G> > >::Type
operator%( const InfixOpWhatzit<LHS,FF>& x, const Full2<G>& rhs )
{
  return x.f[ x.lhs ][ rhs ] ;
}

template <class LHS, class FF, class G>
inline typename LEType<CALL<CALL<FF,LHS>,Full3<G> > >::Type
operator%( const InfixOpWhatzit<LHS,FF>& x, const Full3<G>& rhs )
{
  return x.f[ x.lhs ][ rhs ] ;
}

//////////////////////////////////////////////////////////////////////
// operators
//////////////////////////////////////////////////////////////////////

class XMakePair
{
  public:

    template <class A, class B>
    struct Sig : public FunType<A,B,std::pair<A,B> >
    {
    };

    template <class A, class B>
    std::pair<A,B> operator()( const A& a, const B& b ) const
    {
      return std::make_pair(a,b) ;
    }

} ;

typedef Full2<XMakePair> MakePair ;

Q_FLP_EXPORT extern MakePair makePair ;

class XMin
{
  public:

    template <class T, class U> struct Sig;

    template <class T>
    struct Sig<T,T> : public FunType<T,T,T>
    {
    } ;

    template <class T>
    T operator()( const T& x, const T& y ) const
    {
      return std::less<T>()( x, y ) ? x : y ;
    }

} ;

typedef Full2<XMin> Min ;

Q_FLP_EXPORT extern Min min ;

class XMax
{
  public:

    template <class T, class U> struct Sig ;

    template <class T>
    struct Sig<T,T> : public FunType<T,T,T>
    {
    };

    template <class T>
    T operator()( const T& x, const T& y ) const
    {
      return std::less<T>()( x, y ) ? y : x ;
    }

} ;

typedef Full2<XMax> Max;

Q_FLP_EXPORT extern Max max ;

class XPlus
{
  public:

    template <class T, class U> struct Sig ;

    template <class T>
    struct Sig<T,T> : public FunType<T,T,T>
    {
    };

    template <class T>
    T operator()( const T& x, const T& y ) const
    {
      return std::plus<T>()( x, y ) ;
    }

} ;

typedef Full2<XPlus> Plus;

Q_FLP_EXPORT extern Plus plus ;

class XMinus
{
  public:

    template <class T, class U> struct Sig;

    template <class T>
    struct Sig<T,T> : public FunType<T,T,T>
    {
    };

    template <class T>
    T operator()( const T& x, const T& y ) const
    {
      return std::minus<T>()( x, y ) ;
    }

} ;

typedef Full2<XMinus> Minus ;

Q_FLP_EXPORT extern Minus minus ;

class XMultiplies
{
  public:

    template <class T, class U> struct Sig ;

    template <class T>
    struct Sig<T,T> : public FunType<T,T,T>
    {
    };

    template <class T>
    T operator()( const T& x, const T& y ) const
    {
      return std::multiplies<T>()( x, y ) ;
    }

} ;

typedef Full2<XMultiplies> Multiplies ;

Q_FLP_EXPORT extern Multiplies multiplies ;

class XDivides
{
  public:

    template <class T, class U> struct Sig;

    template <class T>
    struct Sig<T,T> : public FunType<T,T,T>
    {
    } ;

    template <class T>
    T operator()( const T& x, const T& y ) const
    {
      return std::divides<T>()( x, y ) ;
    }

} ;

typedef Full2<XDivides> Divides;

Q_FLP_EXPORT extern Divides divides ;

class XModulus
{
  public:

    template <class T, class U> struct Sig;

    template <class T>
    struct Sig<T,T> : public FunType<T,T,T>
    {
    };

    template <class T>
    T operator()( const T& x, const T& y ) const
    {
      return std::modulus<T>()( x, y ) ;
    }

} ;

typedef Full2<XModulus> Modulus ;

Q_FLP_EXPORT extern Modulus modulus ;

class XNegate
{
  public:

    template <class T>
    struct Sig : public FunType<T,T>
    {
    };

   template <class T>
   T operator()( const T& x ) const
   {
     return std::negate<T>()( x ) ;
   }

};

typedef Full1<XNegate> Negate ;

Q_FLP_EXPORT extern Negate negate ;

class XEqual
{
  public:

    template <class T, class U> struct Sig ;

    template <class T>
    struct Sig<T,T> : public FunType<T,T,bool>
    {
    };

    template <class T>
    bool operator()( const T&x, const T&y ) const
    {
      return std::equal_to<T>()( x, y ) ;
    }
};

typedef Full2<XEqual> Equal ;

Q_FLP_EXPORT extern Equal equal ;

class XNotEqual
{
  public:

    template <class T, class U> struct Sig;

    template <class T>
    struct Sig<T,T> : public FunType<T,T,bool>
    {
    };

    template <class T>
    bool operator()( const T&x, const T&y ) const
    {
      return std::not_equal_to<T>()( x, y );
    }

};

typedef Full2<XNotEqual> NotEqual ;

Q_FLP_EXPORT extern NotEqual notEqual ;

class XGreater
{
  public:

    template <class T, class U> struct Sig ;

    template <class T>
    struct Sig<T,T> : public FunType<T,T,bool>
    {
    };

    template <class T>
    bool operator()( const T&x, const T&y ) const
    {
      return std::greater<T>()( x, y ) ;
    }
};

typedef Full2<XGreater> Greater ;

Q_FLP_EXPORT extern Greater greater ;

class XLess
{
  public:

    template <class T, class U> struct Sig;

    template <class T>
    struct Sig<T,T> : public FunType<T,T,bool>
    {
    };

    template <class T>
    bool operator()( const T&x, const T&y ) const
    {
      return std::less<T>()( x, y ) ;
    }

};

typedef Full2<XLess> Less ;

Q_FLP_EXPORT extern Less less ;

class XGreaterEqual
{
  public:

    template <class T, class U> struct Sig ;

    template <class T>
    struct Sig<T,T> : public FunType<T,T,bool>
    {
    };

    template <class T>
    bool operator()( const T&x, const T&y ) const
    {
      return std::greater_equal<T>()( x, y ) ;
    }

};

typedef Full2<XGreaterEqual> GreaterEqual ;

Q_FLP_EXPORT extern GreaterEqual greaterEqual ;

class XLessEqual
{
  public:

    template <class T, class U> struct Sig;

    template <class T>
    struct Sig<T,T> : public FunType<T,T,bool>
    {
    };

    template <class T>
    bool operator()( const T&x, const T&y ) const
    {
      return std::less_equal<T>()( x, y );
    }

};

typedef Full2<XLessEqual> LessEqual ;

Q_FLP_EXPORT extern LessEqual lessEqual ;

class XLogicalAnd
{
  public:

    template <class T, class U> struct Sig;

    template <class T>
    struct Sig<T,T> : public FunType<T,T,bool>
    {
    };

    template <class T>
    bool operator()( const T&x, const T&y ) const
    {
      return std::logical_and<T>()( x, y ) ;
    }
};

typedef Full2<XLogicalAnd> LogicalAnd ;

Q_FLP_EXPORT extern LogicalAnd logicalAnd ;

class XLogicalOr
{
  public:

    template <class T, class U> struct Sig;

    template <class T>
    struct Sig<T,T> : public FunType<T,T,bool>
    {
    };

    template <class T>
    bool operator()( const T&x, const T&y ) const
    {
      return std::logical_or<T>()( x, y ) ;
    }
};

typedef Full2<XLogicalOr> LogicalOr ;

Q_FLP_EXPORT extern LogicalOr logicalOr ;

class XLogicalNot
{
  public:

    template <class T>
    struct Sig : public FunType<T,bool>
    {
    };

    template <class T>
    bool operator()( const T&x ) const
    {
      return std::logical_not<T>()( x ) ;
    }

};

typedef Full1<XLogicalNot> LogicalNot ;

Q_FLP_EXPORT extern LogicalNot logicalNot ;

class XDereference
{
  public:

    template <class T> struct Sig
    : public FunType<T,typename std::iterator_traits<T>::value_type>
    {
    };

    template <class T>
    typename Sig<T>::ResultType operator()( const T & p ) const
    {
      return (*p) ;
    }

};

typedef Full1<XDereference> Dereference ;

Q_FLP_EXPORT extern Dereference dereference ;

class XAddressOf
{
  public:

    template <class T>
    struct Sig : public FunType<T,const T*>
    {
    };

    template <class T>
    const T * operator()( const T & x ) const
    {
      return &x ;
    }

};

typedef Full1<XAddressOf> AddressOf ;

Q_FLP_EXPORT extern AddressOf addressOf ;

class XDelete_
{
  public:

    template <class T> struct Sig : public FunType<T,void>
    {
    };

    template <class T> void operator()( T* p ) const
    {
      delete p;
    }

} ;

typedef Full1<XDelete_> Delete_ ;

Q_FLP_EXPORT extern Delete_ delete_ ;

template <class Dest>
class XDynamicCast
{
  public:

    template <class Src> struct Sig : public FunType<Src,Dest>
    {
    };

    template <class Src>
    Dest operator()( const Src & s ) const
    {
      return dynamic_cast<Dest>(s);
    }

} ;

template <class T>
class DynamicCast
{
  public:

    typedef Full1<XDynamicCast<T> > Type ;

};

template <class T> Full1<XDynamicCast<T> > dynamicCast()
{
  return makeFull1 ( XDynamicCast<T>() ) ;
}

// outStream is the << stream operator, but takes a stream*
//    e.g.   &cout ^outStream^ x
class XOutStream
{
  public:

    template <class StreamP, class Data> struct Sig
       : public FunType<StreamP,Data,StreamP>
    {
    };

    template <class StreamP, class Data>
    StreamP operator()( StreamP s, const Data& x ) const
    {
      (*s) << x ;
      return s  ;
    }

} ;

typedef Full2<XOutStream> OutStream ;

Q_FLP_EXPORT extern OutStream outStream ;

// inStream is the >> stream operator, but takes stream* and data*
//    e.g.   &cin ^inStream^ &x

class XInStream
{
  public:

    template <class StreamP, class DataP> struct Sig
       : public FunType<StreamP,DataP,StreamP>
    {
    } ;

    template <class StreamP, class DataP>
    StreamP operator()( StreamP s, DataP x ) const
    {
      (*s) >> (*x) ;
      return s     ;
    }

};

typedef Full2<XInStream> InStream ;

Q_FLP_EXPORT extern InStream inStream ;

template <class C, class T>
class ManipMaker
{
  public:

    std::basic_ostream<C,T>& (*
      operator()( std::basic_ostream<C,T>& (*pfn)( std::basic_ostream<C,T>&) )
         const )( std::basic_ostream<C,T>& )
    {
      return pfn ;
    }

    std::basic_ios<C,T>& (*
    operator()( std::basic_ios<C,T>& (*pfn)( std::basic_ios<C,T>& ) )
          const )( std::basic_ios<C,T>& )
    {
      return pfn ;
    }

    std::ios_base& (*
    operator()( std::ios_base& (*pfn)( std::ios_base& ) )
          const )( std::ios_base& )
    {
      return pfn ;
    }
};

template <class C, class T>
ManipMaker<C,T> makeManip( std::basic_ios<C,T>& )
{
  return ManipMaker<C,T>() ;
}

//////////////////////////////////////////////////////////////////////
// STL conversions
//////////////////////////////////////////////////////////////////////

template <class Op>
class Xstl1 : public CfpType<typename Op::argument_type,
                             typename Op::result_type>
{
  public:

    Xstl1( const Op& o ) : f(o)
    {
    }

    typename Op::result_type
    operator()( const typename Op::argument_type& x ) const
    {
      return f(x);
    }

  protected:

    Op f ;

};

template <class Op>
Full1<Xstl1<Op> > stl_to_fun1( const Op& o )
{
  return makeFull1( Xstl1<Op>(o) ) ;
}

template <class Op>
class Xstl2 : public CfpType<typename Op::first_argument_type,
                             typename Op::second_argument_type,
                             typename Op::result_type>
{
  public:

    Xstl2( const Op& o ) : f(o)
    {
    }

    typename Op::result_type
    operator()( const typename Op::first_argument_type  & x ,
                const typename Op::second_argument_type & y ) const
    {
      return f(x,y) ;
    }

  protected:

    Op f ;
};

template <class Op>
Full2<Xstl2<Op> > stl_to_fun2( const Op & o )
{
  return makeFull2 ( Xstl2<Op>(o) ) ;
}

//////////////////////////////////////////////////////////////////////
// monomorphizing conversions
//////////////////////////////////////////////////////////////////////

template <class Arg1, class Arg2, class Arg3, class Res, class F>
class XMonomorphicWrapper3 : public CfpType<Arg1,Arg2,Arg3,Res>
{
  public:

    XMonomorphicWrapper3( const F& g ) : f(g)
    {
    }

    Res operator()( const Arg1 & x, const Arg2 & y, const Arg3 & z ) const
    {
      return f(x,y,z) ;
    }

  protected:

    F f ;

};

template <class Arg1, class Arg2, class Arg3, class Res, class F>
Full3<XMonomorphicWrapper3<Arg1,Arg2,Arg3,Res,F> >
monomorphize3( const F& f )
{
  return makeFull3 ( XMonomorphicWrapper3<Arg1,Arg2,Arg3,Res,F>( f ) ) ;
}

template <class Arg1, class Arg2, class Res, class F>
class XMonomorphicWrapper2 : public CfpType<Arg1,Arg2,Res>
{
  public:

    XMonomorphicWrapper2( const F& g ) : f(g)
    {
    }

    Res operator()( const Arg1& x, const Arg2& y ) const
    {
      return f(x,y) ;
    }

  protected:

    F f ;

};

template <class Arg1, class Arg2, class Res, class F>
Full2<XMonomorphicWrapper2<Arg1,Arg2,Res,F> >
monomorphize2( const F & f )
{
  return makeFull2 ( XMonomorphicWrapper2<Arg1,Arg2,Res,F>( f ) ) ;
}

template <class Arg1, class Res, class F>
class XMonomorphicWrapper1 : public CfpType<Arg1,Res>
{
  public:

    XMonomorphicWrapper1( const F& g ) : f(g)
    {
    }

    Res operator()( const Arg1& x ) const
    {
      return f(x);
    }

  protected:
    F f ;
};

template <class Arg1, class Res, class F>
Full1<XMonomorphicWrapper1<Arg1,Res,F> > monomorphize1( const F& f )
{
  return makeFull1 ( XMonomorphicWrapper1<Arg1,Res,F>( f ) ) ;
}

template <class Res, class F>
class XMonomorphicWrapper0 : public CfpType<Res>
{
  public:

    XMonomorphicWrapper0( const F & g ) : f(g)
    {
    }

    Res operator()() const
    {
      return f();
    }

  protected:

    F f;

};

template <class Res, class F>
Full0<XMonomorphicWrapper0<Res,F> > monomorphize0( const F& f )
{
  return makeFull0 ( XMonomorphicWrapper0<Res,F>( f ) ) ;
}

//////////////////////////////////////////////////////////////////////
// ptr_fun
//////////////////////////////////////////////////////////////////////
// ptr_to_fun is now a functoid -- hurray!

template <class Result>
class Xptr_to_nullary_function : public CfpType<Result>
{
  public:

    explicit Xptr_to_nullary_function(Result (*x)()) : ptr(x)
    {
    }

    Result operator()() const
    {
      return ptr() ;
    }

  protected:

    Result (*ptr)();

};

template <class Arg, class Result>
class Xptr_to_unary_function : public CfpType<Arg, Result>
{
  public:

    explicit Xptr_to_unary_function(Result (*x)(Arg)) : ptr(x)
    {
    }

    Result operator()(Arg x) const
    {
      return ptr ( x ) ;
    }

  protected:

    Result (*ptr)(Arg) ;

};

template <class Arg1, class Arg2, class Result>
class Xptr_to_binary_function : public CfpType<Arg1, Arg2, Result>
{
  public:

    explicit Xptr_to_binary_function(Result (*x)(Arg1, Arg2)) : ptr(x)
    {
    }

    Result operator()(Arg1 x, Arg2 y) const
    {
      return ptr(x, y) ;
    }

  protected:

    Result (*ptr)(Arg1, Arg2);
};

template <class Arg1, class Arg2, class Arg3, class Result>
class Xptr_to_ternary_function : public CfpType<Arg1, Arg2, Arg3, Result>
{
  public:

    explicit Xptr_to_ternary_function(Result (*x)(Arg1, Arg2, Arg3)) : ptr(x)
    {
    }

    Result operator()(Arg1 x, Arg2 y, Arg3 z) const
    {
      return ptr(x,y,z) ;
    }

  protected:

    Result (*ptr)(Arg1, Arg2, Arg3);
};

//////////////////////////////////////////////////////////////////////
// Turn member functions into normal functions which take a Receiver*
// (or a smart pointer) as their first (extra) argument.  Note that we
// disallow reference parameters.
//////////////////////////////////////////////////////////////////////

template <class Arg1, class Arg2, class Arg3, class Result>
class Xptr_to_mem_binary_function
{
  public:

    explicit Xptr_to_mem_binary_function(Result (Arg1::*x)(Arg2,Arg3))
       : ptr(x)
    {
    }

    template <class P, class Y, class Z>
    struct Sig : public FunType<P,Arg2,Arg3,Result>
    {
    };

    template <class P>
    Result operator()(const P& x, const Arg2& y, const Arg3& z) const
       //{ return (x->*ptr)(y,z); }
    {
      return ((*x).*ptr)(y,z) ;
    }

  protected:

    Result (Arg1::*ptr)(Arg2,Arg3) ;

};

template <class Arg1, class Arg2, class Arg3, class Result>
class Xptr_to_const_mem_binary_function
{
  public:

    explicit Xptr_to_const_mem_binary_function(
          Result (Arg1::*x)(Arg2,Arg3) const) : ptr(x)
    {
    }

    template <class P, class Y, class Z>
    struct Sig : public FunType<P,Arg2,Arg3,Result>
    {
    } ;

    template <class P>
    Result operator()(const P& x, const Arg2& y, const Arg3& z) const
       //{ return (x->*ptr)(y,z); }
    {
      return ((*x).*ptr)(y,z) ;
    }

  protected:

    Result (Arg1::*ptr)(Arg2,Arg3) const ;

};

template <class Arg1, class Arg2, class Result>
class Xptr_to_mem_unary_function
{
  public:

    explicit Xptr_to_mem_unary_function(Result (Arg1::*x)(Arg2)) : ptr(x)
    {
    }

    template <class P, class Y>
    struct Sig : public FunType<P,Arg2,Result>
    {
    };

    template <class P>
    Result operator()(const P& x, const Arg2& y) const
    //{ return (x->*ptr)(y); }
    {
      return ((*x).*ptr)(y) ;
    }

  protected:

    Result (Arg1::*ptr)(Arg2) ;

};

template <class Arg1, class Arg2, class Result>
class Xptr_to_const_mem_unary_function
{
  public:

    explicit Xptr_to_const_mem_unary_function(Result (Arg1::*x)(Arg2) const)
       : ptr(x)
    {
    }

    template <class P, class Y>
    struct Sig : public FunType<P,Arg2,Result>
    {
    };

    template <class P>
    Result operator()(const P& x, const Arg2& y) const
       //{ return (x->*ptr)(y); }
    {
      return ((*x).*ptr)(y) ;
    }

  protected:

    Result (Arg1::*ptr)(Arg2) const;

};

template <class Arg1, class Result>
class Xptr_to_mem_nullary_function
{
  public:

    explicit Xptr_to_mem_nullary_function(Result (Arg1::*x)()) : ptr(x)
    {
    }

    template <class P>
    struct Sig : public FunType<P,Result>
    {
    } ;

    template <class P>
    //Result operator()(const P& x) const { return (x->*ptr)(); }
    Result operator()(const P& x) const
    {
      return ((*x).*ptr)() ;
    }

  protected:

    Result (Arg1::*ptr)() ;

};

template <class Arg1, class Result>
class Xptr_to_const_mem_nullary_function
{
  public:

    explicit Xptr_to_const_mem_nullary_function(Result (Arg1::*x)() const)
       : ptr(x)
    {
    }

    template <class P>
    struct Sig : public FunType<P,Result>
    {
    };

    template <class P>
    //Result operator()(const P& x) const { return (x->*ptr)(); }
    Result operator()(const P& x) const
    {
      return ((*x).*ptr)();
    }

  protected:

    Result (Arg1::*ptr)() const;
};

class XPtrToFun
{
  public:

    template <class P> struct Sig ;

    // non-member functions
    template <class Result>
    struct Sig< Result (*)() > : public FunType< Result (*)(),
      Full0<Xptr_to_nullary_function<Result> > >
    {
    } ;

    template <class A1, class Result>
    struct Sig< Result (*)(A1) > : public FunType< Result (*)(A1),
      Full1<Xptr_to_unary_function<A1,Result> > >
    {
    } ;

    template <class A1, class A2, class Result>
    struct Sig< Result (*)(A1,A2) > : public FunType< Result (*)(A1,A2),
      Full2<Xptr_to_binary_function<A1,A2,Result> > >
    {
    } ;

    template <class A1, class A2, class A3, class Result>
    struct Sig< Result (*)(A1,A2,A3) > : public FunType< Result (*)(A1,A2,A3),
      Full3<Xptr_to_ternary_function<A1,A2,A3,Result> > >
    {
    } ;

    // member functions
    template <class A1, class A2, class A3, class Result>
    struct Sig< Result (A1::*)(A2,A3) > : public FunType<
      Result (A1::*)(A2,A3),
      Full3<Xptr_to_mem_binary_function<A1, A2, A3, Result> > >
    {
    } ;

    template <class A1, class A2, class A3, class Result>
    struct Sig< Result (A1::*)(A2,A3) const > : public FunType<
      Result (A1::*)(A2,A3) const,
      Full3<Xptr_to_const_mem_binary_function<A1, A2, A3, Result> > >
    {
    } ;

    template <class A1, class A2, class Result>
    struct Sig< Result (A1::*)(A2) > : public FunType<
      Result (A1::*)(A2),
      Full2<Xptr_to_mem_unary_function<A1, A2, Result> > >
    {
    } ;

    template <class A1, class A2, class Result>
    struct Sig< Result (A1::*)(A2) const > : public FunType<
      Result (A1::*)(A2) const,
      Full2<Xptr_to_const_mem_unary_function<A1, A2, Result> > >
    {
    } ;

    template <class A1, class Result>
    struct Sig< Result (A1::*)() > : public FunType<
      Result (A1::*)(),
      Full1<Xptr_to_mem_nullary_function<A1, Result> > >
    {
    } ;

    template <class A1, class Result>
    struct Sig< Result (A1::*)() const > : public FunType<
      Result (A1::*)() const,
      Full1<Xptr_to_const_mem_nullary_function<A1, Result> > >
    {
    } ;

    // non-member functions
    template <class Result>
    inline Full0<Xptr_to_nullary_function<Result> >
    operator()(Result (*x)()) const
    {
      return makeFull0( Xptr_to_nullary_function<Result>(x) ) ;
    }

    template <class A, class Result>
    inline Full1<Xptr_to_unary_function<A, Result> >
    operator()(Result (*x)(A)) const
    {
      return makeFull1( Xptr_to_unary_function<A, Result>(x) ) ;
    }

    template <class A1, class A2, class Result>
    inline Full2<Xptr_to_binary_function<A1, A2, Result> >
    operator()(Result (*x)(A1, A2)) const
    {
      return makeFull2( Xptr_to_binary_function<A1, A2, Result>(x) ) ;
    }

    template <class A1, class A2, class A3, class Result>
    inline Full3<Xptr_to_ternary_function<A1, A2, A3, Result> >
    operator()(Result (*x)(A1, A2, A3)) const
    {
      return makeFull3( Xptr_to_ternary_function<A1,A2,A3,Result>(x) ) ;
    }

    // member functions
    template <class A1, class A2, class A3, class Result>
    inline Full3<Xptr_to_mem_binary_function<A1, A2, A3, Result> >
    operator()(Result (A1::*x)(A2,A3)) const
    {
      return makeFull3(Xptr_to_mem_binary_function<A1, A2, A3, Result>(x) ) ;
    }

    template <class A1, class A2, class A3, class Result>
    inline Full3<Xptr_to_const_mem_binary_function<A1, A2, A3, Result> >
    operator()(Result (A1::*x)(A2,A3) const) const
    {
      return makeFull3(Xptr_to_const_mem_binary_function<A1, A2, A3, Result>(x) ) ;
    }

    template <class A1, class A2, class Result>
    inline Full2<Xptr_to_mem_unary_function<A1, A2, Result> >
    operator()(Result (A1::*x)(A2)) const
    {
      return makeFull2( Xptr_to_mem_unary_function<A1, A2, Result>(x) ) ;
    }

    template <class A1, class A2, class Result>
    inline Full2<Xptr_to_const_mem_unary_function<A1, A2, Result> >
    operator()(Result (A1::*x)(A2) const) const
    {
      return makeFull2(Xptr_to_const_mem_unary_function<A1, A2, Result>(x) ) ;
    }

    template <class A1, class Result>
    inline Full1<Xptr_to_mem_nullary_function<A1, Result> >
    operator()(Result (A1::*x)()) const
    {
      return makeFull1( Xptr_to_mem_nullary_function<A1, Result>(x) ) ;
    }

    template <class A1, class Result>
    inline Full1<Xptr_to_const_mem_nullary_function<A1, Result> >
    operator()(Result (A1::*x)() const) const
    {
      return makeFull1( Xptr_to_const_mem_nullary_function<A1, Result>(x) ) ;
    }

};

typedef Full1<XPtrToFun> PtrToFun ;

Q_FLP_EXPORT extern PtrToFun ptr_to_fun ;

//////////////////////////////////////////////////////////////////////
// funify is an identity for FullNs, but calls ptr_to_fun otherwise
//////////////////////////////////////////////////////////////////////

class XFunify
{
  public:

    template <class P> struct Sig : public FunType<P,
       typename RT<PtrToFun,P>::ResultType>
    {
    } ;

    template <class F> struct Sig< Full0<F> >
    : public FunType< Full0<F>, Full0<F> >
    {
    } ;

    template <class F> struct Sig< Full1<F> >
    : public FunType< Full1<F>, Full1<F> >
    {
    } ;

    template <class F> struct Sig< Full2<F> >
    : public FunType< Full2<F>, Full2<F> >
    {
    } ;

    template <class F> struct Sig< Full3<F> >
    : public FunType< Full3<F>, Full3<F> >
    {
    } ;

    template <class P>
    typename Sig<P>::ResultType
    operator()( const P & p ) const
    {
      return ptr_to_fun ( p ) ;
    }

    template <class F>
    typename Sig<Full0<F> >::ResultType
    operator()( const Full0<F>& f ) const
    {
      return f ;
    }

    template <class F>
    typename Sig<Full1<F> >::ResultType
    operator()( const Full1<F>& f ) const
    {
      return f ;
    }

    template <class F>
    typename Sig<Full2<F> >::ResultType
    operator()( const Full2<F>& f ) const
    {
      return f ;
    }

    template <class F>
    typename Sig<Full3<F> >::ResultType
    operator()( const Full3<F>& f ) const
    {
      return f ;
    }

};

typedef Full1<XFunify> Funify ;

//////////////////////////////////////////////////////////////////////
// Misc stuff
//////////////////////////////////////////////////////////////////////
// FIX THIS: add dec?  pre/post versions?

class XInc
{
  public:

    template <class T>
    struct Sig : public FunType<T,T>
    {
    };

    template <class T>
    T operator()(const T& x) const
    {
      T y = x ;
      return ++y ;
    }
};

typedef Full1<XInc> Inc;


// These are obsolete; ignore(const_(true)) and ignore(const_(false))
// do the same thing.  Hurray for combinators!

class XAlways1
{
  public:

    template <class T>
    struct Sig : public FunType<T,bool>
    {
    };

    template <class T>
    bool operator()(const T&) const
    {
      return true;
    }

};

typedef Full1<XAlways1> Always1 ;

class XNever1
{
  public:

    template <class T>
    struct Sig : public FunType<T,bool>
    {
    };

    template <class T>
    bool operator()(const T&) const
    {
      return false;
    }

};

typedef Full1<XNever1> Never1 ;

/****************************************************************************\
 * AnyType is the type to use when we don't care about the                  *
 * instantiation of a template. This usually happens when we are            *
 * reading the signature of a monomorphic function as if it were            *
 * polymorphic.                                                             *
\****************************************************************************/

class AnyType { } ;

/****************************************************************************\
 * Ok, this file has been a mess, so I'm trying to clean it up.  The        *
 * file is divided into 4 sections, for Fun0, Fun1, Fun2, and Fun3.         *
 * The sections are all pretty redundant, except that                       *
 *  - Fun2 implements its own currying                                      *
 *  - Fun3 uses Curryable3 to implement its currying                        *
 * As a result, I'm removing some of the redundant comments from all the    *
 * sections except Fun0.  So basically, use the comments in the Fun0        *
 * section as a reference for the corresponding structures in the other     *
 * FunN classes.                                                            *
\****************************************************************************/

template <class Result> class Fun0Impl ;
template <class Result> class Fun0     ;

template <class Rd, class Rs>   // result of dest, result of src
Fun0Impl<Rd>* convert0( const IRef<const Fun0Impl<Rs> >& f ) ;

template <class Rd, class DF> class Fun0Constructor ;

template <class Result>
class Fun0
{
  protected:

    typedef IRef<const Fun0Impl<Result> > RefImpl ;

    RefImpl ref ;

    template <class T> friend class Fun0 ;

    template <class Rd, class Rs>
    friend Fun0<Rd> explicit_convert0( const Fun0<Rs>& f ) ;

    template <class Rd, class DF> friend class Fun0Constructor ;

  public:

    // See comment in Fun0Impl about g++2.95.2
    typedef Result ResultType;

    template <class Dummy1=Void, class Dummy2=Void>
    struct Sig : public FunType<WrongNumberOfSigArgs>
    {
    } ;

    template <class Dummy>
    struct Sig<Void,Dummy> : public FunType<Result>
    {
    } ;

    template <class Dummy, int i> struct crazy_accepts
    {
       static const bool args = false;
    };

    template <class Dummy> struct crazy_accepts<Dummy,0>
    {
      static const bool args = true ;
    };

    static const int crazy_max_args = 0 ;

    typedef const Fun0Impl<Result>* Impl ;

    // int is dummy arg to differentiate from the template constructor
    Fun0 ( int, Impl i ) : ref(i)
    {
    }

    Result operator()() const
    {
      return ref->operator()() ;
    }

    template <class DF>   // direct functoid (or subtype polymorphism)
    Fun0( const DF& f ) : ref( Fun0Constructor<Result,DF>::make(f) )
    {
    }

    Fun0( const Fun0& x ) : ref(x.ref)
    {
    }

    Fun0& operator=( const Fun0& x )
    {
      ref = x.ref  ;
      return *this ;
    }

    typedef Fun0 This ;

    template <class A> typename BracketCallable<This,A>::Result
    operator[]( const A& a ) const
    {
      return BracketCallable<This,A>::go( *this, a ) ;
    }

};

// See comments below
template <class R> struct Inherits<Fun0<R>,CallableWithoutArguments>
{
  static const bool value = true ;
};

template <class R> struct Inherits<Fun0<R>,SmartFunctoid>
{
  static const bool value = true ;
} ;

template <class Result>
class Fun0Impl : public IRefable
{
  public:
    // g++2.95.2 doesn't implement the empty-base-class-optimization, so we
    // 'hand code' the Sig information rather than just inheriting it from a
    // CfpType class.  Fun0s are on the 'critical path' for lists, and need
    // to be extra efficient.
    typedef Result ResultType ;

    template <class Dummy1=Void, class Dummy2=Void>
    struct Sig : public FunType<WrongNumberOfSigArgs>
    {
    } ;

    template <class Dummy>
    struct Sig<Void,Dummy> : public FunType<Result>
    {
    } ;

    virtual Result operator()() const = 0 ;
    virtual ~Fun0Impl(void)
    {
    }

};

// Since we cheated inheritance above, we need to inform our inheritance
// detector for the particular case of importance.

template <class R> struct Inherits<Fun0Impl<R>,CallableWithoutArguments>
{
  static const bool value = true ;
} ;

template <class Rd, class Rs>
class Fun0Converter : public Fun0Impl<Rd>
{
  protected:

    typedef IRef<const Fun0Impl<Rs> > MyFun ;

    MyFun f ;

  public:

    Fun0Converter( const MyFun& g ) : f(g)
    {
    }

    Rd operator()() const
    {
      return f->operator()() ;
    }

};

template <class Rd, class Rs>
Fun0Impl<Rd>* convert0( const IRef<const Fun0Impl<Rs> >& f )
{
  return new Fun0Converter<Rd,Rs>( f ) ;
}

template <class Rd, class Rs>
class Fun0ExplicitConverter : public Fun0Impl<Rd>
{
  protected:

    typedef IRef<const Fun0Impl<Rs> > MyFun ;

    MyFun f;

  public:

    Fun0ExplicitConverter( const MyFun& g ) : f(g)
    {
    }

    Rd operator()() const
    {
      return static_cast<Rd>( f->operator()() ) ;
    }

};

template <class Rd, class Rs>
Fun0<Rd> explicit_convert0( const Fun0<Rs>& f )
{
  return Fun0<Rd>( 1, new Fun0ExplicitConverter<Rd,Rs>( f.ref ) ) ;
}

template <class Gen>
class Gen0 : public Fun0Impl<typename RT<Gen>::ResultType>
{
  public:

    Gen0( Gen x ) : g(x)
    {
    }

    typename RT<Gen>::ResultType operator()() const
    {
      return g();
    }

  protected:

     Gen g ;

};

template <class Gen>
Fun0<typename RT<Gen>::ResultType> makeFun0( const Gen& g )
{
  return Fun0<typename RT<Gen>::ResultType>(1,new Gen0<Gen>(g)) ;
}

template <class Nullary>
Gen0<Nullary>* makeFun0Ref( const Nullary& g )
{
  return new Gen0<Nullary>(g) ;
}

// Note: conversion-from-direct-functoid and subtype-polymorphism are
// really two different kinds of functionality.  However, if we try to
// create two separate constructors in the Fun0 class, we end up with
// ambiguity (C++ can't tell which one to call).  As a result, there is
// one constructor that handles both cases by forwarding the work to
// this class, which uses partial specialization to distinguish between
// the two cases.

template <class Rd, class DF>
class Fun0Constructor
{
  public:

    static Fun0Impl<Rd>* make( const DF& df )
    {
      return makeFun0Ref( monomorphize0<Rd>(df) ) ;
    }

} ;

template <class Rd, class Rs>
class Fun0Constructor<Rd,Fun0<Rs> >
{
  public:

    static Fun0Impl<Rd>* make( const Fun0<Rs>& f )
    {
      return convert0<Rd>(f.ref) ;
    }

} ;

template <class Arg1, class Result> class Fun1Impl ;

template <class A1d, class Rd, class A1s, class Rs>
Fun1Impl<A1d,Rd>* convert1( const IRef<const Fun1Impl<A1s,Rs> >& f ) ;

template <class Ad, class Rd, class DF> class Fun1Constructor ;

template <class Arg1, class Result>
class Fun1 : public CfpType<Arg1,Result>, public SmartFunctoid1
{
  protected:

    typedef IRef<const Fun1Impl<Arg1,Result> > RefImpl;

    RefImpl ref ;

    template <class A, class B> friend class Fun1 ;

    template <class Ad, class Rd, class DF> friend class Fun1Constructor ;

    template <class A1d, class Rd, class A1s, class Rs>
    friend Fun1<A1d,Rd> explicit_convert1( const Fun1<A1s,Rs>& f ) ;

  public:

    typedef Fun1Impl<Arg1,Result> * Impl ;

    Fun1( int, Impl i ) : ref(i)
    {
    }

    Result operator()( const Arg1& x ) const
    {
      return ref->operator()(x) ;
    }

    template <class DF>
    Fun1( const DF& df ) : ref( Fun1Constructor<Arg1,Result,DF>::make(df) )
    {
    }

    Fun1( const Fun1& x ) : ref(x.ref)
    {
    }

    Fun1& operator=( const Fun1& x )
    {
      ref = x.ref; return *this ;
    }

    typedef Fun1 This ;
    template <class A> typename BracketCallable<This,A>::Result
    operator[]( const A& a ) const
    {
      return BracketCallable<This,A>::go( *this, a ) ;
    }

};

template <class Arg1, class Result>
class Fun1Impl : public CfpType<Arg1,Result>, public IRefable
{
  public:

    virtual Result operator()( const Arg1& ) const = 0 ;
    virtual ~Fun1Impl(void)
    {
    }

};

template <class A1d, class Rd, class A1s, class Rs>
class Fun1Converter : public Fun1Impl<A1d,Rd>
{
  protected:

    typedef IRef<const Fun1Impl<A1s,Rs> > MyFun ;

    MyFun f ;

  public:

   Fun1Converter( const MyFun& g ) : f(g)
   {
   }

   Rd operator()( const A1d& x ) const
   {
     return f->operator()( x ) ;
   }

};

template <class A1d, class Rd, class A1s, class Rs>
Fun1Impl<A1d,Rd>* convert1( const IRef<const Fun1Impl<A1s,Rs> >& f )
{
  return new Fun1Converter<A1d,Rd,A1s,Rs>( f ) ;
}

template <class A1d, class Rd, class A1s, class Rs>
class Fun1ExplicitConverter : public Fun1Impl<A1d,Rd>
{
  protected:

    typedef IRef<const Fun1Impl<A1s,Rs> > MyFun ;

    MyFun f ;

  public:

    Fun1ExplicitConverter( const MyFun& g ) : f(g)
    {
    }

    Rd operator()( const A1d& x ) const
    {
      return static_cast<Rd>( f->operator()(  static_cast<A1s>(x)  ) ) ;
    }

};

template <class A1d, class Rd, class A1s, class Rs>
Fun1<A1d,Rd> explicit_convert1( const Fun1<A1s,Rs>& f )
{
  return Fun1<A1d,Rd>( 1, new Fun1ExplicitConverter<A1d,Rd,A1s,Rs>(f.ref) ) ;
}

template <class Gen>
class Gen1 : public Fun1Impl<typename Gen::template Sig<AnyType>::Arg1Type,
                             typename Gen::template Sig<AnyType>::ResultType>
{
  public:

    Gen1( Gen x ) : g(x)
    {
    }

    typename Gen::template Sig<AnyType>::ResultType
    operator()( const typename Gen::template Sig<AnyType>::Arg1Type& x ) const
    {
      return g(x);
    }

  protected:

    Gen g ;

};

template <class Unary>
Fun1<typename Unary::template Sig<AnyType>::Arg1Type,
     typename Unary::template Sig<AnyType>::ResultType>
makeFun1( const Unary& g )
{
  return Fun1<typename Unary::template Sig<AnyType>::Arg1Type,
              typename Unary::template Sig<AnyType>::ResultType>
              (1,new Gen1<Unary>(g)) ;
}

template <class Unary>
Gen1<Unary>* makeFun1Ref( const Unary& g )
{
  return new Gen1<Unary>(g) ;
}

template <class Ad, class Rd, class DF>
class Fun1Constructor
{
  public:

    static Fun1Impl<Ad,Rd>* make( const DF& df )
    {
      return makeFun1Ref( monomorphize1<Ad,Rd>(df) ) ;
    }
};

template <class Ad, class Rd, class As, class Rs>
class Fun1Constructor<Ad,Rd,Fun1<As,Rs> >
{
  public:

    static Fun1Impl<Ad,Rd>* make( const Fun1<As,Rs>& f )
    {
      return convert1<Ad,Rd>(f.ref);
    }

};

//////////////////////////////////////////////////////////////////////

template <class Arg1, class Arg2, class Result> class Fun2Impl ;

template <class A1d, class A2d, class Rd, class A1s, class A2s, class Rs>
Fun2Impl<A1d,A2d,Rd>* convert2( const IRef<const Fun2Impl<A1s,A2s,Rs> >& f ) ;

template <class A1d, class A2d, class Rd, class DF> class Fun2Constructor ;

// Note that this class has two signatures: it can be used either as
// a two argument function or as a single argument function (currying).

template <class Arg1, class Arg2, class Result>
class Fun2 : public SmartFunctoid2
{
  protected:

    typedef IRef<const Fun2Impl<Arg1, Arg2, Result> > RefImpl ;

    RefImpl ref ;

    template <class A1, class A2, class R> friend class Fun2 ;

    template <class A1d, class A2d, class Rd, class A1s, class A2s, class Rs>
    friend Fun2<A1d,A2d,Rd> explicit_convert2( const Fun2<A1s,A2s,Rs>& f ) ;

    template <class A1d, class A2d, class Rd, class DF>
    friend class Fun2Constructor ;

  public:

    // Signature for normal use of the functoid (2 args)
    template <class P1, class P2 = void>
    struct Sig : public FunType<Arg1, Arg2, Result>
    {
    } ;

    // Signature for using this function with automatic currying (1-arg)
    template <class P1>
    struct Sig<P1,void> : public FunType<Arg1, Fun1<Arg2, Result> >
    {
    };

    // Signatures for using this function with underscore currying (1-arg)
    template <class P2>
    struct Sig<AutoCurryType,P2>
    : public FunType<AutoCurryType, P2, Fun1<Arg1, Result> >
    {
    };

    template <class P1>
    struct Sig<P1,AutoCurryType>
    : public FunType<P1, AutoCurryType, Fun1<Arg2, Result> >
    {
    };

    typedef Fun2Impl<Arg1,Arg2,Result>* Impl ;
    Fun2( int, Impl i ) : ref(i)
    {
    }

    template <class DF>
    Fun2( const DF& df )
    : ref( Fun2Constructor<Arg1,Arg2,Result,DF>::make(df) )
    {
    }

    Fun2( const Fun2& x ) : ref(x.ref)
    {
    }

    Fun2& operator=( const Fun2& x )
    {
      ref = x.ref  ;
      return *this ;
    }

    // normal call
    Result operator()( const Arg1& x, const Arg2& y ) const
    {
      return ref->operator()(x,y) ;
    }

    // inheritable underscore currying!
    Fun1<Arg1, Result> operator()( const AutoCurryType&, const Arg2& y ) const
    {
      return makeFun1(bind2of2(*this, y)) ;
    }

    Fun1<Arg2, Result> operator()( const Arg1& x, const AutoCurryType& ) const
    {
      return makeFun1(bind1of2(*this, x)) ;
    }

    // REVIEW: Note that this could return a direct functoid, too, which
    // might be more efficient.  Same with other currying calls.

    // inheritable automatic currying!
    Fun1<Arg2,Result> operator()( const Arg1& x) const
    {
      return makeFun1(bind1of2(*this, x)) ;
    }

    typedef Fun2 This;
    template <class A> typename BracketCallable<This,A>::Result
    operator[]( const A& a ) const
    {
      return BracketCallable<This,A>::go( *this, a ) ;
    }

};

template <class Arg1, class Arg2, class Result>
class Fun2Impl : public CfpType<Arg1,Arg2,Result>
               , public IRefable
{
  public:

    virtual Result operator()( const Arg1&, const Arg2& ) const = 0 ;

    virtual ~Fun2Impl()
    {
    }

};

template <class A1d, class A2d, class Rd, class A1s, class A2s, class Rs>
class Fun2Converter : public Fun2Impl<A1d,A2d,Rd>
{
  protected:

    typedef IRef<const Fun2Impl<A1s,A2s,Rs> > MyFun ;

    MyFun f ;

  public:

    Fun2Converter( const MyFun& g ) : f(g)
    {
    }

    Rd operator()( const A1d& x, const A2d& y ) const
    {
      return f->operator()( x, y ) ;
    }

};

template <class A1d, class A2d, class Rd, class A1s, class A2s, class Rs>
Fun2Impl<A1d,A2d,Rd>* convert2( const IRef<const Fun2Impl<A1s,A2s,Rs> >& f )
{
  return new Fun2Converter<A1d,A2d,Rd,A1s,A2s,Rs>( f ) ;
}

template <class A1d, class A2d, class Rd, class A1s, class A2s, class Rs>
class Fun2ExplicitConverter : public Fun2Impl<A1d,A2d,Rd>
{
  protected:

    typedef IRef<const Fun2Impl<A1s,A2s,Rs> > MyFun ;

    MyFun f ;

  public:

    Fun2ExplicitConverter( const MyFun& g ) : f(g)
    {
    }

    Rd operator()( const A1d& x, const A2d& y ) const
    {
      return static_cast<Rd>( f->operator()( static_cast<A1s>(x)     ,
                                             static_cast<A2s>(y) ) ) ;
    }

};

template <class A1d, class A2d, class Rd, class A1s, class A2s, class Rs>
Fun2<A1d,A2d,Rd> explicit_convert2( const Fun2<A1s,A2s,Rs>& f )
{
  return Fun2<A1d,A2d,Rd>( 1,
      new Fun2ExplicitConverter<A1d,A2d,Rd,A1s,A2s,Rs>(f.ref) ) ;
}

template <class Gen>
class Gen2 : public Fun2Impl<
      typename Gen::template Sig<AnyType, AnyType>::Arg1Type,
      typename Gen::template Sig<AnyType, AnyType>::Arg2Type,
      typename Gen::template Sig<AnyType, AnyType>::ResultType>
{
  public:

    Gen2( Gen x ) : g(x)
    {
    }

    typename Gen::template Sig<AnyType, AnyType>::ResultType
    operator()(
      const typename Gen::template Sig<AnyType,AnyType>::Arg1Type& x,
      const typename Gen::template Sig<AnyType,AnyType>::Arg2Type& y ) const
    {
      return g(x,y) ;
    }

  protected:

    Gen g ;

};

template <class Binary>
Fun2<typename Binary::template Sig<AnyType, AnyType>::Arg1Type  ,
     typename Binary::template Sig<AnyType, AnyType>::Arg2Type  ,
     typename Binary::template Sig<AnyType, AnyType>::ResultType>
makeFun2( const Binary& g )
{
  return Fun2<typename Binary::template Sig<AnyType, AnyType>::Arg1Type  ,
              typename Binary::template Sig<AnyType, AnyType>::Arg2Type  ,
              typename Binary::template Sig<AnyType, AnyType>::ResultType>
              (1,new Gen2<Binary>(g))                                    ;
}

template <class Binary>
Gen2<Binary> * makeFun2Ref( const Binary& g )
{
  return new Gen2<Binary>(g) ;
}

template <class A1d, class A2d, class Rd, class DF>
class Fun2Constructor
{
  public:

    static Fun2Impl<A1d,A2d,Rd>* make( const DF& df )
    {
      return makeFun2Ref( monomorphize2<A1d,A2d,Rd>(df) ) ;
    }

};

template <class A1d, class A2d, class Rd, class A1s, class A2s, class Rs>
class Fun2Constructor<A1d,A2d,Rd,Fun2<A1s,A2s,Rs> >
{
  public:

    static Fun2Impl<A1d,A2d,Rd>* make( const Fun2<A1s,A2s,Rs>& f )
    {
      return convert2<A1d,A2d,Rd>(f.ref) ;
    }

};

//////////////////////////////////////////////////////////////////////

template <class Arg1, class Arg2, class Arg3, class Result> class Fun3Impl ;

template <class Arg1, class Arg2, class Arg3, class Result> class Fun3     ;

template <class A1d, class A2d, class A3d, class Rd,
          class A1s, class A2s, class A3s, class Rs>
Fun3Impl<A1d,A2d,A3d,Rd>*
convert3( const IRef<const Fun3Impl<A1s,A2s,A3s,Rs> >& f ) ;

template <class A1d, class A2d, class A3d, class Rd, class DF>
class Fun3Constructor ;

// The "Guts" class helps us implement currying; Fun3 floats gently atop
// Fun3Guts and adds currying.

template <class Arg1, class Arg2, class Arg3, class Result>
class Fun3Guts : public CfpType<Arg1,Arg2,Arg3,Result>
{
  protected:

    typedef IRef<const Fun3Impl<Arg1,Arg2,Arg3,Result> > RefImpl ;

    RefImpl ref ;

    template <class A, class B, class C, class D> friend class Fun3Guts ;
    template <class A, class B, class C, class D> friend class Fun3     ;

    template <class A1d, class A2d, class A3d, class Rd, class DF>
    friend class Fun3Constructor ;

    template <class A1d, class A2d, class A3d, class Rd,
              class A1s, class A2s, class A3s, class Rs>
    friend Fun3<A1d,A2d,A3d,Rd>
    explicit_convert3( const Fun3<A1s,A2s,A3s,Rs>& f ) ;

  public:

    typedef Fun3Impl<Arg1,Arg2,Arg3,Result> * Impl ;

    Fun3Guts( int, Impl i ) : ref(i)
    {
    }

    Result operator()( const Arg1& x, const Arg2& y, const Arg3& z ) const
    {
      return ref->operator()(x,y,z) ;
    }

    template <class DF>
    Fun3Guts( const DF& df )
    : ref( Fun3Constructor<Arg1,Arg2,Arg3,Result,DF>::make(df) )
    {
    }

    Fun3Guts( const Fun3Guts& x ) : ref(x.ref)
    {
    }

    Fun3Guts & operator=( const Fun3Guts& x )
    {
      ref = x.ref  ;
      return *this ;
    }

};

template <class Arg1, class Arg2, class Arg3, class Result>
class Fun3 : public SmartFunctoid3
{
  protected:

    template <class A1d, class A2d, class A3d, class Rd, class DF>
    friend class Fun3Constructor ;

    template <class A1d, class A2d, class A3d, class Rd,
              class A1s, class A2s, class A3s, class Rs>
    friend Fun3<A1d,A2d,A3d,Rd>
    explicit_convert3( const Fun3<A1s,A2s,A3s,Rs>& f ) ;

    Fun3Guts<Arg1,Arg2,Arg3,Result> rep ;

  public:

    typedef Fun3Impl<Arg1,Arg2,Arg3,Result> * Impl ;

    Fun3( int, Impl i ) : rep(1,i)
    {
    }

    template <class DF>
    Fun3( const DF& df ) : rep(df)
    {
    }

    Fun3( const Fun3& x ) : rep(x.rep)
    {
    }

    Fun3& operator=( const Fun3& x )
    {
      rep = x.rep  ;
      return *this ;
    }

    typedef Curryable3<Fun3Guts<Arg1,Arg2,Arg3,Result> > SigHelp ;

    template <class A, class B=void, class C=void>
    struct Sig : public SigHelp::template Sig<A,B,C>
    {
    } ;

    template <class A, class B, class C>
    typename Sig<A,B,C>::ResultType
    operator()( const A& x, const B& y, const C& z ) const
    {
      return makeCurryable3(rep)(x,y,z) ;
    }

    template <class A, class B>
    typename Sig<A,B>::ResultType
    operator()( const A& x, const B& y ) const
    {
      return curry3(rep,x,y) ;
    }

    template <class A>
    typename Sig<A>::ResultType
    operator()( const A& x ) const
    {
      return curry3(rep,x) ;
    }

    typedef Fun3 This ;

    template <class A> typename BracketCallable<This,A>::Result
    operator[]( const A& a ) const
    {
      return BracketCallable<This,A>::go( *this, a ) ;
    }

} ;

template <class Arg1, class Arg2, class Arg3, class Result>
class Fun3Impl : public CfpType<Arg1,Arg2,Arg3,Result>
               , public IRefable
{
  public:

    Fun3Impl(void)
    {
    }

    virtual ~Fun3Impl()
    {
    }

    virtual Result operator()(const Arg1&,const Arg2&,const Arg3&) const = 0 ;

};

template <class A1d, class A2d, class A3d, class Rd,
          class A1s, class A2s, class A3s, class Rs>
class Fun3Converter : public Fun3Impl<A1d,A2d,A3d,Rd>
{
  protected:

    typedef IRef<const Fun3Impl<A1s,A2s,A3s,Rs> > MyFun ;

    MyFun f ;

  public:

    Fun3Converter( const MyFun& g ) : f(g)
    {
    }

    Rd operator()( const A1d& x, const A2d& y, const A3d& z ) const
    {
      return f->operator()( x, y, z );
    }

};

template <class A1d, class A2d, class A3d, class Rd,
          class A1s, class A2s, class A3s, class Rs>
Fun3Impl<A1d,A2d,A3d,Rd>*
convert3( const IRef<const Fun3Impl<A1s,A2s,A3s,Rs> >& f )
{
  return new Fun3Converter<A1d,A2d,A3d,Rd,A1s,A2s,A3s,Rs>( f ) ;
}

template <class A1d, class A2d, class A3d, class Rd,
          class A1s, class A2s, class A3s, class Rs>
class Fun3ExplicitConverter : public Fun3Impl<A1d,A2d,A3d,Rd>
{
  protected:

    typedef IRef<const Fun3Impl<A1s,A2s,A3s,Rs> > MyFun ;

    MyFun f ;

  public:

    Fun3ExplicitConverter( const MyFun& g ) : f(g)
    {
    }

    Rd operator()( const A1d& x, const A2d& y, const A3d& z ) const
    {
      return static_cast<Rd>( f->operator()(  static_cast<A1s>(x),
         static_cast<A2s>(y), static_cast<A3s>(z)  ) );
    }

};

template <class A1d, class A2d, class A3d, class Rd,
          class A1s, class A2s, class A3s, class Rs>
Fun3<A1d,A2d,A3d,Rd> explicit_convert3( const Fun3<A1s,A2s,A3s,Rs>& f )
{
  return Fun3<A1d,A2d,A3d,Rd>( 1,
    new Fun3ExplicitConverter<A1d,A2d,A3d,Rd,A1s,A2s,A3s,Rs>(f.rep.ref) ) ;
}

template <class Gen>
class Gen3 : public Fun3Impl<
   typename Gen::template Sig<AnyType,AnyType,AnyType>::Arg1Type,
   typename Gen::template Sig<AnyType,AnyType,AnyType>::Arg2Type,
   typename Gen::template Sig<AnyType,AnyType,AnyType>::Arg3Type,
   typename Gen::template Sig<AnyType,AnyType,AnyType>::ResultType>
{
  public:

    Gen3( Gen x ) : g(x)
    {
    }

    typename Gen::template Sig<AnyType,AnyType,AnyType>::ResultType
    operator()(
      const typename Gen::template Sig<AnyType,AnyType,AnyType>::Arg1Type & x ,
      const typename Gen::template Sig<AnyType,AnyType,AnyType>::Arg2Type & y ,
      const typename Gen::template Sig<AnyType,AnyType,AnyType>::Arg3Type & z ) const
    {
      return g(x,y,z) ;
    }

  protected:

    Gen g ;

};

template <class Ternary>
Fun3<typename Ternary::template Sig<AnyType,AnyType,AnyType>::Arg1Type,
     typename Ternary::template Sig<AnyType,AnyType,AnyType>::Arg2Type,
     typename Ternary::template Sig<AnyType,AnyType,AnyType>::Arg3Type,
     typename Ternary::template Sig<AnyType,AnyType,AnyType>::ResultType>
makeFun3( const Ternary& g )
{
  return
    Fun3<typename Ternary::template Sig<AnyType,AnyType,AnyType>::Arg1Type  ,
         typename Ternary::template Sig<AnyType,AnyType,AnyType>::Arg2Type  ,
         typename Ternary::template Sig<AnyType,AnyType,AnyType>::Arg3Type  ,
         typename Ternary::template Sig<AnyType,AnyType,AnyType>::ResultType>
         (1,new Gen3<Ternary>(g)) ;
}

template <class Ternary>
Gen3<Ternary>* makeFun3Ref( const Ternary& g )
{
  return new Gen3<Ternary>(g) ;
}

template <class A1d, class A2d, class A3d, class Rd, class DF>
class Fun3Constructor
{
  public:

    static Fun3Impl<A1d,A2d,A3d,Rd>* make( const DF& df )
    {
      return makeFun3Ref ( monomorphize3<A1d,A2d,A3d,Rd>(df) ) ;
    }

};

template <class A1d, class A2d, class A3d, class Rd,
          class A1s, class A2s, class A3s, class Rs>
class Fun3Constructor<A1d,A2d,A3d,Rd,Fun3<A1s,A2s,A3s,Rs> >
{
  public:

    static Fun3Impl<A1d,A2d,A3d,Rd>* make( const Fun3<A1s,A2s,A3s,Rs>& f )
    {
      return convert3<A1d,A2d,A3d,Rd>(f.rep.ref) ;
    }

};

class Inv { } ;
class Var { } ;

template <class V, class X> class Maybe_Var_Inv ;
template <class X>
class Maybe_Var_Inv<Var,X>
{
  public:

    static void remake( X& x, const X& val )
    {
      x.~X() ;
      new (&x) X(val) ;
    }

    static X clone( const X& x )
    {
      return X(x) ;
    }

};

template <class X>
class Maybe_Var_Inv<Inv,X>
{
  public:

    static void remake( X&, const X& )
    {
    }

    static const X& clone( const X& x )
    {
      return x ;
    }

};

template <class V1, class F> class Reuser0 ;

template <class V1, class F, class R>
class Thunk0 : public Fun0Impl<R>
{
  public:

    mutable F f ;
    Thunk0( const F& ff ) : f(ff)
    {
    }

    void init( const F& ff ) const
    {
      Maybe_Var_Inv<V1,F>::remake( f, ff ) ;
    }

    R operator()() const
    {
      return Maybe_Var_Inv<V1,F>::clone(f)( Reuser0<V1,F>(this) ) ;
    }

};

template <class V1, class F>
class Reuser0
{
  public:

    typedef typename RT<F>::ResultType R ;
    typedef Thunk0<V1,F,R> M ;

    IRef<const M> ref ;

    Reuser0(NIL)
    {
    }

    Reuser0(const M* m) : ref(m)
    {
    }

    Fun0<R> operator()( const F& f )
    {
      if( !ref )   ref = IRef<const M>( new M(f) ) ;
      else         ref->init(f) ;
      return Fun0<R>( 1, ref ) ;
    }

    void iter( const F & f )
    {
      if ( ref ) ref->init(f) ;
    }

};

//////////////////////////////////////////////////////////////////////

template <class V1, class V2, class F, class X> class Reuser1 ;

template <class V1, class V2, class F, class X, class R>
class Thunk1 : public Fun0Impl<R>
{
  public:

    mutable F f ;
    mutable X x ;

    Thunk1( const F& ff, const X& xx ) : f(ff), x(xx)
    {
    }

    void init( const F& ff, const X& xx ) const
    {
      Maybe_Var_Inv<V1,F>::remake( f, ff ) ;
      Maybe_Var_Inv<V2,X>::remake( x, xx ) ;
    }

    R operator()() const
    {
      return Maybe_Var_Inv<V1,F>::clone(f)(
         Maybe_Var_Inv<V2,X>::clone(x),
         Reuser1<V1,V2,F,X>(this) );
    }

};

template <class V1, class V2, class F, class X>
class Reuser1
{
  public:

    typedef typename RT<F,X>::ResultType R ;
    typedef Thunk1<V1,V2,F,X,R> M ;

    IRef<const M> ref ;

    Reuser1(NIL)
    {
    }

    Reuser1(const M* m) : ref(m)
    {
    }

    Fun0<R> operator()( const F& f, const X& x )
    {
      if( !ref )   ref = IRef<const M>( new M(f,x) ) ;
      else         ref->init(f,x) ;
      return Fun0<R>( 1, ref ) ;
    }

    void iter( const F& f, const X& x )
    {
      if( ref )    ref->init(f,x);
    }

};

//////////////////////////////////////////////////////////////////////

template <class V1, class V2, class V3, class F, class X, class Y>
class Reuser2;

template <class V1, class V2, class V3, class F, class X, class Y, class R>
class Thunk2 : public Fun0Impl<R>
{
  public:

    mutable F f ;
    mutable X x ;
    mutable Y y ;

    Thunk2( const F& ff, const X& xx, const Y& yy ) : f(ff), x(xx), y(yy)
    {
    }

    void init( const F& ff, const X& xx, const Y& yy ) const
    {
      Maybe_Var_Inv<V1,F>::remake( f, ff );
      Maybe_Var_Inv<V2,X>::remake( x, xx );
      Maybe_Var_Inv<V3,Y>::remake( y, yy );
    }

    R operator()() const
    {
      return Maybe_Var_Inv<V1,F>::clone(f)(
         Maybe_Var_Inv<V2,X>::clone(x),
         Maybe_Var_Inv<V3,Y>::clone(y),
         Reuser2<V1,V2,V3,F,X,Y>(this) );
    }

};

template <class V1, class V2, class V3, class F, class X, class Y>
class Reuser2
{
  public:

    typedef typename RT<F,X,Y>::ResultType R;
    typedef Thunk2<V1,V2,V3,F,X,Y,R> M;

    IRef<const M> ref ;

    Reuser2(NIL)
    {
    }

    Reuser2(const M* m) : ref(m)
    {
    }

    Fun0<R> operator()( const F& f, const X& x, const Y& y )
    {
      if( !ref )   ref = IRef<const M>( new M(f,x,y) );
      else         ref->init(f,x,y);
      return Fun0<R>( 1, ref ) ;
    }

    void iter( const F& f, const X& x, const Y& y )
    {
      if ( ref ) ref -> init ( f , x , y ) ;
    }

};

//////////////////////////////////////////////////////////////////////

template <class V1, class V2, class V3, class V4,
          class F, class X, class Y, class Z> class Reuser3 ;

template <class V1, class V2, class V3, class V4,
          class F, class X, class Y, class Z, class R>
class Thunk3 : public Fun0Impl<R>
{
  public:

    mutable F f ;
    mutable X x ;
    mutable Y y ;
    mutable Z z ;

    Thunk3( const F& ff, const X& xx, const Y& yy, const Z& zz )
      : f(ff), x(xx), y(yy), z(zz)
    {
    }

    void init( const F& ff, const X& xx, const Y& yy, const Z& zz ) const
    {
      Maybe_Var_Inv<V1,F>::remake( f, ff );
      Maybe_Var_Inv<V2,X>::remake( x, xx );
      Maybe_Var_Inv<V3,Y>::remake( y, yy );
      Maybe_Var_Inv<V4,Z>::remake( z, zz );
    }

    R operator()() const
    {
      return Maybe_Var_Inv<V1,F>::clone(f)(
         Maybe_Var_Inv<V2,X>::clone(x),
         Maybe_Var_Inv<V3,Y>::clone(y),
         Maybe_Var_Inv<V4,Z>::clone(z),
         Reuser3<V1,V2,V3,V4,F,X,Y,Z>(this) );
    }

};

template <class V1, class V2, class V3, class V4,
          class F, class X, class Y, class Z>
class Reuser3
{
  public:

    typedef typename RT<F,X,Y,Z>::ResultType R ;
    typedef Thunk3<V1,V2,V3,V4,F,X,Y,Z,R> M ;

    IRef<const M> ref ;

    Reuser3(NIL)
    {
    }

    Reuser3(const M* m) : ref(m)
    {
    }

    Fun0<R> operator()( const F& f, const X& x, const Y& y, const Z& z )
    {
      if( !ref )   ref = IRef<const M>( new M(f,x,y,z) ) ;
      else         ref->init(f,x,y,z) ;
      return Fun0<R>( 1, ref ) ;
    }

    void iter( const F& f, const X& x, const Y& y, const Z& z )
    {
      if ( ref ) ref->init(f,x,y,z) ;
    }

};

class Exception : public std::exception
{
  public:

    const char * s ;

    Exception( const char* ss ) : s(ss)
    {
    }

    const char * what() const throw()
    {
      return s;
    }

};

class XCons ;
class XHead ;
class XTail ;
class XNull ;
class XCat  ;

class CacheEmpty    { } ;
class CacheDummy    { } ;
class ListRaw       { } ;
class OddListDummyX { } ;
class OddListDummyY { } ;

template <class T                  > class Cache        ;
template <class T                  > class OddList      ;
template <class T                  > class ListIterator ;
template <class T, class It        > class ListItHelp   ;
template <class U, class F         > class cvt          ;
template <class T, class F, class R> class ListHelp     ;
template <class T, class F, class R> class ConsHelp     ;

template <class T> Cache<T> * xempty_helper() ;

template <class T>
class List
{
  protected:

    IRef<Cache<T> > rep;   // never NIL, unless an empty OddList

    template <class U                  > friend class Cache    ;
    template <class U                  > friend class OddList  ;
    template <class U, class F, class R> friend class ConsHelp ;
    template <class U, class F         > friend class cvt      ;

    List ( const IRef<Cache<T> > & p ) : rep(p) { }
    List ( ListRaw, Cache<T>     * p ) : rep(p) { }

    bool priv_isEmpty() const
    {
      return rep->cache().second.rep == Cache<T>::XNIL() ;
    }

    T priv_head() const
    {
      if ( priv_isEmpty() )
        throw Exception("Tried to take head() of empty List") ;

      return rep->cache().first() ;
    }

    List<T> priv_tail() const
    {
      if( priv_isEmpty() )
         throw Exception("Tried to take tail() of empty List") ;

      return rep->cache().second ;
    }

  public:

    typedef T ElementType ;

    List( NIL ) : rep( Cache<T>::XEMPTY() )
    {
    }

    List() : rep( Cache<T>::XEMPTY() )
    {
    }

    template <class F>  // works on both ()->OddList and ()->List
    List( const F& f )
    : rep( ListHelp<T,F,typename F::ResultType>()(f) )
    {
    }

    // Note:  this constructor is still part of List and thus still lazy;
    // the iterators may not get evaluated until much later.  This is a
    // feature, not a bug.  So if the iterators are going to be invalidated
    // before you finish using the list, then you'd better force evaluation
    // of the entire list before the iterators go away.

    template <class It>
    List( const It& begin, const It& end )
    : rep( new Cache<T>( ListItHelp<T,It>(begin,end) ) )
    {
    }

    List( const OddList<T>& e )
    : rep( (e.second.rep != Cache<T>::XNIL  () ) ?
          new Cache<T>(e) : Cache<T>::XEMPTY() )
    {
    }

    // Long lists create long recursions of destructors that blow the
    // stack.  So we have an iterative destructor.  It is quite tricky to
    // get right.  The danger is that, when "bypassing" a node to be
    // unlinked and destructed, that node's 'next' pointer is, in fact, a
    // List object, whose destructor will be called.  As a result, as you
    // bypass a node, you need to see if its refC is down to 1, and if
    // so, mutate its next pointer so that when its destructor is called,
    // it won't cause a recursive cascade.
    ~List()
    {
      while ( rep != Cache<T>::XNIL() && rep != Cache<T>::XBAD() )
      {
        if ( rep->refC == 1 )                    {
          // This is a rotate(), but this sequence is actually faster
          // than rotate(), so we do it explicitly
          IRef<Cache<T> > tmp( rep )             ;
          rep = rep->val.second.rep              ;
          tmp->val.second.rep = Cache<T>::XNIL() ;
        } else rep = rep->val.second.rep         ;
      }
    }

    operator bool() const
    {
      return !priv_isEmpty() ;
    }

    const OddList<T>& force() const
    {
      return rep->cache() ;
    }

    const List<T>& delay() const
    {
      return *this ;
    }

    // Note: force returns a reference; implicit conversion now returns a copy.
    operator OddList<T>() const
    {
      return force() ;
    }

    // VC++7.1 says line below makes "return l;" (when l is a List and
    // function returns an OddList) illegal, and I think it's right.
    //operator const OddList<T>&() const { return force(); }

    T head() const
    {
      return priv_head() ;
    }

    List<T> tail() const
    {
      return priv_tail() ;
    }

    // The following helps makes List almost an STL "container"
    typedef T               value_type     ;
    typedef ListIterator<T> const_iterator ;
    typedef const_iterator  iterator       ; // List is immutable

    iterator begin () const
    {
      return ListIterator<T> ( *this ) ;
    }

    iterator end   () const
    {
      return ListIterator<T> (       ) ;
    }

};

class Argh
{
  public:

    virtual int f (void)
    {
      return 0;
    }

} ;

typedef int (*PtrToFxn)() ;
typedef int (Argh::*PtrToMember);
typedef int (Argh::*PtrToMemberFxn)();

template <class T>
class OddList
{
  protected:

   // We need to make sure that "fst" is properly aligned to hold a "T"
   // object, so we do the 'standard' hack.
    union
    {
      unsigned char fst[ sizeof(T) ];   // The real variable
      // a bunch of dummies of every conceivable type
      long              z1   ;
      long           *  pz1  ;
      long double       z2   ;
      long double    *  pz2  ;
      void           *  z3   ;
      void           ** pz3  ;
      PtrToFxn          z4   ;
      PtrToFxn       *  pz4  ;
      Argh           *  pz5  ;
      int               z6   ;
      int            *  pz6  ;
      char              z7   ;
      char           *  pz7  ;
      double            z8   ;
      double         *  pz8  ;
      PtrToMember       z9   ;
      PtrToMember    *  pz9  ;
      PtrToMemberFxn    z10  ;
      PtrToMemberFxn *  pz10 ;
    }                        ;

    const T & first(void) const
    {
      return *((const T *)(&fst)) ;
    }

    T & first(void)
    {
      return *((T*)(&fst)) ;
    }

    List<T> second ; // If XNIL, then this OddList is NIL

    template <class U> friend class List  ;
    template <class U> friend class Cache ;

    OddList( OddListDummyX ) : second( Cache<T>::XNIL() )
    {
    }

    OddList( OddListDummyY ) : second( Cache<T>::XBAD() )
    {
    }

    void init ( const T& x )
    {
      new (static_cast<void*>(&fst)) T(x) ;
    }

    bool fst_is_valid() const
    {
      if( second.rep != Cache<T>::XNIL() )
         if( second.rep != Cache<T>::XBAD() )
            return true;
      return false;
    }

    bool priv_isEmpty() const
    {
      return second.rep == Cache<T>::XNIL() ;
    }

    T priv_head() const
    {
      if( priv_isEmpty() )
         throw Exception("Tried to take head() of empty OddList") ;
      return first() ;
    }

    List<T> priv_tail() const
    {
      if( priv_isEmpty() )
         throw Exception("Tried to take tail() of empty OddList") ;
      return second ;
    }

  public:

    typedef T ElementType ;

    OddList() : second( Cache<T>::XNIL() )
    {
    }

    OddList( NIL ) : second( Cache<T>::XNIL() )
    {
    }

    OddList( const T& x, const List<T>& y ) : second(y)
    {
      init(x) ;
    }

    OddList( const T& x, NIL ) : second(Cache<T>::XEMPTY())
    {
      init(x);
    }

    OddList( const OddList<T>& x ) : second(x.second)
    {
      if ( fst_is_valid() ) {
         init( x.first() )  ;
      }
    }

    OddList<T>& operator=( const OddList<T>& x )
    {
      if( this == &x ) return *this ;
      if( fst_is_valid() ) {
         if( x.fst_is_valid() )
            first() = x.first();
         else
            first().~T();
      } else {
         if( x.fst_is_valid() )
            init( x.first() );
      }
      second = x.second ;
      return *this ;
    }

    ~OddList(void)
    {
      if ( fst_is_valid() ) {
         first().~T()       ;
      }
    }

    operator bool() const
    {
      return !priv_isEmpty() ;
    }

    const OddList<T>& force() const
    {
      return *this ;
    }

    List<T> delay() const
    {
      return List<T>(*this) ;
    }

    T head() const
    {
      return priv_head() ;
    }

    List<T> tail() const
    {
      return priv_tail();
    }

};

// This converts ()->List<T> to ()->OddList<T>.
// In other words, here is the 'extra work' done when using the
// unoptimized interface.
template <class U,class F>
class cvt : public CfpType < OddList<U> >
{
  public:

    F f;
    cvt( const F& ff ) : f(ff)
    {
    }

    OddList<U> operator()() const
    {
      List<U> l = f()  ;
      return l.force() ;
    }

};

// I malloc a RefCountType to hold the refCount and init it to 1 to ensure the
// refCount will never get to 0, so the destructor-of-global-object
// order at the end of the program is a non-issue.  In other words, the
// memory allocated here is only reclaimed by the operating system.
template <class T>
Cache<T>* xnil_helper()
{
  void *p = std::malloc( sizeof(RefCount) ) ;
  *((RefCount*)p) = 1 ;
  return static_cast<Cache<T>*>( p ) ;
}

template <class T>
Cache<T>* xempty_helper()
{
   (void) Cache<T>::xnil;   // Make sure xnil exists before moving forward
   return new Cache<T>( CacheEmpty() ) ;
}

template <class T>
class Cache
{
  protected:

    RefCount                  refC ;
    mutable Fun0<OddList<T> > fxn  ;
    mutable OddList<T>        val  ;

    // val.second.rep can be XBAD, XNIL, or a valid ptr
    //  - XBAD: val is invalid (fxn is valid)
    //  - XNIL: this is the empty list
    //  - anything else: val.first() is head, val.second is tail()

    // Caches are not copyable or assignable
    Cache( const Cache<T>& ) ;
    void operator=( Cache<T> ) ;

    // This functoid should never be called; it represents a
    // self-referent Cache, which should be impossible under the current
    // implementation.  Nonetheless, we need a 'dummy' function object to
    // represent invalid 'fxn's (val.second.rep!=XBAD), and this
    // implementation seems to be among the most reasonable.

    struct blackhole_helper : CfpType< OddList<T> >
    {
      OddList<T> operator()() const
      {
        throw Exception ( "You have entered a black hole." ) ;
      }
    } ;

    static IRef<Cache<T> > xnil   ;
    static IRef<Cache<T> > xbad   ;
    static IRef<Cache<T> > xempty ;

    // Don't get rid of these XFOO() functions; they impose no overhead,
    // and provide a useful place to add debugging code for tracking down
    // before-main()-order-of-initialization problems.

    static const IRef<Cache<T> >& XEMPTY()
    {
      static IRef<Cache<T> > xempty( xempty_helper<T>() ) ;
      return xempty ;
    }

    static const IRef<Cache<T> >& XNIL()
    { // this list is nil
      static IRef<Cache<T> > xnil( xnil_helper<T>() ) ;
      return xnil ;
    }

    static const IRef<Cache<T> >& XBAD()
    { // the pair is invalid; use fxn
      static IRef<Cache<T> > xbad( xnil_helper<T>() ) ;
      return xbad ;
    }

    static Fun0<OddList<T> > the_blackhole ;

    static Fun0<OddList<T> > & blackhole()
    {
      static Fun0<OddList<T> > the_blackhole( makeFun0( blackhole_helper() ) ) ;
      return the_blackhole;
    }

    OddList<T>& cache() const
    {
      if ( val.second.rep == XBAD() ) {
         val = fxn();
         fxn = blackhole();
      }
      return val;
    }

    template <class U                  > friend class List     ;
    template <class U                  > friend class OddList  ;
    template <class U, class F, class R> friend class ConsHelp ;
    template <class U, class F         > friend class cvt      ;
    template <class U, class F, class R> friend class ListHelp ;

    template <class U> friend Cache<U> * xempty_helper() ;

    Cache( CacheEmpty ) : refC(0), fxn(blackhole()), val()
    {
    }

    Cache( const OddList<T>& x ) : refC(0), fxn(blackhole()), val(x)
    {
    }

    Cache( const T& x, const List<T>& l ) : refC(0),fxn(blackhole()),val(x,l)
    {
    }

    Cache( CacheDummy ) : refC(0), fxn(blackhole()), val( OddListDummyX() )
    {
    }

    Cache( const Fun0<OddList<T> >& f ) : refC(0), fxn(f), val(OddListDummyY())
    {
    }

    template <class F>
    Cache( const F& f )    // ()->OddList
    : refC(0), fxn(makeFun0(f)), val( OddListDummyY() )
    {
    }

    // This is for ()->List<T> to ()->OddList<T>
    struct CvtFxn { } ;

    template <class F>
    Cache( CvtFxn, const F& f )    // ()->List
    : refC(0), fxn(makeFun0(cvt<T,F>(f))), val( OddListDummyY() )
    {
    }

  public:

    void inc()
    {
      ++refC ;
    }

    void dec()
    {
      if (!--refC) delete this ;
    }

};

template <class T>
Fun0<OddList<T> > Cache<T>::the_blackhole( makeFun0( blackhole_helper() ) ) ;

template <class T> IRef<Cache<T> > Cache<T>::xnil   ( xnil_helper  <T>()  ) ;
template <class T> IRef<Cache<T> > Cache<T>::xbad   ( xnil_helper  <T>()  ) ;
template <class T> IRef<Cache<T> > Cache<T>::xempty ( xempty_helper<T>()  ) ;

// Rest of List's stuff

template <class T, class F> struct ListHelp<T,F,List<T> >
{
  IRef<Cache<T> > operator()( const F& f ) const
  {
    return IRef<Cache<T> >(new Cache<T>(Cache<T>::CvtFxn(),f)) ;
  }
} ;

template <class T, class F> struct ListHelp<T,F,OddList<T> >
{
  IRef<Cache<T> > operator()( const F& f ) const
  {
    return IRef<Cache<T> >(new Cache<T>(f)) ;
  }
} ;

template <class T, class It>
class ListItHelp : public CfpType<OddList<T> >
{
  public:

    It begin, end;

    ListItHelp( const It& b, const It& e ) : begin(b), end(e)
    {
    }

    OddList<T> operator()() const ;

};

template <class T>
class ListIterator : public std::iterator<std::input_iterator_tag,T,ptrdiff_t>
{
  protected:

    List<T> l      ;
    bool    is_nil ;

    void advance()
    {
      l = l.tail()            ;
      if ( !l ) is_nil = true ;
    }

    class Proxy
    { // needed for operator->
      protected:

        const T x;

        friend class ListIterator ;

        Proxy( const T& xx ) : x(xx)
        {
        }

      public:

        const T* operator->() const
        {
          return &x ;
        }

    } ;

  public:

    ListIterator() : l(), is_nil(true)
    {
    }

    explicit ListIterator( const List<T>& ll ) : l(ll), is_nil(!ll)
    {
    }

    const T operator*() const
    {
      return l.head();
    }

    const Proxy operator->() const
    {
      return Proxy(l.head());
    }

    ListIterator<T>& operator++()
    {
      advance()    ;
      return *this ;
    }

    const ListIterator<T> operator++(int)
    {
      ListIterator<T> i ( *this ) ;
      advance           (       ) ;
      return i                    ;
    }

    bool operator==( const ListIterator<T>& i ) const
    {
      return is_nil && i.is_nil ;
    }

    bool operator!=( const ListIterator<T>& i ) const
    {
      return ! this->operator==(i) ;
    }

};

class XHead
{
  public:

    template <class LT>
    struct Sig : public FunType<LT,typename LT::ElementType>
    {
    } ;

    template <class T>
    T operator()( const List<T>& l ) const
    {
      return l.head() ;
    }

    template <class T>
    T operator()( const OddList<T>& l ) const
    {
      return l.head() ;
    }

};

typedef Full1<XHead> Head;

Q_FLP_EXPORT extern Head head ;

class XTail
{
  public:

    template <class LT>
    struct Sig : public FunType<LT,List<typename LT::ElementType> >
    {
    } ;

    template <class T>
    List<T> operator()( const List<T>& l ) const
    {
      return l.tail();
    }

    template <class T>
    List<T> operator()( const OddList<T>& l ) const
    {
      return l.tail();
    }

};

typedef Full1<XTail> Tail ;

Q_FLP_EXPORT extern Tail tail ;

class XNull
{
  public:

    template <class LT>
    struct Sig : public FunType<LT,bool>
    {
    };

    template <class T>
    bool operator()( const List<T>& l ) const
    {
      return !l ;
    }

    template <class T>
    bool operator()( const OddList<T>& l ) const
    {
      return !l ;
    }

};

typedef Full1<XNull> Null ;

Q_FLP_EXPORT extern Null null ;

template <class T, class F> class ConsHelp<T,F,List<T> >
{
  public:

    OddList<T> operator()( const T& x, const F& f ) const
    {
      return OddList<T>(x, List<T>(
        IRef<Cache<T> >(new Cache<T>(Cache<T>::CvtFxn(),f)))) ;
    }

};

template <class T, class F> class ConsHelp<T,F,OddList<T> >
{
  public:

    OddList<T> operator()( const T& x, const F& f ) const
    {
      return OddList<T>(x, List<T>( ListRaw(), new Cache<T>(f) )) ;
    }

};

class XCons
{
  public:

    template <class T, class L>
    struct Sig : public FunType<T,L,OddList<T> >
    {
    } ;

    template <class T>
    OddList<T> operator()( const T& x, const List<T>& l ) const
    {
      return OddList<T>(x,l) ;
    }

    template <class T>
    OddList<T> operator()( const T& x, const OddList<T>& l ) const
    {
      return OddList<T>(x,l) ;
    }

    template <class T>
    OddList<T> operator()( const T& x, const NIL& ) const
    {
//      return OddList<T>(x,NIL) ;
      return OddList<T>(x) ;
    }

    template <class T, class F>
    OddList<T> operator()( const T& x, const F& f ) const
    {
      return ConsHelp<T,F,typename F::ResultType>()(x,f) ;
    }

};

typedef Full2<XCons> Cons ;

Q_FLP_EXPORT extern Cons cons ;

template <class T, class It>
OddList<T> ListItHelp<T,It>::operator()() const
{
  if( begin == end ) return OddList<T>();
  It tmp = begin;
  T x( *begin );
  return cons( x, ListItHelp<T,It>( ++tmp, end ) ) ;
}

class XCat
{
  protected:

    // The Intel compiler doesn't like it when I overload this function,
    // so I just used class template partial specialization in a nested
    // helper class to code around it.
    template <class L, class M>
    struct Helper : public CfpType<L,M,OddList<typename L::ElementType> >
    {
      OddList<typename L::ElementType>
      operator()( const L& l,
                  const M& m,
                  Reuser2<Inv,Var,Inv,Helper,List<typename L::ElementType>,M> r = NIL() ) const
      {
         if ( null(l) ) return m().force() ;
                   else return cons ( head(l), r( *this, tail(l), m ) ) ;
      }
    };

    template <class L, class T>
    struct Helper<L,List<T> > : public CfpType<L,List<T>,OddList<typename L::ElementType> >
    {
      OddList<T>
      operator()( const L& l, const List<T>& m,
             Reuser2<Inv,Var,Inv,Helper,List<typename L::ElementType>,List<T> >
             r = NIL() ) const
      {
        if( null(l) ) return m.force() ;
         else return cons( head(l), r( *this, tail(l), m ) ) ;
      }
    };

    template <class L, class T>
    struct Helper<L,OddList<T> >
    : public CfpType<L,OddList<T>,OddList<typename L::ElementType> >
    {
      OddList<T>
      operator()( const L& l, const OddList<T>& m,
           Reuser2<Inv,Var,Inv,Helper,List<typename L::ElementType>,OddList<T> >
           r = NIL() ) const
      {
        if ( null(l) ) return m ;
        else return cons( head(l), r( *this, tail(l), m ) ) ;
      }
    } ;

    template <class L>
    struct Helper<L,NIL>
    : public CfpType<L,NIL,OddList<typename L::ElementType> >
    {
      OddList<typename L::ElementType>
      operator()( const L& l, const NIL& ) const
      {
        return l ;
      }
    } ;

  public:

    template <class L, class M>
    struct Sig : public FunType<L,M,OddList<typename L::ElementType> >
    {
    } ;

    // Note: first arg must be a list, but second arg can be either a list
    // or a function that returns a list.
    template <class L, class M>
    OddList<typename L::ElementType>
    operator()( const L& l, const M& m ) const
    {
      return Helper<L,M>()(l,m) ;
    }

};

typedef Full2<XCat> Cat;

class XDelay
{
  public:

    template <class L>
    struct Sig : public FunType<L,List<typename L::ElementType> >
    {
    };

    template <class L>
    List<typename L::ElementType> operator()( const L& l ) const
    {
      return l.delay();
    }

};

typedef Full1<XDelay> Delay ;

class XForce
{
  public:

    template <class L>
    struct Sig : public FunType<L,OddList<typename L::ElementType> >
    {
    };

    template <class L>
    OddList<typename L::ElementType> operator()( const L& l ) const
    {
      return l.force() ;
    }

};

typedef Full1<XForce> Force ;

//////////////////////////////////////////////////////////////////////
// op== and op<, overloaded for all combos of List, OddList, and NIL
//////////////////////////////////////////////////////////////////////

template <class T>
bool operator==( const OddList<T>& a, NIL )
{
  return null(a) ;
}

template <class T>
bool operator==( const List<T>& a, NIL )
{
  return null(a) ;
}

template <class T>
bool operator==( NIL, const OddList<T>& a )
{
  return null(a) ;
}

template <class T>
bool operator==( NIL, const List<T>& a )
{
  return null(a) ;
}

template <class T>
bool operator==( const List<T>& a, const List<T>& b )
{
  if ( null(a) && null(b) ) return true  ;
  if ( null(a) || null(b) ) return false ;
  return ( head(a) == head(b) )         &&
         ( tail(a) == tail(b) )          ;
}

template <class T>
bool operator==( const OddList<T>& a, const OddList<T>& b )
{
  if ( null(a) && null(b) ) return true  ;
  if ( null(a) || null(b) ) return false ;
   return ( head(a) == head(b) )        &&
          ( tail(a) == tail(b) )         ;
}

template <class T>
bool operator==( const List<T>& a, const OddList<T>& b )
{
  if ( null(a) && null(b) ) return true  ;
  if ( null(a) || null(b) ) return false ;
  return ( head(a) == head(b) )         &&
         ( tail(a) == tail(b) )          ;
}

template <class T>
bool operator==( const OddList<T>& a, const List<T>& b )
{
  if ( null(a) && null(b) ) return true  ;
  if ( null(a) || null(b) ) return false ;
  return ( head(a) == head(b) )         &&
         ( tail(a) == tail(b) )          ;
}

template <class T>
bool operator<( const List<T>& a, const List<T>& b )
{
  if ( null(a) && !null(b) ) return true  ;
  if ( null(b)             ) return false ;
  if ( head(b) <   head(a) ) return false ;
  if ( head(a) <   head(b) ) return true  ;
  return ( tail(a) < tail(b) )            ;
}

template <class T>
bool operator<( const OddList<T>& a, const List<T>& b )
{
  if ( null(a) && !null(b) ) return true  ;
  if ( null(b)             ) return false ;
  if ( head(b) <   head(a) ) return false ;
  if ( head(a) <   head(b) ) return true  ;
  return ( tail(a) < tail(b) )            ;
}

template <class T>
bool operator<( const List<T>& a, const OddList<T>& b )
{
  if ( null(a) && !null(b) ) return true  ;
  if ( null(b)             ) return false ;
  if ( head(b) <   head(a) ) return false ;
  if ( head(a) <   head(b) ) return true  ;
  return ( tail(a) < tail(b) )            ;
}

template <class T>
bool operator<( const OddList<T>& a, const OddList<T>& b )
{
  if ( null(a) && !null(b) ) return true  ;
  if ( null(b)             ) return false ;
  if ( head(b) <   head(a) ) return false ;
  if ( head(a) <   head(b) ) return true  ;
  return ( tail(a) < tail(b) )            ;
}

template <class T>
bool operator<( const OddList<T>&, NIL )
{
  return false ;
}

template <class T>
bool operator<( const List<T>&, NIL )
{
  return false ;
}

template <class T>
bool operator<( NIL, const OddList<T>& b )
{
  return !null(b) ;
}

template <class T>
bool operator<( NIL, const List<T>& b )
{
  return !null(b) ;
}

//////////////////////////////////////////////////////////////////////
// Handy functions for making list literals
//////////////////////////////////////////////////////////////////////
// Yes, these aren't functoids, they're just template functions.  I'm
// lazy and created these mostly to make it easily to make little lists
// in the sample code snippets that appear in papers.

template <class T>
List<T> list_with( const T& a )
{
  List<T> l        ;
  l = cons( a, l ) ;
  return l         ;
}

template <class T>
List<T> list_with( const T& a, const T& b )
{
  List<T> l        ;
  l = cons( b, l ) ;
  l = cons( a, l ) ;
  return l         ;
}

template <class T>
List<T> list_with( const T& a, const T& b, const T& c )
{
  List<T> l        ;
  l = cons( c, l ) ;
  l = cons( b, l ) ;
  l = cons( a, l ) ;
  return l         ;
}

template <class T>
List<T> list_with( const T& a, const T& b, const T& c, const T& d )
{
  List<T> l        ;
  l = cons( d, l ) ;
  l = cons( c, l ) ;
  l = cons( b, l ) ;
  l = cons( a, l ) ;
  return l         ;
}

template <class T>
List<T>
list_with( const T& a, const T& b, const T& c, const T& d, const T& e )
{
  List<T> l        ;
  l = cons( e, l ) ;
  l = cons( d, l ) ;
  l = cons( c, l ) ;
  l = cons( b, l ) ;
  l = cons( a, l ) ;
  return l         ;
}

class XId
{
  public:

    template <class T> struct Sig : public FunType<T,T>
    {
    } ;

    template <class T>
    T operator()( const T& x ) const
    {
      return x;
    }

};

typedef Full1<XId> Id;

Q_FLP_EXPORT extern Id id ;

template <class F, class G>
class XCompose0Helper : public CfpType<
typename F::template Sig<typename RT<G>::ResultType>::ResultType>
{
  protected:

    F f;
    G g;

  public:

    XCompose0Helper( const F& a, const G& b ) : f(a), g(b)
    {
    }

    typename F::template Sig<typename RT<G>::ResultType>::ResultType
    operator()() const
    {
      return f( g() );
    }

};

template <class F, class G>
class XCompose1Helper
{
  protected:

    F f ;
    G g ;

  public:

    XCompose1Helper( const F& a, const G& b ) : f(a), g(b)
    {
    }

    template <class X> struct Sig : public FunType<
       typename RT<G,X>::Arg1Type,
       typename RT<F,typename RT<G,X>::ResultType>::ResultType>
    {
    };

    template <class X>
    typename Sig<X>::ResultType operator()( const X& x ) const
    {
      return f( g(x) );
    }

};

template <class F, class G>
class XCompose2Helper
{
  protected:

    F f ;
    G g ;

  public:

    XCompose2Helper( const F& a, const G& b ) : f(a), g(b) {}
    template <class X, class Y> struct Sig : public FunType<
      typename RT<G,X,Y>::Arg1Type,
      typename RT<G,X,Y>::Arg2Type,
      typename RT<F,typename RT<G,X,Y>::ResultType>::ResultType>
    {
    };

    template <class X, class Y>
    typename Sig<X,Y>::ResultType operator()( const X& x, const Y& y ) const
    {
      return f( g(x,y) ) ;
    }

} ;

template <class F, class G>
class XCompose3Helper
{
  protected:

    F f ;
    G g ;

  public:

    XCompose3Helper( const F& a, const G& b ) : f(a), g(b)
    {
    }

    template <class X, class Y, class Z> struct Sig : public FunType<
      typename RT<G,X,Y,Z>::Arg1Type,
      typename RT<G,X,Y,Z>::Arg2Type,
      typename RT<G,X,Y,Z>::Arg3Type,
      typename RT<F,typename RT<G,X,Y,Z>::ResultType>::ResultType>
    {
    };

    template <class X, class Y, class Z>
    typename Sig<X,Y,Z>::ResultType
    operator()( const X& x, const Y& y, const Z& z ) const
    {
      return f( g(x,y,z) ) ;
    }

};

// Compose is Haskell's operator (.)
// compose(f,g)(x,y,z) = f( g(x,y,z) )
class XCompose
{
  protected:

    template <int i, class F, class G> struct Helper ;

    template <class F, class G>
    struct Helper<0,F,G>
    {
      typedef Full0<XCompose0Helper<F,G> > Result;
      static Result go( const F& f, const G& g )
      {
        return makeFull0(XCompose0Helper<F,G>(f,g)) ;
      }
    };

    template <class F, class G>
    struct Helper<1,F,G>
    {
      typedef Full1<XCompose1Helper<F,G> > Result;
      static Result go( const F& f, const G& g )
      {
        return makeFull1(XCompose1Helper<F,G>(f,g));
      }
    };

    template <class F, class G>
    struct Helper<2,F,G>
    {
      typedef Full2<XCompose2Helper<F,G> > Result;
      static Result go( const F& f, const G& g )
      {
        return makeFull2(XCompose2Helper<F,G>(f,g));
      }
    };

    template <class F, class G>
    struct Helper<3,F,G>
    {
      typedef Full3<XCompose3Helper<F,G> > Result;
      static Result go( const F& f, const G& g )
      {
        return makeFull3(XCompose3Helper<F,G>(f,g));
      }
    };

  public:

    template <class F, class G> struct Sig : public
    FunType<F,G,typename Helper<FunctoidTraits<G>::max_args,F,G>::Result>
    {
    };

    template <class F, class G>
    typename Sig<F,G>::ResultType operator()( const F& f, const G& g ) const
    {
      return Helper<FunctoidTraits<G>::max_args,F,G>::go( f, g ) ;
    }

};

typedef Full2<XCompose> Compose;


//////////////////////////////////////////////////////////////////////
// Now we can create "of", so that
//    f ^of^ g
// means
//    compose( funify(f), funify(g) )
//////////////////////////////////////////////////////////////////////

class XOf
{
  public:

    template <class F, class G> struct Sig : public FunType<F,G,
      typename RT<Compose,typename RT<Funify,F>::ResultType,
      typename RT<Funify,G>::ResultType>::ResultType>
    {
    };

    template <class F, class G>
    typename Sig<F,G>::ResultType
    operator()( const F& f, const G& g ) const
    {
      return compose( funify(f), funify(g) ) ;
    }

};

typedef Full2<XOf> Of ;

template <class F, class G, class H>
class XXCompose2Helper
{
  protected:

    F f ;
    G g ;
    H h ;

  public:

    XXCompose2Helper( const F& a, const G& b, const H& c) : f(a), g(b), h(c)
    {
    }

    template <class T>
    struct Sig : public FunType<
    typename G::template Sig<T>::Arg1Type,
    typename F::template Sig<typename G::template Sig<T>::ResultType,
                             typename H::template Sig<T>::ResultType>::ResultType
    >
    {
    };

    template <class T>
    typename F::template Sig<typename G::template Sig<T>::ResultType,
                             typename H::template Sig<T>::ResultType>::ResultType
    operator()( const T& x ) const
    {
      return f( g(x), h(x) ) ;
    }

};

// compose2(f,g,h)(x) == f( g(x), h(x) )
// Compose2 composes a two argument function with two one-argument
// functions (taking the same type). This is quite useful for the
// common case of binary operators.  Use lambda for more-complicated stuff.
class XCompose2
{
  public:

    template <class F, class G, class H>
    struct Sig : public FunType<F,G,H,Full1<XXCompose2Helper<F,G,H> > >
    {
    };

    template <class F, class G, class H>
    Full1<XXCompose2Helper<F,G,H> >
    operator()(const F& f, const G& g, const H& h) const
    {
      return makeFull1( XXCompose2Helper<F,G,H>( f, g, h ) ) ;
    }

};

typedef Full3<XCompose2> Compose2;

class XUntil
{
  public:

    template <class Pred, class Unary, class T>
    struct Sig : public FunType<Pred,Unary,T,T>
    {
    };

    template <class Pred, class Unary, class T>
    T operator()( const Pred& p, const Unary& op, T start ) const
    {
      while( !p(start) ) {
        T tmp( start );
        start.~T();
        new (&start) T( op(tmp) ) ;
      }
      return start;
    }
};

typedef Full3<XUntil> Until;

class XLast
{
  public:

    template <class L>
    struct Sig : public FunType<L,typename L::ElementType>
    {
    } ;

    template <class L>
    typename L::ElementType operator()( const L& ll ) const
    {
      List<typename L::ElementType> l = ll;
      while( !null( tail(l) ) )
         l = tail(l);
      return head(l);
    }

};

typedef Full1<XLast> Last;

class XInit
{
  public:

    template <class L>
    struct Sig : public FunType<L,OddList<typename L::ElementType> >
    {
    };

    template <class L>
    OddList<typename L::ElementType>
    operator()( const L& l,
               Reuser1<Inv,Var,XInit,List<typename L::ElementType> >
               r = NIL() ) const
    {
      if ( null( tail( l ) ) ) return NIL() ;
      else return cons( head(l), r( XInit(), tail(l) ) ) ;
    }

};

typedef Full1<XInit> Init;

class XLength
{
  public:

    template <class L>
    struct Sig : public FunType<L,size_t>
    {
    };

    template <class L>
    size_t operator()( const L& ll ) const
    {
      List<typename L::ElementType> l = ll ;
      size_t x = 0;
      while ( !null(l) ) {
        l = tail(l);
        ++x;
      }
      return x;
    }

};

typedef Full1<XLength> FLength;

// At is Haskell's operator (!!)
class XAt
{
  public:

    template <class L, class N>
    struct Sig : public FunType<L,N,typename L::ElementType>
    {
    };

    template <class L>
    typename L::ElementType operator()( L l, size_t n ) const
    {
      while( n!=0 ) {
        l = tail(l);
        --n;
      }
      return head(l);
    }

};

typedef Full2<XAt> At;

template <class P, class T>
class XFilterHelp : public Fun0Impl< OddList<T> >
{
  public:

    P p;
    mutable List<T> l;
    XFilterHelp( const P& pp, const List<T>& ll ) : p(pp), l(ll)
    {
    }

    OddList<T> operator()() const
    {
      while(1) {
         if( null(l) )
            return NIL();
         else if( p( head(l) ) ) {
            T x = head(l);
            l = tail(l);
            return cons( x, Fun0< OddList<T> >(1,this) );
         }
         else
            l = tail(l);
      }
    }

};

class XFilter
{
  public:

    template <class P, class L>
    struct Sig : public FunType<P,L,List<typename L::ElementType> >
    {
    };

    template <class P, class L>
    List<typename L::ElementType>
    operator()( const P& p, L l ) const
    {
      return Fun0< OddList<typename L::ElementType> >(1,
               new XFilterHelp<P,typename L::ElementType>(p,l) );
    }

};

typedef Full2<XFilter> FFilter;

class XConcat
{
  public:

    template <class LLT>
    struct Sig : public FunType<LLT,
      OddList<typename LLT::ElementType::ElementType> >
    {
    };

    template <class L>
    OddList<typename L::ElementType::ElementType>
    operator()( const L& l,
               Reuser1<Inv,Var,XConcat,List<typename L::ElementType> >
               r = NIL() ) const
    {
      if ( null(l) ) return NIL() ;
      else return cat( head(l), r(XConcat(),tail(l)) ) ;
    }

};

typedef Full1<XConcat> Concat;

// Note: this isn't lazy (even if 'op' is 'cons').
class XFoldr
{
  public:

    template <class Op, class E, class L>
    struct Sig : public FunType<Op,E,L,E>
    {
    };

    template <class Op, class E, class L>
    E operator()( const Op& op, const E& e, const L& l ) const
    {
      if ( null(l) ) return e ;
      else return op( head(l), XFoldr()( op, e, tail(l) ) ) ;
    }

};

typedef Full3<XFoldr> FFoldr;

class XFoldr1
{
  public:

    template <class Op, class L>
    struct Sig : public FunType<Op,L,typename L::ElementType>
    {
    };

    template <class Op, class L>
    typename L::ElementType operator()( const Op& op, const L& l ) const
    {
      return foldr( op, head(l), tail(l) ) ;
    }

};

typedef Full2<XFoldr1> Foldr1;

class XFoldl
{
  public:

    template <class Op, class E, class L>
    struct Sig : public FunType<Op,E,L,E>
    {
    };

    template <class Op, class E, class L>
    E operator()( const Op& op, E e, const L& ll ) const
    {
      List<typename L::ElementType> l = ll;
      while( !null(l) ) {
         E tmp( e );
         e.~E();
         new (&e) E( op(tmp,head(l)) );
         l = tail(l);
      }
      return e;
    }

};

typedef Full3<XFoldl> Foldl;

Q_FLP_EXPORT extern Foldl foldl ;

class XFoldl1
{
  public:

    template <class Op, class L>
    struct Sig : public FunType<Op,L,typename L::ElementType>
    {
    };

    template <class Op, class L>
    typename L::ElementType operator()( const Op& op, const L& l ) const
    {
      return foldl( op, head(l), tail(l) ) ;
    }

};

typedef Full2<XFoldl1> Foldl1;

Q_FLP_EXPORT extern Foldl1 foldl1 ;

class XScanr
{
  public:

    template <class Op, class E, class L>
    struct Sig : public FunType<Op,E,L,OddList<E> >
    {
    } ;

    template <class Op, class E, class L>
    OddList<E> operator()( const Op& op, const E& e, const L& l ) const
    {
      if ( null(l) ) return cons( e, NIL() );
      else {
        OddList<E> temp = XScanr()( op, e, tail(l) ) ;
        return cons( op( head(l), head(temp) ), temp ) ;
      }
    }

};

typedef Full3<XScanr> Scanr;

class XScanr1
{
  public:

    template <class Op, class L>
    struct Sig : public FunType<Op,L,OddList<typename L::ElementType> >
    {
    };

    template <class Op, class L>
    OddList<typename L::ElementType>
    operator()( const Op& op, const L& l ) const
    {
      if ( null( tail(l) ) ) return l.force() ;
      else {
        OddList<typename L::ElementType> temp = XScanr1()( op, tail(l) );
        return cons( op( head(l), head(temp) ), temp ) ;
      }
    }

};

typedef Full2<XScanr1> Scanr1 ;

class XScanl
{
  public:

    template <class Op, class E, class L>
    struct Sig : public FunType<Op,E,L,OddList<E> >
    {
    };

    template <class Op, class E, class L>
    OddList<E> operator()( const Op& op, const E& e, const L& l,
         Reuser3<Inv,Inv,Var,Var,XScanl,Op,E,List<typename L::ElementType> >
         r = NIL() ) const
    {
      if ( null(l) ) return cons( e, NIL() ) ;
      else return cons( e, r( XScanl(), op, op(e,head(l)), tail(l) ) ) ;
    }

};

typedef Full3<XScanl> Scanl;

class XScanl1
{
  public:

    template <class Op, class L>
    struct Sig : public FunType<Op,L,OddList<typename L::ElementType> >
    {
    };

    template <class Op, class L>
    OddList<typename L::ElementType>
    operator()( const Op& op, const L& l ) const
    {
      return scanl( op, head(l), tail(l) ) ;
    }

};

typedef Full2<XScanl1> Scanl1;

class XIterate
{
  public:

    template <class F, class T>
    struct Sig : public FunType<F,T,OddList<T> >
    {
    };

    template <class F, class T>
    OddList<T> operator()( const F& f, const T& x,
                          Reuser2<Inv,Inv,Var,XIterate,F,T> r = NIL() ) const
    {
      return cons( x, r( XIterate(), f, f(x) ) ) ;
    }

};

typedef Full2<XIterate> Iterate;

class XRepeat
{
  public:

    template <class T>
    struct Sig : public FunType<T,OddList<T> >
    {
    };

    template <class T>
    OddList<T> operator()( const T& x,
                          Reuser1<Inv,Inv,XRepeat,T> r = NIL() ) const
    {
      return cons( x, r( XRepeat(), x ) ) ;
    }

};

typedef Full1<XRepeat> Repeat;

class XMap
{
  public:

    template <class F, class L>
    struct Sig : public FunType<F,L,
      OddList<typename RT<F,typename L::ElementType>::ResultType> >
    {
    };

    template <class F, class L>
    OddList<typename RT<F,typename L::ElementType>::ResultType>
    operator()( const F& f, const L& l,
               Reuser2<Inv,Inv,Var,XMap,F,List<typename L::ElementType> >
               r = NIL() ) const
    {
      if ( null(l) ) return NIL() ;
      else return cons( f(head(l)), r( XMap(), f, tail(l) ) ) ;
    }

};

typedef Full2<XMap> FMap;

Q_FLP_EXPORT extern FMap map ;

class XTake
{
  public:

    template <class N,class L>
    struct Sig : public FunType<N,L,OddList<typename L::ElementType> >
    {
    };

    template <class L>
    OddList<typename L::ElementType>
    operator()( size_t n, const L& l,
               Reuser2<Inv,Var,Var,XTake,size_t,List<typename L::ElementType> >
               r = NIL() ) const
    {
      if ( n==0 || null(l) ) return NIL();
      else return cons( head(l), r( XTake(), n-1, tail(l) ) ) ;
    }

};

typedef Full2<XTake> Take;

class XDrop
{
  public:

    template <class Dummy, class L>
    struct Sig : public FunType<size_t,L,List<typename L::ElementType> >
    {
    };

    template <class L>
    List<typename L::ElementType> operator()( size_t n, const L& ll ) const
    {
      List<typename L::ElementType> l = ll;
      while( n!=0 && !null(l) ) {
         --n;
         l = tail(l);
      }
      return l;
    }

};

typedef Full2<XDrop> Drop;

class XTakeWhile
{
  public:

    template <class P, class L>
    struct Sig : public FunType<P,L,OddList<typename L::ElementType> >
    {
    };

    template <class P, class L>
    OddList<typename L::ElementType>
    operator()( const P& p, const L& l,
               Reuser2<Inv,Inv,Var,XTakeWhile,P,List<typename L::ElementType> >
               r = NIL() ) const
    {
      if ( null(l) || !p( head(l) ) ) return NIL() ;
      else return cons( head(l), r( XTakeWhile(), p, tail(l) ) ) ;
    }

};

typedef Full2<XTakeWhile> TakeWhile;

class XDropWhile
{
  public:

    template <class P, class L>
    struct Sig : public FunType<P,L,List<typename L::ElementType> >
    {
    };

    template <class P, class L>
    List<typename L::ElementType> operator()( const P& p, const L& ll ) const
    {
      List<typename L::ElementType> l = ll;
      while( !null(l) && p( head(l) ) )
         l = tail(l);
      return l;
    }

};

typedef Full2<XDropWhile> DropWhile;

Q_FLP_EXPORT extern DropWhile dropWhile ;

class XReplicate
{
  public:

    template <class N, class T>
    struct Sig : public FunType<N,T,OddList<T> >
    {
    };

    template <class T>
    OddList<T> operator()( size_t n, const T& x ) const
    {
      return take( n, repeat(x) );
    }

};

typedef Full2<XReplicate> Replicate;

class XCycle
{
  public:

    template <class L>
    struct Sig : public FunType<L,OddList<typename L::ElementType> >
    {
    };

    template <class L>
    OddList<typename L::ElementType>
    operator()( const L& l, Reuser1<Inv,Inv,XCycle,L> r = NIL() ) const
    {
      return cat( l, r( XCycle(), l ) ) ;
    }

};

typedef Full1<XCycle> Cycle;

class XSplitAt
{
  public:

    template <class N, class L>
    struct Sig : public FunType<N,L,std::pair<List<typename
      L::ElementType>,List<typename L::ElementType> > >
    {
    };

    template <class T>
    std::pair<List<T>,List<T> > operator()( size_t n, const List<T>& l ) const
    {
      if ( n==0 || null(l) )
         return std::make_pair( List<T>(), l );
      else {
         std::pair<List<T>,List<T> > temp = XSplitAt()( n-1, tail(l) );
         List<T> tl = cons( head(l), temp.first );
         return std::make_pair( tl, temp.second );
      }
    }

};

typedef Full2<XSplitAt> SplitAt;

class XSpan
{
  public:

    template <class P, class L>
    struct Sig : public FunType<P,L,std::pair<List<typename
      L::ElementType>,List<typename L::ElementType> > >
    {
    };

    template <class P, class T>
    std::pair<List<T>,List<T> >
    operator()( const P& p, const List<T>& l ) const
    {
      if ( null(l) || !p(head(l)) )
         return std::make_pair( List<T>(), l );
      else {
         std::pair<List<T>,List<T> > temp = XSpan()( p, tail(l) );
         List<T> tl = cons(head(l),temp.first);
         return std::make_pair( tl, temp.second );
      }
    }

};

typedef Full2<XSpan> Span;

class XBreak
{
  public:

    template <class P, class L>
    struct Sig : public FunType<P,L,std::pair<List<typename
      L::ElementType>,List<typename L::ElementType> > >
    {
    };

    template <class P, class T>
    std::pair<List<T>,List<T> >
    operator()( const P& p, const List<T>& l ) const
    {
      return span( Compose()( LogicalNot(), p ), l );
    }

};

typedef Full2<XBreak> Break;

template <class Binary>
class XFlipHelper
{
  protected:

    Binary op ;

  public:

    XFlipHelper( const Binary& b ) : op(b)
    {
    }

    template <class Y, class X>
    struct Sig : public FunType<Y,X,
       typename Binary::template Sig<X,Y>::ResultType >
    {
    };

    template <class Y, class X>
    typename Binary::template Sig<X,Y>::ResultType
    operator()( const Y& y, const X& x ) const
    {
      return op( x, y );
    }

};

class XFlip
{
  public:

    template <class Binary>
    struct Sig : public FunType<Binary,Full2<XFlipHelper<Binary> > >
    {
    };

    template <class Binary>
    Full2<XFlipHelper<Binary> > operator()( const Binary& op ) const
    {
      return makeFull2( XFlipHelper<Binary>( op ) ) ;
    }

};

typedef Full1<XFlip> Flip;

Q_FLP_EXPORT extern Flip flip ;

class XReverse
{
  public:

    template <class L>
    struct Sig : public FunType<L,List<typename L::ElementType> >
    {
    };

    template <class T>
    List<T> operator()( const List<T>& l ) const
    {
      return curry3( foldl, flip(cons), List<T>(), l );
    }

};

typedef Full1<XReverse> Reverse;

Q_FLP_EXPORT extern Reverse reverse ;

//////////////////////////////////////////////////////////////////////
// Not HSP but close
//////////////////////////////////////////////////////////////////////

// These next two are defined as _lazy_ versions of these operators on lists

class XAnd : public CfpType<List<bool>,bool>
{
  public:

    bool operator()( const List<bool>& l ) const
    {
      return null(dropWhile( equal(true), l )) ;
    }

} ;

typedef Full1<XAnd> And ;

class XOr : public CfpType<List<bool>,bool>
{
  public:

    bool operator()( const List<bool>& l ) const
    {
      return !null(dropWhile( equal(false), l ));
    }

};

typedef Full1<XOr> Or ;

//////////////////////////////////////////////////////////////////////
// Back to HSP
//////////////////////////////////////////////////////////////////////

class XAll
{
  public:

    template <class P, class L>
    struct Sig : public FunType<P,L,bool>
    {
    };

    template <class P, class L>
    bool operator()( const P& p, const L& l ) const
    {
      return and_( map( p, l ) ) ;
    }

};

typedef Full2<XAll> All ;

Q_FLP_EXPORT extern All all ;

class XAny
{
  public:

    template <class P, class L>
    struct Sig : public FunType<P,L,bool>
    {
    };

    template <class P, class L>
    bool operator()( const P& p, const L& l ) const
    {
      return or_( map( p, l ) );
    }

};

typedef Full2<XAny> Any ;

Q_FLP_EXPORT extern Any any ;

class XElem
{
  public:

    template <class T, class L>
    struct Sig : public FunType<T,L,bool>
    {
    };

    template <class T, class L>
    bool operator()( const T& x, const L& l ) const
    {
      return any( equal(x), l ) ;
    }

};

typedef Full2<XElem> Elem ;

Q_FLP_EXPORT extern Elem elem ;

class XNotElem
{
  public:

    template <class T, class L>
    struct Sig : public FunType<T,L,bool>
    {
    };

    template <class T, class L>
    bool operator()( const T& x, const L& l ) const
    {
      return all( notEqual(x), l ) ;
    }

};

typedef Full2<XNotElem> NotElem;

class XSum
{
  public:

    template <class L>
    struct Sig : public FunType<L,typename L::ElementType>
    {
    };

    template <class L>
    typename L::ElementType operator()( const L& l ) const
    {
      return foldl( plus, 0, l );
    }

};

typedef Full1<XSum> Sum ;

class XProduct
{
  public:

    template <class L>
    struct Sig : public FunType<L,typename L::ElementType>
    {
    };

    template <class L>
    typename L::ElementType operator()( const L& l ) const
    {
      return foldl( multiplies, 1, l ) ;
    }

};

typedef Full1<XProduct> Product ;

class XMinimum
{
  public:

    template <class L>
    struct Sig : public FunType<L,typename L::ElementType>
    {
    };

    template <class L>
    typename L::ElementType operator()( const L& l ) const
    {
      return foldl1( min, l ) ;
    }

};

typedef Full1<XMinimum> Minimum;

class XMaximum
{
  public:

    template <class L>
    struct Sig : public FunType<L,typename L::ElementType>
    {
    };

    template <class L>
    typename L::ElementType operator()( const L& l ) const
    {
      return foldl1( max, l ) ;
    }

};

typedef Full1<XMaximum> Maximum;

class XZipWith
{
  public:

    template <class Z, class LA, class LB>
    struct Sig : public FunType<Z,LA,LB,
    OddList<typename RT<Z,typename LA::ElementType,
                         typename LB::ElementType>::ResultType> >
    {
    };

    template <class Z, class LA, class LB>
    OddList<typename RT<Z,typename LA::ElementType,
                         typename LB::ElementType>::ResultType>
    operator()( const Z& z, const LA& a, const LB& b,
                Reuser3<Inv,Inv,Var,Var,XZipWith,Z,
                List<typename LA::ElementType>,
                List<typename LB::ElementType> > r = NIL() ) const
    {
      if ( null(a) || null(b) ) return NIL() ;
      else return cons( z(head(a),head(b)),
                        r( XZipWith(), z, tail(a), tail(b) ) ) ;
    }

};

typedef Full3<XZipWith> ZipWith ;

class XZip
{
  public:

    template <class LA, class LB>
    struct Sig
    : public FunType<LA,LB,OddList<std::pair<typename LA::ElementType,
                                             typename LB::ElementType> > >
    {
    };

    template <class LA, class LB>
    OddList<std::pair<typename LA::ElementType, typename LB::ElementType> >
    operator()( const LA& a, const LB& b ) const
    {
      return zipWith( MakePair(), a, b ) ;
    }

};

typedef Full2<XZip> Zip;

class XFst
{
  public:

    template <class P>
    struct Sig : public FunType<P,typename P::first_type>
    {
    };

    template <class A, class B>
    A operator()( const std::pair<A,B>& p ) const
    {
      return p.first ;
    }

};

typedef Full1<XFst> Fst;

Q_FLP_EXPORT extern Fst fst ;

class XSnd
{
  public:

    template <class P>
    struct Sig : public FunType<P,typename P::second_type>
    {
    };

    template <class A, class B>
    B operator()( const std::pair<A,B>& p ) const
    {
      return p.second ;
    }

};

typedef Full1<XSnd> Snd;

Q_FLP_EXPORT extern Snd snd ;

class XUnzip
{
  public:

    template <class LPT>
    struct Sig : public FunType<LPT,std::pair<
      List<typename LPT::ElementType::first_type>,
      List<typename LPT::ElementType::second_type> > >
    {
    };

    template <class LPT>
    std::pair<
      List<typename LPT::ElementType::first_type>,
      List<typename LPT::ElementType::second_type> >
    operator()( const LPT& l ) const
    {
      typedef typename LPT::ElementType::first_type F;
      typedef typename LPT::ElementType::second_type S;
      return std::make_pair( List<F>(curry2(map,fst,l)),
                             List<S>(curry2(map,snd,l))  );
    }

};

typedef Full1<XUnzip> Unzip;

class XGcdPrime
{
  public:

    template <class T, class U> struct Sig;
    template <class T>
    struct Sig<T,T> : public FunType<T,T,T>
    {
    };

    template <class T>
    T operator()( T x, T y ) const
    {
      while( y!=0 ) {
         T tmp( x%y );
         x = y;
         y = tmp;
      }
      return x;
    }

};

class XGcd
{
  public:

    template <class T, class U> struct Sig;
    template <class T>
    struct Sig<T,T> : public FunType<T,T,T>
    {
    };

    template <class T>
    T operator()( const T& x, const T& y ) const
    {
      if ( x==0 && y==0 )
         throw Exception("Gcd error: x and y both 0") ;
      return XGcdPrime()( x<0?-x:x, y<0?-y:y );
    }

};

typedef Full2<XGcd> Gcd;

Q_FLP_EXPORT extern Gcd gcd ;

class XOdd
{
  public:

    template <class T>
    struct Sig : public FunType<T,bool>
    {
    };

    template <class T>
    bool operator()( const T& x ) const
    {
      return x%2 == 1 ;
    }

};

typedef Full1<XOdd> Odd;

Q_FLP_EXPORT extern Odd odd ;

class XEven
{
  public:

    template <class T>
    struct Sig : public FunType<T,bool>
    {
    };

    template <class T>
    bool operator()( const T& x ) const
    {
      return x%2 == 0 ;
    }

};

typedef Full1<XEven> Even;

Q_FLP_EXPORT extern Even even ;

//////////////////////////////////////////////////////////////////////
// Not HSP but close
//////////////////////////////////////////////////////////////////////

// For some unknown reason, g++2.95.2 (for Solaris, at least) generates
// poor code when these next two functoids are templates.  (g++3 does
// fine, regardless.)  As a result, we make them just work with ints,
// unless the user #defines the flag below.

#ifdef FCPP_TEMPLATE_ENUM

template <class T>
struct XEFH : public Fun0Impl< OddList<T> > {
   mutable T x;
   XEFH( const T& xx ) : x(xx) {}
   OddList<T> operator()() const {
      ++x;
      return cons( x-1, Fun0<OddList<T> >(1,this) );
   }
};

struct XEnumFrom {
   template <class T>
   struct Sig : FunType<T,List<T> > {};

   template <class T>
   List<T> operator()( const T& x ) const {
      return Fun0<OddList<T> >(1, new XEFH<T>(x) );
   }
};

#else

class XEFH : public Fun0Impl< OddList<int> >
{
  public:

    mutable int x;

    XEFH( int xx ) : x(xx)
    {
    }

    OddList<int> operator()() const
    {
      ++x;
      return cons( x-1, Fun0<OddList<int> >(1,this) ) ;
    }

};

struct XEnumFrom : CfpType<int,List<int> > {
   List<int> operator()( int x ) const {
      return Fun0<OddList<int> >(1, new XEFH(x) );
   }
};

#endif

typedef Full1<XEnumFrom> EnumFrom;

Q_FLP_EXPORT extern EnumFrom enumFrom ;

#ifdef FCPP_TEMPLATE_ENUM

template <class T>
struct XEFTH : public Fun0Impl<OddList<T> > {
   mutable T x;
   T y;
   XEFTH( const T& xx, const T& yy ) : x(xx), y(yy) {}
   OddList<T> operator()() const {
      if( x > y )
         return NIL;
      ++x;
      return cons( x-1, Fun0<OddList<T> >( 1, this ) );
   }
};

struct XEnumFromTo {
   template <class T, class U> struct Sig;
   template <class T>
   struct Sig<T,T> : FunType<T,T,List<T> > {};

   template <class T>
   List<T> operator()( const T& x, const T& y ) const {
      return Fun0<OddList<T> >( 1, new XEFTH<T>(x,y) );
   }
};

#else

class XEFTH : public Fun0Impl<OddList<int> >
{
  public:

    mutable int x;
    int y;

    XEFTH( const int& xx, const int& yy ) : x(xx), y(yy)
    {
    }

    OddList<int> operator()() const
    {
      if ( x > y ) return OddList<int>() ;
//      if ( x > y ) return NIL ;
      ++x;
      return cons( x-1, Fun0<OddList<int> >( 1, this ) ) ;
    }

};

class XEnumFromTo : CfpType<int,int,List<int> >
{
  public:

    List<int> operator()( const int& x, const int& y ) const
    {
      return Fun0<OddList<int> >( 1, new XEFTH(x,y) ) ;
    }

};

#endif

typedef Full2<XEnumFromTo> EnumFromTo ;

Q_FLP_EXPORT extern EnumFromTo enumFromTo ;

// Not HSP
class XListUntil
{
  public:

    template <class P, class F, class T>
    struct Sig : public FunType<P,F,T,List<T> >
    {
    };

    template <class Pred, class Unary, class T>
    List<T> operator()( const Pred& p, const Unary& f, const T& x ) const
    {
      return takeWhile( Compose()(logicalNot,p), iterate(f,x) ) ;
    }

};

typedef Full3<XListUntil> ListUntil;

Q_FLP_EXPORT extern ListUntil listUntil ;

//////////////////////////////////////////////////////////////////////
// The "Maybe" type, from Haskell
//////////////////////////////////////////////////////////////////////

class AUniqueTypeForNothing { } ;

Q_FLP_EXPORT extern AUniqueTypeForNothing NOTHING;

template <class T>
class Maybe
{
  protected:

    OddList<T> rep ;

  public:

    typedef T ElementType;

    Maybe( AUniqueTypeForNothing )
    {
    }

    // the Nothing constructor
    Maybe()
    {
    }

    // the Just constructor
    Maybe( const T& x ) : rep( cons(x,NIL()) )
    {
    }

    bool is_nothing() const
    {
      return null(rep);
    }

    T value() const
    {
      return head(rep);
    }

};

class XJust
{
  public:

    template <class T> struct Sig : public FunType<T,Maybe<T> >
    {
    };

    template <class T>
    typename Sig<T>::ResultType
    operator()( const T& x ) const
    {
      return Maybe<T>( x );
    }

};

typedef Full1<XJust> Just;

Q_FLP_EXPORT extern Just just ;

// Haskell's "()" type/value
class Empty { } ;

Q_FLP_EXPORT extern Empty empty ;

// Haskell has curry() and uncurry() for pairs; we call these hCurry()
// and hUncurry().

class XHCurry
{
  public:

    template <class F, class X, class Y> struct Sig : public FunType<F,X,Y,
              typename RT<F,std::pair<X,Y> >::ResultType>
    {
    };

    template <class F, class X, class Y>
    typename Sig<F,X,Y>::ResultType
    operator()( const F& f, const X& x, const Y& y ) const
    {
      return f( makePair(x,y) ) ;
    }

} ;

typedef Full3<XHCurry> HCurry ;

class XHUncurry
{
  public:

    template <class F, class P> struct Sig : public FunType<F,P,typename
       RT<F,typename P::first_type,typename P::second_type>::ResultType>
    {
    } ;

    template <class F, class P>
    typename Sig<F,P>::ResultType
    operator()( const F& f, const P& p ) const
    {
      return f( fst(p), snd(p) ) ;
    }

};

typedef Full2<XHUncurry> HUncurry ;

Q_FLP_EXPORT extern HUncurry hUncurry ;

//////////////////////////////////////////////////////////////////////
// Useful effect combinators
//////////////////////////////////////////////////////////////////////
// Here we define some combinators for statement sequencing:
//    before(f,g)(args) = { f(); return g(args); }
//    after(f,g)(args)  = { r = f(args); g(); return r; }
// That is, before() prepends a thunk onto a functoid, and after()
// appends the thunk onto the back of a functoid.  Finally, noOp
// results in a thunk that does nothing, and serves as the left/right
// identity element for before/after thusly:
//    f  =  before( noOp, f )  =  after( f, noOp )
// Note: the effect happens when all of the functoid's expected
// arguments finally arrive (which, thanks to currying, might not be at
// the "next call".  So if g() expects two arguments, note that
//    before( f, g )( x )
// will not call f() now, rather it waits for another argument.


class XNoOp : public CfpType<void>
{
  public:

    void operator()() const
    {
    }

};

typedef Full0<XNoOp> NoOp;

template <class F, class G>
class XBeforer0 : public CfpType<typename RT<G>::ResultType>
{
  protected:

    F f ;
    G g ;

  public:

    XBeforer0( const F& ff, const G& gg ) : f(ff), g(gg)
    {
    }

    typename RT<G>::ResultType
    operator()() const
    {
      f        ( ) ;
      return g ( ) ;
    }

};

template <class F, class G>
class XBeforer1
{
  protected:

    F f ;
    G g ;

  public:

    XBeforer1( const F& ff, const G& gg ) : f(ff), g(gg)
    {
    }

    template <class X> struct Sig
    : public FunType<typename RT<G,X>::Arg1Type,typename RT<G,X>::ResultType>
    {
    };

    template <class X>
    typename Sig<X>::ResultType
    operator()( const X& x ) const
    {
      f        (   ) ;
      return g ( x ) ;
    }

};

template <class F, class G>
class XBeforer2
{
  protected:

    F f ;
    G g ;

  public:

    XBeforer2( const F& ff, const G& gg ) : f(ff), g(gg)
    {
    }

    template <class X, class Y> struct Sig
    : public FunType<typename RT<G,X,Y>::Arg1Type,
                     typename RT<G,X,Y>::Arg2Type,
                     typename RT<G,X,Y>::ResultType>
    {
    };

    template <class X, class Y>
    typename Sig<X,Y>::ResultType
    operator()( const X& x, const Y& y ) const
    {
      f        (       ) ;
      return g ( x , y ) ;
    }

};

template <class F, class G>
class XBeforer3
{
  protected:

    F f ;
    G g ;

  public:

    XBeforer3( const F& ff, const G& gg ) : f(ff), g(gg)
    {
    }

    template <class X, class Y, class Z> struct Sig
    : public FunType<typename RT<G,X,Y,Z>::Arg1Type,
                     typename RT<G,X,Y,Z>::Arg2Type,
                     typename RT<G,X,Y,Z>::Arg3Type,
                     typename RT<G,X,Y,Z>::ResultType>
    {
    } ;

    template <class X, class Y, class Z>
    typename Sig<X,Y,Z>::ResultType
    operator()( const X& x, const Y& y, const Z& z ) const
    {
      f        (           ) ;
      return g ( x , y , z ) ;
    }

};

class XBefore
{
  protected:

    template <int i, class F, class G> struct Helper ;

    template <class F, class G>
    struct Helper<0,F,G>
    {
      typedef Full0<XBeforer0<F,G> > Result;

      static Result go( const F& f, const G& g )
      {
        return makeFull0( XBeforer0<F,G>(f,g) );
      }
    };

    template <class F, class G>
    struct Helper<1,F,G>
    {
      typedef Full1<XBeforer1<F,G> > Result;

      static Result go( const F& f, const G& g )
      {
        return makeFull1( XBeforer1<F,G>(f,g) ) ;
      }
    };

    template <class F, class G>
    struct Helper<2,F,G>
    {
      typedef Full2<XBeforer2<F,G> > Result ;

      static Result go( const F& f, const G& g )
      {
        return makeFull2( XBeforer2<F,G>(f,g) );
      }
    };

    template <class F, class G>
    struct Helper<3,F,G>
    {
      typedef Full3<XBeforer3<F,G> > Result ;

      static Result go( const F& f, const G& g )
      {
        return makeFull3( XBeforer3<F,G>(f,g) );
      }
    };

  public:

    template <class F, class G> struct Sig : public FunType<F,G,
      typename Helper<FunctoidTraits<G>::max_args,F,G>::Result>
    {
    };

    template <class F, class G>
    typename Sig<F,G>::ResultType operator()( const F& f, const G& g ) const
    {
      return Helper<FunctoidTraits<G>::max_args,F,G>::go( f, g ) ;
    }

};

typedef Full2<XBefore> Before;

template <class F, class G>
class XAfterer0 : public CfpType<typename RT<F>::ResultType>
{
  protected:

    F f ;
    G g ;

  public:

    XAfterer0( const F& ff, const G& gg ) : f(ff), g(gg)
    {
    }

    typename RT<F>::ResultType operator()() const
    {
      typename RT<F>::ResultType tmp = f();
      g() ;
      return tmp ;
    }

};

template <class F, class G>
class XAfterer1
{
  protected:

    F f ;
    G g ;

  public:

    XAfterer1( const F& ff, const G& gg ) : f(ff), g(gg)
    {
    }

    template <class X> struct Sig
    : public FunType<typename RT<F,X>::Arg1Type,
                    typename RT<F,X>::ResultType>
    {
    };

    template <class X>
    typename Sig<X>::ResultType
    operator()( const X& x ) const
    {
      typename Sig<X>::ResultType tmp = f(x);
      g();
      return tmp;
    }

};

template <class F, class G>
class XAfterer2
{
  protected:

    F f ;
    G g ;

  public:

    XAfterer2( const F& ff, const G& gg ) : f(ff), g(gg)
    {
    }

    template <class X, class Y> struct Sig
    : public FunType<typename RT<F,X,Y>::Arg1Type,
                     typename RT<F,X,Y>::Arg2Type,
                     typename RT<F,X,Y>::ResultType>
    {
    };

    template <class X, class Y>
    typename Sig<X,Y>::ResultType
    operator()( const X& x, const Y& y ) const
    {
      typename Sig<X,Y>::ResultType tmp = f(x,y);
      g();
      return tmp;
    }

};

template <class F, class G>
class XAfterer3
{
  protected:

    F f ;
    G g ;

  public:

    XAfterer3( const F& ff, const G& gg ) : f(ff), g(gg)
    {
    }

    template <class X, class Y, class Z> struct Sig
    : public FunType<typename RT<F,X,Y,Z>::Arg1Type,
                     typename RT<F,X,Y,Z>::Arg2Type,
                     typename RT<F,X,Y,Z>::Arg3Type,
                     typename RT<F,X,Y,Z>::ResultType>
    {
    };

    template <class X, class Y, class Z>
    typename Sig<X,Y,Z>::ResultType
    operator()( const X& x, const Y& y, const Z& z ) const
    {
      typename Sig<X,Y,Z>::ResultType tmp = f(x,y,z);
      g();
      return tmp;
    }

};

class XAfter
{
  protected:

    template <int i, class F, class G> struct Helper ;

    template <class F, class G>
    struct Helper<0,F,G>
    {
      typedef Full0<XAfterer0<F,G> > Result ;

      static Result go( const F& f, const G& g )
      {
        return makeFull0( XAfterer0<F,G>(f,g) );
      }
    };

    template <class F, class G>
    struct Helper<1,F,G>
    {
      typedef Full1<XAfterer1<F,G> > Result ;

      static Result go( const F& f, const G& g )
      {
        return makeFull1( XAfterer1<F,G>(f,g) ) ;
      }
    };

    template <class F, class G>
    struct Helper<2,F,G>
    {
      typedef Full2<XAfterer2<F,G> > Result ;

      static Result go( const F& f, const G& g )
      {
        return makeFull2( XAfterer2<F,G>(f,g) );
      }
    };

    template <class F, class G>
    struct Helper<3,F,G>
    {
      typedef Full3<XAfterer3<F,G> > Result ;

      static Result go( const F& f, const G& g )
      {
        return makeFull3( XAfterer3<F,G>(f,g) );
      }
    };

  public:

    template <class F, class G> struct Sig : public FunType<F,G,
       typename Helper<FunctoidTraits<F>::max_args,F,G>::Result>
    {
    };

    template <class F, class G>
    typename Sig<F,G>::ResultType operator()( const F& f, const G& g ) const
    {
      return Helper<FunctoidTraits<F>::max_args,F,G>::go( f, g ) ;
    }

};

typedef Full2<XAfter> After;

// emptify(f)(yadda) == f(yadda), but throws away f's result (even if
//    it's void) and returns Empty instead.  This is useful because
//       length( map( emptify(effectFunctoid), someList ) )
//    is an easy way to do something with each element of someList.

template <class F>
class XEmptifier0 : public CfpType<Empty>
{
  protected:

    F f ;

  public:

    XEmptifier0( const F& ff ) : f(ff)
    {
    }

    Empty operator()() const
    {
      f            ( ) ;
      return Empty ( ) ;
    }

};

template <class F>
class XEmptifier1
{
  protected:

    F f ;

  public:

    XEmptifier1( const F& ff ) : f(ff)
    {
    }

    template <class X> struct Sig
    : public FunType<typename RT<F,X>::Arg1Type,Empty>
    {
    };

    template <class X>
    typename Sig<X>::ResultType
    operator()( const X& x ) const
    {
      f            ( x ) ;
      return Empty (   ) ;
    }

};

template <class F>
class XEmptifier2
{
  protected:

    F f ;

  public:

    XEmptifier2( const F& ff ) : f(ff)
    {
    }

    template <class X, class Y> struct Sig
    : public FunType<typename RT<F,X,Y>::Arg1Type,
                     typename RT<F,X,Y>::Arg2Type,
                    Empty>
    {
    } ;

    template <class X, class Y>
    typename Sig<X,Y>::ResultType
    operator()( const X& x, const Y& y ) const
    {
      f            ( x , y ) ;
      return Empty (       ) ;
    }

};

template <class F>
class XEmptifier3
{
  protected:

    F f ;

  public:

    XEmptifier3( const F& ff ) : f(ff)
    {
    }

    template <class X, class Y, class Z> struct Sig
    : public FunType<typename RT<F,X,Y,Z>::Arg1Type,
                     typename RT<F,X,Y,Z>::Arg2Type,
                     typename RT<F,X,Y,Z>::Arg3Type,
                     Empty>
    {
    };

    template <class X, class Y, class Z>
    typename Sig<X,Y,Z>::ResultType
    operator()( const X& x, const Y& y, const Z& z ) const
    {
      f            ( x , y , z ) ;
      return Empty (           ) ;
    }

};

class XEmptify
{
  protected:

    template <int i, class F> struct Helper ;

    template <class F> struct Helper<0,F>
    {
      typedef Full0<XEmptifier0<F> > Result ;

      static Result go( const F& f )
      {
        return makeFull0( XEmptifier0<F>(f) );
      }
    };

    template <class F> struct Helper<1,F>
    {
      typedef Full1<XEmptifier1<F> > Result ;

      static Result go( const F& f )
      {
        return makeFull1( XEmptifier1<F>(f) );
      }
    };

    template <class F> struct Helper<2,F>
    {
      typedef Full2<XEmptifier2<F> > Result;

      static Result go( const F& f )
      {
        return makeFull2( XEmptifier2<F>(f) );
      }
    };

    template <class F> struct Helper<3,F>
    {
      typedef Full3<XEmptifier3<F> > Result;

      static Result go( const F& f )
      {
        return makeFull3( XEmptifier3<F>(f) );
      }
    };

  public:

    template <class F> struct Sig : public FunType<F,
      typename Helper<FunctoidTraits<F>::max_args,F>::Result>
    {
    };

    template <class F>
    typename Sig<F>::ResultType operator()( const F& f ) const
    {
      return Helper<FunctoidTraits<F>::max_args,F>::go( f ) ;
    }

};

typedef Full1<XEmptify> Emptify;

class XThunkFuncToFunc
{
  public:

    // tftf(f)(yadda) = f()(yadda)
    // f is a thunk that returns a functoid; this combinator 'hides' the thunk.
    // can be useful to break what would otherwise be infinite recursion.
    template <class F> class TFTFH0
    : CfpType<typename RT<typename RT<F>::ResultType>::ResultType>
    {
      protected:

        F f ;

      public:

        TFTFH0( const F& ff ) : f(ff)
        {
        }

        template <class X>
        typename RT<typename RT<F>::ResultType>::ResultType
        operator()() const
        {
          return f()() ;
        }

    };

    template <class F> class TFTFH1
    {
      protected:

        F f ;

      public:

        TFTFH1( const F& ff ) : f(ff)
        {
        }

        template <class X> struct Sig : public FunType<
           typename RT<typename RT<F>::ResultType,X>::Arg1Type,
           typename RT<typename RT<F>::ResultType,X>::ResultType   >
        {
        };

        template <class X>
        typename Sig<X>::ResultType
        operator()( const X& x ) const
        {
          return f()( x ) ;
        }

    } ;

    template <class F> class TFTFH2
    {
      protected:

        F f ;

      public:

        TFTFH2( const F& ff ) : f(ff)
        {
        }

        template <class X, class Y> struct Sig : public FunType<
           typename RT<typename RT<F>::ResultType,X,Y>::Arg1Type,
           typename RT<typename RT<F>::ResultType,X,Y>::Arg2Type,
           typename RT<typename RT<F>::ResultType,X,Y>::ResultType>
        {
        };

        template <class X, class Y>
        typename Sig<X,Y>::ResultType
        operator()( const X& x, const Y& y ) const
        {
          return f()( x, y ) ;
        }

    };

    template <class F> class TFTFH3
    {
      protected:

        F f ;

      public:

        TFTFH3( const F& ff ) : f(ff)
        {
        }

        template <class X, class Y, class Z> struct Sig : public FunType<
          typename RT<typename RT<F>::ResultType,X,Y,Z>::Arg1Type,
          typename RT<typename RT<F>::ResultType,X,Y,Z>::Arg2Type,
          typename RT<typename RT<F>::ResultType,X,Y,Z>::Arg3Type,
          typename RT<typename RT<F>::ResultType,X,Y,Z>::ResultType   >
        {
        };

        template <class X, class Y, class Z>
        typename Sig<X,Y,Z>::ResultType
        operator()( const X& x, const Y& y, const Z& z ) const
        {
          return f()( x, y, z );
        }

    } ;

    template <int i, class F> struct Helper ;

    template <class F> struct Helper<0,F>
    {
      typedef Full0<TFTFH0<F> > Result ;

      static Result go( const F& f )
      {
        return makeFull0( TFTFH0<F>(f) );
      }
    } ;

    template <class F> struct Helper<1,F>
    {
      typedef Full1<TFTFH1<F> > Result ;

      static Result go( const F& f )
      {
        return makeFull1( TFTFH1<F>(f) );
      }
    } ;

    template <class F> struct Helper<2,F>
    {
      typedef Full2<TFTFH2<F> > Result ;

      static Result go( const F& f )
      {
        return makeFull2( TFTFH2<F>(f) ) ;
      }
    } ;

    template <class F> struct Helper<3,F>
    {
      typedef Full3<TFTFH3<F> > Result ;

      static Result go( const F& f )
      {
        return makeFull3( TFTFH3<F>(f) );
      }
    } ;

    template <class F> struct Sig : public FunType<F, typename Helper<
      FunctoidTraits<typename RT<F>::ResultType>::max_args,F>::Result>
    {
    } ;

    template <class F>
    typename Sig<F>::ResultType
    operator()( const F& f ) const
    {
      return Helper<FunctoidTraits<typename RT<F>::ResultType>
         ::max_args,F>::go(f) ;
    }

};

typedef Full1<XThunkFuncToFunc> ThunkFuncToFunc;

//////////////////////////////////////////////////////////////////////
// uncurry
//////////////////////////////////////////////////////////////////////
// Sometimes FC++ expressions result in functoids where, for example,
//    f(x)(y)
// is legal but
//    f(x,y)
// is not, owing to the fact that (in the example) f() is a one-argument
// functoid the returns another one-argument functoid, which is
// different from a two-argument functoid.  (In Haskell, the two types
// are identical.)  uncurry() wraps a functoid in a magical cloak which
// splits up its arguments, so that, for example,
//    uncurry(f)(x,y,z) = f(x)(y)(z)
// It rarely arises that you need this, but when you do, you can't live
// without it.
//
// FIX THIS: Note that uncurry() (as well as curryN()) means something
// different in FC++ than what it does in Haskell.

template <class F>
class XUncurryable : public SmartFunctoid3
{
  protected:

    F f ;

  public:

    XUncurryable( const F& ff ) : f(ff)
    {
      FunctoidTraits<F>::template ensure_accepts<1>::args() ;
    }

    template <class X, class Y=Void, class Z=Void, class Dummy=Void>
    struct Sig : public FunType<typename RT<F,X>::Arg1Type,
             typename RT<typename RT<F,X>::ResultType,Y>::Arg1Type,
 typename RT<typename RT<typename RT<F,X>::ResultType,Y>::ResultType,Z>
   ::Arg1Type,
typename RT<typename RT<typename RT<F,X>::ResultType,Y>::ResultType,Z>
   ::ResultType>
    {
    } ;

    template <class X, class Y, class Dummy>
    struct Sig<X,Y,Void,Dummy> : public FunType<typename RT<F,X>::Arg1Type,
             typename RT<typename RT<F,X>::ResultType,Y>::Arg1Type,
             typename RT<typename RT<F,X>::ResultType,Y>::ResultType>
    {
    } ;

    template <class X, class Dummy>
    struct Sig<X,Void,Void,Dummy> : public FunType<typename RT<F,X>::Arg1Type,
            typename RT<F,X>::ResultType>
    {
    };

    template <class X, class Y, class Z>
    typename Sig<X,Y,Z>::ResultType
    operator()( const X& x, const Y& y, const Z& z ) const
    {
      return f(x)(y)(z) ;
    }

    template <class X, class Y>
    typename Sig<X,Y>::ResultType
    operator()( const X& x, const Y& y ) const
    {
      return f(x)(y) ;
    }

    template <class X>
    typename Sig<X>::ResultType
    operator()( const X& x ) const
    {
      return f(x);
    }

    typedef XUncurryable This;
    template <class A> typename BracketCallable<This,A>::Result
    operator[]( const A& a ) const
    {
      return BracketCallable<This,A>::go( *this, a ) ;
    }

};

class XUncurry
{
  public:

    template <class F>
    struct Sig : FunType<F,XUncurryable<F> >
    {
    };

    template <class F>
    XUncurryable<F> operator()( const F& f ) const
    {
      return XUncurryable<F>(f) ;
    }

};

typedef Full1<XUncurry> Uncurry;

// Uncurry0 is truly a different case from uncurry:
//    uncurry0(f)(x,y,z) = f()(x)(y)(z)

template <class F>
class XUncurryable0
{
  protected:

    F f;

  public:

    XUncurryable0( const F& ff ) : f(ff)
    {
      FunctoidTraits<F>::template ensure_accepts<0>::args() ;
    }

    template <class X> struct Sig
    : public FunType<typename RT<typename RT<F>::ResultType,X>::Arg1Type,
            typename RT<typename RT<F>::ResultType,X>::ResultType>
    {
    };

    template <class X>
    typename Sig<X>::ResultType
    operator()( const X& x ) const
    {
      return f()(x);
    }

};

class XUncurry0
{
  public:

   template <class F>
   struct Sig : FunType<F,XUncurryable<XUncurryable0<F> > > {};

   template <class F>
   XUncurryable<XUncurryable0<F> > operator()( const F& f ) const
   { return uncurry( XUncurryable0<F>(f) ); }
};

typedef Full1<XUncurry0> Uncurry0;

//////////////////////////////////////////////////////////////////////
// duplicate() and ignore()
//////////////////////////////////////////////////////////////////////
// duplicate() duplicates the first argument of a functoid, whereas
// ignore() ignores it:
//    duplicate(f)(x)    = f(x)(x)
//    ignore(f)(x)(args) = f(args)

template <class F>
class XDuplicater
{
  protected:

    F f ;

  public:

    XDuplicater( const F& ff ) : f(ff)
    {
    }

    template <class X>
    struct Sig : public FunType<X,typename RT<typename RT<F,X>::ResultType,
                                             X>::ResultType>
    {
    };

    template <class X>
    typename Sig<X>::ResultType
    operator()( const X& x ) const
    {
      return f(x)(x) ;
    }

};

class XDuplicate
{
  public:

   template <class F>
   struct Sig : public FunType<F,Full1<XDuplicater<F> > >
   {
   };

   template <class F>
   Full1<XDuplicater<F> > operator()( const F& f ) const
   {
     return makeFull1( XDuplicater<F>(f) ) ;
   }

};

typedef Full1<XDuplicate> Duplicate ;

template <class F>
class XIgnorer1
{
  protected:

    F f ;

  public:

    XIgnorer1( const F& ff ) : f(ff)
    {
    }

    template <class X>
    struct Sig : public FunType<X,typename RT<F>::ResultType>
    {
    };

    template <class X>
    typename Sig<X>::ResultType operator()( const X& ) const
    {
      return f ( ) ;
    }

};

template <class F>
class XIgnorer2
{
  protected:

    F f ;

  public:

    XIgnorer2( const F& ff ) : f(ff)
    {
    }

    template <class X, class Y>
    struct Sig : public FunType<X,
      typename RT<F,Y>::Arg1Type,typename RT<F,Y>::ResultType>
    {
    };

    template <class X, class Y>
    typename Sig<X,Y>::ResultType
    operator()( const X&, const Y& y ) const
    {
      return f(y) ;
    }

};

template <class F>
class XIgnorer3
{
  protected:

    F f ;

  public:

    XIgnorer3( const F& ff ) : f(ff)
    {
    }

    template <class X, class Y, class Z>
    struct Sig : public FunType<X,
      typename RT<F,Y,Z>::Arg1Type,
      typename RT<F,Y,Z>::Arg2Type,
      typename RT<F,Y,Z>::ResultType>
    {
    };

    template <class X, class Y, class Z>
    typename Sig<X,Y,Z>::ResultType
    operator()( const X&, const Y& y, const Z& z ) const
    {
      return f(y,z) ;
    }

};

class XIgnore
{
  protected:

    template<int n, class F> struct Helper ;

    template<class F> struct Helper<0,F>
    {
      typedef Full1< XIgnorer1<F> > Result ;

      static inline Result go( const F& f )
      {
        return makeFull1( XIgnorer1<F>(f) ) ;
      }
    };

    template<class F> struct Helper<1,F>
    {
      typedef Full2< XIgnorer2<F> > Result ;

      static inline Result go( const F& f )
      {
        return makeFull2( XIgnorer2<F>(f) ) ;
      }
    };

    template<class F> struct Helper<2,F>
    {
      typedef Full3< XIgnorer3<F> > Result ;

      static inline Result go( const F& f )
      {
        return makeFull3( XIgnorer3<F>(f) ) ;
      }
    };

  public:

    template <class F>
    struct Sig : public FunType<F,
      typename Helper<FunctoidTraits<F>::max_args,F>::Result>
    {
    };

    template <class F>
    typename Sig<F>::ResultType operator()( const F& f ) const
    {
      return Helper<FunctoidTraits<F>::max_args,F>::go(f);
    }

};

typedef Full1<XIgnore> Ignore ;

Q_FLP_EXPORT extern Ignore ignore ;

//////////////////////////////////////////////////////////////////////
// ConstructN
//////////////////////////////////////////////////////////////////////
// C++ constructors are not functions, and thus cannot easily be turned
// into functoids.  So we write these helpers.  For example,
//    construct2<Foo>()(x,y) = Foo(x,y)    // Foo is a type name
// Note also that construct1 also serves the role of an explicit
// converter; if Foos (or any type) can be converted into Bars, then we
// could use a construct1 functoid to capture the conversion function:
//    construct1<Bar>()       // functoid that converts arg into a Bar
//    construct1<Bar>()(x) = Bar(x)
// Note also that these are template functions returning full functoids,
// and we have template structs which name the types of the functoids.

template <class T>
class XConstruct0 : public CfpType<T>
{
  public:

    T operator()() const
    {
      return T() ;
    }

};

template <class T> Full0<XConstruct0<T> > construct0()
{
  return makeFull0( XConstruct0<T>() ) ;
}

template <class T>
class Construct0
{
  public:

    typedef Full0<XConstruct0<T> > Type ;

} ;

template <class T>
class XConstruct1
{
  public:

    template <class X> struct Sig : FunType<X,T>
    {
    } ;

    template <class X>
    T operator()( const X& x ) const
    {
      return T(x);
    }

};

template <class T> Full1<XConstruct1<T> > construct1()
{
  return makeFull1( XConstruct1<T>() ) ;
}

template <class T>
class Construct1
{
  public:

    typedef Full1<XConstruct1<T> > Type ;

} ;

template <class T>
class XConstruct2
{
  public:

    template <class X, class Y> struct Sig : FunType<X,Y,T>
    {
    };

    template <class X, class Y>
    T operator()( const X& x, const Y& y ) const
    {
      return T(x,y);
    }

};

template <class T> Full2<XConstruct2<T> > construct2()
{
  return makeFull2( XConstruct2<T>() );
}

template <class T> class Construct2
{
  public:

    typedef Full2<XConstruct2<T> > Type ;

};

template <class T>
class XConstruct3
{
  public:

    template <class X, class Y, class Z> struct Sig : FunType<X,Y,Z,T>
    {
    };

    template <class X, class Y, class Z>
    T operator()( const X& x, const Y& y, const Z& z ) const
    {
      return T(x,y,z);
    }

};

template <class T> Full3<XConstruct3<T> > construct3()
{
  return makeFull3( XConstruct3<T>() );
}

template <class T> class Construct3
{
  public:

    typedef Full3<XConstruct3<T> > Type ;

} ;

//////////////////////////////////////////////////////////////////////
// NewN works like ConstructN but "new"s it and returns the ptr
//////////////////////////////////////////////////////////////////////

template <class T>
class XNew0 : public CfpType<T*>
{
  public:

    T * operator()() const
    {
      return new T() ;
    }

};

template <class T> Full0<XNew0<T> > new0()
{
  return makeFull0( XNew0<T>() );
}

template <class T> class New0
{
  public:

    typedef Full0<XNew0<T> > Type ;

};

template <class T>
class XNew1
{
  public:

    template <class X> struct Sig : FunType<X,T*>
    {
    };

    template <class X>
    T* operator()( const X& x ) const
    {
      return new T(x);
    }

} ;

template <class T> Full1<XNew1<T> > new1()
{
  return makeFull1( XNew1<T>() ) ;
}

template <class T> class New1
{
  public:

    typedef Full1<XNew1<T> > Type ;

};

template <class T>
class XNew2
{
  public:

   template <class X, class Y> struct Sig : FunType<X,Y,T*>
   {
   };

   template <class X, class Y>
   T * operator()( const X& x, const Y& y ) const
   {
     return new T(x,y) ;
   }

};

template <class T> Full2<XNew2<T> > new2()
{
  return makeFull2( XNew2<T>() ) ;
}

template <class T> class New2
{
  public:

    typedef Full2<XNew2<T> > Type ;

};

template <class T>
class XNew3
{
  public:

    template <class X, class Y, class Z> struct Sig : FunType<X,Y,Z,T*>
    {
    };

    template <class X, class Y, class Z>
    T * operator()( const X& x, const Y& y, const Z& z ) const
    {
      return new T(x,y,z);
    }

};

template <class T> Full3<XNew3<T> > new3()
{
  return makeFull3( XNew3<T>() );
}

template <class T> class New3
{
  public:

    typedef Full3<XNew3<T> > Type ;

};

template <class Rep>
class ThisTypeIsNotAnInstanceOfAnInferrableMonad
{
} ;

template <class T>
class MonadError
{
  public:

    inline static void error()
    {
    }

} ;

template <class T>
class MonadError<ThisTypeIsNotAnInstanceOfAnInferrableMonad<T> >
{
};

template <class Rep>
class MonadTraitsSpecializer
{
  public:

    typedef ThisTypeIsNotAnInstanceOfAnInferrableMonad<Rep> Monad ;

};

template <class Rep>
class MonadTraits
{
  public:

    typedef typename MonadTraitsSpecializer<Rep>::Monad Monad ;

    inline static void ensure_is_instance_of_monad()
    {
      MonadError<Monad>::error() ;
    }

};

/*****************************************************************************\
 * If a monad has a type constructor which is not a type synonym, then       *
 * we call it an "inferrable monad".                                         *
 * For any monad M, you can conjure up one of its functoids via, e.g.        *
 *    unitM<M>()     bindM<M>()                                              *
 * whereas for an inferrable monad, you can just refer to e.g.               *
 *    bind                                                                   *
 * which will use the MonadTraitsSpecializer to infer "M" from "M a".        *
 *                                                                           *
 * (Section 4.3.2 in the Haskell Report explains that an instance of a       *
 * type class's type constructor cannot be a type synonym.)                  *
\*****************************************************************************/

template <class Monad>
class XUnitM
{
  public:

    template <class A> struct Sig
    : public FunType<A,typename Monad::Unit::template Sig<A>::ResultType>
    {
    } ;

    template <class A>
    typename Sig<A>::ResultType
    operator()( const A& a ) const
    {
      return Monad::unit(a) ;
    }

} ;

template <class Monad> Full1<XUnitM<Monad> > unitM()
{
  return makeFull1( XUnitM<Monad>() ) ;
}

template <class Monad> class UnitM
{
  public:

    typedef Full1<XUnitM<Monad> > Type ;

} ;

template <class Monad>
class XBindM
{
  public:

    template <class M, class K> struct Sig : public FunType<M,K,
       typename Monad::Bind::template Sig<M,K>::ResultType>
    {
    };

    template <class M, class K>
    typename Sig<M,K>::ResultType
    operator()( const M& m, const K& k ) const
    {
      return Monad::bind(m,k) ;
    }

} ;

template <class Monad> Full2<XBindM<Monad> > bindM()
{
  return makeFull2( XBindM<Monad>() );
}

template <class Monad> class BindM
{
  public:

    typedef Full2<XBindM<Monad> > Type ;

} ;

template <class Monad>
class XBindM_
{
  public:

    template <class M, class K> struct Sig : public FunType<M,K,
      typename Monad::Bind::template Sig<M,
      typename RT<Ignore,typename RT<Const,K>
      ::ResultType>::ResultType>::ResultType>
    {
    };

    template <class M, class K>
    typename Sig<M,K>::ResultType
    operator()( const M& m, const K& k ) const
    {
      return Monad::bind( m, ignore(const_(k)) ) ;
    }

} ;

template <class Monad> Full2<XBindM_<Monad> > bindM_()
{
  return makeFull2( XBindM_<Monad>() );
}

template <class Monad> class BindM_
{
  public:

    typedef Full2<XBindM_<Monad> > Type ;

} ;

template <class Monad> typename Monad::Zero zeroM()
{
  return Monad::zero;
}

template <class Monad> class ZeroM
{
  public:

    typedef typename Monad::Zero Type ;
};

template <class Monad>
class XPlusM
{
  public:

    template <class MA, class MA2> struct Sig : public FunType<MA,MA2,
       typename Monad::Plus::template Sig<MA,MA2>::ResultType>
    {
    };

    template <class MA, class MA2>
    typename Sig<MA,MA2>::ResultType
    operator()( const MA& x, const MA2& y ) const
    {
      return Monad::plus(x,y);
    }

} ;

template <class Monad> Full2<XPlusM<Monad> > plusM()
{
  return makeFull2( XPlusM<Monad>() ) ;
}

template <class Monad> class PlusM
{
  public:

    typedef Full2<XPlusM<Monad> > Type ;

} ;

template <bool b> class BindError { } ;

template <> class BindError<true>
{
  public:

    static inline void error() {}

};

template <class M, class K>
class BindHelper
{
  public:

    typedef typename MonadTraits<M>::Monad MonadA;
    typedef typename MonadA::template UnRep<M>::Type A;
    typedef typename MonadA::Bind::template Sig<M,K>::ResultType ResultType;
    typedef typename MonadTraits<ResultType>::Monad MonadB;

    inline static void ensure_m_and_k_are_in_the_same_monad_instance()
    {
      BindError<Conversion<MonadA,MonadB>::sameType>::error() ;
    }

} ;

class XBind
{
  public:

    template <class M, class K> struct Sig
    : public FunType<M,K,typename BindHelper<M,K>::ResultType>
    {
    };

    template <class M, class K>
    typename Sig<M,K>::ResultType
    operator()( const M& m, const K& k ) const
    {
      BindHelper<M,K>::ensure_m_and_k_are_in_the_same_monad_instance() ;
      typedef typename BindHelper<M,K>::MonadA MM;
      return MM::bind(m,k);
    }

} ;

typedef Full2<XBind> Bind ;

Q_FLP_EXPORT extern Bind bind ;

class XBind_
{
  public:

     template <class M, class K> struct Sig : public FunType<M,K,
       typename RT<Bind,M,typename RT<Ignore,typename RT<Const,K>
       ::ResultType>::ResultType>::ResultType>
     {
     } ;

     template <class M, class K>
     typename Sig<M,K>::ResultType
     operator()( const M& m, const K& k ) const
     {
       return bind( m, ignore(const_(k)) ) ;
     }

} ;

typedef Full2<XBind_> Bind_ ;

Q_FLP_EXPORT extern Bind_ bind_ ;

template <class Monad>
class XMapM
{
  public:

    template <class F, class M> struct Sig : FunType<F,M,
      typename RT<typename BindM<Monad>::Type,M,typename LEType<
        LAM<LV<1>,CALL<typename UnitM<Monad>::Type,
        CALL<F,LV<1> > > > >::Type>::ResultType>
    {
    } ;

    template <class F, class M>
    typename Sig<F,M>::ResultType
    operator()( const F& f, const M& m ) const
    {
      LambdaVar<1> A;
      return bindM<Monad>()( m, lambda(A)[ unitM<Monad>()[f[A]] ] ) ;
    }

} ;

template <class Monad> Full2<XMapM<Monad> > mapM()
{
  return makeFull2( XMapM<Monad>() ) ;
}

template <class Monad> class MapM
{
  public:

    typedef Full2<XMapM<Monad> > Type  ;

} ;

// If you can't beat 'em, JoinM! :) :) :)

template <class Monad>
class XJoinM
{
  public:

    template <class Z> struct Sig : public FunType<Z,
      typename RT<typename BindM<Monad>::Type,Z,Id>::ResultType>
    {
    } ;

    template <class Z>
    typename Sig<Z>::ResultType
    operator()( const Z& z ) const
    {
      return bindM<Monad>()( z, id ) ;
    }

} ;

template <class Monad> Full1<XJoinM<Monad> > joinM()
{
  return makeFull1( XJoinM<Monad>() ) ;
}

template <class Monad> class JoinM
{
  public:

    typedef Full1<XJoinM<Monad> > Type ;

} ;

//////////////////////////////////////////////////////////////////////

template <int i, class E>
Gets<i,typename LEify<E>::Type>
operator<=( const LambdaVar<i>&, const E& e )
{
  return Gets<i,typename LEify<E>::Type>( LEify<E>::go(e) ) ;
}

//////////////////////////////////////////////////////////////////////
// Next on the agenda...
//    doM[ LE ]                 ==>  LE
//    doM[ LE, stmts ]          ==>  bind_[ LE, doM[stmts] ]
//    doM[ X<=LE, stmts ]  ==>  bind[ LE, lambda(X)[ doM[stmts] ] ]
// "doM" is an unfortunate name, as everything else monad-ly I've
// written uses the 'M' suffix to say "I'm a template, pass me a monad
// as a parameter, please", whereas this isn't true here.  But I still
// like "doM" better than "do_", and just "do" is a C++ keyword.

class DoM_Lambdaoid
{
  public:

    template <class Dummy, class FinalLE, class Stuff> struct Helper2 ;

    template <class D, class FinalLE>
    struct Helper2<D,FinalLE,NIL>
    {
      typedef FinalLE Result ;

      static inline Result go( const FinalLE& le, const NIL & )
      {
        return le ;
      }
    };

    template <class D, class FinalLE, class LE, class Rest>
    struct Helper2<D,FinalLE,CONS<LE,Rest> >
    {
      typedef typename LEType<CALL<Bind_,LE,FinalLE> >::Type Inner;
      typedef typename Helper2<D,Inner,Rest>::Result Result;
      static inline Result go( const FinalLE& le, const CONS<LE,Rest>& rest )
      {
        return Helper2<D,Inner,Rest>::go( bind_[ rest.head, le ], rest.tail );
      }
    };

    template <class D, class FinalLE, int i, class LE, class Rest>
    struct Helper2<D,FinalLE,CONS<Gets<i,LE>,Rest> >
    {
      typedef typename LEType<CALL<Bind,LE,LAM<LV<i>,FinalLE> > >::Type Inner;
      typedef typename Helper2<D,Inner,Rest>::Result Result;
      static inline Result
      go( const FinalLE& le, const CONS<Gets<i,LE>,Rest>& rest )
      {
         LambdaVar<i> X ;
         return Helper2<D,Inner,Rest>::go(
            bind[ rest.head.exp, lambda(X)[ le ] ],    rest.tail ) ;
      }
    };

    template <class Dummy, class X> struct Helper ;

    template <class D, class LE, class Rest>
    struct Helper<D,CONS<LE,Rest> >
    {
      typedef typename Helper2<D,LE,Rest>::Result Result;
      static inline Result go( const CONS<LE,Rest>& l )
      {
        return Helper2<D,LE,Rest>::go( l.head, l.tail );
      }
    };

    template <class X> struct RT
    { typedef typename DoM_Lambdaoid::Helper<int,typename
      LEListify<X>::Type>::Result Type; };

    template <class X>
    typename RT<X>::Type
    operator[]( const X& x ) const
    {
      typedef typename LEListify<X>::Type XP;
      return Helper<int,XP>::go( LEListify<X>::go(x) ) ;
    }

};

template <class A, class B=Void, class C=Void, class D=Void> class DOM;
template <int i, class E> class GETS ;

template <int i, class E>
class LEType< GETS<i,E> >
{
  public:

    typedef Gets<i,typename LEify<typename LEType<E>::Type>::Type> Type ;

};

template <class A, class B, class C, class D>
class LEType< DOM<A,B,C,D> >
{
  public:

    typedef typename LET_LEListify<A,B,C,D>::Type L ;
    typedef typename DoM_Lambdaoid::template RT<L>::Type Type ;

};

template <class A, class B, class C>
class LEType< DOM<A,B,C,Void> >
{
  public:

   typedef typename LET_LEListify<A,B,C>::Type L ;
   typedef typename DoM_Lambdaoid::template RT<L>::Type Type ;

};

template <class A, class B>
class LEType< DOM<A,B,Void,Void> >
{
  public:

    typedef typename LET_LEListify<A,B>::Type L ;
    typedef typename DoM_Lambdaoid::template RT<L>::Type Type ;

};

template <class A>
class LEType< DOM<A,Void,Void,Void> >
{
  public:

    typedef typename LET_LEListify<A>::Type L ;
    typedef typename DoM_Lambdaoid::template RT<L>::Type Type ;

};

//////////////////////////////////////////////////////////////////////
// Finally, the mother-of-all-syntactic-sugar: comprehensions!
//    compM<M>()[ LE ]
//       ==>  unit<M>()[ LE ]
//    compM<M>()[ LE | LEa, stmts ]
//       ==>  bindM_[ LEa, comp<M>()[LE|stmts] ]
//    compM<M>()[ LE | X<=LEa, stmts ]
//       ==>  bindM[ LEa, lambda(X)[ comp<M>()[LE|stmts] ] ]
//    compM<M>()[ LE | guard[LEa], stmts ]
//       ==>  if1[ LEa, comp<M>()[LE|stmts], zero<M>() ]
// The vert (|) will be a bit of a pain, as it binds tighter than the
// comma (but thankfully less tightly that <=), and so I'm gonna have to
// make it return a VertPair or something as a new "exp" type which
// operator,() can LEListify, and then have compM unwrap it on the back
// end.  Hmm, and just to ensure that we don't accidentally call C++'s
// built-in operator|(), I think I'll outlaw the first form of compM
// above, and require that there always be a vert and a right-hand-side
// in user calls.  Yup.

template <class LHS, class RHS>
class VertPair : public LEBase
{
  public:

    LHS lhs;
    RHS rhs;
    VertPair( const LHS& l, const RHS& r ) : lhs(l), rhs(r)
    {
      EnsureLE<LHS>::go();
      EnsureLE<RHS>::go();
    }

} ;

template <class LHS, class RHS>
VertPair<typename LEify<LHS>::Type,typename LEify<RHS>::Type>
operator|( const LHS& l, const RHS& r )
{
  return VertPair<typename LEify<LHS>::Type,typename LEify<RHS>::Type>
       ( LEify<LHS>::go(l), LEify<RHS>::go(r) );
}

template <class BFLE> class Guard : public LEBase
{
  public:

    BFLE fun ;

    Guard(const BFLE&f) : fun(f)
    {
      EnsureLE<BFLE>::go();
    }

};

class Guard_Lambdaoid
{
  public:

    template <class BF>
    Guard<typename LEify<BF>::Type> operator[]( const BF& f ) const
    {
      return Guard<typename LEify<BF>::Type>( LEify<BF>::go(f) ) ;
    }

};

template <class Monad>
class compM
{
  public:

    // Dig walks all the way down the list and gets to the LHS of the
    // VertPair at the end, and returns a _reference_ to it.  This is
    // especially happy because it should translate to a no-op.
    template <class Dummy, class L> struct Dig ;

    template <class D, class LHS, class RHS>
    struct Dig<D,CONS<VertPair<LHS,RHS>,NIL> >
    {
      typedef const LHS& Result;
      typedef LHS Type;
      static inline Result go( const CONS<VertPair<LHS,RHS>,NIL>& l )
      { return l.head.lhs; }
    };

    template <class D, class E, class Rest>
    struct Dig<D,CONS<E,Rest> >
    {
      typedef typename Dig<D,Rest>::Result Result;
      typedef typename Dig<D,Rest>::Type Type;
      static inline Result go( const CONS<E,Rest>& l )
      {
        return Dig<D,Rest>::go( l.tail ) ;
      }
    };

    template <class FinalLE, class Stuff> struct Help2 ;
    template <class FinalLE>
    struct Help2<FinalLE,NIL>
    {
      typedef FinalLE Result;
      static inline Result go( const FinalLE& le, const NIL& )
      {
        return le ;
      }
    };

    template <class FinalLE, class LHS, class RHS>
    struct Help2<FinalLE,CONS<VertPair<LHS,RHS>,NIL> >
    {
      typedef typename Help2<FinalLE,CONS<RHS,NIL> >::Result Result;
      static inline Result
      go( const FinalLE& le, const CONS<VertPair<LHS,RHS>,NIL>& x )
      {
         return Help2<FinalLE,CONS<RHS,NIL> >::go
            ( le, CONS<RHS,NIL>(x.head.rhs) );
      }
    };

    template <class FinalLE, class LE, class Rest>
    struct Help2<FinalLE,CONS<LE,Rest> >
    {
      typedef typename LEType<CALL<typename BindM_<Monad>::Type,LE,
         FinalLE> >::Type NextLE;
      typedef typename Help2<NextLE,Rest>::Result Result;
      static inline Result
      go( const FinalLE& le, const CONS<LE,Rest>& x )
      {
         return Help2<NextLE,Rest>::go(
            bindM_<Monad>()[ x.head, le ], x.tail );
      }
    };

    template <class FinalLE, int i, class LE, class Rest>
    struct Help2<FinalLE,CONS<Gets<i,LE>,Rest> >
    {
      typedef typename LEType<CALL<typename BindM<Monad>::Type,LE,
         LAM<LV<i>,FinalLE> > >::Type NextLE;
      typedef typename Help2<NextLE,Rest>::Result Result;
      static inline Result
      go( const FinalLE& le, const CONS<Gets<i,LE>,Rest>& x )
      {
         LambdaVar<i> X;
         return Help2<NextLE,Rest>::go(
            bindM<Monad>()[ x.head.exp, lambda(X)[ le ] ], x.tail ) ;
      }
    };

    template <class FinalLE, class BF, class Rest>
    struct Help2<FinalLE,CONS<Guard<BF>,Rest> >
    {
      typedef typename LEType<IF1<BF,FinalLE,
         typename ZeroM<Monad>::Type> >::Type NextLE;
      typedef typename Help2<NextLE,Rest>::Result Result;

      static inline Result
      go( const FinalLE& le, const CONS<Guard<BF>,Rest>& x )
      {
         return Help2<NextLE,Rest>::go(
            if1[ x.head.fun, le, zeroM<Monad>() ], x.tail );
      }
    };

    template <class L> struct Helper {
      typedef typename Dig<int,L>::Type DigLE;
      typedef typename LEType<CALL<typename UnitM<Monad>::Type,
         DigLE> >::Type FinalLE;
      typedef typename Help2<FinalLE,L>::Result Result;
      static inline Result go( const L& l )
      {
         return Help2<FinalLE,L>::go( unitM<Monad>()[Dig<int,L>::go(l)], l );
      }
    };

    template <class X> struct RT
    {
      typedef typename LEListify<X>::Type XP   ;
      typedef typename Helper<XP>::Result Type ;
    };

    template <class X>
    typename RT<X>::Type
    operator[]( const X& x ) const
    {
      return Helper<typename RT<X>::XP>::go( LEListify<X>::go(x) ) ;
    }

};

template <class T> class GUARD ;

template <class T> class LEType< GUARD<T> >
{
  public:

     typedef Guard< typename LEify<typename LEType<T>::Type>::Type > Type ;

};

template <class A, class B, class C, class D=Void, class E=Void,
          class F=Void> class COMP
{
};

template <class M, class LHS, class A>
class LEType< COMP<M,LHS,A,Void,Void,Void> >
{
  public:

    typedef typename LEify<typename LEType<LHS>::Type>::Type LHST;
    typedef typename LEify<typename LEType<A>::Type>::Type AT;
    typedef VertPair<LHST,AT> T ;
    typedef typename LET_LEListify<T>::Type TE;
    typedef typename compM<M>::template RT<TE>::Type Type;

};

template <class M, class LHS, class A, class B>
class LEType< COMP<M,LHS,A,B,Void,Void> >
{
  public:

    typedef typename LEify<typename LEType<LHS>::Type>::Type LHST;
    typedef typename LEify<typename LEType<A>::Type>::Type AT;
    typedef VertPair<LHST,AT> T ;
    typedef typename LET_LEListify<T,B>::Type TE;
    typedef typename compM<M>::template RT<TE>::Type Type;

};

template <class M, class LHS, class A, class B, class C>
class LEType< COMP<M,LHS,A,B,C,Void> >
{
  public:

    typedef typename LEify<typename LEType<LHS>::Type>::Type LHST;
    typedef typename LEify<typename LEType<A>::Type>::Type AT;
    typedef VertPair<LHST,AT> T ;
    typedef typename LET_LEListify<T,B,C>::Type TE;
    typedef typename compM<M>::template RT<TE>::Type Type;

};

template <class M, class LHS, class A, class B, class C, class D>
class LEType< COMP<M,LHS,A,B,C,D> >
{
  public:

    typedef typename LEify<typename LEType<LHS>::Type>::Type LHST;
    typedef typename LEify<typename LEType<A>::Type>::Type AT;
    typedef VertPair<LHST,AT> T;
    typedef typename LET_LEListify<T,B,C,D>::Type TE;
    typedef typename compM<M>::template RT<TE>::Type Type;

};

Q_FLP_EXPORT extern DoM_Lambdaoid   doM   ;
Q_FLP_EXPORT extern Guard_Lambdaoid guard ;

//////////////////////////////////////////////////////////////////////
// Monad concepts
//////////////////////////////////////////////////////////////////////
// Here we outline the C++ concepts necessary for monads to work in the
// framework.
/*
   concept Monad {
      // unit :: a -> m a
      // bind :: m a -> ( a -> m b ) -> m b
      typedef Unit;           // a full functoid type
      static Unit unit;
      typedef Bind;           // a full functoid type
      static Bind bind;
   }
   //////////////////////////////
   // Inferrable Monads let you use bind() instead of bindM<Monad>()(), and
   // are also the only Monads that work with do-notation (doM).
   concept InferrableMonad models Monad {
      // type constructor: pass an 'a', get back an 'M a'
      template <class A>  struct Rep   { typedef Type; };
      // type deconstructor: pass an 'M a', get back an 'a'
      template <class MA> struct UnRep { typedef Type; };
   }
   and also
   template <> struct MonadTraitsSpecializer< RepType > {
      typedef Monad;   // the monad concept class
   };
   //////////////////////////////
   // Monad zeros enable comprehension guards to work
   concept MonadWithZero models Monad {
      // zero :: m a
      typedef Zero;           // a value type
      static Zero zero;
   }
   //////////////////////////////
   // Some monads have pluses
   concept MonadWithPlus models Monad {
      // plus :: m a -> ma -> ma
      typedef Plus;           // a full functoid type
      static Plus plus;
   }
*/

class ListM
{
  public:

    template <class A> struct Rep
    {
      typedef List<A> Type;
    } ;

    template <class MA> struct UnRep
    {
      typedef typename MA::ElementType Type;
    } ;

    struct XUnit {
      template <class A> struct Sig : public FunType<A,OddList<A> > {};
      template <class A>
      typename Sig<A>::ResultType operator()( const A& x ) const {
         return cons(x,NIL());
      }
    };

    typedef Full1<XUnit> Unit;
    static Unit unit ;

    struct XBind
    {
      template <class M, class K> struct Sig : public FunType<M,K,
         typename RT<Concat,typename RT<FMap,K,M>::ResultType>::ResultType>
      {
      };

      template <class M, class K>
      typename Sig<M,K>::ResultType
      operator()( const M& m, const K& k ) const
      {
         return concat( map(k,m) );
      }
    };

    typedef Full2<XBind> Bind;
    static Bind bind;

    typedef NIL Zero;
    static Zero zero;

    typedef Cat Plus;   // cat is monad plus for lists
    static Plus plus;

    // FIX THIS maybe: map/join/bind_ could be implemented here as
    // well.  default implementations could be inherited.  Not clear if
    // it gains anything, since you can just call the "free function"
    // versions of them, which have defaults based on unit/bind.

};

template <class T> struct MonadTraitsSpecializer<List<T> >
{
  typedef ListM Monad;
};

template <class T> struct MonadTraitsSpecializer<OddList<T> >
{
  typedef ListM Monad ;
};

//////////////////////////////////////////////////////////////////////

class MaybeM
{
  public:

    template <class A>  struct Rep   { typedef Maybe<A> Type; };
    template <class MA> struct UnRep { typedef typename MA::ElementType Type; };

    typedef Just Unit;
    static Unit unit;

    struct XBind
    {
      template <class M, class K> struct Sig : public FunType<M,K,
         typename RT<K,typename M::ElementType>::ResultType>
      {
      };

      template <class M, class K>
      typename Sig<M,K>::ResultType
      operator()( const M& m, const K& k ) const
      {
         if( m.is_nothing() )
            return NOTHING;
         else
            return k( m.value() );
      }
    };

    typedef Full2<XBind> Bind;
    static Bind bind;

    typedef AUniqueTypeForNothing Zero;
    static Zero zero;

    struct XPlus
    {
      template <class MA, class MA2> struct Sig : public FunType<MA,MA2,MA> {};
      template <class MA, class MA2>
      typename Sig<MA,MA2>::ResultType
      operator()( const MA& x, const MA2& y ) const {
         if( x.is_nothing() )
            return y;
         return x;
      }
    };

   typedef Full2<XPlus> Plus;
   static Plus plus;
};

template <class T> struct MonadTraitsSpecializer<Maybe<T> >
{
   typedef MaybeM Monad;
};

//////////////////////////////////////////////////////////////////////

class IdentityM
{
  public:

   // M a = a

   typedef Id Unit;
   static Unit unit;

   struct XBind
   {
      template <class M, class K> struct Sig : public FunType<M,K,
         typename RT<K,M>::ResultType> {};
      template <class M, class K>
      typename Sig<M,K>::ResultType
      operator()( const M& m, const K& k ) const
      {
         return k(m);
      }
   };
   typedef Full2<XBind> Bind;
   static Bind bind;
};

//////////////////////////////////////////////////////////////////////

template <class State>
class StateM
{
  public:

   // M a =  State -> (a,State)

   struct XUnit
   {
      template <class A> struct Sig : public FunType<A,
         typename RT<MakePair,A>::ResultType> {};
      template <class A>
      typename Sig<A>::ResultType
      operator()( const A& a ) const { return makePair(a); }
   };

   typedef Full1<XUnit> Unit;
   static Unit unit;

   struct XBind
   {
      template <class M, class K> struct Sig : public FunType<M,K,
         typename LEType<LAM<LV<2>,LET<BIND<1,CALL<M,LV<2> > >,
                                       CALL<CALL<K,CALL<Fst,LV<1> > >,
                                            CALL<Snd,LV<1> > >
                                      > > >::Type > {};
      template <class M, class K>
      typename Sig<M,K>::ResultType
      operator()( const M& m, const K& k ) const
      {
         // \s0 -> let (a,s1) = m s0
         //            (b,s2) = k a s1
         //        in  (b,s2)
         LambdaVar<1> P;
         LambdaVar<2> s0;
         return lambda(s0)[ let[ P == m[s0] ].in[
                            k[fst[P]][snd[P]] ] ];
      }
   };

   typedef Full2<XBind> Bind ;
   static Bind bind;

   static typename LEType< LAM<LV<1>,CALL<CALL<MakePair,Empty>,State> > >::Type
   assign( const State& sp )
   {
      LambdaVar<1> s;
      return lambda(s)[ makePair[empty][sp] ] ;
   }

   static typename LEType< LAM<LV<1>,CALL<MakePair,LV<1>,LV<1> > > >::Type
   fetch()
   {
      LambdaVar<1> s;
      return lambda(s)[ makePair[s,s] ];
   }
};

template <class State> typename StateM<State>::Unit StateM<State>::unit;
template <class State> typename StateM<State>::Bind StateM<State>::bind;

//////////////////////////////////////////////////////////////////////
// liftM, liftM2, liftM3   (as in Haskell)

template <class Monad>
class XLiftM
{
  public:

    template <class F> struct Sig : public FunType<F,typename
    LEType<LAM<LV<1>,COMP<Monad,CALL<F,LV<2> >,GETS<2,LV<1> > > > >::Type>
    {
    };

    template <class F>
    typename Sig<F>::ResultType operator()( const F& f ) const
    {
      LambdaVar<1> X;
      LambdaVar<2> X_;
      return lambda(X)[ compM<Monad>()[ f[X_] | X_ <= X ] ] ;
    }

};

template <class Monad> Full1<XLiftM<Monad> > liftM()
{
  return makeFull1( XLiftM<Monad>() ) ;
}

template <class Monad> struct LiftM
{
  typedef Full1<XLiftM<Monad> > Type;
} ;

template <class Monad>
class XLiftM2
{
  public:

    template <class F> struct Sig : public FunType<F,typename
      LEType<LAM<LV<1>,LV<3>,COMP<Monad,CALL<F,LV<2>,LV<4> >,GETS<2,LV<1>
      >,GETS<4,LV<3> > > > >::Type>
    {
    };

    template <class F>
    typename Sig<F>::ResultType operator()( const F& f ) const
    {
      LambdaVar<1> X;
      LambdaVar<2> X_;
      LambdaVar<3> Y;
      LambdaVar<4> Y_;
      return lambda(X,Y)[ compM<Monad>()[ f[X_,Y_] | X_ <= X, Y_ <= Y ] ];
    }

};

template <class Monad> Full1<XLiftM2<Monad> > liftM2()
{
  return makeFull1( XLiftM2<Monad>() );
}

template <class Monad> struct LiftM2
{
  typedef Full1<XLiftM2<Monad> > Type;
} ;

template <class Monad>
class XLiftM3
{
  public:

    template <class F> struct Sig : public FunType<F,typename
      LEType<LAM<LV<1>,LV<3>,LV<5>,COMP<Monad,CALL<F,LV<2>,LV<4>,LV<6>
      >,GETS<2,LV<1> >,GETS<4,LV<3> >,GETS<6,LV<5> > > > >::Type>
    {
    };

    template <class F>
    typename Sig<F>::ResultType operator()( const F& f ) const
    {
      LambdaVar<1> X;
      LambdaVar<2> X_;
      LambdaVar<3> Y;
      LambdaVar<4> Y_;
      LambdaVar<5> Z;
      LambdaVar<6> Z_;
      return lambda(X,Y,Z)[ compM<Monad>()[
            f[X_,Y_,Z_] | X_ <= X, Y_ <= Y, Z_ <= Z ] ];
    }

};

template <class Monad> Full1<XLiftM3<Monad> > liftM3()
{
  return makeFull1( XLiftM3<Monad>() ) ;
}

template <class Monad> class LiftM3
{
  public:

    typedef Full1<XLiftM3<Monad> > Type ;

} ;

//////////////////////////////////////////////////////////////////////
// The ByNeed monad, for "lazifying" computations

template <class T>
class ByNeedImpl
{
  public:

    void inc() const { ++refC_; }
    void dec() const { if (!--refC_) delete this; }

  private:

    mutable RefCount refC_ ;

    typedef union {
      unsigned char val[ sizeof(T) ];   // The real variable
      // a bunch of dummies of every conceivable type
      long z1, *pz1; long double z2, *pz2; void *z3, **pz3;
      PtrToFxn z4, *pz4;
      Argh *pz5;
      int z6, *pz6; char z7, *pz7; double z8, *pz8;
      PtrToMember z9, *pz9;
      PtrToMemberFxn z10, *pz10;
    } U;

    mutable U u;
    mutable Fun0<T> fxn;
    mutable bool val_is_valid;  // FIX THIS: can optimize this away into fxn

    const T& value() const
    {
      return *static_cast<const T*>(static_cast<const void*>(&u.val)) ;
    }

    T& value()
    {
      return *static_cast<T*>(static_cast<void*>(&u.val)) ;
    }

    void init( const T& x ) const
    {
      new (static_cast<void*>(&u.val)) T(x);
    }

    static T dummyT() { throw Exception("Used invalid fxn in ByNeedImpl") ; }

    static Fun0<T> dummy()
    {
//      static Fun0<T> f( ptr_to_fun(&ByNeeddummyT) ) ;
      static Fun0<T> f ;
      return f;
    }

    // No copy/assignment
    ByNeedImpl( const ByNeedImpl& );
    void operator=( const ByNeedImpl& );

  public:

    typedef T ElementType ;

    ByNeedImpl( const T& x ) : refC_(0), fxn( dummy() ), val_is_valid(true)
    {
      init(x);
    }

    ByNeedImpl( Fun0<T> f ) : refC_(0), fxn( f ), val_is_valid(false)
    {
    }

    const T& force() const
    {
      if ( val_is_valid )
         return value();
      else {
         init( fxn() );
         val_is_valid = true;
         return value();
      }
    }

};

template <class T>
class ByNeed
{
  protected:

    IRef<ByNeedImpl<T> > ref ;

  public:

    typedef T ElementType ;

    ByNeed( const T& x ) : ref( new ByNeedImpl<T>(x) )
    {
    }

    ByNeed( Fun0<T> f ) : ref( new ByNeedImpl<T>(f) )
    {
    }

    // default copy constructor and assignment operator are fine
    const T& force() const
    {
      return ref->force();
    }

};

class XBForce
{
  public:

    template <class BT> struct Sig : FunType<BT,typename BT::ElementType>
    {
    };

    template <class T>
    const T& operator()( const ByNeed<T>& bt ) const
    {
      return bt.force();
    }

};

typedef Full1<XBForce> BForce;

Q_FLP_EXPORT extern BForce bForce ;

class XBDelay
{
  public:

    template <class T> struct Sig : FunType<T,ByNeed<T> >
    {
    };

    template <class T>
    ByNeed<T> operator()( const T& x ) const
    {
      return ByNeed<T>( x ) ;
    }

};

typedef Full1<XBDelay> BDelay;

Q_FLP_EXPORT extern BDelay bDelay ;

// bLift lazily lifts a function's results into the ByNeed monad:
//    bLift :: (a -> b) -> a -> ByNeed b
//    bLift(f)(args) == ByNeed<T>( lambda()[ f[args] ] )

template <class F>
class XBLifter0 : public CfpType<ByNeed<typename RT<F>::ResultType> >
{
  protected:

    F f;

 public:

    XBLifter0( const F& ff ) : f(ff)
    {
    }

    ByNeed<typename RT<F>::ResultType>
    operator()() const
    {
      return ByNeed<typename RT<F>::ResultType>( lambda()[ f[_*_] ] ) ;
    }

};

template <class F>
class XBLifter1
{
  protected:

    F f ;

  public:

    XBLifter1( const F& ff ) : f(ff)
    {
    }

    template <class X> struct Sig
       : public FunType<X,ByNeed<typename RT<F,X>::ResultType> >
    {
    };

    template <class X>
    typename Sig<X>::ResultType
    operator()( const X& x ) const
    {
      return typename Sig<X>::ResultType( lambda()[ f[x] ] ) ;
    }

};

template <class F>
class XBLifter2
{
  protected:

    F f ;

  public:

    XBLifter2( const F& ff ) : f(ff)
    {
    }

    template <class X, class Y> struct Sig
      : public FunType<X,Y,ByNeed<typename RT<F,X,Y>::ResultType> >
    {
    } ;

    template <class X, class Y>
    typename Sig<X,Y>::ResultType
    operator()( const X& x, const Y& y ) const
    {
      return typename Sig<X,Y>::ResultType( lambda()[ f[x][y] ] ) ;
    }

};

template <class F>
class XBLifter3
{
  protected:

    F f ;

  public:

    XBLifter3( const F& ff ) : f(ff)
    {
    }

    template <class X, class Y, class Z> struct Sig
      : public FunType<X,Y,Z,ByNeed<typename RT<F,X,Y,Z>::ResultType> >
    {
    };

    template <class X, class Y, class Z>
    typename Sig<X,Y,Z>::ResultType
    operator()( const X& x, const Y& y, const Z& z ) const
    {
      return typename Sig<X,Y,Z>::ResultType( lambda()[ f[x][y][z] ] ) ;
    }
};

class XBLift
{
  protected:

    template <int i, class F> struct Helper ;

    template <class F>
    struct Helper<0,F>
    {
      typedef Full0<XBLifter0<F> > Result ;

      static Result go( const F& f )
      {
        return makeFull0( XBLifter0<F>(f) );
      }
    };

    template <class F>
    struct Helper<1,F>
    {
      typedef Full1<XBLifter1<F> > Result ;

      static Result go( const F& f )
      {
        return makeFull1( XBLifter1<F>(f) );
      }
    };

    template <class F>
    struct Helper<2,F>
    {
      typedef Full2<XBLifter2<F> > Result ;

      static Result go( const F& f )
      {
        return makeFull2( XBLifter2<F>(f) );
      }
    };

    template <class F>
    struct Helper<3,F>
    {
      typedef Full3<XBLifter3<F> > Result ;

      static Result go( const F& f )
      {
        return makeFull3( XBLifter3<F>(f) );
      }
    };

  public:

    template <class F> struct Sig : public FunType<F,
      typename Helper<FunctoidTraits<F>::max_args,F>::Result>
    {
    };

    template <class F>
    typename Sig<F>::ResultType operator()( const F& f ) const
    {
      return Helper<FunctoidTraits<F>::max_args,F>::go( f );
    }

};

typedef Full1<XBLift> BLift ;

Q_FLP_EXPORT extern BLift bLift ;

class ByNeedM
{
  public:

    template <class A> struct Rep
    {
      typedef ByNeed<A> Type;
    } ;

    template <class MA> struct UnRep
    {
      typedef typename MA::ElementType Type;
    } ;

    struct XUnit
    {
      template <class A> struct Sig : public FunType<A,ByNeed<A> >
      {
      };

      template <class A>
      typename Sig<A>::ResultType operator()( const A& x ) const
      {
        return ByNeed<A>( x ) ;
      }

    };

    typedef Full1<XUnit> Unit;
    static Unit unit;

    struct XBind
    {
      template <class M, class K> struct Sig : public FunType<M,K,
         typename RT<K,typename M::ElementType>::ResultType >
      {
      };

      template <class M, class K>
      typename Sig<M,K>::ResultType operator()( const M& m, const K& k ) const
      {
        typedef typename Sig<M,K>::ResultType Res;
        return Res( lambda()[ bForce[ k[ bForce[ m ] ] ] ] ) ;
         //return k( bForce( m ) );
      }

    };

    typedef Full2<XBind> Bind;
    static Bind bind;

};

template <class T> class MonadTraitsSpecializer<ByNeed<T> >
{
  public:

    typedef ByNeedM Monad ;

};

Q_FLP_EXPORT extern Curry1                   curry            ;
Q_FLP_EXPORT extern Curry1                   curry1           ;
Q_FLP_EXPORT extern Curry2                   curry2           ;
Q_FLP_EXPORT extern Curry3                   curry3           ;
Q_FLP_EXPORT extern Const                    const_           ;
Q_FLP_EXPORT extern Bind1of1                 bind1of1         ;
Q_FLP_EXPORT extern Bind1of2                 bind1of2         ;
Q_FLP_EXPORT extern Bind2of2                 bind2of2         ;
Q_FLP_EXPORT extern Bind1and2of2             bind1and2of2     ;
Q_FLP_EXPORT extern Bind1and2and3of3         bind1and2and3of3 ;
Q_FLP_EXPORT extern Bind1and2of3             bind1and2of3     ;
Q_FLP_EXPORT extern Bind2and3of3             bind2and3of3     ;
Q_FLP_EXPORT extern Bind1and3of3             bind1and3of3     ;
Q_FLP_EXPORT extern Bind1of3                 bind1of3         ;
Q_FLP_EXPORT extern Bind2of3                 bind2of3         ;
Q_FLP_EXPORT extern Bind3of3                 bind3of3         ;
Q_FLP_EXPORT extern IfLambdaoid < IfNormal > if0              ;
Q_FLP_EXPORT extern IfLambdaoid < IfTrue   > if1              ;
Q_FLP_EXPORT extern IfLambdaoid < IfFalse  > if2              ;
Q_FLP_EXPORT extern LetRecLambdaoid          letrec           ;
Q_FLP_EXPORT extern LetLambdaoid             let              ;
Q_FLP_EXPORT extern MakePair                 makePair         ;
Q_FLP_EXPORT extern Min                      min              ;
Q_FLP_EXPORT extern Max                      max              ;
Q_FLP_EXPORT extern Plus                     plus             ;
Q_FLP_EXPORT extern Minus                    minus            ;
Q_FLP_EXPORT extern Multiplies               multiplies       ;
Q_FLP_EXPORT extern Divides                  divides          ;
Q_FLP_EXPORT extern Modulus                  modulus          ;
Q_FLP_EXPORT extern Negate                   negate           ;
Q_FLP_EXPORT extern Equal                    equal            ;
Q_FLP_EXPORT extern NotEqual                 notEqual         ;
Q_FLP_EXPORT extern Greater                  greater          ;
Q_FLP_EXPORT extern Less                     less             ;
Q_FLP_EXPORT extern GreaterEqual             greaterEqual     ;
Q_FLP_EXPORT extern LessEqual                lessEqual        ;
Q_FLP_EXPORT extern LogicalAnd               logicalAnd       ;
Q_FLP_EXPORT extern LogicalOr                logicalOr        ;
Q_FLP_EXPORT extern LogicalNot               logicalNot       ;
Q_FLP_EXPORT extern Dereference              dereference      ;
Q_FLP_EXPORT extern AddressOf                addressOf        ;
Q_FLP_EXPORT extern Delete_                  delete_          ;
Q_FLP_EXPORT extern OutStream                outStream        ;
Q_FLP_EXPORT extern InStream                 inStream         ;
Q_FLP_EXPORT extern PtrToFun                 ptr_to_fun       ;
Q_FLP_EXPORT extern Funify                   funify           ;
Q_FLP_EXPORT extern Inc                      inc              ;
Q_FLP_EXPORT extern Always1                  always1          ;
Q_FLP_EXPORT extern Never1                   never1           ;
Q_FLP_EXPORT extern AUniqueTypeForNil        nul              ;
Q_FLP_EXPORT extern Head                     head             ;
Q_FLP_EXPORT extern Tail                     tail             ;
Q_FLP_EXPORT extern Null                     null             ;
Q_FLP_EXPORT extern Cons                     cons             ;
Q_FLP_EXPORT extern Cat                      cat              ;
Q_FLP_EXPORT extern Delay                    delay            ;
Q_FLP_EXPORT extern Force                    force            ;
Q_FLP_EXPORT extern Id                       id               ;
Q_FLP_EXPORT extern Compose                  compose          ;
Q_FLP_EXPORT extern Of                       of               ;
Q_FLP_EXPORT extern Compose2                 compose2         ;
Q_FLP_EXPORT extern Until                    until            ;
Q_FLP_EXPORT extern Last                     last             ;
Q_FLP_EXPORT extern Init                     init             ;
Q_FLP_EXPORT extern FLength                  length           ;
Q_FLP_EXPORT extern At                       at               ;
Q_FLP_EXPORT extern FFilter                  filter           ;
Q_FLP_EXPORT extern Concat                   concat           ;
Q_FLP_EXPORT extern FFoldr                   foldr            ;
Q_FLP_EXPORT extern Foldr1                   foldr1           ;
Q_FLP_EXPORT extern Foldl                    foldl            ;
Q_FLP_EXPORT extern Foldl1                   foldl1           ;
Q_FLP_EXPORT extern Scanr                    scanr            ;
Q_FLP_EXPORT extern Scanr1                   scanr1           ;
Q_FLP_EXPORT extern Scanl                    scanl            ;
Q_FLP_EXPORT extern Scanl1                   scanl1           ;
Q_FLP_EXPORT extern Iterate                  iterate          ;
Q_FLP_EXPORT extern Repeat                   repeat           ;
Q_FLP_EXPORT extern FMap                     map              ;
Q_FLP_EXPORT extern Take                     take             ;
Q_FLP_EXPORT extern Drop                     drop             ;
Q_FLP_EXPORT extern TakeWhile                takeWhile        ;
Q_FLP_EXPORT extern DropWhile                dropWhile        ;
Q_FLP_EXPORT extern Replicate                replicate        ;
Q_FLP_EXPORT extern Cycle                    cycle            ;
Q_FLP_EXPORT extern SplitAt                  splitAt          ;
Q_FLP_EXPORT extern Span                     span             ;
Q_FLP_EXPORT extern Break                    break_           ;
Q_FLP_EXPORT extern Flip                     flip             ;
Q_FLP_EXPORT extern Reverse                  reverse          ;
Q_FLP_EXPORT extern And                      and_             ;
Q_FLP_EXPORT extern Or                       or_              ;
Q_FLP_EXPORT extern All                      all              ;
Q_FLP_EXPORT extern Any                      any              ;
Q_FLP_EXPORT extern Elem                     elem             ;
Q_FLP_EXPORT extern NotElem                  notElem          ;
Q_FLP_EXPORT extern Sum                      sum              ;
Q_FLP_EXPORT extern Product                  product          ;
Q_FLP_EXPORT extern Minimum                  minimum          ;
Q_FLP_EXPORT extern Maximum                  maximum          ;
Q_FLP_EXPORT extern ZipWith                  zipWith          ;
Q_FLP_EXPORT extern Zip                      zip              ;
Q_FLP_EXPORT extern Fst                      fst              ;
Q_FLP_EXPORT extern Snd                      snd              ;
Q_FLP_EXPORT extern Unzip                    unzip            ;
Q_FLP_EXPORT extern Gcd                      gcd              ;
Q_FLP_EXPORT extern Odd                      odd              ;
Q_FLP_EXPORT extern Even                     even             ;
Q_FLP_EXPORT extern EnumFrom                 enumFrom         ;
Q_FLP_EXPORT extern EnumFromTo               enumFromTo       ;
Q_FLP_EXPORT extern ListUntil                listUntil        ;
Q_FLP_EXPORT extern Just                     just             ;
Q_FLP_EXPORT extern Empty                    empty            ;
Q_FLP_EXPORT extern HCurry                   hCurry           ;
Q_FLP_EXPORT extern HUncurry                 hUncurry         ;
Q_FLP_EXPORT extern NoOp                     noOp             ;
Q_FLP_EXPORT extern Before                   before           ;
Q_FLP_EXPORT extern After                    after            ;
Q_FLP_EXPORT extern Emptify                  emptify          ;
Q_FLP_EXPORT extern ThunkFuncToFunc          thunkFuncToFunc  ;
Q_FLP_EXPORT extern Uncurry                  uncurry          ;
Q_FLP_EXPORT extern Uncurry0                 uncurry0         ;
Q_FLP_EXPORT extern Duplicate                duplicate        ;
Q_FLP_EXPORT extern Ignore                   ignore           ;
Q_FLP_EXPORT extern DoM_Lambdaoid            doM              ;
Q_FLP_EXPORT extern Guard_Lambdaoid          guard            ;
Q_FLP_EXPORT extern BForce                   bForce           ;
Q_FLP_EXPORT extern BDelay                   bDelay           ;
Q_FLP_EXPORT extern BLift                    bLift            ;
Q_FLP_EXPORT extern Bind                     bind             ;
Q_FLP_EXPORT extern Bind_                    bind_            ;

}

}

QT_END_NAMESPACE

#endif
