# Static compressed prefix tree in array

I was looking for an elegant way to store a static compressed prefix tree, but every implementation used a lot of extra (fragmented) memory through pointers. So, I created a simple format to store this tree in a single array.
My implementation is superior compared to others found online due to:
 - Great cache locality
 - No memory fragmentation
 - Less memory usage than a static array of strings (actual compression)
 - Simple code

It's impressive that its real-world memory usage is <= the sum of lengths of every string, which means, you get faster search, while also using less memory.

## How does it work?

<img width="427" height="307" alt="tree" src="https://github.com/user-attachments/assets/08c3b767-017b-473c-9c04-0f2ce5a61084" />

This is a normal prefix tree. Each node has string fragment and an array of pointers to each child. Nodes and fragments are usually heap-allocated, which means memory fragmentation, and extra memory usage for each pointer.
It is obvious this can be improved, especially since our compressed prefix tree is static.

So, why don't we store everything in a single array, and each pointer will be an offset to the next fragment: 

<img width="600" height="200" alt="array1" src="https://github.com/user-attachments/assets/66c50c3e-df5e-4a66-964d-77f73bc814af" />

This is really simple to work on, to search for "heat":
 - compare characters until element in array is not a character
 - iterate through children, until we find one that starts we the next letter of the word
 - repeat until either one is 0 (or 1, see below)

You might wonder, what happens if a word is a prefix of another word (e.g hope and hopefully)?

<img width="600" height="200" alt="array2" src="https://github.com/user-attachments/assets/57a263dc-81e6-4aec-9fe5-030bb9fe0945" />

After the common prefix (ope), the branch continues, but child count is 1, which means that this fragment is a complete word, and a prefix of the next word.

You can see the full code (with tests) in the `tree/` directory.

<br><br>

-----------

<br><br>

# String comparison with penalty for character distance in keyboard

A normal string comparison doesn't take into account that letters close in the keyboard are more likely to be swapped when typing.
So, the `table/` directory has a simple algorithm that creates a 26x26 2d array, that maps each letter's penalty to another letter.
For example, `w` and `s` have a (manhattan) distance of 1, whereas `q` and `r` are 2 keys apart, thus much less likely be swapped when typing.

However this is flawed in the case the 2 strings don't have equal length (such as when a key wasn't pressed), but this issue can be mitigated by doing 2 comparisons, one from the start, and one from the end.
