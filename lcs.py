#least common substring problem

a = "abcfgrrrlllppp"
b = "bcdgppq"

table = [[-1 for j in range(len(b)+1)] for i in range(len(a)+1)]

for row in table:
	row[0] = 0
for col in range(len(table[0])):
	table[0][col] = 0

def LCS_ix(i,j): #calculate the LCS subproblem at the ith index of a and jth index of b
	ix_i = i+1
	ix_j = j+1
	if a[i] == b[j]:
		table[ix_i][ix_j] = table[ix_i-1][ix_j-1] + 1
	else:
		table[ix_i][ix_j] = max(table[ix_i-1][ix_j],table[ix_i][ix_j-1])

def LCS_fill():
	for i in range(len(a)):
		for j in range(len(b)):
			LCS_ix(i,j)

def LCS_trace(i_last, j_last):
	if i_last == 0 or j_last == 0:
		return [""] 
	elif a[i_last-1] == b[j_last-1]:
		return [i + a[i_last-1] for i in LCS_trace(i_last-1,j_last-1)]#add char to each prefix
	else:
		R = []
		if table[i_last][j_last-1] >= table[i_last-1][j_last]:
			R = LCS_trace(i_last,j_last-1)
		if table[i_last-1][j_last] >= table[i_last][j_last-1]:
			R = R + LCS_trace(i_last-1,j)
		return R		

LCS_fill()
print set(LCS_trace(len(a),len(b)))
