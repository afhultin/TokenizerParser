# Tokenizer & Parser

Lexical analyzer and recursive-descent parser in C++ for a simple language with `int`/`float` declarations and arithmetic expressions.

The tokenizer reads a source file character by character and spits out tokens (identifiers, literals, operators, keywords). The parser consumes those tokens and checks them against this grammar:

```
<stmt>   → <decl> | <assign>
<decl>   → (int | float) <ident> [= <literal>] {, <ident> [= <literal>]}
<assign> → <ident> = <expr>
<expr>   → <term> {(+ | -) <term>}
<term>   → <factor> {(* | /) <factor>}
<factor> → <ident> | <int_lit> | ( <expr> )
```

It also maintains a symbol table and reports errors with line numbers.

## Files

- `Q1Tokenizer.cpp` - standalone tokenizer
- `Q1Parser.cpp` - full parser (includes tokenizer + symbol table + error reporting)
- `Q2Tokenizer.cpp` / `Q2Parser.cpp` - alternate versions
- `prg.in`, `prg2.in` - sample input programs

## Build & run

```bash
g++ -o parser Q1Parser.cpp && ./parser
```
