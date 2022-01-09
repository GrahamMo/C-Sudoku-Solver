# C-Sudoku-Solver
This was my first program in C that takes an unsolved Sudoku puzzle and solves it (if it's possible).

The general logic of the solution is it finds the next empty square and inputs a valid number, then it continues doing the same until there is a contradiction in the puzzle and then trys the next possible valid number.

The interesting thing about this solution is at first glance it seems that the runtime would be really long time since its running so many for loops, however when wrong numbers are inputted, like with sudoku on paper, contradictions appear quickly which causes the program to attempt the next value.
