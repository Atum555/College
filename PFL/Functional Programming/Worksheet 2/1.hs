classifyIf :: Int -> String
classifyIf x =
  if x <= 9
    then "failed"
    else
      if x <= 12
        then "passed"
        else
          if x <= 15
            then "good"
            else
              if x <= 18
                then "very good"
                else
                  if x <= 20
                    then "excellent"
                    else "Invalid grade"

-- >>> classifyIf 12
-- "passed"

classifyCond :: Int -> String
classifyCond x
  | x <= 9 = "failed"
  | x <= 12 = "passed"
  | x <= 15 = "good"
  | x <= 18 = "very good"
  | x <= 20 = "excellent"
  | otherwise = "Invalid grade"

-- >>> classifyCond 12
-- "passed"
