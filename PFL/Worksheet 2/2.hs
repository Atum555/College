classifyBMI :: (Ord a, Floating a) => a -> a -> String
classifyBMI weight height
  | bmi < 18.5 = "underweight"
  | bmi < 25 = "normal weight"
  | bmi < 30 = "overweight"
  | otherwise = "obese"
  where
    bmi = weight / (height ** 2)

-- >>> classifyBMI 90 1.90
-- "normal weight"

-- >>> classifyBMI 60 1.65
-- "normal weight"
