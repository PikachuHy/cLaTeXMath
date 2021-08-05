#ifndef LATEX_MACRO_FRAC_H
#define LATEX_MACRO_FRAC_H

#include "macro/macro_decl.h"
#include "atom/atom_frac.h"
#include "atom/atom_char.h"

namespace tex {

sptr<Atom> _choose(
  const std::string& left, const std::string& right,
  TeXParser& tp, Args& args
);

inline macro(choose) {
  return _choose("lparen", "rparen", tp, args);
}

inline macro(brack) {
  return _choose("lbrack", "rbrack", tp, args);
}

inline macro(bangle) {
  return _choose("langle", "rangle", tp, args);
}

inline macro(brace) {
  return _choose("lbrace", "rbrace", tp, args);
}

inline macro(frac) {
  Formula num(tp, args[1], false);
  Formula den(tp, args[2], false);
  if (num._root == nullptr || den._root == nullptr)
    throw ex_parse("Both numerator and denominator of a fraction can't be empty!");
  return sptrOf<FractionAtom>(num._root, den._root, true);
}

inline macro(binom) {
//  Formula num(tp, args[1], false);
//  Formula den(tp, args[2], false);
//  if (num._root == nullptr || den._root == nullptr)
//    throw ex_parse("Both binomial coefficients must be not empty!");
//  auto f = sptrOf<FractionAtom>(num._root, den._root, false);
//  auto l = SymbolAtom::get("lbrack");
//  auto r = SymbolAtom::get("rbrack");
//  // modify its type to opening and closing
//  l->_type = AtomType::opening;
//  r->_type = AtomType::closing;
//  return sptrOf<FencedAtom>(f, l, r);
}

macro(above);

macro(atop);

macro(over);

macro(abovewithdelims);

macro(atopwithdelims);

macro(overwithdelims);

macro(sfrac);

macro(cfrac);

macro(genfrac);

}

#endif //LATEX_MACRO_FRAC_H
