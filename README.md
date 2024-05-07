# Figures Count

## Overview
Implements an algorithm for calculating the number of figures composed of marked elements in an input matrix. Provides a simple console interface facilitating the use of the algorithm.

## Implementation
In order to calculate the number of the figures in the input matrix, an undirected graph is constructed.
All marked elements in the matrix are represented as vertices in the graph. In case two marked elements are neighbouring (meaning they are consecutive in a given row or a given column in the input matrix),
an edge between them is added to the graph. The number of connected components in this graph is then calculated, using a standard algorithm, based on depth-first search.
The number of connected components in the graph is the number of figures in the input matrix. 

## Testing
 - In order to validate the correctnes of the implemented algorithm, unit tests exercising various input confgurations are added. [Googletest](https://github.com/google/googletest) is used for the purpouse.
 - [Google benchmark](https://github.com/google/benchmark) is used for benchmarking algorithm execution with various input matrix sizes and configurations.

## Future Work
 - Based on data from (production) usage, the need for further optimisation of the main algorithm should be revisited.
 - Improvements of the console interface such as user-defined symbols for empty and marked elements, cancellation of the current iteration, etc. could be considered.
Aslo, the need for optimisations in the console interface should be evaluated.
 - Adding graphical user interface facilitating the use of the algorithm could be considered.
