#include "core/formula.h"

using namespace std;
using namespace tex;

const map<c32, string> Formula::_charToSymbol{
  {'+', "plus"},
  {'-', "minus"},
  {'*', "ast"},
  {'/', "slash"},
  {'|', "vert"},
  {'(', "lparen"},
  {')', "rparen"},
  {'[', "lbrack"},
  {']', "rbrack"},
  {'{', "lbrace"},
  {'}', "rbrace"},
  {',', "comma"},
  {';', "semicolon"},
  {'!', "exclam"},
  {'?', "question"},
  {'|', "vert"},
  {':', "colon"},
  {'=', "equal"},
  {'>', "greater"},
  {'<', "less"},
};

map<string, string> Formula::_predefFormulaStrs{
  {"qquad",            "\\quad\\quad"},
  {" ",                "\\nbsp"},
  // region dots
  {"dotsc",            "\\ldots"},
  {"dots",             "\\ldots"},
  {"dotsb",            "\\cdots"},
  {"dotso",            "\\ldots"},
  {"dotsi",            "\\!\\cdots"},
  {"hdots",            "\\ldots"},
  // endregion
  // region math symbols
  {"relbar",           "\\mathrel{\\smash-}"},
  {"log",              "\\mathop{\\mathrm{log}}\\nolimits"},
  {"lg",               "\\mathop{\\mathrm{lg}}\\nolimits"},
  {"ln",               "\\mathop{\\mathrm{ln}}\\nolimits"},
  {"ln",               "\\mathop{\\mathrm{ln}}\\nolimits"},
  {"lim",              "\\mathop{\\mathrm{lim}}"},
  {"limsup",           "\\mathop{\\mathrm{lim\\,sup}}"},
  {"liminf",           "\\mathop{\\mathrm{lim\\,inf}}"},
  {"injlim",           "\\mathop{\\mathrm{inj\\,lim}}"},
  {"projlim",          "\\mathop{\\mathrm{proj\\,lim}}"},
  {"varinjlim",        "\\mathop{\\underrightarrow{\\mathrm{lim}}}"},
  {"varprojlim",       "\\mathop{\\underleftarrow{\\mathrm{lim}}}"},
  {"varliminf",        "\\mathop{\\underline{\\mathrm{lim}}}"},
  {"varlimsup",        "\\mathop{\\overline{\\mathrm{lim}}}"},
  {"sin",              "\\mathop{\\mathrm{sin}}\\nolimits"},
  {"arcsin",           "\\mathop{\\mathrm{arcsin}}\\nolimits"},
  {"sinh",             "\\mathop{\\mathrm{sinh}}\\nolimits"},
  {"cos",              "\\mathop{\\mathrm{cos}}\\nolimits"},
  {"arccos",           "\\mathop{\\mathrm{arccos}}\\nolimits"},
  {"cot",              "\\mathop{\\mathrm{cot}}\\nolimits"},
  {"arccot",           "\\mathop{\\mathrm{arccot}}\\nolimits"},
  {"cosh",             "\\mathop{\\mathrm{cosh}}\\nolimits"},
  {"tan",              "\\mathop{\\mathrm{tan}}\\nolimits"},
  {"arctan",           "\\mathop{\\mathrm{arctan}}\\nolimits"},
  {"tanh",             "\\mathop{\\mathrm{tanh}}\\nolimits"},
  {"coth",             "\\mathop{\\mathrm{coth}}\\nolimits"},
  {"sec",              "\\mathop{\\mathrm{sec}}\\nolimits"},
  {"arcsec",           "\\mathop{\\mathrm{arcsec}}\\nolimits"},
  {"arccsc",           "\\mathop{\\mathrm{arccsc}}\\nolimits"},
  {"sech",             "\\mathop{\\mathrm{sech}}\\nolimits"},
  {"csc",              "\\mathop{\\mathrm{csc}}\\nolimits"},
  {"csch",             "\\mathop{\\mathrm{csch}}\\nolimits"},
  {"max",              "\\mathop{\\mathrm{max}}"},
  {"min",              "\\mathop{\\mathrm{min}}"},
  {"sup",              "\\mathop{\\mathrm{sup}}"},
  {"inf",              "\\mathop{\\mathrm{inf}}"},
  {"arg",              "\\mathop{\\mathrm{arg}}\\nolimits"},
  {"ker",              "\\mathop{\\mathrm{ker}}\\nolimits"},
  {"dim",              "\\mathop{\\mathrm{dim}}\\nolimits"},
  {"hom",              "\\mathop{\\mathrm{hom}}\\nolimits"},
  {"det",              "\\mathop{\\mathrm{det}}"},
  {"exp",              "\\mathop{\\mathrm{exp}}\\nolimits"},
  {"Pr",               "\\mathop{\\mathrm{Pr}}"},
  {"gcd",              "\\mathop{\\mathrm{gcd}}"},
  {"deg",              "\\mathop{\\mathrm{deg}}\\nolimits"},
  {"bmod",             "\\:\\mathbin{\\mathrm{mod}}\\:"},
  // endregion
  // region symbol alias
  {"arrowvert",        "\\vert"},
  {"Arrowvert",        "\\Vert"},
  {"aa",               "\\mathring{a}"},
  {"AA",               "\\mathring{A}"},
  {"ddag",             "\\ddagger"},
  {"dag",              "\\dagger"},
  {"Doteq",            "\\doteqdot"},
  {"doublecup",        "\\Cup"},
  {"doublecap",        "\\Cap"},
  {"llless",           "\\lll"},
  {"gggtr",            "\\ggg"},
  {"copyright",        "\\circledR"},
  {"micro",            "\\mu"},
  {"rVert",            "\\Vert"},
  {"lVert",            "\\Vert"},
  {"lvert",            "\\vert"},
  {"rvert",            "\\vert"},
  // endregion
  // region Greek
  {"Alpha",            "Α"},
  {"Beta",             "Β"},
  {"Epsilon",          "Ε"},
  {"Zeta",             "Ζ"},
  {"Eta",              "Η"},
  {"Iota",             "Ι"},
  {"Kappa",            "Κ"},
  {"Mu",               "Μ"},
  {"Nu",               "Ν"},
  {"Omicron",          "Ο"},
  {"Rho",              "Ρ"},
  {"Tau",              "Τ"},
  {"Chi",              "Χ"},
  {"Nabla",            "∇"},
  {"omicron",          "ο"},
  // endregion
  // region colons
  {"ratio",            "\\mathrel{\\colon}"},
  {"minuscolon",       "\\dashcolon"},
  {"minuscoloncolon",  "\\mathrel{\\minus\\nokern\\colon\\nokern\\colon}"},
  {"simcolon",         "\\mathrel{\\sim\\nokern\\colon}"},
  {"simcoloncolon",    "\\mathrel{\\sim\\nokern\\colon\\nokern\\colon}"},
  {"approxcolon",      "\\mathrel{\\approx\\nokern\\colon}"},
  {"approxcoloncolon", "\\mathrel{\\approx\\nokern\\colon\\nokern\\colon}"},
  {"coloncolon",       "\\Colon"},
  {"equalscolon",      "\\eqcolon"},
  {"equalscoloncolon", "\\mathrel{\\equal\\nokern\\colon\\nokern\\colon}"},
  {"colonminus",       "\\mathrel{\\reflectbox{\\dashcolon}}"},
  {"coloncolonminus",  "\\mathrel{\\colon\\nokern\\colon\\nokern\\minus}"},
  {"colonequals",      "\\mathrel{\\reflectbox{\\eqcolon}}"},
  {"coloncolonequals", "\\mathrel{\\colon\\nokern\\colon\\nokern\\equal}"},
  {"colonsim",         "\\mathrel{\\colon\\nokern\\sim}"},
  {"coloncolonsim",    "\\mathrel{\\colon\\nokern\\colon\\nokern\\sim}"},
  {"colonapprox",      "\\mathrel{\\colon\\nokern\\approx}"},
  {"coloncolonapprox", "\\mathrel{\\colon\\nokern\\colon\\nokern\\approx}"},
  // endregion
  {"celsius",          "\\mathord{{}^\\circ\\mathrm{C}}"},
  {"marker",           "\\kern{0.25ex}\\rule{0.5ex}{1.2ex}\\kern{0.25ex}"},
  {"hybull",           "\\rule[0.6ex]{1ex}{0.2ex}"},
  {"block",            "\\rule{1ex}{1.2ex}"},
  {"uhblk",            "\\rule[0.6ex]{1ex}{0.6ex}"},
  {"lhblk",            "\\rule{1ex}{0.6ex}"},
  {"Android",          "\\large{🤖️}"},
  {"AndroidTeX",       "\\Android\\TeX"},
  {"TeX",              "\\text{T\\kern-.15em\\raisebox{-.4ex}{E}\\kern-.15em X}"},
  {"LaTeX",            "\\text{L\\kern-0.25em"
                       "\\raisebox{.45ex}{\\scalebox{0.7}{A}}"
                       "\\kern-.15em T\\kern-.15em"
                       "\\raisebox{-.4ex}{E}\\kern-.15em X}"},
  {"IJ",               "{I\\kern-0.065em J}"},
  {"ij",               "{i\\kern-0.065em j}"},
  {"idotsint",         "\\int\\cdots\\int"},
};
