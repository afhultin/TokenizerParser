# Tokenizer & Parser

A lexical analyzer and recursive-descent parser in C++ for a simple programming language supporting integer/float declarations and arithmetic expressions.

## Components

### Tokenizer (`Q1Tokenizer.cpp`)
Lexical analyzer that reads source files character by character and produces a stream of tokens:
- **Identifiers** and **keywords** (`int`, `float`)
- **Integer and float literals**
- **Operators** (`+`, `-`, `*`, `/`, `=`)
- **Delimiters** (`(`, `)`, `,`)

### Parser (`Q1Parser.cpp`)
Recursive-descent parser that processes the token stream and enforces grammar rules:
- **Declarations** — `int x = 5, y = 10` and `float pi = 3.14`
- **Assignment statements** — `x = y + 5 * (z - 2)`
- **Arithmetic expressions** — with correct operator precedence (factor → term → expr)
- **Symbol table** — tracks declared variables with types and values
- **Error reporting** — reports syntax errors with line numbers

## Grammar

```
<stmt>   → <decl> | <assign>
<decl>   → (int | float) <ident> [= <literal>] {, <ident> [= <literal>]}
<assign> → <ident> = <expr>
<expr>   → <term> {(+ | -) <term>}
<term>   → <factor> {(* | /) <factor>}
<factor> → <ident> | <int_lit> | ( <expr> )
```

## Usage

```bash
g++ -o tokenizer Q1Tokenizer.cpp && ./tokenizer    # runs tokenizer on prg2.in
g++ -o parser Q1Parser.cpp && ./parser              # runs full parser on prg2.in
```

Input files (`prg.in`, `prg2.in`) contain sample programs in the supported language.

Built for a Languages and Paradigms course.
