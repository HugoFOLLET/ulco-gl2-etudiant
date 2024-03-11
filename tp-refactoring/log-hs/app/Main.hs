import System.IO

add3 :: Int -> Int 
add3 = (+3)

mul2 :: Int -> Int
mul2 = (*2)

mycompute :: Int -> IO Int
mycompute v0 = do
    putStrLn ("add3 " ++ show v0)
    let v1 = add3 v0
    putStrLn ("mul2 " ++ show v1)
    let v2 = mul2 v1
    return v2

mycomputeFile :: Int -> IO Int
mycomputeFile v0 = do
    file <- openFile "log.txt" WriteMode
    hPutStrLn file ("add3 " ++ show v0)
    let v1 = add3 v0
    hPutStrLn file ("mul2 " ++ show v1)
    let v2 = mul2 v1
    hClose file
    return v2

mycompute2 :: (String -> IO()) -> Int -> IO Int
mycompute2 func v0 = do
    func ("add3 " ++ show v0)
    let v1 = add3 v0
    func ("mul2 " ++ show v1)
    let v2 = mul2 v1
    return v2


main :: IO ()
main = do
    putStrLn "this is log-hs"
    
    res <- mycompute 12
    print res

    res2 <- mycomputeFile 15
    print res2

    resF <- mycompute2 putStrLn 58
    print resF

    file <- openFile "log2.txt" WriteMode
    resF2 <- mycompute2 (hPutStrLn file) 17
    hClose file
    print resF2
