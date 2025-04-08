{-
-- EPITECH PROJECT, 2024
-- Semester_3
-- File description:
-- Main
-}

module Main (main) where

import Lib
import System.Environment (getArgs)
import Data.Maybe (fromMaybe)
import System.Exit (exitWith, ExitCode(..))
import System.Exit (exitFailure)

data Conf = Conf
  { rule      :: Maybe Int
  , start     :: Maybe Int
  , linesCount :: Maybe Int
  , window    :: Maybe Int
  , move      :: Maybe Int
  } deriving (Show)

defaultConf :: Conf
defaultConf = Conf
  { rule      = Nothing
  , start     = Just 0
  , linesCount = Nothing
  , window    = Just 80
  , move      = Nothing
  }

getOpts :: Conf -> [String] -> Maybe Conf
getOpts conf [] = Just conf
getOpts conf (option:arg:args) =
  case option of
    "--rule"   -> getOpts (conf { rule      = readMaybe arg }) args
    "--start"  -> getOpts (conf { start     = readMaybe arg }) args
    "--lines"  -> getOpts (conf { linesCount = readMaybe arg }) args
    "--window" -> getOpts (conf { window    = readMaybe arg }) args
    "--move"   -> getOpts (conf { move      = readMaybe arg }) args
    _          -> Nothing

readMaybe :: Read a => String -> Maybe a
readMaybe s = case reads s of
  [(x, "")] -> Just x
  _         -> Nothing

exitWithError :: String -> IO a
exitWithError errMsg = putStrLn errMsg >> exitWith (ExitFailure 84)

main :: IO ()
main = getArgs >>= \args ->
  case getOpts defaultConf args of
    Just conf ->
      case rule conf of
        Just ruleValue ->
          let lnsValue = fromMaybe maxBound (linesCount conf)
              strtValue = fromMaybe 0 (start conf)
              wndwValue = fromMaybe 80 (window conf)
              mvValue = fromMaybe 0 (move conf)
           in displayAutomaton ruleValue strtValue lnsValue wndwValue mvValue
        Nothing -> exitWithError "Rule is mandatory"
    Nothing -> exitWithError "Invalid options provided."

applyRule :: Int -> [Bool] -> Bool
applyRule 30 neighbors = rule30 neighbors
applyRule 90 neighbors = rule90 neighbors
applyRule 110 neighbors = rule110 neighbors
applyRule _ _ = error "Unsupported rule"

rule30 :: [Bool] -> Bool
rule30 [a, b, c] = a /= (b || c)
rule30 _ = error "Invalid neighborhood for Rule 30"

rule90 :: [Bool] -> Bool
rule90 [a, b, c] = a /= c
rule90 _ = error "Invalid neighborhood for Rule 90"

rule110 :: [Bool] -> Bool
rule110 [a, b, c] = a /= (b && c)
rule110 _ = error "Invalid neighborhood for Rule 110"

getNthGeneration :: Int -> Int -> [Bool] -> [Bool]
getNthGeneration _ 0 cells = cells
getNthGeneration rule n cells =
  getNthGeneration rule (n - 1)
    (map (\i -> applyRule rule (getNeighbors i cells)) [0 .. length cells - 1])

displayAutomaton :: Int -> Int -> Int -> Int -> Int -> IO ()
displayAutomaton rule start linesCount window move =
  let initOff = (window `div` 2)
      initialGeneration = replicate initOff False ++ [True] ++ replicate (window - initOff - 2) False
      displayLines 0 _ = return ()
      displayLines n gen =
        let translated = if move < 0 then drop (abs move) gen else replicate (abs move) False ++ gen
            truncated = take window translated
        in putStrLn (concatMap (\b -> if b then "*" else " ") truncated)
           >> displayLines (n - 1) (getNthGeneration rule (start + 1) gen)
  in displayLines linesCount initialGeneration

getNeighbors :: Int -> [Bool] -> [Bool]
getNeighbors i cells =
  let left = if i > 0 then cells !! (i - 1) else False
      center = cells !! i
      right = if i < length cells - 1 then cells !! (i + 1) else False
  in [left, center, right]
