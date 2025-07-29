**Sudoku Solver (C++)**  
<br>
A C++ implementation of a Sudoku solver using the backtracking algorithm.  
This program takes a 9x9 Sudoku puzzle as input (with empty cells represented as `.`)  
and fills in the board with a valid solution.  
<br>
<br>

**Features**  
- Solves any valid 9x9 Sudoku puzzle  
- Uses classic backtracking algorithm  
- Input and output are printed in a human-readable grid format  
- Simple and clean C++ code with no external dependencies
  
<br>
<br>

**How It Works**    
Uses recursive backtracking to fill in the board:

- Try placing digits `'1'` to `'9'` in empty cells  
- Check if the placement is valid using Sudoku rules:
  - Row constraint  
  - Column constraint  
  - 3x3 subgrid constraint  
- Recursively proceed with the next empty cell  
- If no valid number can be placed, **backtrack** to the previous step

