type Name = Char -- ’x’, ’y’, ’z’, etc.

type Env = [(Name, Bool)]

data Prop
  = Const Bool
  | Var Name
  | Not Prop
  | And Prop Prop
  | Or Prop Prop
  | Imply Prop Prop

eval :: Env -> Prop -> Bool
eval env (Const b) = b
eval env (Var x) = case lookup x env of
  Just b -> b
  Nothing -> error "undefined variable"
eval env (Not p) = not (eval env p)
eval env (And p q) = eval env p && eval env q
eval env (Or p q) = eval env p || eval env q
eval env (Imply p q) = not (eval env p) || eval env q

vars :: Prop -> [Name]
vars (Const _) = []
vars (Var x) = [x]
vars (Not x) = vars x
vars (And p q) = vars p ++ vars q
vars (Or p q) = vars p ++ vars q
vars (Imply p q) = vars p ++ vars q

booleans :: Int -> [[Bool]]
booleans 0 = [[]]
booleans n = [b : bs | b <- [False, True], bs <- booleans (n - 1)]

environments :: [Name] -> [Env]
environments names = map (zip names) (booleans (length names))

table :: Prop -> [(Env, Bool)]
-- table p = map (\env -> (env, eval env p)) (environments (vars p))
table p = [(env, eval env p) | env <- environments (vars p)]

-- >>> table (And (Not (Var 'a')) (Var 'b'))
-- >>> table (Or (And (Not (Var 'a')) (Var 'b')) (Var 'c'))
-- [([('a',False),('b',False)],False),([('a',False),('b',True)],True),([('a',True),('b',False)],False),([('a',True),('b',True)],False)]
-- [([('a',False),('b',False),('c',False)],False),([('a',False),('b',False),('c',True)],True),([('a',False),('b',True),('c',False)],True),([('a',False),('b',True),('c',True)],True),([('a',True),('b',False),('c',False)],False),([('a',True),('b',False),('c',True)],True),([('a',True),('b',True),('c',False)],False),([('a',True),('b',True),('c',True)],True)]
