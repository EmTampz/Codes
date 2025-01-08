% Dalion, Adrian Lloyd L.
% Tampugao, Mohammad Muraya S.

% This Prolog program models a family tree encompassing three generations
% with detailed relationships including gender and familial roles.

% Facts about gender
male(adam).
male(charles).
male(edward).
male(george).
male(ian).
male(kevin).
male(mike).
male(oscar).
male(quinn).
male(steve).
male(tim).

female(eve).
female(diana).
female(faye).
female(hannah).
female(julia).
female(lisa).
female(nancy).
female(patty).
female(rachel).

% Facts about family relationships
grandparent(adam, X) :- parent(adam, Y), parent(Y, X).
grandparent(eve, X) :- parent(eve, Y), parent(Y, X).

parent(adam, charles).
parent(adam, diana).
parent(eve, charles).
parent(eve, diana).
parent(adam, edward).
parent(adam, faye).
parent(eve, edward).
parent(eve, faye).

parent(charles, george).
parent(charles, hannah).
parent(diana, ian).
parent(diana, julia).
parent(edward, kevin).
parent(edward, lisa).
parent(faye, mike).
parent(faye, nancy).
parent(charles, oscar).
parent(diana, patty).
parent(edward, quinn).
parent(faye, rachel).
parent(charles, steve).
parent(diana, tim).

% Rules
granpa(X, Y) :- male(X), grandparent(X, Y).
granma(X, Y) :- female(X), grandparent(X, Y).
father(X, Y) :- male(X), parent(X, Y).
mother(X, Y) :- female(X), parent(X, Y).
son(X, Y) :- male(X), parent(Y, X).
daughter(X, Y) :- female(X), parent(Y, X).
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.
aunt(X, Y) :- female(X), sibling(X, Z), parent(Z, Y).
uncle(X, Y) :- male(X), sibling(X, Z), parent(Z, Y).
cousin(X, Y) :- parent(Z, X), parent(W, Y), sibling(Z, W).










