
# Nie wyświetlamy potwierdzeń przy przeładowaniu
set confirm off
#do we need to see every commands?
set trace-command off

define diag1
    printf "--- Diagnostyka Funkcji ---\n"
    # Wyświetla adres i plik/linię
    i args
    info line
     frame
     where 3
    disassemble $pc, +20 
    printf "Adres w rejestrze PC: %p\n", $pc
    printf "---------------------------\n"
end

b test_of_references
set $bp1 = $bpnum

b functions_main
set $bp2 = $bpnum

b func_normal_arg
set $bp3 = $bpnum

commands $bp1
    printf "function that uses reference argument "
    diag1
    #layout split
end 
commands $bp2
printf "main  function\n\n"
diag1
p/x &str1
set $addr=&str1
end 


commands $bp3
    printf "function that uses no-reference argument "
    diag1
    #layout split
end 

run
c
p/x str 
printf "address of string %p argument, and in this function %p\n", $addr, &str
#printf "using of address argument does not copy whole array to function \n"
c

printf "address of string %p argument, and in this function %p\n", $addr, &str
#fin
#printf "address of span array %p \n",&span_int2
#set $addr=&span_int2 
