main = mapM_ (putStrLn . f) [1..100]

f :: Int -> String
f x
  | g 15 = "FizzBuzz"
  | g 3 = "Fizz"
  | g 5 = "Buzz"
  | otherwise = show x
  where g a = x `mod` a == 0
