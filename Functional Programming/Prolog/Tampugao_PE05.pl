% Dalion, Adrian Lloyd L.
% Tampugao, Mohammad Muraya S.
% This Prolog program determines the slayer in a detective mystery by analyzing characters' locations,
% costumes, and eyebrow colors based on provided clues.

% Location facts for each person
location(nobita, 25).
location(kudo, 29).
location(conan, 23).
location(pope, 27).

% Costume facts based on room implications and items worn
costume(conan, fancy_bracelet).
costume(nobita, pendant).
costume(pope, g_shock).
costume(conan, shades).  % Conan wears shades based on deductions from the clues provided

% Eyebrow color logic based on costumes and room implications
eyebrows(nobita, silver).
eyebrows(pope, brown).
eyebrows(conan, pink).   % Conan has pink eyebrows as he wears shades

% Determining the slayer based on eyebrow color
slayer(X) :- eyebrows(X, pink).

