# Wash

## Analysis

## Test Plan

Partial of test plan that tests the command line arguments
```command  +   input  output         rationale
no arguments        nothing        verify program starts up and shuts down
wash a b c    q     nothing        verify program correctly quits after startup
wash a        n     nothing        verify program correctly quits at end of list
wash a b c    n q   nothing        verify program correctly quits after next
wash a b c    c q   contents of a  verify program get contents to screen
 (assuming that a exists)
wash a b c    c q   "a not found"  verify program print error message to screen
 (where a does not exists)
wash a b c    t q   nothing        verify file a is created and has length zero
 (where file a does not exist)
wash a b c    c q   nothing        verify file a now has zero length
 (where file a exists)```

[//]: # (flesh out this test plan by adding a complete set of tests for one of the wash functions.)

