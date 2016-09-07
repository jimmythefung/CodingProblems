# String Permutation  
Given a string, s. Return all permutations.  
i.e. s="abc"  
     return {abc, acb, bac, bca, cab, cba}  

Idea:  
-Recursion.  
-Let's say I have s="abc", and a permutation function P(s) that gives permutations of s. Then P(s) = "a"+{P("bc")}  
-Note P("bc") = {"bc", "cb"}
-Then for each element in {P("bc")}, insert "a" at all and incremental positions to form a new set {P("abc")}.  
-We form, for "bc" -> (a)bc, b(a)c, bc(a)  
-and for      "cb" -> (a)cb, c(a)b, cb(a)  
-Which results in P(s) = {abc, bac, bca, acb, cab, cba}
