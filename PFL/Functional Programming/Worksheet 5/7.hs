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

-- >>> vars (And (Var 'p') (Not (Var 'p')))
-- "pp"
