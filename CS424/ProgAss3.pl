male(will).
male(matt).
male(billy).
male(david).
male(cameron).
male(lin).
female(mistie).
female(lisa).
female(kiersten).
female(eileen).
parent(billy, will).
parent(billy, matt).
parent(mistie, will).
parent(mistie, matt).
parent(david, cameron).
parent(david, kiersten).
parent(lisa, cameron).
parent(lisa, kiersten).
parent(lin, billy).
parent(lin, lisa).
parent(eileen, billy).
parent(eileen, lisa).
son(C, P) :- parent(P, C), male(C).
daughter(C, P) :- parent(P, C), female(C).
brother(X, Y) :- father(F, X), father(F, Y), mother(M, X), mother(M, Y), male(X), not(X = Y).
sister(X, Y) :- father(F, X), father(F, Y), mother(M, X), mother(M, Y),  female(X), not(X = Y).
mother(P, C) :- parent(P, C), female(P).
father(P, C) :- parent(P, C), male(P).
grandparent(G, C) :- parent(G, P), parent(P, C).
grandfather(G, C) :- grandparent(G, C), male(G).
grandmother(G, C) :- grandparent(G, C), female(G).
cousin(X, Y) :- parent(A, X), parent(B, Y), brother(A, B), not(X = Y), not(A = B).
cousin(X, Y) :- parent(A, X), parent(B, Y), sister(A, B), not(X = Y), not(A = B).