          push 2
 paint 7 dhdhhd
                   congrats 10
                   con
 h                10



h 10
push 1
push 2
push 3
pall
  
                                                                            MONTY 

                       

push 4
  shape 10

vulnerabilities i just noticed:
1) since the tokenizer function uses its own initialized index variable unlike before that after tokenizing the opcode it updates the scoped index valriable so when tokenizing the number value its starts from when the opcode ends in the line of the file its reading from
there-by making reading faster. but in the current implementation its doesn't do that and read the line its trying to tokenize twice to get the opcode and then the value:
   pros:
   1) it can find if a line began with a number and can determine the next action to do with that ( throw error? )
   cons:
   1) theoretically slower but almost unoticeable.
