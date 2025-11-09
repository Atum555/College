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
