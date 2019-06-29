module Main where

multiply :: Integer -> Integer -> Integer
multiply x y = x * y

main :: IO ()
main = do
  a <- getLine
  b <- getLine
  let x = (read a :: Integer)
  let y = (read b :: Integer)
  print (multiply x y)
