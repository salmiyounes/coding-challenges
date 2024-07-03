
from typing import List, Set
from collections import deque

# Constants
FORBIDDEN = {'ab', 'cd', 'pq', 'xy'}
VOWELS = {'a', 'e', 'i', 'o', 'u'}

def is_forbidden(word: str) -> bool:
    window = deque(maxlen=2)
    for char in word:
        window.append(char)
        if ''.join(window) in FORBIDDEN:
            return True
    return False

def contains_vowels(word: str) -> bool:
    vowel_count = sum(1 for char in word if char in VOWELS)
    return vowel_count >= 3

def has_double_letter(word: str) -> bool:
    for i in range(len(word) - 1):
        if word[i] == word[i+1]:
            return True
    return False

def main():
    try:
        with open('input.txt', 'r') as file:
            data = file.read().strip().split('\n')
    except FileNotFoundError:
        print("Input file not found.")
        return
    
    count = 0
    for word in data:
        if not is_forbidden(word) and contains_vowels(word) and has_double_letter(word):
            count += 1
    
    print(count)

if __name__ == "__main__":
    main()
