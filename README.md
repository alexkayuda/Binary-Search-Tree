# This project was part of the Data Structures Honors Course.

*This is a smaller version of an existing software application that was developed to analyze large text data. It generates a report that contains the following information:*

#### Statistical Summary:
- Total  number  of  words  in  the  report 
- Number  of  unique  words 
- Number  of  unique  words  of  more  than  three  letters 
- Average  word  length    
- Average  sentence  length
- An index (alphabetical  listing) of all the unique words 

#### Style Warnings:

- if any word was used too often. (lists each unique word of more than three letters if its usage is more than 5% of the total
number of words of more than three letters).
- if average sentence length is greater than 10.
- if average word length is greater than 5.

-------
## Example

*User specifies an absolute / relative path to a file that contains a text that needs to be processed*



*E.g.: /Users/machineName/Desktop/article.txt*
```
This laBoratory experiment introduces students to fuNdamentals laws of light behaviors reflection 
and refraction. Light travels in the form of rays which are capable of rEflecting or refracting once 
contacting an interface. In !!!!!!___ observing an optic image of light reflecting or refracting once contacting 
an interface, these rays of light reflect or refract at unique angles. When a ray reflects,,, tHe 
ray returns in the direction for !?: which it caMe at the angle at which it came; this can be represented 
bY the Law of Reflection. In refracting, the ray passes through a transparent or semi-transparent 
interface and then [!@#$%^&* exits the interface at a unIque angle, specific to the material of which the 
interface is compRised oF;;;; refraction is mathematically represented by Snell’s Law. 
```

*Program generates a report at specified location (creates and writes to a text file)*


*E.g.: /Users/machineName/Desktop/report.txt*


*Note: Program will ignore all punctuation and special symbols.*
```
File Name: /Users/machineName/Desktop/article.txt
==============================================================================

	Statistical Summary:
Total Number Of Words: 124
Total Number Of "Unique" Words: 65
Total Number Of "Unique" Words With More Than Tree Letters: 47
Average Word Length: 5 characters
Average Sentance Length: 24 words

==============================================================================

	Style Warnings:
Average Sentance Length is Too Long - 24 words

==============================================================================

	Index Of Unique Words:

A:
	a
	an
	and
	angle
	angles
	are
	at
B:
	be
	behaviors
	by
C:
	came
	can
	capable
	comprised
	contacting
D:
	direction
E:
	exits
	experiment
F:
	for
	form
	fundamentals
I:
	image
	in
	interface
	introduces
	is
	it
L:
	laboratory
	law
	laws
	light
M:
	material
	mathematically
O:
	observing
	of
	once
	optic
	or
P:
	passes
R:
	ray
	rays
	reflect
	reflecting
	reflection
	reflects
	refract
	refracting
	refraction
	represented
	returns
S:
	semitransparent
	snell’s
	specific
	students
T:
	the
	then
	these
	this
	through
	to
	transparent
	travels
U:
	unique
W:
	when
	which
```
