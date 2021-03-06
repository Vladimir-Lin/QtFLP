#include <qtflp.h>

namespace N  {
namespace LP {

ListM::Unit              ListM::unit      ;
ListM::Bind              ListM::bind      ;
ListM::Zero              ListM::zero      ;
MaybeM::Unit             MaybeM::unit     ;
MaybeM::Bind             MaybeM::bind     ;
MaybeM::Zero             MaybeM::zero     ;
IdentityM::Unit          IdentityM::unit  ;
IdentityM::Bind          IdentityM::bind  ;
ByNeedM::Unit            ByNeedM::unit    ;
ByNeedM::Bind            ByNeedM::bind    ;

AutoCurryType            _                ;
Curry1                   curry            ;
Curry1                   curry1           ;
Curry2                   curry2           ;
Curry3                   curry3           ;
Const                    const_           ;
Bind1of1                 bind1of1         ;
Bind1of2                 bind1of2         ;
Bind2of2                 bind2of2         ;
Bind1and2of2             bind1and2of2     ;
Bind1and2and3of3         bind1and2and3of3 ;
Bind1and2of3             bind1and2of3     ;
Bind2and3of3             bind2and3of3     ;
Bind1and3of3             bind1and3of3     ;
Bind1of3                 bind1of3         ;
Bind2of3                 bind2of3         ;
Bind3of3                 bind3of3         ;
IfLambdaoid < IfNormal > if0              ;
IfLambdaoid < IfTrue   > if1              ;
IfLambdaoid < IfFalse  > if2              ;
LetRecLambdaoid          letrec           ;
LetLambdaoid             let              ;
MakePair                 makePair         ;
Min                      min              ;
Max                      max              ;
Plus                     plus             ;
Minus                    minus            ;
Multiplies               multiplies       ;
Divides                  divides          ;
Modulus                  modulus          ;
Negate                   negate           ;
Equal                    equal            ;
NotEqual                 notEqual         ;
Greater                  greater          ;
Less                     less             ;
GreaterEqual             greaterEqual     ;
LessEqual                lessEqual        ;
LogicalAnd               logicalAnd       ;
LogicalOr                logicalOr        ;
LogicalNot               logicalNot       ;
Dereference              dereference      ;
AddressOf                addressOf        ;
Delete_                  delete_          ;
OutStream                outStream        ;
InStream                 inStream         ;
PtrToFun                 ptr_to_fun       ;
Funify                   funify           ;
Inc                      inc              ;
Always1                  always1          ;
Never1                   never1           ;
AUniqueTypeForNil        nul              ;
Head                     head             ;
Tail                     tail             ;
Null                     null             ;
Cons                     cons             ;
Cat                      cat              ;
Delay                    delay            ;
Force                    force            ;
Id                       id               ;
Compose                  compose          ;
Of                       of               ;
Compose2                 compose2         ;
Until                    until            ;
Last                     last             ;
Init                     init             ;
FLength                  length           ;
At                       at               ;
FFilter                  filter           ;
Concat                   concat           ;
FFoldr                   foldr            ;
Foldr1                   foldr1           ;
Foldl                    foldl            ;
Foldl1                   foldl1           ;
Scanr                    scanr            ;
Scanr1                   scanr1           ;
Scanl                    scanl            ;
Scanl1                   scanl1           ;
Iterate                  iterate          ;
Repeat                   repeat           ;
FMap                     map              ;
Take                     take             ;
Drop                     drop             ;
TakeWhile                takeWhile        ;
DropWhile                dropWhile        ;
Replicate                replicate        ;
Cycle                    cycle            ;
SplitAt                  splitAt          ;
Span                     span             ;
Break                    break_           ;
Flip                     flip             ;
Reverse                  reverse          ;
And                      and_             ;
Or                       or_              ;
All                      all              ;
Any                      any              ;
Elem                     elem             ;
NotElem                  notElem          ;
Sum                      sum              ;
Product                  product          ;
Minimum                  minimum          ;
Maximum                  maximum          ;
ZipWith                  zipWith          ;
Zip                      zip              ;
Fst                      fst              ;
Snd                      snd              ;
Unzip                    unzip            ;
Gcd                      gcd              ;
Odd                      odd              ;
Even                     even             ;
EnumFrom                 enumFrom         ;
EnumFromTo               enumFromTo       ;
ListUntil                listUntil        ;
Just                     just             ;
Empty                    empty            ;
HCurry                   hCurry           ;
HUncurry                 hUncurry         ;
NoOp                     noOp             ;
Before                   before           ;
After                    after            ;
Emptify                  emptify          ;
ThunkFuncToFunc          thunkFuncToFunc  ;
Uncurry                  uncurry          ;
Uncurry0                 uncurry0         ;
Duplicate                duplicate        ;
Ignore                   ignore           ;
DoM_Lambdaoid            doM              ;
Guard_Lambdaoid          guard            ;
BForce                   bForce           ;
BDelay                   bDelay           ;
BLift                    bLift            ;
Bind                     bind             ;
Bind_                    bind_            ;

}

}
