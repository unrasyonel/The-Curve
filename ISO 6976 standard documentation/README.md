ISO 6976 (Natural Gas - Calculation of Values, density, relative density and Wobbe indices from composition)

# The code is a C++ program that calculates various calorific values based on the ISO 6976 standard.

ISO 6976 is an international standard for calculating calorific values of natural gas.

Notes -The "uncertainty of calculation" part of the PDF, which covers chapter 11, is not included in the code.
Example calculations and values can be found in ISO 6976, chapter 12, "tables of data".

Content of the code:

1. NegativeCheck: This function checks if a number is negative, and if it is negative, prompts the user to enter a valid number.

2. compressionFactor: Calculates the compression factor for mole fraction and addition factor based on user input.

3. GrossMolar: Calculates the gross molar basis calorific value based on user input for ideal gross molar basis calorific value and mole fraction.

4. NetCalValue: Calculates the net calorific value based on user input for ideal gross molar basis calorific value, mole fraction, number of components, mole fraction and number of hydrogen atoms.

5. grossMass: Calculates the molar mass based on user input for the mole fraction and molar mass of the component.

6. netMass: Calculates the net mass calorific value based on user input for the number of components, mole fraction and molar mass.

7. idealGasGCV: Calculates the ideal gas gross calorific value based on user input for volume and number of components.

8. idealGasNCV: Calculates the ideal gas net calorific value based on user input for volume, number of components and other intermediate calculations.

9. realGasGCV: Calculates the real gas gross calorific value based on user input for volume, number of components and compression factor.


In the main() function, the 'case' and 'if' functions were mainly used to select and direct the desired calculations.

Again, the number of components is used mainly for creating variables and calling functions.


2005 release of the document can be obtained from the following link:

https://annas-archive.org/md5/366fd8036a647a100f704adf6599b768
