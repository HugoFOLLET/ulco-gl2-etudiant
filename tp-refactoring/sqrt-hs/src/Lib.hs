module Lib where

mysqrt :: Double -> Maybe Double
mysqrt x 
    | x < 0 = Nothing
    | otherwise = Just(sqrt x)
