class Solution {
    public void solveSudoku(char[][] board) {

		solve(board, 0, 0);

	}
    
    private boolean solve(char[][] board, int i, int j) {

		if (i == board.length) {

			
			return true;
		}

		int ni = 0;
		int nj = 0;

		// if j reaches end, initialize it with next i=i+1,j=0
		if (j == board.length - 1) {

			nj = 0;
			ni = i + 1;
		} else {

			ni = i;
			nj = j + 1;
		}

		// if content on board at i and j is not null, advance to next cell
		if (board[i][j] == '.') {

			for (char po = '1'; po <= '9'; po++) {

				// if success

				if (isValid(board, i, j, po)) {

					// set board value with that num
					board[i][j] = po;
					if (solve(board, ni, nj)) {
						return true;
					}

					board[i][j] = '.';

				}
			}

		}else {
			return solve(board, ni, nj);
		}
		
		return false;
	}

	private static boolean isValid(char[][] board, int x, int y, char val) {

		// check in row
		int n = board.length;
		for (int i = 0; i < n; i++) {

			if (board[i][y] == val) {
				return false;
			}
		}

		// check in col
		for (int i = 0; i < n; i++) {

			if (board[x][i] == val) {
				return false;
			}
		}

		// check in submatrix

		int smi = (x / 3) * 3;
		int smj = (y / 3) * 3;

		for (int i = 0; i < 3; i++) {

			for (int j = 0; j < 3; j++) {

				if (board[smi + i][smj + j] == val) {

					return false;
				}

			}
		}
        return true;

    }	
}